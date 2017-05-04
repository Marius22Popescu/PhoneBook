// PhoneBook4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Contact.h"
#include <sstream>
using namespace std;

void add(int size, Contact *p);
void list(int size, Contact *p);
void search(int size, Contact *p);
void delet(int size, Contact *p);
void fileInput(int size, Contact *p);
void fileOutput(int size, Contact *p);
int displayMenu();

const int max = 400;
int _tmain(int argc, _TCHAR* argv[])
{
	Contact *Pbook;
	Pbook = new Contact[100];
	Contact *p = Pbook;
	int input;
	int size = 0;
	cout << "*** MY PHONEBOOK APPLICATION ***\nPlease choose an operation: \n";
	do
	{
		input = displayMenu();
		switch (input)
		{
		case 1:
		{
			fileInput(size, p);
			add(size, p);
			fileOutput(size, p);
			size++;
		}
			break;

		case 2:
			fileInput(size, p);
			search(size, p);
			break;

		case 3:
			fileInput(size, p);
			delet(size, p);
			fileOutput(size, p);
			break;

		case 4:
			fileInput(size, p);
			list(size, p);

			break;
		default:
			return 0;
		}
	} while (input = !0);

	return 0;
	system("pause");
	return 0;
}

int displayMenu()
{
	int r = 0;
	char c;
	cout << "A(add) | S (Search) | D(Delete) | L(List) | Q(Quit):\n";
	cin.clear();
	cin >> c;
	cin.ignore(100, '\n');
	if (c == 'a')
		r = 1;
	else if (c == 's')
		r = 2;
	else if (c == 'd')
		r = 3;
	else if (c == 'l')
		r = 4;
	else if (c == 'q')
		r = 0;
	else
		r = 0;

	return r;
}

void add(int size, Contact *p)
{
	int number = 0;
	string name = " ";
	cout << "Enter name:\n";
	getline(cin, name);
	cout << "Enter phone:\n";
	cin >> number;
	p[size].setName(name);
	p[size].setNumber(number);
	
}

void list(int size, Contact *p)
{
	for (int i = 0; i < size; i++)
	{
		cout << p[i].getName() << " " << p[i].getNumber() << endl;
	}
}

void search(int size, Contact *p)
{
	cout << "Enter a nume for search: \n";
	string toSearch;
	string temp = " ";
	getline(cin, toSearch);
	for (int i = 0; i <= size; i++)
	{
		temp = p[i].getName();
		if (temp == toSearch)
		{
			cout << p[i].getName() << " " << p[i].getNumber() << endl;
		}
	}
}
void delet(int size, Contact *p)
{
	cout << "Enter a name for dellete: \n";
	string toSearch;
	string temp = " ";
	getline(cin, toSearch);
	for (int i = 0; i <= size; i++)
	{
		temp = p[i].getName();
		if (temp == toSearch)
		{
			for (int j = i; j <= size; j++)
			{
				p[j] = p[j + 1];
				//p[j].setName(p[j+1].getName());      
				//p[j].setNumber(p[j+1].getNumber());
			}
			cout << "delete" << endl;
		}
	}
}

void fileInput(int size, Contact *p)
{
	ifstream fin;
	fin.open("phonebook.txt");
	if (fin.is_open())
	{
		cout << "test" << endl;
		while (! fin.eof())
		{
			getline(fin, p[size].getName());
			fin >> p[size].getName();
			cout << p[size].getName();
			fin.ignore('#');
			//fin.ignore(100, '\n');                   //   !!!!HERE IS THE PROBLEM!!!!
			//fin.get(p[size].getNumber());
			string numberStr;
			fin>>numberStr;
			stringstream ss(numberStr);
			int value = 0;
			ss >> value;
			p[size].setNumber(value);
			fin.ignore(100, '\n');
			size++;
		}
		fin.close();
	}
	else
		cout << "\nError: The file could not be opened";
	return;
}

void fileOutput(int size, Contact *p)
{
	ofstream fout;
	fout.open("phonebook.txt", ios::app);
	if (fout.is_open())
	{
		for (int i = 0; i < size; i++)
		{
			fout << p[i].getName()<<"#"<< p[i].getNumber() << endl;
			
		}
		fout.close();
	}
	else
		cout << "\nError: The file could not be opened";
	return;
}