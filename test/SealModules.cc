
#include "PluginManager/ModuleDef.h"

#include "FWCore/Framework/interface/MakerMacros.h"

#include "Alignment/LaserAlignment/test/ReadLaserRecHit.h"
DEFINE_FWK_MODULE(ReadLaserRecHit);

#include "Alignment/LaserAlignment/test/RecoAnalyzer.h"
DEFINE_ANOTHER_FWK_MODULE(RecoAnalyzer);

#include "Alignment/LaserAlignment/test/ExpectedAlignmentCorrectionsCalculator.h"
DEFINE_ANOTHER_FWK_MODULE(ExpectedAlignmentCorrectionsCalculator);
