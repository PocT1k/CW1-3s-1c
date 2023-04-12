#ifndef CW_FUNCTIONS_H
#define CW_FUNCTIONS_H

#include <iostream> //Вывод
#include <fstream> //Файлы
#include <Windows.h> //Виндовс
#include <climits> //Константы
#include <iomanip> //Вы,вод
#include <string> //Строки
#include <conio.h> //"Консоль"
#include <ctime> //Время
#include <cstdio>  //Файлы

#include "Struct.h"
#include "Line.h"


void test();

void readLine(string& strLine, LineNode* line);
void readFileLine(istream& stream, InstituteNode& institute);
void readFromFile(InstituteNode& institute);

void writeNumber(ostream& stream, string* number);
void writeStudentLine(ostream& stream, StudentNode* node);
void writeRecordLine(ostream& stream, RecordNode* node);
void writeFailLine(ostream& stream, LineNode* node);
void writeToFile(InstituteNode& institute, int flag);

void createStydent(InstituteNode& institute);
void editStydent(InstituteNode& institute);
void deleteStydent(InstituteNode& institute);
void printStydent(InstituteNode& institute);

void createRecord(InstituteNode& institute);
void editRecord(InstituteNode& institute);
void deleteRecord(InstituteNode& institute);
void printRecord(InstituteNode& institute);

void deleteGroup(InstituteNode& institute);
void printGroup(InstituteNode& institute);

InstituteNode createInstitutesList();

#endif