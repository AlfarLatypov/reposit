// ConsoleApplication7.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <algorithm>
#include <string>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <fstream>
#include <time.h>

using namespace std;

int u;

//gotovo
class Question {
public:
	string quest;
	string var1, var2, var3, var4, right;
	int choice;

	Question() {}

	Question(string quest, string right, string var1, string var2, string var3, string var4) {
		this->quest = quest;
		this->right = right;
		this->var1 = var1;
		this->var2 = var2;
		this->var3 = var3;
		this->var4 = var4;
	}

	~Question() {}

};
//gotovo
class Quiz
{
public:
	int num = 1; float otv = 0;
	Question q;
	std::vector<Question> quizzz;
	bool repeat[31] = { false }; //kol-vo voprosov v faile

	Quiz() {}
	void retrieveQuestions() {

		ifstream fin("questions.txt");
		if (fin.is_open()) {
			string s;

			while (!fin.eof()) {
				getline(fin, s); //Question
				q.quest = s;

				getline(fin, s); //Answer
				q.right = s;

				getline(fin, s);//false or true variant
				q.var1 = s;

				getline(fin, s);//false or true variant
				q.var2 = s;

				getline(fin, s);//false or true variant
				q.var3 = s;

				getline(fin, s);//false or true variant
				q.var4 = s;

				quizzz.push_back(q);

			}

		}

	}

	////////////////
	int StartTest();
	////////////////

