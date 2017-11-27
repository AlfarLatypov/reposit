//#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>


using namespace std;

//Джинерики - это шаблоны (generic template)  
//template <class T> //bez raznitsi
//template <typename T>

//
//template <typename T>
//T getAverageOfArrayElement(T a[], int size){
//	T sum = 0;
//	for (int i = 0; i < size; ++i) 
//		sum += a[i];
//	return sum / size;
//}
//
//
//
//void main() {
//
//	int a[5] = { 1,2,3,4,5 };
//	double b[5] = { 11.44,12.5,13.222,14.9,15.11111 };
//	float c[5] = { 6.2, 7.5, 8.9, 9.44, 10.3 };
//	char d[5] = { 'a','b','c','d','e' };
//
//	cout  << "\n\t\t\tint - " << setw(10) << getAverageOfArrayElement(a, 5) << endl;
//	cout  << "\n\t\t\tdouble - " << setw(10) << getAverageOfArrayElement(b, 5) << endl;
//	cout  << "\n\t\t\tfloat - " << setw(10) << getAverageOfArrayElement(c, 5) << endl;
//	cout  << "\n\t\t\tchar - " << setw(10) << (int)(getAverageOfArrayElement(d, 5)) << "\n\n\n\n";
//	
//}

/*Тема:​ ​Шаблоны​ ​функций  Задание. ​
​Реализуйте​ ​шаблонные​ ​функции​ ​для​ ​поиска​ ​
--максимума,​ ​
--минимума,​
​--сортировки​ ​массива (любым​ ​алгоритмом​ ​сортировки),​
--​поиска​ ​в​ ​массиве,​ ​
--замены​ ​элемента​ ​массива​ ​на переданное​ ​значение.
Бонус:
1) Написать​ ​перегруженные​ ​шаблоны​ ​функций​ ​для​ ​нахождения​ ​корней​
​линейного (a*x​ ​+​ ​b​ ​=​ ​0)​ ​и​ ​квадратного​ ​(a*x2+b*x​ ​+​ ​c​ ​=​ ​0)​ ​уравнений.
2) Хэш-таблица:​ ​написать​ ​реализацию​ ​с​ ​шаблоном.*/


//__________________________________________________________________________________________________________
//               MAXIMUM
template< typename T > //template functions for searching the maximum
T max(const T a, const T b)
{
	return a > b ? a : b; //returns a maximum of two
}

//void main() {   //main for this template (T max)
//	cout << max(1, 2) << endl;
//	cout << max('a', 'b') << endl;
//    max(("abc"), ("cde")) ? cout << "abc" << endl : cout << "cde" << endl;
//   system("pause");
//}


template <typename T>  //template functions for searching the maximum
T getMaxmumOfArrayElement(T a[], const int size) {
	if (size < 1) cout << "\n\t\tArray is emty\n\n\n";
	T max = a[0];
	for (int i = 0; i < size; ++i)
		if (max < a[i])
			max = a[i];
	return max;
}

//void main() {   //main for this template (T max)
//	int a[5] = { 11,24,3,41,5 };
//	char b[5] = { 'd','b','a','i','f' };
//	double c[5] = { 11.2,24.9,3.1,41.2,5.0 };
//	cout << "\n\t\t\tMAX    - " << setw(5) << getMaxmumOfArrayElement(a, 5) << endl;
//	cout << "\n\t\t\tMAX    - " << setw(5) << getMaxmumOfArrayElement(b, 5) << endl;
//	cout << "\n\t\t\tMAX    - " << setw(5) << (static_cast<float>(getMaxmumOfArrayElement(a, 5)))+0.2 << endl;
//	system("pause");
//}

//__________________________________________________________________________________________________________
//               MINIMUM

template <typename T>   //template functions for searching the maximum
T getMinimumOfArrayElement(T a[], const int size) {
	if (size < 1) cout << "\n\t\tArray is emty\n\n\n";
	T min = a[0];
	for (int i = 0; i < size; ++i)
		if (min > a[i])
			min = a[i];
	return min;
}

//void main() {   //main for this template (T min)
//	int a[5] = { 11,24,3,41,5 };
//	char b[5] = { 'd','b','a','i','f' };
//	double c[5] = { 11.2,24.9,3.1,41.2,5.0 };
//	cout << "\n\t\t\tMIN    - " << setw(5) << getMinimumOfArrayElement(a, 5) << endl;
//	cout << "\n\t\t\tMIN    - " << setw(5) << getMinimumOfArrayElement(b, 5) << endl;
//	cout << "\n\t\t\tMIN    - " << setw(5) << (static_cast<float>(getMinimumOfArrayElement(a, 5)))+0.1 << endl;
//	system("pause");
//}

