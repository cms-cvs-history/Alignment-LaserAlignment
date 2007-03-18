/** \file RecoAnalyzerClusters.cc
 *  some plots for SiStripClusters
 *
 *  $Date: Sun Mar 18 19:55:09 CET 2007 $
 *  $Revision: 1.1 $
 *  \author Maarten Thomas
 */

#include "Alignment/LaserAlignment/test/RecoAnalyzer.h"

void RecoAnalyzer::trackerClusters(edm::Event const& theEvent, edm::EventSetup const& theSetup)
{
  // get the SiStripClusters from the event
  edm::Handle<edm::DetSetVector<SiStripCluster> > theClusters;
  theEvent.getByLabel(theClusterProducer, theClusters);

  const edm::DetSetVector<SiStripCluster>& input = *theClusters;

  // loop over clusters
  for (edm::DetSetVector<SiStripCluster>::const_iterator DSViter = input.begin(); DSViter != input.end(); DSViter++)
    {
      for (edm::DetSet<SiStripCluster>::const_iterator iCluster = (*DSViter).data.begin(); iCluster != (*DSViter).data.end(); iCluster++)
			{
				theClusterPositions->Fill(iCluster->barycenter());
			}
    }
}
