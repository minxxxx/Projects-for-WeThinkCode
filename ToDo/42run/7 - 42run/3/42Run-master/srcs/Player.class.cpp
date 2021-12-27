#include <Player.class.hpp>
#include <TimeManager.class.hpp>
#include <iostream>

Player::Player(Model* m) : _m(m), _position(0.0f, -0.55f, 0.0f), _scale(0.070f), _rotation(0.0f, glm::radians(180.0f), 0.0f), _isGrounded(true), _isJumpingUp(false), _isJumpingDown(false) {

}

Player::~Player(void) {

}

void Player::draw(Camera *camera) {
   //std::cout << "X: " << this->_position.x << std::endl;
    //std::cout << "Z: " << this->_position.z << std::endl;
    if (this->_isJumpingUp) {
        this->_position.y += TimeManager::instance().deltaTime * 2.0f;
        this->_rotation.y += (glm::radians(360.0f) * TimeManager::instance().deltaTime) * 1.065f * 2.0f;
        if (this->_position.y > 0.4f) {
            this->_position.y = 0.4f;
            this->_isJumpingUp = false;
            this->_isJumpingDown = true;
        }



    } else if (this->_isJumpingDown) {
        this->_position.y -= TimeManager::instance().deltaTime * 2.25f;
        this->_rotation.y += (glm::radians(360.0f) * TimeManager::instance().deltaTime) * 1.065f * 2.0f;

        if (this->_position.y <= -0.55f) {
            this->_position.y = -0.55f;
            this->_isJumpingDown = false;
            this->_isGrounded = true;
            this->_rotation.y = glm::radians(180.0f);
        }


    }



    this->_m->draw(camera, this->_position, this->_scale, this->_rotation);
}

void Player::moveLeft(void) {
    if (this->_position.x > -0.82f) {
        if (this->_isJumpingUp || this->_isJumpingDown) {
            this->_position.x -= TimeManager::instance().deltaTime;
        } else {
            this->_position.x -= TimeManager::instance().deltaTime * 2.0f;
        }

        if (this->_position.x < -0.82f) {
            this->_position.x = -0.82f;
        }
    }

}

void Player::moveRight(void) {
    if (this->_position.x < 0.82f) {
        if (this->_isJumpingUp || this->_isJumpingDown) {
            this->_position.x += TimeManager::instance().deltaTime;
        } else {
            this->_position.x += TimeManager::instance().deltaTime * 2.0f;
        }
        if (this->_position.x > 0.82f) {
            this->_position.x = 0.82f;
        }
    }
}

void Player::jump(void) {
    if (this->_isGrounded) {
        this->_isGrounded = false;
        this->_isJumpingUp = true;
        this->_isJumpingDown = false;
    }
}

glm::vec3 &Player::getPosition(void) {
    return _position;
}
