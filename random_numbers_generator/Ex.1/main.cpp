#include <iostream>

#include "RandomGen.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"  

int main() {
  
   TApplication app("app",0,0);

   RandomGen mygen(1);

   int nmax = 10000;

   //===================== UNIFORME =======================

   TH1F unif("Uniforme","Uniforme",250,4,11);

   for ( int k=0; k<nmax; k++){
     unif.Fill(mygen.Unif(5,10)); 
   }

   TCanvas can1("Uniforme","Uniforme");
   unif.GetXaxis()->SetTitle("x [AU]");
   unif.GetYaxis()->SetTitle("N");
   unif.SetTitle("Distribuzione uniforme");
   unif.Draw();

   //==================== ESPONENZIALE ========================

   TH1F exp("EXP","EXP",250, 0, 8);

   for ( int k=0; k<nmax; k++){
     exp.Fill(mygen.Exp(1)); 
   }

   TCanvas can2("EXP","EXP");
   exp.GetXaxis()->SetTitle("x [AU]");
   exp.GetYaxis()->SetTitle("N");
   exp.SetTitle("Distribuzione esponenziale");
   exp.Draw();

   //==================== GAUSS (BOX-MULLER) ========================

   TH1F gaussBM("GAUSS","GAUSS",250, -3, 5);

   for ( int k=0; k<nmax; k++){
     gaussBM.Fill(mygen.Gauss(1, 1 ));  
   }

   TCanvas can3("GAUSS","GAUSS");
   gaussBM.GetXaxis()->SetTitle("x [AU]");
   gaussBM.GetYaxis()->SetTitle("N");
   gaussBM.SetTitle("Distribuzione normale (BM)");
   gaussBM.Draw();

   //==================== GAUSS (accept-reject) ========================

   TH1F gaussAR("GAUSSar","GAUSSar",250, -3, 5);

   for ( int k=0; k<nmax; k++){
     gaussAR.Fill(mygen.GaussAR(1, 1 ));  
   }

   TCanvas can4("GAUSSar","GAUSSar");
   gaussAR.GetXaxis()->SetTitle("x [AU]");
   gaussAR.GetYaxis()->SetTitle("N");
   gaussAR.SetTitle("Distribuzione normale (AR)");
   gaussAR.Draw();

   app.Run();   

   return 0;
}