/*  
 * Analyzer program to make some plots for the reconstruction
 */


#ifndef LaserAlignment_RecoAnalyzer_H
#define LaserAlignment_RecoAnalyzer_H

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/Selector.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Utilities/interface/EDMException.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "Geometry/TrackerNumberingBuilder/interface/GeometricDet.h"
#include "Geometry/CommonTopologies/interface/PixelTopology.h"
#include "Geometry/CommonTopologies/interface/StripTopology.h"
#include "Geometry/TrackerGeometryBuilder/interface/PixelGeomDetType.h"
#include "Geometry/TrackerGeometryBuilder/interface/StripGeomDetType.h"
#include "Geometry/TrackerGeometryBuilder/interface/PixelGeomDetUnit.h"
#include "Geometry/TrackerGeometryBuilder/interface/StripGeomDetUnit.h"
#include "DataFormats/GeometrySurface/interface/BoundSurface.h"
#include "DataFormats/GeometryVector/interface/GlobalPoint.h"
#include "DataFormats/DetId/interface/DetId.h"

#include "DataFormats/SiStripDetId/interface/StripSubdetector.h"
#include "DataFormats/SiStripDetId/interface/TECDetId.h"
#include "DataFormats/SiStripDetId/interface/TIBDetId.h"
#include "DataFormats/SiStripDetId/interface/TOBDetId.h"
#include "DataFormats/SiStripDigi/interface/SiStripDigi.h"
#include "DataFormats/Common/interface/DetSetVector.h"
#include "DataFormats/SiStripCluster/interface/SiStripCluster.h"
#include "DataFormats/TrackerRecHit2D/interface/SiStripRecHit2DCollection.h"
#include "DataFormats/TrackerRecHit2D/interface/SiStripMatchedRecHit2DCollection.h"

#include "DataFormats/TrackCandidate/interface/TrackCandidateCollection.h"
#include "DataFormats/TrackCandidate/interface/TrackCandidate.h"

// ROOT
#include "TH1.h"
#include "TH2.h"
#include "TString.h"
#include "TFile.h"
#include "TObject.h"

#include <iostream>

class RecoAnalyzer : public edm::EDAnalyzer, public TObject 
{
 public:
  typedef std::vector<edm::ParameterSet> Parameters;

  explicit RecoAnalyzer(edm::ParameterSet const& theConf);
  ~RecoAnalyzer();
  
  // this method will do the user analysis 
  virtual void analyze(edm::Event const& theEvent, edm::EventSetup const& theSetup);
  virtual void beginJob(const edm::EventSetup& theSetup);

 private:
  void closeRootFile();
  
  void fillAdcCounts(TH1D * theHistogram,
		     edm::DetSet<SiStripDigi>::const_iterator digiRangeIterator,
		     edm::DetSet<SiStripDigi>::const_iterator digiRangeIteratorEnd);

  void initHistograms();

  void trackerStatistics(edm::Event const& theEvent, edm::EventSetup const& theSetup);
  void trackerClusters(edm::Event const& theEvent, edm::EventSetup const& theSetup);
  void trackerRecHits(edm::Event const& theEvent, edm::EventSetup const& theSetup);
  void trackerTC(edm::Event const& theEvent, edm::EventSetup const& theSetup);
  
 private:
  double theSearchPhiTIB;
  double theSearchPhiTOB;
  double theSearchPhiTEC;
  double theSearchZTIB;
  double theSearchZTOB;

  // digi producer
  Parameters theDigiProducersList;

  // cluster producer
  std::string theClusterProducer;

  // RecHit producer
  std::string theRecHitProducer;

  // Tree stuff
  TFile * theFile;
  int theCompression;
  std::string theFileName;

  // monitor histograms

  /* Laser Beams in TEC+ */
  // Adc counts for Beam 0 in Ring 4
  TH1D * theBeam0Ring4Disc1PosAdcCounts;
  TH1D * theBeam0Ring4Disc2PosAdcCounts;
  TH1D * theBeam0Ring4Disc3PosAdcCounts;
  TH1D * theBeam0Ring4Disc4PosAdcCounts;
  TH1D * theBeam0Ring4Disc5PosAdcCounts;
  TH1D * theBeam0Ring4Disc6PosAdcCounts;
  TH1D * theBeam0Ring4Disc7PosAdcCounts;
  TH1D * theBeam0Ring4Disc8PosAdcCounts;
  TH1D * theBeam0Ring4Disc9PosAdcCounts;

