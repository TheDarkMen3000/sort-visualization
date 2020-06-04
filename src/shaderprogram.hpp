#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

#include "rect.hpp"
#include <GL/glew.h>

class ShaderProgram
{
private:
    GLuint m_VertexShader;
    GLuint m_FragmentShader;
    GLuint m_Shader;
    
    GLuint m_TransformMatrix,
           m_Color;

public:
    ShaderProgram();
    ~ShaderProgram();

    void start();
    void stop();

    void setTransform(Rect* rect, unsigned int rectCount);
    void setColor(float r, float g, float b);

private:
    GLuint loadShader(const char* path, GLenum type);
};

#endif