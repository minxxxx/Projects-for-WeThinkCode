#include <QMouseEvent>
#include <QGuiApplication>

#include "NGLScene.h"
#include <ngl/Transformation.h>
#include <ngl/NGLInit.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/ShaderLib.h>

NGLScene::NGLScene()
{
  setTitle("Simple Projectiles");
  m_fps=0;
  m_frames=0;
  m_animate=true;
}


NGLScene::~NGLScene()
{
  std::cout<<"Shutting down NGL, removing VAO's and Shaders\n";
}



void NGLScene::resizeGL( int _w, int _h )
{
  m_project=ngl::perspective( 45.0f, static_cast<float>( _w ) / _h, 0.05f, 350.0f );
  m_win.width  = static_cast<int>( _w * devicePixelRatio() );
  m_win.height = static_cast<int>( _h * devicePixelRatio() );
}


void NGLScene::initializeGL()
{
  // we must call this first before any other GL commands to load and link the
  // gl commands from the lib, if this is not done program will crash
  ngl::NGLInit::instance();

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);			   // Grey Background
  // enable depth testing for drawing
  glEnable(GL_DEPTH_TEST);
  // enable multisampling for smoother drawing
  glEnable(GL_MULTISAMPLE);
  //m_cam.reset( new ngl::PathCamera(ngl::Vec4(0,1,-0.2f),"data/loop.dat",0.001f));
  m_view=ngl::lookAt(ngl::Vec3(0,1,-0.2f),ngl::Vec3(0.0f,0.0f,0.0f),ngl::Vec3::up());
  m_project=ngl::perspective(40.0,1024.0f/720.0f,0.5f,150.0);
  // now to load the shader and set the values
  // grab an instance of shader manager
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  // we are creating a shader called Phong
  shader->createShaderProgram("PointSprite");
  // now we are going to create empty shaders for Frag and Vert
  shader->attachShader("PointSpriteVertex",ngl::ShaderType::VERTEX);
  shader->attachShader("PointSpriteFragment",ngl::ShaderType::FRAGMENT);
  // attach the source
  shader->loadShaderSource("PointSpriteVertex","shaders/Vertex.vs");
  shader->loadShaderSource("PointSpriteFragment","shaders/Fragment.fs");
  // compile the shaders
  shader->compileShader("PointSpriteVertex");
  shader->compileShader("PointSpriteFragment");
  // add them to the program
  shader->attachShaderToProgram("PointSprite","PointSpriteVertex");
  shader->attachShaderToProgram("PointSprite","PointSpriteFragment");
  // now bind the shader attributes for most NGL primitives we use the following
  // layout attribute 0 is the vertex data (x,y,z)
  shader->bindAttribute("PointSprite",0,"inVert");

  // now we have associated this data we can link the shader
  shader->linkProgramObject("PointSprite");


  shader->createShaderProgram("Colour");

  shader->attachShader("ColourVertex",ngl::ShaderType::VERTEX);
  shader->attachShader("ColourFragment",ngl::ShaderType::FRAGMENT);
  shader->loadShaderSource("ColourVertex","shaders/Colour.vs");
  shader->loadShaderSource("ColourFragment","shaders/Colour.fs");

  shader->compileShader("ColourVertex");
  shader->compileShader("ColourFragment");
  shader->attachShaderToProgram("Colour","ColourVertex");
  shader->attachShaderToProgram("Colour","ColourFragment");

  shader->bindAttribute("Colour",0,"inVert");

  shader->linkProgramObject("Colour");
  (*shader)["Colour"]->use();
  // the shader will use the currently active material and light0 so set them
  shader->setUniform("Colour",0.2f,0.2f,0.2f,1.0f);
  glEnable(GL_BLEND);
  glBlendFunc(GL_ONE, GL_ONE);
  glEnable(GL_PROGRAM_POINT_SIZE);
  glEnable(GL_POINT_SPRITE);

  glPointParameterf( GL_POINT_FADE_THRESHOLD_SIZE, 32.0f );
  glPointParameteri(GL_POINT_SPRITE_COORD_ORIGIN,GL_LOWER_LEFT);
  glPointParameterf( GL_POINT_SIZE_MIN, 1.0f );
  glPointParameterf( GL_POINT_SIZE_MAX, 32.0f );


  m_emitter1.reset(  new Emitter(ngl::Vec3(0,0,0),"textures/SmokeTest.tiff",6000));
  m_emitter2.reset(  new Emitter(ngl::Vec3(2,0,2),"textures/SmokeTest2.tiff",6000));
  m_emitter3.reset(  new Emitter(ngl::Vec3(2,0,2),"textures/SmokeTest3.tiff",6000));
  m_emitter1->setCam(m_view,m_project);
  m_emitter2->setCam(m_view,m_project);
  m_emitter3->setCam(m_view,m_project);
  m_emitter1->setShaderName("PointSprite");
  m_emitter2->setShaderName("PointSprite");
  m_emitter3->setShaderName("PointSprite");
  // pre-roll the simulation to make it stable
  for(int i=0; i<500; ++i)
  {
    m_emitter1->update();
    m_emitter2->update();
    m_emitter3->update();
  }
  ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();
  prim->createLineGrid("plane",10,10,40);

  m_fpsTimer =startTimer(10);
  m_camTimer=startTimer(10);

  m_text->setScreenSize(width(),height());
  // as re-size is not explicitly called we need to do this.
  glViewport(0,0,width(),height());
  m_particleTimer=startTimer(20);

}




void NGLScene::paintGL()
{
  // grab an instance of the shader manager
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  glViewport(0,0,m_win.width,m_win.height);
  (*shader)["PointSprite"]->use();
  // clear the screen and depth buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // Rotation based on the mouse position for our global
  // transform
  ngl::Transformation trans;
  trans.setRotation(m_win.spinXFace,m_win.spinYFace,0);
  // set this in the TX stack
  ngl::Mat4 MV;
  ngl::Mat4 MVP;

  MV=m_view*trans.getMatrix() ;
  MVP=m_project*MV ;

  glBindTexture(GL_TEXTURE_2D,m_emitter1->getTextureID());
  glTexEnvf(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);

  m_emitter1->draw(MVP);

  glBindTexture(GL_TEXTURE_2D,m_emitter2->getTextureID());
  glTexEnvf(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);

  m_emitter2->draw(MVP);

  glBindTexture(GL_TEXTURE_2D,m_emitter3->getTextureID());
  glTexEnvf(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);

  m_emitter3->draw(MVP);


  (*shader)["Colour"]->use();
  shader->setUniform("MVP",MVP);

  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();
  prim->draw("plane");

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

  default : break;
  }
    update();
}

void NGLScene::timerEvent(QTimerEvent *_event )
{
	if( m_animate == true)
	{
		m_emitter1->update();
		m_emitter2->update();
		m_emitter3->update();

	}
	if(_event->timerId() == m_camTimer)
	{
	}
	update();
		// re-draw GL
}