  // Adc counts for Beam 1 in Ring 4
  TH1D * theBeam1Ring4Disc1PosAdcCounts;
  TH1D * theBeam1Ring4Disc2PosAdcCounts;
  TH1D * theBeam1Ring4Disc3PosAdcCounts;
  TH1D * theBeam1Ring4Disc4PosAdcCounts;
  TH1D * theBeam1Ring4Disc5PosAdcCounts;
  TH1D * theBeam1Ring4Disc6PosAdcCounts;
  TH1D * theBeam1Ring4Disc7PosAdcCounts;
  TH1D * theBeam1Ring4Disc8PosAdcCounts;
  TH1D * theBeam1Ring4Disc9PosAdcCounts;

  // plots for TEC2TEC
  TH1D * theBeam1Ring4Disc1PosTEC2TECAdcCounts;
  TH1D * theBeam1Ring4Disc2PosTEC2TECAdcCounts;
  TH1D * theBeam1Ring4Disc3PosTEC2TECAdcCounts;
  TH1D * theBeam1Ring4Disc4PosTEC2TECAdcCounts;
  TH1D * theBeam1Ring4Disc5PosTEC2TECAdcCounts;

  // Adc counts for Beam 2 in Ring 4
  TH1D * theBeam2Ring4Disc1PosAdcCounts;
  TH1D * theBeam2Ring4Disc2PosAdcCounts;
  TH1D * theBeam2Ring4Disc3PosAdcCounts;
  TH1D * theBeam2Ring4Disc4PosAdcCounts;
  TH1D * theBeam2Ring4Disc5PosAdcCounts;
  TH1D * theBeam2Ring4Disc6PosAdcCounts;
  TH1D * theBeam2Ring4Disc7PosAdcCounts;
  TH1D * theBeam2Ring4Disc8PosAdcCounts;
  TH1D * theBeam2Ring4Disc9PosAdcCounts;

  // plots for TEC2TEC
  TH1D * theBeam2Ring4Disc1PosTEC2TECAdcCounts;
  TH1D * theBeam2Ring4Disc2PosTEC2TECAdcCounts;
  TH1D * theBeam2Ring4Disc3PosTEC2TECAdcCounts;
  TH1D * theBeam2Ring4Disc4PosTEC2TECAdcCounts;
  TH1D * theBeam2Ring4Disc5PosTEC2TECAdcCounts;

  // Adc counts for Beam 3 in Ring 4
  TH1D * theBeam3Ring4Disc1PosAdcCounts;
  TH1D * theBeam3Ring4Disc2PosAdcCounts;
  TH1D * theBeam3Ring4Disc3PosAdcCounts;
  TH1D * theBeam3Ring4Disc4PosAdcCounts;
  TH1D * theBeam3Ring4Disc5PosAdcCounts;
  TH1D * theBeam3Ring4Disc6PosAdcCounts;
  TH1D * theBeam3Ring4Disc7PosAdcCounts;
  TH1D * theBeam3Ring4Disc8PosAdcCounts;
  TH1D * theBeam3Ring4Disc9PosAdcCounts;

  // Adc counts for Beam 4 in Ring 4
  TH1D * theBeam4Ring4Disc1PosAdcCounts;
  TH1D * theBeam4Ring4Disc2PosAdcCounts;
  TH1D * theBeam4Ring4Disc3PosAdcCounts;
  TH1D * theBeam4Ring4Disc4PosAdcCounts;
  TH1D * theBeam4Ring4Disc5PosAdcCounts;
  TH1D * theBeam4Ring4Disc6PosAdcCounts;
  TH1D * theBeam4Ring4Disc7PosAdcCounts;
  TH1D * theBeam4Ring4Disc8PosAdcCounts;
  TH1D * theBeam4Ring4Disc9PosAdcCounts;

  // plots for TEC2TEC
  TH1D * theBeam4Ring4Disc1PosTEC2TECAdcCounts;
  TH1D * theBeam4Ring4Disc2PosTEC2TECAdcCounts;
  TH1D * theBeam4Ring4Disc3PosTEC2TECAdcCounts;
  TH1D * theBeam4Ring4Disc4PosTEC2TECAdcCounts;
  TH1D * theBeam4Ring4Disc5PosTEC2TECAdcCounts;

  // Adc counts for Beam 5 in Ring 4
  TH1D * theBeam5Ring4Disc1PosAdcCounts;
  TH1D * theBeam5Ring4Disc2PosAdcCounts;
  TH1D * theBeam5Ring4Disc3PosAdcCounts;
  TH1D * theBeam5Ring4Disc4PosAdcCounts;
  TH1D * theBeam5Ring4Disc5PosAdcCounts;
  TH1D * theBeam5Ring4Disc6PosAdcCounts;
  TH1D * theBeam5Ring4Disc7PosAdcCounts;
  TH1D * theBeam5Ring4Disc8PosAdcCounts;
  TH1D * theBeam5Ring4Disc9PosAdcCounts;

