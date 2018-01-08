// Number.h

#pragma once


#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace::std;

class Numbers
{
public:
	Numbers(int); // Construct
	~Numbers(); // Destructor

	void setElement(int, int); // sets an element to a value.
	int getElement(int) const; // Returns an element.
	void getValues();
	void getValues(char fileName[]);
	int getNumElements() const;
	void displayValues() const;

	int getMayor() const;
	int getMenor() const;
	int getAverage() const;


private:
	int *list; // Pointer to the array.
	int numElements; // Number of elements.
	bool isValid(int) const; // Validates subscripts.

};

