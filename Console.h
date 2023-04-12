#ifndef CW_CONSOLE_H
#define CW_CONSOLE_H

#include <iostream> //Вывод
#include <fstream> //Файлы
#include <Windows.h> //Виндовс
#include <climits> //Константы
#include <iomanip> //Вы,вод
#include <string> //Строки
#include <conio.h> //"Консоль"

#include "Char.h"

using namespace std;

#define kESC 27
#define kSPACE 32
#define kENTER 13
#define kBACKSPACE 8
#define k1 49
#define k2 50
#define k3 51
#define k4 52
#define k5 53
#define k6 54
#define k7 55
#define k8 56
#define k9 57
#define k0 58


string getLetter(char key);
void consoleCursorGoToXY(short x, short y);
void consoleCursorVisible(bool show);
void consoleCoutLetter(string let, short w, short h, short hStart = 0);
void consoleCoutMesage(string arr[], short w, short h, short hStart = 0);
void consoleClearLine();
void consoleSpace(int num);
int getConsole(string& strLine, short w, short h, int len, short hStart = 0);

#endif