  // Adc counts for Beam 6 in Ring 4
  TH1D * theBeam6Ring4Disc1PosAdcCounts;
  TH1D * theBeam6Ring4Disc2PosAdcCounts;
  TH1D * theBeam6Ring4Disc3PosAdcCounts;
  TH1D * theBeam6Ring4Disc4PosAdcCounts;
  TH1D * theBeam6Ring4Disc5PosAdcCounts;
  TH1D * theBeam6Ring4Disc6PosAdcCounts;
  TH1D * theBeam6Ring4Disc7PosAdcCounts;
  TH1D * theBeam6Ring4Disc8PosAdcCounts;
  TH1D * theBeam6Ring4Disc9PosAdcCounts;

  // plots for TEC2TEC
  TH1D * theBeam6Ring4Disc1PosTEC2TECAdcCounts;
  TH1D * theBeam6Ring4Disc2PosTEC2TECAdcCounts;
  TH1D * theBeam6Ring4Disc3PosTEC2TECAdcCounts;
  TH1D * theBeam6Ring4Disc4PosTEC2TECAdcCounts;
  TH1D * theBeam6Ring4Disc5PosTEC2TECAdcCounts;

  // Adc counts for Beam 7 in Ring 4
  TH1D * theBeam7Ring4Disc1PosAdcCounts;
  TH1D * theBeam7Ring4Disc2PosAdcCounts;
  TH1D * theBeam7Ring4Disc3PosAdcCounts;
  TH1D * theBeam7Ring4Disc4PosAdcCounts;
  TH1D * theBeam7Ring4Disc5PosAdcCounts;
  TH1D * theBeam7Ring4Disc6PosAdcCounts;
  TH1D * theBeam7Ring4Disc7PosAdcCounts;
  TH1D * theBeam7Ring4Disc8PosAdcCounts;
  TH1D * theBeam7Ring4Disc9PosAdcCounts;

  // plots for TEC2TEC
  TH1D * theBeam7Ring4Disc1PosTEC2TECAdcCounts;
  TH1D * theBeam7Ring4Disc2PosTEC2TECAdcCounts;
  TH1D * theBeam7Ring4Disc3PosTEC2TECAdcCounts;
  TH1D * theBeam7Ring4Disc4PosTEC2TECAdcCounts;
  TH1D * theBeam7Ring4Disc5PosTEC2TECAdcCounts;

  // Adc counts for Beam 0 in Ring 6
  TH1D * theBeam0Ring6Disc1PosAdcCounts;
  TH1D * theBeam0Ring6Disc2PosAdcCounts;
  TH1D * theBeam0Ring6Disc3PosAdcCounts;
  TH1D * theBeam0Ring6Disc4PosAdcCounts;
  TH1D * theBeam0Ring6Disc5PosAdcCounts;
  TH1D * theBeam0Ring6Disc6PosAdcCounts;
  TH1D * theBeam0Ring6Disc7PosAdcCounts;
  TH1D * theBeam0Ring6Disc8PosAdcCounts;
  TH1D * theBeam0Ring6Disc9PosAdcCounts;

  // Adc counts for Beam 1 in Ring 6
  TH1D * theBeam1Ring6Disc1PosAdcCounts;
  TH1D * theBeam1Ring6Disc2PosAdcCounts;
  TH1D * theBeam1Ring6Disc3PosAdcCounts;
  TH1D * theBeam1Ring6Disc4PosAdcCounts;
  TH1D * theBeam1Ring6Disc5PosAdcCounts;
  TH1D * theBeam1Ring6Disc6PosAdcCounts;
  TH1D * theBeam1Ring6Disc7PosAdcCounts;
  TH1D * theBeam1Ring6Disc8PosAdcCounts;
  TH1D * theBeam1Ring6Disc9PosAdcCounts;

  // Adc counts for Beam 2 in Ring 6
  TH1D * theBeam2Ring6Disc1PosAdcCounts;
  TH1D * theBeam2Ring6Disc2PosAdcCounts;
  TH1D * theBeam2Ring6Disc3PosAdcCounts;
  TH1D * theBeam2Ring6Disc4PosAdcCounts;
  TH1D * theBeam2Ring6Disc5PosAdcCounts;
  TH1D * theBeam2Ring6Disc6PosAdcCounts;
  TH1D * theBeam2Ring6Disc7PosAdcCounts;
  TH1D * theBeam2Ring6Disc8PosAdcCounts;
  TH1D * theBeam2Ring6Disc9PosAdcCounts;

  // Adc counts for Beam 3 in Ring 6
  TH1D * theBeam3Ring6Disc1PosAdcCounts;
  TH1D * theBeam3Ring6Disc2PosAdcCounts;
  TH1D * theBeam3Ring6Disc3PosAdcCounts;
  TH1D * theBeam3Ring6Disc4PosAdcCounts;
  TH1D * theBeam3Ring6Disc5PosAdcCounts;
  TH1D * theBeam3Ring6Disc6PosAdcCounts;
  TH1D * theBeam3Ring6Disc7PosAdcCounts;
  TH1D * theBeam3Ring6Disc8PosAdcCounts;
  TH1D * theBeam3Ring6Disc9PosAdcCounts;

