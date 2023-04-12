#ifndef CW_ERROR_H
#define CW_ERROR_H

#include <iostream> //Вывод
#include <fstream> //Файлы
#include <Windows.h> //Виндовс
#include <climits> //Константы
#include <iomanip> //Вы,вод
#include <string> //Строки
#include <conio.h> //"Консоль"


void err_Lenght(int err);
void err_Syntax(int err);
void err_Type(int err);
void err_AmountData(int err);
void err_Number(int err);
void err_ChecksumNumber(int err);
void err_Surname(int err);
void err_Name(int err);
void err_Patronymic(int err);
void err_Institute(int err);
void err_Faculty(int err);
void err_Training(int err);
void err_Course(int err);
void err_Group(int err);
void err_Payment(int err);
void err_Year(int err);
void err_Department(int err);
void err_Date(int err);

void err_Gender(int err);
void err_Address(int err);
void err_Status(int err);

void err_Subject(int err);
void err_TeacherSurname(int err);
void err_TeacherName(int err);
void err_TeacherPatronymic(int err);
void err_Value(int err);
void err_Room(int err);

void err_ChecksumData(int err);

void err_UniqueGroup(int err);
void err_UniqueNumber(int err);
void err_UniqueSNA(int err);
void err_UniqueRoom(int err);

typedef void (*Err)(int err);

#endif