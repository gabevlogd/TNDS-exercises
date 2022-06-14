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

	Eulero myEuler;
	OscillatoreArmonico osc{1.};

	double tmax = 70.0;
  double h    = atof(argv[1]);
  vector<double> x {0.0, 1.0};
  double t = 0.0;

	int Nstep = int(tmax/h+0.5);

	TApplication app("app",0,0);

  //======================== GRAFICO POSIZIONE ==========================
  
  TCanvas Canvas_1 ("plot","plot");
  TGraph moto;
  string title = "Oscillatore armonico (passo = " + std::to_string(h) + ")";
  moto.GetXaxis()->SetTitle("tempo [s]");
  moto.GetYaxis()->SetTitle("posizione [m]");
  moto.SetTitle(title.c_str());

	for (int step=0; step<Nstep; step++){
		moto.SetPoint(step, t, x[0]);
		x = myEuler.Passo(t,x,h,osc);
		t+=h;
	}

	moto.Draw("AL");

	//======================== GRAFICO ERRORE ==========================

	TCanvas Canvas_2 ("plot", "plot");
	Canvas_2.SetLogy();
	Canvas_2.SetLogx();

  TGraph Error;
	string title_2 = "Andamento dell'errore";
  Error.GetXaxis()->SetTitle("Passo [s]");
  Error.GetYaxis()->SetTitle("Errore a t=70 s");
  Error.SetTitle(title_2.c_str());

  for (int i=0; i<10; i++){
	  h = 0.1*pow(0.5, i);
	  Nstep = tmax/h+0.5; 
 	  x = {0.0, 1.0};
  	t = 0.0;

	  for (int step = 0; step < Nstep; step++){	
   		x = myEuler.Passo(t,x,h,osc);
    	t = t+h; 
		}

	  double eps = fabs(x[0]-sin(t));
	  Error.SetPoint(i,h,eps);
  }

  Error.Draw("A*L");

	app.Run();

  return 0;
}