  // Adc counts for Beam 4 in Ring 6
  TH1D * theBeam4Ring6Disc1PosAdcCounts;
  TH1D * theBeam4Ring6Disc2PosAdcCounts;
  TH1D * theBeam4Ring6Disc3PosAdcCounts;
  TH1D * theBeam4Ring6Disc4PosAdcCounts;
  TH1D * theBeam4Ring6Disc5PosAdcCounts;
  TH1D * theBeam4Ring6Disc6PosAdcCounts;
  TH1D * theBeam4Ring6Disc7PosAdcCounts;
  TH1D * theBeam4Ring6Disc8PosAdcCounts;
  TH1D * theBeam4Ring6Disc9PosAdcCounts;

  // Adc counts for Beam 5 in Ring 6
  TH1D * theBeam5Ring6Disc1PosAdcCounts;
  TH1D * theBeam5Ring6Disc2PosAdcCounts;
  TH1D * theBeam5Ring6Disc3PosAdcCounts;
  TH1D * theBeam5Ring6Disc4PosAdcCounts;
  TH1D * theBeam5Ring6Disc5PosAdcCounts;
  TH1D * theBeam5Ring6Disc6PosAdcCounts;
  TH1D * theBeam5Ring6Disc7PosAdcCounts;
  TH1D * theBeam5Ring6Disc8PosAdcCounts;
  TH1D * theBeam5Ring6Disc9PosAdcCounts;

  // Adc counts for Beam 6 in Ring 6
  TH1D * theBeam6Ring6Disc1PosAdcCounts;
  TH1D * theBeam6Ring6Disc2PosAdcCounts;
  TH1D * theBeam6Ring6Disc3PosAdcCounts;
  TH1D * theBeam6Ring6Disc4PosAdcCounts;
  TH1D * theBeam6Ring6Disc5PosAdcCounts;
  TH1D * theBeam6Ring6Disc6PosAdcCounts;
  TH1D * theBeam6Ring6Disc7PosAdcCounts;
  TH1D * theBeam6Ring6Disc8PosAdcCounts;
  TH1D * theBeam6Ring6Disc9PosAdcCounts;

  // Adc counts for Beam 7 in Ring 6
  TH1D * theBeam7Ring6Disc1PosAdcCounts;
  TH1D * theBeam7Ring6Disc2PosAdcCounts;
  TH1D * theBeam7Ring6Disc3PosAdcCounts;
  TH1D * theBeam7Ring6Disc4PosAdcCounts;
  TH1D * theBeam7Ring6Disc5PosAdcCounts;
  TH1D * theBeam7Ring6Disc6PosAdcCounts;
  TH1D * theBeam7Ring6Disc7PosAdcCounts;
  TH1D * theBeam7Ring6Disc8PosAdcCounts;
  TH1D * theBeam7Ring6Disc9PosAdcCounts;

  /* Laser Beams in TEC- */
  // Adc counts for Beam 0 in Ring 4
  TH1D * theBeam0Ring4Disc1NegAdcCounts;
  TH1D * theBeam0Ring4Disc2NegAdcCounts;
  TH1D * theBeam0Ring4Disc3NegAdcCounts;
  TH1D * theBeam0Ring4Disc4NegAdcCounts;
  TH1D * theBeam0Ring4Disc5NegAdcCounts;
  TH1D * theBeam0Ring4Disc6NegAdcCounts;
  TH1D * theBeam0Ring4Disc7NegAdcCounts;
  TH1D * theBeam0Ring4Disc8NegAdcCounts;
  TH1D * theBeam0Ring4Disc9NegAdcCounts;

  // Adc counts for Beam 1 in Ring 4
  TH1D * theBeam1Ring4Disc1NegAdcCounts;
  TH1D * theBeam1Ring4Disc2NegAdcCounts;
  TH1D * theBeam1Ring4Disc3NegAdcCounts;
  TH1D * theBeam1Ring4Disc4NegAdcCounts;
  TH1D * theBeam1Ring4Disc5NegAdcCounts;
  TH1D * theBeam1Ring4Disc6NegAdcCounts;
  TH1D * theBeam1Ring4Disc7NegAdcCounts;
  TH1D * theBeam1Ring4Disc8NegAdcCounts;
  TH1D * theBeam1Ring4Disc9NegAdcCounts;

  // plots for TEC2TEC
  TH1D * theBeam1Ring4Disc1NegTEC2TECAdcCounts;
  TH1D * theBeam1Ring4Disc2NegTEC2TECAdcCounts;
  TH1D * theBeam1Ring4Disc3NegTEC2TECAdcCounts;
  TH1D * theBeam1Ring4Disc4NegTEC2TECAdcCounts;
  TH1D * theBeam1Ring4Disc5NegTEC2TECAdcCounts;

