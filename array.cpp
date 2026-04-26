#include "array.h"
#include <iostream>
#include <cstring>

Array::Array(int size, int step) : m_size(size), m_step(step), m_curIndex(0)
{
	m_pArr = new int[m_size];

    if (!m_pArr) {
        std::cout << "Failed to allocate memory" << std::endl;
        m_size = 0;
    }
}

Array::~Array() 
{
    delete[] m_pArr;
}

void Array::showElements() 
{
    for (int i = 0; i < m_curIndex; i++) {
        std::cout << m_pArr[i] << " ";
    }
    std::cout << std::endl;
}

void Array::expandArray(int size) 
{
    int newSize = m_size + size;
    
    int *pNewArr = new int[newSize];
    memcpy(pNewArr, m_pArr, sizeof(int)*m_size);

    delete[] m_pArr;

    m_size = newSize;
    m_pArr = pNewArr;
}

int Array::getSize()
{
    return m_size;
}

int Array::getElemSize()
{
    return m_curIndex;
}

void Array::setValue(int val)
{
    if (m_curIndex >= m_size) 
    {
        expandArray(m_step);
    }
    m_pArr[m_curIndex] = val;
    m_curIndex++;
}

void Array::setArray(int* pArr, int size)
{
    if (pArr == nullptr || size <= 0) return;

    if (m_curIndex + size > m_size) {
        expandArray(m_curIndex + size - m_size);
    }

    /*
    for (int i = 0; i < size; ++i) {
        m_pArr[m_curIndex] = pArr[i];
        m_curIndex++;
    }
    */
    memcpy(m_pArr + m_curIndex, pArr, sizeof(int)*size);
    m_curIndex += size;
}