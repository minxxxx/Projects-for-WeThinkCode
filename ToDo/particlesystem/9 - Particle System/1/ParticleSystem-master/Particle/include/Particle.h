#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <ngl/Vec3.h>

struct Particle
{
  ngl::Vec3 pos;
  ngl::Vec3 dir;
  ngl::Vec3 colour;
  int life=0;
  int maxLife;
  bool respawn=false;
};


#endif
