#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

class Matrix4x4
{
private:
    float m_Values[4][4];

public:
    Matrix4x4();
    Matrix4x4(float dia);

    const float* getData() const;

    float* operator[](unsigned int index);
    Matrix4x4 operator*(Matrix4x4& other);
};

#endif