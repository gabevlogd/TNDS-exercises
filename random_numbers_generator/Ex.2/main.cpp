#include <iostream>
#include <vector>
#include "RandomGen.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h" 

using namespace std;

int main ( int argc, char** argv ) {

	if(argc < 3) {
		cerr << "Using Program " << argv[0] << " <N-entries> <N-somme> " << endl;
    exit(-1);
  }

	TApplication app("app",0,0);

	unsigned int N = atoi(argv[1]);
	unsigned int N_somme = atoi(argv[2]);
	unsigned int j = 0; //varivabile di appoggio nel ciclo-for a riga 49

	RandomGen mygen(1);

	vector<double> Entries;
	for (int i=0; i<N; i++) Entries.push_back(mygen.Rand()); 



	//================ Istogramma distribuzione degli N numeri generati: =======================


	TH1F unif("Uniforme","Uniforme",250,0,1);
  for ( int k=0; k<N; k++) unif.Fill(Entries[k]);
  TCanvas can1("Uniforme","Uniforme");
  unif.GetXaxis()->SetTitle("x [AU]");
  unif.GetYaxis()->SetTitle("N");
  unif.SetTitle("Distribuzione uniforme");
  unif.Draw();
	


	//================= Istogramma distribuzione delle somme: ===========================


	TH1F somme("Sum","Sum",250,0,N_somme);

	for ( int k=0; k<int(N/N_somme); k++ ){
		double somma=0;
		for (int i=0; i<N_somme; i++) {
			somma+=Entries[j];
			j++; 
		}
		somme.Fill(somma);
	}

	TCanvas can2("Somme","Somme");
  somme.GetXaxis()->SetTitle("somme");
  somme.GetYaxis()->SetTitle("N");
  somme.SetTitle("Distribuzione delle somme");
  somme.Draw();

	app.Run();   

  return 0;


}
