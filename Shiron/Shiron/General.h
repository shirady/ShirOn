#ifndef __GENERAL_H
#define __GENERAL_H

#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

//template<class T>
class General
{
public:

	template<class T>
	 static void printCollection(const T& collection);
};

/*
T should have the following:
const_iterator, methods 'begin' and 'end', operator<<
*/
template <class T>
void General::printCollection(const T& collection)
{
	typename T::const_iterator itr = collection.begin();
	typename T::const_iterator itrEnd = collection.end();

	if (itr == itrEnd)
	{
		cout << "Collection is empty!\n";
		return;
	}
	int i = 1;
	for (; itr != itrEnd; ++itr)
	{
		cout << "#" << i << " " << *(*itr);
		i++;
	}
	cout << endl;
	
}

#endif //__GENERAL_H