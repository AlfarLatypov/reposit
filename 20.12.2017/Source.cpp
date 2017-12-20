#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <string>
void Vector() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	std::vector <int> x(arr, arr + 10);
	std::vector <int> ::iterator it = x.begin(); // iterator íåîáõîäèì äëÿ áåãà ïî ìàññèâó, ÷òîá íå âûøåë èç äåàïàçîíà
	for (; it != x.end(); ++it)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;

}
void List() {
	std::cout << std::endl << "\n\n\n\n\t\t";
	int arr[10] = { 5,9,3,4,1,0,7,8,2,6 };
	std::list <int> y(arr, arr + 10);
	//auto it1 = y.begin();//begaet po massivu// ukazali otkuda nachat` bejat`
	y.sort();
	std::list<int>::iterator it1 = y.begin();//begaet po massivu// ukazali otkuda nachat` bejat`
	for (; it1 != y.end(); ++it1)
	{
		std::cout << *it1 << '\t';
	}
	std::cout << std::endl << std::endl << std::endl<<"\n\n\n";
}
void Map() {
	std::map <std::string, int> dictionary;
	dictionary.emplace(std::make_pair<std::string, int>("123", 1));
	std::cout << dictionary.at("123") << std::endl;
	auto it2 = dictionary.begin();
	for (; it2 != dictionary.end(); ++it2) {
		std::cout << it2->first << '\t' << it2->second << '\t';
	}
	std::cout << std::endl;

	dictionary.at("123") = 4; // prisvoili novoe znachenie
}
void Multimap() {
	std::multimap<std::string, int> dictionary1;
	dictionary1.insert(std::make_pair<std::string, int>("123", 1));
	dictionary1.insert(std::make_pair<std::string, int>("123", 5));
	std::cout << dictionary1.find("123")->first << std::endl;
	auto it2 = dictionary1.begin();
	for (; it2 != dictionary1.end(); ++it2) {
		std::cout << it2->first << '\t' << it2->second << '\t';
	}
	std::cout << std::endl;


}



int main() {

	//List();
	Multimap();
	return 0;
}