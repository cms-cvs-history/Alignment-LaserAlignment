/*
 * Analyzer program for Reco results
 */

#include "Alignment/LaserAlignment/test/RecoAnalyzer.h"

RecoAnalyzer::RecoAnalyzer(edm::ParameterSet const& theConf) 
  : theSearchPhiTIB(theConf.getUntrackedParameter<double>("SearchWindowPhiTIB",0.05)),
    theSearchPhiTOB(theConf.getUntrackedParameter<double>("SearchWindowPhiTOB",0.05)),
    theSearchPhiTEC(theConf.getUntrackedParameter<double>("SearchWindowPhiTEC",0.05)),
    theSearchZTIB(theConf.getUntrackedParameter<double>("SearchWindowZTIB",1.0)),
    theSearchZTOB(theConf.getUntrackedParameter<double>("SearchWindowZTOB",1.0)),
    theDigiProducersList(theConf.getParameter<Parameters>("DigiProducersList")),
    theClusterProducer(theConf.getParameter<std::string>("ClusterProducer")),
    theRecHitProducer(theConf.getParameter<std::string>("RecHitProducer")),
    theFile(),
    theCompression(theConf.getUntrackedParameter<int>("ROOTFileCompression",1)),
    theFileName(theConf.getUntrackedParameter<std::string>("ROOTFileName","test.root"))
{
  // load the configuration from the ParameterSet  
  edm::LogInfo("RecoAnalyzer") << "==========================================================="
				  << "\n===                Start configuration                  ==="
				  << "\n    theSearchPhiTIB            = " << theSearchPhiTIB
				  << "\n    theSearchPhiTOB            = " << theSearchPhiTOB
				  << "\n    theSearchPhiTEC            = " << theSearchPhiTEC 
				  << "\n    theSearchZTIB              = " << theSearchZTIB
				  << "\n    theSearchZTOB              = " << theSearchZTOB
				  << "\n    ROOT filename              = " << theFileName
				  << "\n    compression                = " << theCompression
				  << "\n===========================================================";
}

RecoAnalyzer::~RecoAnalyzer()
{
  // close the rootfile
  closeRootFile();

  if (theFile != 0) { delete theFile; }

}

void RecoAnalyzer::analyze(edm::Event const& theEvent, edm::EventSetup const& theSetup) 
{
  // do the Tracker Statistics
  trackerStatistics(theEvent, theSetup);

  // some plots for SiStripClusters
  trackerClusters(theEvent, theSetup);

  // plots for RecHits
  trackerRecHits(theEvent, theSetup);

  // info about the TrackCandidates
  trackerTC(theEvent, theSetup);
}


void RecoAnalyzer::beginJob(const edm::EventSetup& theSetup) 
{
  // creating a new file
  theFile = new TFile(theFileName.c_str(),"RECREATE","CMS ROOT file");
  theFile->SetCompressionLevel(theCompression);
      
  // initialize the histograms
  if (theFile) 
    {
      this->initHistograms();
    }
  else 
    {
      throw edm::Exception(edm::errors::LogicError,
			   "<RecoAnalyzer::initSetup()>: ERROR!!! something wrong with the RootFile");
    } 
}

void RecoAnalyzer::closeRootFile()
{
  theFile->Write();
}

void RecoAnalyzer::fillAdcCounts(TH1D * theHistogram, 
				 edm::DetSet<SiStripDigi>::const_iterator digiRangeIterator,
				 edm::DetSet<SiStripDigi>::const_iterator digiRangeIteratorEnd)
{
  // loop over all the digis in this det
  for (; digiRangeIterator != digiRangeIteratorEnd; ++digiRangeIterator) 
    {
      const SiStripDigi *digi = &*digiRangeIterator;
      
      // fill the number of adc counts in the histogram
      if (digi->channel() < 512)
	{
	  Double_t theBinContent = theHistogram->GetBinContent(digi->channel()) + digi->adc();
	  theHistogram->SetBinContent(digi->channel(), theBinContent);
	}
    }
}



