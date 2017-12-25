#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <functional>
#include <time.h>

using namespace std;

//class comparator {
//public:
//	bool operator()(int x, int y) {
//		return x < y;
//	}
//};
//
//
//
//
//
//
//void main() {
//	//srand(time(NULL));
//	std::vector<int> x{ 1,3,3,3,2,3,3,4,5,4 };
//	//std::vector<int> x;
//	x.reserve(30);
//	int s = 10;
//
//	//x.assign(s, rand() % 10); //assign - zapolnyaet vector
//	cout << "\n\t\t\t\t  Size vector = " << x.size() << endl; //x.size() - pokajet razmer reserva - razmer vectora
//	cout << "\n Vector ";
//	for_each(x.begin(), x.end(), [](int & a)
//	{
//		//a = rand() % 90+10; 
//		cout << "\t[" << a << "] ";
//	});
//	cout << "\n\n";
//
//
//
//	cout << " Sort greater";
//	sort(x.begin(), x.end(), std::greater<int>()); //less (po vozrastaniu), greater(po ubuvaniu) //std::greater<int>()
//	for_each(x.begin(), x.end(), [](int & a) {cout << "\t[" << a << "] "; });
//
//	cout << "\n Sort less";
//	sort(x.begin(), x.end(), less<int>()); //less (po vozrastaniu), greater(po ubuvaniu) //std::greater<int>()
//	for_each(x.begin(), x.end(), [](int & a) {cout << "\t[" << a << "] "; });
//
//	std::vector <int> ::iterator it1 = x.begin();
//	std::vector <int> ::iterator it2 = x.begin() + x.size() - 1;
//	cout << "\n\n Minimum =      [" << *it1 << "]";
//	cout << "\n Maximum =      [" << *it2 << "]\n";
//
//	cout << "\n Minimum = " << *min_element(x.begin(), x.end());
//	cout << "\n Maximum = " << *max_element(x.begin(), x.end());
//	cout << "\n\n";
//	int n = 10, nn = 3;
//	for_each(x.begin(), x.end(), [n](int & a) {a += n; }); //uvelichili kajdui element na 10
//	for_each(x.begin(), x.end(), [nn](int & a) {a -= nn; });//umenshili kajdui element na 3
//	x.erase(x.begin() + nn); cout << "\n";//udalili element s indexom 3
//	for_each(x.begin(), x.end(), [](int & a) {cout << "\t[" << a << "] "; });
//	x.erase(x.begin() + 4); cout << "\n"; //udalili element s indexom 4
//	for_each(x.begin(), x.end(), [](int & a) {cout << "\t[" << a << "] "; });
//
//	std::vector<int>::iterator finder;
//	finder = find(x.begin(), x.end(), 10);
//	if (finder != x.end()) {
//		std::cout << "\n\n\tElement found in vector X: " << *finder << '\n';
//		x.erase(finder);
//
//	}
//	else
//		std::cout << "\n\n\tElement not found in vector X!\n";
//	for_each(x.begin(), x.end(), [](int & a) {cout << "\t[" << a << "] "; });
//
//
//	/*auto it = x.begin();
//	auto y = find(it, x.end(), 37);
//	while (it != x.end()) {
//
//	if (it != x.end()) {
//	x.erase(y);
//	it++;
//	}
//	}*/
//	cout << "\n\n\n";
//	x.erase(remove(x.begin(), x.end(), 10), x.end());
//	for_each(x.begin(), x.end(), [](int & a) {cout << "\t[" << a << "] "; });
//
//	x.erase(x.begin() + 1, x.begin() + 5);//udalyaet so vtorogo do pyatogo elementa
//	for_each(x.begin(), x.end(), [](int & a) {cout << "\t[" << a << "] "; });
//
//	cout << "\n\n\n";
//}



class Singleton {
public:
	static Singleton& getInstance() { // ¬озвращает ссылку на единственный экземпл€р
		static Singleton instance;  // Ёкземпл€р будет создан при первом же вызове
		return instance;
		// ј уничтожат его после выхода из main (конечно, если Instance вызывали хоть раз)
	};  
private:
	Singleton() {};   //  онструктор с нужной сигнатурой, скрыт от посторонних
	Singleton(const Singleton&) = delete;  // ќтключаем конструктор копировани€ (только объ€влен, описывать не надо)
	Singleton &operator = (const Singleton &) = delete;
	~Singleton(){}
};


void main() {
	Singleton& a = Singleton::getInstance();
	Singleton& b = Singleton::getInstance();
	Singleton& c = Singleton::getInstance();

	cout << &a << "\n" << &b << "\n" << &c << endl;

}