	friend int getMeI(bool arr[], int size);

};
//gotovo
int getMeI(bool arr[], int size) { // questions do not recur
	int w = rand() % 31;
	if (arr[w]) { getMeI(arr, size); }
	else  return w;
}
//gotovo
int Quiz::StartTest()
{
	const time_t timer = time(NULL);
	//cout << ("%s\n", ctime(&timer)); _getch();


	int test = 0;

	while (test < 10)
	{
		int i = getMeI(repeat, 31);
		repeat[i] = true;

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		system("CLS");  cout << "\t\tВопрос №" << num;
		SetConsoleTextAttribute(hConsole, 22);
		cout << "\n\t\t" << quizzz.at(i).quest;
		SetConsoleTextAttribute(hConsole, 7);
		cout << "\n\t\t1) - " << quizzz.at(i).var1 << "\n\t\t2) - "
			<< quizzz.at(i).var2 << "\n\t\t3) - " << quizzz.at(i).var3 << "\n\t\t4) - " << quizzz.at(i).var4;
		SetConsoleTextAttribute(hConsole, 22);
		cout << "\n\n\t\tНажмите [0] - ноль для выхода из программы!\n";
		SetConsoleTextAttribute(hConsole, 14);
		cout << "\n\t\tКоличество правильных ответов " << otv << " из 10\n\n";
		SetConsoleTextAttribute(hConsole, 7);
		cout << "\n\t\tYour choice - "; cin >> quizzz.at(i).choice;

		/////////////////////////////////////////////////////////////////////////////////////////////

		switch (quizzz.at(i).choice) {

		case 1:

			if (quizzz.at(i).var1 == quizzz.at(i).right) {

				otv++;

				system("CLS");  cout << "\t\tВопрос №" << num;

				SetConsoleTextAttribute(hConsole, 22);

				cout << "\n\t\t" << quizzz.at(i).quest;

				SetConsoleTextAttribute(hConsole, 2);

				cout << "\n\t\t1) - " << quizzz.at(i).var1;

				SetConsoleTextAttribute(hConsole, 15);

				cout << "\n\t\t2) - " << quizzz.at(i).var2 << "\n\t\t3) - " << quizzz.at(i).var3 << "\n\t\t4) - "

					<< quizzz.at(i).var4 << "\n";

				SetConsoleTextAttribute(hConsole, 22);

				cout << "\n\t\tНажмите [0] - ноль для выхода из программы!\n";

				SetConsoleTextAttribute(hConsole, 14);

				cout << "\n\t\tКоличество правильных ответов " << otv << " из 10\n\n";

				SetConsoleTextAttribute(hConsole, 2);

				cout << "\n\t\tПравильно!";

				SetConsoleTextAttribute(hConsole, 7);



			}

			else {

				system("CLS");  cout << "\t\tВопрос №" << num;

				SetConsoleTextAttribute(hConsole, 22);

				cout << "\n\t\t" << quizzz.at(i).quest;

				SetConsoleTextAttribute(hConsole, 12);

				cout << "\n\t\t1) - " << quizzz.at(i).var1 << "\t <- Ваш ответ!";

				SetConsoleTextAttribute(hConsole, 7);



				if (quizzz.at(i).var2 == quizzz.at(i).right) {

					SetConsoleTextAttribute(hConsole, 2);

					cout << "\n\t\t2) - " << quizzz.at(i).var2 << "\t <- Правильный ответ!";

					SetConsoleTextAttribute(hConsole, 7);

					cout << "\n\t\t3) - " << quizzz.at(i).var3;

					cout << "\n\t\t4) - " << quizzz.at(i).var4 << "\n";

					SetConsoleTextAttribute(hConsole, 22);

					cout << "\n\t\tНажмите [0] - ноль для выхода из программы!\n";

					SetConsoleTextAttribute(hConsole, 14);

					cout << "\n\t\tКоличество правильных ответов " << otv << " из 10\n\n";

				}

				if (quizzz.at(i).var3 == quizzz.at(i).right) {

					SetConsoleTextAttribute(hConsole, 7);

					cout << "\n\t\t2) - " << quizzz.at(i).var2;

					SetConsoleTextAttribute(hConsole, 2);

					cout << "\n\t\t3) - " << quizzz.at(i).var3 << "\t <- Правильный ответ!";

					SetConsoleTextAttribute(hConsole, 7);

					cout << "\n\t\t4) - " << quizzz.at(i).var4 << "\n";

					SetConsoleTextAttribute(hConsole, 22);

					cout << "\n\t\tНажмите [0] - ноль для выхода из программы!\n";

					SetConsoleTextAttribute(hConsole, 14);

					cout << "\n\t\tКоличество правильных ответов " << otv << " из 10\n\n";

				}

				if (quizzz.at(i).var4 == quizzz.at(i).right) {

					SetConsoleTextAttribute(hConsole, 7);

					cout << "\n\t\t2) - " << quizzz.at(i).var2;

					cout << "\n\t\t3) - " << quizzz.at(i).var3;

					SetConsoleTextAttribute(hConsole, 2);

					cout << "\n\t\t4) - " << quizzz.at(i).var4 << "\t <- Правильный ответ!\n";

					SetConsoleTextAttribute(hConsole, 22);

					cout << "\n\t\tНажмите [0] - ноль для выхода из программы!\n";

					SetConsoleTextAttribute(hConsole, 14);

					cout << "\n\t\tКоличество правильных ответов " << otv << " из 10\n\n";

					SetConsoleTextAttribute(hConsole, 7);

				}

				SetConsoleTextAttribute(hConsole, 12);

				cout << "\n\t\tНЕ Правильно!\n\n";

				SetConsoleTextAttribute(hConsole, 7);

			} break;

			//---------------------------------------------------------------------------------------------------------


		case 2: if (quizzz.at(i).var2 == quizzz.at(i).right) {

			otv++;

			system("CLS");  cout << "\t\tВопрос №" << num;

			SetConsoleTextAttribute(hConsole, 22);

			cout << "\n\t\t" << quizzz.at(i).quest;

			SetConsoleTextAttribute(hConsole, 15);

			cout << "\n\t\t1) - " << quizzz.at(i).var1;

			SetConsoleTextAttribute(hConsole, 2);

			cout << "\n\t\t2) - " << quizzz.at(i).var2;

			SetConsoleTextAttribute(hConsole, 15);

			cout << "\n\t\t3) - " << quizzz.at(i).var3 << "\n\t\t4) - " << quizzz.at(i).var4 << "\n";

			SetConsoleTextAttribute(hConsole, 22);

			cout << "\n\t\tНажмите [0] - ноль для выхода из программы!\n";

			SetConsoleTextAttribute(hConsole, 14);

			cout << "\n\t\tКоличество правильных ответов " << otv << " из 10\n\n";

			SetConsoleTextAttribute(hConsole, 2);

			cout << "\n\t\tПравильно!";

			SetConsoleTextAttribute(hConsole, 7);

		}

				else {

					system("CLS");  cout << "\t\tВопрос №" << num;

					SetConsoleTextAttribute(hConsole, 22);

					cout << "\n\t\t" << quizzz.at(i).quest;



					if (quizzz.at(i).var1 == quizzz.at(i).right) {

						SetConsoleTextAttribute(hConsole, 2);

						cout << "\n\t\t1) - " << quizzz.at(i).var1 << "\t <- Правильный ответ!";

						SetConsoleTextAttribute(hConsole, 12);

						cout << "\n\t\t2) - " << quizzz.at(i).var2 << "\t <- Ваш ответ!";

						SetConsoleTextAttribute(hConsole, 7);

						cout << "\n\t\t3) - " << quizzz.at(i).var3;

						cout << "\n\t\t4) - " << quizzz.at(i).var4 << "\n";

						SetConsoleTextAttribute(hConsole, 22);

						cout << "\n\t\tНажмите [0] - ноль для выхода из программы!\n";

						SetConsoleTextAttribute(hConsole, 14);

						cout << "\n\t\tКоличество правильных ответов " << otv << " из 10\n\n";

					}



					if (quizzz.at(i).var3 == quizzz.at(i).right) {

						SetConsoleTextAttribute(hConsole, 7);

						cout << "\n\t\t1) - " << quizzz.at(i).var1;

						SetConsoleTextAttribute(hConsole, 12);

						cout << "\n\t\t2) - " << quizzz.at(i).var2 << "\t <- Ваш ответ!";

						SetConsoleTextAttribute(hConsole, 2);

						cout << "\n\t\t3) - " << quizzz.at(i).var3 << "\t <- Правильный ответ!";

						SetConsoleTextAttribute(hConsole, 7);

						cout << "\n\t\t4) - " << quizzz.at(i).var4 << "\n";

						SetConsoleTextAttribute(hConsole, 22);

						cout << "\n\t\tНажмите [0] - ноль для выхода из программы!\n";

						SetConsoleTextAttribute(hConsole, 14);

						cout << "\n\t\tКоличество правильных ответов " << otv << " из 10\n\n";

					}

					if (quizzz.at(i).var4 == quizzz.at(i).right) {

						SetConsoleTextAttribute(hConsole, 7);

						cout << "\n\t\t1) - " << quizzz.at(i).var1;

						SetConsoleTextAttribute(hConsole, 12);

						cout << "\n\t\t2) - " << quizzz.at(i).var2 << "\t <- Ваш ответ!";

						SetConsoleTextAttribute(hConsole, 7);

						cout << "\n\t\t3) - " << quizzz.at(i).var3;

						SetConsoleTextAttribute(hConsole, 2);

						cout << "\n\t\t4) - " << quizzz.at(i).var4 << "\t <- Правильный ответ!\n";

						SetConsoleTextAttribute(hConsole, 7);

						SetConsoleTextAttribute(hConsole, 22);

						cout << "\n\t\tНажмите [0] - ноль для выхода из программы!\n";

						SetConsoleTextAttribute(hConsole, 14);

						cout << "\n\t\tКоличество правильных ответов " << otv << " из 10\n\n";

					}

					SetConsoleTextAttribute(hConsole, 12);

					cout << "\n\t\tНЕ Правильно!\n\n";

					SetConsoleTextAttribute(hConsole, 7);

				} break;



				//---------------------------------------------------------------------------------------------------------

		case 3: if (quizzz.at(i).var3 == quizzz.at(i).right) {

			otv++;

			system("CLS");  cout << "\t\tВопрос №" << num;

			SetConsoleTextAttribute(hConsole, 22);

			cout << "\n\t\t" << quizzz.at(i).quest;

			SetConsoleTextAttribute(hConsole, 15);

			cout << "\n\t\t1) - " << quizzz.at(i).var1;

			cout << "\n\t\t2) - " << quizzz.at(i).var2;

			SetConsoleTextAttribute(hConsole, 2);

			cout << "\n\t\t3) - " << quizzz.at(i).var3;

			SetConsoleTextAttribute(hConsole, 15);

			cout << "\n\t\t4) - " << quizzz.at(i).var4 << "\n";

			SetConsoleTextAttribute(hConsole, 22);

			cout << "\n\t\tНажмите [0] - ноль для выхода из программы!\n";

			SetConsoleTextAttribute(hConsole, 14);

			cout << "\n\t\tКоличество правильных ответов " << otv << " из 10\n\n";

			SetConsoleTextAttribute(hConsole, 2);

			cout << "\n\t\tПравильно!";

			SetConsoleTextAttribute(hConsole, 7);

		}

				else {

					system("CLS");  cout << "\t\tВопрос №" << num;

					SetConsoleTextAttribute(hConsole, 22);

					cout << "\n\t\t" << quizzz.at(i).quest;



					if (quizzz.at(i).var1 == quizzz.at(i).right) {

						SetConsoleTextAttribute(hConsole, 2);

						cout << "\n\t\t1) - " << quizzz.at(i).var1 << setw(25) << "\t <- Правильный ответ!";

						SetConsoleTextAttribute(hConsole, 7);

						cout << "\n\t\t2) - " << quizzz.at(i).var2;

						SetConsoleTextAttribute(hConsole, 12);

						cout << "\n\t\t3) - " << quizzz.at(i).var3 << setw(10) << "\t <- Ваш ответ!";

						SetConsoleTextAttribute(hConsole, 7);

						cout << "\n\t\t4) - " << quizzz.at(i).var4 << "\n";

						SetConsoleTextAttribute(hConsole, 22);

						cout << "\n\t\tНажмите [0] - ноль для выхода из программы!\n";

						SetConsoleTextAttribute(hConsole, 14);

						cout << "\n\t\tКоличество правильных ответов " << otv << " из 10\n\n";

					}



					if (quizzz.at(i).var2 == quizzz.at(i).right) {

						SetConsoleTextAttribute(hConsole, 7);

						cout << "\n\t\t1) - " << quizzz.at(i).var1;

						SetConsoleTextAttribute(hConsole, 2);

						cout << "\n\t\t2) - " << quizzz.at(i).var2 << setw(25) << "\t <- Правильный ответ!";

						SetConsoleTextAttribute(hConsole, 12);

						cout << "\n\t\t3) - " << quizzz.at(i).var3 << setw(15) << "\t <- Ваш ответ!";

						SetConsoleTextAttribute(hConsole, 7);

						cout << "\n\t\t4) - " << quizzz.at(i).var4 << "\n";

						SetConsoleTextAttribute(hConsole, 22);

						cout << "\n\t\tНажмите [0] - ноль для выхода из программы!\n";

						SetConsoleTextAttribute(hConsole, 14);

						cout << "\n\t\tКоличество правильных ответов " << otv << " из 10\n\n";

					}

					if (quizzz.at(i).var4 == quizzz.at(i).right) {

						SetConsoleTextAttribute(hConsole, 7);

						cout << "\n\t\t1) - " << quizzz.at(i).var1;

						cout << "\n\t\t2) - " << quizzz.at(i).var2;

						SetConsoleTextAttribute(hConsole, 12);

						cout << "\n\t\t3) - " << quizzz.at(i).var3 << setw(25) << "\t <- Ваш ответ!";

						SetConsoleTextAttribute(hConsole, 2);

						cout << "\n\t\t4) - " << quizzz.at(i).var4 << setw(25) << "\t <- Правильный ответ!\n";

						SetConsoleTextAttribute(hConsole, 22);

						cout << "\n\t\tНажмите [0] - ноль для выхода из программы!\n";

						SetConsoleTextAttribute(hConsole, 14);

						cout << "\n\t\tКоличество правильных ответов " << otv << " из 10\n\n";

						SetConsoleTextAttribute(hConsole, 7);

					}

					SetConsoleTextAttribute(hConsole, 12);

					cout << "\n\t\tНЕ Правильно!\n\n";

					SetConsoleTextAttribute(hConsole, 7);

				} break;

				//---------------------------------------------------------------------------------------------------------



		case 4: if (quizzz.at(i).var4 == quizzz.at(i).right) {

			otv++;

			system("CLS");  cout << "\t\tВопрос №" << num;

			SetConsoleTextAttribute(hConsole, 22);

			cout << "\n\t\t" << quizzz.at(i).quest;

			SetConsoleTextAttribute(hConsole, 7);

			cout << "\n\t\t1) - " << quizzz.at(i).var1;

			cout << "\n\t\t2) - " << quizzz.at(i).var2;

			cout << "\n\t\t3) - " << quizzz.at(i).var3;

			SetConsoleTextAttribute(hConsole, 2);

			cout << "\n\t\t4) - " << quizzz.at(i).var4 << "\n";

			SetConsoleTextAttribute(hConsole, 22);

			cout << "\n\t\tНажмите [0] - ноль для выхода из программы!\n";

			SetConsoleTextAttribute(hConsole, 14);

			cout << "\n\t\tКоличество правильных ответов " << otv << " из 10\n\n";

			SetConsoleTextAttribute(hConsole, 2);

			cout << "\n\t\tПравильно!";

			SetConsoleTextAttribute(hConsole, 7);

		}

				else {

					system("CLS");  cout << "\t\tВопрос №" << num;

					SetConsoleTextAttribute(hConsole, 22);

					cout << "\n\t\t" << quizzz.at(i).quest;



					if (quizzz.at(i).var1 == quizzz.at(i).right) {

						SetConsoleTextAttribute(hConsole, 2);

						cout << "\n\t\t1) - " << quizzz.at(i).var1 << setw(25) << "\t     <- Правильный ответ!";

						SetConsoleTextAttribute(hConsole, 7);

						cout << "\n\t\t2) - " << quizzz.at(i).var2;

						cout << "\n\t\t3) - " << quizzz.at(i).var3;

						SetConsoleTextAttribute(hConsole, 12);

						cout << "\n\t\t4) - " << quizzz.at(i).var4 << setw(15) << "    <- Ваш ответ!\n";

						SetConsoleTextAttribute(hConsole, 22);

						cout << "\n\t\tНажмите [0] - ноль для выхода из программы!\n";

						SetConsoleTextAttribute(hConsole, 14);

						cout << "\n\t\tКоличество правильных ответов " << otv << " из 10\n\n";

					}



					if (quizzz.at(i).var2 == quizzz.at(i).right) {

						SetConsoleTextAttribute(hConsole, 7);

						cout << "\n\t\t1) - " << quizzz.at(i).var1;

						SetConsoleTextAttribute(hConsole, 2);

						cout << "\n\t\t2) - " << quizzz.at(i).var2 << setw(25) << "\t <- Правильный ответ!";

						SetConsoleTextAttribute(hConsole, 7);

						cout << "\n\t\t3) - " << quizzz.at(i).var3;

						SetConsoleTextAttribute(hConsole, 12);

						cout << "\n\t\t4) - " << quizzz.at(i).var4 << "    <- Ваш ответ!\n";

						SetConsoleTextAttribute(hConsole, 22);

						cout << "\n\t\tНажмите [0] - ноль для выхода из программы!\n";

						SetConsoleTextAttribute(hConsole, 14);

						cout << "\n\t\tКоличество правильных ответов " << otv << " из 10\n\n";

					}

					if (quizzz.at(i).var3 == quizzz.at(i).right) {

						SetConsoleTextAttribute(hConsole, 7);

						cout << "\n\t\t1) - " << quizzz.at(i).var1;

						cout << "\n\t\t2) - " << quizzz.at(i).var2;

						SetConsoleTextAttribute(hConsole, 2);

						cout << "\n\t\t3) - " << quizzz.at(i).var3 << setw(25) << "\t <- Правильный ответ!";

						SetConsoleTextAttribute(hConsole, 12);

						cout << "\n\t\t4) - " << quizzz.at(i).var4 << "    <- Ваш ответ!\n";

						SetConsoleTextAttribute(hConsole, 22);

						cout << "\n\t\tНажмите [0] - ноль для выхода из программы!\n";

						SetConsoleTextAttribute(hConsole, 14);

						cout << "\n\t\tКоличество правильных ответов " << otv << " из 10\n\n";

					}

					SetConsoleTextAttribute(hConsole, 12);

					cout << "\n\t\tНЕ Правильно!\n\n";

					SetConsoleTextAttribute(hConsole, 7);

				} break;

				//---------------------------------------------------------------------------------------------------------

		case 0: return otv;

		}

		_getch(); test++; num++;

	}

	const time_t timer1 = time(NULL);
	//cout << ("%s\n", ctime(&timer)); _getch();
	int gameTime = (timer1 - timer);
	//************cout << gameTime<< "    "<< ((otv/ gameTime)*1000);
	return (otv / gameTime) * 1000;
}
//gotovo
class User
{
public:
	string nameUser;
	string pass;
	bool is_new_user = true;
	float rate = 0;

