#ifndef CW_LINE_H
#define CW_LINE_H

#include <iostream> //�����
#include <fstream> //�����
#include <Windows.h> //�������
#include <climits> //���������
#include <iomanip> //��,���
#include <string> //������
#include <conio.h> //"�������"

using namespace std;


struct Node; //����
struct LineNode; //�����

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
    /*��� ������� �������� ���� ��� ���� ���� ����*/
    string* number = new string[]{ "    ", "    ", "    ", "2908", "1930", "0000", "0000", "0000" }; //���������� ������ �����
    string checksumNumber = ""; //����������� ��� ������� ������
    string surname = ""; //�������
    string name = ""; //���
    string patronymic = ""; //��������
    string institute = "�"; //��������
    string faculty = ""; //���������
    string training = ""; //����� ��������
    string course = ""; //����
    string group = ""; //������
    string payment = ""; //����� ������ ������
    string year = ""; //��� �����������
    string department = ""; //�������
    string date = ""; //����
    string checksumData = ""; //����������� ����� ������

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
    int* errorLine = new int[quantityErrorLine] { 0, //1 - ������������� ������
        0, //2 - �� ������������ ����������
        0, //3 - ����������� ��� ������
        0, //4 - �������� ���������� ������
        0, //5 - ������������ �����
        0, //6 - �� �������� ���������� ����� �����
        0, //7 - ������������ �������
        0, //8 - ������������ ���
        0, //9 - ������������ ��������
        0, //10 - ������������ ��������
        0, //11 - ������������ ���������
        0, //12 - ������������ ����� ��������
        0, //13 - ������������ ����
        0, //14 - ������������ ����� ������
        0, //15 - ������������ ������ ������
        0, //16 - ������������ ��� �����������
        0, //17 - ������������ �������
        0, //18 - ������������ ����
        0}; //19 - �� �������� ���������� ����� ������
    int quantityErrorStudent = 3;
    int* errorStudent = new int[quantityErrorStudent] { 0, //1 - ������������ ���
        0, // 2 - ������������ �����
        0}; // 3 - ������������ ������ ��������
    int quantityErrorRecord = 6;
    int* errorRecord = new int[quantityErrorRecord] {0, //1 - ������������ �������
        0, //2 - ������������ ������� �������
        0, //3 - ������������ ��� �������
        0, //4 - ������������ �������� �������
        0, //5 - ������������ ������
        0}; //6 - ������������ ����� ���������
    int quantityErrorUnique = 4;
    int* errorUnique = new int[quantityErrorUnique] {0, //1 - � ���������� ����� ������ ������
        0, //2 - ���������� ����� ��� ����������
        0, //3 - � ���� ������ ��� ���� ������� � ����� ���
        0}; //4 - � ���������� ���������� ������ ������
    string arrFields[7] = { "_________________________", "__________", "____", "___", "__", "_", ""};

    char type = 'E'; //S - �������, R - ���������

    string gender = "�"; //���
    string address = ""; //�����
    string status = "1"; //������ ��������

    string subject = ""; //�������
    string teacherSurname = ""; //������� �������
    string teacherName = ""; //��� �������
    string teacherPatronymic = ""; //�������� �������
    string value = "-"; //������
    string room = ""; //���������� ����� ���������

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
    bool err = 0; //���� �� ������
    string str = "";
    int len = 0;

    LineNode* next = nullptr;
};
int fillFiedls(LineNode* line, string strLine, checkLine checkFunk, Err checkErr, string field, int numFields, short w, short i, short hStart = 0, short down = 0);

#endif