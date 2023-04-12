/****************************************************************
*                     КАФЕДРА № 304 2 КУРС                      *
*---------------------------------------------------------------*
* Project Type  : Win32 Console Application                     *
* Project Name  : CW1 3s-1c                                     *
* File Name     : CW1 3s-1c.cpp                                 *
* Language      : C/C++                                         *
* Programmer(s) : Новиков К.А.                                  *
* Modifyed By   :                                               *
* Lit source    :                                               *
* Created       : 16/12/2022                                    *
* Last Revision : 27/12/2022                                    *
* Comment(s)    : Курсовая работа списки.                       *
****************************************************************/

#include <iostream> //Вывод
#include <fstream> //Файлы
#include <Windows.h> //Виндовс
#include <climits> //Константы
#include <iomanip> //Вы,вод
#include <string> //Строки
#include <conio.h> //"Консоль"

#include "Struct.h"
#include "Menu.h"

using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    srand(time(nullptr));
    SetConsoleTitle(L"БД института");
    consoleCursorVisible(false);
    cout << "Начало работы программы" << endl;
    //test();

    InstituteNode institute = createInstitutesList();

    menuStop();
    char key;
    bool run = 1;
    system("CLS");
    printCommands();
    while (run) {
        consoleCursorVisible(false);
        key = _getch();
        //cout << "Код:" << (int)key << endl;

        switch (key) {
        case kESC:
            run = 0;
            break;
        case k1:
            menuReadFile(institute);
            break;
        case k2:
            menuWriteFile(institute);
            break;
        case k3:
            menuDeleteAll(institute);
            break;
        case k4:
            menuStudents(institute);
            break;
        case k5:
            menuRecords(institute);
            break;
        case k6:
            menuGroups(institute);
            break;
        case k7:
            menuFails( institute);
            break;
        default:
            break;
        }
    }
}