	User() {}
	User(string nameUser, string pass, bool is_new_user) {
		this->nameUser = nameUser;
		this->pass = pass;
		this->is_new_user = is_new_user;
	}

	~User() {}

	void setUser()
	{
		cout << "\n\t\tВведите имя: ";           cin >> nameUser;
		cout << "\n\t\tПридумайте пароль: ";     cin >> pass;
		is_new_user = false;
		rate = 0;
		system("cls");
	}

	string getUser() { return nameUser; }  //_getch();



};
//gotovo
class Rating
{
public:
	User temp;
	vector<User> usersss;

	void retrieveUsers() {
		ifstream fin("users.txt");
		if (fin.is_open()) {
			string s;

			while (!fin.eof()) {
				/*	fin >> s; //name
				temp.nameUser = s;

				fin >> s; //password
				temp.pass = s;

				fin >> temp.is_new_user >> temp.rate; //new or old user and rating
				usersss.push_back(temp);*/

				fin >> temp.nameUser >> temp.pass >> temp.is_new_user >> temp.rate;
				if (!(temp.nameUser == "1000000000" || temp.pass == "1000000000"))
					usersss.push_back(temp);
				temp.nameUser = "1000000000";
				temp.pass == "1000000000";
			}
			fin.close();
		}
	}

