/** \file RecoAnalyzerInitHistograms.cc
 *  Init histograms for the RecoAnalyzer
 *
 *  $Date: Sun Mar 18 19:55:23 CET 2007 $
 *  $Revision: 1.1 $
 *  \author Maarten Thomas
 */

#include "Alignment/LaserAlignment/test/RecoAnalyzer.h"

void RecoAnalyzer::initHistograms()
{
  // --- LaserBeams ---
  TDirectory * BeamDir = theFile->mkdir("LaserBeams");

  TDirectory * TECPosDir = BeamDir->mkdir("TEC+");
  TDirectory * TECNegDir = BeamDir->mkdir("TEC-");
  TDirectory * TOBDir = BeamDir->mkdir("TOB");
  TDirectory * TIBDir = BeamDir->mkdir("TIB");

  TDirectory * Ring4PosDir = TECPosDir->mkdir("Ring 4");
  TDirectory * Ring6PosDir = TECPosDir->mkdir("Ring 6");

  TDirectory * Ring4NegDir = TECNegDir->mkdir("Ring 4");
  TDirectory * Ring6NegDir = TECNegDir->mkdir("Ring 6");

  TDirectory * Ring4Beam0PosDir = Ring4PosDir->mkdir("Beam 0");
  TDirectory * Ring4Beam1PosDir = Ring4PosDir->mkdir("Beam 1");
  TDirectory * Ring4Beam2PosDir = Ring4PosDir->mkdir("Beam 2");
  TDirectory * Ring4Beam3PosDir = Ring4PosDir->mkdir("Beam 3");
  TDirectory * Ring4Beam4PosDir = Ring4PosDir->mkdir("Beam 4");
  TDirectory * Ring4Beam5PosDir = Ring4PosDir->mkdir("Beam 5");
  TDirectory * Ring4Beam6PosDir = Ring4PosDir->mkdir("Beam 6");
  TDirectory * Ring4Beam7PosDir = Ring4PosDir->mkdir("Beam 7");
  TDirectory * Ring6Beam0PosDir = Ring6PosDir->mkdir("Beam 0");
  TDirectory * Ring6Beam1PosDir = Ring6PosDir->mkdir("Beam 1");
  TDirectory * Ring6Beam2PosDir = Ring6PosDir->mkdir("Beam 2");
  TDirectory * Ring6Beam3PosDir = Ring6PosDir->mkdir("Beam 3");
  TDirectory * Ring6Beam4PosDir = Ring6PosDir->mkdir("Beam 4");
  TDirectory * Ring6Beam5PosDir = Ring6PosDir->mkdir("Beam 5");
  TDirectory * Ring6Beam6PosDir = Ring6PosDir->mkdir("Beam 6");
  TDirectory * Ring6Beam7PosDir = Ring6PosDir->mkdir("Beam 7");

  TDirectory * Ring4Beam0NegDir = Ring4NegDir->mkdir("Beam 0");
  TDirectory * Ring4Beam1NegDir = Ring4NegDir->mkdir("Beam 1");
  TDirectory * Ring4Beam2NegDir = Ring4NegDir->mkdir("Beam 2");
  TDirectory * Ring4Beam3NegDir = Ring4NegDir->mkdir("Beam 3");
  TDirectory * Ring4Beam4NegDir = Ring4NegDir->mkdir("Beam 4");
  TDirectory * Ring4Beam5NegDir = Ring4NegDir->mkdir("Beam 5");
  TDirectory * Ring4Beam6NegDir = Ring4NegDir->mkdir("Beam 6");
  TDirectory * Ring4Beam7NegDir = Ring4NegDir->mkdir("Beam 7");
  TDirectory * Ring6Beam0NegDir = Ring6NegDir->mkdir("Beam 0");
  TDirectory * Ring6Beam1NegDir = Ring6NegDir->mkdir("Beam 1");
  TDirectory * Ring6Beam2NegDir = Ring6NegDir->mkdir("Beam 2");
  TDirectory * Ring6Beam3NegDir = Ring6NegDir->mkdir("Beam 3");
  TDirectory * Ring6Beam4NegDir = Ring6NegDir->mkdir("Beam 4");
  TDirectory * Ring6Beam5NegDir = Ring6NegDir->mkdir("Beam 5");
  TDirectory * Ring6Beam6NegDir = Ring6NegDir->mkdir("Beam 6");
  TDirectory * Ring6Beam7NegDir = Ring6NegDir->mkdir("Beam 7");

  TDirectory * Beam0TOBDir = TOBDir->mkdir("Beam 0");
  TDirectory * Beam1TOBDir = TOBDir->mkdir("Beam 1");
  TDirectory * Beam2TOBDir = TOBDir->mkdir("Beam 2");
  TDirectory * Beam3TOBDir = TOBDir->mkdir("Beam 3");
  TDirectory * Beam4TOBDir = TOBDir->mkdir("Beam 4");
  TDirectory * Beam5TOBDir = TOBDir->mkdir("Beam 5");
  TDirectory * Beam6TOBDir = TOBDir->mkdir("Beam 6");
  TDirectory * Beam7TOBDir = TOBDir->mkdir("Beam 7");

  TDirectory * Beam0TIBDir = TIBDir->mkdir("Beam 0");
  TDirectory * Beam1TIBDir = TIBDir->mkdir("Beam 1");
  TDirectory * Beam2TIBDir = TIBDir->mkdir("Beam 2");
  TDirectory * Beam3TIBDir = TIBDir->mkdir("Beam 3");
  TDirectory * Beam4TIBDir = TIBDir->mkdir("Beam 4");
  TDirectory * Beam5TIBDir = TIBDir->mkdir("Beam 5");
  TDirectory * Beam6TIBDir = TIBDir->mkdir("Beam 6");
  TDirectory * Beam7TIBDir = TIBDir->mkdir("Beam 7"); 

  // --- Clusters ---
  TDirectory * ClusterDir = theFile->mkdir("Clusters");

  // --- RecHits ---
  TDirectory * RecHitDir = theFile->mkdir("RecHits");

  /* LaserBeams in the TEC+ */
  // {{{ ----- Adc counts for Beam 0 in Ring 4
  theBeam0Ring4Disc1PosAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 0 in Ring 4", 512, 0, 511);
  theBeam0Ring4Disc1PosAdcCounts->SetDirectory(Ring4Beam0PosDir);
  theBeam0Ring4Disc2PosAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 0 in Ring 4", 512, 0, 511);
  theBeam0Ring4Disc2PosAdcCounts->SetDirectory(Ring4Beam0PosDir);
  theBeam0Ring4Disc3PosAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 0 in Ring 4", 512, 0, 511);
  theBeam0Ring4Disc3PosAdcCounts->SetDirectory(Ring4Beam0PosDir);
  theBeam0Ring4Disc4PosAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 0 in Ring 4", 512, 0, 511);
  theBeam0Ring4Disc4PosAdcCounts->SetDirectory(Ring4Beam0PosDir);
  theBeam0Ring4Disc5PosAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 0 in Ring 4", 512, 0, 511);
  theBeam0Ring4Disc5PosAdcCounts->SetDirectory(Ring4Beam0PosDir);
  theBeam0Ring4Disc6PosAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 0 in Ring 4", 512, 0, 511);
  theBeam0Ring4Disc6PosAdcCounts->SetDirectory(Ring4Beam0PosDir);
  theBeam0Ring4Disc7PosAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 0 in Ring 4", 512, 0, 511);
  theBeam0Ring4Disc7PosAdcCounts->SetDirectory(Ring4Beam0PosDir);
  theBeam0Ring4Disc8PosAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 0 in Ring 4", 512, 0, 511);
  theBeam0Ring4Disc8PosAdcCounts->SetDirectory(Ring4Beam0PosDir);
  theBeam0Ring4Disc9PosAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 0 in Ring 4", 512, 0, 511);
  theBeam0Ring4Disc9PosAdcCounts->SetDirectory(Ring4Beam0PosDir);
  // }}}

  // {{{ ----- Adc counts for Beam 1 in Ring 4
  theBeam1Ring4Disc1PosAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc1PosAdcCounts->SetDirectory(Ring4Beam1PosDir);
  theBeam1Ring4Disc2PosAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc2PosAdcCounts->SetDirectory(Ring4Beam1PosDir);
  theBeam1Ring4Disc3PosAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc3PosAdcCounts->SetDirectory(Ring4Beam1PosDir);
  theBeam1Ring4Disc4PosAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc4PosAdcCounts->SetDirectory(Ring4Beam1PosDir);
  theBeam1Ring4Disc5PosAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc5PosAdcCounts->SetDirectory(Ring4Beam1PosDir);
  theBeam1Ring4Disc6PosAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc6PosAdcCounts->SetDirectory(Ring4Beam1PosDir);
  theBeam1Ring4Disc7PosAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc7PosAdcCounts->SetDirectory(Ring4Beam1PosDir);
  theBeam1Ring4Disc8PosAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc8PosAdcCounts->SetDirectory(Ring4Beam1PosDir);
  theBeam1Ring4Disc9PosAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc9PosAdcCounts->SetDirectory(Ring4Beam1PosDir);
  // }}}

  // plots for TEC2TEC beam 1
  theBeam1Ring4Disc1PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc1TEC2TEC","Adc counts on Disc 1 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc1PosTEC2TECAdcCounts->SetDirectory(Ring4Beam1PosDir);
  theBeam1Ring4Disc2PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc2TEC2TEC","Adc counts on Disc 2 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc2PosTEC2TECAdcCounts->SetDirectory(Ring4Beam1PosDir);
  theBeam1Ring4Disc3PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc3TEC2TEC","Adc counts on Disc 3 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc3PosTEC2TECAdcCounts->SetDirectory(Ring4Beam1PosDir);
  theBeam1Ring4Disc4PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc4TEC2TEC","Adc counts on Disc 4 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc4PosTEC2TECAdcCounts->SetDirectory(Ring4Beam1PosDir);
  theBeam1Ring4Disc5PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc5TEC2TEC","Adc counts on Disc 5 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc5PosTEC2TECAdcCounts->SetDirectory(Ring4Beam1PosDir);
  // }}}

  // {{{ ----- Adc counts for Beam 2 in Ring 4
  theBeam2Ring4Disc1PosAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc1PosAdcCounts->SetDirectory(Ring4Beam2PosDir);
  theBeam2Ring4Disc2PosAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc2PosAdcCounts->SetDirectory(Ring4Beam2PosDir);
  theBeam2Ring4Disc3PosAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc3PosAdcCounts->SetDirectory(Ring4Beam2PosDir);
  theBeam2Ring4Disc4PosAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc4PosAdcCounts->SetDirectory(Ring4Beam2PosDir);
  theBeam2Ring4Disc5PosAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc5PosAdcCounts->SetDirectory(Ring4Beam2PosDir);
  theBeam2Ring4Disc6PosAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc6PosAdcCounts->SetDirectory(Ring4Beam2PosDir);
  theBeam2Ring4Disc7PosAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc7PosAdcCounts->SetDirectory(Ring4Beam2PosDir);
  theBeam2Ring4Disc8PosAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc8PosAdcCounts->SetDirectory(Ring4Beam2PosDir);
  theBeam2Ring4Disc9PosAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc9PosAdcCounts->SetDirectory(Ring4Beam2PosDir);
  // }}}

  // plots for TEC2TEC beam 2
  theBeam2Ring4Disc1PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc1TEC2TEC","Adc counts on Disc 1 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc1PosTEC2TECAdcCounts->SetDirectory(Ring4Beam2PosDir);
  theBeam2Ring4Disc2PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc2TEC2TEC","Adc counts on Disc 2 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc2PosTEC2TECAdcCounts->SetDirectory(Ring4Beam2PosDir);
  theBeam2Ring4Disc3PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc3TEC2TEC","Adc counts on Disc 3 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc3PosTEC2TECAdcCounts->SetDirectory(Ring4Beam2PosDir);
  theBeam2Ring4Disc4PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc4TEC2TEC","Adc counts on Disc 4 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc4PosTEC2TECAdcCounts->SetDirectory(Ring4Beam2PosDir);
  theBeam2Ring4Disc5PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc5TEC2TEC","Adc counts on Disc 5 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc5PosTEC2TECAdcCounts->SetDirectory(Ring4Beam2PosDir);
  // }}}

  // {{{ ----- Adc counts for Beam 3 in Ring 4
  theBeam3Ring4Disc1PosAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 3 in Ring 4", 512, 0, 511);
  theBeam3Ring4Disc1PosAdcCounts->SetDirectory(Ring4Beam3PosDir);
  theBeam3Ring4Disc2PosAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 3 in Ring 4", 512, 0, 511);
  theBeam3Ring4Disc2PosAdcCounts->SetDirectory(Ring4Beam3PosDir);
  theBeam3Ring4Disc3PosAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 3 in Ring 4", 512, 0, 511);
  theBeam3Ring4Disc3PosAdcCounts->SetDirectory(Ring4Beam3PosDir);
  theBeam3Ring4Disc4PosAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 3 in Ring 4", 512, 0, 511);
  theBeam3Ring4Disc4PosAdcCounts->SetDirectory(Ring4Beam3PosDir);
  theBeam3Ring4Disc5PosAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 3 in Ring 4", 512, 0, 511);
  theBeam3Ring4Disc5PosAdcCounts->SetDirectory(Ring4Beam3PosDir);
  theBeam3Ring4Disc6PosAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 3 in Ring 4", 512, 0, 511);
  theBeam3Ring4Disc6PosAdcCounts->SetDirectory(Ring4Beam3PosDir);
  theBeam3Ring4Disc7PosAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 3 in Ring 4", 512, 0, 511);
  theBeam3Ring4Disc7PosAdcCounts->SetDirectory(Ring4Beam3PosDir);
  theBeam3Ring4Disc8PosAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 3 in Ring 4", 512, 0, 511);
  theBeam3Ring4Disc8PosAdcCounts->SetDirectory(Ring4Beam3PosDir);
  theBeam3Ring4Disc9PosAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 3 in Ring 4", 512, 0, 511);
  theBeam3Ring4Disc9PosAdcCounts->SetDirectory(Ring4Beam3PosDir);
  // }}}

  // {{{ ----- Adc counts for Beam 4 in Ring 4
  theBeam4Ring4Disc1PosAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc1PosAdcCounts->SetDirectory(Ring4Beam4PosDir);
  theBeam4Ring4Disc2PosAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc2PosAdcCounts->SetDirectory(Ring4Beam4PosDir);
  theBeam4Ring4Disc3PosAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc3PosAdcCounts->SetDirectory(Ring4Beam4PosDir);
  theBeam4Ring4Disc4PosAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc4PosAdcCounts->SetDirectory(Ring4Beam4PosDir);
  theBeam4Ring4Disc5PosAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc5PosAdcCounts->SetDirectory(Ring4Beam4PosDir);
  theBeam4Ring4Disc6PosAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc6PosAdcCounts->SetDirectory(Ring4Beam4PosDir);
  theBeam4Ring4Disc7PosAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc7PosAdcCounts->SetDirectory(Ring4Beam4PosDir);
  theBeam4Ring4Disc8PosAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc8PosAdcCounts->SetDirectory(Ring4Beam4PosDir);
  theBeam4Ring4Disc9PosAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc9PosAdcCounts->SetDirectory(Ring4Beam4PosDir);
  // }}}

  // plots for TEC2TEC beam 4
  theBeam4Ring4Disc1PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc1TEC2TEC","Adc counts on Disc 1 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc1PosTEC2TECAdcCounts->SetDirectory(Ring4Beam4PosDir);
  theBeam4Ring4Disc2PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc2TEC2TEC","Adc counts on Disc 2 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc2PosTEC2TECAdcCounts->SetDirectory(Ring4Beam4PosDir);
  theBeam4Ring4Disc3PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc3TEC2TEC","Adc counts on Disc 3 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc3PosTEC2TECAdcCounts->SetDirectory(Ring4Beam4PosDir);
  theBeam4Ring4Disc4PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc4TEC2TEC","Adc counts on Disc 4 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc4PosTEC2TECAdcCounts->SetDirectory(Ring4Beam4PosDir);
  theBeam4Ring4Disc5PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc5TEC2TEC","Adc counts on Disc 5 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc5PosTEC2TECAdcCounts->SetDirectory(Ring4Beam4PosDir);
  // }}}

  // {{{ ----- Adc counts for Beam 5 in Ring 4
  theBeam5Ring4Disc1PosAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 5 in Ring 4", 512, 0, 511);
  theBeam5Ring4Disc1PosAdcCounts->SetDirectory(Ring4Beam5PosDir);
  theBeam5Ring4Disc2PosAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 5 in Ring 4", 512, 0, 511);
  theBeam5Ring4Disc2PosAdcCounts->SetDirectory(Ring4Beam5PosDir);
  theBeam5Ring4Disc3PosAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 5 in Ring 4", 512, 0, 511);
  theBeam5Ring4Disc3PosAdcCounts->SetDirectory(Ring4Beam5PosDir);
  theBeam5Ring4Disc4PosAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 5 in Ring 4", 512, 0, 511);
  theBeam5Ring4Disc4PosAdcCounts->SetDirectory(Ring4Beam5PosDir);
  theBeam5Ring4Disc5PosAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 5 in Ring 4", 512, 0, 511);
  theBeam5Ring4Disc5PosAdcCounts->SetDirectory(Ring4Beam5PosDir);
  theBeam5Ring4Disc6PosAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 5 in Ring 4", 512, 0, 511);
  theBeam5Ring4Disc6PosAdcCounts->SetDirectory(Ring4Beam5PosDir);
  theBeam5Ring4Disc7PosAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 5 in Ring 4", 512, 0, 511);
  theBeam5Ring4Disc7PosAdcCounts->SetDirectory(Ring4Beam5PosDir);
  theBeam5Ring4Disc8PosAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 5 in Ring 4", 512, 0, 511);
  theBeam5Ring4Disc8PosAdcCounts->SetDirectory(Ring4Beam5PosDir);
  theBeam5Ring4Disc9PosAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 5 in Ring 4", 512, 0, 511);
  theBeam5Ring4Disc9PosAdcCounts->SetDirectory(Ring4Beam5PosDir);
  // }}}

  // {{{ ----- Adc counts for Beam 6 in Ring 4
  theBeam6Ring4Disc1PosAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc1PosAdcCounts->SetDirectory(Ring4Beam6PosDir);
  theBeam6Ring4Disc2PosAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc2PosAdcCounts->SetDirectory(Ring4Beam6PosDir);
  theBeam6Ring4Disc3PosAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc3PosAdcCounts->SetDirectory(Ring4Beam6PosDir);
  theBeam6Ring4Disc4PosAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc4PosAdcCounts->SetDirectory(Ring4Beam6PosDir);
  theBeam6Ring4Disc5PosAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc5PosAdcCounts->SetDirectory(Ring4Beam6PosDir);
  theBeam6Ring4Disc6PosAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc6PosAdcCounts->SetDirectory(Ring4Beam6PosDir);
  theBeam6Ring4Disc7PosAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc7PosAdcCounts->SetDirectory(Ring4Beam6PosDir);
  theBeam6Ring4Disc8PosAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc8PosAdcCounts->SetDirectory(Ring4Beam6PosDir);
  theBeam6Ring4Disc9PosAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc9PosAdcCounts->SetDirectory(Ring4Beam6PosDir);
  // }}}

  // plots for TEC2TEC beam 6
  theBeam6Ring4Disc1PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc1TEC2TEC","Adc counts on Disc 1 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc1PosTEC2TECAdcCounts->SetDirectory(Ring4Beam6PosDir);
  theBeam6Ring4Disc2PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc2TEC2TEC","Adc counts on Disc 2 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc2PosTEC2TECAdcCounts->SetDirectory(Ring4Beam6PosDir);
  theBeam6Ring4Disc3PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc3TEC2TEC","Adc counts on Disc 3 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc3PosTEC2TECAdcCounts->SetDirectory(Ring4Beam6PosDir);
  theBeam6Ring4Disc4PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc4TEC2TEC","Adc counts on Disc 4 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc4PosTEC2TECAdcCounts->SetDirectory(Ring4Beam6PosDir);
  theBeam6Ring4Disc5PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc5TEC2TEC","Adc counts on Disc 5 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc5PosTEC2TECAdcCounts->SetDirectory(Ring4Beam6PosDir);
  // }}}

  // {{{ ----- Adc counts for Beam 7 in Ring 4
  theBeam7Ring4Disc1PosAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc1PosAdcCounts->SetDirectory(Ring4Beam7PosDir);
  theBeam7Ring4Disc2PosAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc2PosAdcCounts->SetDirectory(Ring4Beam7PosDir);
  theBeam7Ring4Disc3PosAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc3PosAdcCounts->SetDirectory(Ring4Beam7PosDir);
  theBeam7Ring4Disc4PosAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc4PosAdcCounts->SetDirectory(Ring4Beam7PosDir);
  theBeam7Ring4Disc5PosAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc5PosAdcCounts->SetDirectory(Ring4Beam7PosDir);
  theBeam7Ring4Disc6PosAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc6PosAdcCounts->SetDirectory(Ring4Beam7PosDir);
  theBeam7Ring4Disc7PosAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc7PosAdcCounts->SetDirectory(Ring4Beam7PosDir);
  theBeam7Ring4Disc8PosAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc8PosAdcCounts->SetDirectory(Ring4Beam7PosDir);
  theBeam7Ring4Disc9PosAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc9PosAdcCounts->SetDirectory(Ring4Beam7PosDir);
  // }}}

  // plots for TEC2TEC beam 7
  theBeam7Ring4Disc1PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc1TEC2TEC","Adc counts on Disc 1 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc1PosTEC2TECAdcCounts->SetDirectory(Ring4Beam7PosDir);
  theBeam7Ring4Disc2PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc2TEC2TEC","Adc counts on Disc 2 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc2PosTEC2TECAdcCounts->SetDirectory(Ring4Beam7PosDir);
  theBeam7Ring4Disc3PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc3TEC2TEC","Adc counts on Disc 3 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc3PosTEC2TECAdcCounts->SetDirectory(Ring4Beam7PosDir);
  theBeam7Ring4Disc4PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc4TEC2TEC","Adc counts on Disc 4 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc4PosTEC2TECAdcCounts->SetDirectory(Ring4Beam7PosDir);
  theBeam7Ring4Disc5PosTEC2TECAdcCounts = new TH1D("AdcCountsDisc5TEC2TEC","Adc counts on Disc 5 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc5PosTEC2TECAdcCounts->SetDirectory(Ring4Beam7PosDir);
  // }}}

  // {{{ ----- Adc counts for Beam 0 in Ring 6
  theBeam0Ring6Disc1PosAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 0 in Ring 6", 512, 0, 511);
  theBeam0Ring6Disc1PosAdcCounts->SetDirectory(Ring6Beam0PosDir);
  theBeam0Ring6Disc2PosAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 0 in Ring 6", 512, 0, 511);
  theBeam0Ring6Disc2PosAdcCounts->SetDirectory(Ring6Beam0PosDir);
  theBeam0Ring6Disc3PosAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 0 in Ring 6", 512, 0, 511);
  theBeam0Ring6Disc3PosAdcCounts->SetDirectory(Ring6Beam0PosDir);
  theBeam0Ring6Disc4PosAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 0 in Ring 6", 512, 0, 511);
  theBeam0Ring6Disc4PosAdcCounts->SetDirectory(Ring6Beam0PosDir);
  theBeam0Ring6Disc5PosAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 0 in Ring 6", 512, 0, 511);
  theBeam0Ring6Disc5PosAdcCounts->SetDirectory(Ring6Beam0PosDir);
  theBeam0Ring6Disc6PosAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 0 in Ring 6", 512, 0, 511);
  theBeam0Ring6Disc6PosAdcCounts->SetDirectory(Ring6Beam0PosDir);
  theBeam0Ring6Disc7PosAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 0 in Ring 6", 512, 0, 511);
  theBeam0Ring6Disc7PosAdcCounts->SetDirectory(Ring6Beam0PosDir);
  theBeam0Ring6Disc8PosAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 0 in Ring 6", 512, 0, 511);
  theBeam0Ring6Disc8PosAdcCounts->SetDirectory(Ring6Beam0PosDir);
  theBeam0Ring6Disc9PosAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 0 in Ring 6", 512, 0, 511);
  theBeam0Ring6Disc9PosAdcCounts->SetDirectory(Ring6Beam0PosDir);
  // }}}

  // {{{ ----- Adc counts for Beam 1 in Ring 6
  theBeam1Ring6Disc1PosAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 1 in Ring 6", 512, 0, 511);
  theBeam1Ring6Disc1PosAdcCounts->SetDirectory(Ring6Beam1PosDir);
  theBeam1Ring6Disc2PosAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 1 in Ring 6", 512, 0, 511);
  theBeam1Ring6Disc2PosAdcCounts->SetDirectory(Ring6Beam1PosDir);
  theBeam1Ring6Disc3PosAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 1 in Ring 6", 512, 0, 511);
  theBeam1Ring6Disc3PosAdcCounts->SetDirectory(Ring6Beam1PosDir);
  theBeam1Ring6Disc4PosAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 1 in Ring 6", 512, 0, 511);
  theBeam1Ring6Disc4PosAdcCounts->SetDirectory(Ring6Beam1PosDir);
  theBeam1Ring6Disc5PosAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 1 in Ring 6", 512, 0, 511);
  theBeam1Ring6Disc5PosAdcCounts->SetDirectory(Ring6Beam1PosDir);
  theBeam1Ring6Disc6PosAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 1 in Ring 6", 512, 0, 511);
  theBeam1Ring6Disc6PosAdcCounts->SetDirectory(Ring6Beam1PosDir);
  theBeam1Ring6Disc7PosAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 1 in Ring 6", 512, 0, 511);
  theBeam1Ring6Disc7PosAdcCounts->SetDirectory(Ring6Beam1PosDir);
  theBeam1Ring6Disc8PosAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 1 in Ring 6", 512, 0, 511);
  theBeam1Ring6Disc8PosAdcCounts->SetDirectory(Ring6Beam1PosDir);
  theBeam1Ring6Disc9PosAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 1 in Ring 6", 512, 0, 511);
  theBeam1Ring6Disc9PosAdcCounts->SetDirectory(Ring6Beam1PosDir);
  // }}}

  // {{{ ----- Adc counts for Beam 2 in Ring 6
  theBeam2Ring6Disc1PosAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 2 in Ring 6", 512, 0, 511);
  theBeam2Ring6Disc1PosAdcCounts->SetDirectory(Ring6Beam2PosDir);
  theBeam2Ring6Disc2PosAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 2 in Ring 6", 512, 0, 511);
  theBeam2Ring6Disc2PosAdcCounts->SetDirectory(Ring6Beam2PosDir);
  theBeam2Ring6Disc3PosAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 2 in Ring 6", 512, 0, 511);
  theBeam2Ring6Disc3PosAdcCounts->SetDirectory(Ring6Beam2PosDir);
  theBeam2Ring6Disc4PosAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 2 in Ring 6", 512, 0, 511);
  theBeam2Ring6Disc4PosAdcCounts->SetDirectory(Ring6Beam2PosDir);
  theBeam2Ring6Disc5PosAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 2 in Ring 6", 512, 0, 511);
  theBeam2Ring6Disc5PosAdcCounts->SetDirectory(Ring6Beam2PosDir);
  theBeam2Ring6Disc6PosAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 2 in Ring 6", 512, 0, 511);
  theBeam2Ring6Disc6PosAdcCounts->SetDirectory(Ring6Beam2PosDir);
  theBeam2Ring6Disc7PosAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 2 in Ring 6", 512, 0, 511);
  theBeam2Ring6Disc7PosAdcCounts->SetDirectory(Ring6Beam2PosDir);
  theBeam2Ring6Disc8PosAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 2 in Ring 6", 512, 0, 511);
  theBeam2Ring6Disc8PosAdcCounts->SetDirectory(Ring6Beam2PosDir);
  theBeam2Ring6Disc9PosAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 2 in Ring 6", 512, 0, 511);
  theBeam2Ring6Disc9PosAdcCounts->SetDirectory(Ring6Beam2PosDir);
  // }}}

  // {{{ ----- Adc counts for Beam 3 in Ring 6
  theBeam3Ring6Disc1PosAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 3 in Ring 6", 512, 0, 511);
  theBeam3Ring6Disc1PosAdcCounts->SetDirectory(Ring6Beam3PosDir);
  theBeam3Ring6Disc2PosAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 3 in Ring 6", 512, 0, 511);
  theBeam3Ring6Disc2PosAdcCounts->SetDirectory(Ring6Beam3PosDir);
  theBeam3Ring6Disc3PosAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 3 in Ring 6", 512, 0, 511);
  theBeam3Ring6Disc3PosAdcCounts->SetDirectory(Ring6Beam3PosDir);
  theBeam3Ring6Disc4PosAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 3 in Ring 6", 512, 0, 511);
  theBeam3Ring6Disc4PosAdcCounts->SetDirectory(Ring6Beam3PosDir);
  theBeam3Ring6Disc5PosAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 3 in Ring 6", 512, 0, 511);
  theBeam3Ring6Disc5PosAdcCounts->SetDirectory(Ring6Beam3PosDir);
  theBeam3Ring6Disc6PosAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 3 in Ring 6", 512, 0, 511);
  theBeam3Ring6Disc6PosAdcCounts->SetDirectory(Ring6Beam3PosDir);
  theBeam3Ring6Disc7PosAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 3 in Ring 6", 512, 0, 511);
  theBeam3Ring6Disc7PosAdcCounts->SetDirectory(Ring6Beam3PosDir);
  theBeam3Ring6Disc8PosAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 3 in Ring 6", 512, 0, 511);
  theBeam3Ring6Disc8PosAdcCounts->SetDirectory(Ring6Beam3PosDir);
  theBeam3Ring6Disc9PosAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 3 in Ring 6", 512, 0, 511);
  theBeam3Ring6Disc9PosAdcCounts->SetDirectory(Ring6Beam3PosDir);
  // }}}

  // {{{ ----- Adc counts for Beam 4 in Ring 6
  theBeam4Ring6Disc1PosAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 4 in Ring 6", 512, 0, 511);
  theBeam4Ring6Disc1PosAdcCounts->SetDirectory(Ring6Beam4PosDir);
  theBeam4Ring6Disc2PosAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 4 in Ring 6", 512, 0, 511);
  theBeam4Ring6Disc2PosAdcCounts->SetDirectory(Ring6Beam4PosDir);
  theBeam4Ring6Disc3PosAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 4 in Ring 6", 512, 0, 511);
  theBeam4Ring6Disc3PosAdcCounts->SetDirectory(Ring6Beam4PosDir);
  theBeam4Ring6Disc4PosAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 4 in Ring 6", 512, 0, 511);
  theBeam4Ring6Disc4PosAdcCounts->SetDirectory(Ring6Beam4PosDir);
  theBeam4Ring6Disc5PosAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 4 in Ring 6", 512, 0, 511);
  theBeam4Ring6Disc5PosAdcCounts->SetDirectory(Ring6Beam4PosDir);
  theBeam4Ring6Disc6PosAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 4 in Ring 6", 512, 0, 511);
  theBeam4Ring6Disc6PosAdcCounts->SetDirectory(Ring6Beam4PosDir);
  theBeam4Ring6Disc7PosAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 4 in Ring 6", 512, 0, 511);
  theBeam4Ring6Disc7PosAdcCounts->SetDirectory(Ring6Beam4PosDir);
  theBeam4Ring6Disc8PosAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 4 in Ring 6", 512, 0, 511);
  theBeam4Ring6Disc8PosAdcCounts->SetDirectory(Ring6Beam4PosDir);
  theBeam4Ring6Disc9PosAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 4 in Ring 6", 512, 0, 511);
  theBeam4Ring6Disc9PosAdcCounts->SetDirectory(Ring6Beam4PosDir);
  // }}}

  // {{{ ----- Adc counts for Beam 5 in Ring 6
  theBeam5Ring6Disc1PosAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 5 in Ring 6", 512, 0, 511);
  theBeam5Ring6Disc1PosAdcCounts->SetDirectory(Ring6Beam5PosDir);
  theBeam5Ring6Disc2PosAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 5 in Ring 6", 512, 0, 511);
  theBeam5Ring6Disc2PosAdcCounts->SetDirectory(Ring6Beam5PosDir);
  theBeam5Ring6Disc3PosAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 5 in Ring 6", 512, 0, 511);
  theBeam5Ring6Disc3PosAdcCounts->SetDirectory(Ring6Beam5PosDir);
  theBeam5Ring6Disc4PosAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 5 in Ring 6", 512, 0, 511);
  theBeam5Ring6Disc4PosAdcCounts->SetDirectory(Ring6Beam5PosDir);
  theBeam5Ring6Disc5PosAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 5 in Ring 6", 512, 0, 511);
  theBeam5Ring6Disc5PosAdcCounts->SetDirectory(Ring6Beam5PosDir);
  theBeam5Ring6Disc6PosAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 5 in Ring 6", 512, 0, 511);
  theBeam5Ring6Disc6PosAdcCounts->SetDirectory(Ring6Beam5PosDir);
  theBeam5Ring6Disc7PosAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 5 in Ring 6", 512, 0, 511);
  theBeam5Ring6Disc7PosAdcCounts->SetDirectory(Ring6Beam5PosDir);
  theBeam5Ring6Disc8PosAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 5 in Ring 6", 512, 0, 511);
  theBeam5Ring6Disc8PosAdcCounts->SetDirectory(Ring6Beam5PosDir);
  theBeam5Ring6Disc9PosAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 5 in Ring 6", 512, 0, 511);
  theBeam5Ring6Disc9PosAdcCounts->SetDirectory(Ring6Beam5PosDir);
  // }}}

  // {{{ ----- Adc counts for Beam 6 in Ring 6
  theBeam6Ring6Disc1PosAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 6 in Ring 6", 512, 0, 511);
  theBeam6Ring6Disc1PosAdcCounts->SetDirectory(Ring6Beam6PosDir);
  theBeam6Ring6Disc2PosAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 6 in Ring 6", 512, 0, 511);
  theBeam6Ring6Disc2PosAdcCounts->SetDirectory(Ring6Beam6PosDir);
  theBeam6Ring6Disc3PosAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 6 in Ring 6", 512, 0, 511);
  theBeam6Ring6Disc3PosAdcCounts->SetDirectory(Ring6Beam6PosDir);
  theBeam6Ring6Disc4PosAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 6 in Ring 6", 512, 0, 511);
  theBeam6Ring6Disc4PosAdcCounts->SetDirectory(Ring6Beam6PosDir);
  theBeam6Ring6Disc5PosAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 6 in Ring 6", 512, 0, 511);
  theBeam6Ring6Disc5PosAdcCounts->SetDirectory(Ring6Beam6PosDir);
  theBeam6Ring6Disc6PosAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 6 in Ring 6", 512, 0, 511);
  theBeam6Ring6Disc6PosAdcCounts->SetDirectory(Ring6Beam6PosDir);
  theBeam6Ring6Disc7PosAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 6 in Ring 6", 512, 0, 511);
  theBeam6Ring6Disc7PosAdcCounts->SetDirectory(Ring6Beam6PosDir);
  theBeam6Ring6Disc8PosAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 6 in Ring 6", 512, 0, 511);
  theBeam6Ring6Disc8PosAdcCounts->SetDirectory(Ring6Beam6PosDir);
  theBeam6Ring6Disc9PosAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 6 in Ring 6", 512, 0, 511);
  theBeam6Ring6Disc9PosAdcCounts->SetDirectory(Ring6Beam6PosDir);
  // }}}

  // {{{ ----- Adc counts for Beam 7 in Ring 6
  theBeam7Ring6Disc1PosAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 7 in Ring 6", 512, 0, 511);
  theBeam7Ring6Disc1PosAdcCounts->SetDirectory(Ring6Beam7PosDir);
  theBeam7Ring6Disc2PosAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 7 in Ring 6", 512, 0, 511);
  theBeam7Ring6Disc2PosAdcCounts->SetDirectory(Ring6Beam7PosDir);
  theBeam7Ring6Disc3PosAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 7 in Ring 6", 512, 0, 511);
  theBeam7Ring6Disc3PosAdcCounts->SetDirectory(Ring6Beam7PosDir);
  theBeam7Ring6Disc4PosAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 7 in Ring 6", 512, 0, 511);
  theBeam7Ring6Disc4PosAdcCounts->SetDirectory(Ring6Beam7PosDir);
  theBeam7Ring6Disc5PosAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 7 in Ring 6", 512, 0, 511);
  theBeam7Ring6Disc5PosAdcCounts->SetDirectory(Ring6Beam7PosDir);
  theBeam7Ring6Disc6PosAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 7 in Ring 6", 512, 0, 511);
  theBeam7Ring6Disc6PosAdcCounts->SetDirectory(Ring6Beam7PosDir);
  theBeam7Ring6Disc7PosAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 7 in Ring 6", 512, 0, 511);
  theBeam7Ring6Disc7PosAdcCounts->SetDirectory(Ring6Beam7PosDir);
  theBeam7Ring6Disc8PosAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 7 in Ring 6", 512, 0, 511);
  theBeam7Ring6Disc8PosAdcCounts->SetDirectory(Ring6Beam7PosDir);
  theBeam7Ring6Disc9PosAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 7 in Ring 6", 512, 0, 511);
  theBeam7Ring6Disc9PosAdcCounts->SetDirectory(Ring6Beam7PosDir);
  // }}}

  /* LaserBeams in the TEC- */
  // {{{ ----- Adc counts for Beam 0 in Ring 4
  theBeam0Ring4Disc1NegAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 0 in Ring 4", 512, 0, 511);
  theBeam0Ring4Disc1NegAdcCounts->SetDirectory(Ring4Beam0NegDir);
  theBeam0Ring4Disc2NegAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 0 in Ring 4", 512, 0, 511);
  theBeam0Ring4Disc2NegAdcCounts->SetDirectory(Ring4Beam0NegDir);
  theBeam0Ring4Disc3NegAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 0 in Ring 4", 512, 0, 511);
  theBeam0Ring4Disc3NegAdcCounts->SetDirectory(Ring4Beam0NegDir);
  theBeam0Ring4Disc4NegAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 0 in Ring 4", 512, 0, 511);
  theBeam0Ring4Disc4NegAdcCounts->SetDirectory(Ring4Beam0NegDir);
  theBeam0Ring4Disc5NegAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 0 in Ring 4", 512, 0, 511);
  theBeam0Ring4Disc5NegAdcCounts->SetDirectory(Ring4Beam0NegDir);
  theBeam0Ring4Disc6NegAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 0 in Ring 4", 512, 0, 511);
  theBeam0Ring4Disc6NegAdcCounts->SetDirectory(Ring4Beam0NegDir);
  theBeam0Ring4Disc7NegAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 0 in Ring 4", 512, 0, 511);
  theBeam0Ring4Disc7NegAdcCounts->SetDirectory(Ring4Beam0NegDir);
  theBeam0Ring4Disc8NegAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 0 in Ring 4", 512, 0, 511);
  theBeam0Ring4Disc8NegAdcCounts->SetDirectory(Ring4Beam0NegDir);
  theBeam0Ring4Disc9NegAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 0 in Ring 4", 512, 0, 511);
  theBeam0Ring4Disc9NegAdcCounts->SetDirectory(Ring4Beam0NegDir);
  // }}}

  // {{{ ----- Adc counts for Beam 1 in Ring 4
  theBeam1Ring4Disc1NegAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc1NegAdcCounts->SetDirectory(Ring4Beam1NegDir);
  theBeam1Ring4Disc2NegAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc2NegAdcCounts->SetDirectory(Ring4Beam1NegDir);
  theBeam1Ring4Disc3NegAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc3NegAdcCounts->SetDirectory(Ring4Beam1NegDir);
  theBeam1Ring4Disc4NegAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc4NegAdcCounts->SetDirectory(Ring4Beam1NegDir);
  theBeam1Ring4Disc5NegAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc5NegAdcCounts->SetDirectory(Ring4Beam1NegDir);
  theBeam1Ring4Disc6NegAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc6NegAdcCounts->SetDirectory(Ring4Beam1NegDir);
  theBeam1Ring4Disc7NegAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc7NegAdcCounts->SetDirectory(Ring4Beam1NegDir);
  theBeam1Ring4Disc8NegAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc8NegAdcCounts->SetDirectory(Ring4Beam1NegDir);
  theBeam1Ring4Disc9NegAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc9NegAdcCounts->SetDirectory(Ring4Beam1NegDir);
  // }}}

  // plots for TEC2TEC beam 1
  theBeam1Ring4Disc1NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc1TEC2TEC","Adc counts on Disc 1 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc1NegTEC2TECAdcCounts->SetDirectory(Ring4Beam1NegDir);
  theBeam1Ring4Disc2NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc2TEC2TEC","Adc counts on Disc 2 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc2NegTEC2TECAdcCounts->SetDirectory(Ring4Beam1NegDir);
  theBeam1Ring4Disc3NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc3TEC2TEC","Adc counts on Disc 3 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc3NegTEC2TECAdcCounts->SetDirectory(Ring4Beam1NegDir);
  theBeam1Ring4Disc4NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc4TEC2TEC","Adc counts on Disc 4 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc4NegTEC2TECAdcCounts->SetDirectory(Ring4Beam1NegDir);
  theBeam1Ring4Disc5NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc5TEC2TEC","Adc counts on Disc 5 for Beam 1 in Ring 4", 512, 0, 511);
  theBeam1Ring4Disc5NegTEC2TECAdcCounts->SetDirectory(Ring4Beam1NegDir);
  // }}}

  // {{{ ----- Adc counts for Beam 2 in Ring 4
  theBeam2Ring4Disc1NegAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc1NegAdcCounts->SetDirectory(Ring4Beam2NegDir);
  theBeam2Ring4Disc2NegAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc2NegAdcCounts->SetDirectory(Ring4Beam2NegDir);
  theBeam2Ring4Disc3NegAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc3NegAdcCounts->SetDirectory(Ring4Beam2NegDir);
  theBeam2Ring4Disc4NegAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc4NegAdcCounts->SetDirectory(Ring4Beam2NegDir);
  theBeam2Ring4Disc5NegAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc5NegAdcCounts->SetDirectory(Ring4Beam2NegDir);
  theBeam2Ring4Disc6NegAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc6NegAdcCounts->SetDirectory(Ring4Beam2NegDir);
  theBeam2Ring4Disc7NegAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc7NegAdcCounts->SetDirectory(Ring4Beam2NegDir);
  theBeam2Ring4Disc8NegAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc8NegAdcCounts->SetDirectory(Ring4Beam2NegDir);
  theBeam2Ring4Disc9NegAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc9NegAdcCounts->SetDirectory(Ring4Beam2NegDir);
  // }}}

  // plots for TEC2TEC beam 2
  theBeam2Ring4Disc1NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc1TEC2TEC","Adc counts on Disc 1 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc1NegTEC2TECAdcCounts->SetDirectory(Ring4Beam2NegDir);
  theBeam2Ring4Disc2NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc2TEC2TEC","Adc counts on Disc 2 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc2NegTEC2TECAdcCounts->SetDirectory(Ring4Beam2NegDir);
  theBeam2Ring4Disc3NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc3TEC2TEC","Adc counts on Disc 3 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc3NegTEC2TECAdcCounts->SetDirectory(Ring4Beam2NegDir);
  theBeam2Ring4Disc4NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc4TEC2TEC","Adc counts on Disc 4 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc4NegTEC2TECAdcCounts->SetDirectory(Ring4Beam2NegDir);
  theBeam2Ring4Disc5NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc5TEC2TEC","Adc counts on Disc 5 for Beam 2 in Ring 4", 512, 0, 511);
  theBeam2Ring4Disc5NegTEC2TECAdcCounts->SetDirectory(Ring4Beam2NegDir);
  // }}}

  // {{{ ----- Adc counts for Beam 3 in Ring 4
  theBeam3Ring4Disc1NegAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 3 in Ring 4", 512, 0, 511);
  theBeam3Ring4Disc1NegAdcCounts->SetDirectory(Ring4Beam3NegDir);
  theBeam3Ring4Disc2NegAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 3 in Ring 4", 512, 0, 511);
  theBeam3Ring4Disc2NegAdcCounts->SetDirectory(Ring4Beam3NegDir);
  theBeam3Ring4Disc3NegAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 3 in Ring 4", 512, 0, 511);
  theBeam3Ring4Disc3NegAdcCounts->SetDirectory(Ring4Beam3NegDir);
  theBeam3Ring4Disc4NegAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 3 in Ring 4", 512, 0, 511);
  theBeam3Ring4Disc4NegAdcCounts->SetDirectory(Ring4Beam3NegDir);
  theBeam3Ring4Disc5NegAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 3 in Ring 4", 512, 0, 511);
  theBeam3Ring4Disc5NegAdcCounts->SetDirectory(Ring4Beam3NegDir);
  theBeam3Ring4Disc6NegAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 3 in Ring 4", 512, 0, 511);
  theBeam3Ring4Disc6NegAdcCounts->SetDirectory(Ring4Beam3NegDir);
  theBeam3Ring4Disc7NegAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 3 in Ring 4", 512, 0, 511);
  theBeam3Ring4Disc7NegAdcCounts->SetDirectory(Ring4Beam3NegDir);
  theBeam3Ring4Disc8NegAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 3 in Ring 4", 512, 0, 511);
  theBeam3Ring4Disc8NegAdcCounts->SetDirectory(Ring4Beam3NegDir);
  theBeam3Ring4Disc9NegAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 3 in Ring 4", 512, 0, 511);
  theBeam3Ring4Disc9NegAdcCounts->SetDirectory(Ring4Beam3NegDir);
  // }}}

  // {{{ ----- Adc counts for Beam 4 in Ring 4
  theBeam4Ring4Disc1NegAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc1NegAdcCounts->SetDirectory(Ring4Beam4NegDir);
  theBeam4Ring4Disc2NegAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc2NegAdcCounts->SetDirectory(Ring4Beam4NegDir);
  theBeam4Ring4Disc3NegAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc3NegAdcCounts->SetDirectory(Ring4Beam4NegDir);
  theBeam4Ring4Disc4NegAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc4NegAdcCounts->SetDirectory(Ring4Beam4NegDir);
  theBeam4Ring4Disc5NegAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc5NegAdcCounts->SetDirectory(Ring4Beam4NegDir);
  theBeam4Ring4Disc6NegAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc6NegAdcCounts->SetDirectory(Ring4Beam4NegDir);
  theBeam4Ring4Disc7NegAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc7NegAdcCounts->SetDirectory(Ring4Beam4NegDir);
  theBeam4Ring4Disc8NegAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc8NegAdcCounts->SetDirectory(Ring4Beam4NegDir);
  theBeam4Ring4Disc9NegAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc9NegAdcCounts->SetDirectory(Ring4Beam4NegDir);
  // }}}

  // plots for TEC2TEC beam 4
  theBeam4Ring4Disc1NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc1TEC2TEC","Adc counts on Disc 1 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc1NegTEC2TECAdcCounts->SetDirectory(Ring4Beam4NegDir);
  theBeam4Ring4Disc2NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc2TEC2TEC","Adc counts on Disc 2 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc2NegTEC2TECAdcCounts->SetDirectory(Ring4Beam4NegDir);
  theBeam4Ring4Disc3NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc3TEC2TEC","Adc counts on Disc 3 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc3NegTEC2TECAdcCounts->SetDirectory(Ring4Beam4NegDir);
  theBeam4Ring4Disc4NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc4TEC2TEC","Adc counts on Disc 4 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc4NegTEC2TECAdcCounts->SetDirectory(Ring4Beam4NegDir);
  theBeam4Ring4Disc5NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc5TEC2TEC","Adc counts on Disc 5 for Beam 4 in Ring 4", 512, 0, 511);
  theBeam4Ring4Disc5NegTEC2TECAdcCounts->SetDirectory(Ring4Beam4NegDir);
  // }}}

  // {{{ ----- Adc counts for Beam 5 in Ring 4
  theBeam5Ring4Disc1NegAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 5 in Ring 4", 512, 0, 511);
  theBeam5Ring4Disc1NegAdcCounts->SetDirectory(Ring4Beam5NegDir);
  theBeam5Ring4Disc2NegAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 5 in Ring 4", 512, 0, 511);
  theBeam5Ring4Disc2NegAdcCounts->SetDirectory(Ring4Beam5NegDir);
  theBeam5Ring4Disc3NegAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 5 in Ring 4", 512, 0, 511);
  theBeam5Ring4Disc3NegAdcCounts->SetDirectory(Ring4Beam5NegDir);
  theBeam5Ring4Disc4NegAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 5 in Ring 4", 512, 0, 511);
  theBeam5Ring4Disc4NegAdcCounts->SetDirectory(Ring4Beam5NegDir);
  theBeam5Ring4Disc5NegAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 5 in Ring 4", 512, 0, 511);
  theBeam5Ring4Disc5NegAdcCounts->SetDirectory(Ring4Beam5NegDir);
  theBeam5Ring4Disc6NegAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 5 in Ring 4", 512, 0, 511);
  theBeam5Ring4Disc6NegAdcCounts->SetDirectory(Ring4Beam5NegDir);
  theBeam5Ring4Disc7NegAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 5 in Ring 4", 512, 0, 511);
  theBeam5Ring4Disc7NegAdcCounts->SetDirectory(Ring4Beam5NegDir);
  theBeam5Ring4Disc8NegAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 5 in Ring 4", 512, 0, 511);
  theBeam5Ring4Disc8NegAdcCounts->SetDirectory(Ring4Beam5NegDir);
  theBeam5Ring4Disc9NegAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 5 in Ring 4", 512, 0, 511);
  theBeam5Ring4Disc9NegAdcCounts->SetDirectory(Ring4Beam5NegDir);
  // }}}

  // {{{ ----- Adc counts for Beam 6 in Ring 4
  theBeam6Ring4Disc1NegAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc1NegAdcCounts->SetDirectory(Ring4Beam6NegDir);
  theBeam6Ring4Disc2NegAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc2NegAdcCounts->SetDirectory(Ring4Beam6NegDir);
  theBeam6Ring4Disc3NegAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc3NegAdcCounts->SetDirectory(Ring4Beam6NegDir);
  theBeam6Ring4Disc4NegAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc4NegAdcCounts->SetDirectory(Ring4Beam6NegDir);
  theBeam6Ring4Disc5NegAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc5NegAdcCounts->SetDirectory(Ring4Beam6NegDir);
  theBeam6Ring4Disc6NegAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc6NegAdcCounts->SetDirectory(Ring4Beam6NegDir);
  theBeam6Ring4Disc7NegAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc7NegAdcCounts->SetDirectory(Ring4Beam6NegDir);
  theBeam6Ring4Disc8NegAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc8NegAdcCounts->SetDirectory(Ring4Beam6NegDir);
  theBeam6Ring4Disc9NegAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc9NegAdcCounts->SetDirectory(Ring4Beam6NegDir);
  // }}}

  // plots for TEC2TEC beam 6
  theBeam6Ring4Disc1NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc1TEC2TEC","Adc counts on Disc 1 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc1NegTEC2TECAdcCounts->SetDirectory(Ring4Beam6NegDir);
  theBeam6Ring4Disc2NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc2TEC2TEC","Adc counts on Disc 2 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc2NegTEC2TECAdcCounts->SetDirectory(Ring4Beam6NegDir);
  theBeam6Ring4Disc3NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc3TEC2TEC","Adc counts on Disc 3 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc3NegTEC2TECAdcCounts->SetDirectory(Ring4Beam6NegDir);
  theBeam6Ring4Disc4NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc4TEC2TEC","Adc counts on Disc 4 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc4NegTEC2TECAdcCounts->SetDirectory(Ring4Beam6NegDir);
  theBeam6Ring4Disc5NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc5TEC2TEC","Adc counts on Disc 5 for Beam 6 in Ring 4", 512, 0, 511);
  theBeam6Ring4Disc5NegTEC2TECAdcCounts->SetDirectory(Ring4Beam6NegDir);
  // }}}

  // {{{ ----- Adc counts for Beam 7 in Ring 4
  theBeam7Ring4Disc1NegAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc1NegAdcCounts->SetDirectory(Ring4Beam7NegDir);
  theBeam7Ring4Disc2NegAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc2NegAdcCounts->SetDirectory(Ring4Beam7NegDir);
  theBeam7Ring4Disc3NegAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc3NegAdcCounts->SetDirectory(Ring4Beam7NegDir);
  theBeam7Ring4Disc4NegAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc4NegAdcCounts->SetDirectory(Ring4Beam7NegDir);
  theBeam7Ring4Disc5NegAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc5NegAdcCounts->SetDirectory(Ring4Beam7NegDir);
  theBeam7Ring4Disc6NegAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc6NegAdcCounts->SetDirectory(Ring4Beam7NegDir);
  theBeam7Ring4Disc7NegAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc7NegAdcCounts->SetDirectory(Ring4Beam7NegDir);
  theBeam7Ring4Disc8NegAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc8NegAdcCounts->SetDirectory(Ring4Beam7NegDir);
  theBeam7Ring4Disc9NegAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc9NegAdcCounts->SetDirectory(Ring4Beam7NegDir);
  // }}}

  // plots for TEC2TEC beam 7
  theBeam7Ring4Disc1NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc1TEC2TEC","Adc counts on Disc 1 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc1NegTEC2TECAdcCounts->SetDirectory(Ring4Beam7NegDir);
  theBeam7Ring4Disc2NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc2TEC2TEC","Adc counts on Disc 2 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc2NegTEC2TECAdcCounts->SetDirectory(Ring4Beam7NegDir);
  theBeam7Ring4Disc3NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc3TEC2TEC","Adc counts on Disc 3 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc3NegTEC2TECAdcCounts->SetDirectory(Ring4Beam7NegDir);
  theBeam7Ring4Disc4NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc4TEC2TEC","Adc counts on Disc 4 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc4NegTEC2TECAdcCounts->SetDirectory(Ring4Beam7NegDir);
  theBeam7Ring4Disc5NegTEC2TECAdcCounts = new TH1D("AdcCountsDisc5TEC2TEC","Adc counts on Disc 5 for Beam 7 in Ring 4", 512, 0, 511);
  theBeam7Ring4Disc5NegTEC2TECAdcCounts->SetDirectory(Ring4Beam7NegDir);
  // }}}

  // {{{ ----- Adc counts for Beam 0 in Ring 6
  theBeam0Ring6Disc1NegAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 0 in Ring 6", 512, 0, 511);
  theBeam0Ring6Disc1NegAdcCounts->SetDirectory(Ring6Beam0NegDir);
  theBeam0Ring6Disc2NegAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 0 in Ring 6", 512, 0, 511);
  theBeam0Ring6Disc2NegAdcCounts->SetDirectory(Ring6Beam0NegDir);
  theBeam0Ring6Disc3NegAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 0 in Ring 6", 512, 0, 511);
  theBeam0Ring6Disc3NegAdcCounts->SetDirectory(Ring6Beam0NegDir);
  theBeam0Ring6Disc4NegAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 0 in Ring 6", 512, 0, 511);
  theBeam0Ring6Disc4NegAdcCounts->SetDirectory(Ring6Beam0NegDir);
  theBeam0Ring6Disc5NegAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 0 in Ring 6", 512, 0, 511);
  theBeam0Ring6Disc5NegAdcCounts->SetDirectory(Ring6Beam0NegDir);
  theBeam0Ring6Disc6NegAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 0 in Ring 6", 512, 0, 511);
  theBeam0Ring6Disc6NegAdcCounts->SetDirectory(Ring6Beam0NegDir);
  theBeam0Ring6Disc7NegAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 0 in Ring 6", 512, 0, 511);
  theBeam0Ring6Disc7NegAdcCounts->SetDirectory(Ring6Beam0NegDir);
  theBeam0Ring6Disc8NegAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 0 in Ring 6", 512, 0, 511);
  theBeam0Ring6Disc8NegAdcCounts->SetDirectory(Ring6Beam0NegDir);
  theBeam0Ring6Disc9NegAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 0 in Ring 6", 512, 0, 511);
  theBeam0Ring6Disc9NegAdcCounts->SetDirectory(Ring6Beam0NegDir);
  // }}}

  // {{{ ----- Adc counts for Beam 1 in Ring 6
  theBeam1Ring6Disc1NegAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 1 in Ring 6", 512, 0, 511);
  theBeam1Ring6Disc1NegAdcCounts->SetDirectory(Ring6Beam1NegDir);
  theBeam1Ring6Disc2NegAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 1 in Ring 6", 512, 0, 511);
  theBeam1Ring6Disc2NegAdcCounts->SetDirectory(Ring6Beam1NegDir);
  theBeam1Ring6Disc3NegAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 1 in Ring 6", 512, 0, 511);
  theBeam1Ring6Disc3NegAdcCounts->SetDirectory(Ring6Beam1NegDir);
  theBeam1Ring6Disc4NegAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 1 in Ring 6", 512, 0, 511);
  theBeam1Ring6Disc4NegAdcCounts->SetDirectory(Ring6Beam1NegDir);
  theBeam1Ring6Disc5NegAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 1 in Ring 6", 512, 0, 511);
  theBeam1Ring6Disc5NegAdcCounts->SetDirectory(Ring6Beam1NegDir);
  theBeam1Ring6Disc6NegAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 1 in Ring 6", 512, 0, 511);
  theBeam1Ring6Disc6NegAdcCounts->SetDirectory(Ring6Beam1NegDir);
  theBeam1Ring6Disc7NegAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 1 in Ring 6", 512, 0, 511);
  theBeam1Ring6Disc7NegAdcCounts->SetDirectory(Ring6Beam1NegDir);
  theBeam1Ring6Disc8NegAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 1 in Ring 6", 512, 0, 511);
  theBeam1Ring6Disc8NegAdcCounts->SetDirectory(Ring6Beam1NegDir);
  theBeam1Ring6Disc9NegAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 1 in Ring 6", 512, 0, 511);
  theBeam1Ring6Disc9NegAdcCounts->SetDirectory(Ring6Beam1NegDir);
  // }}}

  // {{{ ----- Adc counts for Beam 2 in Ring 6
  theBeam2Ring6Disc1NegAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 2 in Ring 6", 512, 0, 511);
  theBeam2Ring6Disc1NegAdcCounts->SetDirectory(Ring6Beam2NegDir);
  theBeam2Ring6Disc2NegAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 2 in Ring 6", 512, 0, 511);
  theBeam2Ring6Disc2NegAdcCounts->SetDirectory(Ring6Beam2NegDir);
  theBeam2Ring6Disc3NegAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 2 in Ring 6", 512, 0, 511);
  theBeam2Ring6Disc3NegAdcCounts->SetDirectory(Ring6Beam2NegDir);
  theBeam2Ring6Disc4NegAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 2 in Ring 6", 512, 0, 511);
  theBeam2Ring6Disc4NegAdcCounts->SetDirectory(Ring6Beam2NegDir);
  theBeam2Ring6Disc5NegAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 2 in Ring 6", 512, 0, 511);
  theBeam2Ring6Disc5NegAdcCounts->SetDirectory(Ring6Beam2NegDir);
  theBeam2Ring6Disc6NegAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 2 in Ring 6", 512, 0, 511);
  theBeam2Ring6Disc6NegAdcCounts->SetDirectory(Ring6Beam2NegDir);
  theBeam2Ring6Disc7NegAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 2 in Ring 6", 512, 0, 511);
  theBeam2Ring6Disc7NegAdcCounts->SetDirectory(Ring6Beam2NegDir);
  theBeam2Ring6Disc8NegAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 2 in Ring 6", 512, 0, 511);
  theBeam2Ring6Disc8NegAdcCounts->SetDirectory(Ring6Beam2NegDir);
  theBeam2Ring6Disc9NegAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 2 in Ring 6", 512, 0, 511);
  theBeam2Ring6Disc9NegAdcCounts->SetDirectory(Ring6Beam2NegDir);
  // }}}

  // {{{ ----- Adc counts for Beam 3 in Ring 6
  theBeam3Ring6Disc1NegAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 3 in Ring 6", 512, 0, 511);
  theBeam3Ring6Disc1NegAdcCounts->SetDirectory(Ring6Beam3NegDir);
  theBeam3Ring6Disc2NegAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 3 in Ring 6", 512, 0, 511);
  theBeam3Ring6Disc2NegAdcCounts->SetDirectory(Ring6Beam3NegDir);
  theBeam3Ring6Disc3NegAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 3 in Ring 6", 512, 0, 511);
  theBeam3Ring6Disc3NegAdcCounts->SetDirectory(Ring6Beam3NegDir);
  theBeam3Ring6Disc4NegAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 3 in Ring 6", 512, 0, 511);
  theBeam3Ring6Disc4NegAdcCounts->SetDirectory(Ring6Beam3NegDir);
  theBeam3Ring6Disc5NegAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 3 in Ring 6", 512, 0, 511);
  theBeam3Ring6Disc5NegAdcCounts->SetDirectory(Ring6Beam3NegDir);
  theBeam3Ring6Disc6NegAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 3 in Ring 6", 512, 0, 511);
  theBeam3Ring6Disc6NegAdcCounts->SetDirectory(Ring6Beam3NegDir);
  theBeam3Ring6Disc7NegAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 3 in Ring 6", 512, 0, 511);
  theBeam3Ring6Disc7NegAdcCounts->SetDirectory(Ring6Beam3NegDir);
  theBeam3Ring6Disc8NegAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 3 in Ring 6", 512, 0, 511);
  theBeam3Ring6Disc8NegAdcCounts->SetDirectory(Ring6Beam3NegDir);
  theBeam3Ring6Disc9NegAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 3 in Ring 6", 512, 0, 511);
  theBeam3Ring6Disc9NegAdcCounts->SetDirectory(Ring6Beam3NegDir);
  // }}}

  // {{{ ----- Adc counts for Beam 4 in Ring 6
  theBeam4Ring6Disc1NegAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 4 in Ring 6", 512, 0, 511);
  theBeam4Ring6Disc1NegAdcCounts->SetDirectory(Ring6Beam4NegDir);
  theBeam4Ring6Disc2NegAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 4 in Ring 6", 512, 0, 511);
  theBeam4Ring6Disc2NegAdcCounts->SetDirectory(Ring6Beam4NegDir);
  theBeam4Ring6Disc3NegAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 4 in Ring 6", 512, 0, 511);
  theBeam4Ring6Disc3NegAdcCounts->SetDirectory(Ring6Beam4NegDir);
  theBeam4Ring6Disc4NegAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 4 in Ring 6", 512, 0, 511);
  theBeam4Ring6Disc4NegAdcCounts->SetDirectory(Ring6Beam4NegDir);
  theBeam4Ring6Disc5NegAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 4 in Ring 6", 512, 0, 511);
  theBeam4Ring6Disc5NegAdcCounts->SetDirectory(Ring6Beam4NegDir);
  theBeam4Ring6Disc6NegAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 4 in Ring 6", 512, 0, 511);
  theBeam4Ring6Disc6NegAdcCounts->SetDirectory(Ring6Beam4NegDir);
  theBeam4Ring6Disc7NegAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 4 in Ring 6", 512, 0, 511);
  theBeam4Ring6Disc7NegAdcCounts->SetDirectory(Ring6Beam4NegDir);
  theBeam4Ring6Disc8NegAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 4 in Ring 6", 512, 0, 511);
  theBeam4Ring6Disc8NegAdcCounts->SetDirectory(Ring6Beam4NegDir);
  theBeam4Ring6Disc9NegAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 4 in Ring 6", 512, 0, 511);
  theBeam4Ring6Disc9NegAdcCounts->SetDirectory(Ring6Beam4NegDir);
  // }}}

  // {{{ ----- Adc counts for Beam 5 in Ring 6
  theBeam5Ring6Disc1NegAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 5 in Ring 6", 512, 0, 511);
  theBeam5Ring6Disc1NegAdcCounts->SetDirectory(Ring6Beam5NegDir);
  theBeam5Ring6Disc2NegAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 5 in Ring 6", 512, 0, 511);
  theBeam5Ring6Disc2NegAdcCounts->SetDirectory(Ring6Beam5NegDir);
  theBeam5Ring6Disc3NegAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 5 in Ring 6", 512, 0, 511);
  theBeam5Ring6Disc3NegAdcCounts->SetDirectory(Ring6Beam5NegDir);
  theBeam5Ring6Disc4NegAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 5 in Ring 6", 512, 0, 511);
  theBeam5Ring6Disc4NegAdcCounts->SetDirectory(Ring6Beam5NegDir);
  theBeam5Ring6Disc5NegAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 5 in Ring 6", 512, 0, 511);
  theBeam5Ring6Disc5NegAdcCounts->SetDirectory(Ring6Beam5NegDir);
  theBeam5Ring6Disc6NegAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 5 in Ring 6", 512, 0, 511);
  theBeam5Ring6Disc6NegAdcCounts->SetDirectory(Ring6Beam5NegDir);
  theBeam5Ring6Disc7NegAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 5 in Ring 6", 512, 0, 511);
  theBeam5Ring6Disc7NegAdcCounts->SetDirectory(Ring6Beam5NegDir);
  theBeam5Ring6Disc8NegAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 5 in Ring 6", 512, 0, 511);
  theBeam5Ring6Disc8NegAdcCounts->SetDirectory(Ring6Beam5NegDir);
  theBeam5Ring6Disc9NegAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 5 in Ring 6", 512, 0, 511);
  theBeam5Ring6Disc9NegAdcCounts->SetDirectory(Ring6Beam5NegDir);
  // }}}

  // {{{ ----- Adc counts for Beam 6 in Ring 6
  theBeam6Ring6Disc1NegAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 6 in Ring 6", 512, 0, 511);
  theBeam6Ring6Disc1NegAdcCounts->SetDirectory(Ring6Beam6NegDir);
  theBeam6Ring6Disc2NegAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 6 in Ring 6", 512, 0, 511);
  theBeam6Ring6Disc2NegAdcCounts->SetDirectory(Ring6Beam6NegDir);
  theBeam6Ring6Disc3NegAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 6 in Ring 6", 512, 0, 511);
  theBeam6Ring6Disc3NegAdcCounts->SetDirectory(Ring6Beam6NegDir);
  theBeam6Ring6Disc4NegAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 6 in Ring 6", 512, 0, 511);
  theBeam6Ring6Disc4NegAdcCounts->SetDirectory(Ring6Beam6NegDir);
  theBeam6Ring6Disc5NegAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 6 in Ring 6", 512, 0, 511);
  theBeam6Ring6Disc5NegAdcCounts->SetDirectory(Ring6Beam6NegDir);
  theBeam6Ring6Disc6NegAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 6 in Ring 6", 512, 0, 511);
  theBeam6Ring6Disc6NegAdcCounts->SetDirectory(Ring6Beam6NegDir);
  theBeam6Ring6Disc7NegAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 6 in Ring 6", 512, 0, 511);
  theBeam6Ring6Disc7NegAdcCounts->SetDirectory(Ring6Beam6NegDir);
  theBeam6Ring6Disc8NegAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 6 in Ring 6", 512, 0, 511);
  theBeam6Ring6Disc8NegAdcCounts->SetDirectory(Ring6Beam6NegDir);
  theBeam6Ring6Disc9NegAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 6 in Ring 6", 512, 0, 511);
  theBeam6Ring6Disc9NegAdcCounts->SetDirectory(Ring6Beam6NegDir);
  // }}}

  // {{{ ----- Adc counts for Beam 7 in Ring 6
  theBeam7Ring6Disc1NegAdcCounts = new TH1D("AdcCountsDisc1","Adc counts on Disc 1 for Beam 7 in Ring 6", 512, 0, 511);
  theBeam7Ring6Disc1NegAdcCounts->SetDirectory(Ring6Beam7NegDir);
  theBeam7Ring6Disc2NegAdcCounts = new TH1D("AdcCountsDisc2","Adc counts on Disc 2 for Beam 7 in Ring 6", 512, 0, 511);
  theBeam7Ring6Disc2NegAdcCounts->SetDirectory(Ring6Beam7NegDir);
  theBeam7Ring6Disc3NegAdcCounts = new TH1D("AdcCountsDisc3","Adc counts on Disc 3 for Beam 7 in Ring 6", 512, 0, 511);
  theBeam7Ring6Disc3NegAdcCounts->SetDirectory(Ring6Beam7NegDir);
  theBeam7Ring6Disc4NegAdcCounts = new TH1D("AdcCountsDisc4","Adc counts on Disc 4 for Beam 7 in Ring 6", 512, 0, 511);
  theBeam7Ring6Disc4NegAdcCounts->SetDirectory(Ring6Beam7NegDir);
  theBeam7Ring6Disc5NegAdcCounts = new TH1D("AdcCountsDisc5","Adc counts on Disc 5 for Beam 7 in Ring 6", 512, 0, 511);
  theBeam7Ring6Disc5NegAdcCounts->SetDirectory(Ring6Beam7NegDir);
  theBeam7Ring6Disc6NegAdcCounts = new TH1D("AdcCountsDisc6","Adc counts on Disc 6 for Beam 7 in Ring 6", 512, 0, 511);
  theBeam7Ring6Disc6NegAdcCounts->SetDirectory(Ring6Beam7NegDir);
  theBeam7Ring6Disc7NegAdcCounts = new TH1D("AdcCountsDisc7","Adc counts on Disc 7 for Beam 7 in Ring 6", 512, 0, 511);
  theBeam7Ring6Disc7NegAdcCounts->SetDirectory(Ring6Beam7NegDir);
  theBeam7Ring6Disc8NegAdcCounts = new TH1D("AdcCountsDisc8","Adc counts on Disc 8 for Beam 7 in Ring 6", 512, 0, 511);
  theBeam7Ring6Disc8NegAdcCounts->SetDirectory(Ring6Beam7NegDir);
  theBeam7Ring6Disc9NegAdcCounts = new TH1D("AdcCountsDisc9","Adc counts on Disc 9 for Beam 7 in Ring 6", 512, 0, 511);
  theBeam7Ring6Disc9NegAdcCounts->SetDirectory(Ring6Beam7NegDir);
  // }}}

  /* LaserBeams in the TOB */
  /**************************************** 
   * the different z positions of the beams
   * are numbered in the following way
   *
   * Position1 = +1040 mm
   * Position2 = +580 mm
   * Position3 = +220 mm
   * Position4 = -140 mm
   * Position5 = -500 mm
   * Position6 = -860 mm
   *****************************************/
  // {{{ ----- Adc Counts in Beam 0
  theBeam0TOBPosition1AdcCounts = new TH1D("AdcCountsZ=1040mm","Adc counts for Beam 0 at z = 1040 mm", 512, 0, 511);
  theBeam0TOBPosition1AdcCounts->SetDirectory(Beam0TOBDir);
  theBeam0TOBPosition2AdcCounts = new TH1D("AdcCountsZ=580mm","Adc counts for Beam 0 at z = 580 mm", 512, 0, 511);
  theBeam0TOBPosition2AdcCounts->SetDirectory(Beam0TOBDir);
  theBeam0TOBPosition3AdcCounts = new TH1D("AdcCountsZ=220mm","Adc counts for Beam 0 at z = 220 mm", 512, 0, 511);
  theBeam0TOBPosition3AdcCounts->SetDirectory(Beam0TOBDir);
  theBeam0TOBPosition4AdcCounts = new TH1D("AdcCountsZ=-140mm","Adc counts for Beam 0 at z = -140 mm", 512, 0, 511);
  theBeam0TOBPosition4AdcCounts->SetDirectory(Beam0TOBDir);
  theBeam0TOBPosition5AdcCounts = new TH1D("AdcCountsZ=-500mm","Adc counts for Beam 0 at z = -500 mm", 512, 0, 511);
  theBeam0TOBPosition5AdcCounts->SetDirectory(Beam0TOBDir);
  theBeam0TOBPosition6AdcCounts = new TH1D("AdcCountsZ=-860mm","Adc counts for Beam 0 at z = -860 mm", 512, 0, 511);
  theBeam0TOBPosition6AdcCounts->SetDirectory(Beam0TOBDir);
  // }}}

  // {{{ ----- Adc Counts in Beam 1
  theBeam1TOBPosition1AdcCounts = new TH1D("AdcCountsZ=1040mm","Adc counts for Beam 1 at z = 1040 mm", 512, 0, 511);
  theBeam1TOBPosition1AdcCounts->SetDirectory(Beam1TOBDir);
  theBeam1TOBPosition2AdcCounts = new TH1D("AdcCountsZ=580mm","Adc counts for Beam 1 at z = 580 mm", 512, 0, 511);
  theBeam1TOBPosition2AdcCounts->SetDirectory(Beam1TOBDir);
  theBeam1TOBPosition3AdcCounts = new TH1D("AdcCountsZ=220mm","Adc counts for Beam 1 at z = 220 mm", 512, 0, 511);
  theBeam1TOBPosition3AdcCounts->SetDirectory(Beam1TOBDir);
  theBeam1TOBPosition4AdcCounts = new TH1D("AdcCountsZ=-140mm","Adc counts for Beam 1 at z = -140 mm", 512, 0, 511);
  theBeam1TOBPosition4AdcCounts->SetDirectory(Beam1TOBDir);
  theBeam1TOBPosition5AdcCounts = new TH1D("AdcCountsZ=-500mm","Adc counts for Beam 1 at z = -500 mm", 512, 0, 511);
  theBeam1TOBPosition5AdcCounts->SetDirectory(Beam1TOBDir);
  theBeam1TOBPosition6AdcCounts = new TH1D("AdcCountsZ=-860mm","Adc counts for Beam 1 at z = -860 mm", 512, 0, 511);
  theBeam1TOBPosition6AdcCounts->SetDirectory(Beam1TOBDir);
  // }}}
  
  // {{{ ----- Adc Counts in Beam 2
  theBeam2TOBPosition1AdcCounts = new TH1D("AdcCountsZ=1040mm","Adc counts for Beam 2 at z = 1040 mm", 512, 0, 511);
  theBeam2TOBPosition1AdcCounts->SetDirectory(Beam2TOBDir);
  theBeam2TOBPosition2AdcCounts = new TH1D("AdcCountsZ=580mm","Adc counts for Beam 2 at z = 580 mm", 512, 0, 511);
  theBeam2TOBPosition2AdcCounts->SetDirectory(Beam2TOBDir);
  theBeam2TOBPosition3AdcCounts = new TH1D("AdcCountsZ=220mm","Adc counts for Beam 2 at z = 220 mm", 512, 0, 511);
  theBeam2TOBPosition3AdcCounts->SetDirectory(Beam2TOBDir);
  theBeam2TOBPosition4AdcCounts = new TH1D("AdcCountsZ=-140mm","Adc counts for Beam 2 at z = -140 mm", 512, 0, 511);
  theBeam2TOBPosition4AdcCounts->SetDirectory(Beam2TOBDir);
  theBeam2TOBPosition5AdcCounts = new TH1D("AdcCountsZ=-500mm","Adc counts for Beam 2 at z = -500 mm", 512, 0, 511);
  theBeam2TOBPosition5AdcCounts->SetDirectory(Beam2TOBDir);
  theBeam2TOBPosition6AdcCounts = new TH1D("AdcCountsZ=-860mm","Adc counts for Beam 2 at z = -860 mm", 512, 0, 511);
  theBeam2TOBPosition6AdcCounts->SetDirectory(Beam2TOBDir);
  // }}}

  // {{{ ----- Adc Counts in Beam 3
  theBeam3TOBPosition1AdcCounts = new TH1D("AdcCountsZ=1040mm","Adc counts for Beam 3 at z = 1040 mm", 512, 0, 511);
  theBeam3TOBPosition1AdcCounts->SetDirectory(Beam3TOBDir);
  theBeam3TOBPosition2AdcCounts = new TH1D("AdcCountsZ=580mm","Adc counts for Beam 3 at z = 580 mm", 512, 0, 511);
  theBeam3TOBPosition2AdcCounts->SetDirectory(Beam3TOBDir);
  theBeam3TOBPosition3AdcCounts = new TH1D("AdcCountsZ=220mm","Adc counts for Beam 3 at z = 220 mm", 512, 0, 511);
  theBeam3TOBPosition3AdcCounts->SetDirectory(Beam3TOBDir);
  theBeam3TOBPosition4AdcCounts = new TH1D("AdcCountsZ=-140mm","Adc counts for Beam 3 at z = -140 mm", 512, 0, 511);
  theBeam3TOBPosition4AdcCounts->SetDirectory(Beam3TOBDir);
  theBeam3TOBPosition5AdcCounts = new TH1D("AdcCountsZ=-500mm","Adc counts for Beam 3 at z = -500 mm", 512, 0, 511);
  theBeam3TOBPosition5AdcCounts->SetDirectory(Beam3TOBDir);
  theBeam3TOBPosition6AdcCounts = new TH1D("AdcCountsZ=-860mm","Adc counts for Beam 3 at z = -860 mm", 512, 0, 511);
  theBeam3TOBPosition6AdcCounts->SetDirectory(Beam3TOBDir);
  // }}}

  // {{{ ----- Adc Counts in Beam 4
  theBeam4TOBPosition1AdcCounts = new TH1D("AdcCountsZ=1040mm","Adc counts for Beam 4 at z = 1040 mm", 512, 0, 511);
  theBeam4TOBPosition1AdcCounts->SetDirectory(Beam4TOBDir);
  theBeam4TOBPosition2AdcCounts = new TH1D("AdcCountsZ=580mm","Adc counts for Beam 4 at z = 580 mm", 512, 0, 511);
  theBeam4TOBPosition2AdcCounts->SetDirectory(Beam4TOBDir);
  theBeam4TOBPosition3AdcCounts = new TH1D("AdcCountsZ=220mm","Adc counts for Beam 4 at z = 220 mm", 512, 0, 511);
  theBeam4TOBPosition3AdcCounts->SetDirectory(Beam4TOBDir);
  theBeam4TOBPosition4AdcCounts = new TH1D("AdcCountsZ=-140mm","Adc counts for Beam 4 at z = -140 mm", 512, 0, 511);
  theBeam4TOBPosition4AdcCounts->SetDirectory(Beam4TOBDir);
  theBeam4TOBPosition5AdcCounts = new TH1D("AdcCountsZ=-500mm","Adc counts for Beam 4 at z = -500 mm", 512, 0, 511);
  theBeam4TOBPosition5AdcCounts->SetDirectory(Beam4TOBDir);
  theBeam4TOBPosition6AdcCounts = new TH1D("AdcCountsZ=-860mm","Adc counts for Beam 4 at z = -860 mm", 512, 0, 511);
  theBeam4TOBPosition6AdcCounts->SetDirectory(Beam4TOBDir);
  // }}}

  // {{{ ----- Adc Counts in Beam 5
  theBeam5TOBPosition1AdcCounts = new TH1D("AdcCountsZ=1040mm","Adc counts for Beam 5 at z = 1040 mm", 512, 0, 511);
  theBeam5TOBPosition1AdcCounts->SetDirectory(Beam5TOBDir);
  theBeam5TOBPosition2AdcCounts = new TH1D("AdcCountsZ=580mm","Adc counts for Beam 5 at z = 580 mm", 512, 0, 511);
  theBeam5TOBPosition2AdcCounts->SetDirectory(Beam5TOBDir);
  theBeam5TOBPosition3AdcCounts = new TH1D("AdcCountsZ=220mm","Adc counts for Beam 5 at z = 220 mm", 512, 0, 511);
  theBeam5TOBPosition3AdcCounts->SetDirectory(Beam5TOBDir);
  theBeam5TOBPosition4AdcCounts = new TH1D("AdcCountsZ=-140mm","Adc counts for Beam 5 at z = -140 mm", 512, 0, 511);
  theBeam5TOBPosition4AdcCounts->SetDirectory(Beam5TOBDir);
  theBeam5TOBPosition5AdcCounts = new TH1D("AdcCountsZ=-500mm","Adc counts for Beam 5 at z = -500 mm", 512, 0, 511);
  theBeam5TOBPosition5AdcCounts->SetDirectory(Beam5TOBDir);
  theBeam5TOBPosition6AdcCounts = new TH1D("AdcCountsZ=-860mm","Adc counts for Beam 5 at z = -860 mm", 512, 0, 511);
  theBeam5TOBPosition6AdcCounts->SetDirectory(Beam5TOBDir);
  // }}}

  // {{{ ----- Adc Counts in Beam 6
  theBeam6TOBPosition1AdcCounts = new TH1D("AdcCountsZ=1040mm","Adc counts for Beam 6 at z = 1040 mm", 512, 0, 511);
  theBeam6TOBPosition1AdcCounts->SetDirectory(Beam6TOBDir);
  theBeam6TOBPosition2AdcCounts = new TH1D("AdcCountsZ=580mm","Adc counts for Beam 6 at z = 580 mm", 512, 0, 511);
  theBeam6TOBPosition2AdcCounts->SetDirectory(Beam6TOBDir);
  theBeam6TOBPosition3AdcCounts = new TH1D("AdcCountsZ=220mm","Adc counts for Beam 6 at z = 220 mm", 512, 0, 511);
  theBeam6TOBPosition3AdcCounts->SetDirectory(Beam6TOBDir);
  theBeam6TOBPosition4AdcCounts = new TH1D("AdcCountsZ=-140mm","Adc counts for Beam 6 at z = -140 mm", 512, 0, 511);
  theBeam6TOBPosition4AdcCounts->SetDirectory(Beam6TOBDir);
  theBeam6TOBPosition5AdcCounts = new TH1D("AdcCountsZ=-500mm","Adc counts for Beam 6 at z = -500 mm", 512, 0, 511);
  theBeam6TOBPosition5AdcCounts->SetDirectory(Beam6TOBDir);
  theBeam6TOBPosition6AdcCounts = new TH1D("AdcCountsZ=-860mm","Adc counts for Beam 6 at z = -860 mm", 512, 0, 511);
  theBeam6TOBPosition6AdcCounts->SetDirectory(Beam6TOBDir);
  // }}}

  // {{{ ----- Adc Counts in Beam 7
  theBeam7TOBPosition1AdcCounts = new TH1D("AdcCountsZ=1040mm","Adc counts for Beam 7 at z = 1040 mm", 512, 0, 511);
  theBeam7TOBPosition1AdcCounts->SetDirectory(Beam7TOBDir);
  theBeam7TOBPosition2AdcCounts = new TH1D("AdcCountsZ=580mm","Adc counts for Beam 7 at z = 580 mm", 512, 0, 511);
  theBeam7TOBPosition2AdcCounts->SetDirectory(Beam7TOBDir);
  theBeam7TOBPosition3AdcCounts = new TH1D("AdcCountsZ=220mm","Adc counts for Beam 7 at z = 220 mm", 512, 0, 511);
  theBeam7TOBPosition3AdcCounts->SetDirectory(Beam7TOBDir);
  theBeam7TOBPosition4AdcCounts = new TH1D("AdcCountsZ=-140mm","Adc counts for Beam 7 at z = -140 mm", 512, 0, 511);
  theBeam7TOBPosition4AdcCounts->SetDirectory(Beam7TOBDir);
  theBeam7TOBPosition5AdcCounts = new TH1D("AdcCountsZ=-500mm","Adc counts for Beam 7 at z = -500 mm", 512, 0, 511);
  theBeam7TOBPosition5AdcCounts->SetDirectory(Beam7TOBDir);
  theBeam7TOBPosition6AdcCounts = new TH1D("AdcCountsZ=-860mm","Adc counts for Beam 7 at z = -860 mm", 512, 0, 511);
  theBeam7TOBPosition6AdcCounts->SetDirectory(Beam7TOBDir);
  // }}}

  /* LaserBeams in the TIB */
  /**************************************** 
   * the different z positions of the beams
   * are numbered in the following way
   *
   * Position1 = +620 mm
   * Position2 = +380 mm
   * Position3 = +180 mm
   * Position4 = -100 mm
   * Position5 = -340 mm
   * Position6 = -540 mm
   *****************************************/
  // {{{ ----- Adc Counts in Beam 0
  theBeam0TIBPosition1AdcCounts = new TH1D("AdcCountsZ=620mm","Adc counts for Beam 0 at z = 620 mm", 512, 0, 511);
  theBeam0TIBPosition1AdcCounts->SetDirectory(Beam0TIBDir);
  theBeam0TIBPosition2AdcCounts = new TH1D("AdcCountsZ=380mm","Adc counts for Beam 0 at z = 380 mm", 512, 0, 511);
  theBeam0TIBPosition2AdcCounts->SetDirectory(Beam0TIBDir);
  theBeam0TIBPosition3AdcCounts = new TH1D("AdcCountsZ=180mm","Adc counts for Beam 0 at z = 180 mm", 512, 0, 511);
  theBeam0TIBPosition3AdcCounts->SetDirectory(Beam0TIBDir);
  theBeam0TIBPosition4AdcCounts = new TH1D("AdcCountsZ=-100mm","Adc counts for Beam 0 at z = -100 mm", 512, 0, 511);
  theBeam0TIBPosition4AdcCounts->SetDirectory(Beam0TIBDir);
  theBeam0TIBPosition5AdcCounts = new TH1D("AdcCountsZ=-340mm","Adc counts for Beam 0 at z = -340 mm", 512, 0, 511);
  theBeam0TIBPosition5AdcCounts->SetDirectory(Beam0TIBDir);
  theBeam0TIBPosition6AdcCounts = new TH1D("AdcCountsZ=-540mm","Adc counts for Beam 0 at z = -540 mm", 512, 0, 511);
  theBeam0TIBPosition6AdcCounts->SetDirectory(Beam0TIBDir);
  // }}}

  // {{{ ----- Adc Counts in Beam 1
  theBeam1TIBPosition1AdcCounts = new TH1D("AdcCountsZ=620mm","Adc counts for Beam 1 at z = 620 mm", 512, 0, 511);
  theBeam1TIBPosition1AdcCounts->SetDirectory(Beam1TIBDir);
  theBeam1TIBPosition2AdcCounts = new TH1D("AdcCountsZ=380mm","Adc counts for Beam 1 at z = 380 mm", 512, 0, 511);
  theBeam1TIBPosition2AdcCounts->SetDirectory(Beam1TIBDir);
  theBeam1TIBPosition3AdcCounts = new TH1D("AdcCountsZ=180mm","Adc counts for Beam 1 at z = 180 mm", 512, 0, 511);
  theBeam1TIBPosition3AdcCounts->SetDirectory(Beam1TIBDir);
  theBeam1TIBPosition4AdcCounts = new TH1D("AdcCountsZ=-100mm","Adc counts for Beam 1 at z = -100 mm", 512, 0, 511);
  theBeam1TIBPosition4AdcCounts->SetDirectory(Beam1TIBDir);
  theBeam1TIBPosition5AdcCounts = new TH1D("AdcCountsZ=-340mm","Adc counts for Beam 1 at z = -340 mm", 512, 0, 511);
  theBeam1TIBPosition5AdcCounts->SetDirectory(Beam1TIBDir);
  theBeam1TIBPosition6AdcCounts = new TH1D("AdcCountsZ=-540mm","Adc counts for Beam 1 at z = -540 mm", 512, 0, 511);
  theBeam1TIBPosition6AdcCounts->SetDirectory(Beam1TIBDir);
  // }}}

  // {{{ ----- Adc Counts in Beam 2
  theBeam2TIBPosition1AdcCounts = new TH1D("AdcCountsZ=620mm","Adc counts for Beam 2 at z = 620 mm", 512, 0, 511);
  theBeam2TIBPosition1AdcCounts->SetDirectory(Beam2TIBDir);
  theBeam2TIBPosition2AdcCounts = new TH1D("AdcCountsZ=380mm","Adc counts for Beam 2 at z = 380 mm", 512, 0, 511);
  theBeam2TIBPosition2AdcCounts->SetDirectory(Beam2TIBDir);
  theBeam2TIBPosition3AdcCounts = new TH1D("AdcCountsZ=180mm","Adc counts for Beam 2 at z = 180 mm", 512, 0, 511);
  theBeam2TIBPosition3AdcCounts->SetDirectory(Beam2TIBDir);
  theBeam2TIBPosition4AdcCounts = new TH1D("AdcCountsZ=-100mm","Adc counts for Beam 2 at z = -100 mm", 512, 0, 511);
  theBeam2TIBPosition4AdcCounts->SetDirectory(Beam2TIBDir);
  theBeam2TIBPosition5AdcCounts = new TH1D("AdcCountsZ=-340mm","Adc counts for Beam 2 at z = -340 mm", 512, 0, 511);
  theBeam2TIBPosition5AdcCounts->SetDirectory(Beam2TIBDir);
  theBeam2TIBPosition6AdcCounts = new TH1D("AdcCountsZ=-540mm","Adc counts for Beam 2 at z = -540 mm", 512, 0, 511);
  theBeam2TIBPosition6AdcCounts->SetDirectory(Beam2TIBDir);
  // }}}

  // {{{ ----- Adc Counts in Beam 3
  theBeam3TIBPosition1AdcCounts = new TH1D("AdcCountsZ=620mm","Adc counts for Beam 3 at z = 620 mm", 512, 0, 511);
  theBeam3TIBPosition1AdcCounts->SetDirectory(Beam3TIBDir);
  theBeam3TIBPosition2AdcCounts = new TH1D("AdcCountsZ=380mm","Adc counts for Beam 3 at z = 380 mm", 512, 0, 511);
  theBeam3TIBPosition2AdcCounts->SetDirectory(Beam3TIBDir);
  theBeam3TIBPosition3AdcCounts = new TH1D("AdcCountsZ=180mm","Adc counts for Beam 3 at z = 180 mm", 512, 0, 511);
  theBeam3TIBPosition3AdcCounts->SetDirectory(Beam3TIBDir);
  theBeam3TIBPosition4AdcCounts = new TH1D("AdcCountsZ=-100mm","Adc counts for Beam 3 at z = -100 mm", 512, 0, 511);
  theBeam3TIBPosition4AdcCounts->SetDirectory(Beam3TIBDir);
  theBeam3TIBPosition5AdcCounts = new TH1D("AdcCountsZ=-340mm","Adc counts for Beam 3 at z = -340 mm", 512, 0, 511);
  theBeam3TIBPosition5AdcCounts->SetDirectory(Beam3TIBDir);
  theBeam3TIBPosition6AdcCounts = new TH1D("AdcCountsZ=-540mm","Adc counts for Beam 3 at z = -540 mm", 512, 0, 511);
  theBeam3TIBPosition6AdcCounts->SetDirectory(Beam3TIBDir);
  // }}}

  // {{{ ----- Adc Counts in Beam 4
  theBeam4TIBPosition1AdcCounts = new TH1D("AdcCountsZ=620mm","Adc counts for Beam 4 at z = 620 mm", 512, 0, 511);
  theBeam4TIBPosition1AdcCounts->SetDirectory(Beam4TIBDir);
  theBeam4TIBPosition2AdcCounts = new TH1D("AdcCountsZ=380mm","Adc counts for Beam 4 at z = 380 mm", 512, 0, 511);
  theBeam4TIBPosition2AdcCounts->SetDirectory(Beam4TIBDir);
  theBeam4TIBPosition3AdcCounts = new TH1D("AdcCountsZ=180mm","Adc counts for Beam 4 at z = 180 mm", 512, 0, 511);
  theBeam4TIBPosition3AdcCounts->SetDirectory(Beam4TIBDir);
  theBeam4TIBPosition4AdcCounts = new TH1D("AdcCountsZ=-100mm","Adc counts for Beam 4 at z = -100 mm", 512, 0, 511);
  theBeam4TIBPosition4AdcCounts->SetDirectory(Beam4TIBDir);
  theBeam4TIBPosition5AdcCounts = new TH1D("AdcCountsZ=-340mm","Adc counts for Beam 4 at z = -340 mm", 512, 0, 511);
  theBeam4TIBPosition5AdcCounts->SetDirectory(Beam4TIBDir);
  theBeam4TIBPosition6AdcCounts = new TH1D("AdcCountsZ=-540mm","Adc counts for Beam 4 at z = -540 mm", 512, 0, 511);
  theBeam4TIBPosition6AdcCounts->SetDirectory(Beam4TIBDir);
  // }}}

  // {{{ ----- Adc Counts in Beam 5
  theBeam5TIBPosition1AdcCounts = new TH1D("AdcCountsZ=620mm","Adc counts for Beam 5 at z = 620 mm", 512, 0, 511);
  theBeam5TIBPosition1AdcCounts->SetDirectory(Beam5TIBDir);
  theBeam5TIBPosition2AdcCounts = new TH1D("AdcCountsZ=380mm","Adc counts for Beam 5 at z = 380 mm", 512, 0, 511);
  theBeam5TIBPosition2AdcCounts->SetDirectory(Beam5TIBDir);
  theBeam5TIBPosition3AdcCounts = new TH1D("AdcCountsZ=180mm","Adc counts for Beam 5 at z = 180 mm", 512, 0, 511);
  theBeam5TIBPosition3AdcCounts->SetDirectory(Beam5TIBDir);
  theBeam5TIBPosition4AdcCounts = new TH1D("AdcCountsZ=-100mm","Adc counts for Beam 5 at z = -100 mm", 512, 0, 511);
  theBeam5TIBPosition4AdcCounts->SetDirectory(Beam5TIBDir);
  theBeam5TIBPosition5AdcCounts = new TH1D("AdcCountsZ=-340mm","Adc counts for Beam 5 at z = -340 mm", 512, 0, 511);
  theBeam5TIBPosition5AdcCounts->SetDirectory(Beam5TIBDir);
  theBeam5TIBPosition6AdcCounts = new TH1D("AdcCountsZ=-540mm","Adc counts for Beam 5 at z = -540 mm", 512, 0, 511);
  theBeam5TIBPosition6AdcCounts->SetDirectory(Beam5TIBDir);
  // }}}

  // {{{ ----- Adc Counts in Beam 6
  theBeam6TIBPosition1AdcCounts = new TH1D("AdcCountsZ=620mm","Adc counts for Beam 6 at z = 620 mm", 512, 0, 511);
  theBeam6TIBPosition1AdcCounts->SetDirectory(Beam6TIBDir);
  theBeam6TIBPosition2AdcCounts = new TH1D("AdcCountsZ=380mm","Adc counts for Beam 6 at z = 380 mm", 512, 0, 511);
  theBeam6TIBPosition2AdcCounts->SetDirectory(Beam6TIBDir);
  theBeam6TIBPosition3AdcCounts = new TH1D("AdcCountsZ=180mm","Adc counts for Beam 6 at z = 180 mm", 512, 0, 511);
  theBeam6TIBPosition3AdcCounts->SetDirectory(Beam6TIBDir);
  theBeam6TIBPosition4AdcCounts = new TH1D("AdcCountsZ=-100mm","Adc counts for Beam 6 at z = -100 mm", 512, 0, 511);
  theBeam6TIBPosition4AdcCounts->SetDirectory(Beam6TIBDir);
  theBeam6TIBPosition5AdcCounts = new TH1D("AdcCountsZ=-340mm","Adc counts for Beam 6 at z = -340 mm", 512, 0, 511);
  theBeam6TIBPosition5AdcCounts->SetDirectory(Beam6TIBDir);
  theBeam6TIBPosition6AdcCounts = new TH1D("AdcCountsZ=-540mm","Adc counts for Beam 6 at z = -540 mm", 512, 0, 511);
  theBeam6TIBPosition6AdcCounts->SetDirectory(Beam6TIBDir);
  // }}}

  // {{{ ----- Adc Counts in Beam 7
  theBeam7TIBPosition1AdcCounts = new TH1D("AdcCountsZ=620mm","Adc counts for Beam 7 at z = 620 mm", 512, 0, 511);
  theBeam7TIBPosition1AdcCounts->SetDirectory(Beam7TIBDir);
  theBeam7TIBPosition2AdcCounts = new TH1D("AdcCountsZ=380mm","Adc counts for Beam 7 at z = 380 mm", 512, 0, 511);
  theBeam7TIBPosition2AdcCounts->SetDirectory(Beam7TIBDir);
  theBeam7TIBPosition3AdcCounts = new TH1D("AdcCountsZ=180mm","Adc counts for Beam 7 at z = 180 mm", 512, 0, 511);
  theBeam7TIBPosition3AdcCounts->SetDirectory(Beam7TIBDir);
  theBeam7TIBPosition4AdcCounts = new TH1D("AdcCountsZ=-100mm","Adc counts for Beam 7 at z = -100 mm", 512, 0, 511);
  theBeam7TIBPosition4AdcCounts->SetDirectory(Beam7TIBDir);
  theBeam7TIBPosition5AdcCounts = new TH1D("AdcCountsZ=-340mm","Adc counts for Beam 7 at z = -340 mm", 512, 0, 511);
  theBeam7TIBPosition5AdcCounts->SetDirectory(Beam7TIBDir);
  theBeam7TIBPosition6AdcCounts = new TH1D("AdcCountsZ=-540mm","Adc counts for Beam 7 at z = -540 mm", 512, 0, 511);
  theBeam7TIBPosition6AdcCounts->SetDirectory(Beam7TIBDir);
  // }}}

  // {{{ ----- Clusters
  theClusterPositions = new TH1D("ClusterBarycenter","Barycenter of the clusters", 20, 0.0, 900.0);
  theClusterPositions->SetDirectory(ClusterDir);
  // }}}

  // {{{ ----- RecHits
  theRecHitPositionsX = new TH1D("RecHitPositionsX","X position of the RecHits", 200, -100.0, 100.0);
  theRecHitPositionsX->SetDirectory(RecHitDir);
  theRecHitPositionsX->Sumw2();
  theRecHitPositionsY = new TH1D("RecHitPositionsY","Y position of the RecHits", 200, -100.0, 100.0);
  theRecHitPositionsY->SetDirectory(RecHitDir);
  theRecHitPositionsY->Sumw2();
  theRecHitPositionsZ = new TH1D("RecHitPositionsZ","Z position of the RecHits", 600, -300.0, 300.0);
  theRecHitPositionsZ->SetDirectory(RecHitDir);
  theRecHitPositionsZ->Sumw2();
  theRecHitPositionsYvsX = new TH2D("RecHitPositionsYvsX","Y vs X position of the RecHits", 
				    200, -100.0, 100.0, 200, -100.0, 100.0);
  theRecHitPositionsYvsX->SetDirectory(RecHitDir);
  theRecHitPositionsYvsX->Sumw2();
  theRecHitPositionsPhivsZ = new TH2D("RecHitPositionsPhivsZ","Phi vs Z position of the RecHits",
				      600, -300.0, 300.0, 70, -3.5, 3.5);
  theRecHitPositionsPhivsZ->SetDirectory(RecHitDir);
  theRecHitPositionsPhivsZ->Sumw2();
  theRecHitPositionsRvsZ = new TH2D("RecHitPositionsRvsZ","R vs Z position of the RecHits",
				    600, -300.0, 300.0, 200, -100.0, 100.0);
  theRecHitPositionsRvsZ->SetDirectory(RecHitDir);
  theRecHitPositionsRvsZ->Sumw2();
  // }}}
}
