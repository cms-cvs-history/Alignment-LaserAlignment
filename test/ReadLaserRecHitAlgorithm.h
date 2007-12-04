#ifndef LaserAlignment_ReadLaserRecHitAlgorithm_h
#define LaserAlignment_ReadLaserRecHitAlgorithm_h

/** \class ReadLaserRecHitAlgorithm
 *  Algorithm to read RecHits from the LaserBeams
 *
 *  $Date: 2007/03/25 17:26:51 $
 *  $Revision: 1.5 $
 *  \author Maarten Thomas
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"


#include "DataFormats/TrackerRecHit2D/interface/SiStripRecHit2DCollection.h"
#include "DataFormats/TrackerRecHit2D/interface/SiStripMatchedRecHit2DCollection.h"
#include "DataFormats/Common/interface/OwnVector.h"

class ReadLaserRecHitAlgorithm 
{
 public:
  /// constructor
  ReadLaserRecHitAlgorithm(const edm::ParameterSet& conf);
  /// destructor
  ~ReadLaserRecHitAlgorithm();
  

  /// Runs the algorithm on a SiStripRecHit2DCollection
  void run(const SiStripRecHit2DCollection* input, const edm::EventSetup& theSetup);
  /// Runs the algorithm on a SiStripMatchedRecHit2DCollection
  void run(const SiStripMatchedRecHit2DCollection* input, const edm::EventSetup& theSetup);

 private:

  edm::ParameterSet conf_;
};
#endif