	bool SaveUseres() {
		ofstream fout;

		fout.open("users.txt");

		if (fout.is_open()) {

			for (int i = 0; i < usersss.size(); i++) {
				fout << usersss.at(i).nameUser << "\n" << usersss.at(i).pass << "\n"
					<< usersss.at(i).is_new_user << "\n" << usersss.at(i).rate << "\n";
			}
			fout.close();
		}
		else return false;

		return true;
	}

	void addNewUser(); //vunesena za class

	void printUsers() {
		cout << "\n\t   -= Рэйтинг Участников =-\n\t\t  Имя\tБаллы\n\t\t-----------------\n";
		sort(usersss.begin(), usersss.end(),
			[](const User & a, const User & b) -> bool
		{return a.rate > b.rate; });


		for_each(usersss.begin(), usersss.end(), [](User a)
		{ cout << "\t\t " << setw(5) << a.nameUser << "   " << setw(4) << a.rate << "\n"; });

		cout << "\t\t----------------- \n";

	}



};
//gotovo
bool verification() {
	string name, vvod_pass;
	Rating usrs; //создали экземпляр класса Рэйтинг игроков
	usrs.retrieveUsers();// считали с файла всех игроков


	int attemp = 0;
	while (attemp < 4)
	{
		system("cls");
		usrs.printUsers();
		cout << "\n\n\t\t   ~~~~~~~~~\n\t\t    В Х О Д\n\t\t   ~~~~~~~~~";
		if (attemp > 0) cout << "\n\tВы ввели не правильный логин или пароль! \n\t\tПопробуйте еще раз! ";
		if (attemp == 3)
		{
			system("cls");
			cout << "\n\n\n\n\t\t   Такого аккаунта Нет! \n\t\tПерейдите в раздел Регистрация! ";
			_getch(); system("cls");
			return false;
		}
		cout << "\n\n\t\tВведите логин: "; cin >> name;
		cout << "\t\tВведите пароль: "; cin >> vvod_pass;
		attemp++;

		for (int i = 0; i < usrs.usersss.size(); i++)
			if (name == usrs.usersss.at(i).nameUser && vvod_pass == usrs.usersss.at(i).pass)
			{
				u = i;	return true;
			}

	}

	return false;
}
//gotovo
class Oformlenie : public Rating {
public:

