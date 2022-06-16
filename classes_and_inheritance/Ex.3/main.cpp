#include "CampoVettoriale.h"
#include "PuntoMateriale.h"

#include <iostream>
#include <cstdlib>

using namespace std;

int main (int argc, char** argv) { // esempio di main.cpp per verificare la funzionalità delle classi CampoVettoriale & PuntoMateriale

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

  // somma nella Posizione r il contributo del CampoElettrico di elettrone e protone
  CampoVettoriale E = elettrone.CampoElettrico(r)+protone.CampoElettrico(r);

  // Stamp su termianle le tre componenti del CampoVettoriale risultante nella Posizione r
  cout << "Ex = " << E.getFx() << ", Ey = " << E.getFy() << ", Ez = " << E.getFz() << endl;

  return 0;
}