  // Adc counts for Beam 2 in Ring 4
  TH1D * theBeam2Ring4Disc1NegAdcCounts;
  TH1D * theBeam2Ring4Disc2NegAdcCounts;
  TH1D * theBeam2Ring4Disc3NegAdcCounts;
  TH1D * theBeam2Ring4Disc4NegAdcCounts;
  TH1D * theBeam2Ring4Disc5NegAdcCounts;
  TH1D * theBeam2Ring4Disc6NegAdcCounts;
  TH1D * theBeam2Ring4Disc7NegAdcCounts;
  TH1D * theBeam2Ring4Disc8NegAdcCounts;
  TH1D * theBeam2Ring4Disc9NegAdcCounts;

  // plots for TEC2TEC
  TH1D * theBeam2Ring4Disc1NegTEC2TECAdcCounts;
  TH1D * theBeam2Ring4Disc2NegTEC2TECAdcCounts;
  TH1D * theBeam2Ring4Disc3NegTEC2TECAdcCounts;
  TH1D * theBeam2Ring4Disc4NegTEC2TECAdcCounts;
  TH1D * theBeam2Ring4Disc5NegTEC2TECAdcCounts;

  // Adc counts for Beam 3 in Ring 4
  TH1D * theBeam3Ring4Disc1NegAdcCounts;
  TH1D * theBeam3Ring4Disc2NegAdcCounts;
  TH1D * theBeam3Ring4Disc3NegAdcCounts;
  TH1D * theBeam3Ring4Disc4NegAdcCounts;
  TH1D * theBeam3Ring4Disc5NegAdcCounts;
  TH1D * theBeam3Ring4Disc6NegAdcCounts;
  TH1D * theBeam3Ring4Disc7NegAdcCounts;
  TH1D * theBeam3Ring4Disc8NegAdcCounts;
  TH1D * theBeam3Ring4Disc9NegAdcCounts;

  // Adc counts for Beam 4 in Ring 4
  TH1D * theBeam4Ring4Disc1NegAdcCounts;
  TH1D * theBeam4Ring4Disc2NegAdcCounts;
  TH1D * theBeam4Ring4Disc3NegAdcCounts;
  TH1D * theBeam4Ring4Disc4NegAdcCounts;
  TH1D * theBeam4Ring4Disc5NegAdcCounts;
  TH1D * theBeam4Ring4Disc6NegAdcCounts;
  TH1D * theBeam4Ring4Disc7NegAdcCounts;
  TH1D * theBeam4Ring4Disc8NegAdcCounts;
  TH1D * theBeam4Ring4Disc9NegAdcCounts;

  // plots for TEC2TEC
  TH1D * theBeam4Ring4Disc1NegTEC2TECAdcCounts;
  TH1D * theBeam4Ring4Disc2NegTEC2TECAdcCounts;
  TH1D * theBeam4Ring4Disc3NegTEC2TECAdcCounts;
  TH1D * theBeam4Ring4Disc4NegTEC2TECAdcCounts;
  TH1D * theBeam4Ring4Disc5NegTEC2TECAdcCounts;

  // Adc counts for Beam 5 in Ring 4
  TH1D * theBeam5Ring4Disc1NegAdcCounts;
  TH1D * theBeam5Ring4Disc2NegAdcCounts;
  TH1D * theBeam5Ring4Disc3NegAdcCounts;
  TH1D * theBeam5Ring4Disc4NegAdcCounts;
  TH1D * theBeam5Ring4Disc5NegAdcCounts;
  TH1D * theBeam5Ring4Disc6NegAdcCounts;
  TH1D * theBeam5Ring4Disc7NegAdcCounts;
  TH1D * theBeam5Ring4Disc8NegAdcCounts;
  TH1D * theBeam5Ring4Disc9NegAdcCounts;

  // Adc counts for Beam 6 in Ring 4
  TH1D * theBeam6Ring4Disc1NegAdcCounts;
  TH1D * theBeam6Ring4Disc2NegAdcCounts;
  TH1D * theBeam6Ring4Disc3NegAdcCounts;
  TH1D * theBeam6Ring4Disc4NegAdcCounts;
  TH1D * theBeam6Ring4Disc5NegAdcCounts;
  TH1D * theBeam6Ring4Disc6NegAdcCounts;
  TH1D * theBeam6Ring4Disc7NegAdcCounts;
  TH1D * theBeam6Ring4Disc8NegAdcCounts;
  TH1D * theBeam6Ring4Disc9NegAdcCounts;