//__________________________________________________________________________________________________________
//               SORT
//option 1
template <typename T>     //template functions for sort array
void getSortOfArrayElement(T a[], const int size) {
	if (size < 1) cout << "\n\t\tArray is emty\n\n\n";
	cout << "\n\t\t\t          ARRAY\n\t\t      ";
	for (int i = 0; i < size; i++)
		cout << setw(3) << " | " << a[i] << " ";
	cout << "|\n\t\t      ------------------------------\n\t\t\t           SORT";
	//-------------------------------------------------------
	for (int j = 0; j < size; ++j)
		for (int i = 0; i < size - 1; ++i)
			if (a[i] > a[i + 1])
				swap(a[i], a[i + 1]);
	cout << "\n\t\t      ";
	for (int i = 0; i < size; i++)
		cout << setw(3) << " | " << a[i] << " ";
	cout << "|\n\t\t      ------------------------------\n";
}


//void main() {   //main for this template (t sort)
//	int a[5] = { 11,24,3,41,5 };
//	char b[5] = { 'd','b','a','i','c' };
//	double c[5] = { 11.2,24.9,3.1,41.2,5.0 };
//	char d[] = "dabfc";
//
//	getSortOfArrayElement(d, strlen(d));
//	getSortOfArrayElement(a, 5);
//	getSortOfArrayElement(b, 5);
//	getSortOfArrayElement(c, 5);
//
//	system("pause");
//}

