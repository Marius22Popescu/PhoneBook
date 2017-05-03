#include "stdafx.h"
#include "Contact.h"
#include <iostream>

using namespace std;

Contact::Contact()
{
	
}

Contact::~Contact()
{
	
}

string Contact::getName()
{
	return name;
}

 int Contact::getNumber()
{
	return number;
}

void Contact::setName(string n)
{
	name = n;
}

void Contact::setNumber(int x)
{
	number = x;
}