  // plots for TEC2TEC
  TH1D * theBeam6Ring4Disc1NegTEC2TECAdcCounts;
  TH1D * theBeam6Ring4Disc2NegTEC2TECAdcCounts;
  TH1D * theBeam6Ring4Disc3NegTEC2TECAdcCounts;
  TH1D * theBeam6Ring4Disc4NegTEC2TECAdcCounts;
  TH1D * theBeam6Ring4Disc5NegTEC2TECAdcCounts;

  // Adc counts for Beam 7 in Ring 4
  TH1D * theBeam7Ring4Disc1NegAdcCounts;
  TH1D * theBeam7Ring4Disc2NegAdcCounts;
  TH1D * theBeam7Ring4Disc3NegAdcCounts;
  TH1D * theBeam7Ring4Disc4NegAdcCounts;
  TH1D * theBeam7Ring4Disc5NegAdcCounts;
  TH1D * theBeam7Ring4Disc6NegAdcCounts;
  TH1D * theBeam7Ring4Disc7NegAdcCounts;
  TH1D * theBeam7Ring4Disc8NegAdcCounts;
  TH1D * theBeam7Ring4Disc9NegAdcCounts;

  // plots for TEC2TEC
  TH1D * theBeam7Ring4Disc1NegTEC2TECAdcCounts;
  TH1D * theBeam7Ring4Disc2NegTEC2TECAdcCounts;
  TH1D * theBeam7Ring4Disc3NegTEC2TECAdcCounts;
  TH1D * theBeam7Ring4Disc4NegTEC2TECAdcCounts;
  TH1D * theBeam7Ring4Disc5NegTEC2TECAdcCounts;

  // Adc counts for Beam 0 in Ring 6
  TH1D * theBeam0Ring6Disc1NegAdcCounts;
  TH1D * theBeam0Ring6Disc2NegAdcCounts;
  TH1D * theBeam0Ring6Disc3NegAdcCounts;
  TH1D * theBeam0Ring6Disc4NegAdcCounts;
  TH1D * theBeam0Ring6Disc5NegAdcCounts;
  TH1D * theBeam0Ring6Disc6NegAdcCounts;
  TH1D * theBeam0Ring6Disc7NegAdcCounts;
  TH1D * theBeam0Ring6Disc8NegAdcCounts;
  TH1D * theBeam0Ring6Disc9NegAdcCounts;

  // Adc counts for Beam 1 in Ring 6
  TH1D * theBeam1Ring6Disc1NegAdcCounts;
  TH1D * theBeam1Ring6Disc2NegAdcCounts;
  TH1D * theBeam1Ring6Disc3NegAdcCounts;
  TH1D * theBeam1Ring6Disc4NegAdcCounts;
  TH1D * theBeam1Ring6Disc5NegAdcCounts;
  TH1D * theBeam1Ring6Disc6NegAdcCounts;
  TH1D * theBeam1Ring6Disc7NegAdcCounts;
  TH1D * theBeam1Ring6Disc8NegAdcCounts;
  TH1D * theBeam1Ring6Disc9NegAdcCounts;

  // Adc counts for Beam 2 in Ring 6
  TH1D * theBeam2Ring6Disc1NegAdcCounts;
  TH1D * theBeam2Ring6Disc2NegAdcCounts;
  TH1D * theBeam2Ring6Disc3NegAdcCounts;
  TH1D * theBeam2Ring6Disc4NegAdcCounts;
  TH1D * theBeam2Ring6Disc5NegAdcCounts;
  TH1D * theBeam2Ring6Disc6NegAdcCounts;
  TH1D * theBeam2Ring6Disc7NegAdcCounts;
  TH1D * theBeam2Ring6Disc8NegAdcCounts;
  TH1D * theBeam2Ring6Disc9NegAdcCounts;

  // Adc counts for Beam 3 in Ring 6
  TH1D * theBeam3Ring6Disc1NegAdcCounts;
  TH1D * theBeam3Ring6Disc2NegAdcCounts;
  TH1D * theBeam3Ring6Disc3NegAdcCounts;
  TH1D * theBeam3Ring6Disc4NegAdcCounts;
  TH1D * theBeam3Ring6Disc5NegAdcCounts;
  TH1D * theBeam3Ring6Disc6NegAdcCounts;
  TH1D * theBeam3Ring6Disc7NegAdcCounts;
  TH1D * theBeam3Ring6Disc8NegAdcCounts;
  TH1D * theBeam3Ring6Disc9NegAdcCounts;

  // Adc counts for Beam 4 in Ring 6
  TH1D * theBeam4Ring6Disc1NegAdcCounts;
  TH1D * theBeam4Ring6Disc2NegAdcCounts;
  TH1D * theBeam4Ring6Disc3NegAdcCounts;
  TH1D * theBeam4Ring6Disc4NegAdcCounts;
  TH1D * theBeam4Ring6Disc5NegAdcCounts;
  TH1D * theBeam4Ring6Disc6NegAdcCounts;
  TH1D * theBeam4Ring6Disc7NegAdcCounts;
  TH1D * theBeam4Ring6Disc8NegAdcCounts;
  TH1D * theBeam4Ring6Disc9NegAdcCounts;

