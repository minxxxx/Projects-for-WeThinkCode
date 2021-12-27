#ifndef EMITTER_H_
#define EMITTER_H_
#include <vector>
#include <QTime>
#include <ngl/Mat4.h>
#include <ngl/Vec3.h>


#include "Particle.h"


class Emitter
{
public :

	/// @brief ctor
	/// @param _pos the position of the emitter
	/// @param _numParticles the number of particles to create
  Emitter(ngl::Vec3 _pos, std::string _texture, size_t _numParticles );
	/// @brief a method to update each of the particles contained in the system
	void update();
	/// @brief a method to draw all the particles contained in the system
  void draw(const ngl::Mat4 &_mvp);
  GLuint getTextureID() const {return m_textureID;}
  void setShaderName(const std::string &_n){m_shaderName=_n;}
  const std::string getShaderName()const {return m_shaderName;}
  void setCam(const ngl::Mat4 &_view, ngl::Mat4 &_project)
  {
    m_view=_view;
    m_project=_project;
  }
private :
	/// @brief the position of the emitter
  ngl::Vec3 m_pos;
	/// @brief the number of particles
  size_t m_numParticles;
	/// @brief the container for the particles
	std::vector <Particle> m_particles;
	/// @brief the container for the points passed to GL
  std::vector <ngl::Vec4> m_particlePositions;
	/// @brief the texture ID for the emitters point sprite
	GLuint m_textureID;
  /// @brief the name of the shader to use
  std::string m_shaderName;
  ngl::Mat4 m_view;
  ngl::Mat4 m_project;

};


#endif

