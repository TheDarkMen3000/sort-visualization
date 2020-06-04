#include "shaderprogram.hpp"
#include "matrix.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

ShaderProgram::ShaderProgram()
{
    m_VertexShader = loadShader("assets/vertex.shader", GL_VERTEX_SHADER);
    m_FragmentShader = loadShader("assets/fragment.shader", GL_FRAGMENT_SHADER);

    m_Shader = glCreateProgram();

    glAttachShader(m_Shader, m_VertexShader);
    glAttachShader(m_Shader, m_FragmentShader);
    glLinkProgram(m_Shader);

    m_TransformMatrix = glGetUniformLocation(m_Shader, "transformMatrix");
    m_Color = glGetUniformLocation(m_Shader, "color");
}

ShaderProgram::~ShaderProgram()
{
    glDetachShader(m_Shader, m_VertexShader);
    glDeleteShader(m_VertexShader);

    glDetachShader(m_Shader, m_FragmentShader);
    glDeleteShader(m_FragmentShader);

    glDeleteProgram(m_Shader);
}

void ShaderProgram::start()
{
    glUseProgram(m_Shader);
}

void ShaderProgram::stop()
{
    glUseProgram(0);
}

void ShaderProgram::setTransform(Rect* rect, unsigned int rectCount)
{
    float ratio = (2.0f / rectCount);

    Matrix4x4 translateMatrix(1.0f), scaleMatrix(1.0f);

    // Translate
    // x pos
    translateMatrix[0][3] = -1 + rect->getIndex() * ratio;
    // y pos
    translateMatrix[1][3] = -1;

    // Scale
    // x scale
    scaleMatrix[0][0] = ratio;
    // y scale
    scaleMatrix[1][1] = (rect->getValue() + 1.0f) * ratio;

    Matrix4x4 transformMatrix = translateMatrix * scaleMatrix;

    glUniformMatrix4fv(m_TransformMatrix, 1, GL_TRUE, transformMatrix.getData());
}

void ShaderProgram::setColor(float r, float g, float b)
{
    glUniform3f(m_Color, r, g, b);
}

GLuint ShaderProgram::loadShader(const char* path, GLenum type)
{
    std::ifstream f(path);
    std::stringstream buffer;
    buffer << f.rdbuf();

    std::string source = buffer.str();
    const char* cSource = source.c_str();
    int length = (int)source.size();

    f.close();

    GLuint shader = glCreateShader(type);

    glShaderSource(shader, 1, &cSource, &length);
    glCompileShader(shader);

    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status != GL_TRUE)
    {
        char buffer[1024];
        glGetShaderInfoLog(shader, 1024, 0, buffer);

        if (type == GL_VERTEX_SHADER)
        {
            std::cout << "Vertex Shader: ";
        }
        else if (type == GL_FRAGMENT_SHADER)
        {
            std::cout << "Fragment Shader: ";
        }

        std::cout << buffer << std::endl;

        glDeleteShader(shader);

        return 0;
    }

    return shader;
}