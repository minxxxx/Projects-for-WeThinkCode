#include "Emitter.h"
#include <ngl/NGLInit.h>
#include <iostream>
#include <ngl/Random.h>
#include <ngl/VAOFactory.h>


static std::default_random_engine s_generator;

Emitter::Emitter(ngl::Vec3 _pos, size_t  nParticles)
{
  m_pos=_pos;
  m_particles.resize(nParticles);

  for(auto &p : m_particles)
  {
    resetParticle(p);
  }
  m_vao=ngl::VAOFactory::createVAO(ngl::simpleVAO,GL_POINTS);

}

void Emitter::resetParticle(Particle &io_p)
{
  std::bernoulli_distribution distribution(0.5);

  ngl::Random *rng=ngl::Random::instance();
  io_p.respawn=distribution(s_generator);
  io_p.pos=m_pos;
  io_p.life=5;

  if(io_p.respawn==true)
  {
    io_p.dir.m_x=rng->randomNumber(1);
    io_p.dir.m_y=rng->randomPositiveNumber(0.2f);
    io_p.dir.m_z=rng->randomNumber(1);

    io_p.colour.m_r=rng->randomPositiveNumber(1.0f);
    io_p.colour.m_g=rng->randomPositiveNumber(1.0f);
    io_p.colour.m_b=rng->randomPositiveNumber(1.0f);
    io_p.maxLife=static_cast<int>(80+rng->randomPositiveNumber(100.0f));
  }
}


void Emitter::draw()
{
  m_vao->bind();
  struct part
  {
    ngl::Vec3 p;
    ngl::Vec3 c;
    ngl::Real size;
  };


  std::vector<part> particle(m_particles.size());
  for(size_t i=0; i<m_particles.size(); ++i )
  {
    particle[i].p=m_particles[i].pos;
    particle[i].c=m_particles[i].colour;
    particle[i].size=m_particles[i].life;
  }

  m_vao->setData(ngl::SimpleVAO::VertexData(particle.size()*sizeof (part),
                                            particle[0].p.m_x));

  m_vao->setVertexAttributePointer(0,3,GL_FLOAT,(GLsizei)sizeof(part),0);
  m_vao->setVertexAttributePointer(1,3,GL_FLOAT,(GLsizei)sizeof(part),3);
  m_vao->setVertexAttributePointer(2,1,GL_FLOAT,(GLsizei)sizeof(part),6);
  m_vao->setNumIndices(particle.size());
  m_vao->draw();
  m_vao->unbind();
}
void Emitter::update()
{
  for(auto &p : m_particles)
  {
    p.pos+=p.dir;
    if(++p.life > p.maxLife)
    {
        resetParticle(p);
    }

  }

}

void Emitter::updatePosition(ngl::Real _dx, ngl::Real _dy, ngl::Real _dz)
{
  m_pos.m_x+=_dx;
  m_pos.m_y+=_dy;
  m_pos.m_z+=_dz;
}










