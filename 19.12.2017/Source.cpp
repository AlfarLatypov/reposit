//HOME WORK

////#include "stdafx.h"
//#include<iostream>
//#include<fstream>
//#include<string>
//
///*������� �23
//����: ������������ ����
//� ������ ���������� ��������������� � �������� ����-
//��� �� ������� ����� ������� �� ������ �� ����������� ������
//(������, ������� � �.�.).
//���������� ��� ��������� ������ � ������������� ����.
//���������� ���������� ��������� ��������� �����������.
//��������� �������� ����������� �������� ��� ��-������������ ����������� �������.*/
//
//
//using namespace std;
////���������� ��� ��������� ������ � ������������� ����. 
//namespace Alfar
//{
//
//	template< typename T >
//	class Node
//	{
//	public:
//		int value;
//		Node *prev, *next;
//
//		Node() {}
//		Node(const T value) {
//			this->value = value;
//			prev = next = NULL;
//		}
//		~Node();
//
//	};
//
//}
//
//namespace Latypov
//{
//	template< typename T >
//	class DoubleLinkedList
//	{
//	public:
//		Alfar::Node<T>*first, *last; //���������� Node ������������ ���� Alfar
//
//		DoubleLinkedList() {
//			first = last = NULL;
//		}
//
//		~DoubleLinkedList() {};
//
//		void AddToTail(const T &value) {
//			if (first == NULL) {
//				last = first = new Alfar::Node<T>(value);
//			}
//			else {
//				Alfar::Node<T> *temp = new Alfar::Node<T>(value);
//				last->next = temp;
//				temp->prev = last;
//				last = temp;
//			}
//		}
//
//		void DeleteFromTail() {
//			last->prev->next = NULL;
//			last = last->prev;
//		}
//
//		void AddToHead(const T & value) {
//			if (first == NULL) {
//				last = first = new Alfar::Node<T>(value);
//			}
//			else {
//				Alfar::Node<T> *temp = new Alfar::Node<T>(value);
//				first->prev = temp;
//				temp->next = first;
//				first = temp;
//			}
//
//		}
//
//		void DeleteFromHead() {
//			first = first->next;
//		}
//
//		void show() {
//			if (first == NULL) {
//				std::cout << "List is empty" << std::endl;
//			}
//			else {
//				for (Alfar::Node<T> * temp = first; temp != NULL; temp = temp->next)
//					std::cout << "\t" << temp->value << "\n";
//			}
//		}
//
//	};
//
//}
//
//
//
//void main() {
//
//	//���������� ���������� ��������� ��������� �����������. 
//	Latypov::DoubleLinkedList<int> *a = new Latypov::DoubleLinkedList<int>();
//
//
//	//��������� �������� ����������� �������� ��� ��-������������ ����������� �������.
//	a->AddToTail(2);
//	a->AddToTail(3);
//	a->AddToTail(4);
//	a->AddToTail(5);
//	a->AddToTail(6);
//	a->AddToHead(1);
//	a->show();
//	a->DeleteFromTail();
//	cout << endl;
//	a->show();
//	cout << endl;
//
//	a->DeleteFromHead();
//	cout << endl;
//	a->show();
//	cout << endl;
//
//	delete a;
//
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include<iostream>
//#include<fstream>
//#include<string>
//
//using namespace std;
///*������� �1
//���������� ���������, ������� ������������� �����������-
//����� �� ������ � �������.
//- ���������� �������� � ������������ ���� � �����,
//����� ���� ��������� ���������� ��������� �� ������� ����������� �����.
//����������� ����������:
//� ����� �������� ������ (�� ������ ���������� ����������
//������ ������ �� ����� �����);
//� ������ ������ �� ����� ������ (�� ������ �������� ��������-
//�� �� ������ ������);
//� ����������� ����� �� �����;
//� ��������� ����������� �����.
//����������� ��� ������ � ������� ������, � ��� ������ ��
//�������� ����� string*/
//
//string menu() {
//	string path;
//	cout << "\n\t\t\t Please enter name file - ";
//	getline(cin, path);
//
//	return path;
//}
//
//
//
//void main()
//{
//
//	int choice;
//	string str, find, fpath = menu();
//	size_t pos;
//
//	while (true) {
//		system("cls");
//		cout << "\n\t--------------<< M E N U >>--------------\n";
//		cout << "\n\t[ 1 ] - Push 1 to display the file on the screen"; //� ����������� ����� �� �����
//		cout << "\n\t[ 2 ] - Push 2 to enter data into the file";  //� ������ ������ �� ����� ������ 
//		cout << "\n\t[ 3 ] - Push 3 to add into file";  //� ��������� ������ � ���� 
//		cout << "\n\t[ 4 ] - Push 4 to find in the file";  //� ����� �������� ������
//		cout << "\n\t[ 5 ] - Push 5 to reverse the file";  //� ��������� ����������� �����
//		cout << "\n\t[ 0 ] - Push 0 to EXIT";  //� EXIT
//
//
//
//		cout << "\n\n\t     Your choice is - "; cin >> choice;
//
//		ifstream fin(fpath);
//		ofstream fout;
//
//		switch (choice)
//		{
//		case 1:
//			if (fin.is_open())
//				while (getline(fin, str)) { system("cls"); cout << endl << endl << "\t\t" << str << endl << endl << endl << endl; } //� ����������� ����� �� �����
//			else cout << "Ne otkruli";	 system("pause"); break;
//		case 2: fout.open(fpath); cin >> str;//getline(cin, str);                     //� ������ ������ �� ����� ������ 
//			if (fout.is_open()) { fout << str; }  break;
//		case 3: fout.open(fpath, ios::app); cin >> str;                              //� ��������� ������ � ���� 
//			if (fout.is_open()) { fout << str; }  break;
//		case 4: system("cls");                                                      //� ����� �������� ������
//			cout << "\n\t\twhat to look for? - "; cin >> find;
//			pos = str.find(find);
//			while (getline(fin, str)) { system("cls"); cout << endl << endl << "\t\t" << str << endl; }
//			if (pos != string::npos) { cout << "\n\t\tFound at pos = " << pos + 1 << "\n"; system("pause"); }
//			else { std::cout << "\n\t\tNot found\n"; system("pause"); }
//			break;
//		case 5: system("cls"); cout << "\n\t\t";
//			for (int i = str.size() - 1; i >= 0; --i)
//				std::cout << str[i]; cout << "\n\n"; system("pause"); break;
//		case 0: fin.close(); fout.close(); return;
//
//		}
//	}
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//#include<iostream>
//#include<fstream>
//#include<string>
//
//using namespace std;
///*������� �2
//�������� ���������� ���������� HTML-������.
//���������� ����������� � ������������ ���� � �����,
//����� ���� ��������� ���� �� ����������.
//��������� ���������� ��� ������ ������� �������� �������:
//��� �������� ���� ������ �����������,
//���� ��� ���� < ��� ������ ������� ���� >. �� ������ ���������
//����� ���������� ��������� �������� �� �����.
//����������� ��� ������ � ������� ������, � ��� ������ �� �������� ����� string.
//
//�������:
//���������� ��������� �����
//<html>
//<body>To be or not to be</body>
//</html>
//���������� ����������� �����
//<html>
//<body To be or not to be</body>
//</html>*/
//
//string menu() { //������������ ������ ��� ����� ���� ���������� � ��������� ����������
//	string path;
//	cout << "\n\t\t\t Please enter name file - ";
//	getline(cin, path);
//
//	return path;
//}
//
//
//void main() //������ �2
//{
//
//	int  open = 0, clouse = 0;
//	string str, fpath = menu();
//
//	ifstream fin(fpath); // ��������� �����
//
//	if (fin.is_open()) {
//		cout << "\n\t";
//		while (!fin.eof()) { getline(fin, str); cout << str << endl; } //����� �� ����� ����� � ��������� ������ � str � ������� �� �����
//		cout << "\n\t";
//	}
//	else cout << "Ne otkruli";
//
//
//	for (int i = 0; i < str.length(); i++) { //��������� ����� �� str � ������� ����
//		if (str[i] == '<')	open++;
//		if (str[i] == '>')	clouse++;
//	}
//
//	//���� ���-�� �������� ����� ����� ���-�� ��������, �� �� ��, ����� �� ��.
//	//������� ����� ���������� � ������� �������� �� ������ �������� �����, � ������ ������� ��� � ">" �� ����� ����������,
//	//� �� "<" �� ����� �������������, �� ��� ������ ������ �������.
//	(open == clouse) ? cout << "the Valid file. OK!\n\n" : cout << "NOT a Valid file. ERROR!" << endl;
//
//
//	ofstream fout; //�� ���� ����� ����� ������ ������������� � ����, �������� �� ��������� ���, ���� �������� ��� ����������
//	fout.open(fpath, ios::app); cin >> str;
//	if (fout.is_open()) { fout << str; }
//
//	fin.close(); fout.close();
//
//}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stream

