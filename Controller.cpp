#include "Controller.h"
#include <iostream>
#include "Repository.h"
#include "Domain.h"
#include <windows.h>
using namespace std;
Controller::Controller(Repository& repo):repo(repo)
{
	
}


bool Controller::add_film(Film film) {
	if (this->repo.find_film(film) > -1)
		return false;
	this->repo.add(film);
	return true;
}

bool Controller::remove_film(Film film) {
	if (this->repo.find_film(film) == -1)
		return false;
	this->repo.remove(film);
	return true;
}

bool Controller::modify_film(Film old_film, Film new_film) {
	if (this->repo.find_film(old_film) == -1)
		return false;
	this->repo.modify(old_film, new_film);
	return true;
}

void Controller::show_trailer(Film film) {
	ShellExecute(NULL, "open", film.get_trailer().c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void Controller::print_movies(int pos) {
	vector <Film> all_movies = this->repo.get_movies();
	Film film = all_movies[pos];
	cout << "Title: " << film.get_title() << endl;
	cout << "Genre: " << film.get_genre() << endl;
	cout << "Year: " << film.get_year() << endl;
	cout << "Likes: " << film.get_likes() << endl;
	cout << "Trailer: " << film.get_trailer() << endl;
	cout << "----------------------------------------------" << endl;
}

bool Controller::add_film_watchlist(Film film) {
	if (this->repo.find_film_watchlist(film) > -1)
		return false;
	this->repo.add_watchlist(film);
	return true;
}

bool Controller::remove_film_watchlist(Film film) {
	if (this->repo.find_film_watchlist(film) == -1)
		return false;
	this->repo.remove_watchlist(film);
	return true;
}

void Controller::inc_like(Film film)
{
	this->repo.inc_like(film);
}

void Controller::print_watchlist()
{
	int count = 0;
	Film film;
	vector<Film> watchlist = this->repo.get_watchlist();
	for (int i = 0; i < watchlist.size(); i++)
	{
		film = watchlist[i];
		count += 1;
		cout << count << "." << " " << film.get_title() << " " << film.get_year() << endl;
		cout << "\n";
	}
}

void Controller::print_movies_admin() {
	vector <Film> all_movies = this->repo.get_movies();
	for (int i = 0; i < all_movies.size(); i++)
	{
		this->print_movies(i);
	}
}

bool Controller::print_movies_user(int pos, string genre) {
	vector <Film> all_movies = this->repo.get_movies();
	if (genre == all_movies[pos].get_genre() || genre == "") {
		this->print_movies(pos);
		return true;
	}
	else return false;
}

vector<Film> Controller::get_movies()
{
	return(this->repo.get_movies());
}

Controller::~Controller()
{
}