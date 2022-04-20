
#include<iostream>
#include<string>
#include<time.h>

using namespace std;


class Student {
		int age;
		string name;
		int num_grupp;
	public:
		void set_Age(int ageValue) {
			age = ageValue;
		}
		void set_Name(string nameValue) {
			name = nameValue;
		}
		void set_num_grupp(int num_gruppValue) {
			num_grupp = num_gruppValue;
		}
		void print() {
			cout << " Age " << age << "\n Name " << name << "\n Number " << num_grupp << endl;
		}
};

int main() {
	setlocale(LC_ALL, "RUS");
	
	Student student;

	student.set_Age(15);
	student.set_Name("ildar");
	student.set_num_grupp(10);
	student.print();

	return 0;
}