//
//#include<iostream>
//#include<fstream>
//#include<string>
//
//using namespace std;
//
//class A {
//public:
//	int value;
//	friend std::ostream & operator << (std::ostream &stream, A& a);
//	friend std::istream & operator << (std::istream &stream, A& a);
//
//};
//
//std::ostream & operator << (std::ostream &stream, A& a)
//{
//	stream << a.value;
//	return stream;
//}
//
//std::istream & operator >> (std::istream &stream, A& a)
//{
//	stream >> a.value;
//	return stream;
//}
//
//int main() {
//	A a ;
//	/*a.value = 5;
//	std::ofstream fout;
//	fout.open("File.txt");
//	fout << a;
//	fout.close();*/
//
//	std::ifstream fin;
//	fin.open("File.txt");
//	fin >> a;
//	cout << a << endl;
//	fin.close();
//
//	return 0;
//}


//STRING

//#include<iostream>
//#include<fstream>
//#include<string>
//
//using namespace std;
//
//
//void main() {
//	string s, x ="123";
//	s += "hello"; //�������� � �����
//	swap(s, x);
//	reverse(s.begin(), s.end());
//	reverse(x.begin(), x.end());
//	cout << s << " " << x<<endl;
//
//
//}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//SMART POINTERS ����� ���������

