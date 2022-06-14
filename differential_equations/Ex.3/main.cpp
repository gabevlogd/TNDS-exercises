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

	RungeKutta myRK;
	Pendolo pend{1., 9.81};

	double tmax = 70.0;
  double h = atof(argv[1]);
  double A = 0.;   //ampiezza oscillazione
  double t = 0.0;
  double v = 0.0;  //velocità al passo precedente (x_n-1)
  double T = 0.0;  //periodo
  double i = 0;    //variabile di appoggio per il ciclo while

	TApplication app("app",0,0);

  //======================== ROOT ==========================
  
  TCanvas Canvas_1 ("plot","plot");
  TGraph myGraph;
  string title = "Peridodo di oscillazione";
  myGraph.GetXaxis()->SetTitle("Ampiezza [rad]");
  myGraph.GetYaxis()->SetTitle("Periodo [s]");
  myGraph.SetTitle(title.c_str());

	while (A<=3){
	  A+=0.1;
	  t=0;
	  vector<double> x{-A, 0.0};

	  while(x[1]>=0){
		  v = x[1]; //velocità precedente
		  x = myRK.Passo(t, x, h, pend);
		  t += h;
	  }
	  T = 2 * ( t - x[1] * h/(x[1]-v) );
	  myGraph.SetPoint(i, A, T);
	  i++;  
  }

	myGraph.Draw("A*L");



	app.Run();

  return 0;
}