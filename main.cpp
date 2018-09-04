#include "stdafx.h"
#include "MyEvent.h"
#include <conio.h>

int main()
{
	MyEvent e1([]() {
		if ('w' == _getch())
			std::cout << "w" << std::endl;
	});
	MyEvent e2([]() {
		if ('s' == _getch())
			std::cout << "s" << std::endl;
	});
	MyEvent e3([]() {
		if ('a' == _getch())
			std::cout << "a" << std::endl;
	});

	MyEvent e4([]() {
		if ('d' == _getch())
			std::cout << "d" << std::endl;
	});


	MyEventManager eventManager;
	eventManager.addVectorEvent({ e1, e2, e3, e4 });

	eventManager.start();

	//main loop
	while (1) {



	}

	return 0;
}