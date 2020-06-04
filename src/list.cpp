#include "list.hpp"
#include <chrono>
#include <random>
#include <iostream>
#include <thread>

List::List(unsigned int count)
{
    m_RectCount = count;
    m_Rects = new Rect*[m_RectCount];
    m_MarkIndex = -1;
    m_Swap1Index = -1;
    m_Swap2Index = -1;

    m_SwapTimeout = 5;

    for (unsigned int i = 0; i < m_RectCount; i++)
    {
        m_Rects[i] = new Rect(i, i);
    }

    shuffel();
}

List::~List()
{
    for (unsigned int i = 0; i < m_RectCount; i++)
    {
        delete m_Rects[i];
    }

    delete[] m_Rects;
}

Rect** List::getRects() const
{
    return m_Rects;
}

unsigned int List::getRectCount() const
{
    return m_RectCount;
}

Rect* List::getRect(unsigned int index) const
{
    if (index < m_RectCount)
    {
        return m_Rects[index];
    }
    return 0;
}

unsigned int List::getValue(unsigned int index) const
{
    Rect* result = getRect(index);

    if (result) return result->getValue();
    else return 0;
}

unsigned int List::getMarked() const
{
    return m_MarkIndex;
}

unsigned int List::setMarked(unsigned int index)
{
    if (index >= 0 && index < m_RectCount)
    {
        m_MarkIndex = index;
        return getValue(index);
    }
    return 0;
}

bool List::wasSwaped(Rect* rect) const
{
    if (rect->getIndex() == m_Swap1Index || rect->getIndex() == m_Swap2Index) return true;
    else return false;
}

void List::shuffel()
{
    unsigned int seed = (unsigned int)std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> rand(0, m_RectCount - 1);

    for (unsigned int i = 0; i < m_RectCount * 10; i++)
    {
        _swap(rand(generator), rand(generator));
    }

    m_MarkIndex = -1;
    m_Swap1Index = -1;
    m_Swap2Index = -1;
}

void List::swap(unsigned int index1, unsigned int index2)
{
    if (index1 < m_RectCount && index2 < m_RectCount)
    {
        _swap(index1, index2);
        m_Swap1Index = index1;
        m_Swap2Index = index2;

        std::this_thread::sleep_for(std::chrono::duration<int,std::milli>(m_SwapTimeout));
    }
}

void List::_swap(unsigned int index1, unsigned int index2)
{
    if (index1 < m_RectCount && index2 < m_RectCount)
    {
        Rect* tmp = m_Rects[index2];

        m_Rects[index2] = m_Rects[index1];
        m_Rects[index1] = tmp;

        m_Rects[index1]->setIndex(index1);
        m_Rects[index2]->setIndex(index2);
    }
}

void List::setSwapTimeout(unsigned int time)
{
    m_SwapTimeout = time;
}

Rect* List::operator[](int index)
{
    if (index < m_RectCount)
    {
        return m_Rects[index];
    }
    return 0;
}