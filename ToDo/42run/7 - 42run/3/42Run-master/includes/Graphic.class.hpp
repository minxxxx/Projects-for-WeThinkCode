#ifndef _42RUN_GRAPHIC_CLASS_HPP_
#define _42RUN_GRAPHIC_CLASS_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <42run.hpp>
#include <Player.class.hpp>

#include <Camera.class.hpp>

class Graphic {

public:
    static Graphic & instance(void);
    ~Graphic(void);

    void terminate(void);


    void clear(void);
    void display(void);

    bool processInput(Camera * camera, Player * player);


private:
    Graphic(void);

    GLFWwindow* _window;


};


#endif //42RUN_GRAPHIC_CLASS_HPP
