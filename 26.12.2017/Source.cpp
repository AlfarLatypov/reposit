//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <list>
//#include <map>
//#include <string>
//#include <functional>
//#include <time.h>
//
//
///*Задание №1.
//В контейнере типа vector хранится набор целых чисел. Создай-
//те функторы для решения следующих задач:
//■ Поиск минимального значения; (+)
//■ Поиск максимального значения; (+)
//■ Сортировка данных по убыванию; (+)
//■ Сортировка данных по возрастанию; (+)
//■ Увеличение значений в контейнере на заданную константу; (+)
//■ Уменьшение значений в контейнере на заданную константу; (+)
//■ Удаление элементов из контейнера равных искомому значе- (+)
//нию.                                                       (+)
//Не забывайте использовать алгоритмы там, где это необходимо. (+)
//Задание №2                                              (+)
//Измените функторы из первого задания в шаблонные клас- (+)
//сы-функторов. Проверьте работу полученного решения на раз- (+)
//ных контейнерах с разным содержимым.                          (+)*/
//
//
//
//using namespace std;
//
//template <typename type>
//class Comparator_less { //klass sortirovki povozrastaniu
//public:
//	bool operator()(type x, type y) { //functor
//		return x < y;
//	}
//};
//
//template <typename type>
//class Comparator_greater { //klass sortirovki poubuvaniu
//public:
//	bool operator()(type x, type y) { //functor
//		return x > y;
//	}
//};
//
//template <typename type>
//class Finder_max { //klass poiska maximuma
//public:
//	Finder_max(type & storage) : max_value(storage) {}
//
//	void operator () (const type & value) { if (value > max_value) max_value = value; }
//
//	type & max_value;
//};
//
//template <typename type>
//class Finder_min { //klass poiska minimuma
//public:
//	Finder_min(type & storage) : min_value(storage) {}
//
//	void operator () (const type & value) { if (value < min_value) min_value = value; }
//
//	type & min_value;
//};
//
//
//template <typename type>
//class Vector_plus10 { //klass 
//public:
//	const type n = 10;
//	type & value;
//	Vector_plus10(type & a) : value(a) {}
//	type operator()(type value) { //functor + 10
//		return value + n;
//	}
//
//
//};
//
//
//
//
//
//void main() {
//	//srand(time(NULL));
//
//	std::vector<int> x{ 9,4,6,5,4,3,1,4,2,0 };
//	//std::vector<int> x;
//	x.reserve(30);
//	int s = 10;
//	int max_element = 0;
//	int min_element = 1000000000;
//
//	Comparator_less<int> functor_sort_less;
//	Comparator_greater<int> functor_sort_greater;
//	Vector_plus10<int> plus_10();
//
//	//x.assign(s, rand() % 10); //assign - zapolnyaet vector
//	cout << "\n\t\t\t\t  Size vector = " << x.size() << endl; //x.size() - pokajet razmer reserva - razmer vectora
//	cout << "\n Vector ";
//	for_each(x.begin(), x.end(), [](int & a)
//	{
//		//a = rand() % 90+10; 
//		cout << "\t[" << a << "] ";
//	});
//	cout << "\n\nSort less";
//
//
//	sort(x.begin(), x.end(), functor_sort_less);//ispolzuem functor dlya sortirovki po vozrastaniu
//	for_each(x.begin(), x.end(), [](int & a) {cout << "\t[" << a << "] "; });
//	cout << "\n\nSort greater";
//
//	sort(x.begin(), x.end(), functor_sort_greater);//ispolzuem functor dlya sortirovki po vozrastaniu
//	for_each(x.begin(), x.end(), [](int & a) {cout << "\t[" << a << "] "; });
//	cout << "\n\n";
//
//	std::for_each(x.begin(), x.end(), Finder_max<int>(max_element)); //ispolzuem functor dlya poiska maximuma
//	std::cout << "Max element     [" << max_element << "]\n";
//
//	std::for_each(x.begin(), x.end(), Finder_min<int>(min_element)); //ispolzuem functor dlya poiska minimuma
//	std::cout << "Min element     [" << min_element << "]\n\nVector + 10";
//
//	int n = 10, nn = 3;
//	for_each(x.begin(), x.end(), [n](int & a) {a += n;  cout << "\t[" << a << "] "; }); //uvelichili kajdui element na 10
//	std::cout << "\nVector - 3";
//
//	for_each(x.begin(), x.end(), [nn](int & a) {a -= nn; cout << "\t[" << a << "] "; });//umenshili kajdui element na 3
//	cout << "\n\nDelete index 0";
//
//	x.erase(x.begin() + 0); //udalili element s indexom 0
//	for_each(x.begin(), x.end(), [](int & a) {cout << "\t[" << a << "] "; });
//	cout << "\nDelete value = 11 ";
//	x.erase(remove(x.begin(), x.end(), 11), x.end()); //udalili element = 11
//	for_each(x.begin(), x.end(), [](int & a) {cout << "\t[" << a << "] "; });
//	cout << "\n\n\n\n";
//		
//}



#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <functional>
#include <time.h>
using namespace std;
//*Задание 2
//Есть файл с данными о названиях стран и городов.
//Реализуйте программу, которая позволит
//--загружать данные из файла,
//--сохранять данные в файл,
//--искать города конкретной страны,
//--заменять название города,
//--добавлять города и страны,
//--удалять города и страны,
//--подсчитывать количество городов,
//--отображать список стран.
//При программировании приложения обязательно используйте механизм лямбд.*/



class City {
public:
	string name;
	City() {}
	~City() {}

};



class Country : public City {
public:
string Country_name;
class goroda {
	public:
		string Country;
		goroda(string &Country) {
			this->Country = Country;}
			~goroda() {}
};
	vector<goroda> *Citys;
	Country() {
		Citys = new vector<goroda>();
		Citys->reserve(20);}
		~Country() {}
	void addGoroda(string value) {
		this->Country_name = value;
		Citys->push_back(*(new goroda(value)));
}
	
	void printgoroda(Country *Country) {
		for (int i = 0; i < Country->Citys->size(); i++) {
			if (i < Country->Citys->size() - 1)
				cout << Country->Citys->at(i).Country << ", ";
			else cout << Country->Citys->at(i).Country << endl;
	}
		cout << endl;
	}
	friend void show(Country &);
};


inline void show(Country &Country) {
	cout << "\n\tCountry - " << Country.name
		<< "\n\tCitys - ";
		Country.printgoroda(&Country);
}




void main() {
	Country *a;
	a = new Country();
	a->name = "Kazakhstan";
	a->addGoroda("Almaty");
	a->addGoroda("Karaganda");
	a->addGoroda("Taraz");
	show(*a);

	delete a;

}