/*
Задание №1
Реализуйте класс “Студент”. Необходимо хранить в перемен-
ных-членах класса: ФИО, дату рождения, контактный телефон,
город, страну, название учебного заведения, город и страну (где
находится учебное заведение), номер группы. Реализуйте функ-
ции-члены класса для ввода данных, вывода данных, реализуйте
аксессоры для доступа к отдельным переменным-членам.
*/

#include<iostream>
#include<string>

using namespace std;

/// <summary>
/// Класс описывающий студента
/// </summary>
class Student {
		string surname;
		string name;
		string middleТame;
		string birthdate;
		string telefon;
		int numberGrupp;
	public:
		void setSurname(string value) {
			surname = value;
		}
		void setName(string value) {
			name = value;
		}
		void setMiddleТame(string value) {
			middleТame = value;
		}
		void setBirthdate(string value) {
			birthdate = value;
		}
		void setTelefon(string value) {
			telefon = value;
		}
		void setNumberGrupp(int value) {
			numberGrupp = value;
		}
		string getSurname() {
			return surname;
		}
		string getName() {
			return name;
		}
		string getMiddleТame() {
			return middleТame;
		}
		string getBirthdate() {
			return birthdate;
		}
		string getTelefon() {
			return telefon;
		}
		int getberGrupp() {
			return numberGrupp;
		}
		void print() {
			cout << "Фамилия " << surname << "\nИмя " << name << "\nОтчетсво " << middleТame 
				 << "\nДата рождения " << birthdate << "\nТелефон " << telefon << "\nНомер группы "
				 << numberGrupp;
		}
};

int main() {
	setlocale(LC_ALL, "RUS");
	
	Student student;

	student.setSurname("Ягудин");
	student.setName("Ильдар");
	student.setMiddleТame("Ришатович");
	student.setBirthdate("15/10/1986");
	student.setTelefon("+7373263104");
	student.setNumberGrupp(15);

	student.print();

	return 0;
}