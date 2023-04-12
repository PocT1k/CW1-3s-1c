#include "Error.h"

using namespace std;


string fileDam = ", ���� ��������";
void err_Lenght(int err) {
    if (err == 1) { cout << "������������� ������ ������" << fileDam; return; }
    cout << "�������������� ������ 1:" << err;
}
void err_Syntax(int err) {
    if (err == 1) { cout << "������������� ���������� �����" << fileDam; return; }
    cout << "�������������� ������ 2:" << err;
}
void err_Type(int err) {
    if (err == 1) { cout << "����������� ��� ������" << fileDam; return; }
    cout << "�������������� ������ 3:" << err;
}
void err_AmountData(int err) {
    if (err == 1) { cout << "������������� ���������� ������" << fileDam; return; }
    if (err == 2) { cout << "������������� ���������� ������" << fileDam; return; }
    if (err == 3) { cout << "������������� ���������� ������" << fileDam; return; }
    cout << "�������������� ������ 4:" << err;
}
void err_Number(int err) {
    if (err == 1) { cout << "������������ ������ �����" << fileDam; return; }
    cout << "�������������� ������ 5:" << err;
}
void err_ChecksumNumber(int err) {
    if (err == 1) { cout << "�� ��������� ����������� ����� ������� ������" << fileDam; return; }
    cout << "�������������� ������ 6:" << err;
}
void err_Surname(int err) {
    if (err == 1) { cout << "������� ���������� �� � ������� �����"; return; }
    if (err == 2) { cout << "� ������� ����������� ������������ �������"; return; }
    cout << "�������������� ������ 7:" << err;
}
void err_Name(int err) {
    if (err == 1) { cout << "����������� ���"; return; }
    if (err == 2) { cout << "��� ���������� �� � ������� �����"; return; }
    if (err == 3) { cout << "� ����� ������������ ������������ �������"; return; }
    cout << "�������������� ������ 8:" << err;
}
void err_Patronymic(int err) {
    if (err == 1) { cout << "�������� ���������� �� � ������� �����"; return; }
    if (err == 2) { cout << "� �������� ����������� ������������ �������"; return; }
    cout << "�������������� ������ 9:" << err;
}
void err_Institute(int err) {
    if (err == 1) { cout << "������������ ������ �������� ���������"; return; }
    if (err == 2) { cout << "������������ ��������"; return; }
    cout << "�������������� ������ 10:" << err;
}
void err_Faculty(int err) {
    if (err == 1) { cout << "������������ ������ �������� ����������"; return; }
    if (err == 2) { cout << "� ������ ���������� ����������� �� �����"; return; }
    if (err == 3) { cout << "������������ ����� ����������"; return; }
    cout << "�������������� ������ 11:" << err;
}
void err_Training(int err) {
    if (err == 1) { cout << "������������ ������� ����� ��������"; return; }
    if (err == 2) { cout << "������������ ������� ����� ��������"; return; }
    cout << "�������������� ������ 12:" << err;
}
void err_Course(int err) {
    if (err == 1) { cout << "������������ �������� �����"; return; }
    if (err == 2) { cout << "� ������ ����� ����������� �� �����"; return; }
    if (err == 3) { cout << "������������ �������� �����"; return; }
    cout << "�������������� ������ 13:" << err;
}
void err_Group(int err) {
    if (err == 1) { cout << "������������ ������ �������� ������ ������"; return; }
    if (err == 2) { cout << "� ������ ������ ������������ �� �����"; return; }
    if (err == 3) { cout << "������������ �������� ������ ������"; return; }
    cout << "�������������� ������ 14:" << err;
}
void err_Payment(int err) {
    if (err == 1) { cout << "������������ �������� ������������������������� ������"; return; }
    if (err == 2) { cout << "������������ �������� ������������������������� ������"; return; }
    cout << "�������������� ������ 15:" << err;
}
void err_Year(int err) {
    if (err == 1) { cout << "������������ ������ �������� ����"; return; }
    if (err == 2) { cout << "� �������� ���� ������������ �� �����"; return; }
    if (err == 3) { cout << "������������ �������� ����"; return; }
    cout << "�������������� ������ 16:" << err;
}
void err_Department(int err) {
    if (err == 1) { cout << "������������ ������ �������� ������ �������"; return; }
    if (err == 2) { cout << "� ������ ������� ����������� �� �����"; return; }
    if (err == 3) { cout << "������������ �������� ������ �������"; return; }
    cout << "�������������� ������ 17:" << err;
}
void err_Date(int err) {
    if (err == 1) { cout << "������������ �������� ������ ����"; return; }
    if (err == 2) { cout << "�� ���������� ����� ������ ����"; return; }
    if (err == 3) { cout << "� �������� ���� ����������� �� �����"; return; }
    if (err == 4) { cout << "������������ �������� ����"; return; }
    if (err == 5) { cout << "������������ �������� ������"; return; }
    if (err == 6) { cout << "������������ �������� ���"; return; }
    cout << "�������������� ������ 18:" << err;
}