  // Adc counts for Beam 5 in Ring 6
  TH1D * theBeam5Ring6Disc1NegAdcCounts;
  TH1D * theBeam5Ring6Disc2NegAdcCounts;
  TH1D * theBeam5Ring6Disc3NegAdcCounts;
  TH1D * theBeam5Ring6Disc4NegAdcCounts;
  TH1D * theBeam5Ring6Disc5NegAdcCounts;
  TH1D * theBeam5Ring6Disc6NegAdcCounts;
  TH1D * theBeam5Ring6Disc7NegAdcCounts;
  TH1D * theBeam5Ring6Disc8NegAdcCounts;
  TH1D * theBeam5Ring6Disc9NegAdcCounts;

  // Adc counts for Beam 6 in Ring 6
  TH1D * theBeam6Ring6Disc1NegAdcCounts;
  TH1D * theBeam6Ring6Disc2NegAdcCounts;
  TH1D * theBeam6Ring6Disc3NegAdcCounts;
  TH1D * theBeam6Ring6Disc4NegAdcCounts;
  TH1D * theBeam6Ring6Disc5NegAdcCounts;
  TH1D * theBeam6Ring6Disc6NegAdcCounts;
  TH1D * theBeam6Ring6Disc7NegAdcCounts;
  TH1D * theBeam6Ring6Disc8NegAdcCounts;
  TH1D * theBeam6Ring6Disc9NegAdcCounts;

  // Adc counts for Beam 7 in Ring 6
  TH1D * theBeam7Ring6Disc1NegAdcCounts;
  TH1D * theBeam7Ring6Disc2NegAdcCounts;
  TH1D * theBeam7Ring6Disc3NegAdcCounts;
  TH1D * theBeam7Ring6Disc4NegAdcCounts;
  TH1D * theBeam7Ring6Disc5NegAdcCounts;
  TH1D * theBeam7Ring6Disc6NegAdcCounts;
  TH1D * theBeam7Ring6Disc7NegAdcCounts;
  TH1D * theBeam7Ring6Disc8NegAdcCounts;
  TH1D * theBeam7Ring6Disc9NegAdcCounts;

  // TOB Beams
  // Adc counts for Beam 0
  TH1D * theBeam0TOBPosition1AdcCounts;
  TH1D * theBeam0TOBPosition2AdcCounts;
  TH1D * theBeam0TOBPosition3AdcCounts;
  TH1D * theBeam0TOBPosition4AdcCounts;
  TH1D * theBeam0TOBPosition5AdcCounts;
  TH1D * theBeam0TOBPosition6AdcCounts;

  // Adc counts for Beam 1
  TH1D * theBeam1TOBPosition1AdcCounts;
  TH1D * theBeam1TOBPosition2AdcCounts;
  TH1D * theBeam1TOBPosition3AdcCounts;
  TH1D * theBeam1TOBPosition4AdcCounts;
  TH1D * theBeam1TOBPosition5AdcCounts;
  TH1D * theBeam1TOBPosition6AdcCounts;

  // Adc counts for Beam 2
  TH1D * theBeam2TOBPosition1AdcCounts;
  TH1D * theBeam2TOBPosition2AdcCounts;
  TH1D * theBeam2TOBPosition3AdcCounts;
  TH1D * theBeam2TOBPosition4AdcCounts;
  TH1D * theBeam2TOBPosition5AdcCounts;
  TH1D * theBeam2TOBPosition6AdcCounts;

  // Adc counts for Beam 3
  TH1D * theBeam3TOBPosition1AdcCounts;
  TH1D * theBeam3TOBPosition2AdcCounts;
  TH1D * theBeam3TOBPosition3AdcCounts;
  TH1D * theBeam3TOBPosition4AdcCounts;
  TH1D * theBeam3TOBPosition5AdcCounts;
  TH1D * theBeam3TOBPosition6AdcCounts;

  // Adc counts for Beam 4
  TH1D * theBeam4TOBPosition1AdcCounts;
  TH1D * theBeam4TOBPosition2AdcCounts;
  TH1D * theBeam4TOBPosition3AdcCounts;
  TH1D * theBeam4TOBPosition4AdcCounts;
  TH1D * theBeam4TOBPosition5AdcCounts;
  TH1D * theBeam4TOBPosition6AdcCounts;

  // Adc counts for Beam 5
  TH1D * theBeam5TOBPosition1AdcCounts;
  TH1D * theBeam5TOBPosition2AdcCounts;
  TH1D * theBeam5TOBPosition3AdcCounts;
  TH1D * theBeam5TOBPosition4AdcCounts;
  TH1D * theBeam5TOBPosition5AdcCounts;
  TH1D * theBeam5TOBPosition6AdcCounts;

