#include <QMouseEvent>
#include <QGuiApplication>

#include "NGLScene.h"
#include <ngl/NGLInit.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/ShaderLib.h>
#include <iostream>

NGLScene::NGLScene()
{
  // re-size the widget to that of the parent (in this case the GLFrame passed in on construction)
  setTitle("Particle");

}


NGLScene::~NGLScene()
{
  std::cout<<"Shutting down NGL, removing VAO's and Shaders\n";
}



void NGLScene::resizeGL(int _w , int _h)
{
  m_win.width  = static_cast<int>( _w * devicePixelRatio() );
  m_win.height = static_cast<int>( _h * devicePixelRatio() );
  m_project=ngl::perspective(45.0f,static_cast<float>(_w)/_h,0.05f,350.0f);
}

constexpr auto ColourShader="ColourShader";


void NGLScene::initializeGL()
{
  // we need to initialise the NGL lib which will load all of the OpenGL functions, this must
  // be done once we have a valid GL context but before we call any GL commands. If we dont do
  // this everything will crash
  ngl::NGLInit::instance();
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);			   // Grey Background
  // enable depth testing for drawing
  glEnable(GL_DEPTH_TEST);
  // enable multisampling for smoother drawing
  glEnable(GL_MULTISAMPLE);

  ngl::ShaderLib *shader = ngl::ShaderLib::instance();

  shader->loadShader(ColourShader,
                     "shaders/ColourVert.glsl",
                     "shaders/ColourFrag.glsl");
  shader->use(ColourShader);
  m_emitter.reset(new Emitter(ngl::Vec3::zero(),100000));

  glPointSize(8);
  startTimer(10);
  m_view=ngl::lookAt(ngl::Vec3(0,4,10),ngl::Vec3::zero(),ngl::Vec3::up());
  m_project=ngl::perspective(45.0,(float)width()/height(),0.5f,1000.0f);
  ngl::VAOPrimitives::instance()->createTrianglePlane("ground",20,20,10,10,ngl::Vec3::up());
  glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);

}

void NGLScene::timerEvent(QTimerEvent *)
{
  m_emitter->update();
  update();
}


void NGLScene::paintGL()
{
  // clear the screen and depth buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0,0,m_win.width,m_win.height);

  ngl::Mat4 rotX;
  ngl::Mat4 rotY;
  rotX.rotateX(m_win.spinXFace);
  rotY.rotateY(m_win.spinYFace);
  ngl::Mat4 mouseRotation= rotY* rotX;
  mouseRotation.m_m[3][0] = m_modelPos.m_x;
  mouseRotation.m_m[3][1] = m_modelPos.m_y;
  mouseRotation.m_m[3][2] = m_modelPos.m_z;
  ngl::Mat4 MVP=m_project*m_view*mouseRotation;
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  shader->use("ColourShader");

  shader->setUniform("MVP",MVP);
  m_emitter->draw();

  shader->use("nglColourShader");
  shader->setUniform("MVP",MVP);
  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  shader->setUniform("Colour",0.1f,0.1f,0.1f,1.0f);
  ngl::VAOPrimitives::instance()->draw("ground");
}

//----------------------------------------------------------------------------------------------------------------------

void NGLScene::keyPressEvent(QKeyEvent *_event)
{
  // this method is called every time the main window recives a key event.
  // we then switch on the key value and set the camera in the GLWindow
  switch (_event->key())
  {
  // escape key to quite
  case Qt::Key_Escape : QGuiApplication::exit(EXIT_SUCCESS); break;
  case Qt::Key_Space :
      m_win.spinXFace=0;
      m_win.spinYFace=0;
      m_modelPos.set(ngl::Vec3::zero());

  break;

  case Qt::Key_Left : m_emitter->updatePosition(-0.1f,0,0); break;
  case Qt::Key_Right: m_emitter->updatePosition(0.1f,0,0); break;
  case Qt::Key_Up : m_emitter->updatePosition(0,0.1f,0); break;
  case Qt::Key_Down: m_emitter->updatePosition(0,-0.1f,0); break;

  case Qt::Key_I : m_emitter->updatePosition(0,0,0.1f); break;
  case Qt::Key_O: m_emitter->updatePosition(0,0,-0.1f); break;



  default : break;
  }
  // finally update the GLWindow and re-draw

    update();
}
