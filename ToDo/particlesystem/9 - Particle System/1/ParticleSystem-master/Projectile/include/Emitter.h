#ifndef EMITTER_H_
#define EMITTER_H_
#include <vector>
#include <ngl/Vec3.h>
#include <ngl/Mat4.h>
#include "Particle.h"


class Emitter
{
public :

	/// @brief ctor
	/// @param _pos the position of the emitter
	/// @param _numParticles the number of particles to create
	Emitter( ngl::Vec3 _pos, int _numParticles, ngl::Vec3 *_wind );
	/// @brief a method to update each of the particles contained in the system
	void update();
	/// @brief a method to draw all the particles contained in the system
  void draw(const ngl::Mat4 &_view, const ngl::Mat4 &_project);

private :
	/// @brief the position of the emitter
	ngl::Vec3 m_pos;
	/// @brief the number of particles
	int m_numParticles;
	/// @brief the container for the particles
	std::vector <Particle> m_particles;
	/// @brief a wind vector
	ngl::Vec3 *m_wind;
  /// @brief the name of the shader to use
  std::string m_shaderName;
  /// @brief a pointer to the camera used for drawing

};


#endif

