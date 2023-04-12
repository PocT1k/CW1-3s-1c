#ifndef CW_MENU_H
#define CW_MENU_H

#include <iostream> //�����
#include <fstream> //�����
#include <Windows.h> //�������
#include <climits> //���������
#include <iomanip> //��,���
#include <string> //������
#include <conio.h> //"�������"

#include "Struct.h"
#include "Char.h"
#include "Functions.h"
#include "Console.h"

using namespace std;


void menuStop();
void printCommands();
void menuReadFile(InstituteNode& institute);
void menuWriteFile(InstituteNode& institute);
void menuDeleteAll(InstituteNode& institute);
void menuStudents(InstituteNode& institute);
void menuRecords(InstituteNode& institute);
void menuGroups(InstituteNode& institute);
void menuFails(InstituteNode& institute);

#endif