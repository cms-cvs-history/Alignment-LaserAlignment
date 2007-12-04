#ifndef LaserAlignment_ReadLaserRecHit_h
#define LaserAlignment_ReadLaserRecHit_h

/** \class ReadLaserRecHit
 *  small test program to read the RecHits from the laser beams
 *
 *  $Date: 2007/03/18 19:00:21 $
 *  $Revision: 1.3 $
 *  \author Maarten Thomas
 */

#include <memory>
#include <string>
#include <iostream>

#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"


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
