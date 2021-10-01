/*
Exercise number 3
*/

#include "Interface.h"
#include <crtdbg.h>

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

int main()
{
	Interface interface;
	interface.readSystem();
	interface.readUsersInformationFromFile();
	interface.menuOptions();
	return 0;
}
