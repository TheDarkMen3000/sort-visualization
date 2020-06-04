#include "window.hpp"
#include "renderer.hpp"
#include "list.hpp"
#include "sortengine.hpp"
#include <iostream>
#include <thread>
#include <sol/sol.hpp>

void parseArgs(int argv, char** args);

int main(int argv, char** args)
{
    if (argv == 2)
    {
        const char* scriptPath = args[1];

        Window win;

        if (!win.init(800, 800, "Sort visualisation"))
        {
            std::cout << "Could not create window!" << std::endl;
            return -1;
        }

        List rects(100);

        Renderer renderer(&rects);

        try 
        {
            SortEngine sEngine(scriptPath);

            sEngine.sort(&rects);

            while (win.isOpen())
            {
                glClear(GL_COLOR_BUFFER_BIT);

                renderer.render();

                win.update();
            }

            sEngine.join();
        }
        catch (sol::error &e)
        {
            std::cout << "Lua Error: " << e.what() << std::endl;
        }

        return 0;
    }
    
    std::cout << "Usage: sort <Algorithm script file>" << std::endl;
}