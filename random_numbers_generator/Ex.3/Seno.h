#ifndef __Seno_h__
#define __Seno_h__

#include "FunzioneBase.h"
#include <cmath>

class Seno : public FunzioneBase{
public:
  Seno(){};
  ~Seno(){};
  double Eval(double x) const {return sin(x);}
  
};

#endif