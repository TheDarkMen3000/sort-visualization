#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <atomic>

class Window
{
private:
    GLFWwindow* m_Win;

    static GLuint rectVBO;

public:
    static GLuint rectVAO;
    static std::atomic<bool> running;

    ~Window();

    bool init(int width, int height, const char* title);

    bool isOpen();

    void update();
};

#endif