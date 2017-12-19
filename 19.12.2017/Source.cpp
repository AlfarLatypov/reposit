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




#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string menu() {
	string path;
	cout << "\n\t\t\t Please enter name file - ";
	getline(cin, path);

	return path;
}



void main()
{

	int choice;
	string str, find, fpath = menu();
	size_t pos;

	while (true) {
		system("cls");
		cout << "\n\t--------------<< M E N U >>--------------\n";
		cout << "\n\t[ 1 ] - Push 1 to display the file on the screen"; //� ����������� ����� �� �����
		cout << "\n\t[ 2 ] - Push 2 to enter data into the file";  //� ������ ������ �� ����� ������ 
		cout << "\n\t[ 3 ] - Push 3 to add into file";  //� ��������� ������ � ���� 
		cout << "\n\t[ 4 ] - Push 4 to find in the file";  //� ����� �������� ������
		cout << "\n\t[ 5 ] - Push 5 to reverse the file";  //� ��������� ����������� �����
		cout << "\n\t[ 0 ] - Push 0 to EXIT";  //� EXIT



		cout << "\n\n\t     Your choice is - "; cin >> choice;

		ifstream fin(fpath);
		ofstream fout;

		switch (choice)
		{
		case 1:
			if (fin.is_open())
				while (getline(fin, str)) { system("cls"); cout << endl << endl << "\t\t" << str << endl << endl << endl << endl; } //� ����������� ����� �� �����
			else cout << "Ne otkruli";	 system("pause"); break;
		case 2: fout.open(fpath); cin >> str;//getline(cin, str);                     //� ������ ������ �� ����� ������ 
			if (fout.is_open()) { fout << str; }  break;
		case 3: fout.open(fpath, ios::app); cin >> str;                              //� ��������� ������ � ���� 
			if (fout.is_open()) { fout << str; }  break;
		case 4: system("cls");                                                      //� ����� �������� ������
			cout << "\n\t\twhat to look for? - "; cin >> find;
			pos = str.find(find);
			while (getline(fin, str)) { system("cls"); cout << endl << endl << "\t\t" << str << endl; }
			if (pos != string::npos) { cout << "\n\t\tFound at pos = " << pos + 1 << "\n"; system("pause"); }
			else { std::cout << "\n\t\tNot found\n"; system("pause"); }
			break;
		case 5: system("cls"); cout << "\n\t\t";
			for (int i = str.size() - 1; i >= 0; --i)
				std::cout << str[i]; cout << "\n\n"; system("pause"); break;
		case 0: fin.close(); fout.close(); return;

		}
	}
}


