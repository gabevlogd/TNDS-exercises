#include <iostream>
#include <vector>
#include <cmath>
#include <string>

#include "TApplication.h"
#include "TCanvas.h" 
#include "TGraph.h"
#include "TAxis.h"

#include "EquazioniDifferenziali.h"

using namespace std;



int main ( int argc, char** argv ) {

	if(argc != 2) {
		std::cout << "Using Program " << argv[0] << " [StepSize] " << std::endl;
		exit(-1);
  }

	vector<double> x {0.0, 0.0};
	double t = 0.0;
	double T = 0; //tempo di inversione del moto

	double omega0 = 10.;
  double alpha = 1./30.;
	
	double h = atof(argv[1]);
  double tmax = 30;
	int nstep = tmax/h+0.5;
	double V = 0.0;  //velocita al passo precedente 
	double P = 0.0;  //posizione al passo precedente 
	double f = 9.;  //forzante oscillatore 
	bool s=0;  //segno velocita
	int i=0;  //indice del SetPoint

  RungeKutta myRK;
	OscillatoreForzato osc{omega0, alpha, f};

	TApplication app("app",0,0);

  //======================== ROOT ==========================

	//MOTO:

	TCanvas Canvas_2 ("plot","plot");
  TGraph moto;
  string title1 = "Oscillatore forzato (passo = " + std::to_string(h) + ")";
  moto.GetXaxis()->SetTitle("tempo [s]");
  moto.GetYaxis()->SetTitle("posizione [m]");
  moto.SetTitle(title1.c_str());

	for (int step=0; step<nstep; step++){
		moto.SetPoint(step, t, x[0]);
		x = myRK.Passo(t,x,h,osc);
		t+=h;
	}

	moto.Draw("AL");


	//CURVA DI RISONANZA:

	t = 0;
	x = {0., 0.};
	tmax = 10./alpha;
	nstep = tmax/h+0.5;
  
  TCanvas Canvas_1 ("plot","plot");
  TGraph myGraph;
  string title = "curva di risonanza";
  myGraph.GetXaxis()->SetTitle("Pulsazione [rad/s]");
  myGraph.GetYaxis()->SetTitle("Ampiezza [m]");
  myGraph.SetTitle(title.c_str());

	while (f<=11.){

		//condizioni iniziali:
		x[0]=0;
		x[1]=0;
		t = 0.0;

		//evolvo il sistema fino a tmax per stabilizzare il transiente
		for (int step=0; step<nstep; step++){
			x = myRK.Passo(t,x,h,osc);
			t+=h;
		}
		
		//controllo il segno della velocità ed evolvo il sistema finche non cambia segno
	  s = segno(x[1]);
	  while (segno(x[1])==s){
			V=x[1];
			P=x[0];
			x = myRK.Passo(t,x,h,osc);
    	t += h;
		}

		T =  ( t - x[1] * h/(x[1]-V) ); //tempo T per cui la velocità è nulla e l'ampiezza è massima

		//riporto il sistema all'istante precedente per evolverlo di un passo h tale che 
		//cada esattamente al tempo T (questo passo è la differenza tra T e un generico t<T : h=Τ-t)
		x[0]=P;
		x[1]=V;
		t-=h;
		x = myRK.Passo(t,x,T-t,osc);
		
		//inserisco nel grafico la forzante e l'ampezza massima di osillazione 
		myGraph.SetPoint(i, f, fabs(x[0]));
		i++;
		f+=0.05;
		osc.SetF(f);
	}

	myGraph.Draw("A*L");



	app.Run();

  return 0;
}
