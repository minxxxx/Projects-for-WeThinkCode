#include <Shader.class.hpp>							// References the Shader class definition and GLEW header

#include <cstdlib>
#include <iostream>


Shader::Shader(void) {
    return ;
}

Shader::~Shader(void)
{
    this->destroy();
    return ;
}

std::string Shader::loadShaderFile(std::string strFile)
{

	std::ifstream fin(strFile.c_str());

	if ( !fin )
		return "";

	std::string strLine = "";
	std::string strText = "";


	while ( getline(fin, strLine) )
	{
		strText = strText + "\n" + strLine;
	}


	fin.close();

	return strText;
}


void Shader::initialize(std::string strVertexFile, std::string strFragmentFile)
{

	std::string strVShader, strFShader;

	if ( !strVertexFile.length() || !strFragmentFile.length() )
		return;

	if ( this->_vertexShaderId || this->_fragmentShaderId || this->_shaderProgramId )
        this->destroy();

	GLenum errorCheckValue = glGetError();

	// Here we get an Id to our vertex and fragment shaders
    this->_vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    this->_fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

	// Now we load the shaders from the respective files and store it in a string
	strVShader = this->loadShaderFile(strVertexFile.c_str());
	strFShader = this->loadShaderFile(strFragmentFile.c_str());

	// Do a quick switch so we can do a double pointer below
	const char *szVShader = strVShader.c_str();
	const char *szFShader = strFShader.c_str();


	// Now this assigns the shader text file to each shader pointer
	glShaderSource(this->_vertexShaderId, 1, &szVShader, NULL);
	glShaderSource(this->_fragmentShaderId, 1, &szFShader, NULL);


	// Now we actually compile the shader code
	glCompileShader(this->_vertexShaderId);
	glCompileShader(this->_fragmentShaderId);

	// Next we create a program object to represent our shaders
    this->_shaderProgramId = glCreateProgram();

	// We attach each shader we just loaded to our program object
	glAttachShader(this->_shaderProgramId, this->_vertexShaderId);
	glAttachShader(this->_shaderProgramId, this->_fragmentShaderId);


	// Our last init function is to link our program object with OpenGL
	glLinkProgram(this->_shaderProgramId);

	errorCheckValue = glGetError();

	if ( errorCheckValue != GL_NO_ERROR )
	{
		fprintf(stderr, "ERROR: Could not create the shader program with error Id: %d\n", errorCheckValue);
		exit(-1);
	}
}


GLint Shader::getVariable(std::string strVariable)
{
	if(!this->_shaderProgramId)
		return -1;

	//std::cout << "strVariable :" <<  strVariable.c_str() << " shader programm id : " << _shaderProgramId << std::endl;

	return glGetUniformLocation(this->_shaderProgramId, strVariable.c_str());
}


void Shader::destroy()
{
	if(this->_vertexShaderId)
	{
		glDetachShader(this->_shaderProgramId, this->_vertexShaderId);
		glDeleteShader(this->_vertexShaderId);
        this->_vertexShaderId = 0;
	}

	if(this->_fragmentShaderId)
	{
		glDetachShader(this->_shaderProgramId, this->_fragmentShaderId);
		glDeleteShader(this->_fragmentShaderId);
        this->_fragmentShaderId = 0;
	}

	if(this->_shaderProgramId)
	{
		glDeleteShader(this->_shaderProgramId);
        this->_shaderProgramId = 0;
	}
}


void Shader::turnOn(void)
{
    glUseProgram(this->_shaderProgramId);
}

void Shader::turnOff(void)
{
    glUseProgram(0);
}