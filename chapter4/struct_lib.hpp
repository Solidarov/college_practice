#ifndef STRUCT_LIB
#define STRUCT_LIB

#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

struct Student {
    string name;
    int fLang;
    int advMath;
    int physics;
    int programming;
    string maxMark;

    Student(string n, int fl, int am, int ph, int pr) :
        name(n), fLang(fl), advMath(am), physics(ph), programming(pr){
            map <int, string> grades = {{fl, "Іноземна мова"}, {am, "Вища математика"}, {ph, "Фізика"}, {pr, "Програмування"}};
            maxMark = grades.rbegin() -> second;
        }
};

/*
    Шапка таблиці
*/
void Shapka();

/*
    Виводить на екран таблицю
*/
void OutTable();

/*
    Додає запис про студента до таблиці
*/
void NewStudent();

/*
    Видаляє запис по номеру
*/
void DelRow(int n);

/*
    Меню вибору
*/
void menu();

#endif