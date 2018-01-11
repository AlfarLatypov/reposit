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

class Quiz
{
public:
	int num = 1, otv = 0;
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

	void StartTest();

	////////////////



	friend int getMeI(bool arr[], int size);

};

int getMeI(bool arr[], int size) { // questions do not recur
	int w = rand() % 31;
	if (arr[w]) { getMeI(arr, size); }
	else  return w;
}

void Quiz::StartTest()
{
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

		case 0: return;

		}

		_getch(); test++; num++;

	}
}

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
		cout << "Введите имя: ";           cin >> nameUser;
	}
	
	void getUser() { cout << nameUser; }  //_getch();
	
	

};

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
				fin >> s; //name
				temp.nameUser = s;
				
				fin >> s; //password
				temp.pass = s;
				
				fin >> temp.is_new_user >> temp.rate; //new or old user and rating
				usersss.push_back(temp);
			}
		}
	}
	


	void printUsers() {
		cout << "\n\t\tРэйтинг Тестируемых\n\n\t\t Имя\tБаллы\n";
		sort(usersss.begin(), usersss.end(),
			[](const User & a, const User & b) -> bool
		{return a.rate > b.rate;});

		for_each(usersss.begin(), usersss.end(), [](User a)
		{ cout <<"\t\t"<< a.nameUser << "\t" << a.rate << "\n"; });

		//std::vector<User>::iterator it = usersss.begin();
		//*for (; it != x.end(); ++it)
		//	//{
		//	//	std::cout << *it << '\t';
		//	//}
		//	//std::cout << std::endl;*/
		//cout << "\n\t\t" << usersss.at(1).nameUser << "\n";// << usersss.at(1).pass
		//<< " " << usersss.at(1).is_new_user<< " " << usersss.at(1).rate;
	}
	
};

bool verification() {
	string name, vvod_pass;
	Rating usrs; //создали экземпляр класса Рэйтинг игроков
	usrs.retrieveUsers();// считали с файла всех игроков
	usrs.printUsers();
	/*cout << "\n\n\t\tВведите логин: "; cin >> name;
	cout << "\t\tВведите пароль: "; cin >> vvod_pass;*/

	//vector<User>::iterator it = usrs.usersss.begin(); cout << usrs.usersss.at(i).pass << "\n";
	int attemp = 0;
	while (attemp < 3) 
	{
		cout << "\n\n\t\tВведите логин: "; cin >> name;
		cout << "\t\tВведите пароль: "; cin >> vvod_pass;
				attemp++;

		for (int i = 0; i < usrs.usersss.size(); i++) 
			if (name == usrs.usersss.at(i).nameUser && vvod_pass == usrs.usersss.at(i).pass)return true;
					
	}
	return false;
}

void addNewUser() {

	cout << "Регистрация";
}

void START() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	
	//User new_user;
	//new_user.setUser();
	//new_user.getUser();
	Quiz quiz;
	quiz.retrieveQuestions();

	bool dopusk = verification();
	(dopusk) ? quiz.StartTest() : addNewUser();

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