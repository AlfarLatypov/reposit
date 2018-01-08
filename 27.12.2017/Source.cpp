#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <functional>
#include <fstream>
#include <time.h>

using namespace std;



///*Задание 1

//Есть файл с данными о названиях стран и городов.
//Реализуйте программу, которая позволит
//--загружать данные из файла,       (+)
//--сохранять данные в файл,         (+)
//--искать города конкретной страны, (+)
//--заменять название города,        (+)
//--добавлять города и страны,       (+)
//--удалять города и страны,
//--подсчитывать количество городов, (+)
//--отображать список стран.         (+)
//При программировании приложения обязательно исполь-
//зуйте механизм лямбд.*/
//
//
//_________________________________________________________________________________________________________________+





class City

{

public:

	std::string country;

	std::string name;

	City(std::string country, std::string name)

	{

		this->country = country;

		this->name = name;

	}

	friend std::ostream & operator <<(std::ostream & stream, City & city);

	friend bool operator == (const City & city1, const City & city2);





};

//peregruzili == dlyq sravneniya objectov

bool operator == (const City & city1, const City & city2)

{

	return city1.name == city2.name && city1.country == city2.country;

}







std::ostream & operator <<(std::ostream & stream, City & city) {

	return stream << city.country << ' ' << city.name << std::endl;

}



class Manager {

public:

	std::vector<City> cities;

	Manager() {

		//dobavlyaem goroda i strani

		City city("Russia", "Moscow");

		cities.push_back(city);

		City city1("Russia", "Omsk");

		cities.push_back(city1);

		City city2("Kazakhstan", "Almaty");

		cities.push_back(city2);

		City city3("Kazakhstan", "Astana");

		cities.push_back(city3);



	}

	void writeToFile() {

		std::ofstream out("countries.txt");

		std::for_each(cities.begin(), cities.end(), [&out](City & city)

		{

			if (out.is_open())

			{

				out << city;

			}

		});

		out.close();

	}

	void readFromFile() {

		std::ifstream in("countries.txt");

		if (in.is_open()) {

			while (in.eof()) {

				std::string s;

				std::getline(in, s);

				int position = s.find_first_of(' ');

				cities.push_back(

					City(

						std::string{ s.begin(), s.begin() + position },

						std::string{ s.begin() + position + 1, s.end() }

					)

				);

			}

		}

	}

	friend std::ostream & operator <<(std::ostream & stream, Manager & manager);







	//poisk po strane

	void filter(string &filter) {



		for_each(cities.begin(), cities.end(), [&filter](City & city)

		{

			if (filter == city.country)

				cout << "\t" << city.name; });



	}



	//starui sposob

	/*for (int i = 0; i < cities.size(); i++) {

	if (filter == cities.at(i).country) {

	cout << "\n" << cities.at(i).name << " ";

	}

	else cout << cities.at(i).name << endl;

	}*/





	//zamena goroda

	void remove(City &old, City &city_new) {

		std::replace(cities.begin(), cities.end(), old, city_new);



	}



};



std::ostream & operator <<(std::ostream & stream, Manager & manager) {

	std::for_each(manager.cities.begin(), manager.cities.end(), [&stream](City & city) {

		stream << city;

	});

	return stream;

}





int main() {

	// 1. sozdali

	Manager m;



	//2. zapisali v fail

	m.writeToFile();



	//3 .schitali s faila

	m.readFromFile();



	//4. vuvili na ikran ves spisok

	std::cout << "\n\t1) SPISOK STRAN I GORODOV:\n----------------------------------\n" << m << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";



	//5. ispol`zuem filter. Vivodim tolko goroda Rossii

	string f = "Russia";

	std::cout << "\n\t2) GORODA ROSSII:\n----------------------------------\n";

	m.filter(f);

	cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n 3) ZAMENILI OMSK NA ST.PETERBURG\n----------------------------------\n";



	//6. Gorod Omsk pomenyali na St.Petersburg

	City d1("Russia", "Omsk");

	City d2("Russia", "St.Petersburg");

	m.remove(d1, d2);

	m.filter(f);



	//7. Kol-vo gorodov

	cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\t4)  KOL-VO GORODOV = ";

	cout << m.cities.size() << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";





	//8. Spisok Stran

	cout << "\n\t 5) SPISOK STRAN:\n----------------------------------\n";



	for (int i = 0; i < m.cities.size() - 1; i++)

		if (m.cities.at(i + 1).country != m.cities.at(i).country)

			cout << "\t" << m.cities.at(i).country << "\n\t" << m.cities.at(i + 1).country;

	cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";







	return 0;

}

