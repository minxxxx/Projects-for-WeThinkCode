# **OpenGL/OpenCL Particle System**

![particles](https://cloud.githubusercontent.com/assets/8960984/11858124/db8c0b54-a41b-11e5-8870-a7a47dae63e2.gif)

This project simulates a particle system using a combined OpenGL and OpenCL processing pipeline. Each time the rendering device idles, but before an image is drawn to screen, OpenCL acquires the respective buffer objects, accesses and/or modifies the contents, and reinserts the buffers back into the OpenGL rendering pipeline.

The particles only interact with two bumper objects. In this implementation, the particles must stay within a bounding sphere and outside of a smaller sphere. Anytime a particle passes beyond the allowed boundaries, it reflects off the bumper object.

Particles are colored according to their speeds. Red encodes for the fastest particles and blue signifies
motionless particles. Speeds in between are calculated by interpolating hues.