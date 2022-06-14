#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TAxis.h" 

#include <iostream>

#include "Esperimento.h"

using namespace std;

int main() {

	Esperimento myEsp {0.005};
	Esperimento myEsp1 {0.01};


	TApplication app("app",0,0);
	
  TH1F Eta("Eta","Eta", 250, 0.68, 1);
  Eta.StatOverflows( kTRUE );

	TH1F Eta1("Eta","Eta", 250, 0.68, 1);
  Eta1.StatOverflows( kTRUE );

	for(int i=0; i<1000; i++){
	  myEsp.Esegui();
	  myEsp.Analizza();

		myEsp1.Esegui();
	  myEsp1.Analizza();

		Eta.Fill(myEsp.GetEtaMis()); 
		Eta1.Fill(myEsp1.GetEtaMis()); 
	}

	TCanvas can1("Eta", "Eta");
  can1.cd();
  Eta.GetXaxis()->SetTitle("Eta [Kg/(m*s)]");
  Eta.GetYaxis()->SetTitle("N");
  Eta.SetTitle("Distribuzione risultati di Eta (R=0.005)");
  Eta.Draw();

	TCanvas can2("Eta", "Eta");
  can2.cd();
  Eta1.GetXaxis()->SetTitle("Eta [Kg/(m*s)]");
  Eta1.GetYaxis()->SetTitle("N");
  Eta1.SetTitle("Distribuzione risultati di Eta (R=0.01)");
  Eta1.Draw();

	app.Run();

	return 0;



}

//errore piu pesante?