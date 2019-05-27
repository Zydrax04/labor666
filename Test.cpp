#include "Ui.h"
#include "Domain.h"
#include "Repository.h"
#pragma once
#include "Controller.h"
#include "Repository.h"
#include <assert.h>
#include <iostream>
#include <string>
#include "Test.h"
using namespace std;


void Test::find_film_test() {
	Film film1("John", "Action", 2019, 23, "http");
	Film film2("Mike", "Action", 2018, 23, "http");
	Repository repo;
	repo.add(film1);
	repo.add(film2);
	assert(repo.find_film(film2) == 1);
	assert(repo.find_film(film1) == 0);
}

void Test::add_test() {
	Film film1("John", "Action", 2019, 23, "http");
	Film film2("Mike", "Action", 2018, 23, "http");
	Repository repo;
	repo.add(film1);
	repo.add(film2);
	assert(repo.get_movies().size() == 2);
}

void Test::remove_test() {
	Film film1("John", "Action", 2019, 23, "http");
	Film film2("Mike", "Action", 2018, 23, "http");
	Repository repo;
	repo.add(film1);
	repo.add(film2);
	repo.remove(film2);
	repo.remove(film1);
	assert(repo.get_movies().size() == 0);
}

void Test::repository_test() {
	find_film_test();
	add_test();
	remove_test();
}

void Test::testAll() {
	repository_test();
}

Test::Test()
{
}


Test::~Test()
{
}
