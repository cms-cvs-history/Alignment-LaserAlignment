#ifndef LaserAlignment_LaserHitPairGeneratorFromLayerPair_h
#define LaserAlignment_LaserHitPairGeneratorFromLayerPair_h

/** \class CompareHitPairsZ
 *  compare hit pairs in z direction
 *
 *  $Date: 2007/05/10 10:38:15 $
 *  $Revision: 1.13 $
 *  \author Maarten Thomas
 */

/** \class LaserHitPairGeneratorFromLayerPair
 *  generate hit pairs from hits on consecutive discs in the endcaps used by the LaserSeedGenerator
 *
 *  $Date: 2007/05/10 10:38:15 $
 *  $Revision: 1.13 $
 *  \author Maarten Thomas
 */

#include "Alignment/LaserAlignment/interface/LaserHitPairGenerator.h"
#include "Alignment/LaserAlignment/interface/OrderedLaserHitPair.h"
#include "Alignment/LaserAlignment/interface/OrderedLaserHitPairs.h"
#include "Alignment/LaserAlignment/interface/LayerWithHits.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "FWCore/Framework/interface/EventSetup.h"

class DetLayer;
class TrackingRegion;
class LayerWithHits;

class CompareHitPairsZ
{
 public:
	/// compare hit pairs in z direction
  CompareHitPairsZ(const edm::EventSetup& iSetup)
    { iSetup.get<TrackerDigiGeometryRecord>().get(tracker); };

  bool operator() ( OrderedLaserHitPair h1, OrderedLaserHitPair h2)
  {
    GlobalPoint in1p = tracker->idToDet((*(h1.inner())).geographicalId())->surface().toGlobal((*(h1.inner())).localPosition());
    GlobalPoint in2p = tracker->idToDet((*(h2.inner())).geographicalId())->surface().toGlobal((*(h2.inner())).localPosition());
    GlobalPoint ou1p = tracker->idToDet((*(h1.outer())).geographicalId())->surface().toGlobal((*(h1.outer())).localPosition());
    GlobalPoint ou2p = tracker->idToDet((*(h2.outer())).geographicalId())->surface().toGlobal((*(h2.outer())).localPosition());

    if (ou1p.z() * ou2p.z() < 0.0) return ou1p.z() > ou2p.z();
    else
      {
	double dist1 = 100.0 * fabs(ou1p.z() - in1p.z());
	double dist2 = 100.0 * fabs(ou2p.z() - in2p.z());
	return dist1 < dist2;
      }
  }

 private:
  edm::ESHandle<TrackerGeometry> tracker;

};

class LaserHitPairGeneratorFromLayerPair
{
 public:
	/// constructor
  	LaserHitPairGeneratorFromLayerPair(const LayerWithHits * inner, const LayerWithHits * outer, 
			const edm::EventSetup & iSetup);

	/// destructor
  virtual ~LaserHitPairGeneratorFromLayerPair() {}

	/// from base class
  virtual void hitPairs(const TrackingRegion & ar, OrderedLaserHitPairs & ap, const edm::EventSetup & iSetup);

  virtual LaserHitPairGeneratorFromLayerPair * clone() const 
  {
    return new LaserHitPairGeneratorFromLayerPair(*this);
  }

	/// return inner layer
  const LayerWithHits * innerLayer() const { return theInnerLayer; }
	/// return outer layer
  const LayerWithHits * outerLayer() const { return theOuterLayer; }

 private:
  // all data members are "shallow copy" 
  const TrackerGeometry* trackerGeometry;
  const LayerWithHits * theInnerLayer;
  const LayerWithHits * theOuterLayer;
  const DetLayer * innerlay;
  const DetLayer * outerlay;
};

#endif
