#ifndef __bisezione__
#define __bisezione__

#include <float.h> // Serve per includere DBL_MAX
#include <iostream>

#include "solutore.h"

using namespace std;

class Bisezione : public Solutore {

public:

  Bisezione (){};
  ~Bisezione () {};

	
  double CercaZeri (double a, double b, const FunzioneBase* f, double) override;

  double CercaZeri (double a, double b, const FunzioneBase& f, double) override;

	int sign(double x){
 		if(x<0)
    return -1;
  	else
    return 1;
	}

};

#endif // __bisezione__
