#include "Char.h"

using namespace std;


int getWordEnd(int num) {
    if ((num % 10 <= 0) || (num % 10 >= 5)) {
        return 0;
    }
    if ((num % 10 == 1)) {
        return 1;
    }
    return 2;
    //0 �������
    //1 ������
    //2 ������
    //3 ������
    //4 ������
    //5 �������
    //6 �������
    //7 �������
    //8 �������
    //9 �������
}

void deleteSpace(string& str) {
    if (str[0] == ' ') {
        str.erase(str.find(' '), 1);
        deleteSpace(str);
    }
    if (str.length() != 0) {
        if (str[str.length() - 1] == ' ') {
            str = str.substr(0, str.length() - 1);
            deleteSpace(str);
        }
    }
    return;
}

string addZero(string str, int num) {
    if (str.length() < num) {
        str = '0' + str;
        str = addZero(str, num);
    }
    return str;
}

string getStatus(string val) {
    if (val == "1") {
        return "���������� ��������";
    }
    if (val == "2") {
        return "� ������������� �������";
    }
    if (val == "3") {
        return "�������� ��������";
    }
    if (val == "0") {
        return "��������";
    }
}

string getValue(string val) {
    if (val == "") {
        return "-";
    }
    if (val == "-") {
        return "-";
    }
    if (val == "0") {
        return "";
    }
    if (val == "1") {
        return "�/�";
    }
    if (val == "6") {
        return "�/�";
    }
    if (val == "7") {
        return "�/�";
    }
    else {
        return val;
    }
}

string getChecksum(string str) { //������� ��������� ����������� �����
    if (str.size() % 2 == 1) {
        str = str + 'm';
    }
    unsigned long long int sum = 0;
    int mul;
    int div;
    for (int i = 0; i < str.size(); i = i + 2) { //���������� � ����������� ����� ��������� ��������� ������� � ��������� �� ��������
        mul = str[i] * str[i + 1];
        div = str[i] / str[i + 1];
        sum = sum + mul + div;
        sum = sum % 1000000000000000000; //������������� ������������
    }
    while (sum % 10 == 0) { //������� ���� � �����
        sum = sum / 10;
    }
    sum = sum % 1000000; //��������� 6 ��������� ����
    str = to_string(sum);
    if (str.length() < 6) {
        str = addZero(str, 6); //��� ����� ������ 6 - ��������� �������� ����
    }
    return str;
}

string getNumber(string* str) {
    string number = "";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            number = number + str[i][j];
        }
    }
    return number;
}

int compareString(string str1, string str2) { //��������� ����� � ���������� �������
    int i = 0;
    while ((str1[i] != '\0') && (str2[i] != '\0')) {
        if (str1[i] > str2[i]) {
            return 1; //������ ������
        }
        if (str1[i] < str2[i]) {
            return 2; //������ ������
        }
        i++;
    }
    if (str1[i] == '\0') {
        return 2;
    }
    return 0; //����������
}

void copyNumber(string* from, string* to) { //������������� ������
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            to[i][j] = from[i][j];
        }
    }
}

bool isDigit(char ch) {
    if (('0' <= ch) && (ch <= '9')) {
        return 1;
    }
    return 0;
}

bool isBigRus(char ch) {
    if ((('�' <= ch) && (ch <= '�')) || (ch == '�')) {
        return 1;
    }
    return 0;
}

bool isSmallRus(char ch) {
    if ((('�' <= ch) && (ch <= '�')) || (ch == '�')) {
        return 1;
    }
    return 0;
}

bool checkNumber(char ch) {
    if (isDigit(ch) == 1) {
        return 1;
    }
    if (isBigRus(ch) == 1) {
        return 1;
    }
    if (ch == ' ') {
        return 1;
    }
    if (ch == '-') {
        return 1;
    }
    return 0; //����� �� ��������
}

string toSmallRus(string str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '�') {
            str[i] = '�';
        }
        else {
            if (isBigRus(str[i]) == 1) {
                str[i] = str[i] + 32;
            }
        }
        i++;
    }
    return str;
}

string toBigRus(string str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '�') {
            str[i] = '�';
        }
        else {
            if (isSmallRus(str[i]) == 1) {
                str[i] = str[i] - 32;
            }
        }
        i++;
    }
    return str;
}