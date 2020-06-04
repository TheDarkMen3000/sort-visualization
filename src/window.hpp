#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
private:
    GLFWwindow* m_Win;

    static GLuint rectVBO;

public:
    static GLuint rectVAO;

    ~Window();

    bool init(int width, int height, const char* title);

    bool isOpen();

    void update();
};

#endif