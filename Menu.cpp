#include "Menu.h"

using namespace std;


void menuStop() {
    cout << endl << "Для взаимодействия с программой нажмите ENTER";
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
    cout << "Нажмите соотвествующую клавишу:" << endl;
    cout << "1 Загрузить из файла" << endl;
    cout << "2 Выгрузить в файл" << endl;
    cout << "3 Удалить всё" << endl;
    cout << "4 Взаимодействие со студентами" << endl;
    cout << "5 Взаимодействие с ведомостями" << endl;
    cout << "6 Взаимодействие с группами" << endl;
    cout << "7 Список незагруженных линий" << endl;
    cout << "ESC остановить программу" << endl;
}

void menuReadFile(InstituteNode& institute) {
    consoleCursorVisible(false);
    system("CLS");
    cout << "Введите название файла для загрузки" << endl;
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
    cout << "Введите название файла для выгрузки" << endl;
    consoleCursorVisible(true);

    getline(cin, institute.fileToWork);
    consoleCursorVisible(false);
    cout << "Сохранить не загрузившиеся записи?" << endl;
    cout << "1 Да" << endl;
    cout << "2 Нет" << endl;
    cout << "ESC назад в главное меню" << endl;

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
    cout << "Действительно всё удалить?" << endl;
    cout << "1 Да" << endl;
    cout << "2 Нет" << endl;
    cout << "ESC назад в главное меню" << endl;

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
    cout << "Нажмите соответсвующую клавишу:" << endl;
    cout << "1 Создать нового студента" << endl;
    cout << "2 Редактировать студента" << endl;
    cout << "3 Удалить студента" << endl;
    cout << "4 Вывести студента" << endl;
    cout << "5 Cписок записей студентов" << endl;
    cout << "ESC назад в главное меню" << endl;

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
    cout << "Нажмите соответсвующую клавишу:" << endl;
    cout << "1 Взять новую ведомость" << endl;
    cout << "2 Редактировать ведомость" << endl;
    cout << "3 Удалить ведомость" << endl;
    cout << "4 Вывести ведомость" << endl;
    cout << "5 Cписок записей ведомостей" << endl;
    cout << "ESC назад в главное меню" << endl;

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
    cout << "Нажмите соответсвующую клавишу:" << endl;
    cout << "1 Удалить группу" << endl;
    cout << "2 Вывести группу" << endl;
    cout << "ESC назад в главное меню" << endl;

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
        cout << "Список незагруженных линий и ошибки в них:" << endl;
        institute.printFailList(1);
    }
    else {
        cout << "Не загруженные линии отсутствуют" << endl;
    }

    menuStop();
    system("CLS");
    printCommands();
}