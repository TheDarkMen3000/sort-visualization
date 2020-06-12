#ifndef LIST_HPP
#define LIST_HPP

#include "rect.hpp"

class List
{
private:
    Rect** m_Rects;
    unsigned int m_RectCount;

    unsigned int m_MarkIndex, m_Swap1Index, m_Swap2Index;

    unsigned int m_SwapTimeout;

public:
    List(unsigned int count);
    List(const List& other) = delete;
    ~List();

    List operator=(const List& other) = delete;

    Rect** getRects() const;
    unsigned int getRectCount() const;

    Rect* getRect(unsigned int index) const;
    unsigned int getValue(unsigned int index) const;

    unsigned int getMarked() const;
    unsigned int setMarked(unsigned int index);

    bool wasSwaped(Rect* rect) const;

    void shuffel();
    void swap(unsigned int index1, unsigned int index2);

    void setSwapTimeout(unsigned int time);

    Rect* operator[](unsigned int index);

private:
    void _swap(unsigned int index1, unsigned int index2);
};

#endif