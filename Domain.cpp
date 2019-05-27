#include "Domain.h"

Film::Film() {
	this->title = "";
	this->genre = "";
	this->year = 0;
	this->likes = 0;
	this->trailer = "";
}

Film::Film(string title, string genre, int year, int likes, string trailer) {
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->likes = likes;
	this->trailer = trailer;
}

//getters

string Film::get_title() {
	return this->title;
}

string Film::get_genre() {
	return this->genre;
}

int Film::get_year() {
	return this->year;
}

int Film::get_likes() {
	return this->likes;
}

string Film::get_trailer() {
	return this->trailer;
}

//setters
void Film::set_title(string title) {
	this->title = title;
}

void Film::set_genre(string genre) {
	this->genre = genre;
}

void Film::set_year(int year) {
	this->year = year;
}

void Film::set_likes(int likes) {
	this->likes = likes;
}

void Film::set_trailer(string trailer) {
	this->trailer = trailer;
}

Film::~Film() {

}