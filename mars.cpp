#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
/*
 * Входные данные после 3 строки нужно принимать построчно, я принял одной строкой все описания кабелей.
 */
int main ()
{
    int countStations, countCabels;
    cin >> countStations;
    cin.get();

    char *t = new char[255]; // на время выделяется память (с запасом) под строку 
    cin.getline(t, 255); // чтение строки
        
    char *s = new char[strlen(t)]; // выделяется новая память под размер введённой строки
    strcpy(s, t); // копируется строка в новую память

    int N[countStations]; //numb - количество целых чисел в строке S
    istringstream ss(s);
    for(int i = 0; i < countStations; ++i)
        ss >> N[i];

    cin >> countCabels;
    cin.get();

    int summ = 0;
    if (countCabels > 0) {
        char *t = new char[255]; // на время выделяется память (с запасом) под строку 
        cin.getline(t, 255); // чтение строки
            
        char *s = new char[strlen(t)]; // выделяется новая память под размер введённой строки
        strcpy(s, t); // копируется строка в новую память

        const int numbCabels = countCabels;
        int cabels[numbCabels*3]; //numbCabels - количество целых чисел в строке S
        istringstream ss(s);
        for(int i = 0; i < numbCabels*3; ++i)
            ss >> cabels[i];

        for(int i = 0; i < numbCabels*3; i++) {
            //cabels[i] каждый первый элемент из троицы
            //N[cabels[i] - 1] обращение к цене станции
            if (N[cabels[i] - 1] > N[cabels[i]]) {//сравнение двух цен станций из троицы
                if (N[cabels[i] - 1] > cabels[i+2]) {
                    N[cabels[i] - 1] = cabels[i+2];
                }
            }
            if (N[cabels[i] - 1] < N[cabels[i]]) {//сравнение двух цен станций из троицы
                if (N[cabels[i]] > cabels[i+2]) {
                    N[cabels[i]] = cabels[i+2];
                }
            }
            i +=2;
        }
        
        for(int i = 0; i < countStations; ++i) {
            summ = summ + N[i];
        }
        cout << summ << endl; //вывод суммы
    } else {
        for(int i = 0; i < countStations; i++) {
            summ = summ + N[i];
        }
        cout << summ << endl;//вывод суммы
    }
    
    return 0;
}
