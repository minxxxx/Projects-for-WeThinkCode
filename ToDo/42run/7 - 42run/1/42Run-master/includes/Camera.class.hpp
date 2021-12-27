#ifndef CAMERA_CLASS_HPP
# define CAMERA_CLASS_HPP

#define PI 3.14159265358979323846264338327950288		// Define PI for usage in positioning the camera's rotations
#define GLM_FORCE_RADIANS								// Make sure GLM is using radians instead of degrees

#include <fstream>
#include <glm/glm.hpp>									// Used for the GLM math library
#include <glm/gtc/matrix_transform.hpp>					// Used for the GLM math library
#include <glm/gtx/transform2.hpp>						// Used for the GLM math library


// This is our bare-bones Camera class to manage user movement in our 3D scene.
// The next tutorials will add rotation and mouse support to our class.
class Camera 
{
    public:

        Camera(void);
        ~Camera(void);

        glm::mat4 setPerspective(float fov, float aspectRatio, float nearPlane, float farPlane);
        glm::mat4 getRotationMatrix(void);
        glm::mat4 getProjectionMatrix(void);
        glm::mat4 getViewMatrix(void);
        void setPosition(glm::vec3 position);
        glm::vec3 getPosition(void);
        glm::vec3 getView(void);
        glm::vec3 getUp(void);
        glm::vec3 getRight(void);
        float getYaw(void);
        void setYaw(float yaw);
        float getPitch(void);
        void setPitch(float pitch);
        void setSpeed(double speed);
        double getSpeed(void);
        void setRotationSpeed(double speed);
        double getRotationSpeed(void);
        void setViewByMouse(float mouseX, float mouseY);
        void positionCamera(float positionX, float positionY, float positionZ, float yaw, float pitch);
        void moveCamera(float speed);
        void strafe(float speed);

    protected:

        glm::mat4 _projectionMatrix;								// The camera's projection matrix
        glm::vec3 _position;										// The camera's position
        float _speed = 5.0;								// The camera's speed that is used with a time slice
        float _yaw = 0;										// The horizontal rotation angle (in radians), y-axis
        float _pitch = 0;									// The vertical rotation angle (in radians, x-axis
        float _rotationSpeed = 5;                           // This is our rotation speed that is used with the time slice and yaw
        double _mouseSpeed = 0.0005;                        // The speed for the mouse rotations

};


#endif