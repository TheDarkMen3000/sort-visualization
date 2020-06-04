#include "matrix.hpp"

Matrix4x4::Matrix4x4()
{
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            m_Values[x][y] = 0.0f;
        }
    }
}

Matrix4x4::Matrix4x4(float dia)
{
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            m_Values[x][y] = 0.0f;
        }
    }

    m_Values[0][0] = dia;
    m_Values[1][1] = dia;
    m_Values[2][2] = dia;
    m_Values[3][3] = dia;
}

const float* Matrix4x4::getData() const
{
    return &m_Values[0][0];
}

float* Matrix4x4::operator[](unsigned int index)
{
    if (index >= 0 && index < 4)
    {
        return m_Values[index];
    }

    return 0;
}

Matrix4x4 Matrix4x4::operator*(Matrix4x4& other)
{
    Matrix4x4 result;

    for (int i = 0; i < 4; i++)
    {
        result[i][0] = m_Values[i][0] * other[0][0] + m_Values[i][1] * other[1][0] + m_Values[i][2] * other[2][0] + m_Values[i][3] * other[3][0];
        result[i][1] = m_Values[i][0] * other[0][1] + m_Values[i][1] * other[1][1] + m_Values[i][2] * other[2][1] + m_Values[i][3] * other[3][1];
        result[i][2] = m_Values[i][0] * other[0][2] + m_Values[i][1] * other[1][2] + m_Values[i][2] * other[2][2] + m_Values[i][3] * other[3][2];
        result[i][3] = m_Values[i][0] * other[0][3] + m_Values[i][1] * other[1][3] + m_Values[i][2] * other[2][3] + m_Values[i][3] * other[3][3];
    }

    return result;
}