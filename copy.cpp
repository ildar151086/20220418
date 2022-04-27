/*
Создайте класс Array (или используйте ранее созданный вами).
Класс Array – это класс динамического массива. Размер масси-
ва может быть передан в качестве параметра или задан с помо-
щью вызова функции-члена. Класс должен позволять заполнять
массив значениями, отображать содержимое массива, изменять
размер массива, сортировать массив, определять минимальное
и максимальное значение. Класс должен содержать набор кон-
структоров (конструктор копирования обязателен), деструктор.
*/


#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class ArrayT {
    int size;
    int minValue;
    int maxValue;
    int* pArr;
public:
    ArrayT(int size) {
        this->size = size;
        pArr = new int[size];
        for (int i = 0; i < size; i++) {
            *(pArr + i) = rand() % 10 + 1;
        }
        cout << "Выделили память" << endl;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << *(pArr + i) << " ";
        }
        cout << endl;
    }

    void minValueT() {
        int min = *pArr;
        for (int i = 1; i < size; i++) {
            if (min > *(pArr + i)) {
                min = *(pArr + i);
            }
        }
        cout << " Минимальный элемент " << min << endl;
    }
    void maxValueT() {
        int max = *pArr;
        for (int i = 1; i < size; i++) {
            if (max < *(pArr + i)) {
                max = *(pArr + i);
            }
        }
        cout << " Максимальный элемент " << max << endl;
    };

    ArrayT operator+ (ArrayT second) {
        int tempSize = this->size + second.size;
        ArrayT temp(1);

        int *summElements = new int[tempSize];

        for (int i = 0; i < this->size; i++) {
            *(summElements + i) = *(this->pArr + i);
        }

        for (int i = 0; i < second.size; i++) {
            *(summElements + this->size + i) = *(second.pArr + i);
        }
        
        //this->pArr = summElements;
        //this->size = tempSize;
        temp.pArr = summElements;
        temp.size = tempSize;

        //return *this;
        return temp;

    }

    //ArrayT operator= (ArrayT &second) {
    //    ArrayT *temp();
    //    temp->pArr = second.pArr;
    //    temp->size = second.size;

    //    return *temp;
    //}


    ~ArrayT() {
        delete[] pArr;
        cout << "Удалили память" << endl;
    }

};

int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(0));

    int sizeFirst = 100;

    ArrayT first(sizeFirst);
    first.print();
    first.maxValueT();
    first.minValueT();

    int sizeSecond = 100;

    ArrayT second(sizeSecond);
    second.print();
    second.maxValueT();
    second.minValueT();
    
    cout << "Суммарный массив " << endl;
    ArrayT tree(1);
    tree.print();
    tree = first + second;
    //tree = first;
    tree.print();

    return 0;
}
