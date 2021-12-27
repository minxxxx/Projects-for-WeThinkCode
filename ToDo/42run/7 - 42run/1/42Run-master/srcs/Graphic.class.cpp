#include <Graphic.class.hpp>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <TimeManager.class.hpp>

Graphic & Graphic::instance(void) {
    static Graphic inst;
    return inst;
}

Graphic::~Graphic(void) {
    return ;
}

Graphic::Graphic(void) {

    if ( !glfwInit() )
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        std::exit(-1);
    }

    //AA
    //glfwWindowHint(GLFW_SAMPLES, 4);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    this->_window = glfwCreateWindow(WIDTH, HEIGHT, "42run", NULL, NULL);


    if ( this->_window == NULL )
    {
        fprintf(stderr, "Failed to create a GLFW window, you might need to download the latest drivers or change the OpenGL version to 3\n");
        delete this;

        std::exit(-1);
    }

    // Create the OpenGL context from the window and settings specified
    glfwMakeContextCurrent(this->_window);

    //set input mode
    glfwSetInputMode(this->_window, GLFW_STICKY_KEYS, GL_TRUE);


    //This turn off v sync
    //glfwSwapInterval(0);

    //hide mouse
    glfwSetInputMode(this->_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    //set cursor position
    glfwSetCursorPos(this->_window, 0, 0);

    //needed to work
    glewExperimental = GL_TRUE;

    GLenum err = glewInit();

    if ( GLEW_OK != err )
    {
        fprintf(stderr, "Failed to initialize glew\n");
        std::exit(-1);
    }

    glViewport(0, 0, WIDTH, HEIGHT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


    //wireframe
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

}

void Graphic::clear(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
}

void Graphic::display(void) {
    glfwSwapBuffers(this->_window);
}

bool Graphic::processInput(Camera * camera, Player * player) {


    glfwPollEvents();

    if ( glfwGetKey(this->_window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(this->_window) != 0 )
        return false;
    if ( glfwGetKey(this->_window, GLFW_KEY_LEFT) || glfwGetKey(this->_window, GLFW_KEY_A) )
        player->moveLeft();
    if ( glfwGetKey(this->_window, GLFW_KEY_RIGHT) || glfwGetKey(this->_window, GLFW_KEY_D) )
        player->moveRight();
    if (glfwGetKey(this->_window, GLFW_KEY_SPACE) || glfwGetKey(this->_window, GLFW_KEY_UP) || glfwGetKey(this->_window, GLFW_KEY_W))
        player->jump();


    if (glfwGetKey(this->_window, GLFW_KEY_I))
        camera->moveCamera(camera->getSpeed() * TimeManager::instance().deltaTime);
    if (glfwGetKey(this->_window, GLFW_KEY_K))
        camera->moveCamera(-1 * camera->getSpeed() * TimeManager::instance().deltaTime);
    if (glfwGetKey(this->_window, GLFW_KEY_J))
        camera->strafe(-1 * camera->getSpeed() * TimeManager::instance().deltaTime);
    if (glfwGetKey(this->_window, GLFW_KEY_L))
        camera->strafe(camera->getSpeed() * TimeManager::instance().deltaTime);



    double mouseX, mouseY;

    glfwGetCursorPos(this->_window, &mouseX, &mouseY);

    if ( mouseX != 0 && mouseY != 0 ) {
        camera->setViewByMouse((float)mouseX, (float)mouseY);
    }

    glfwSetCursorPos(this->_window, 0, 0);


    return true;
}

void Graphic::terminate(void) {
    glfwTerminate();
}
