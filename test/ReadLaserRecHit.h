/* 
 * small test program to read RecHits from the laser beams
 */

#ifndef LaserAlignment_ReadLaserRecHit_h
#define LaserAlignment_ReadLaserRecHit_h

#include <memory>
#include <string>
#include <iostream>

#include "FWCore/Framework/interface/Handle.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/TrackerRecHit2D/interface/SiStripRecHit2DCollection.h"
#include "DataFormats/TrackerRecHit2D/interface/SiStripMatchedRecHit2DCollection.h"
#include "DataFormats/Common/interface/EDProduct.h"

#include "Alignment/LaserAlignment/test/ReadLaserRecHitAlgorithm.h"

class ReadLaserRecHit : public edm::EDAnalyzer
{
 public:
  
  explicit ReadLaserRecHit(const edm::ParameterSet& conf);
  
  virtual ~ReadLaserRecHit();
  
  virtual void analyze(const edm::Event& e, const edm::EventSetup& c);
  
 private:
  ReadLaserRecHitAlgorithm readRecHitAlgorithm_;
  edm::ParameterSet conf_;
  
};
#endif
