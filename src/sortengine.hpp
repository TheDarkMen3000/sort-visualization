#ifndef SORTENGINE_HPP
#define SORTENGINE_HPP

#include <sol/sol.hpp>
#include <thread>
#include "list.hpp"

class SortEngine
{
private:
    sol::state m_State;
    std::function<int(List&)> m_Sort;

    std::thread m_SortThread;

public:
    SortEngine(const char* scriptPath);

    void sort(List* list);
    void join();

private:
    bool getRunning();

    void sortMain(List* list);
};

#endif