#version 410

layout (location=0) in vec3 inPos;
layout (location=1) in vec3 inColour;
layout (location=2) in float inSize;

uniform mat4 MVP;
out vec3 colour;
void main()
{
  gl_PointSize=2+inSize/10;
  colour=inColour;
  gl_Position = MVP*vec4(inPos,1.0);
}
