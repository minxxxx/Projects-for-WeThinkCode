#ifndef _42RUN_TEXTMANAGER_CLASS_HPP_
#define _42RUN_TEXTMANAGER_CLASS_HPP_


#include <string>
#include <GL/glew.h>
#include <freetype2/ft2build.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include FT_FREETYPE_H
#include <42run.hpp>
#include <map>

#include <Shader.class.hpp>

struct Character {
    GLuint textureID;    // ID handle of the glyph texture
    glm::ivec2 size;     // Size of glyph
    glm::ivec2 bearing;  // Offset from baseline to left/top of glyph
    GLuint advance;      // Horizontal offset to advance to next glyph
};

class TextManager {

public:
    static TextManager &  instance(void);

    ~TextManager(void);

    void    print(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);

private:
    TextManager(void);

    Shader      _shader;

    glm::mat4   _projection;

    std::map<GLchar, Character> _characters;
    GLuint VAO, VBO;

};

#endif //_42RUN_TEXTMANAGER_CLASS_HPP_
