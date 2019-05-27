#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;
class MyException : public exception
{
public:
	MyException();
	~MyException();
	string message = "";
	const char* what() const throw();

};

class InvalidData : public MyException {
public:
	InvalidData();
};

