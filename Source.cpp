/*
К уже реализованному классу Student добавьте необходимые
конструкторы, сделайте ряд функций inline. Обязательно выделять память под ФИО
студента динамически, выделенную память необходимо освобо
ждать в деструкторе.
Реализуйте класс “Студент”. Необходимо хранить в перемен-
ных-членах класса: ФИО, дату рождения, контактный телефон,
город, страну, название учебного заведения, город и страну (где
находится учебное заведение), номер группы. Реализуйте функ-
ции-члены класса для ввода данных, вывода данных, реализуйте
аксессоры для доступа к отдельным переменным-членам. Добавьте конструкторы
*/

#include<iostream>
#include<string>

using namespace std;

class Student {
	string *name;
	string *birday;
	string *telefon;
	int *numderGrupp;
public:
	Student(string name, string birday, string telefon, int numderGrupp) {

		this->name = new string[name.length()];
		this->name = &name;

		this->birday = new string[birday.length()];
		this->birday = &birday;

		this->telefon = new string[telefon.length()];
		this->telefon = &telefon;

		this->numderGrupp = &numderGrupp;
	}
	void print() {
		cout << " ФИО " << name << " День рождения " << birday
			<< " Телефон " << telefon << " Номер группы " << numderGrupp << endl;
	}
	~Student() {
		cout << "Деструктор начало" << endl;
		
		delete this->name;
		delete this->birday;
		delete this->telefon;
		delete this->name;

		cout << "Деструктор конец" << endl;
	}

};


int main() {
	setlocale(LC_ALL, "RUS");

	Student student1("Ягудин", "15101986", "1234567", 55);


	student1.print();


	return 0;
}