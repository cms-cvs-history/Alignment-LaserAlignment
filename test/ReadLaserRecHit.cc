/** \file ReadLaserRecHit.cc
 *  small test program to read the RecHits from the laser beams
 *
 *  $Date: 2007/03/18 19:00:21 $
 *  $Revision: 1.2 $
 *  \author Maarten Thomas
 */

#include "Alignment/LaserAlignment/test/ReadLaserRecHit.h"
#include "DataFormats/Common/interface/Handle.h" 
#include "FWCore/Framework/interface/Event.h" 
#include "DataFormats/TrackerRecHit2D/interface/SiStripRecHit2DCollection.h" 
#include "DataFormats/TrackerRecHit2D/interface/SiStripMatchedRecHit2DCollection.h" 

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
