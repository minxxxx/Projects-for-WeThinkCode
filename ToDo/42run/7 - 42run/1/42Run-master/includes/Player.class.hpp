#ifndef PLAYER_CLASS_HPP
#define PLAYER_CLASS_HPP

#include <Model.class.hpp>
#include <glm/glm.hpp>
#include <Camera.class.hpp>

class Player {
public:
    Player(Model * m);
    ~Player(void);

    void draw(Camera * camera);

    void moveLeft(void);
    void moveRight(void);
    void jump(void);

    glm::vec3 & getPosition(void);

private:
    Model       *_m;
    glm::vec3   _position;
    glm::vec3   _scale;
    glm::vec3   _rotation;


    bool        _isGrounded;
    bool        _isJumpingUp;
    bool        _isJumpingDown;
};

#endif //PLAYER_CLASS_HPP
