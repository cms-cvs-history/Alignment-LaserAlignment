#ifndef LaserAlignment_ReadLaserRecHit_h
#define LaserAlignment_ReadLaserRecHit_h

/** \class ReadLaserRecHit
 *  small test program to read the RecHits from the laser beams
 *
 *  $Date: Sun Mar 18 19:50:27 CET 2007 $
 *  $Revision: 1.1 $
 *  \author Maarten Thomas
 */

#include <memory>
#include <string>
#include <iostream>

#include "DataFormats/Common/interface/Handle.h"
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
  /// constructor
  explicit ReadLaserRecHit(const edm::ParameterSet& conf);
  /// destructor
  virtual ~ReadLaserRecHit();
  /// analyze the event content
  virtual void analyze(const edm::Event& e, const edm::EventSetup& c);
  
 private:
  ReadLaserRecHitAlgorithm readRecHitAlgorithm_;
  edm::ParameterSet conf_;
  
};
#endif
