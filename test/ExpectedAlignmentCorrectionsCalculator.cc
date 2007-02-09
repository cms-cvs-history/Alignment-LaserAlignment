/*
 * Calculate the expected alignment
 * corrections from the applied misalignments
 */

#include "Alignment/LaserAlignment/test/ExpectedAlignmentCorrectionsCalculator.h"

// system include files
#include <memory>
#include <math.h>

// user include files
#include "FWCore/MessageLogger/interface/MessageLogger.h"


ExpectedAlignmentCorrectionsCalculator::ExpectedAlignmentCorrectionsCalculator(const edm::ParameterSet& iConfig)
  : thePosEndcapLayerShiftsX(), thePosEndcapLayerShiftsY(), thePosEndcapLayerRotationsZ(), thePosExpectedPhi(),thePosAbsExpectedPhi(),
    theNegEndcapLayerShiftsX(), theNegEndcapLayerShiftsY(), theNegEndcapLayerRotationsZ(), theNegExpectedPhi(),
    theTEC2TECShiftsX(), theTEC2TECShiftsY(), theTEC2TECRotationsZ(), theTEC2TECExpectedPhi()
{
   //now do what ever initialization is needed
  thePosEndcapLayerShiftsX.clear();
  thePosEndcapLayerShiftsY.clear();
  thePosEndcapLayerRotationsZ.clear();
  thePosExpectedPhi.clear();
  thePosAbsExpectedPhi.clear();

  theNegEndcapLayerShiftsX.clear();
  theNegEndcapLayerShiftsY.clear();
  theNegEndcapLayerRotationsZ.clear();
  theNegExpectedPhi.clear();

  theTEC2TECShiftsX.clear();
  theTEC2TECShiftsY.clear();
  theTEC2TECRotationsZ.clear();
  theTEC2TECExpectedPhi.clear();

  // for TEC 1
  // get the applied misalignments to calculate the expected corrections and compare them to the corrections given by the alignment algorithm
  // get the applied shifts in x 
  thePosEndcapLayerShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer1").getParameter<double>("dX"));
  thePosEndcapLayerShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer2").getParameter<double>("dX"));
  thePosEndcapLayerShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer3").getParameter<double>("dX"));
  thePosEndcapLayerShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer4").getParameter<double>("dX"));
  thePosEndcapLayerShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer5").getParameter<double>("dX"));
  thePosEndcapLayerShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer6").getParameter<double>("dX"));
  thePosEndcapLayerShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer7").getParameter<double>("dX"));
  thePosEndcapLayerShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer8").getParameter<double>("dX"));
  thePosEndcapLayerShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer9").getParameter<double>("dX"));

  // get the applied shifts in y
  thePosEndcapLayerShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer1").getParameter<double>("dY"));
  thePosEndcapLayerShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer2").getParameter<double>("dY"));
  thePosEndcapLayerShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer3").getParameter<double>("dY"));
  thePosEndcapLayerShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer4").getParameter<double>("dY"));
  thePosEndcapLayerShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer5").getParameter<double>("dY"));
  thePosEndcapLayerShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer6").getParameter<double>("dY"));
  thePosEndcapLayerShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer7").getParameter<double>("dY"));
  thePosEndcapLayerShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer8").getParameter<double>("dY"));
  thePosEndcapLayerShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer9").getParameter<double>("dY"));

  // get the applied rotations around the z-axis
  thePosEndcapLayerRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer1").getParameter<double>("phiZ"));
  thePosEndcapLayerRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer2").getParameter<double>("phiZ"));
  thePosEndcapLayerRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer3").getParameter<double>("phiZ"));
  thePosEndcapLayerRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer4").getParameter<double>("phiZ"));
  thePosEndcapLayerRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer5").getParameter<double>("phiZ"));
  thePosEndcapLayerRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer6").getParameter<double>("phiZ"));
  thePosEndcapLayerRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer7").getParameter<double>("phiZ"));
  thePosEndcapLayerRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer8").getParameter<double>("phiZ"));
  thePosEndcapLayerRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer9").getParameter<double>("phiZ"));


  // for TEC 2
  // get the applied misalignments to calculate the expected corrections and compare them to the corrections given by the alignment algorithm
  // get the applied shifts in x
  theNegEndcapLayerShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer1").getParameter<double>("dX"));
  theNegEndcapLayerShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer2").getParameter<double>("dX"));
  theNegEndcapLayerShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer3").getParameter<double>("dX"));
  theNegEndcapLayerShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer4").getParameter<double>("dX"));
  theNegEndcapLayerShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer5").getParameter<double>("dX"));
  theNegEndcapLayerShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer6").getParameter<double>("dX"));
  theNegEndcapLayerShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer7").getParameter<double>("dX"));
  theNegEndcapLayerShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer8").getParameter<double>("dX"));
  theNegEndcapLayerShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer9").getParameter<double>("dX"));

  // get the applied shifts in y
  theNegEndcapLayerShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer1").getParameter<double>("dY"));
  theNegEndcapLayerShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer2").getParameter<double>("dY"));
  theNegEndcapLayerShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer3").getParameter<double>("dY"));
  theNegEndcapLayerShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer4").getParameter<double>("dY"));
  theNegEndcapLayerShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer5").getParameter<double>("dY"));
  theNegEndcapLayerShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer6").getParameter<double>("dY"));
  theNegEndcapLayerShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer7").getParameter<double>("dY"));
  theNegEndcapLayerShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer8").getParameter<double>("dY"));
  theNegEndcapLayerShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer9").getParameter<double>("dY"));

  // get the applied rotations around the z-axis
  theNegEndcapLayerRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer1").getParameter<double>("phiZ"));
  theNegEndcapLayerRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer2").getParameter<double>("phiZ"));
  theNegEndcapLayerRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer3").getParameter<double>("phiZ"));
  theNegEndcapLayerRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer4").getParameter<double>("phiZ"));
  theNegEndcapLayerRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer5").getParameter<double>("phiZ"));
  theNegEndcapLayerRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer6").getParameter<double>("phiZ"));
  theNegEndcapLayerRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer7").getParameter<double>("phiZ"));
  theNegEndcapLayerRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer8").getParameter<double>("phiZ"));
  theNegEndcapLayerRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer9").getParameter<double>("phiZ"));

  // for TEC2TEC
  // get the applied misalignments to calculate the expected corrections and compare them to the corrections given by the alignment algorithm
  // get the applied shifts in x 
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer5").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer4").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer3").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer2").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer1").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TOB1").getParameter<edm::ParameterSet>("BarrelLayer1").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TIB1").getParameter<edm::ParameterSet>("BarrelLayer4").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TOB1").getParameter<edm::ParameterSet>("BarrelLayer1").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TIB1").getParameter<edm::ParameterSet>("BarrelLayer4").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TOB1").getParameter<edm::ParameterSet>("BarrelLayer1").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TIB1").getParameter<edm::ParameterSet>("BarrelLayer4").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TIB2").getParameter<edm::ParameterSet>("BarrelLayer4").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TOB2").getParameter<edm::ParameterSet>("BarrelLayer1").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TIB2").getParameter<edm::ParameterSet>("BarrelLayer4").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TOB2").getParameter<edm::ParameterSet>("BarrelLayer1").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TIB2").getParameter<edm::ParameterSet>("BarrelLayer4").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TOB2").getParameter<edm::ParameterSet>("BarrelLayer1").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer1").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer2").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer3").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer4").getParameter<double>("dX"));
  theTEC2TECShiftsX.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer5").getParameter<double>("dX"));

  // get the applied shifts in y
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer5").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer4").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer3").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer2").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer1").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TOB1").getParameter<edm::ParameterSet>("BarrelLayer1").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TIB1").getParameter<edm::ParameterSet>("BarrelLayer4").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TOB1").getParameter<edm::ParameterSet>("BarrelLayer1").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TIB1").getParameter<edm::ParameterSet>("BarrelLayer4").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TOB1").getParameter<edm::ParameterSet>("BarrelLayer1").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TIB1").getParameter<edm::ParameterSet>("BarrelLayer4").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TIB2").getParameter<edm::ParameterSet>("BarrelLayer4").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TOB2").getParameter<edm::ParameterSet>("BarrelLayer1").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TIB2").getParameter<edm::ParameterSet>("BarrelLayer4").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TOB2").getParameter<edm::ParameterSet>("BarrelLayer1").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TIB2").getParameter<edm::ParameterSet>("BarrelLayer4").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TOB2").getParameter<edm::ParameterSet>("BarrelLayer1").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer1").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer2").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer3").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer4").getParameter<double>("dY"));
  theTEC2TECShiftsY.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer5").getParameter<double>("dY"));

  // get the applied rotations around the z-axis
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer5").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer4").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer3").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer2").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC1").getParameter<edm::ParameterSet>("EndcapLayer1").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TOB1").getParameter<edm::ParameterSet>("BarrelLayer1").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TIB1").getParameter<edm::ParameterSet>("BarrelLayer4").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TOB1").getParameter<edm::ParameterSet>("BarrelLayer1").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TIB1").getParameter<edm::ParameterSet>("BarrelLayer4").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TOB1").getParameter<edm::ParameterSet>("BarrelLayer1").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TIB1").getParameter<edm::ParameterSet>("BarrelLayer4").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TIB2").getParameter<edm::ParameterSet>("BarrelLayer4").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TOB2").getParameter<edm::ParameterSet>("BarrelLayer1").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TIB2").getParameter<edm::ParameterSet>("BarrelLayer4").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TOB2").getParameter<edm::ParameterSet>("BarrelLayer1").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TIB2").getParameter<edm::ParameterSet>("BarrelLayer4").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TOB2").getParameter<edm::ParameterSet>("BarrelLayer1").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer1").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer2").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer3").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer4").getParameter<double>("phiZ"));
  theTEC2TECRotationsZ.push_back(iConfig.getParameter<edm::ParameterSet>("TEC2").getParameter<edm::ParameterSet>("EndcapLayer5").getParameter<double>("phiZ"));
}


