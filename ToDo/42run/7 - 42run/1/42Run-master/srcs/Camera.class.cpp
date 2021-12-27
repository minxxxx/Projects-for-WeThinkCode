#include <Camera.class.hpp>
#include <iostream>

Camera::Camera(void) {
	this->_position = glm::vec3(0.0, 0.0, 0.0);
}

Camera::~Camera(void) {
    return ;
}

glm::mat4 Camera::setPerspective(float fov, float aspectRatio, float nearPlane, float farPlane) {
	this->_projectionMatrix = glm::perspective(fov, aspectRatio, nearPlane, farPlane);

	return this->_projectionMatrix;
}


void Camera::positionCamera(float positionX, float positionY, float positionZ, float yaw, float pitch) {
	this->_position = glm::vec3( positionX, positionY, positionZ );
    this->_yaw = yaw;
    this->_pitch = pitch;
}


glm::mat4 Camera::getViewMatrix(void) {
    return this->getRotationMatrix() * inverse(translate(glm::mat4(), this->_position));
}

glm::mat4 Camera::getRotationMatrix(void) {
    glm::mat4 rotationMatrix(1.0f);
    rotationMatrix = rotate(rotationMatrix, this->_pitch, glm::vec3(1, 0, 0));
    rotationMatrix = rotate(rotationMatrix, this->_yaw, glm::vec3(0, 1, 0));

    return rotationMatrix;
}


glm::vec3 Camera::getView(void) {
    glm::vec4 viewVector = inverse(this->getRotationMatrix()) * glm::vec4(0, 0, -1, 1);

    return glm::vec3(viewVector);
}


glm::vec3 Camera::getUp(void) {
    glm::vec4 upVector = inverse(this->getRotationMatrix()) * glm::vec4(0, 1, 0, 1);

    return glm::vec3(upVector); }

glm::vec3 Camera::getRight(void) {
    glm::vec4 rightVector = inverse(this->getRotationMatrix()) * glm::vec4(1, 0, 0, 1);

    return glm::vec3(rightVector);
}


// This will move the camera forward or backward depending on the speed
void Camera::moveCamera(float speed) {
	glm::vec3 viewVector = this->getView();

    this->_position.x += viewVector.x * speed;
    this->_position.y += viewVector.y * speed;
    this->_position.z += viewVector.z * speed;

    //std::cout << "pos x : " << this->_position.x << " y : " << this->_position.y << " z : " << this->_position.z << " pitch : " << this->_pitch << " yaw : " << this->_yaw << std::endl;
}

void Camera::setViewByMouse(float xOffset, float yOffset) {
    this->_yaw += xOffset * this->_mouseSpeed;
    this->_pitch += yOffset * this->_mouseSpeed;

    if ( this->_yaw > 2 * PI )
        this->_yaw = 0;

    if ( this->_yaw < 0 )
        this->_yaw = 2 * PI;

    if ( this->_pitch > glm::radians(90.0f) )
        this->_pitch = glm::radians(90.0f);
    if ( this->_pitch < glm::radians(-90.0f) )
        this->_pitch = glm::radians(-90.0f);
}

void Camera::strafe(float speed) {
    glm::vec3 rightVector = this->getRight();

    this->_position.x += rightVector.x * speed;
    this->_position.z += rightVector.z * speed;
}

glm::mat4 Camera::getProjectionMatrix(void) {
    return this->_projectionMatrix;
}

void Camera::setPosition(glm::vec3 position) {
    this->_position = position;
}

glm::vec3 Camera::getPosition(void) {
    return this->_position;
}

float Camera::getYaw(void) {
    return this->_yaw;
}

void Camera::setYaw(float yaw) {
    this->_yaw = yaw;
}

float Camera::getPitch(void) {
    return this->_pitch;
}

void Camera::setPitch(float pitch) {
    this->_pitch = pitch;
}

void Camera::setSpeed(double speed) {
    this->_speed = speed;
}

double Camera::getSpeed(void) {
    return this->_speed;
}

void Camera::setRotationSpeed(double speed) {
    this->_rotationSpeed = speed;
}

double Camera::getRotationSpeed(void) {
    return this->_rotationSpeed;
}