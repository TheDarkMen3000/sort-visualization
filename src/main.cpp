#include "window.hpp"
#include "renderer.hpp"
#include "list.hpp"
#include <iostream>
#include <thread>
#include <atomic>

void bubblesort(List* list);

std::atomic<bool> running;

int main()
{
    running = true;
    Window win;

    if (!win.init(800, 800, "Sort visualisation"))
    {
        std::cout << "Could not create window!" << std::endl;
        return -1;
    }

    List rects(100);

    Renderer renderer(&rects);

    std::thread sort(bubblesort, &rects);

    while (win.isOpen())
    {
        glClear(GL_COLOR_BUFFER_BIT);

        renderer.render();

        win.update();
    }

    running = false;

    sort.join();

    return 0;
}

void bubblesort(List* list)
{
    for (int n = list->getRectCount(); n > 1 && running; n--)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (list->getRect(i)->getValue() > list->getRect(i + 1)->getValue())
            {
                list->swap(i, i + 1);
            }
        }
    }
}