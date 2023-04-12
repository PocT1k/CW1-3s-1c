#include "Menu.h"

using namespace std;


void menuStop() {
    cout << endl << "��� �������������� � ���������� ������� ENTER";
    char key;
    while (true) {
        key = _getch();
        switch (key) {
        case kENTER:
            return;
        default:
            break;
        }
    }
}

void printCommands() {
    cout << "������� �������������� �������:" << endl;
    cout << "1 ��������� �� �����" << endl;
    cout << "2 ��������� � ����" << endl;
    cout << "3 ������� ��" << endl;
    cout << "4 �������������� �� ����������" << endl;
    cout << "5 �������������� � �����������" << endl;
    cout << "6 �������������� � ��������" << endl;
    cout << "7 ������ ������������� �����" << endl;
    cout << "ESC ���������� ���������" << endl;
}

void menuReadFile(InstituteNode& institute) {
    consoleCursorVisible(false);
    system("CLS");
    cout << "������� �������� ����� ��� ��������" << endl;
    consoleCursorVisible(true);

    getline(cin, institute.fileToWork);
    consoleCursorVisible(false);
    readFromFile(institute);

    menuStop();
    system("CLS");
    printCommands();
}

void menuWriteFile(InstituteNode& institute) {
    consoleCursorVisible(false);
    system("CLS");
    cout << "������� �������� ����� ��� ��������" << endl;
    consoleCursorVisible(true);

    getline(cin, institute.fileToWork);
    consoleCursorVisible(false);
    cout << "��������� �� ������������� ������?" << endl;
    cout << "1 ��" << endl;
    cout << "2 ���" << endl;
    cout << "ESC ����� � ������� ����" << endl;

    char key;
    bool run = 1;
    while (run) {
        key = _getch();
        switch (key) {
        case kESC:
            system("CLS");
            printCommands();
            return;
        case k1:
            writeToFile(institute, 1);
            run = 0;
            break;
        case k2:
            writeToFile(institute, 0);
            run = 0;
            break;
        default:
            break;
        }
    }

    menuStop();
    system("CLS");
    printCommands();
}

void menuDeleteAll(InstituteNode& institute) {
    consoleCursorVisible(false);
    system("CLS");
    cout << "������������� �� �������?" << endl;
    cout << "1 ��" << endl;
    cout << "2 ���" << endl;
    cout << "ESC ����� � ������� ����" << endl;

    char key;
    bool run = 1;
    while (run) {
        key = _getch();
        switch (key) {
        case kESC:
        case k2:
            run = 0;
            break;
        case kENTER:
        case k1:
            institute.deleteAll();
            run = 0;
            break;
        default:
            break;
        }
    }

    menuStop();
    system("CLS");
    printCommands();
}

void menuStudents(InstituteNode& institute) {
    consoleCursorVisible(false);
    system("CLS");
    cout << "������� �������������� �������:" << endl;
    cout << "1 ������� ������ ��������" << endl;
    cout << "2 ������������� ��������" << endl;
    cout << "3 ������� ��������" << endl;
    cout << "4 ������� ��������" << endl;
    cout << "5 C����� ������� ���������" << endl;
    cout << "ESC ����� � ������� ����" << endl;

    char key;
    bool run = 1;
    while (run) {
        key = _getch();
        switch (key) {
        case kESC:
            run = 0;
            break;
        case k1:
        {
            createStydent(institute);
            run = 0;
            break;
        }
        case k2:
            editStydent(institute);
            run = 0;
            break;
        case k3:
            deleteStydent(institute);
            run = 0;
            break;
        case k4:
            printStydent(institute);
            run = 0;
            break;
        case k5:
            institute.printLineStudents();
            run = 0;
            break;
        default:
            break;
        }
    }

    menuStop();
    system("CLS");
    printCommands();
}

void menuRecords(InstituteNode& institute) {
    consoleCursorVisible(false);
    system("CLS");
    cout << "������� �������������� �������:" << endl;
    cout << "1 ����� ����� ���������" << endl;
    cout << "2 ������������� ���������" << endl;
    cout << "3 ������� ���������" << endl;
    cout << "4 ������� ���������" << endl;
    cout << "5 C����� ������� ����������" << endl;
    cout << "ESC ����� � ������� ����" << endl;

    char key;
    bool run = 1;
    while (run) {
        key = _getch();
        switch (key) {
        case kESC:
            run = 0;
            break;
        case k1:
        {
            createRecord(institute);
            run = 0;
            break;
        }
        case k2:
            editRecord(institute);
            run = 0;
            break;
        case k3:
            deleteRecord(institute);
            run = 0;
            break;
        case k4:
            printRecord(institute);
            run = 0;
            break;
        case k5:
            institute.printLineRecords();
            run = 0;
            break;
        default:
            break;
        }
    }

    menuStop();
    system("CLS");
    printCommands();
}

void menuGroups(InstituteNode& institute) {
    consoleCursorVisible(false);
    system("CLS");
    cout << "������� �������������� �������:" << endl;
    cout << "1 ������� ������" << endl;
    cout << "2 ������� ������" << endl;
    cout << "ESC ����� � ������� ����" << endl;

    char key;
    bool run = 1;
    while (run) {
        key = _getch();
        switch (key) {
        case kESC:
            run = 0;
            break;
        case k1:
        {
            deleteGroup(institute);
            run = 0;
            break;
        }
        case k2:
            printGroup(institute);
            run = 0;
            break;
        default:
            break;
        }
    }

    menuStop();
    system("CLS");
    printCommands();
}

void menuFails(InstituteNode& institute) {
    system("CLS");
    if (institute.failList != nullptr) {
        cout << "������ ������������� ����� � ������ � ���:" << endl;
        institute.printFailList(1);
    }
    else {
        cout << "�� ����������� ����� �����������" << endl;
    }

    menuStop();
    system("CLS");
    printCommands();
}