#pragma once
#include <string>
#include <iostream>

using namespace std;

class Student 
{
private:
	string name;
	string lastName;
	short int age;
public:
	Student(string, string, short int);
};