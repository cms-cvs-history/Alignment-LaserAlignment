#ifndef LaserAlignment_BeamProfileFitter_h
#define LaserAlignment_BeamProfileFitter_h

/** \class BeamProfileFitter
 *  Fitting laser profiles from the beams in the Laser Alignment System
 *
 *  $Date: 2007/03/16 14:29:55 $
 *  $Revision: 1.2 $
 *  \author Maarten Thomas
 */

// Framework headers
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

// DetId
#include "DataFormats/DetId/interface/DetId.h"

// the result of the fit will be stored into the edm
#include "DataFormats/LaserAlignment/interface/LASBeamProfileFit.h"

// ROOT headers
#include "TH1.h"
#include "TVector2.h"
#include "TVector3.h"
#include "TMatrix.h"
#include "TSpectrum.h"
#include "TVirtualFitter.h"
#include "TF1.h"
#include "TMinuit.h"

#include <string>
#include <iostream>

class BeamProfileFitter {
 public:
  /// default constructor
  BeamProfileFitter(edm::ParameterSet const& theConf);
  
  /// default destructor
  ~BeamProfileFitter();
  
  /// fitting routine
  std::vector<LASBeamProfileFit> doFit(const edm::EventSetup& theSetup, 
				       DetId theDetUnitId, TH1D * theHistogram, 
				       bool theSaveHistograms, 
				       int ScalingFactor, int theBeam, 
				       int theDisc, int theRing, 
				       int theSide, bool isTEC2TEC, 
				       bool & isGoodResult );

  /// the peakfinder
  std::vector<double> findPeakGaus(TH1D* theHist, int theDisc, int theRing);

 private:
  bool theClearHistoAfterFit;
  bool theScaleHisto;
  double theMinSignalHeight;

  /// function to calculate the error on phi
  Double_t phiError(TVector3 thePosition, TMatrix theCovarianceMatrix);
  
  /// function to calculate an angle between 0 and 2*Pi
  double angle(double theAngle);
};
#endif
