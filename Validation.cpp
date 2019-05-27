
#include "Validation.h"
#include "MyException.h"
using namespace std;

Validation::Validation()
{
}


Validation::~Validation()
{
}

//functie care verifica daca titlul e valid
void Validation::titel_validation(string titel) {
	if (titel == "") 
		throw(InvalidData());
}
//functie care verifica daca genul e valid
void Validation::genre_validation(string genre) {
	if (genre == "") 
		throw(InvalidData());
}
//functie care verifica daca anul e valid
void Validation::jahr_validation(int jahr) {
	if ((jahr < 1888) && (jahr > 2019)) 
		throw(InvalidData());
}
//functie care verifica daca nr like uri e valid
void Validation::likes_validation(int likes) {
	if (likes < 0) 
		throw(InvalidData());
}
//functie care verifica daca trailerul e valid
void Validation::trailer_validation(string trailer) {
	if (trailer == "") 
		throw(InvalidData());
}

void input_file_validation(ifstream fin) {
	if (!fin.is_open())
		throw(InvalidData());
}

//fct care valideaza obiectele
bool Validation::validate_object( string titel, string genre, int jahr, int likes, string trailer) {
	bool ok = false;
	titel_validation(titel);
	genre_validation(genre);
	jahr_validation(jahr);
	likes_validation(likes);
	trailer_validation(trailer);
	ok = true;
	return ok;
}

string Validation::to_csv_field_validation(string field) {
	//function checks for ',' in a movie field and replaces them
	//parameters: the movie field
	//return: the formated string
	for (int i = 0; i < field.size(); i++) {
		if (field[i] == ',')
			field[i] = '&';
	}
	return field;
}

string Validation::from_csv_field_validation(string field) {
	//function checks for '&' in a movie field and replaces them
	//parameters: the movie field
	//return: the formated string
	for (int i = 0; i < field.size(); i++) {
		if (field[i] == '&')
			field[i] = ',';
	}
	return field;
}