void err_Gender(int err) {
    if (err == 1) { cout << "������������ ������ �������� ����"; return; }
    if (err == 2) { cout << "������������ �������� ����"; return; }
    cout << "�������������� ������ 19:" << err;
}
void err_Address(int err) {
    if (err == 1) { cout << "����������� �����"; return; }
    if (err == 2) { cout << "� �������� ������ ������������ ������������ �������"; return; }
    cout << "�������������� ������ 20:" << err;
}
void err_Status(int err) {
    if (err == 1) { cout << "������������ ������ �������� ������� ��������"; return; }
    if (err == 2) { cout << "� �������� ������� �������� ����������� �� �����"; return; }
    if (err == 3) { cout << "������������ �������� ������� ��������"; return; }
    cout << "�������������� ������ 21:" << err;
}

void err_Subject(int err) {
    if (err == 1) { cout << "���������� �������"; return; }
    if (err == 2) { cout << "� �������� �������� ����������� ������������ �������"; return; }
    cout << "�������������� ������ 22:" << err;
}
void err_TeacherSurname(int err) {
    if (err == 1) { cout << "������� ������������� ���������� �� � ������� �����"; return; }
    if (err == 2) { cout << "� ������� ������������� ������������ ������������ �������"; return; }
    cout << "�������������� ������ 23:" << err;
}
void err_TeacherName(int err) {
    if (err == 1) { cout << "���������� ��� �������������"; return; }
    if (err == 2) { cout << "��� ������������� ���������� �� � ������� �����"; return; }
    if (err == 3) { cout << "� ����� ������������� ������������ ������������ �������"; return; }
    cout << "�������������� ������ 24:" << err;
}
void err_TeacherPatronymic(int err) {
    if (err == 1) { cout << "�������� ������������� ���������� �� � ������� �����"; return; }
    if (err == 2) { cout << "� �������� ������������� ������������ ������������ �������"; return; }
    cout << "�������������� ������ 25:" << err;
}
void err_Value(int err) {
    if (err == 1) { cout << "� �������� ������ ����������� �� �����"; return; }
    if (err == 2) { cout << "������������ �������� ������"; return; }
    if (err == 3) { cout << "������������ �������� ������"; return; }
    cout << "�������������� ������ 26:" << err;
}
void err_Room(int err) {
    if (err == 1) { cout << "����������� ����� ���������"; return; }
    if (err == 2) { cout << "� ������ ��������� ������������ �� �����"; return; }
    cout << "�������������� ������ 27:" << err;
}

void err_ChecksumData(int err) {
    if (err == 1) { cout << "�� ��������� ����������� ����� ���� ��������" << fileDam; return; }
    cout << "�������������� ������ 28:" << err;
}

void err_UniqueGroup(int err) {
    if (err == 1) { cout << "� ���������� ����� ������ ������, ���������� ����� ��������"; return; }
    if (err == 2) { cout << "� ���������� ����� ������ ������, ���������� ������������������������� ������"; return; }
    if (err == 3) { cout << "� ���������� ����� ������ ������, ���������� ��� �����������"; return; }
    if (err == 4) { cout << "� ���������� ����� ������ ������, ���������� �������"; return; }
    cout << "�������������� ������ 29:" << err;
}
void err_UniqueNumber(int err) {
    if (err == 1) { cout << "������������ � ����� ���������� ������� ��� ����������" << fileDam; return; }
    cout << "�������������� ������ 30:" << err;
}
void err_UniqueSNA(int err) {
    if (err == 1) { cout << "� ����� ������ �� ����������� ������� ��������� � ����������� ���"; return; }
    cout << "�������������� ������ 31:" << err;
}
void err_UniqueRoom(int err) {
    if (err == 1) { cout << "� ���������� ���������� ������ ������, ���������� ����"; return; }
    if (err == 2) { cout << "� ���������� ���������� ������ ������, ���������� �������"; return; }
    if (err == 3) { cout << "� ���������� ���������� ������ ������, ���������� ������� �������������"; return; }
    if (err == 4) { cout << "� ���������� ���������� ������ ������, ���������� ��� �������������"; return; }
    if (err == 5) { cout << "� ���������� ���������� ������ ������, ���������� �������� �������������"; return; }
    cout << "�������������� ������ 32:" << err;
}