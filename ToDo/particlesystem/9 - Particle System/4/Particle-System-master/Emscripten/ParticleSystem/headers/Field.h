#pragma once
#include "BaseObject.h"
#include "Particle.h"

class Field: public BaseObject {

public:

  ///////////////////////////////////////////////////////////////////
  //
  //
  ///////////////////////////////////////////////////////////////////
  Field(int id, int type);

  ///////////////////////////////////////////////////////////////////
  //
  //
  ///////////////////////////////////////////////////////////////////
  virtual void applyForce (Particle* pParticle);
};
