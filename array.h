#pragma once

class Array {
	int m_size;
	int m_step;
	int *m_pArr;
	int m_curIndex;

public:
	Array(int size = 5, int step = 5);
	~Array();
	void showElements();
	void expandArray(int size);
	int getSize();
	int getElemSize();
	void setValue(int val);
	void setArray(int* pArr, int size);
};