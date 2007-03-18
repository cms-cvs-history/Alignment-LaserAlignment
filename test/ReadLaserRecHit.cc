/** \file ReadLaserRecHit.cc
 *  small test program to read the RecHits from the laser beams
 *
 *  $Date: Sun Mar 18 19:50:12 CET 2007 $
 *  $Revision: 1.1 $
 *  \author Maarten Thomas
 */

#include "Alignment/LaserAlignment/test/ReadLaserRecHit.h"

ReadLaserRecHit::ReadLaserRecHit(edm::ParameterSet const& conf) : 
  readRecHitAlgorithm_(conf) ,
  conf_(conf)
{}

// Virtual destructor needed.
ReadLaserRecHit::~ReadLaserRecHit() { }  

// Functions that gets called by framework every event
void ReadLaserRecHit::analyze(const edm::Event& e, const edm::EventSetup& es)
{
  std::string rechitProducer = conf_.getParameter<std::string>("RecHitProducer");
  
  // Step A: Get Inputs 
  edm::Handle<SiStripMatchedRecHit2DCollection> rechitsmatched;
  edm::Handle<SiStripRecHit2DCollection> rechitsrphi;
  edm::Handle<SiStripRecHit2DCollection> rechitsstereo;
  e.getByLabel(rechitProducer,"matchedRecHit", rechitsmatched);
  e.getByLabel(rechitProducer,"rphiRecHit", rechitsrphi);
  e.getByLabel(rechitProducer,"stereoRecHit", rechitsstereo);
  
  std::cout<<"Matched hits:"<<std::endl;
  readRecHitAlgorithm_.run(rechitsmatched.product(), es);
  std::cout<<"Rphi hits:"<<std::endl;
  readRecHitAlgorithm_.run(rechitsrphi.product(), es);
  std::cout<<"Stereo hits:"<<std::endl;
  readRecHitAlgorithm_.run(rechitsstereo.product(), es);
}
