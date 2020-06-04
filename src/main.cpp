#include "window.hpp"
#include "renderer.hpp"
#include "list.hpp"
#include "sortengine.hpp"
#include <iostream>
#include <thread>
#include <sol/sol.hpp>

int main()
{
    Window win;

    if (!win.init(800, 800, "Sort visualisation"))
    {
        std::cout << "Could not create window!" << std::endl;
        return -1;
    }

    List rects(100);

    Renderer renderer(&rects);

    SortEngine sEngine("lua/bubblesort.lua");

    sEngine.sort(&rects);

    while (win.isOpen())
    {
        glClear(GL_COLOR_BUFFER_BIT);

        renderer.render();

        win.update();
    }

    sEngine.join();

    return 0;
}