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
    //0 записей
    //1 запись
    //2 записи
    //3 записи
    //4 записи
    //5 записей
    //6 записей
    //7 записей
    //8 записей
    //9 записей
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
        return "Продолжает обучение";
    }
    if (val == "2") {
        return "В академическом отпуске";
    }
    if (val == "3") {
        return "Закончил обучение";
    }
    if (val == "0") {
        return "Отчислен";
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
        return "н/я";
    }
    if (val == "6") {
        return "н/д";
    }
    if (val == "7") {
        return "н/к";
    }
    else {
        return val;
    }
}

string getChecksum(string str) { //Функция получения контрольной суммы
    if (str.size() % 2 == 1) {
        str = str + 'm';
    }
    unsigned long long int sum = 0;
    int mul;
    int div;
    for (int i = 0; i < str.size(); i = i + 2) { //Прибавляем к контрольной сумме результат попарного деления и умножения их значений
        mul = str[i] * str[i + 1];
        div = str[i] / str[i + 1];
        sum = sum + mul + div;
        sum = sum % 1000000000000000000; //Предотвращаем переполнение
    }
    while (sum % 10 == 0) { //Убираем нули в конце
        sum = sum / 10;
    }
    sum = sum % 1000000; //Оставляем 6 последних цифр
    str = to_string(sum);
    if (str.length() < 6) {
        str = addZero(str, 6); //При длине меньше 6 - добавляем значимые нули
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

int compareString(string str1, string str2) { //Сравнение строк в алфавитном порядке
    int i = 0;
    while ((str1[i] != '\0') && (str2[i] != '\0')) {
        if (str1[i] > str2[i]) {
            return 1; //Первая больше
        }
        if (str1[i] < str2[i]) {
            return 2; //Вторая больше
        }
        i++;
    }
    if (str1[i] == '\0') {
        return 2;
    }
    return 0; //Одинаковые
}

void copyNumber(string* from, string* to) { //Переписывание номера
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
    if ((('А' <= ch) && (ch <= 'Я')) || (ch == 'Ё')) {
        return 1;
    }
    return 0;
}

bool isSmallRus(char ch) {
    if ((('а' <= ch) && (ch <= 'я')) || (ch == 'ё')) {
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
    return 0; //Номер не допустим
}

string toSmallRus(string str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == 'Ё') {
            str[i] = 'ё';
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
        if (str[i] == 'ё') {
            str[i] = 'Ё';
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