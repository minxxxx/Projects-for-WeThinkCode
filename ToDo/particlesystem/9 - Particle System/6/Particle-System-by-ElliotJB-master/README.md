# Particle System

## INTRODUCTION

## Particle:
In the physical sciences, a particle is a small localized object to which can be ascribed several physical or chemical properties such as volume or mass.
A particle can be a smoke, a spark, a drop of water, etc. Especially to give visual effects.

![](https://raw.githubusercontent.com/elliotjb/Particle-System-by-ElliotJB/master/docs/particle_example.jpg)


Particles are graphical primitives such as points, lines, your imagination:

![](https://raw.githubusercontent.com/elliotjb/Particle-System-by-ElliotJB/master/docs/Particle_line.jpg)
![](https://raw.githubusercontent.com/elliotjb/Particle-System-by-ElliotJB/master/docs/Particle_point.jpg)

## Particle System
Particle systems are one such technique. By creating a small physics system that throws around hundreds – even thousands – of tiny little particles, awesome visual effects like smoke, fire, sparks, rocket exhaust and many more can be created. They are simple to create and really add nice visual effects to your game. 

![](https://raw.githubusercontent.com/elliotjb/Particle-System-by-ElliotJB/master/docs/gdm0798.jpg)

A Particle system in a graphic engine, Unity:

![](https://raw.githubusercontent.com/elliotjb/Particle-System-by-ElliotJB/master/docs/maxresdefault.jpg)

## Atributes of Particle
To create a Particle System, it is necessary to set a series of attributes that will have each particle:

### Position:
 - It is the position from where you are respawn, you can play with this value and establish an area from the center of the point and make it exit from a random place.
 - Example:
 
 ![](https://media.giphy.com/media/fmTp0H3B7ElR6/giphy.gif)
 
 *Image taken with my particle system.*
 
 
### Speed:
 - The speed at which it will come out, here you can apply a force, for example: gravity or wind. This can increase realism.
 - Example Speed:
 
  ![](https://media.giphy.com/media/muKgnCvN7srmg/giphy.gif)
  
  *Image taken with my particle system.*


 - Example Gravity:
 
  ![](https://media.giphy.com/media/eb9wp9JrbweE8/giphy.gif)
  
  *Image taken with my particle system.*

  
  
### Color:
 - Each particle has to have a color. For greater realism, it is better to have a variety of shades of the same color.
 - Example:
 
 ![](https://media.giphy.com/media/9iZPq8W1drGVO/giphy.gif)
 
 *Image taken with my particle system.*

  
### Life Time:
 - It is the life time of the particle. If you play with time so that each particle has a different one, you can get more relist effects.
 - Example:
 
 ![](https://media.giphy.com/media/3cNZJEBYJEHx6/giphy.gif)
 
 *Image taken with my particle system.*

 
### Age:
 - To understand it better, if you have a particle that has 4 phases, childhood, young, adult and old. Each phase has a different color, with this you can play and tell you that some particles start in childhood and others in the following phases, so you get a greater realism.
 - I haven't used this attribute.
 
 
### Shape:
 - In my case I use squares but in other cases they can be lines, mini-balls, etc.
 - Example:

 ![]( https://media.giphy.com/media/umMc0SQMI4rwQ/giphy.gif)
 
 
 
#### Size:
 - You can play with the size of the particles, if you use a small size you can achieve higher quality in some cases.
 - Example:

 ![](https://media.giphy.com/media/BwZpj7IQdlH4Q/giphy.gif)



#### Transparency:
 - Transparency is important to bring realism to the particles. If you do not use it the player sees something strange.
 - Example **Without Transparency**:
 
 ![](https://media.giphy.com/media/c7Y12WoD7g7Ze/giphy.gif) 
 
 *Image taken with my particle system.*

 
  - Example **With Transparency**:
  
 ![](https://media.giphy.com/media/BubacVhtlbr20/giphy.gif) 
 
 *Image taken with my particle system.*


## Age Of Empires 2
- Example:

<https://media.giphy.com/media/HJVsC0wynlEo8/giphy.gif>


## CODE

 ![](https://raw.githubusercontent.com/elliotjb/Particle-System-by-ElliotJB/master/docs/Code_3_2.PNG) 
 ![](https://raw.githubusercontent.com/elliotjb/Particle-System-by-ElliotJB/master/docs/exp.png) 




## TODOS
We will create some particles that follow the player "Link" and the mouse, to do this follow the next TODOs:

### TODO 1
Set degrade.y -> time of life
First we need to know if the particle is active. 
If it is, we set the maximum life it can have (#define), and if it is not, we put it to death " = 0".

- Solution -> <https://github.com/elliotjb/Particle-System-by-ElliotJB/blob/master/Motor2D/Particle.cpp#L18>
- Solution -> <https://github.com/elliotjb/Particle-System-by-ElliotJB/blob/master/Motor2D/Particle.cpp#L63>

**When you finish run the program and try to put explosions and fireworks.**

 ![](https://s-media-cache-ak0.pinimg.com/originals/2b/cc/0e/2bcc0e11960ebe99ec2c4d402328a970.gif) 

### TODO 2
Create a Particle Vector, use std::vector
Also, create a pointer to an entity (SceneElement*)
And finally a pointer to an iPoint (iPoint*)

- Solution -> <https://github.com/elliotjb/Particle-System-by-ElliotJB/blob/master/Motor2D/P_Follow.h#L28>

 ![](https://s-media-cache-ak0.pinimg.com/originals/2b/cc/0e/2bcc0e11960ebe99ec2c4d402328a970.gif) 

### TODO 3
Check if entity (element) is different from nullptr
Then set the position of the entity and the pointer iPoint (object) to nullptr and entity pointer has created in .h
//---------------------------
Otherwise, do it backwards. //element == nullptr and position = object

- Solution -> <https://github.com/elliotjb/Particle-System-by-ElliotJB/blob/master/Motor2D/P_Follow.cpp#L8>

 ![](https://s-media-cache-ak0.pinimg.com/originals/2b/cc/0e/2bcc0e11960ebe99ec2c4d402328a970.gif) 

### TODO 4
In this TODO we need open Particle.h and see the constructor
Create a new Particle and pushback in vector.
TIPS: Speed = fPoint(0,0) // P_Direction = P_NON

- Solution -> <https://github.com/elliotjb/Particle-System-by-ElliotJB/blob/master/Motor2D/P_Follow.cpp#L37>
 
  ![](https://s-media-cache-ak0.pinimg.com/originals/2b/cc/0e/2bcc0e11960ebe99ec2c4d402328a970.gif) 
 
### TODO 5
Here we have to Update the position.
Check if the entity is diferent nullptr and set position. On the contrary, use Update_position(iPoint* pos);

- Solution -> <https://github.com/elliotjb/Particle-System-by-ElliotJB/blob/master/Motor2D/P_Follow.cpp#L53>

 ![](https://s-media-cache-ak0.pinimg.com/originals/2b/cc/0e/2bcc0e11960ebe99ec2c4d402328a970.gif) 
 
### TODO 6
Iterate the filled vector, First Comprovated if the particle is Dead, and then use particle[i]->Modify();
TIPS: Use number_particles!! // iPoint num_tex -> (0, n_textures)!

- Solution -> <https://github.com/elliotjb/Particle-System-by-ElliotJB/blob/master/Motor2D/P_Follow.cpp#L80>

 ![](https://s-media-cache-ak0.pinimg.com/originals/2b/cc/0e/2bcc0e11960ebe99ec2c4d402328a970.gif) 

### TODO 7
Draw particles
Iterate the filled vector, Call the functioon render();

- Solution -> <https://github.com/elliotjb/Particle-System-by-ElliotJB/blob/master/Motor2D/P_Follow.cpp#L93>

 ![](https://s-media-cache-ak0.pinimg.com/originals/2b/cc/0e/2bcc0e11960ebe99ec2c4d402328a970.gif)  

### TODO 8 
Uncomment

- Solution -> <https://github.com/elliotjb/Particle-System-by-ElliotJB/blob/master/Motor2D/ParticleManager.cpp#L33>


## Content
In this project you can see 4 diferents methods of Particle system:
 - Follow
 - Fire
 - Explosion
 - Firework


## Controls

- With Arrows you can move "Link"
- "F"-> Put a fire in mouse position.
- "SPACE" -> Firework in mouse position.
- Cick-Left -> Explision CROSS.
- Cick-Center -> Explision CIRCLE.
- Cick-Right -> Explision RANDOM.


## Author
Name: Elliot Jimenez Bosch
Email: elliot.jimenez1@gmail.com
GitHub: <https://github.com/elliotjb>











