#include <iostream>
#include "Ui.h"
#include "Repository.h"
#include "Controller.h"
#include "Test.h"
using namespace std;



int main() {
	//Test test;
	//test.testAll();

	Repository repo;
	Controller contr(repo);
	Ui ui(contr);
	ui.choose_menu();
	vector <Film> l = repo.get_movies();
	

	
	return 0;
}