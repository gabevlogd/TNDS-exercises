#include "CampoVettoriale.h"
#include "PuntoMateriale.h"
#include "TApplication.h"  //mantengo aperto root per visualizzrae output grafici
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TF1.h"

#include <iostream>
#include <cstdlib>

using namespace std;

int main (int argc, char** argv) { 

  if(argc < 4) {
        cerr << "Using Program ./" << argv[0] << " <x> <y> <z> " << endl;
        exit(-1);
  }

  double x = atof(argv[1]);// caricate il valore da argv[1]
  double y = atof(argv[2]);// caricate il valore da argv[2]
  double z = atof(argv[3]);// caricate il valore da argv[3]

  Posizione r(x,y,z);

  const double e  = 1.60217653E-19;
  const double me = 9.1093826E-31;
  const double mp = 1.67262171E-27;
  const double d  = 1.E-10;

  PuntoMateriale elettrone (me, -e, 0., 0., d/2.);
  PuntoMateriale protone (me, e, 0., 0., -d/2.);

	// sommate nella Posizione r il contributo del CampoElettrico di elettrone e protone
  CampoVettoriale E = elettrone.CampoElettrico(r)+protone.CampoElettrico(r);

  // Stampate su termianle le tre componenti del CampoVettoriale risultante nella Posizione r
	cout << "Ex = " << E.getFx() << ", Ey = " << E.getFy() << ", Ez = " << E.getFz() << endl;

	//======================================ROOT================================================

	TApplication app("app",0,0);
	TCanvas mycanvas ("Plot1","Plot1");
	TGraph AndamentoCampo;
	AndamentoCampo.GetXaxis()->SetTitle("posizione");
  AndamentoCampo.GetYaxis()->SetTitle("modulo del campo");
  AndamentoCampo.SetTitle("andamento del campo elettrico lungo l'asse di un dipolo");

	Posizione P;
	for (int i=100,j=0; i<=1000; i++,j++){
		P.setX(i*d);
		E=elettrone.CampoElettrico(P)+protone.CampoElettrico(P);
		AndamentoCampo.SetPoint(j, P.getX(),E.Modulo());
	}

	//==================================ANDAMENTO CAMPO=======================================

	//partendo dall'ultima posizione usata nel ciclo for qui sopra creo una nuova posizione variata sull'asse del dipolo:
	Posizione P1(d*1001, P.getY(), P.getZ());
	//calcolo il campo in questa nuova posizione P1:
	CampoVettoriale E1 = elettrone.CampoElettrico(P1)+protone.CampoElettrico(P1);
	//calcolo alpha ( E=kR^(alpha) ) con la legge di potenza:
	double alpha=log(E.Modulo()/E1.Modulo())/log(P.getR()/P1.getR());
	cout << "il campo ha un andamento: R^" << alpha << endl;

	//eseguo un fit (k*x^alpha)
	TF1 *f1 = new TF1("f1","[0]*x^[1]",0.,10.);
	f1->SetParameter(0,1.E-19);     
	f1->SetParameter(1,alpha);     
	AndamentoCampo.Fit(f1, "w","",0.,1000.);

	//DISEGNO IL GRAFICO
	AndamentoCampo.Draw("AL");
  app.Run();

	

  return 0;
}