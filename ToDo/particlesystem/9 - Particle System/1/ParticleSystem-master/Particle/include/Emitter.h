#ifndef EMITTER_H_
#define EMITTER_H_
#include <ngl/Vec3.h>
#include <vector>
#include <ngl/SimpleVAO.h>
#include <memory>
#include "Particle.h"
class Emitter
{
  public :
    Emitter(ngl::Vec3 _pos, size_t nParticles);
    void draw();
    void update();
    void updatePosition(ngl::Real _dx, ngl::Real _dy, ngl::Real _dz);
  private :

    void resetParticle(Particle &io_p);

    std::vector<Particle> m_particles;
    ngl::Vec3 m_pos;
    std::unique_ptr<ngl::AbstractVAO> m_vao;
};


#endif
