#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <functional>
#include <array> 
#include <set>


using namespace std;

class A {
public:
	A() {
		cout << "A()" << endl;
	}
	A(int x) : value(x) {

	}
	~A() {
		cout << "~A()" << endl;
	}
	int value;
	friend std::ostream & operator << (std::ostream &stream, A& a);
	friend std::istream & operator << (std::istream &stream, A& a);
};

std::ostream & operator << (std::ostream &stream, A& a)
{
	stream << a.value;
	return stream;
}

std::istream & operator<<(std::istream & stream, A & a)
{
	stream >> a.value;
	return stream;
}

class Finder {
public:
	Finder(int y) : x(y){}
	int x;

	bool operator() (const A & a) {
		return a.value == x;
	}
};


template <class InputIterator1, class InputIterator2>
bool is_permutation(InputIterator1 first1, InputIterator1 last1,
	InputIterator2 first2)
{
	std::tie(first1, first2) = std::mismatch(first1, last1, first2);
	if (first1 == last1) return true;
	InputIterator2 last2 = first2; std::advance(last2, std::distance(first1, last1));
	for (InputIterator1 it1 = first1; it1 != last1; ++it1) {
		if (std::find(first1, it1, *it1) == it1) {
			auto n = std::count(first2, last2, *it1);
			if (n == 0 || std::count(it1, last1, *it1) != n) return false;
		}
	}
	return true;
}



//
//void main() {
//
//	//vector<A> x = { A(1),A(2),A(3)};
//	//int y = 2;
//	////cin >> y;
//	//Finder f(y); //functor
//	////std::vector<A>::iterator it = x.begin();
//	//*for (; it != x.end(); ++it)
//	//{
//	//	std::cout << *it << '\t';
//	//}
//	//std::cout << std::endl;*/
//		//for_each(x.begin(), x.end(), [](A a) { cout << a.value << " "; });
//	////auto a = find_if(x.begin(), x.end(), f);//functor
//		////auto b = find_if(x.begin(), x.end(), [y](A & a) { return a.value = y; });//lampda
//	////std::cout << *a << '\n' << *b << '\n';
//		////std::vector<A>::iterator it = std::find_if(x.begin(), x.end(), f);
//
//	
//	//http://www.cplusplus.com/reference/algorithm/is_permutation/?kw=is_permutation
//	
//	std::array<char, 5> first = { 'a','b','c','d','e' };
//	std::array<char, 5> second = { 'b','a','c','d','e' };
//	std::array<char, 5> third = { 'b','f','c','d','e' };
//
//	/*if (std::is_permutation(first.begin(), first.end(), second.begin()))
//		std::cout << "first and second arrays contain the same elements.\n";
//	else std::cout << "first and second arrays NOT contain the same elements.\n";*/
//	
//	
//	switch (true)
//	{
//	case 1:if (std::is_permutation(first.begin(), first.end(), second.begin()))
//		std::cout << "first and second arrays contain the same elements.\n";
//		   else std::cout << "first and second arrays NOT contain the same elements.\n";
//	case 2:if (std::is_permutation(second.begin(), second.end(), third.begin()))
//		std::cout << "first and second arrays contain the same elements.\n";
//		   else std::cout << "first and second arrays NOT contain the same elements.\n"; 
// break;
//	}
//
//
//	set<int> s;
//	unsigned size = vec.size();
//	for (unsigned i = 0; i < size; ++i) s.insert(vec[i]);
//	vec.assign(s.begin(), s.end());
//
//
//
//
//
//}



#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>


int main()
{
	// remove duplicate elements (normal use)
	std::vector<int> v{ 1,2,3,1,2,3,3,4,5,4,5,6,7 };
	std::sort(v.begin(), v.end()); // 1 1 2 2 3 3 3 4 4 5 5 6 7 
	auto last = std::unique(v.begin(), v.end());
	// v now holds {1 2 3 4 5 6 7 x x x x x x}, where 'x' is indeterminate
	v.erase(last, v.end());
	for (int i : v)
		std::cout << i << " ";
	std::cout << "\n";

	// remove consecutive spaces
	std::string s = "wanna go    to      space?";
	auto end = std::unique(s.begin(), s.end(), [](char l, char r) {
		return std::isspace(l) && std::isspace(r) && l == r;
	});
	// s now holds "wanna go to space?xxxxxxxx", where 'x' is indeterminate
	std::cout << std::string(s.begin(), end) << '\n';
}


