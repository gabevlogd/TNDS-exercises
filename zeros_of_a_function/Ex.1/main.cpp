#include <iostream>
#include <cstdlib>

#include "parabola.h"

using namespace std;

int main ( int argc, char** argv ) {

	if(argc < 4) {
		cerr << "Using Program ./" << argv[0] << " <a> <b> <c> " << endl;
    exit(-1);
  }

	double a = atof(argv[1]);
  double b = atof(argv[2]);
  double c = atof(argv[3]);

	double Xv = -b/(2.*a);

	FunzioneBase *P=new Parabola(a, b, c);
	
	cout << "vertex coordinates: (" << Xv << ", " << P->Eval(Xv) << ")" << endl;

  return 0;
}
