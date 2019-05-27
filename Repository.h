#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Domain.h"
#include "Validation.h"
#include "MyException.h"

using namespace std;

class Repository
{
private:
	vector <Film> movies;
	vector <Film> watchlist;
public:
	Repository();

	//increases the likes of a movie
	void inc_like(Film film);
	//add new movie to the watchlist
	void add_watchlist(Film film);

	//remove movie from the watchlist
	void remove_watchlist(Film film);

	//getter
	vector <Film> get_watchlist();

	//add new movie to the list
	void add(Film new_film);

	//remove movie from the list
	void remove(Film film);

	//getter
	vector <Film> get_movies();

	//modifies a film from the list
	void modify(Film old_film, Film new_film);

	//find film from the list
	//returns index of the film in the list or -1 if not found
	int find_film(Film film);

	//find film from the watchlist
	//returns index of the film in the list or -1 if not found
	int find_film_watchlist(Film film);

	~Repository();
};

