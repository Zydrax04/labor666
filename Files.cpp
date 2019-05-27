
#include "Files.h"
#include <fstream>
#include "Repository.h"
using namespace std;

Files::Files()
{
}

Files::~Files()
{

}


// functie care printeaza continutul unui vector intr-un fisier in format csv
void CSV_Format::write_file(vector <Film> list)
{	
	ofstream fout(this->fileName);
	//open(my_file);
	for (int i = 0; i < list.size(); i++)
		fout << list[i].get_title() << "," << list[i].get_genre() << "," << list[i].get_year() << "," << list[i].get_likes() << "," << list[i].get_trailer() << endl;
	fout.close();
}

CSV_Format::CSV_Format(string fileName) {
	this->fileName = fileName;
}

HTML_Format::HTML_Format(string fileName) {
	this->fileName = fileName;
}

//  functie care printeaza continutul unui vector intr-un fisier in format html
void HTML_Format::write_file(vector <Film> list)
{
	ofstream fout(this->fileName);
	//open(my_file);
	fout << "<!DOCTYPE html> \n <html> \n <head> \n <title>Watchliste</title> \n </head> \n <body> \n <table border= \"1\"> \n <tr> \n <td>Titel</td> \n <td>Genre</td> \n <td>Jahr</td> \n <td>Likes</td> \n <td>Trailer link</td> \n </tr> \n ";
	for (int i = 0; i < list.size(); i++)
	{
		fout << "<tr>\n";
		fout << "<td>" << list[i].get_title() << "</td>\n";
		fout << "<td>" << list[i].get_genre() << "</td>\n";
		fout << "<td>" << list[i].get_year() << "</td>\n";
		fout << "<td>" << list[i].get_likes() << "</td>\n";
		fout << "<td><a href= \"" << list[i].get_trailer() << "\">Link</a></td>\n";
		fout << "</tr>";
	}
	fout << "</table>\n</body>\n</html>";
	fout.close();
}