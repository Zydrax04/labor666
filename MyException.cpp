
#include "MyException.h"


MyException::MyException()
{
}


MyException::~MyException()
{
}

const char* MyException::what() const throw()
{
	return message.c_str();
}

InvalidData::InvalidData()
{
	message = "Invalid data /n";
}
