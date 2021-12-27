#ifndef _42RUN_MESH_CLASS_HPP_
#define _42RUN_MESH_CLASS_HPP_

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Shader.class.hpp>
#include <vector>
#include <assimp/types.h>


struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};


struct Texture {
    GLuint id;
    std::string type;
    aiString path;
};

class Mesh {

public:
/*  Mesh Data  */
std::vector<Vertex> vertices;
std::vector<GLuint> indices;
std::vector<Texture> textures;

Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
~Mesh(void);


void draw(void);
void setShader(Shader * s);

private:
    /*  Render data  */
    GLuint VAO, VBO, EBO;

    Shader * _shader;
    void _setupMesh(void);

};

#endif //_42RUN_MESH_CLASS_HPP_
