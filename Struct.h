#ifndef CW_STRUCT_H
#define CW_STRUCT_H

#include <iostream> //�����
#include <fstream> //�����
#include <Windows.h> //�������
#include <climits> //���������
#include <iomanip> //��,���
#include <string> //������
#include <conio.h> //"�������"

#include "Char.h"
#include "Error.h"
#include "Console.h"
#include "Line.h"

using namespace std;


struct InstituteNode; //��������
struct StudentNode; //�������
struct RecordNode; //���������


class StudentNode : public Node {
public:
    friend struct InstituteNode;
    string gender = "�"; //���
    string address = ""; //�����
    string status = ""; //������ ��������

    explicit StudentNode(LineNode* line) {
        copyNumber(line->number, this->number);
        this->checksumNumber = line->checksumNumber;
        this->surname = line->surname;
        this->name = line->name;
        this->patronymic = line->patronymic;
        this->institute = line->institute;
        this->faculty = line->faculty;
        this->training = line->training;
        this->course = line->course;
        this->group = line->group;
        this->payment = line->payment;
        this->year = line->year;
        this->department = line->department;
        this->date = line->date;

        this->gender = line->gender;
        this->address = line->address;
        this->status = line->status;

        this->checksumData = line->checksumData;

        if (line != nullptr) {
            delete line;
        }
    }

    virtual ~StudentNode() {
    };

    void printStudentCard();
    void printHeadGroupCard();
    void printStudentOne(int num = 0);
    LineNode* copyStudent();
    StudentNode* nextNode();
private:
    StudentNode* next = nullptr;
    StudentNode* prev = nullptr;
};

class RecordNode : public Node {
public:
    friend struct InstituteNode;
    string subject = ""; //�������
    string teacherSurname = ""; //������� �������
    string teacherName = ""; //��� �������
    string teacherPatronymic = ""; //�������� �������
    string value = ""; //������
    string room = ""; //���������� ����� ���������

    explicit RecordNode(LineNode* line) {
        copyNumber(line->number, this->number);
        this->checksumNumber = line->checksumNumber;
        this->surname = line->surname;
        this->name = line->name;
        this->patronymic = line->patronymic;
        this->institute = line->institute;
        this->faculty = line->faculty;
        this->training = line->training;
        this->course = line->course;
        this->group = line->group;
        this->payment = line->payment;
        this->year = line->year;
        this->department = line->department;
        this->date = line->date;

        this->subject = line->subject;
        this->teacherSurname = line->teacherSurname;
        this->teacherName = line->teacherName;
        this->teacherPatronymic = line->teacherPatronymic;
        this->value = line->value;
        this->room = line->room;

        this->checksumData = line->checksumData;

        if (line != nullptr) {
            delete line;
        }
    }

    ~RecordNode() {
    };

    int editRecord(LineNode* line, int all, int now);

    void printRoom();
    void printHeadRecordCard();
    void printHeadRecordCardSNP();
    void printStudentOne();
    void printEditRecordOne(int num);
    void printRecordOne(int num);
    LineNode* copyRecord();
    RecordNode* nextNode();
private:
    RecordNode* next = nullptr;
    RecordNode* prev = nullptr;
};

class InstituteNode {
public:
    //string path = "Data\\";
    string path = "";
    //string file = "InstituteData";
    string file = "data";
    string expansion = ".txt";
    string fileToWork = "";
    string fileTheName = "";
    int nodeSuccess = 0;
    int nodeMistake = 0;
    int operationSuccess = 0;
    int operationMistake = 0;

    string* worlEnd_������ = new string[] {"�������", "������", "������"};
    string* worlEnd_����� = new string[] { "�����", "�����", "�����" };

    explicit InstituteNode() {
    }

    ~InstituteNode() {
        if (worlEnd_������ == nullptr) {
            delete[] worlEnd_������;
        }
        if (worlEnd_����� == nullptr) {
            delete[] worlEnd_�����;
        }
    };

    StudentNode* headStudentsList = nullptr;
    StudentNode* endStudentsList = nullptr;

    RecordNode* headRecordsList = nullptr;
    RecordNode* endRecordsList = nullptr;

    LineNode* failList = nullptr;
    LineNode* lastFailList = nullptr;

    void resetSM();
    int checkUniqueSNP(LineNode* line);
    int compareSNP(StudentNode* node, LineNode* line);
    int checkUniqueGroup(LineNode* line);
    int compareGroup(StudentNode* node, LineNode* line);
    int checkUniqueNumber(string* number);
    int compareNumber(string* str1, string* str2);
    int checkUniqueRoom(LineNode* line);
    int compareRoom(RecordNode* node, LineNode* line);

    string generateRecordRoom();
    void generateNumber(LineNode* line);
    StudentNode* findStudent(LineNode* line);
    RecordNode* findRecord(LineNode* line);
    StudentNode* findGroup(LineNode* line);

    void add(LineNode* line);
    void deleteAll();
    void deleteOneStydent(string* number);
    void deleteOneStydent(StudentNode* node);
    void deleteOneRecord(RecordNode* node);
    void deleteRecord(LineNode* node);
    void deleteGroup(LineNode* line);
    void printLineStudents();
    void printLineRecords();
    void printFailList(int num = 0);

private:
    void addStudent(LineNode* line);
    void addRecord(LineNode* line);
    void addFail(LineNode* line);
    void addStartStudent(StudentNode* newStydent);
    void addAfterStudent(StudentNode* node, StudentNode* newStydent);
    void addStartRecord(RecordNode* newRecord);
    void addAfterRecord(RecordNode* node, RecordNode* newRecord);
};

#endif