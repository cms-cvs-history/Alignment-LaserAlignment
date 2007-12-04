#ifndef LaserAlignment_ExpectedAlignmentcorrectionsCalculator_H
#define LaserAlignment_ExpectedAlignmentCorrectionsCalculator_H

/** \class ExpectedAlignmentCorrectionsCalculator
 *  Calculate the expected alignment corrections from the applied misalignments
 *
 *  $Date: 2007/03/18 19:00:21 $
 *  $Revision: 1.2 $
 *  \author Maarten Thomas
 */

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"


#include "FWCore/ParameterSet/interface/ParameterSet.h"

class ExpectedAlignmentCorrectionsCalculator : public edm::EDAnalyzer 
{
 public:
	/// constructor
  explicit ExpectedAlignmentCorrectionsCalculator(const edm::ParameterSet&);
	/// destructor
  ~ExpectedAlignmentCorrectionsCalculator();


 private:
	/// begin job
  virtual void beginJob(const edm::EventSetup&) ;
	/// analyze the event (nothing done here)
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
	/// end job
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