	void zastavka() {
		cout << "\n\tД О Б Р О  П О Ж А Л О В А Т Ь\n\t\t   В   Т Е С Т И Р О В Щ И К\n\t\t\t          Л А Т Ы П О В А! ";
		cout << "\n\n\t\t\tП р о в е р ь  с в о и  з н а н и я !"; _getch(); system("cls");

	}


	void registratsuya()
	{
		cout << "\n\n\t\t   ~~~~~~~~~~~~~~~~~~~~~~~\n\t\t    Р Е Г И С Т Р А Ц И Я\n\t\t   ~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	}
	void DobroPojalovat() {

		cout << "\n\n\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t\t   Поздравляем! \n\t    Регистрация прошла успешно!\n\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		retrieveUsers();
		printUsers(); _getch();
	}

	void Pristupim() {
		system("cls");
		cout << "\n\n\t\t   П Р И С Т У П И М !\n\n\t\tLoading  ";

		for (int i = 0; i < 600000000; i++) {
			if (i % 100000000 == 0) cout << '.';
		}
		system("cls");
	}

	int EnterOrRegistr() {
		int choice;
		cout << "\n\n\n\t\t\t\t-== В Х О Д ==-\n\t\t\t--== Р Е Г И С Т Р А Ц И Я ==-\n\t\t\t\t-== В Ы Х О Д ==-";
		cout << "\n\n\n\t\t"
			<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
			<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
			<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
			<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
			<< char(205) << char(205) << char(205);

		cout << "\n\n\t\tНажмите:\n\t\t\t[1] для входа \n\t\t\t[2] для регистрации нового пользователя\n\t\t\t[0] для выхода из программы";
		cout << "\n\n\t\t\tYour choice is - "; cin >> choice;
		//_getch();
		system("cls");
		return choice;
	}


};

//gotovo
void Rating::addNewUser() {

	User new_user;
	string new_name;
	Oformlenie r;
	r.registratsuya();
	new_user.setUser();
	new_name = new_user.getUser();
	cout << "\n\t\t      " << new_name;
	r.DobroPojalovat();
	//cout << usersss.size();
	usersss.push_back(new_user);
	//cout << usersss.size();
	system("cls");
	r.Pristupim();

	//SaveUseres();
}

void START() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	enum VHOD { ENTER = 1, REGISTR, EXIT };

