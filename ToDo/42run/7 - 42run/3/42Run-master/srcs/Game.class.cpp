#include <Game.class.hpp>
#include <Graphic.class.hpp>
#include <TimeManager.class.hpp>
#include <42run.hpp>
#include <Model.class.hpp>
#include <Camera.class.hpp>
#include <TextManager.class.hpp>
#include <TextManager.class.hpp>
#include <glm/glm.hpp>
#include <iostream>
#include <Player.class.hpp>
#include <time.h>

Game::Game(void) {
}

Game::~Game(void) {

    std::list<Section *>::iterator it;
    for (it = this->_sections.begin() ; it != this->_sections.end() ; it ++) {
        delete (*it);
    }
    Graphic::instance().terminate();

    return ;
}

eSection Game::randSection(void)
{
    int section = (rand() % 4) + 1;

    return static_cast<eSection >(section);
}

void Game::startGame(void) {

    Graphic & g = Graphic::instance();

    TextManager & tm = TextManager::instance();
    tm.print("Loading Models, Textures and Shaders...", 245.0f, 340.0f, 1.0f, glm::vec3(1.0f, 1.0f, 1.0f));
    g.display();

    Shader s;
    s.initialize("shaders/Shader.vertex", "shaders/Shader.fragment");
    Model playerModel ("models/nanosuit/nanosuit.obj", &s);
    Model m ("models/cluster/cluster.obj", &s);
    Model m2 ("models/cluster2/cluster2.obj", &s);
    Model k ("models/krabbs/krabbs.obj", &s);
    Model f ("models/fighter/fighter.obj", &s);
    Model d ("models/dragon/dragon.obj", &s);
    Model sn ("models/sonic/sonic.obj", &s);
    Model a ("models/apple/apple.obj", &s);

    std::map<eSection , Model *> models;
    models[NABOO] = &f;
    models[KRABBS] = &k;
    models[DRAGON] = &d;
    models[SONIC] = &sn;

    Player player(&playerModel);

    glm::vec3 startPos(0.0f, 0.0f, -7.0f);
    for(int i = 0; i < SECTIONS; i++)
    {
        eSection rands = randSection();
        Section * s = new Section((rand() % 2) == 0 ? &m : &m2, rands, models[rands], &a);
        s->setPosition(startPos);
        startPos.z -= SECTIONSIZE;
        this->_sections.push_back(s);
    }


    double distance = 0;

    //									 FOV		    Aspect Ratio			   Near / Far Planes
    this->_camera.setPerspective(glm::radians(45.0f), WIDTH / (float)HEIGHT, 0.01f, 100.0f);
    //					        Position	         Yaw	 Pitch
    this->_camera.positionCamera(0, 0.9f, 3.0f,		0.0f,		0.2f);

    int appleCount = 0;


    while (g.processInput(&this->_camera, &player)) {

        TimeManager::instance().calculateFrameRate(false);

        g.clear();

        std::list<Section *>::iterator it;
        for (it = this->_sections.begin() ; it != this->_sections.end() ; ++it) {
            (*it)->move();
            (*it)->draw(&this->_camera);
        }

        player.draw(&this->_camera);

        if (this->_sections.front()->getPosition().z >= SECTIONSIZE)
        {
            Section * front = this->_sections.front();
            this->_sections.pop_front();
            delete front;
            eSection rands = randSection();
            Section * s = new Section((rand() % 2) == 0 ? &m : &m2, rands, models[rands], &a);
            glm::vec3 pos = this->_sections.back()->getPosition();
            pos.z -= SECTIONSIZE;
            s->setPosition(pos);
            this->_sections.push_back(s);
        }

        if (this->_sections.front()->takeApple(player.getPosition()))
            appleCount++;

        if (this->_sections.front()->collide(&player))
            break ;



        distance += TimeManager::instance().deltaTime * 5.0f;

        tm.print(std::to_string((int)distance), 15.0f, 15.0f, 1.0f, glm::vec3(1.0f, 0.0f, 0.0f));
        tm.print(std::to_string(appleCount), 1200.0f, 15.0f, 1.0f, glm::vec3(1.0f, 0.0f, 1.0f));

        g.display();
    }

    while (g.processInput(&this->_camera, &player)) {
        g.clear();

        tm.print("SCORE: " + std::to_string((int)distance) + " x " + std::to_string(appleCount) + " = " + std::to_string((int)distance * appleCount), 50.0f, 400.0f, 1.0f, glm::vec3(1.0f, 1.0f, 1.0f));
        tm.print(std::to_string((int)distance), 15.0f, 15.0f, 1.0f, glm::vec3(1.0f, 0.0f, 0.0f));
        tm.print(std::to_string(appleCount), 1200.0f, 15.0f, 1.0f, glm::vec3(1.0f, 0.0f, 1.0f));

        g.display();
    }

}
