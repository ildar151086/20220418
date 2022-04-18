/*
Текстовый файл состоит не более чем из 106 символов X, Y и Z.
Определите максимальное количество идущих подряд символов, среди которых каждые два соседних различны.
Для выполнения этого задания следует написать программу.
Ниже приведён файл, который необходимо обработать с помощью данного алгоритма.
*/
#include <iostream>
#include <fstream>


using namespace std;

/// сравниваем символы. Если разные то прибавляем к счетчику 1 
inline int compare(char readCh,  char previousCH, int countIndex) {
    return (readCh != previousCH) ? (countIndex + 1) : 1;
}

/// Максимальынй элемент из двуух чисел
inline int maxmially(int countIndex, int maxCount) {
    return (countIndex >= maxCount) ? countIndex : maxCount;
}

/// <summary>
/// Определяет максимальную последовательность символов
/// </summary>
/// <param name="fileRead">Файл для анализа</param>
/// <returns>Максимальная длина различных символов</returns>
int maxCountInFile(ifstream &fileRead) {
    int maxCount = 0;
    // Счетчик для хранения последовательности различных символов
    int countIndex = 1;

    char readCh = ' ';
    char previousCH = ' ';

    while (fileRead.get(readCh)) {  

        countIndex = compare(readCh, previousCH, countIndex);
        maxCount = maxmially(countIndex, maxCount);
        previousCH = readCh;

    }
    return maxCount;
}

int main() {
    setlocale(LC_ALL, "RUS");
    ifstream fileRead;

    fileRead.open("24_demo.txt");
    cout << "Максимальная последовательность : " << maxCountInFile(fileRead);

    // Закрываем файл
    fileRead.close();



    return 0;
}