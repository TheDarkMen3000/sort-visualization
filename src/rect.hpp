#ifndef RECT_HPP
#define RECT_HPP

class Rect
{
private:
    int m_Index;
    int m_Value;

public:
    Rect() = default;
    Rect(int index, int value);

    void setIndex(int index);
    int getIndex() const;

    int getValue() const;
};

#endif