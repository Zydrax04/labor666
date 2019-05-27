#pragma once
#include <iostream>
#include <string>
using namespace std;

class Film {
private:
	string title;
	string genre;
	int year;
	int likes;
	string trailer;
public:
	Film();
	Film(string title, string genre, int year, int likes, string trailer);
	
	//getters
	string get_title();
	string get_genre();
	int get_year();
	int get_likes();
	string get_trailer();

	//setters
	void set_title(string title);
	void set_genre(string genre);
	void set_year(int year);
	void set_likes(int likes);
	void set_trailer(string trailer);

	~Film();
};