//R A I I - ��������� � ������������ ��������������

/*auto_ptr � ����� ���������, ������� ��������� ��������, ���������� � ������� ��������� new � ������� ���� ������, 
����� auto_ptr ����� ���������. ������ ��������� ����� ���� ����������� � ����� ����������� ������������ ���������� 
��� ����������� ����������� ��������, ��� �������� �������� ����������� ���������� ��������� � ������� � ��� ����������� 
����������� ��������� �������� �� �������.
����������� auto_ptr �������� ��������� � �������� �������� ������� ����������: ����������� ����������� � ��������
������������ ������������ auto_ptr �������� ������ �������� ��������, ����� ������� "�����" ���������� �� ������ ���������. 
��-�� ����� ���������� ������� � ����������� auto_ptr �� ����� ���� ������� � ����������� ����������. 
��� ���� � ������ ����� ���������������� ������������ std::unique_ptr.*/


/*std::shared_ptr � ����� ���������, � ����������� ��������� �������� ����� ��� ���������. 
��������� ���������� shared_ptr ����� ������� ����� � ��� �� ��������; ������ ����� ���������, ����� ��������� shared_ptr,
����������� �� ����, ����� ��������� ��� �������. ������ ������������ � �������������� delete-expression ��� � ��������������
���������������� ������� �������� �������, ���������� � ����������� shared_ptr.

shared_ptr ����� �� ������� �� ����� ��������, � ���� ������ �� ���������� ������.
shared_ptr �������� ����������� CopyConstructible � CopyAssignable.

�������-�����
(�����������)
������� ����� shared_ptr
(public �������-����) [�������]
(����������)
��������� ������, ������� �������, ���� ������ ��� shared_ptrs ����������� �� ����
(public �������-����) [�������]
operator=
������ �������� shared_ptr
(public �������-����) [�������]
������������
reset
�������� ������, ������� �������
(public �������-����) [�������]
swap
����� ����������
(public �������-����) [�������]
�����������
get
���������� ��������� �� ����������� ������


(public �������-����) [�������]
operator*
operator->
�������������� ��������� �� ����������� ������


(public �������-����) [�������]
use_count
���������� ���������� �������� shared_ptr, ������� ��������� �� ��� �� ����������� ������
(public �������-����) [�������]
unique
���������, �������������� �� ����������� ������ ����������� ������� �������� shared_ptr
(public �������-����) [�������]
operator bool
���������, ��������� �� ��������� �� ������
(public �������-����) [�������]
owner_before
������������� ��������� �� ������ ������������ ����� ����������


(public �������-����)
*/

