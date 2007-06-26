/** \file RecoAnalyzer.cc
*  Analyzer program for Reco results
  *
  *  $Date: 2007/06/18 09:13:48 $
  *  $Revision: 1.7 $
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
  theFileName(theConf.getUntrackedParameter<std::string>("ROOTFileName","test.root")),
  thePosTECR4Beam0RecHits(),  thePosTECR4Beam1RecHits(),  thePosTECR4Beam2RecHits(),
  thePosTECR4Beam3RecHits(),  thePosTECR4Beam4RecHits(),  thePosTECR4Beam5RecHits(),
  thePosTECR4Beam6RecHits(),  thePosTECR4Beam7RecHits(),  thePosTECR6Beam0RecHits(),
  thePosTECR6Beam1RecHits(),  thePosTECR6Beam2RecHits(),  thePosTECR6Beam3RecHits(),
  thePosTECR6Beam4RecHits(),  thePosTECR6Beam5RecHits(),  thePosTECR6Beam6RecHits(),
  thePosTECR6Beam7RecHits(),  theNegTECR4Beam0RecHits(),  theNegTECR4Beam1RecHits(),
  theNegTECR4Beam2RecHits(),  theNegTECR4Beam3RecHits(),  theNegTECR4Beam4RecHits(),
  theNegTECR4Beam5RecHits(),  theNegTECR4Beam6RecHits(),  theNegTECR4Beam7RecHits(),
  theNegTECR6Beam0RecHits(),  theNegTECR6Beam1RecHits(),  theNegTECR6Beam2RecHits(),
  theNegTECR6Beam3RecHits(),  theNegTECR6Beam4RecHits(),  theNegTECR6Beam5RecHits(),
  theNegTECR6Beam6RecHits(),  theNegTECR6Beam7RecHits()
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
  thePosTECR4Beam0RecHits.empty();
  thePosTECR4Beam1RecHits.empty();
  thePosTECR4Beam2RecHits.empty();
  thePosTECR4Beam3RecHits.empty();
  thePosTECR4Beam4RecHits.empty();
  thePosTECR4Beam5RecHits.empty();
  thePosTECR4Beam6RecHits.empty();
  thePosTECR4Beam7RecHits.empty();
  thePosTECR6Beam0RecHits.empty();
  thePosTECR6Beam1RecHits.empty();
  thePosTECR6Beam2RecHits.empty();
  thePosTECR6Beam3RecHits.empty();
  thePosTECR6Beam4RecHits.empty();
  thePosTECR6Beam5RecHits.empty();
  thePosTECR6Beam6RecHits.empty();
  thePosTECR6Beam7RecHits.empty();

  theNegTECR4Beam0RecHits.empty();
  theNegTECR4Beam1RecHits.empty();
  theNegTECR4Beam2RecHits.empty();
  theNegTECR4Beam3RecHits.empty();
  theNegTECR4Beam4RecHits.empty();
  theNegTECR4Beam5RecHits.empty();
  theNegTECR4Beam6RecHits.empty();
  theNegTECR4Beam7RecHits.empty();
  theNegTECR6Beam0RecHits.empty();
  theNegTECR6Beam1RecHits.empty();
  theNegTECR6Beam2RecHits.empty();
  theNegTECR6Beam3RecHits.empty();
  theNegTECR6Beam4RecHits.empty();
  theNegTECR6Beam5RecHits.empty();
  theNegTECR6Beam6RecHits.empty();
  theNegTECR6Beam7RecHits.empty();

  for( unsigned int i = 0; i < 9; ++i )
  {
    thePosTECR4Beam0RecHits.push_back(0.0);
    thePosTECR4Beam1RecHits.push_back(0.0);
    thePosTECR4Beam2RecHits.push_back(0.0);
    thePosTECR4Beam3RecHits.push_back(0.0);
    thePosTECR4Beam4RecHits.push_back(0.0);
    thePosTECR4Beam5RecHits.push_back(0.0);
    thePosTECR4Beam6RecHits.push_back(0.0);
    thePosTECR4Beam7RecHits.push_back(0.0);
    thePosTECR6Beam0RecHits.push_back(0.0);
    thePosTECR6Beam1RecHits.push_back(0.0);
    thePosTECR6Beam2RecHits.push_back(0.0);
    thePosTECR6Beam3RecHits.push_back(0.0);
    thePosTECR6Beam4RecHits.push_back(0.0);
    thePosTECR6Beam5RecHits.push_back(0.0);
    thePosTECR6Beam6RecHits.push_back(0.0);
    thePosTECR6Beam7RecHits.push_back(0.0);

    theNegTECR4Beam0RecHits.push_back(0.0);
    theNegTECR4Beam1RecHits.push_back(0.0);
    theNegTECR4Beam2RecHits.push_back(0.0);
    theNegTECR4Beam3RecHits.push_back(0.0);
    theNegTECR4Beam4RecHits.push_back(0.0);
    theNegTECR4Beam5RecHits.push_back(0.0);
    theNegTECR4Beam6RecHits.push_back(0.0);
    theNegTECR4Beam7RecHits.push_back(0.0);
    theNegTECR6Beam0RecHits.push_back(0.0);
    theNegTECR6Beam1RecHits.push_back(0.0);
    theNegTECR6Beam2RecHits.push_back(0.0);
    theNegTECR6Beam3RecHits.push_back(0.0);
    theNegTECR6Beam4RecHits.push_back(0.0);
    theNegTECR6Beam5RecHits.push_back(0.0);
    theNegTECR6Beam6RecHits.push_back(0.0);
    theNegTECR6Beam7RecHits.push_back(0.0);
  }

  // do the Tracker Statistics
  trackerStatistics(theEvent, theSetup);

  // some plots for SiStripClusters
  trackerClusters(theEvent, theSetup);

  // plots for RecHits
  trackerRecHits(theEvent, theSetup);

  // info about the TrackCandidates
  trackerTC(theEvent, theSetup);
  
  LogDebug("RecoAnalyzer:RecHits") << "TEC+ R4 Beam 0 RecHits: " << thePosTECR4Beam0RecHits.at(0) << " "
                 << thePosTECR4Beam0RecHits.at(1) << " " << thePosTECR4Beam0RecHits.at(2) << " " 
                 << thePosTECR4Beam0RecHits.at(3) << " " << thePosTECR4Beam0RecHits.at(4) << " "
                 << thePosTECR4Beam0RecHits.at(5) << " " << thePosTECR4Beam0RecHits.at(6) << " "
                 << thePosTECR4Beam0RecHits.at(7) << " " << thePosTECR4Beam0RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC+ R4 Beam 1 RecHits: " << thePosTECR4Beam1RecHits.at(0) << " "
                 << thePosTECR4Beam1RecHits.at(1) << " " << thePosTECR4Beam1RecHits.at(2) << " "
                 << thePosTECR4Beam1RecHits.at(3) << " " << thePosTECR4Beam1RecHits.at(4) << " "
                 << thePosTECR4Beam1RecHits.at(5) << " " << thePosTECR4Beam1RecHits.at(6) << " "
                 << thePosTECR4Beam1RecHits.at(7) << " " << thePosTECR4Beam1RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC+ R4 Beam 2 RecHits: " << thePosTECR4Beam2RecHits.at(0) << " "
                 << thePosTECR4Beam2RecHits.at(1) << " " << thePosTECR4Beam2RecHits.at(2) << " "
                 << thePosTECR4Beam2RecHits.at(3) << " " << thePosTECR4Beam2RecHits.at(4) << " "
                 << thePosTECR4Beam2RecHits.at(5) << " " << thePosTECR4Beam2RecHits.at(6) << " "
                 << thePosTECR4Beam2RecHits.at(7) << " " << thePosTECR4Beam2RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC+ R4 Beam 3 RecHits: " << thePosTECR4Beam3RecHits.at(0) << " "
                 << thePosTECR4Beam3RecHits.at(1) << " " << thePosTECR4Beam3RecHits.at(2) << " "
                 << thePosTECR4Beam3RecHits.at(3) << " " << thePosTECR4Beam3RecHits.at(4) << " "
                 << thePosTECR4Beam3RecHits.at(5) << " " << thePosTECR4Beam3RecHits.at(6) << " "
                 << thePosTECR4Beam3RecHits.at(7) << " " << thePosTECR4Beam3RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC+ R4 Beam 4 RecHits: " << thePosTECR4Beam4RecHits.at(0) << " "
                 << thePosTECR4Beam4RecHits.at(1) << " " << thePosTECR4Beam4RecHits.at(2) << " "
                 << thePosTECR4Beam4RecHits.at(3) << " " << thePosTECR4Beam4RecHits.at(4) << " "
                 << thePosTECR4Beam4RecHits.at(5) << " " << thePosTECR4Beam4RecHits.at(6) << " "
                 << thePosTECR4Beam4RecHits.at(7) << " " << thePosTECR4Beam4RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC+ R4 Beam 5 RecHits: " << thePosTECR4Beam5RecHits.at(0) << " "
                 << thePosTECR4Beam5RecHits.at(1) << " " << thePosTECR4Beam5RecHits.at(2) << " "
                 << thePosTECR4Beam5RecHits.at(3) << " " << thePosTECR4Beam5RecHits.at(4) << " "
                 << thePosTECR4Beam5RecHits.at(5) << " " << thePosTECR4Beam5RecHits.at(6) << " "
                 << thePosTECR4Beam5RecHits.at(7) << " " << thePosTECR4Beam5RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC+ R4 Beam 6 RecHits: " << thePosTECR4Beam6RecHits.at(0) << " "
                 << thePosTECR4Beam6RecHits.at(1) << " " << thePosTECR4Beam6RecHits.at(2) << " "
                 << thePosTECR4Beam6RecHits.at(3) << " " << thePosTECR4Beam6RecHits.at(4) << " "
                 << thePosTECR4Beam6RecHits.at(5) << " " << thePosTECR4Beam6RecHits.at(6) << " "
                 << thePosTECR4Beam6RecHits.at(7) << " " << thePosTECR4Beam6RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC+ R4 Beam 7 RecHits: " << thePosTECR4Beam7RecHits.at(0) << " "
                 << thePosTECR4Beam7RecHits.at(1) << " " << thePosTECR4Beam7RecHits.at(2) << " "
                 << thePosTECR4Beam7RecHits.at(3) << " " << thePosTECR4Beam7RecHits.at(4) << " "
                 << thePosTECR4Beam7RecHits.at(5) << " " << thePosTECR4Beam7RecHits.at(6) << " "
                 << thePosTECR4Beam7RecHits.at(7) << " " << thePosTECR4Beam7RecHits.at(8);

  LogDebug("RecoAnalyzer:RecHits") << "TEC+ R6 Beam 0 RecHits: " << thePosTECR6Beam0RecHits.at(0) << " "
                 << thePosTECR6Beam0RecHits.at(1) << " " << thePosTECR6Beam0RecHits.at(2) << " " 
                 << thePosTECR6Beam0RecHits.at(3) << " " << thePosTECR6Beam0RecHits.at(4) << " "
                 << thePosTECR6Beam0RecHits.at(5) << " " << thePosTECR6Beam0RecHits.at(6) << " "
                 << thePosTECR6Beam0RecHits.at(7) << " " << thePosTECR6Beam0RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC+ R6 Beam 1 RecHits: " << thePosTECR6Beam1RecHits.at(0) << " "
                 << thePosTECR6Beam1RecHits.at(1) << " " << thePosTECR6Beam1RecHits.at(2) << " "
                 << thePosTECR6Beam1RecHits.at(3) << " " << thePosTECR6Beam1RecHits.at(4) << " "
                 << thePosTECR6Beam1RecHits.at(5) << " " << thePosTECR6Beam1RecHits.at(6) << " "
                 << thePosTECR6Beam1RecHits.at(7) << " " << thePosTECR6Beam1RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC+ R6 Beam 2 RecHits: " << thePosTECR6Beam2RecHits.at(0) << " "
                 << thePosTECR6Beam2RecHits.at(1) << " " << thePosTECR6Beam2RecHits.at(2) << " "
                 << thePosTECR6Beam2RecHits.at(3) << " " << thePosTECR6Beam2RecHits.at(4) << " "
                 << thePosTECR6Beam2RecHits.at(5) << " " << thePosTECR6Beam2RecHits.at(6) << " "
                 << thePosTECR6Beam2RecHits.at(7) << " " << thePosTECR6Beam2RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC+ R6 Beam 3 RecHits: " << thePosTECR6Beam3RecHits.at(0) << " "
                 << thePosTECR6Beam3RecHits.at(1) << " " << thePosTECR6Beam3RecHits.at(2) << " "
                 << thePosTECR6Beam3RecHits.at(3) << " " << thePosTECR6Beam3RecHits.at(4) << " "
                 << thePosTECR6Beam3RecHits.at(5) << " " << thePosTECR6Beam3RecHits.at(6) << " "
                 << thePosTECR6Beam3RecHits.at(7) << " " << thePosTECR6Beam3RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC+ R6 Beam 4 RecHits: " << thePosTECR6Beam4RecHits.at(0) << " "
                 << thePosTECR6Beam4RecHits.at(1) << " " << thePosTECR6Beam4RecHits.at(2) << " "
                 << thePosTECR6Beam4RecHits.at(3) << " " << thePosTECR6Beam4RecHits.at(4) << " "
                 << thePosTECR6Beam4RecHits.at(5) << " " << thePosTECR6Beam4RecHits.at(6) << " "
                 << thePosTECR6Beam4RecHits.at(7) << " " << thePosTECR6Beam4RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC+ R6 Beam 5 RecHits: " << thePosTECR6Beam5RecHits.at(0) << " "
                 << thePosTECR6Beam5RecHits.at(1) << " " << thePosTECR6Beam5RecHits.at(2) << " "
                 << thePosTECR6Beam5RecHits.at(3) << " " << thePosTECR6Beam5RecHits.at(4) << " "
                 << thePosTECR6Beam5RecHits.at(5) << " " << thePosTECR6Beam5RecHits.at(6) << " "
                 << thePosTECR6Beam5RecHits.at(7) << " " << thePosTECR6Beam5RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC+ R6 Beam 6 RecHits: " << thePosTECR6Beam6RecHits.at(0) << " "
                 << thePosTECR6Beam6RecHits.at(1) << " " << thePosTECR6Beam6RecHits.at(2) << " "
                 << thePosTECR6Beam6RecHits.at(3) << " " << thePosTECR6Beam6RecHits.at(4) << " "
                 << thePosTECR6Beam6RecHits.at(5) << " " << thePosTECR6Beam6RecHits.at(6) << " "
                 << thePosTECR6Beam6RecHits.at(7) << " " << thePosTECR6Beam6RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC+ R6 Beam 7 RecHits: " << thePosTECR6Beam7RecHits.at(0) << " "
                 << thePosTECR6Beam7RecHits.at(1) << " " << thePosTECR6Beam7RecHits.at(2) << " "
                 << thePosTECR6Beam7RecHits.at(3) << " " << thePosTECR6Beam7RecHits.at(4) << " "
                 << thePosTECR6Beam7RecHits.at(5) << " " << thePosTECR6Beam7RecHits.at(6) << " "
                 << thePosTECR6Beam7RecHits.at(7) << " " << thePosTECR6Beam7RecHits.at(8);
             
  
  LogDebug("RecoAnalyzer:RecHits") << "TEC- R4 Beam 0 RecHits: " << theNegTECR4Beam0RecHits.at(0) << " "
                 << theNegTECR4Beam0RecHits.at(1) << " " << theNegTECR4Beam0RecHits.at(2) << " " 
                 << theNegTECR4Beam0RecHits.at(3) << " " << theNegTECR4Beam0RecHits.at(4) << " "
                 << theNegTECR4Beam0RecHits.at(5) << " " << theNegTECR4Beam0RecHits.at(6) << " "
                 << theNegTECR4Beam0RecHits.at(7) << " " << theNegTECR4Beam0RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC- R4 Beam 1 RecHits: " << theNegTECR4Beam1RecHits.at(0) << " "
                 << theNegTECR4Beam1RecHits.at(1) << " " << theNegTECR4Beam1RecHits.at(2) << " "
                 << theNegTECR4Beam1RecHits.at(3) << " " << theNegTECR4Beam1RecHits.at(4) << " "
                 << theNegTECR4Beam1RecHits.at(5) << " " << theNegTECR4Beam1RecHits.at(6) << " "
                 << theNegTECR4Beam1RecHits.at(7) << " " << theNegTECR4Beam1RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC- R4 Beam 2 RecHits: " << theNegTECR4Beam2RecHits.at(0) << " "
                 << theNegTECR4Beam2RecHits.at(1) << " " << theNegTECR4Beam2RecHits.at(2) << " "
                 << theNegTECR4Beam2RecHits.at(3) << " " << theNegTECR4Beam2RecHits.at(4) << " "
                 << theNegTECR4Beam2RecHits.at(5) << " " << theNegTECR4Beam2RecHits.at(6) << " "
                 << theNegTECR4Beam2RecHits.at(7) << " " << theNegTECR4Beam2RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC- R4 Beam 3 RecHits: " << theNegTECR4Beam3RecHits.at(0) << " "
                 << theNegTECR4Beam3RecHits.at(1) << " " << theNegTECR4Beam3RecHits.at(2) << " "
                 << theNegTECR4Beam3RecHits.at(3) << " " << theNegTECR4Beam3RecHits.at(4) << " "
                 << theNegTECR4Beam3RecHits.at(5) << " " << theNegTECR4Beam3RecHits.at(6) << " "
                 << theNegTECR4Beam3RecHits.at(7) << " " << theNegTECR4Beam3RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC- R4 Beam 4 RecHits: " << theNegTECR4Beam4RecHits.at(0) << " "
                 << theNegTECR4Beam4RecHits.at(1) << " " << theNegTECR4Beam4RecHits.at(2) << " "
                 << theNegTECR4Beam4RecHits.at(3) << " " << theNegTECR4Beam4RecHits.at(4) << " "
                 << theNegTECR4Beam4RecHits.at(5) << " " << theNegTECR4Beam4RecHits.at(6) << " "
                 << theNegTECR4Beam4RecHits.at(7) << " " << theNegTECR4Beam4RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC- R4 Beam 5 RecHits: " << theNegTECR4Beam5RecHits.at(0) << " "
                 << theNegTECR4Beam5RecHits.at(1) << " " << theNegTECR4Beam5RecHits.at(2) << " "
                 << theNegTECR4Beam5RecHits.at(3) << " " << theNegTECR4Beam5RecHits.at(4) << " "
                 << theNegTECR4Beam5RecHits.at(5) << " " << theNegTECR4Beam5RecHits.at(6) << " "
                 << theNegTECR4Beam5RecHits.at(7) << " " << theNegTECR4Beam5RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC- R4 Beam 6 RecHits: " << theNegTECR4Beam6RecHits.at(0) << " "
                 << theNegTECR4Beam6RecHits.at(1) << " " << theNegTECR4Beam6RecHits.at(2) << " "
                 << theNegTECR4Beam6RecHits.at(3) << " " << theNegTECR4Beam6RecHits.at(4) << " "
                 << theNegTECR4Beam6RecHits.at(5) << " " << theNegTECR4Beam6RecHits.at(6) << " "
                 << theNegTECR4Beam6RecHits.at(7) << " " << theNegTECR4Beam6RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC- R4 Beam 7 RecHits: " << theNegTECR4Beam7RecHits.at(0) << " "
                 << theNegTECR4Beam7RecHits.at(1) << " " << theNegTECR4Beam7RecHits.at(2) << " "
                 << theNegTECR4Beam7RecHits.at(3) << " " << theNegTECR4Beam7RecHits.at(4) << " "
                 << theNegTECR4Beam7RecHits.at(5) << " " << theNegTECR4Beam7RecHits.at(6) << " "
                 << theNegTECR4Beam7RecHits.at(7) << " " << theNegTECR4Beam7RecHits.at(8);

  LogDebug("RecoAnalyzer:RecHits") << "TEC- R6 Beam 0 RecHits: " << theNegTECR6Beam0RecHits.at(0) << " "
                 << theNegTECR6Beam0RecHits.at(1) << " " << theNegTECR6Beam0RecHits.at(2) << " " 
                 << theNegTECR6Beam0RecHits.at(3) << " " << theNegTECR6Beam0RecHits.at(4) << " "
                 << theNegTECR6Beam0RecHits.at(5) << " " << theNegTECR6Beam0RecHits.at(6) << " "
                 << theNegTECR6Beam0RecHits.at(7) << " " << theNegTECR6Beam0RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC- R6 Beam 1 RecHits: " << theNegTECR6Beam1RecHits.at(0) << " "
                 << theNegTECR6Beam1RecHits.at(1) << " " << theNegTECR6Beam1RecHits.at(2) << " "
                 << theNegTECR6Beam1RecHits.at(3) << " " << theNegTECR6Beam1RecHits.at(4) << " "
                 << theNegTECR6Beam1RecHits.at(5) << " " << theNegTECR6Beam1RecHits.at(6) << " "
                 << theNegTECR6Beam1RecHits.at(7) << " " << theNegTECR6Beam1RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC- R6 Beam 2 RecHits: " << theNegTECR6Beam2RecHits.at(0) << " "
                 << theNegTECR6Beam2RecHits.at(1) << " " << theNegTECR6Beam2RecHits.at(2) << " "
                 << theNegTECR6Beam2RecHits.at(3) << " " << theNegTECR6Beam2RecHits.at(4) << " "
                 << theNegTECR6Beam2RecHits.at(5) << " " << theNegTECR6Beam2RecHits.at(6) << " "
                 << theNegTECR6Beam2RecHits.at(7) << " " << theNegTECR6Beam2RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC- R6 Beam 3 RecHits: " << theNegTECR6Beam3RecHits.at(0) << " "
                 << theNegTECR6Beam3RecHits.at(1) << " " << theNegTECR6Beam3RecHits.at(2) << " "
                 << theNegTECR6Beam3RecHits.at(3) << " " << theNegTECR6Beam3RecHits.at(4) << " "
                 << theNegTECR6Beam3RecHits.at(5) << " " << theNegTECR6Beam3RecHits.at(6) << " "
                 << theNegTECR6Beam3RecHits.at(7) << " " << theNegTECR6Beam3RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC- R6 Beam 4 RecHits: " << theNegTECR6Beam4RecHits.at(0) << " "
                 << theNegTECR6Beam4RecHits.at(1) << " " << theNegTECR6Beam4RecHits.at(2) << " "
                 << theNegTECR6Beam4RecHits.at(3) << " " << theNegTECR6Beam4RecHits.at(4) << " "
                 << theNegTECR6Beam4RecHits.at(5) << " " << theNegTECR6Beam4RecHits.at(6) << " "
                 << theNegTECR6Beam4RecHits.at(7) << " " << theNegTECR6Beam4RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC- R6 Beam 5 RecHits: " << theNegTECR6Beam5RecHits.at(0) << " "
                 << theNegTECR6Beam5RecHits.at(1) << " " << theNegTECR6Beam5RecHits.at(2) << " "
                 << theNegTECR6Beam5RecHits.at(3) << " " << theNegTECR6Beam5RecHits.at(4) << " "
                 << theNegTECR6Beam5RecHits.at(5) << " " << theNegTECR6Beam5RecHits.at(6) << " "
                 << theNegTECR6Beam5RecHits.at(7) << " " << theNegTECR6Beam5RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC- R6 Beam 6 RecHits: " << theNegTECR6Beam6RecHits.at(0) << " "
                 << theNegTECR6Beam6RecHits.at(1) << " " << theNegTECR6Beam6RecHits.at(2) << " "
                 << theNegTECR6Beam6RecHits.at(3) << " " << theNegTECR6Beam6RecHits.at(4) << " "
                 << theNegTECR6Beam6RecHits.at(5) << " " << theNegTECR6Beam6RecHits.at(6) << " "
                 << theNegTECR6Beam6RecHits.at(7) << " " << theNegTECR6Beam6RecHits.at(8);
  LogDebug("RecoAnalyzer:RecHits") << "TEC- R6 Beam 7 RecHits: " << theNegTECR6Beam7RecHits.at(0) << " "
                 << theNegTECR6Beam7RecHits.at(1) << " " << theNegTECR6Beam7RecHits.at(2) << " "
                 << theNegTECR6Beam7RecHits.at(3) << " " << theNegTECR6Beam7RecHits.at(4) << " "
                 << theNegTECR6Beam7RecHits.at(5) << " " << theNegTECR6Beam7RecHits.at(6) << " "
                 << theNegTECR6Beam7RecHits.at(7) << " " << theNegTECR6Beam7RecHits.at(8);
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

void RecoAnalyzer::fillLaserBeamPlots(double r_, int theWheel, std::string thePart, int theRing, int theBeam)
{
  if ( (thePart == "TEC+") && (theRing == 4) && (theBeam == 0) )
  {
    thePosTECR4Beam0RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 0 in Ring 4 ****

  // **** Beam 1 in Ring 4 ****
  else if ( (thePart == "TEC+") && (theRing == 4) && (theBeam == 1) )
  {
    thePosTECR4Beam1RecHits.at(theWheel - 1) = r_;
  }
    // **** end of beam 1 in Ring 4 ****

  // **** Beam 2 in Ring 4 ****
  else if ( (thePart == "TEC+") && (theRing == 4) && (theBeam == 2) )
  {
    thePosTECR4Beam2RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 2 in Ring 4 ****

  // **** Beam 3 in Ring 4 ****
  else if ( (thePart == "TEC+") && (theRing == 4) && (theBeam == 3) )
  {
    thePosTECR4Beam3RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 3 in Ring 4 ****

  // **** Beam 4 in Ring 4 ****
  else if ( (thePart == "TEC+") && (theRing == 4) && (theBeam == 4) )
  {
    thePosTECR4Beam4RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 4 in Ring 4 ****

  // **** Beam 5 in Ring 4 ****
  else if ( (thePart == "TEC+") && (theRing == 4) && (theBeam == 5) )
  {
    thePosTECR4Beam5RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 5 in Ring 4 ****

  // **** Beam 6 in Ring 4 ****
  else if ( (thePart == "TEC+") && (theRing == 4) && (theBeam == 6) )
  {
    thePosTECR4Beam6RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 6 in Ring 4 ****

  // **** Beam 7 in Ring 4 ****
  else if ( (thePart == "TEC+") && (theRing == 4) && (theBeam == 7) )
  {
    thePosTECR4Beam7RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 7 in Ring 4 ****

  // **** Ring 6
  else if ( (thePart == "TEC+") && (theRing == 6) && (theBeam == 0) )
  {
    thePosTECR6Beam0RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 0 in Ring 6 ****

  // **** Beam 1 in Ring 6 ****
  else if ( (thePart == "TEC+") && (theRing == 6) && (theBeam == 1) )
  {
    thePosTECR6Beam1RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 1 in Ring 6 ****

  // **** Beam 2 in Ring 6 ****
  else if ( (thePart == "TEC+") && (theRing == 6) && (theBeam == 2) )
  {
    thePosTECR6Beam2RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 2 in Ring 6 ****

  // **** Beam 3 in Ring 6 ****
  else if ( (thePart == "TEC+") && (theRing == 6) && (theBeam == 3) )
  {
    thePosTECR6Beam3RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 3 in Ring 6 ****

  // **** Beam 4 in Ring 6 ****
  else if ( (thePart == "TEC+") && (theRing == 6) && (theBeam == 4) )
  {
    thePosTECR6Beam4RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 4 in Ring 6 ****

  // **** Beam 5 in Ring 6 ****
  else if ( (thePart == "TEC+") && (theRing == 6) && (theBeam == 5) )
  {
    thePosTECR6Beam5RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 5 in Ring 6 ****

  // **** Beam 6 in Ring 6 ****
  else if ( (thePart == "TEC+") && (theRing == 6) && (theBeam == 6) )
  {
    thePosTECR6Beam6RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 6 in Ring 6 ****

  // **** Beam 7 in Ring 6 ****
  else if ( (thePart == "TEC+") && (theRing == 6) && (theBeam == 7) )
  {
    thePosTECR6Beam7RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 7 in Ring 6 ****

  // ***** TEC- *****
  else if ( (thePart == "TEC-") && (theRing == 4) && (theBeam == 0) )
  {
    theNegTECR4Beam0RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 0 in Ring 4 ****

  // **** Beam 1 in Ring 4 ****
  else if ( (thePart == "TEC-") && (theRing == 4) && (theBeam == 1) )
  {
    theNegTECR4Beam1RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 1 in Ring 4 ****

  // **** Beam 2 in Ring 4 ****
  else if ( (thePart == "TEC-") && (theRing == 4) && (theBeam == 2) )
  {
    theNegTECR4Beam2RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 2 in Ring 4 ****

  // **** Beam 3 in Ring 4 ****
  else if ( (thePart == "TEC-") && (theRing == 4) && (theBeam == 3) )
  {
    theNegTECR4Beam3RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 3 in Ring 4 ****

  // **** Beam 4 in Ring 4 ****
  else if ( (thePart == "TEC-") && (theRing == 4) && (theBeam == 4) )
  {
    theNegTECR4Beam4RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 4 in Ring 4 ****

  // **** Beam 5 in Ring 4 ****
  else if ( (thePart == "TEC-") && (theRing == 4) && (theBeam == 5) )
  {
    theNegTECR4Beam5RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 5 in Ring 4 ****

  // **** Beam 6 in Ring 4 ****
  else if ( (thePart == "TEC-") && (theRing == 4) && (theBeam == 6) )
  {
    theNegTECR4Beam6RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 6 in Ring 4 ****

  // **** Beam 7 in Ring 4 ****
  else if ( (thePart == "TEC-") && (theRing == 4) && (theBeam == 7) )
  {
    theNegTECR4Beam7RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 7 in Ring 4 ****

  // **** Ring 6
  else if ( (thePart == "TEC-") && (theRing == 6) && (theBeam == 0) )
  {
    theNegTECR6Beam0RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 0 in Ring 6 ****

  // **** Beam 1 in Ring 6 ****
  else if ( (thePart == "TEC-") && (theRing == 6) && (theBeam == 1) )
  {
    theNegTECR6Beam1RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 1 in Ring 6 ****

  // **** Beam 2 in Ring 6 ****
  else if ( (thePart == "TEC-") && (theRing == 6) && (theBeam == 2) )
  {
    theNegTECR6Beam2RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 2 in Ring 6 ****

  // **** Beam 3 in Ring 6 ****
  else if ( (thePart == "TEC-") && (theRing == 6) && (theBeam == 3) )
  {
    theNegTECR6Beam3RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 3 in Ring 6 ****

  // **** Beam 4 in Ring 6 ****
  else if ( (thePart == "TEC-") && (theRing == 6) && (theBeam == 4) )
  {
    theNegTECR6Beam4RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 4 in Ring 6 ****

  // **** Beam 5 in Ring 6 ****
  else if ( (thePart == "TEC-") && (theRing == 6) && (theBeam == 5) )
  {
    theNegTECR6Beam5RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 5 in Ring 6 ****

  // **** Beam 6 in Ring 6 ****
  else if ( (thePart == "TEC-") && (theRing == 6) && (theBeam == 6) )
  {
    theNegTECR6Beam6RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 6 in Ring 6 ****

  // **** Beam 7 in Ring 6 ****
  else if ( (thePart == "TEC-") && (theRing == 6) && (theBeam == 7) )
  {
    theNegTECR6Beam7RecHits.at(theWheel - 1) = r_;
  }
  // **** end of beam 7 in Ring 6 ****

}
