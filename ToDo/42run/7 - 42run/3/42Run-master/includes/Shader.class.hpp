#ifndef SHADER_CLASS_HPP
#define SHADER_CLASS_HPP

#include <string>										// Used for our STL string objects
#include <fstream>										// Used for our ifstream object to load text files
#include <GL/glew.h>		    							// Used for the OpenGL types like GLuint, GLfloat, etc.


class Shader
{
    public:
        Shader(void);
        ~Shader(void);

        std::string loadShaderFile(std::string strFile);

        void initialize(std::string strVertexFile, std::string strFragmentFile );

        GLint getVariable(std::string strVariable);

        void setInt(GLint id, int newValue)											{ glUniform1i(id, newValue);		}
        void setFloat(GLint id, GLfloat newValue)									{ glUniform1f(id, newValue);		}
        void setFloat2(GLint id, GLfloat v0, GLfloat v1)							{ glUniform2f(id, v0, v1);			}
        void setFloat3(GLint id, GLfloat v0, GLfloat v1, GLfloat v2)				{ glUniform3f(id, v0, v1, v2);		}
        void setFloat4(GLint id, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)	{ glUniform4f(id, v0, v1, v2, v3);	}


        void setMatrix4(GLint id, GLsizei count, GLboolean transpose, const GLfloat *value)
        {
            glUniformMatrix4fv(id, count, transpose, value);
        }


        void turnOn(void);
        void turnOff(void);

        void destroy();

    private:
        GLuint _vertexShaderId;
        GLuint _fragmentShaderId;
        GLuint _shaderProgramId;
};

#endif
