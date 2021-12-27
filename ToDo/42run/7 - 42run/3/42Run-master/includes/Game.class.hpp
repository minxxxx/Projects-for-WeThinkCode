#ifndef _42RUN_GAME_CLASS_HPP_
#define _42RUN_GAME_CLASS_HPP_

#include <Camera.class.hpp>
#include <Section.class.hpp>
#include <list>

class Game {

public:
    Game(void);
    ~Game(void);

    void startGame(void);
    eSection randSection(void);


private:
    Camera      _camera;
    std::list<Section *>  _sections;

};

#endif //42RUN_GAME_CLASS_HPP