//option 2
template <typename T>  //template functions for sort array
void quicksort(T* a, int low, int high) { // (array, i[0], i[size-1])  //int a[5] = { 5, 1, 4, 3, 2 };
	int i = low, j = high;  //i = 0; j = 5-1=4
	T pivot = a[(low + high) / 2]; //T pivot = 0 + 4 = 4/2=2

	while (i <= j) {// while i <= j 
		while (a[i] < pivot) // while a[i] < pivot (2)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	if (low < j)
		quicksort(a, low, j);
	if (i < high)
		quicksort(a, i, high);
}


//void main() {   //main for this template (t sort)
//	int size = 5;
//	int a[5] = { 5, 1, 4, 3, 2 };
//	char b[5] = { 'd','b','a','i','c' };
//
//	quicksort(a, 0, size - 1); // (array, i[0], i[size-1])
//	quicksort(b, 0, size - 1); // (array, i[0], i[size-1])
//	
//	for (int i = 0; i < 5; ++i) 
//	cout << a[i] << " ";
//	cout << endl;
//	for (int i = 0; i < 5; ++i)
//		cout << b[i] << " ";
//	cout << endl;
//	system("pause");
//}

//__________________________________________________________________________________________________________
//               SEARCH

template <typename T>
T getFindOfArrayElement(T a[], int size, int x) {
	if (size < 1) cout << "\n\t\tArray is emty\n\n\n";
	cout << "\n\t\t";
	for (int i = 0; i < size; ++i)
		cout << a[i] << " ";
	cout << endl;



	for (int i = 0; i < size; ++i)
		if (x == a[i])
			cout << "\n\t\t" << a[i] << " is element No." << i + 1 << endl;
	cout << "\n\n\t"; return x;
	cout << "\n\t\t\t\t404 NOT FIND\n\n\n";


}

//void main() {   //main for this template (t find)
//	int a[5] = { 11,24,3,41,5 };
//  char b[5] = { 'd','b','a','i','c' };
//
//
//  getFindOfArrayElement(a, 5, 41);
//  getFindOfArrayElement(b, 5, 'a');
//}

//__________________________________________________________________________________________________________
//               Replacing an array element with a passed value

template <typename T>
T ReplacingOfArrayElement(T a[], int size, int x, int y) {
	if (size < 1) cout << "\n\t\tArray is emty\n\n\n";
	cout << "\n\t\t";
	for (int i = 0; i < size; ++i)
		cout << a[i] << " ";

	for (int i = 0; i < size; ++i)
		if (x == a[i]) a[i] = y;

	cout << "\n\t\t";
	for (int i = 0; i < size; ++i)
		cout << a[i] << " ";
	cout << endl;

	return x;
}

//void main() {   //main for this template (t replace)
//	  int a[5] = { 11,24,3,41,5 };
//	  char b[5] = { 'd','b','a','i','c' };
//	
//	
//	  ReplacingOfArrayElement(a, 5, 3, 777);
//	  ReplacingOfArrayElement(b, 5, 'a','A');
//	}

//__________________________________________________________________________________________________________
//  <<  B O N U S >> <<  B O N U S >> <<  B O N U S >> <<  B O N U S >> <<  B O N U S >> <<  B O N U S >>

/* Бонус:
BONUS:
1) Написать​ ​перегруженные​ ​шаблоны​ ​функций​ ​для​ ​нахождения​ ​корней​
​линейного(a*x​ ​ + ​ ​b​ ​ = ​ ​0)​ ​и​ ​квадратного​ ​(a*x2 + b*x​ ​ + ​ ​c​ ​ = ​ ​0)​ ​уравнений.
1) Write overloaded function templates to find the roots
Linear (a * x + b = 0) and square (a * x2 + b * x + c = 0) equations.
2) Хэш - таблица:​ ​написать​ ​реализацию​ ​с​ ​шаблоном.
2) Hash table: write an implementation with a template.
*/

//__________________________________________________________________________________________________________
//                   The linear equation (a * x + b = 0)
//​1) шаблоны​ ​функций​ ​для​ ​нахождения​ ​корней​ ​линейного(a*x​ ​ + ​ ​b​ ​ = ​ ​0) уравнения
//1) Templates of functions for finding the roots of the linear (a * x + b = 0) equation
template<typename T>
int line(const T &a, const T &b, T &x, bool &res) {
	if (a == 0) { return (res = false); } // NO ROOTS
	res = true;
	return (x = (-b) / a);
}

//void main() {   //main for this template (t linear (a * x + b = 0) equation)
//	int a, b, x1;  a = -2; b = 56; //integer
//	double c, d, x2; c = 12.5; d = 144.3;  //double
//	bool res;
//	
//	cout << line(a, b, x1, res) << endl; //integer
//	cout << line(c, d, x2, res) << endl; //double
//	system("pause");
//}

//__________________________________________________________________________________________________________
//                    The square equation (a * x2 + b * x + c = 0) 
//​1) шаблоны​ ​функций​ ​для​ ​нахождения​ ​корней​ квадратного​ ​(a*x2 + b*x​ ​ + ​ ​c​ ​ = ​ ​0)​ ​уравнения
//1) templates of functions for finding the roots of the square (a * x2 + b * x + c = 0) equation
template<typename T>
void square(const T &a, const T &b, const T &c, T &x1, T &x2) {
	const T D = (b*b) - (4 * a*c);

	if (D > 0)
	{
		x1 = ((-b) + sqrt(D)) / (2 * a);
		x2 = ((-b) - sqrt(D)) / (2 * a);
		cout << "x1 = " << x1 << "\n";
		cout << "x2 = " << x2 << "\n";
	}
	else if (D < 0)
	{
		cout << "NO ROOTS\n";
	}
	else
	{
		x1 = ((-b) + sqrt(D)) / (2 * a);
		cout << "x1 = " << x1 << "\n";
	}

}


//void main() {   //main for this template (t square (a * x2 + b * x + c = 0) equation)
//	//int a = -2, b = 5, c = 3, x1, x2;  //integer
//	double a = -2.56, b = 1000.24, c = 33.2, x1, x2;  //double
//
//	square(a, b, c, x1, x2); 
//	
//	system("pause");
//}


//__________________________________________________________________________________________________________

//2) Хэш - таблица:​ ​написать​ ​реализацию​ ​с​ ​шаблоном.
//2) Hash table : write an implementation with a template.




//__________________________________________________________________________________________________________
//27.11.2017





//template<typename T1, typename T2, >
//auto sum(T1 t1, T2 t2)-> decltype(T1 + T2) {
//
//	return t1 + t2;
//}
//
//void main() {
//
//	int x;
//	auto a = sum("123", 5);
//	decltype(x) y = 5; //объявить переменную "у" с таким же типом что и "х"
//	
//
//
//}

template<typename T >
class Matrix {
	T **arr;
	int height, width;
public:
	Matrix() {}
	Matrix(int height, int width) {
		this->height = height;
		this->width = width;
		arr = new T*[width];
		for (int i = 0; i < width; i++) {
			arr[i] = new T[height];
		}
	}
	~Matrix()
	{
		for (int i = 0; i < width; i++) {
			delete arr[i];
		}
		delete arr;
	}

	friend void randArr(Matrix<T> *&t);
	friend void print(Matrix<T> &t);


};



template<typename T >
inline void randArr(Matrix <T> *&t) {
	for (int i = 0; i < t->width; i++)
		for (int j = 0; j < t->height; j++)
			arr[i][j] = rand() % 100;
}

template<typename T >
void  print(Matrix <T> &t) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			cout << arr[i][j] << " ";
		} cout << endl;
	}
}




void main() {
	srand(time(NULL));
	auto x = 5;
	decltype(x) y = 5;

	Matrix <int> *Neo = new Matrix<int>(x, y);
	randArr(Neo);
	print(*Neo);


}