ExpectedAlignmentCorrectionsCalculator::~ExpectedAlignmentCorrectionsCalculator()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
ExpectedAlignmentCorrectionsCalculator::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
}


// ------------ method called once each job just before starting event loop  ------------
void 
ExpectedAlignmentCorrectionsCalculator::beginJob(const edm::EventSetup&)
{

}

// ------------ method called once each job just after ending the event loop  ------------
void 
ExpectedAlignmentCorrectionsCalculator::endJob() 
{
  // calculate the corrections and print the results
  float RRing4 = 56.4;            // radius of Ring 4
  float RRing6 = 84.0;            // radius of Ring 6
  float LaserPhi0 = 0.392699082;  // phi position of the first Laserdiode in Ring 4

  // calculate the expected correction using the applied misalignments
  for (int j = 0; j < 8; ++j)
    {
      // for TEC 1
      thePosExpectedPhi.push_back( thePosEndcapLayerRotationsZ.at(0)
				  + (sin(LaserPhi0)/RRing6) * thePosEndcapLayerShiftsX.at(0)
				  - (cos(LaserPhi0)/RRing6) * thePosEndcapLayerShiftsY.at(0)
				  - ( thePosEndcapLayerRotationsZ.at(j+1)
				     + (sin(LaserPhi0)/RRing6) * thePosEndcapLayerShiftsX.at(j+1)
				     - (cos(LaserPhi0)/RRing6) * thePosEndcapLayerShiftsY.at(j+1) ));

      // for TEC 2
      theNegExpectedPhi.push_back( theNegEndcapLayerRotationsZ.at(0)
				  + (sin(LaserPhi0)/RRing6) * theNegEndcapLayerShiftsX.at(0)
				  - (cos(LaserPhi0)/RRing6) * theNegEndcapLayerShiftsY.at(0)
				  - ( theNegEndcapLayerRotationsZ.at(j+1)
				      + (sin(LaserPhi0)/RRing6) * theNegEndcapLayerShiftsX.at(j+1)
				      - (cos(LaserPhi0)/RRing6) * theNegEndcapLayerShiftsY.at(j+1) ) );
    }

  for (int j = 0; j < 21; j++)
    {
      // for TEC2TEC
      theTEC2TECExpectedPhi.push_back( theTEC2TECRotationsZ.at(0)
				      + (sin(LaserPhi0)/RRing4) * theTEC2TECShiftsX.at(0)
				      - (cos(LaserPhi0)/RRing4) * theTEC2TECShiftsY.at(0)
				      - ( theTEC2TECRotationsZ.at(j+1)
					  + (sin(LaserPhi0)/RRing4) * theTEC2TECShiftsX.at(j+1)
					  - (cos(LaserPhi0)/RRing4) * theTEC2TECShiftsY.at(j+1) ) );

    }

  for (int j = 0; j < 9; ++j)
    {
      // for TEC 1
      thePosAbsExpectedPhi.push_back( thePosEndcapLayerRotationsZ.at(j)
				      + (sin(LaserPhi0)/RRing6) * thePosEndcapLayerShiftsX.at(j)
				      - (cos(LaserPhi0)/RRing6) * thePosEndcapLayerShiftsY.at(j));
    }

  LogDebug("ExpectedCorrectionsCalculator") << " Expected Correction for TEC+ in Phi[" << "0" << "] = " << thePosExpectedPhi.at(0) << "\n"
					    << " Expected Correction for TEC+ in Phi[" << "1" << "] = " << thePosExpectedPhi.at(1) << "\n"
					    << " Expected Correction for TEC+ in Phi[" << "2" << "] = " << thePosExpectedPhi.at(2) << "\n"
					    << " Expected Correction for TEC+ in Phi[" << "3" << "] = " << thePosExpectedPhi.at(3) << "\n"
					    << " Expected Correction for TEC+ in Phi[" << "4" << "] = " << thePosExpectedPhi.at(4) << "\n"
					    << " Expected Correction for TEC+ in Phi[" << "5" << "] = " << thePosExpectedPhi.at(5) << "\n"
					    << " Expected Correction for TEC+ in Phi[" << "6" << "] = " << thePosExpectedPhi.at(6) << "\n"
					    << " Expected Correction for TEC+ in Phi[" << "7" << "] = " << thePosExpectedPhi.at(7) << "\n"
					    << "-------------------------------------------------------------------------------\n" 
					    << " Abs Expected Correction for TEC+ in Phi[" << "0" << "] = " << thePosAbsExpectedPhi.at(0) << "\n"
					    << " Abs Expected Correction for TEC+ in Phi[" << "1" << "] = " << thePosAbsExpectedPhi.at(1) << "\n"
					    << " Abs Expected Correction for TEC+ in Phi[" << "2" << "] = " << thePosAbsExpectedPhi.at(2) << "\n"
					    << " Abs Expected Correction for TEC+ in Phi[" << "3" << "] = " << thePosAbsExpectedPhi.at(3) << "\n"
					    << " Abs Expected Correction for TEC+ in Phi[" << "4" << "] = " << thePosAbsExpectedPhi.at(4) << "\n"
					    << " Abs Expected Correction for TEC+ in Phi[" << "5" << "] = " << thePosAbsExpectedPhi.at(5) << "\n"
					    << " Abs Expected Correction for TEC+ in Phi[" << "6" << "] = " << thePosAbsExpectedPhi.at(6) << "\n"
					    << " Abs Expected Correction for TEC+ in Phi[" << "7" << "] = " << thePosAbsExpectedPhi.at(7) << "\n"
					    << " Abs Expected Correction for TEC+ in Phi[" << "8" << "] = " << thePosAbsExpectedPhi.at(8) << "\n"
					    << "-------------------------------------------------------------------------------\n" 
					    << " Expected Correction for TEC- in Phi[" << "0" << "] = " << theNegExpectedPhi.at(0) << "\n"
					    << " Expected Correction for TEC- in Phi[" << "1" << "] = " << theNegExpectedPhi.at(1) << "\n"
					    << " Expected Correction for TEC- in Phi[" << "2" << "] = " << theNegExpectedPhi.at(2) << "\n"
					    << " Expected Correction for TEC- in Phi[" << "3" << "] = " << theNegExpectedPhi.at(3) << "\n"
					    << " Expected Correction for TEC- in Phi[" << "4" << "] = " << theNegExpectedPhi.at(4) << "\n"
					    << " Expected Correction for TEC- in Phi[" << "5" << "] = " << theNegExpectedPhi.at(5) << "\n"
					    << " Expected Correction for TEC- in Phi[" << "6" << "] = " << theNegExpectedPhi.at(6) << "\n"
					    << " Expected Correction for TEC- in Phi[" << "7" << "] = " << theNegExpectedPhi.at(7) << "\n"
					    << "-------------------------------------------------------------------------------\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "0" << "] = " << theTEC2TECExpectedPhi.at(0) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "1" << "] = " << theTEC2TECExpectedPhi.at(1) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "2" << "] = " << theTEC2TECExpectedPhi.at(2) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "3" << "] = " << theTEC2TECExpectedPhi.at(3) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "4" << "] = " << theTEC2TECExpectedPhi.at(4) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "5" << "] = " << theTEC2TECExpectedPhi.at(5) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "6" << "] = " << theTEC2TECExpectedPhi.at(6) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "7" << "] = " << theTEC2TECExpectedPhi.at(7) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "8" << "] = " << theTEC2TECExpectedPhi.at(8) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "9" << "] = " << theTEC2TECExpectedPhi.at(9) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "10" << "] = " << theTEC2TECExpectedPhi.at(10) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "11" << "] = " << theTEC2TECExpectedPhi.at(11) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "12" << "] = " << theTEC2TECExpectedPhi.at(12) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "13" << "] = " << theTEC2TECExpectedPhi.at(13) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "14" << "] = " << theTEC2TECExpectedPhi.at(14) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "15" << "] = " << theTEC2TECExpectedPhi.at(15) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "16" << "] = " << theTEC2TECExpectedPhi.at(16) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "17" << "] = " << theTEC2TECExpectedPhi.at(17) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "18" << "] = " << theTEC2TECExpectedPhi.at(18) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "19" << "] = " << theTEC2TECExpectedPhi.at(19) << "\n"
					    << " Expected Correction for TEC2TEC in Phi[" << "20" << "] = " << theTEC2TECExpectedPhi.at(20) << "\n";

}

