#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Domain.h"
using namespace std;

class Files
{
public:
	string fileName;
	Files();
	~Files();
	void write_file(vector <Film> list);
};

class CSV_Format : public Files
{
	public:
		CSV_Format(string fileName);
		void write_file(vector <Film> list);
};

class HTML_Format : public Files
{
public:
	HTML_Format(string fileName);
	void write_file(vector <Film> list);
};