  // Adc counts for Beam 6
  TH1D * theBeam6TOBPosition1AdcCounts;
  TH1D * theBeam6TOBPosition2AdcCounts;
  TH1D * theBeam6TOBPosition3AdcCounts;
  TH1D * theBeam6TOBPosition4AdcCounts;
  TH1D * theBeam6TOBPosition5AdcCounts;
  TH1D * theBeam6TOBPosition6AdcCounts;

  // Adc counts for Beam 7
  TH1D * theBeam7TOBPosition1AdcCounts;
  TH1D * theBeam7TOBPosition2AdcCounts;
  TH1D * theBeam7TOBPosition3AdcCounts;
  TH1D * theBeam7TOBPosition4AdcCounts;
  TH1D * theBeam7TOBPosition5AdcCounts;
  TH1D * theBeam7TOBPosition6AdcCounts;

  // TIB Beams
  // Adc counts for Beam 0
  TH1D * theBeam0TIBPosition1AdcCounts;
  TH1D * theBeam0TIBPosition2AdcCounts;
  TH1D * theBeam0TIBPosition3AdcCounts;
  TH1D * theBeam0TIBPosition4AdcCounts;
  TH1D * theBeam0TIBPosition5AdcCounts;
  TH1D * theBeam0TIBPosition6AdcCounts;

  // Adc counts for Beam 1
  TH1D * theBeam1TIBPosition1AdcCounts;
  TH1D * theBeam1TIBPosition2AdcCounts;
  TH1D * theBeam1TIBPosition3AdcCounts;
  TH1D * theBeam1TIBPosition4AdcCounts;
  TH1D * theBeam1TIBPosition5AdcCounts;
  TH1D * theBeam1TIBPosition6AdcCounts;

  // Adc counts for Beam 2
  TH1D * theBeam2TIBPosition1AdcCounts;
  TH1D * theBeam2TIBPosition2AdcCounts;
  TH1D * theBeam2TIBPosition3AdcCounts;
  TH1D * theBeam2TIBPosition4AdcCounts;
  TH1D * theBeam2TIBPosition5AdcCounts;
  TH1D * theBeam2TIBPosition6AdcCounts;

  // Adc counts for Beam 3
  TH1D * theBeam3TIBPosition1AdcCounts;
  TH1D * theBeam3TIBPosition2AdcCounts;
  TH1D * theBeam3TIBPosition3AdcCounts;
  TH1D * theBeam3TIBPosition4AdcCounts;
  TH1D * theBeam3TIBPosition5AdcCounts;
  TH1D * theBeam3TIBPosition6AdcCounts;

  // Adc counts for Beam 4
  TH1D * theBeam4TIBPosition1AdcCounts;
  TH1D * theBeam4TIBPosition2AdcCounts;
  TH1D * theBeam4TIBPosition3AdcCounts;
  TH1D * theBeam4TIBPosition4AdcCounts;
  TH1D * theBeam4TIBPosition5AdcCounts;
  TH1D * theBeam4TIBPosition6AdcCounts;

  // Adc counts for Beam 5
  TH1D * theBeam5TIBPosition1AdcCounts;
  TH1D * theBeam5TIBPosition2AdcCounts;
  TH1D * theBeam5TIBPosition3AdcCounts;
  TH1D * theBeam5TIBPosition4AdcCounts;
  TH1D * theBeam5TIBPosition5AdcCounts;
  TH1D * theBeam5TIBPosition6AdcCounts;

  // Adc counts for Beam 6
  TH1D * theBeam6TIBPosition1AdcCounts;
  TH1D * theBeam6TIBPosition2AdcCounts;
  TH1D * theBeam6TIBPosition3AdcCounts;
  TH1D * theBeam6TIBPosition4AdcCounts;
  TH1D * theBeam6TIBPosition5AdcCounts;
  TH1D * theBeam6TIBPosition6AdcCounts;

  // Adc counts for Beam 7
  TH1D * theBeam7TIBPosition1AdcCounts;
  TH1D * theBeam7TIBPosition2AdcCounts;
  TH1D * theBeam7TIBPosition3AdcCounts;
  TH1D * theBeam7TIBPosition4AdcCounts;
  TH1D * theBeam7TIBPosition5AdcCounts;
  TH1D * theBeam7TIBPosition6AdcCounts;

  // clusters
  TH1D * theClusterPositions;

  // RecHits
  TH1D * theRecHitPositionsX;
  TH1D * theRecHitPositionsY;
  TH1D * theRecHitPositionsZ;
  TH2D * theRecHitPositionsYvsX;
  TH2D * theRecHitPositionsPhivsZ;
  TH2D * theRecHitPositionsRvsZ;
};
#endif
