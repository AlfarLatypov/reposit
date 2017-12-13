#include <iostream>
#include <math.h>
#include <string>
using namespace  std;

class MyException : public exception {
public:
	virtual const char * what() const {
		return "Overfow exception!!";
	}

};


int convert(string s) {
	if (s.length() > 31) {
		throw MyException();
	}
		int res = 0, radix = 1;
		for (int i = s.length() - 1; i >= 0; i--) {
			res += radix * ((int)s[i] - 48);
			radix *= 10;
		}
		return res;
	
}


void main() {
	
	/*string a = "128";
	cout << convert(a) << endl;

	int x = stoi(a);
	cout << x << endl;*/
		
	try {
		convert("3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333");
	}
	catch (MyException e) {
		cout << e.what() << endl;
	}
}
























