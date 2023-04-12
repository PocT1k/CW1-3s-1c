#ifndef CW_LINE_H
#define CW_LINE_H

#include <iostream> //Вывод
#include <fstream> //Файлы
#include <Windows.h> //Виндовс
#include <climits> //Константы
#include <iomanip> //Вы,вод
#include <string> //Строки
#include <conio.h> //"Консоль"

using namespace std;


struct Node; //Узел
struct LineNode; //Линия

string getStringBeforeSep(string& strLine, LineNode* line);

int checkLine_Lenght(string& strLine, LineNode* line);
int checkLine_Syntax(string& strLine, LineNode* line);
int checkLine_Type(string& strLine, LineNode* line);
int checkLine_AmountData(string& strLine, LineNode* line);
int checkLine_Number(string& strLine, LineNode* line);
int checkLine_ChecksumNumber(string& strLine, LineNode* line);
int checkLine_Surname(string& strLine, LineNode* line);
int checkLine_Name(string& strLine, LineNode* line);
int checkLine_Patronymic(string& strLine, LineNode* line);
int checkLine_Institute(string& strLine, LineNode* line);
int checkLine_Faculty(string& strLine, LineNode* line);
int checkLine_Training(string& strLine, LineNode* line);
int checkLine_Course(string& strLine, LineNode* line);
int checkLine_Group(string& strLine, LineNode* line);
int checkLine_Payment(string& strLine, LineNode* line);
int checkLine_Year(string& strLine, LineNode* line);
int checkLine_Department(string& strLine, LineNode* line);
int checkLine_Date(string& strLine, LineNode* line);

int checkLine_Gender(string& strLine, LineNode* line);
int checkLine_Address(string& strLine, LineNode* line);
int checkLine_Status(string& strLine, LineNode* line);

int checkLine_Subject(string& strLine, LineNode* line);
int checkLine_TeacherSurname(string& strLine, LineNode* line);
int checkLine_TeacherName(string& strLine, LineNode* line);
int checkLine_TeacherPatronymic(string& strLine, LineNode* line);
int checkLine_Value(string& strLine, LineNode* line);
int checkLine_Room(string& strLine, LineNode* line);

int checkLine_ChecksumData(string& strLine, LineNode* line);

typedef int(*checkLine)(string& strLine, LineNode* line);

class Node {
public:
    friend struct InstituteNode;
    /*Имя Фамилия Отчество Дата Год Мили Нано Ранд*/
    string* number = new string[]{ "    ", "    ", "    ", "2908", "1930", "0000", "0000", "0000" }; //Уникальный личный номер
    string checksumNumber = ""; //Проверочный код личного номера
    string surname = ""; //Фамилия
    string name = ""; //Имя
    string patronymic = ""; //Отчество
    string institute = "М"; //Институт
    string faculty = ""; //Факультет
    string training = ""; //Форма обучения
    string course = ""; //Курс
    string group = ""; //Группа
    string payment = ""; //Форма оплаты группы
    string year = ""; //Год поступления
    string department = ""; //Кафедра
    string date = ""; //Дата
    string checksumData = ""; //Контпольная сумма данных

    virtual ~Node() {
        if (number != nullptr) {
            delete[] number;
        }
    };

    string getGroup();
    void printLineGeneral();
    void writeGeneral(ostream& stream, Node* node);
private:

};

class LineNode : public Node {
public:
    friend struct InstituteNode;

    int quantityErrorLine = 19;
    int* errorLine = new int[quantityErrorLine] { 0, //1 - недостаточная длинна
        0, //2 - не соотвествует синтаксису
        0, //3 - неизвестный тип записи
        0, //4 - неверное количество данных
        0, //5 - недопустимый номер
        0, //6 - не сходится контрольна сумма числа
        0, //7 - некорректная Фамилия
        0, //8 - некорректное Имя
        0, //9 - некорректное Отчество
        0, //10 - некорректный институт
        0, //11 - некорректный факультет
        0, //12 - некорректная форма обучения
        0, //13 - некорректный курс
        0, //14 - некорректный номер группы
        0, //15 - некорректный оплата группы
        0, //16 - некорректный год поступления
        0, //17 - некорректная кафедра
        0, //18 - некорректная дата
        0}; //19 - не сходится контрольна сумма данных
    int quantityErrorStudent = 3;
    int* errorStudent = new int[quantityErrorStudent] { 0, //1 - некорректный пол
        0, // 2 - некорректный адрес
        0}; // 3 - некорректный статус обучения
    int quantityErrorRecord = 6;
    int* errorRecord = new int[quantityErrorRecord] {0, //1 - некорректный предмет
        0, //2 - некорректная Фамилия учителя
        0, //3 - некорректное Имя учителя
        0, //4 - некорректное Отчество учителя
        0, //5 - некорректная оценка
        0}; //6 - некорректный номер ведомости
    int quantityErrorUnique = 4;
    int* errorUnique = new int[quantityErrorUnique] {0, //1 - у одинаковых групп разные данные
        0, //2 - уникальный номер уже существует
        0, //3 - в этой группе уже есть студент с таким ФИО
        0}; //4 - у одинаковых ведомостей разные данные
    string arrFields[7] = { "_________________________", "__________", "____", "___", "__", "_", ""};

    char type = 'E'; //S - студент, R - ведомость

    string gender = "С"; //Пол
    string address = ""; //Адрес
    string status = "1"; //Статус обучения

    string subject = ""; //Предмет
    string teacherSurname = ""; //Фамилия учителя
    string teacherName = ""; //Имя учителя
    string teacherPatronymic = ""; //Отчество учителя
    string value = "-"; //Оценка
    string room = ""; //Уникальный номер ведомости

    char sep = ';';
    int amountDataThis = 0;
    int amountDataMinStudent = 19;
    int amountDataMinRecord = 22;
    int amountDataMin = min(this->amountDataMinStudent, this->amountDataMinRecord);
    int lenStrMin = 4 + this->amountDataMin + 8 * 5 - 1 + 6 * 2;

    LineNode() {
    }

    ~LineNode() {
        if (errorLine != nullptr) {
            delete[] errorLine;
        }
    };

    void coutError();
    void setErr();
    void resetErr();
    bool getErr();
    void coutErr();

    void createStr(string str);
    void coutStr();
    string getStr();
    void createLen(int len);
    void addLen(int num);
    void subLen(int num);
    int getLen();

    LineNode* copyLineNode();
    void printErr(LineNode* node);

    void coutCreateStudentCart(string arrFields[], int size, string strLines[]);
    void coutFindStudentCart(string arrFields[], int size);
    void coutCreateRecordCart(string arrFields[], int size1);
    void coutFindGroupCart(string arrFields[], int size);
    void coutFindRecordCart(string arrFields[], int size1);

    int fillStydent(LineNode* line, int operatinFlag = 1);
    int findStydent(LineNode* line);
    int fillRecord(LineNode* line);
    int findRecord(LineNode* line);
    int findGroup(LineNode* line);

    LineNode* nextNode(LineNode* node);
private:
    bool err = 0; //Была ли ошибка
    string str = "";
    int len = 0;

    LineNode* next = nullptr;
};
int fillFiedls(LineNode* line, string strLine, checkLine checkFunk, Err checkErr, string field, int numFields, short w, short i, short hStart = 0, short down = 0);

#endif