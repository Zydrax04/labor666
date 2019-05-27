#pragma once
#include <iostream>
#include "Repository.h"
#include "Domain.h"
#include <string>
//#include <windows.h>
using namespace std;

class Controller
{
private:
	Repository& repo;
public:
	Controller(Repository& repo);
	//Controller();

	bool add_film(Film film);
	bool remove_film(Film film);
	bool modify_film(Film old_film, Film new_film);
	void print_movies(int pos);
	void show_trailer(Film film);
	bool add_film_watchlist(Film film);
	bool remove_film_watchlist(Film film);
	void inc_like(Film film);
	void print_watchlist();
	void print_movies_admin();
	bool print_movies_user(int pos, string genre);
	vector<Film> get_movies();

	~Controller();
};