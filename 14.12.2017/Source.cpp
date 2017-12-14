#include <cereal/types/unordered_map.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/archives/binary.hpp>

#include <cstring>
#include <string>
#include <iostream>
#include <conio.h>  //���������� ���������� �-��� ���� � ����
#include <fstream> //���������� ���������� �-��� ������ � �������
using namespace std;


//enum MENU { FILL = 1, SHOW};
//
//class Point {
//public: 
//
//	int x, y;
//
//	Point() {} 
//	Point(int _x, int _y) {
//		x = _x;
//		y = _y;
//	}
//		
//	//�-��� �������������
//	void init() { //����������� ���� ������ 
//		cout << endl;
//		cout << "Enter point x -\t"; cin >> x;
//		cout << "Enter point y -\t"; cin >> y;
//	}
//	inline void show() {
//		cout << endl;
//		cout << "Point x -\t" << x << endl;
//		cout << "Point y -\t" << y << endl;
//		_getch();
//	}
//
//	~Point() {} 
//};
//
//int Menu() {
//
//	cout << "\n\n\t\t------------<< M E N U >>---------------\n";
//	cout << "\n\t\tPress [1] to fill in the data"; //������� 1 ����� ��������� ������ 
//	cout << "\n\t\tPress [2] to show the data"; //������� 2 ����� �������� ������ 
//	cout << "\n\t\tPress [0] to EXIT"; //������� 0 ��� ������
//	cout << "\n\n\t\t----------------------------------------\n";
//	cout << "\n\n\t\tYour choice is - ";
//	int choice;
//	cin >> choice;
//	return choice;
//
//	system("cls");
//}
//
////�-��� ��������� ��� ������ � ����
//bool Save(Point point1) {
//	ofstream fout;
//	fout.open("Point.txt");
//
//	if (fout.is_open()) {
//
//		fout << point1.x << " " << point1.y;
//
//		fout.close();
//	}
//	else return false;
//
//	return true;
//}
////�-���  ��������� ��� ������ �� �����
//Point init(Point point1) {
//	ifstream fin;
//	fin.open("Point.txt");
//	if (fin.is_open()) {
//
//		fin >> point1.x >> point1.y;
//		fin.close();
//	}
//	return point1;
//}
//
//void main() {
//	Point point1;
//	point1 = init(point1);
//
//	while (true) {
//		system("cls");
//		switch (Menu()) {
//		case FILL: system("cls"); point1.init(); _getch(); system("cls"); break;//������� �-��� ���������� ������ ��������
//		case SHOW: point1.show(); break;//������ ��������� ������ �������� �� �����
//		case 0:  system("cls");
//			if (Save(point1))
//				cout << "\n\n\n\n\t\t\t\t\tSAVED\n\n\n\n" << endl;
//			else
//				cout << "\n\n\n\n\t\t\t\t\tNOT SAVED\n\n\n\n" << endl;
//			_getch(); system("cls");
//
//			cout << "\n\n\n\n\t\t\t\t\tBYE!!!\n\t\t\t\t\t\tBYE!!!\n\n\n\n\n"; return;
//		}
//	}
//
//
//	system("pause");
//}

/////////////////////////////////////////////////////////////////////////////////////////////////

//void main() {
//	ifstream fin("file.txt");
//	string str;
//
//	if (fin.is_open()) {
//		while (getline(fin,str))
//		{
//		cout << endl << endl << str << endl << endl << endl << endl;//t >> str;
//		}
//	} fin.close();
//		
//	
//	getline(cin, str);
//		ofstream fout;
//		fout.open("file.txt");
//		//fout.open("file.txt", ios::app);
//	
//		if (fout.is_open()) {
//			
//			fout << str ;
//		}
//	fout.close();
//	//////////////////////////////////////////////////////////////	
//	/*ofstream o;
//	string s;
//	while (getline(cin, str)) {
//		if (str != "exit") {
//			o << s;
//		}
//		else break;
//	} o.close();
//	cout << endl << endl << s << endl;*/
//}
//t.eof



struct MyRecord //���� ������ 
{
	uint8_t x, y; //��� ���� 8�� ������  (������� 32 ����)
	float z; // ���� ���� 

	template <class Archive>
	void serialize(Archive & ar) //���� ����� ��������� � ������� �������� ����� (����� ��� ������)
	{
		ar(x, y, z);
	}
};

struct SomeData // ����� �� ������
{
	int32_t id;
	std::shared_ptr<std::unordered_map<uint32_t, MyRecord>> data; //��������� ��� � ������� ��� ������� (���� ��� 32 � �������� MyRecord)

	template <class Archive> 
	void save(Archive & ar) const //����� ���������� ������ 
	{
		ar(data);
	}

	template <class Archive>
	void load(Archive & ar) //����� �������� 
	{
		static int32_t idGen = 0; //���� ���������
		id = idGen++; //��� ������������� ������ � �����
		ar(data);
	}
};

int main()
{
	std::ofstream os("out.cereal", std::ios::binary); //�o���� ofstream � � �������� �������
 //cereal:: - ��� ���������, ����� BinaryOutputArchive �� �������� ������� ������ archive � ��������� ������ os
	cereal::BinaryOutputArchive archive(os); 

	SomeData myData;
	archive(myData);

	return 0;
}









