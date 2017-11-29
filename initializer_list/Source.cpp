#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Point {
public:
	int x, y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	
};


template<typename... T >
int check(T...args) {
	int cnt = 0;
	int r = 5;
	for (auto&& i : initializer_list<Point>{ args... }) {
		if (i.x * i.x + i.y *i.y <= r *r) {
			cnt++;
		}
	}return cnt;
}




void main() {
	cout <<
		check(Point{ 1,2 },
			Point{ 2,3 },
			Point{ 2,3 },
			Point{ 2,3 },
			Point{ 2,3 },
			Point{ 2,3 },
			Point{ 2,3 },
			Point{ 2,3 },
			Point{ 2,2 },
			Point{ 3,3 }) << endl;


}