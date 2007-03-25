#ifndef LaserAlignment_ReadLaserRecHitAlgorithm_h
#define LaserAlignment_ReadLaserRecHitAlgorithm_h

/** \class ReadLaserRecHitAlgorithm
 *  Algorithm to read RecHits from the LaserBeams
 *
 *  $Date: 2007/03/18 19:00:21 $
 *  $Revision: 1.4 $
 *  \author Maarten Thomas
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "Geometry/TrackerGeometryBuilder/interface/StripGeomDetUnit.h"
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "Geometry/CommonTopologies/interface/RectangularStripTopology.h"
#include "Geometry/CommonTopologies/interface/TrapezoidalStripTopology.h"
#include "DataFormats/GeometryCommonDetAlgo/interface/MeasurementPoint.h"

#include "DataFormats/GeometrySurface/interface/LocalError.h"
#include "DataFormats/GeometryVector/interface/LocalPoint.h"
#include "DataFormats/GeometryVector/interface/GlobalPoint.h"
#include "DataFormats/GeometryCommonDetAlgo/interface/GlobalError.h"
#include "DataFormats/GeometryCommonDetAlgo/interface/ErrorFrameTransformer.h"

#include "DataFormats/SiStripDetId/interface/StripSubdetector.h"
#include "DataFormats/SiStripDetId/interface/TIBDetId.h"
#include "DataFormats/SiStripDetId/interface/TOBDetId.h"
#include "DataFormats/SiStripDetId/interface/TIDDetId.h"
#include "DataFormats/SiStripDetId/interface/TECDetId.h"
#include "DataFormats/TrackerRecHit2D/interface/SiStripRecHit2DCollection.h"
#include "DataFormats/TrackerRecHit2D/interface/SiStripMatchedRecHit2DCollection.h"
#include "DataFormats/Common/interface/OwnVector.h"
#include "DataFormats/SiStripCluster/interface/SiStripCluster.h"

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
