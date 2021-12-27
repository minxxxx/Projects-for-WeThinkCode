#include "Particle.h"
#include <ngl/Random.h>
#include <ngl/Transformation.h>
#include <ngl/ShaderLib.h>
#include <ngl/VAOPrimitives.h>
#include "Emitter.h"
/// @brief ctor
/// @param _pos the start position of the particle
Particle::Particle(ngl::Vec3 _pos, ngl::Vec3 *_wind,  Emitter *_emitter   )
{
	m_pos=_pos;
	m_origin=_pos;
	m_wind=_wind;
  ngl::Random *rand=ngl::Random::instance();
  m_dir.m_x=rand->randomNumber(5)+0.5f;
  m_dir.m_y=rand->randomPositiveNumber(10.0f)+0.5f;
  m_dir.m_z=rand->randomNumber(5)+0.5f;
  m_currentLife=0.0f;
  m_gravity=-9.0f;//4.65;
  m_emitter=_emitter;

}
/// @brief a method to update the particle position
void Particle::update()
{

	m_currentLife+=0.05;
	// use projectile motion equation to calculate the new position
	// x(t)=Ix+Vxt
	// y(t)=Iy+Vxt-1/2gt^2
	// z(t)=Iz+Vzt
	m_pos.m_x=m_origin.m_x+(m_wind->m_x*m_dir.m_x*m_currentLife);
	m_pos.m_y= m_origin.m_y+(m_wind->m_y*m_dir.m_y*m_currentLife)+m_gravity*(m_currentLife*m_currentLife);
	m_pos.m_z=m_origin.m_z+(m_wind->m_z*m_dir.m_z*m_currentLife);

	// if we go below the origin re-set
  if(m_pos.m_y <= m_origin.m_y-0.01f)
	{
		m_pos=m_origin;
		m_currentLife=0.0;
		ngl::Random *rand=ngl::Random::instance();
    m_dir.m_x=rand->randomNumber(5)+0.5f;
    m_dir.m_y=rand->randomPositiveNumber(10)+0.5f;
    m_dir.m_z=rand->randomNumber(5)+0.5f;

	}
}
/// @brief a method to draw the particle
void Particle::draw(const ngl::Mat4 &_view, const ngl::Mat4 &_project)
{
  // get the VBO instance and draw the built in teapot
  ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();
  ngl::Transformation transform;
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  shader->use("Phong");
  transform.setPosition(m_pos);
  ngl::Mat4 MV;
  ngl::Mat4 MVP;
  ngl::Mat3 normalMatrix;
  ngl::Mat4 M;
  M=transform.getMatrix();
  MV=_view*transform.getMatrix();

  MVP=_project *MV;
  normalMatrix=MV;
  normalMatrix.inverse().transpose();
  shader->setUniform("MV",MV);
  shader->setUniform("MVP",MVP);
  shader->setUniform("normalMatrix",normalMatrix);
  shader->setUniform("M",M);
  prim->draw("sphere");

}