/*std::unique_ptr � ����� ���������, �������:

�������� ����������� �������� �������� ����� ��� ���������, �
��������� ������ ����� ��� ���������, ����� unique_ptr ������� �� ������� ���������.
unique_ptr �� ����� ���� ���������� ��� ����� ����� �������� ����������, ��� ���������� unique_ptr �� ����� 
��������� ����� � ��� �� ��������. ������������� unique_ptr ����� �������� �������� ����������� �������� ������� 
��������� unique_ptr. const std::unique_ptr �� ����� ���� �������, ����������� ����� ����� ������������ ������� ��������,
� ������� ��������� ��� ������. ����� unique_ptr ������������, �� ������� ������ � ������� Deleter.

���������� ��� ������ std::unique_ptr:

1) ��������� �������� ����� ������ �������, ��������, ���������� � ������� ��������� new

2) ��������� �������� ����� �������, � ������, ������������ �� ����� ����������, ���������� � ������� new[]

�������� ������ ���������� std::unique_ptr ��������:

����������� ������������ ���������� ��� ������� � �������, ������� ��������� ��������� � ������������ �������� �����,
���������� �������� � ������ ����������� ���������� � ���������� �� ����������
�������� �������� ����������� ��������� �������� � �������
��������� �������� ����������� ��������� �������� �� �������
� �������� ���� �������� � �����������, �������������� ��������� �����������, ����� ��� std::vector, ������� ������ 
��������� �� ����������� ���������� ������� (��������, ���� ���������� ����������� ���������)*/



//#include<memory>
//#include<iostream>
//using namespace std;
//
// class A {
//	public:
//		A() { cout << "\n     CREATE - A()" << endl; }
//		~A() { cout << "     DELETE - ~A()" << endl << endl << endl; }
//		int value;
//		
//	
//	};
//
// //��������� ����� ��� ����� �� �-���
//void auto_pt() {
//
//	auto_ptr<A> a(new A());
//	a->value = 5;
//	auto_ptr<A> b = a; //�� ���� ����������, ��� ������ � ����� ����� �, � ���������
//	cout << "\n\t" << b->value << endl << endl;
//}
//
////��������� ���� ��� � ������� ���-�� ������ �� ��������� �
//void shared_pt() {
//
//	shared_ptr<int> x(new int(5));
//	cout <<  "   Use pointer - "<<x.use_count() << endl << endl;
//	shared_ptr<int> y = x;
//	cout << "   Use pointer - " << y.use_count() << endl << endl;
//
//}
//
//
//void sum (shared_ptr<int> & x){
// cout << "   Use pointer - " << x.use_count() << endl << endl;
//}
//
//
//
//void unique_pt() {
//
//	unique_ptr<int> x(new int(5));
//	
//}
//
//void main() {
//	shared_ptr<int> bbb(new int(777));
//	auto_pt();
//	shared_pt();
//	sum(bbb);
//
//}


#include <algorithm>
#include <iostream>
#include <string>
#include <set>

//int main()
//{
//	std::string str = "apple";
//	std::sort(str.begin(), str.end());
//	std::cout <<"Povtoryaetsya bukva - "<< *std::unique(str.begin(), str.end());
//	std::cout << std::endl;
//}
//
//
int main() {
	std::string x = "1233";
	std::getline(std::cin, x);
	std::set<char> y;

	for (size_t i = 0; i < x.length(); ++i) {
		if (y.find(x[i]) != y.end()) {
			std::cout << "not unique" << std::endl;
			break;
		}
		else y.insert(x[i]);
	}
}