	Oformlenie r;
	Quiz quiz;
	quiz.retrieveQuestions();
	Rating raiting;
	raiting.retrieveUsers();

	//**************quiz.StartTest();

	r.zastavka();
	//r.EnterOrRegistr();

	int choice, result = 0; bool dopusk;
	choice = r.EnterOrRegistr();

	switch (choice) {
	case ENTER: dopusk = verification();

		if (dopusk) {
			raiting.usersss.at(u).rate = quiz.StartTest();
			system("cls");
			cout << "\n\n\t\t    " << raiting.usersss.at(u).getUser();
			cout << "\n\tПоздравляем! Ваш результат - " << raiting.usersss.at(u).rate << "\n";
			raiting.printUsers();
			//raiting.SaveUseres();

			///////////////////////////////

			while (true) {
				_getch();
				system("cls");
				cout << "\n\n\n\t\t\tПовторим?\n\n\t\t\t 1) Д А\n\t\t\t 2) Н Е Т\n\n\n\t\t     Ваш выбор - ";
				cin >> choice;
				if (choice == 1) {
					quiz.otv = 0;
					quiz.num = 0;
					//raiting.usersss.at(u).rate = quiz.StartTest();
					//quiz.StartTest();

					//************************************
					raiting.usersss.at(u).rate = quiz.StartTest();
					system("cls");
					cout << "\n\n\t\t    " << raiting.usersss.at(u).getUser();
					cout << "\n\tПоздравляем! Ваш результат - " << raiting.usersss.at(u).rate << "\n";
					raiting.printUsers();


				}
				else {
					raiting.SaveUseres(); return;
				}
			}
			///////////////////////////////


		}
		else {
			raiting.addNewUser();  result = quiz.StartTest();
			system("cls");
			cout << "\n\n\t\t    " << raiting.usersss.at(raiting.usersss.size() - 1).getUser();
			cout << "\n\tПоздравляем! Ваш результат - " << result << "\n";
			raiting.usersss.at(raiting.usersss.size() - 1).rate = result;
			raiting.printUsers();
			//raiting.SaveUseres();

			///////////////////////////////

			while (true) {
				_getch();
				system("cls");
				cout << "\n\n\n\t\t\tПовторим?\n\n\t\t\t 1) Д А\n\t\t\t 2) Н Е Т\n\n\n\t\t     Ваш выбор - ";
				cin >> choice;
				if (choice == 1) {
					quiz.otv = 0;
					quiz.num = 0;
					//raiting.usersss.at(raiting.usersss.size() - 1).rate = 0;
					//quiz.StartTest();


					//************************************
					result = quiz.StartTest();
					system("cls");
					cout << "\n\n\t\t    " << raiting.usersss.at(raiting.usersss.size() - 1).getUser();
					cout << "\n\tПоздравляем! Ваш результат - " << result << "\n";
					raiting.usersss.at(raiting.usersss.size() - 1).rate = result;
					raiting.printUsers();

				}
				else {
					raiting.SaveUseres(); return;
				}
			}
		}
		///////////////////////////////

		break;

	case REGISTR:
		raiting.addNewUser();  result = quiz.StartTest();
		system("cls");
		cout << "\n\n\t\t\t" << raiting.usersss.at(raiting.usersss.size() - 1).getUser();
		cout << "\n\tПоздравляем! Ваш результат - " << result << "\n";
		raiting.usersss.at(raiting.usersss.size() - 1).rate = result;
		raiting.printUsers();
		//raiting.SaveUseres();

		///////////////////////////////

		while (true) {
			_getch();
			system("cls");
			cout << "\n\n\n\t\t\tПовторим?\n\n\t\t\t 1) Д А\n\t\t\t 2) Н Е Т\n\n\n\t\t     Ваш выбор - ";
			cin >> choice;
			if (choice == 1) {
				quiz.otv = 0;
				quiz.num = 0;
				//raiting.usersss.at(raiting.usersss.size() - 1).rate = 0;
				//quiz.StartTest();


				//************************************
				result = quiz.StartTest();
				system("cls");
				cout << "\n\n\t\t    " << raiting.usersss.at(raiting.usersss.size() - 1).getUser();
				cout << "\n\tПоздравляем! Ваш результат - " << result << "\n";
				raiting.usersss.at(raiting.usersss.size() - 1).rate = result;
				raiting.printUsers();
			}
			else {
				raiting.SaveUseres(); return;
			}
		}
		///////////////////////////////
		/*raiting.addNewUser(); result = quiz.StartTest(); raiting.SaveUseres();*/
		break;
	case EXIT:  raiting.SaveUseres(); return;
	}

	//system("cls");
	//cout <<"\n\n\t\t\t"<< raiting.usersss.at(raiting.usersss.size() - 1).getUser();
	//cout << "\n\tПоздравляем! Ваш результат - " << result << " из 10\n";

	/*raiting.usersss.at(raiting.usersss.size() - 1).rate = result;
	raiting.printUsers();
	raiting.SaveUseres();*/

	//quiz.StartTest();

	//raiting.printUsers();
	/*
	Quiz quiz;
	quiz.retrieveQuestions();
	quiz.StartTest();

	*/

}



void main() {

	START();
	//system("pause");
	cout << "\n\n\n";

}

