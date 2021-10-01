/*
Exercise number 2
*/

#include "Interface.h"
//#include <crtdbg.h>

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

int main(int argc, int argv[])
{
	Interface interface;
	interface.readSystem();
	interface.menuOptions();
}

