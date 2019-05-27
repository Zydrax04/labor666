#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class Validation
{
public:
	Validation();
	

	void titel_validation(string titel);
	void genre_validation(string genre);
	void jahr_validation(int jahr);
	void likes_validation(int likes);
	void trailer_validation(string trailer);
	void input_file_validation(ifstream fin);
	string to_csv_field_validation(string field);
	string from_csv_field_validation(string field);
	string hmtl_field_validation(string field);
	bool validate_object( string titel, string genre, int jahr, int likes, string trailer);

	~Validation();
};

