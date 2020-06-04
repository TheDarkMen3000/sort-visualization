#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "list.hpp"
#include "shaderprogram.hpp"

class Renderer
{
private:
    List* m_Rects;
    ShaderProgram m_Shader;

public:
    Renderer(List* rects);

    void render();
};

#endif