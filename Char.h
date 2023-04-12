#ifndef CW_CHAR_H
#define CW_CHAR_H

#include <iostream> //Вывод
#include <fstream> //Файлы
#include <Windows.h> //Виндовс
#include <climits> //Константы
#include <iomanip> //Вы,вод
#include <string> //Строки
#include <conio.h> //"Консоль"

using namespace std;


int getWordEnd(int num);
void deleteSpace(string& str);
string addZero(string str, int num);
string getStatus(string val);
string getValue(string val);
string getChecksum(string str);
string getNumber(string* str);
int compareString(string str1, string str2);
void copyNumber(string* from, string* to);
bool isDigit(char ch);
bool isBigRus(char ch);
bool isSmallRus(char ch);
bool checkNumber(char ch);
string toSmallRus(string str);
string toBigRus(string str);

#endif