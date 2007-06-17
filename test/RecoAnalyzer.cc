/** \file RecoAnalyzer.cc
*  Analyzer program for Reco results
  *
  *  $Date: 2007/06/16 13:17:42 $
  *  $Revision: 1.3 $
  *  \author Maarten Thomas
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

void RecoAnalyzer::fillLaserBeamPlots(double r_, double z_, std::string thePart, int theRing, int theBeam)
{
  if ( (thePart == "TEC+") && (theRing == 4) && (theBeam == 0) )
  {
    thePosTECR4Beam0RecHits->Fill(z_,r_);
  }
  // **** end of beam 0 in Ring 4 ****

  // **** Beam 1 in Ring 4 ****
  else if ( (thePart == "TEC+") && (theRing == 4) && (theBeam == 1) )
  {
    thePosTECR4Beam1RecHits->Fill(z_,r_);
  }
    // **** end of beam 1 in Ring 4 ****

  // **** Beam 2 in Ring 4 ****
  else if ( (thePart == "TEC+") && (theRing == 4) && (theBeam == 2) )
  {
    thePosTECR4Beam2RecHits->Fill(z_,r_);
  }
  // **** end of beam 2 in Ring 4 ****

  // **** Beam 3 in Ring 4 ****
  else if ( (thePart == "TEC+") && (theRing == 4) && (theBeam == 3) )
  {
    thePosTECR4Beam3RecHits->Fill(z_,r_);
  }
  // **** end of beam 3 in Ring 4 ****

  // **** Beam 4 in Ring 4 ****
  else if ( (thePart == "TEC+") && (theRing == 4) && (theBeam == 4) )
  {
    thePosTECR4Beam4RecHits->Fill(z_,r_);
  }
  // **** end of beam 4 in Ring 4 ****

  // **** Beam 5 in Ring 4 ****
  else if ( (thePart == "TEC+") && (theRing == 4) && (theBeam == 5) )
  {
    thePosTECR4Beam5RecHits->Fill(z_,r_);
  }
  // **** end of beam 5 in Ring 4 ****

  // **** Beam 6 in Ring 4 ****
  else if ( (thePart == "TEC+") && (theRing == 4) && (theBeam == 6) )
  {
    thePosTECR4Beam6RecHits->Fill(z_,r_);
  }
  // **** end of beam 6 in Ring 4 ****

  // **** Beam 7 in Ring 4 ****
  else if ( (thePart == "TEC+") && (theRing == 4) && (theBeam == 7) )
  {
    thePosTECR4Beam7RecHits->Fill(z_,r_);
  }
  // **** end of beam 7 in Ring 4 ****

  // **** Ring 6
  else if ( (thePart == "TEC+") && (theRing == 6) && (theBeam == 0) )
  {
    thePosTECR6Beam0RecHits->Fill(z_,r_);
  }
  // **** end of beam 0 in Ring 6 ****

  // **** Beam 1 in Ring 6 ****
  else if ( (thePart == "TEC+") && (theRing == 6) && (theBeam == 1) )
  {
    thePosTECR6Beam1RecHits->Fill(z_,r_);
  }
  // **** end of beam 1 in Ring 6 ****

  // **** Beam 2 in Ring 6 ****
  else if ( (thePart == "TEC+") && (theRing == 6) && (theBeam == 2) )
  {
    thePosTECR6Beam2RecHits->Fill(z_,r_);
  }
  // **** end of beam 2 in Ring 6 ****

  // **** Beam 3 in Ring 6 ****
  else if ( (thePart == "TEC+") && (theRing == 6) && (theBeam == 3) )
  {
    thePosTECR6Beam3RecHits->Fill(z_,r_);
  }
  // **** end of beam 3 in Ring 6 ****

  // **** Beam 4 in Ring 6 ****
  else if ( (thePart == "TEC+") && (theRing == 6) && (theBeam == 4) )
  {
    thePosTECR6Beam4RecHits->Fill(z_,r_);
  }
  // **** end of beam 4 in Ring 6 ****

  // **** Beam 5 in Ring 6 ****
  else if ( (thePart == "TEC+") && (theRing == 6) && (theBeam == 5) )
  {
    thePosTECR6Beam5RecHits->Fill(z_,r_);
  }
  // **** end of beam 5 in Ring 6 ****

  // **** Beam 6 in Ring 6 ****
  else if ( (thePart == "TEC+") && (theRing == 6) && (theBeam == 6) )
  {
    thePosTECR6Beam6RecHits->Fill(z_,r_);
  }
  // **** end of beam 6 in Ring 6 ****

  // **** Beam 7 in Ring 6 ****
  else if ( (thePart == "TEC+") && (theRing == 6) && (theBeam == 7) )
  {
    thePosTECR6Beam7RecHits->Fill(z_,r_);
  }
  // **** end of beam 7 in Ring 6 ****

  // ***** TEC- *****
  else if ( (thePart == "TEC-") && (theRing == 4) && (theBeam == 0) )
  {
    theNegTECR4Beam0RecHits->Fill(z_,r_);
  }
  // **** end of beam 0 in Ring 4 ****

  // **** Beam 1 in Ring 4 ****
  else if ( (thePart == "TEC-") && (theRing == 4) && (theBeam == 1) )
  {
    theNegTECR4Beam1RecHits->Fill(z_,r_);
  }
  // **** end of beam 1 in Ring 4 ****

  // **** Beam 2 in Ring 4 ****
  else if ( (thePart == "TEC-") && (theRing == 4) && (theBeam == 2) )
  {
    theNegTECR4Beam2RecHits->Fill(z_,r_);
  }
  // **** end of beam 2 in Ring 4 ****

  // **** Beam 3 in Ring 4 ****
  else if ( (thePart == "TEC-") && (theRing == 4) && (theBeam == 3) )
  {
    theNegTECR4Beam3RecHits->Fill(z_,r_);
  }
  // **** end of beam 3 in Ring 4 ****

  // **** Beam 4 in Ring 4 ****
  else if ( (thePart == "TEC-") && (theRing == 4) && (theBeam == 4) )
  {
    theNegTECR4Beam4RecHits->Fill(z_,r_);
  }
  // **** end of beam 4 in Ring 4 ****

  // **** Beam 5 in Ring 4 ****
  else if ( (thePart == "TEC-") && (theRing == 4) && (theBeam == 5) )
  {
    theNegTECR4Beam5RecHits->Fill(z_,r_);
  }
  // **** end of beam 5 in Ring 4 ****

  // **** Beam 6 in Ring 4 ****
  else if ( (thePart == "TEC-") && (theRing == 4) && (theBeam == 6) )
  {
    theNegTECR4Beam6RecHits->Fill(z_,r_);
  }
  // **** end of beam 6 in Ring 4 ****

  // **** Beam 7 in Ring 4 ****
  else if ( (thePart == "TEC-") && (theRing == 4) && (theBeam == 7) )
  {
    theNegTECR4Beam7RecHits->Fill(z_,r_);
  }
  // **** end of beam 7 in Ring 4 ****

  // **** Ring 6
  else if ( (thePart == "TEC-") && (theRing == 6) && (theBeam == 0) )
  {
    theNegTECR6Beam0RecHits->Fill(z_,r_);
  }
  // **** end of beam 0 in Ring 6 ****

  // **** Beam 1 in Ring 6 ****
  else if ( (thePart == "TEC-") && (theRing == 6) && (theBeam == 1) )
  {
    theNegTECR6Beam1RecHits->Fill(z_,r_);
  }
  // **** end of beam 1 in Ring 6 ****

  // **** Beam 2 in Ring 6 ****
  else if ( (thePart == "TEC-") && (theRing == 6) && (theBeam == 2) )
  {
    theNegTECR6Beam2RecHits->Fill(z_,r_);
  }
  // **** end of beam 2 in Ring 6 ****

  // **** Beam 3 in Ring 6 ****
  else if ( (thePart == "TEC-") && (theRing == 6) && (theBeam == 3) )
  {
    theNegTECR6Beam3RecHits->Fill(z_,r_);
  }
  // **** end of beam 3 in Ring 6 ****

  // **** Beam 4 in Ring 6 ****
  else if ( (thePart == "TEC-") && (theRing == 6) && (theBeam == 4) )
  {
    theNegTECR6Beam4RecHits->Fill(z_,r_);
  }
  // **** end of beam 4 in Ring 6 ****

  // **** Beam 5 in Ring 6 ****
  else if ( (thePart == "TEC-") && (theRing == 6) && (theBeam == 5) )
  {
    theNegTECR6Beam5RecHits->Fill(z_,r_);
  }
  // **** end of beam 5 in Ring 6 ****

  // **** Beam 6 in Ring 6 ****
  else if ( (thePart == "TEC-") && (theRing == 6) && (theBeam == 6) )
  {
    theNegTECR6Beam6RecHits->Fill(z_,r_);
  }
  // **** end of beam 6 in Ring 6 ****

  // **** Beam 7 in Ring 6 ****
  else if ( (thePart == "TEC-") && (theRing == 6) && (theBeam == 7) )
  {
    theNegTECR6Beam7RecHits->Fill(z_,r_);
  }
  // **** end of beam 7 in Ring 6 ****

}

