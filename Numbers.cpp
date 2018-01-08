// Numbers.cpp

#include<iostream>
#include<cstdlib>

using namespace::std;

#include"Numbers.h"

Numbers::Numbers(int size)
{
	list = new int[size];
	numElements = size;

	for (int i = 0; i < size; i++) 
	{
		list[i] = 0;

	}

}

Numbers::~Numbers()
{
	delete[] list;
}

void Numbers::setElement(int element, int value) 
{
	if (isValid(element)) 
	{
		list[element] = value;

	}
	else 
	{
		cout << "Error: Invalid Subscript\n";
		exit(EXIT_FAILURE);

	}



}

int Numbers::getElement(int element) const 
{
	if (isValid(element))
	{
		return list[element];
	}
	else 
	{
		cout << "Error: Invalid subscript\n";
		exit(EXIT_FAILURE);

	}

}


void Numbers::getValues() 
{

	int value;

	for (int i = 0; i < getNumElements(); i++) 
	{
		cout << "Dato [" << i << "] = ";
		cin >> value;
		setElement(i, value);


	}


}

void Numbers::getValues(char fileName[]) 
{
	int count = 0;
	fstream inputFile;

	// Open the file.

	inputFile.open(fileName);

	if (!inputFile) 
	{
		cout << "Error Opening " << fileName << ".\n";
	}

	else
	{
		// Read the numbers from the files into the array.

		while (count < getNumElements() && inputFile >> list[count])
		{
			count++;
		}

		// Close the file.

		inputFile.close();
		displayValues();

	}



}

int Numbers::getNumElements() const 
{
	return numElements;

}

void Numbers::displayValues() const 
{

	int value;
	cout << "El contenido del arreglo es: ";

	for (int i = 0; i < getNumElements(); i++) 
	{
		value = getElement(i);
		cout << value << ",";


	}

	cout << "\nThe highest number is: " << getMayor() << endl;
	cout << "\nThe lowest numbe is: " << getMenor() << endl;
	cout << "\nThe average is: " << getAverage() << endl;

	cout << endl;

}

int Numbers::getMayor() const
{
	int mayor;

	mayor = list[0];

	for (int i = 0; i < numElements; i++) 
	{
		if (list[i] > mayor) 
		{
			mayor = list[i];
		}

	}

	return mayor;

}


int Numbers::getMenor() const
{
	int menor;

	menor = list[0];

	for (int i = 0; i < numElements; i++)
	{
		if (list[i] < menor)
		{
			menor = list[i];
		}

	}

	return menor;

}


int Numbers::getAverage() const
{
	int total = 0;			// Initialize accumulator
	int average = 0;		// Will hold the average

	for (int i = 0; i < numElements; i++)
	{
		total += list[i];

	}

	average = total / numElements;

	return average;

}

bool Numbers::isValid(int element) const 
{

	bool status;

	if (element < 0 || element >= numElements)
	{
		status = false;
	}
	else
		status = true;

	return status;

}