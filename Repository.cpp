#include "Repository.h"
#include <vector>
#include <cstdlib>

using namespace std;

Repository::Repository()
{
	//constructor reads data from filme.txt file
	//parameters: none
	//return: void
	ifstream fin("filme.txt");
	Validation validator;
	if (!fin.is_open()) {
		cout << "Input File not found" << endl;
		exit(0);
	}
	string field, line;
	vector <string> movie;
	while (getline(fin, line)) {
		movie.clear();
		for (int i = 0; i < line.size(); i++) {  //parse string
			if(line[i] != ',')
				field += line[i];
			else{
				//complete field
				string valid_field = validator.from_csv_field_validation(field);
				movie.push_back(valid_field);
				field = "";
			}
		}
		movie.push_back(field);
		field = "";
		//add film

		Film film(movie[0], movie[1], atoi(movie[2].c_str()), atoi(movie[3].c_str()), movie[4]);
		this->add(film);
	}
	fin.close();
}

int Repository::find_film(Film film) {
	//function searches a film in the movies list
	//parameters: the film to search for
	//return: the index of the film in the list or -1 if not found
	unsigned int i;
	for (i = 0; i < this->movies.size(); i++) {
		if (this->movies[i].get_title() == film.get_title())
			if (this->movies[i].get_year() == film.get_year())
				return i;
	}
	return -1;
}

void Repository::add(Film new_film) {
	//function adds a new film to the movies list
	//parameters: the new film
	//return: void
	this->movies.push_back(new_film);
}

void Repository::remove(Film film) {
	//function erases one film from the movies list
	//parameters: the film to remove
	//return: void
	int index = this->find_film(film);
	this->movies.erase(this->movies.begin() + index);
}

void Repository::modify(Film old_film, Film new_film) {
	//function modifies an old film with a new one
	//parameters: old film and the new film
	//return:: void
	int i = this->find_film(old_film);
	this->movies[i].set_title(new_film.get_title());
	this->movies[i].set_genre(new_film.get_genre());
	this->movies[i].set_year(new_film.get_year());
	this->movies[i].set_likes(new_film.get_likes());
	this->movies[i].set_trailer(new_film.get_trailer());
}

vector <Film> Repository::get_movies() {
	//function returns the movies list 
	//parameters:-
	//return vector
	return this->movies;
}

vector <Film> Repository::get_watchlist() {
	//function returns the watchlist 
	//parameters:-
	//return vector
	return this->watchlist;
}

void Repository::add_watchlist(Film film) {
	//function adds a new film to the watchlist
	//parameters: the new film
	//return: void
	this->watchlist.push_back(film);
}

void Repository::remove_watchlist(Film film) {
	//function erases one film from the watchlist
	//parameters: the film to remove
	//return: void
	int index = this->find_film_watchlist(film);
	this->watchlist.erase(this->watchlist.begin() + index);
}

int Repository::find_film_watchlist(Film film) {
	//function searches a film in the watchlist
	//parameters: the film to search for
	//return: the index of the film in the list or -1 if not found
	for (int i = 0; i < this->watchlist.size(); i++) {
		if (this->watchlist[i].get_title() == film.get_title())
			if (this->watchlist[i].get_year() == film.get_year())
				return i;
	}
	return -1;
}

void Repository::inc_like(Film film) {
	//function increments likes for a film
	//parameters: the film
	//return: void
	int index = this->find_film(film);
	int old = this->movies[index].get_likes();
	this->movies[index].set_likes(old + 1);
}

Repository::~Repository()
{
	//Destructor writes data in input file at end of the program
	ofstream fout("filme.txt");
	if (!fout.is_open()) {
		cout << "Input File not found" << endl;
		exit(0);
	}
	Validation validator;
	for (int i = 0; i < this->movies.size(); i++) {
		Film film = movies[i];
		string title = validator.to_csv_field_validation(film.get_title());
		fout << title << "," << film.get_genre() << "," << film.get_year() << "," << film.get_likes() << "," << film.get_trailer() << endl;
	}
	fout.close();
}