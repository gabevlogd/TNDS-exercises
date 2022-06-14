#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TGraph.h"
#include "TAxis.h"  

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#include "IntegralMC.h"
#include "Seno.h"

using namespace std;


int main ( int argc, char** argv ) {

	if (argc != 2){
		cout << "using program: " << argv[0] << " [integration method]" << endl;
		cout << "integration method: 0=Hit or Miss , 1=Average" << endl;
		exit(-1);
	}
	else if (atoi(argv[1]) != 0 && atoi(argv[1]) != 1){
		cout << "invalid entry" << endl;
		exit(-1);
	}

	int integrations_method = atoi(argv[1]);


	TApplication app("app",0,0);

	IntegralMC myinteg(1);
	Seno mysin;
	vector<TH1F*> Isto(5);
	vector<TCanvas*> Canvas(6);
	vector<int> N = {100, 500, 1000, 5000, 10000};

	//===================== ISTOGRAMMI INTEGRALI ======================

	for(int i=0; i<5; i++){

		Isto[i] = new TH1F("integrale","integrale"+i,250,1.4,2.6);
		Isto[i]->StatOverflows( kTRUE );

		if(integrations_method == 1){
			for ( int k=0; k<10000; k++){
				Isto[i]->Fill(myinteg.IntegralAVE(0, M_PI, N[i], mysin));
			}
		}
		else {
			for ( int k=0; k<10000; k++){
				Isto[i]->Fill(myinteg.IntegralHoM(0, M_PI, N[i], 1, mysin));
			}
		}

		Canvas[i] = new TCanvas("i"+i,"plot");
		Canvas[i]->cd();
		Isto[i]->GetXaxis()->SetTitle("I");
		Isto[i]->GetYaxis()->SetTitle("N");
		string title = "Distribuzione risultati integrale (N=" + to_string(N[i]) + ")";
		Isto[i]->SetTitle(title.c_str());
		Isto[i]->Draw();
	}

	//======================== ANDAMENTO ERRORE ==========================

	TGraph* errors = new TGraph(5);
	for(int i=0; i<5; i++){
		errors->SetPoint(i, N[i], Isto[i]->GetStdDev(1));
	}
	Canvas[6] = new TCanvas("Errori","Errori");
   Canvas[6]->cd();
   errors->GetXaxis()->SetTitle("N");
   errors->GetYaxis()->SetTitle("Dev.Std.");
   errors->SetTitle("Andamento dell'errore");
   errors->Draw("A*L");

	 //========================= N stimato con sigma=0.001 ========================

	 double k = 0;
	 for (int i=0; i<5; i++){
		 k += Isto[i]->GetStdDev(1)*sqrt(N[i]);
	 }
	 k = k/5.; // stimo k facendo una media dei k calcolati per ogni N usato precedentemente
	 cout << "N minimo per ottenre una precisione di 0.001: N = ";
   cout << pow(k/0.001, 2) << std::endl;

	app.Run();


  return 0;
}
