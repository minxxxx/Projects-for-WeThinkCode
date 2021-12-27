#version 410 core

layout(location=0) out vec4 fragColour;


in vec3 colour;

void main()
{
  vec2 coord = gl_PointCoord - vec2(0.5);  //from [0,1] to [-0.5,0.5]
  if(length(coord) > 0.5)                  //outside of circle radius?
      discard;
  fragColour.rgb=colour;
}
