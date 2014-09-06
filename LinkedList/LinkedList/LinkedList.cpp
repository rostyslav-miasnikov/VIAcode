// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "list.h"


int _tmain(int argc, _TCHAR* argv[])
{
	my::list<int> mylist;
	mylist.print();

	mylist.push_back(7);
	mylist.push_back(6);
	mylist.push_back(5);
	mylist.print();

	int sz = mylist.size();

	mylist.sort();
	mylist.print();

	sz = mylist.size();

	std::cout << "First value: " << mylist.first() << std::endl;
	std::cout << "Last value: " << mylist.last() << std::endl;

	std::cout << "[0]: " << **( mylist.at(0) ) << std::endl;
	std::cout << "[1]: " << **( mylist.at(1) ) << std::endl;
	std::cout << "[2]: " << **( mylist.at(2) ) << std::endl;

	mylist.erase(mylist.at(1));
	mylist.print();

	mylist.erase(mylist.at(1));
	mylist.print();

	mylist.erase(mylist.at(1));
	mylist.print();

	mylist.erase(mylist.at(0));
	mylist.print();

	system("PAUSE");

	return 0;
}

