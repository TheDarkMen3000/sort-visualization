#include "window.hpp"

GLuint Window::rectVAO = 0;
GLuint Window::rectVBO = 0;

Window::~Window()
{
    if (m_Win) { glfwDestroyWindow(m_Win); }

    glfwTerminate();
}

bool Window::init(int width, int height, const char* title)
{
    if (!glfwInit())
    {
        return false;
    }

    m_Win = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!m_Win)
    {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(m_Win);

    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        return false;
    }

    if (rectVAO == 0)
    {
        float pos[12] = {
            0.0f, 0.0f,
            0.0f, 1.0f,
            1.0f, 1.0f,
            1.0f, 1.0f,
            1.0f, 0.0f,
            0.0f, 0.0f
        };

        glCreateVertexArrays(1, &rectVAO);

        glBindVertexArray(rectVAO);

        glCreateBuffers(1, &rectVBO);
        glBindBuffer(GL_ARRAY_BUFFER, rectVBO);
        glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), pos, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

        glBindVertexArray(0);
    }

    return true;
}

bool Window::isOpen()
{
    return !glfwWindowShouldClose(m_Win);
}

void Window::update()
{
    glfwSwapBuffers(m_Win);
    glfwPollEvents();
}