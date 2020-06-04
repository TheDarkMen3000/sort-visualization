#include "renderer.hpp"
#include "window.hpp"

Renderer::Renderer(List* rects)
{
    m_Rects = rects;
}

void Renderer::render()
{
    glBindVertexArray(Window::rectVAO);
    m_Shader.start();

    for (unsigned int i = 0; i < m_Rects->getRectCount(); i++)
    {
        if (m_Rects->getRect(i)->getIndex() == m_Rects->getMarked())
        {
            m_Shader.setColor(0.0f, 0.0f, 1.0f);
        }
        else if (m_Rects->wasSwaped(m_Rects->getRect(i)))
        {
            m_Shader.setColor(1.0f, 0.0f, 0.0f);
        }
        else
        {
            m_Shader.setColor(1.0f, 1.0f, 1.0f);
        }
        m_Shader.setTransform(m_Rects->getRect(i), m_Rects->getRectCount());
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }

    m_Shader.stop();
    glBindVertexArray(0);
}