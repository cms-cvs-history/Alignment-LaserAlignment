/*
 * Calculate the expected alignment
 * corrections from the applied misalignments
 */

#ifndef LaserAlignment_ExpectedAlignmentcorrectionsCalculator_H
#define LaserAlignment_ExpectedAlignmentCorrectionsCalculator_H

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

class ExpectedAlignmentCorrectionsCalculator : public edm::EDAnalyzer 
{
 public:
  explicit ExpectedAlignmentCorrectionsCalculator(const edm::ParameterSet&);
  ~ExpectedAlignmentCorrectionsCalculator();


 private:
  virtual void beginJob(const edm::EventSetup&) ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  // ----------member data ---------------------------

  // vectors to store the applied distortions and the expected corrections
  std::vector<double> thePosEndcapLayerShiftsX;
  std::vector<double> thePosEndcapLayerShiftsY;
  std::vector<double> thePosEndcapLayerRotationsZ;
  std::vector<double> thePosExpectedPhi;
  std::vector<double> thePosAbsExpectedPhi;

  std::vector<double> theNegEndcapLayerShiftsX;
  std::vector<double> theNegEndcapLayerShiftsY;
  std::vector<double> theNegEndcapLayerRotationsZ;
  std::vector<double> theNegExpectedPhi;

  std::vector<double> theTEC2TECShiftsX;
  std::vector<double> theTEC2TECShiftsY;
  std::vector<double> theTEC2TECRotationsZ;
  std::vector<double> theTEC2TECExpectedPhi;
};
#endif
