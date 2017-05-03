#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

class Contact
{
private:

	int number = 0;
	string name = "";

public:

	Contact();
	virtual ~Contact();
	string getName();
	int getNumber();
	void setName(string n);
	void setNumber(int x);
	friend void list(int size, Contact *p);
};