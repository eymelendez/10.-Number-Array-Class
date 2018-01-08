// MAIN_Numbers.cpp

#include<iostream>
#include<fstream>

using namespace::std;

#include"Numbers.h"

int main() 
{
	int size;
	char fileName[15];

	cout << "Entre el numero de elementos: ";
	cin >> size;

	Numbers list(size);
	list.getValues();
	list.displayValues();

	cout << "Entre el nombre del archivo: ";
	cin >> fileName;

	list.getValues(fileName);

	system("pause");

	return 0;


} // end main. 22 de marzo de 2017 - Successful!
