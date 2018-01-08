#include <iostream>
#include <algorithm>
#include <string>
#include <windows.h> 
#include <conio.h> 

using namespace std;

class Question {
public:
	int choice, num = 1, otv = 0;
	string quest;
	string var1, var2, var3, var4, right;
	Question(){
		quest = "Кто вырос в джунглях среди диких зверей?";
		right = "Маугли";
		var1 = "Колобок";
		var2 = "Маугли";
		var3 = "Бэтмен";
		var4 = "Чарльз Дарвин";

	}

	~Question(){}
	void Start() {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//SetConsoleTextAttribute(hConsole, 12);
		cout << "\t\tВопрос №" << num;
		cout << "\n\t\t"<<quest << "\n\t\t1) - " << var1 << "\n\t\t2) - " 
			<< var2 << "\n\t\t3) - " << var3 << "\n\t\t4) - " << var4 << "\n";
		cout << "\n\t\tYour choice - "; cin >> choice;

		switch (choice) {
		case 1: if (var1 == right) { SetConsoleTextAttribute(hConsole, 2); cout << "\n\n\t\tПравильно!\n\n"; otv++; }
				else { SetConsoleTextAttribute(hConsole, 12); cout << "\n\n\t\tНЕ Правильно!\n\n"; } break;
		case 2: if (var2 == right) { SetConsoleTextAttribute(hConsole, 2); cout << "\n\n\t\tПравильно!\n\n"; otv++; }
				else { SetConsoleTextAttribute(hConsole, 12); cout << "\n\n\t\tНЕ Правильно!\n\n"; } break;
		case 3: if (var3 == right) { SetConsoleTextAttribute(hConsole, 2); cout << "\n\n\t\tПравильно!\n\n"; otv++; }
				else { SetConsoleTextAttribute(hConsole, 12); cout << "\n\n\t\tНЕ Правильно!\n\n"; } break;
		case 4: if (var4 == right) { SetConsoleTextAttribute(hConsole, 2); cout << "\n\n\t\tПравильно!\n\n"; otv++; }
				else { SetConsoleTextAttribute(hConsole, 12); cout << "\n\n\t\tНЕ Правильно!\n\n"; } break;
		}
	}

};


void main() {
	setlocale(LC_ALL, "RU");
	
	Question a;
	a.Start();
}