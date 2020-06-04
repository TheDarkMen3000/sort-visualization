#include "rect.hpp"

Rect::Rect(int index, int value)
{
    m_Index = index;
    m_Value = value;
}

void Rect::setIndex(int index)
{
    m_Index = index;
}

int Rect::getIndex() const
{
    return m_Index;
}

int Rect::getValue() const
{
    return m_Value;
}