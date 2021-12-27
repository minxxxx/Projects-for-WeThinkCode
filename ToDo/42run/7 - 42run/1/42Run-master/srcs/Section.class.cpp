#include <Section.class.hpp>
#include <TimeManager.class.hpp>
#include <map>
#include <iostream>
#include <cmath>

Section::Section(Model *model, eSection type, Model * obstacle, Model *apple) : _m(model), _obstacle(obstacle), _apple(apple), _type(type), _scale(1.0f), _rotation(0.0f), _appleRot(0.0f), _appleScale(0.5f)
{
    typedef void (Section::*INIT)(void);
    static std::map<eSection, INIT> map = {
            { NABOO, &Section::_initNaboo },
            { DRAGON, &Section::_initDragon },
            { KRABBS, &Section::_initKrabbs },
            { SONIC, &Section::_initSonic }
    };

    INIT ft = map[type];
    (this->*ft)();

    return;
}

Section::~Section(void)
{
    return;
}

void Section::setPosition(glm::vec3 pos)
{
    this->_position = pos;

    typedef void (Section::*POS)(glm::vec3);
    static std::map<eSection, POS> map = {
            { NABOO, &Section::_posNaboo },
            { DRAGON, &Section::_posDragon },
            { KRABBS, &Section::_posKrabbs },
            { SONIC, &Section::_posSonic }
    };

    POS ft = map[_type];
    (this->*ft)(pos);

}

glm::vec3 & Section::getPosition(void)
{
    return this->_position;
}

glm::vec3 & Section::getOPosition(void)
{
    return this->_oPosition;
}

void Section::move(void)
{
    this->_position.z += (11.35f * TimeManager::instance().deltaTime) / 2.5f;
    this->_oPosition.z += (11.35f * TimeManager::instance().deltaTime) / 2.5f;

    for (std::list<glm::vec3>::iterator it = this->_applesPos.begin() ; it != this->_applesPos.end() ; ++it) {
        (*it).z += (11.35f * TimeManager::instance().deltaTime) / 2.5f;
    }
}

void Section::draw(Camera *camera)
{
    this->_m->draw(camera, this->_position, this->_scale, this->_rotation);
    this->_obstacle->draw(camera, this->_oPosition, this->_oScale, this->_oRotation);

    this->_appleRot.y += TimeManager::instance().deltaTime;

    for (std::list<glm::vec3>::iterator it = this->_applesPos.begin() ; it != this->_applesPos.end() ; ++it) {
        this->_apple->draw(camera, (*it), this->_appleScale, this->_appleRot);
    }

}

bool Section::collide(Player * player)
{

    typedef bool (Section::*COL)(Player *);
    static std::map<eSection, COL> map = {
            { NABOO, &Section::_colNaboo },
            { DRAGON, &Section::_colDragon },
            { KRABBS, &Section::_colKrabbs },
            { SONIC, &Section::_colSonic }
    };

    COL ft = map[_type];
    return (this->*ft)(player);
}

void Section::_initNaboo(void) {
    this->_oScale = glm::vec3(0.4f);
    this->_oRotation = glm::vec3(0.0f, glm::radians(85.0f), 0.0f);
}

void Section::_initKrabbs(void) {
    this->_oScale = glm::vec3(0.8f);
    this->_oRotation = glm::vec3(0.0f);
}

void Section::_initDragon(void) {
    this->_oScale = glm::vec3(0.7f);
    this->_oRotation = glm::vec3(0.0f, glm::radians(180.0f), 0.0f);
}

void Section::_initSonic(void) {
    this->_oScale = glm::vec3(0.5f);
    this->_oRotation = glm::vec3(0.0f);
}

void Section::_posDragon(glm::vec3 pos) {

    this->_oPosition = pos;
    this->_oPosition.y -= 0.55f;
    this->_oPosition.x += 0.5f;

    if (rand() % 2 == 0)
        this->_applesPos.push_back(glm::vec3(_oPosition.x, -0.55f, _oPosition.z + 2.0f));
    if (rand() % 2 == 0)
        this->_applesPos.push_back(glm::vec3(_oPosition.x, -0.55f, _oPosition.z - 2.0f));
    if (rand() % 2 == 0)
        this->_applesPos.push_back(glm::vec3(_oPosition.x - 0.9f, -0.55f, _oPosition.z));

}

void Section::_posNaboo(glm::vec3 pos) {

    this->_oPosition = pos;
    this->_oPosition.y -= 0.45f;

}

void Section::_posKrabbs(glm::vec3 pos) {

    this->_oPosition = pos;
    this->_oPosition.y -= 0.55f;
    this->_oPosition.x -= 0.5f;

    if (rand() % 2 == 0)
        this->_applesPos.push_back(glm::vec3(_oPosition.x, -0.55f, _oPosition.z + 2.0f));
    if (rand() % 2 == 0)
        this->_applesPos.push_back(glm::vec3(_oPosition.x, -0.55f, _oPosition.z - 2.0f));
    if (rand() % 2 == 0)
        this->_applesPos.push_back(glm::vec3(_oPosition.x + 1.2f, -0.55f, _oPosition.z));

}

void Section::_posSonic(glm::vec3 pos) {

    this->_oPosition = pos;
    this->_oPosition.y -= 0.55f;

    if (rand() % 2 == 0)
        this->_applesPos.push_back(glm::vec3(_oPosition.x + 0.7f, -0.55f, _oPosition.z));

    if (rand() % 2 == 0)
        this->_applesPos.push_back(glm::vec3(_oPosition.x - 0.7f, -0.55f, _oPosition.z));

}

bool Section::takeApple(glm::vec3 & playerPos) {
    for (std::list<glm::vec3>::iterator it = this->_applesPos.begin() ; it != this->_applesPos.end() ; ++it) {
        if (glm::distance(playerPos, (*it)) <= 0.35f) {
            _applesPos.erase(it);
            return true ;
        }
    }

    return false;
}

bool Section::_colNaboo(Player *p) {
    if ((std::fabs(p->getPosition().z - this->getOPosition().z) < 1.0f) && (std::fabs(p->getPosition().y - this->getOPosition().y) < 0.4f)) {
        return true;
    }
    return false;
}

bool Section::_colKrabbs(Player *p) {
    if ((std::fabs(p->getPosition().z - this->getOPosition().z) < 1.0f) && (std::fabs(p->getPosition().x - this->getOPosition().x) < 0.9f)) {
        return true;
    }
    return false;
}

bool Section::_colDragon(Player *p) {
    if ((std::fabs(p->getPosition().z - this->getOPosition().z) < 1.0f) && (std::fabs(p->getPosition().x - this->getOPosition().x) < 0.6f)) {
        return true;
    }
    return false;
}

bool Section::_colSonic(Player *p) {
    if ((std::fabs(p->getPosition().z - this->getOPosition().z) < 1.0f) && (std::fabs(p->getPosition().x - this->getOPosition().x) < 0.5f)) {
        return true;
    }
    return false;
}
