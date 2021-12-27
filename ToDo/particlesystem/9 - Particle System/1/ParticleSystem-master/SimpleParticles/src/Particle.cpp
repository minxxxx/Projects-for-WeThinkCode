#include "Particle.h"
#include <ngl/Random.h>
#include <ngl/ShaderLib.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/Transformation.h>
#include "Emitter.h"
/// @brief ctor
/// @param _pos the start position of the particle
Particle::Particle(ngl::Vec3 _pos, Emitter *_emitter  )
{
	m_pos=_pos;
	m_origin=_pos;
  ngl::Random *rand=ngl::Random::instance();
  m_dir=rand->getRandomNormalizedVec3();
  m_colour=rand->getRandomColour4();
  m_lifetime=rand->randomPositiveNumber(200.0f);
	m_currentLife=0;
  m_emitter = _emitter;
}
/// @brief a method to update the particle position
void Particle::update()
{
	m_pos+=m_dir;
	++m_currentLife;
	if(m_currentLife > m_lifetime)
	{
		m_pos=m_origin;
		m_currentLife=0;
		ngl::Random *rand=ngl::Random::instance();
    m_dir=rand->getRandomNormalizedVec3();
		m_lifetime=rand->randomPositiveNumber(200);

	}
}
/// @brief a method to draw the particle
void Particle::draw(const ngl::Mat4 &_view, const ngl::Mat4 &_project) const
{
  // get the VBO instance and draw the built in teapot
  ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();
  ngl::Transformation trans;
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  shader->use("Phong");
  trans.setPosition(m_pos);

  ngl::Mat4 MV;
  ngl::Mat4 MVP;
  ngl::Mat3 normalMatrix;
  ngl::Mat4 M;
  M=trans.getMatrix();
  MV=_view*M;
  MVP=_project*MV;
  normalMatrix=MV;
  normalMatrix.inverse().transpose();
  shader->setUniform("MV",MV);
  shader->setUniform("MVP",MVP);
  shader->setUniform("normalMatrix",normalMatrix);
  shader->setUniform("M",M);

  prim->draw("sphere");

}
