#pragma once
#include <iostream>
#include "Controller.h"
#include "Domain.h"
#include "Files.h"
using namespace std;

class Ui
{
private:
	Controller contr;
public:
	Ui(const Controller& contr);
	//Ui();

	Film read_film_data();
	Film read_existing_film();

	void add();
	void remove();
	void modify();
	void see_all_movies();
	void print_menu();
	void print_client_menu();
	void client_menu();
	void admin_menu();
	void delete_client_movie();
	void watch_list();
	void see_CSV_watch_list();
	void see_html_watch_list();
	void choose_menu();
	void admin_movies();
	void user_movies();

	~Ui();
};