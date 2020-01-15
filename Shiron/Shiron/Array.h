#ifndef __ARRAY_H
#define __ARRAY_H

#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

//was used for an array of const Feedback* in Seller
template<class T>
class Array 
{
public:
	static constexpr unsigned int INITIAL_PHYSICAL_SIZE = 1;
	static constexpr unsigned int INITIAL_LOGICAL_SIZE = 0;

private:
	unsigned int m_logicSize;
	unsigned int m_physSize;
	T* m_arr;

	bool setLogicSize(unsigned int logicSize);
	bool setPhysSize(unsigned int physSize);

	void reallocArray();
	void cleanArray();

public:
	Array(int physSize = INITIAL_PHYSICAL_SIZE); //c'tor
	Array(const Array& other); //d'tor
	~Array(); //d'tor

	unsigned int getLogicSize() const;
	unsigned int getPhysSize() const;

	const Array& operator=(const Array& other);
	const Array& operator+=(const T& newVal);

	friend ostream& operator<<(ostream& os, const Array& arr)
	{
		for (unsigned int i = 0; i < arr.m_logicSize; i++)
			os << "#" << i + 1 << " " << *(arr.m_arr[i]) << endl;
		return os;
	}
};

template<class T>
Array<T>::Array(int physSize)
{
	m_arr = nullptr;
	setPhysSize(physSize);
	setLogicSize(INITIAL_LOGICAL_SIZE);
	m_arr = new T[m_physSize];
}

template<class T>
Array<T>::Array(const Array& other) : m_arr(nullptr)
{
	*this = other;
}

template<class T>
Array<T>::~Array()
{
	cleanArray();
}
template<class T>
void Array<T>::cleanArray()
{
	for (unsigned int i = 0; i < m_logicSize; i++)
		delete m_arr[i];
	delete[]m_arr;
}

template<class T>
const Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		cleanArray();
		m_physSize = other.m_physSize;
		m_logicSize = other.m_logicSize;
		m_arr = new T[m_physSize];
		for (unsigned int i = 0; i < m_logicSize; i++)
			m_arr[i] = other.m_arr[i];
	}
	return *this;
}

template<class T>
const Array<T>& Array<T>::operator+=(const T& newVal)
{
	if (m_logicSize == m_physSize)
	{
		m_physSize *= 2;
		reallocArray();
	}
	m_arr[m_logicSize++] = newVal;
	return *this;
}

template<class T>
void Array<T>::reallocArray()
{
	T* tempArr = new T[m_physSize];
	for (unsigned int i = 0; i < m_logicSize; i++)
	{
		tempArr[i] = m_arr[i];
	}
	delete[]m_arr;
	m_arr = tempArr;
}

template<class T>
bool Array<T>::setLogicSize(unsigned int logicSize)
{
	if (logicSize >= INITIAL_LOGICAL_SIZE)
	{
		m_logicSize = logicSize;
		return true;
	}
	return false;
}

template<class T>
bool Array<T>::setPhysSize(unsigned int physSize)
{
	if (physSize >= INITIAL_PHYSICAL_SIZE)
	{
		m_physSize = physSize;
		return true;
	}
	return false;
}

template<class T>
unsigned int Array<T>::getLogicSize() const
{
	return m_logicSize;
}

template<class T>
unsigned int Array<T>::getPhysSize() const
{
	return m_physSize;
}

#endif // __ARRAY_H