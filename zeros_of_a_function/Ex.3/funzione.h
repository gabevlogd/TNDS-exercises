#ifndef __Funzione__
#define __Funzione__

#include "funzioneBase.h"

class xTanx : public FunzioneBase {

public:

  xTanx() {;}
  ~xTanx() {;}

  virtual double Eval (double x) const override {return sin(x)-x*cos(x);}


};

#endif // __Funzione__