#include "Functions.h"

using namespace std;


void test() {
    cout << "------------------------------------" << endl;
    //cout << INT_MAX << endl;


    //char c = 't';
    //cout << c << endl;

    //ofstream fout;
    //fout.open("Проверка1.ins");
    //fout << "123 Да Нет Yes No";
    //fout.close();
    //ifstream fin;
    //fin.open("Проверка1.ins");
    //string str1;
    //getline(fin, str1);
    //cout << str1 << endl;


    cout << "------------------------------------" << endl;
}

void readLine(string& strLine, LineNode* line) { //Обработка полученной линии из файла
    //line->coutStr();

    checkLine checkLineFile_Start[] = { checkLine_Syntax, checkLine_Type, checkLine_AmountData }; //Старотовая проверка строки
    checkLine checkLineFile_Total[] = { checkLine_Number, checkLine_ChecksumNumber, checkLine_Surname, checkLine_Name, checkLine_Patronymic, checkLine_Institute, checkLine_Faculty, checkLine_Training , checkLine_Course, checkLine_Group, checkLine_Payment, checkLine_Year, checkLine_Department, checkLine_Date }; //Общая проверка файла
    checkLine checkLineFile_Student[] = { checkLine_Gender, checkLine_Address, checkLine_Status }; //Проверка студента для файла
    checkLine checkLineFile_Record[] = { checkLine_Subject, checkLine_TeacherSurname, checkLine_TeacherName, checkLine_TeacherPatronymic, checkLine_Value, checkLine_Room }; //Проверка ведомости для файла
    int size_checkLineFile_Start = sizeof(checkLineFile_Start) / sizeof(checkLineFile_Start[0]);
    int size_checkLineFile_Total = sizeof(checkLineFile_Total) / sizeof(checkLineFile_Total[0]);
    int size_checkLineFile_Student = sizeof(checkLineFile_Student) / sizeof(checkLineFile_Student[0]);
    int size_checkLineFile_Record = sizeof(checkLineFile_Record) / sizeof(checkLineFile_Record[0]);

    line->errorLine[0] = checkLine_Lenght(strLine, line);
    if (line->errorLine[0] == 0) {
        for (int i = 0; i < size_checkLineFile_Start; i++) {
            line->errorLine[i] = checkLineFile_Start[i](strLine, line);
        }
        line->setErr();
        if (line->getErr() == 0) {
            for (int i = 4; i < (size_checkLineFile_Total + 4); i++) {
                line->errorLine[i] = checkLineFile_Total[i - 4](strLine, line);
            }

            if (line->type == 'S') {
                for (int i = 0; i < size_checkLineFile_Student; i++) {
                    line->errorStudent[i] = checkLineFile_Student[i](strLine, line);
                }
            }
            if (line->type == 'R') {
                for (int i = 0; i < size_checkLineFile_Record; i++) {
                    line->errorRecord[i] = checkLineFile_Record[i](strLine, line);
                }
            }
            line->errorLine[18] = checkLine_ChecksumData(strLine, line);
        }
    }
    line->setErr();

    //line->coutError();
}

void readFileLine(istream& stream, InstituteNode& institute) { //Получение линии из файла
    string strLine = "";
    getline(stream, strLine);
    deleteSpace(strLine);
    if (strLine == "") {
        return;
    }

    LineNode* line = new LineNode;
    line->createStr(strLine);

    readLine(strLine, line);

    institute.add(line);
}

void readFromFile(InstituteNode& institute) {
    cout << endl;
    ifstream instituteDataFile;
    instituteDataFile.open(institute.fileToWork);

    if (!instituteDataFile) {
        cout << "Ошибка чтения файла " << institute.fileToWork << endl;
        return;
    }
    if (!instituteDataFile.is_open()) {
        cout << "Ошибка открытия файла " << institute.fileToWork << endl;
        return;
    }
    cout << "Открыт файл " << institute.fileToWork << endl;

    istream* stream = nullptr;
    stream = &instituteDataFile;

    while (!stream->eof()) {
        readFileLine(*stream, institute);
    }
    instituteDataFile.close();

    cout << "Чтение файла " << institute.fileToWork << " закончено" << endl;
    if (institute.nodeSuccess != 0) {
        cout << "Успешно загружено " << institute.nodeSuccess << " " << institute.worlEnd_запись[getWordEnd(institute.nodeSuccess)] << endl;

        if (institute.nodeMistake != 0) {
            cout << "Не удалось загрузить " << institute.nodeMistake << " " << institute.worlEnd_запись[getWordEnd(institute.nodeMistake)] << endl;
            cout << "Список не загруженных записей:" << endl;
            cout << endl;
        }
        else {
            cout << "Не загруженных записей нет" << endl;
        }
    }
    else {
        cout << "Файл пуст" << endl;
    }

    institute.resetSM();
    institute.printFailList(1);
}

void writeNumber(ostream& stream, string* number) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            stream << number[i][j];
        }
        if (i != 7) {
            stream << "-";
        }
    }
}

void writeStudentLine(ostream& stream, StudentNode* node) {
    stream << "[S]:";
    writeNumber(stream, node->number);
    node->writeGeneral(stream, node);
    stream << node->gender << ";" << node->address << ";" << node->status;
    stream << ";" << node->checksumData;
    stream << ";";
    stream << endl;
}

void writeRecordLine(ostream& stream, RecordNode* node) {
    stream << "[R]:";
    writeNumber(stream, node->number);
    node->writeGeneral(stream, node);
    stream << node->subject << ";" << node->teacherSurname << ";" << node->teacherName << ";" << node->teacherPatronymic << ";" << node->value << ";" << node->room;
    stream << ";" << node->checksumData;
    stream << ";";
    stream << endl;
}

void writeFailLine(ostream& stream, LineNode* node) {
    stream << node->getStr();
    stream << endl;
}

void writeToFile(InstituteNode& institute, int flag) {
    cout << endl;
    ofstream instituteDataFile;
    instituteDataFile.open(institute.fileToWork);

    if (!instituteDataFile) {
        cout << "Ошибка создания файла " << institute.fileToWork << endl;
        return;
    }
    if (!instituteDataFile.is_open()) {
        cout << "Ошибка открытия файла " << institute.fileToWork << endl;
        return;
    }
    cout << "Создан файл " << institute.fileToWork << endl;

    ostream* stream = nullptr;
    stream = &instituteDataFile;

    StudentNode* nodeS = institute.headStudentsList;
    while (nodeS != nullptr) {
        writeStudentLine(*stream, nodeS);
        institute.nodeSuccess++;
        nodeS = nodeS->nextNode();
    }
    instituteDataFile << endl;

    RecordNode* nodeR = institute.headRecordsList;
    while (nodeR != nullptr) {
        writeRecordLine(*stream, nodeR);
        institute.nodeSuccess++;
        nodeR = nodeR->nextNode();
    }

    if (flag) {
        instituteDataFile << endl;
        LineNode* nodeF = institute.failList;
        while (nodeF != nullptr) {
            writeFailLine(*stream, nodeF);
            institute.nodeMistake++;
            nodeF = nodeF->nextNode(nodeF);
        }
    }

    instituteDataFile.close();

    cout << "Зпись файла " << institute.fileToWork << " закончена" << endl;
    cout << "Успешно загружено " << institute.nodeSuccess << " " << institute.worlEnd_запись[getWordEnd(institute.nodeSuccess)];
    if (institute.nodeMistake != 0) {
        cout << " и " << institute.nodeMistake << " не загрузившихся " << institute.worlEnd_запись[getWordEnd(institute.nodeMistake)];
    }
    cout << endl;
    institute.resetSM();
}

void createStydent(InstituteNode& institute) {
    LineNode* line = new LineNode;
    system("CLS");

    int outFlag = line->fillStydent(line);
    if (outFlag) {
        cout << endl;
        cout << "Создание нового студента отменено" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    line->errorUnique[0] = institute.checkUniqueGroup(line);
    if (line->errorUnique[0] == 0) {
        line->errorUnique[2] = institute.checkUniqueSNP(line);
        if (line->errorUnique[2] == 0) { //Само добавление
            cout << endl;
            cout << "Добавление нового студента..." << endl;

            institute.generateNumber(line);
            line->checksumNumber = getChecksum(getNumber(line->number));
            string data = "";
            data = data + line->type + getNumber(line->number) + line->checksumNumber + line->surname + line->name + line->patronymic + line->institute + line->faculty + line->training + line->course + line->group + line->payment + line->year + line->department + line->date;
            data = data + line->gender + line->address + line->status;
            line->checksumData = getChecksum(data);

            institute.add(line);
            institute.resetSM();

            cout << "Новый студент успешно добавлен!" << endl;
            return;
        }
        else { //errU 2
            line->printErr(line);
            cout << "Студент не создан" << endl;
        }
    }
    else { //errU 0
        line->printErr(line);
        cout << "Студент не создан" << endl;
    }
}

void editStydent(InstituteNode& institute) {
    LineNode* line = new LineNode;
    system("CLS");

    int outFlag = line->findStydent(line);
    if (outFlag) {
        cout << endl;
        cout << "Редактирование студента отменено" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    cout << endl;
    cout << "Поиск студента..." << endl;
    StudentNode* node = institute.findStudent(line);
    if (line != nullptr) {
        delete line;
    }

    if(node == nullptr) {
        cout << endl;
        cout << "Студент не найден" << endl;
        return;
    }
    else { //Само редактирование
        node->printStudentCard();
        cout << endl;

        char key;
        bool run = 1;
        cout << "Продолжить редактирование?" << endl;
        cout << "1 Да" << endl;
        cout << "2 Нет" << endl;
        cout << endl;

        while (run) {
            key = _getch();
            switch (key) {
            case kESC:
            case k2:
                system("CLS");
                cout << "Редактирование остановлено" << endl;
                run = 0;
                break;
            case k1:
            case kENTER: { //Редактирование
                LineNode* line = node->copyStudent();
                system("CLS");

                int outFlag = line->fillStydent(line, 1);
                if (outFlag) {
                    cout << endl;
                    cout << "Редактирование студента отменено" << endl;
                    if (line != nullptr) {
                        delete line;
                    }
                    return;
                }

                line->errorUnique[0] = institute.checkUniqueGroup(line);
                if (line->errorUnique[0] == 0) {
                    if ((line->institute == node->institute) && (line->faculty == node->faculty) && (line->course == node->course) && (line->group == node->group)) {
                        line->errorUnique[2] = 0;
                    }
                    else {
                        line->errorUnique[2] = institute.checkUniqueSNP(line);
                    }
                    if (line->errorUnique[2] == 0) {
                        cout << endl;
                        cout << "Внесение изменений..." << endl;

                        string data = "";
                        data = data + line->type + getNumber(line->number) + line->checksumNumber + line->surname + line->name + line->patronymic + line->institute + line->faculty + line->training + line->course + line->group + line->payment + line->year + line->department + line->date;
                        data = data + line->gender + line->address + line->status;
                        line->checksumData = getChecksum(data);

                        institute.deleteOneStydent(node->number);

                        institute.add(line);
                        institute.resetSM();

                        cout << "Студент успешно отредактирован!" << endl;
                        return;
                    }
                    else { //errU 2
                        line->printErr(line);
                        cout << endl;
                        cout << "Студент не отредактирован" << endl;
                    }
                }
                else { //errU 0
                    line->printErr(line);
                    cout << endl;
                    cout << "Студент не отредактирован" << endl;
                }
                run = 0;
                break;
            } //Редактирование
            default:
                break;
            }
        }
    }
}

void deleteStydent(InstituteNode& institute) {
    LineNode* line = new LineNode;
    system("CLS");

    int outFlag = line->findStydent(line);
    if (outFlag) {
        cout << "Удаление студента отменено" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    cout << endl;
    cout << "Поиск студента..." << endl;
    StudentNode* node = institute.findStudent(line);
    if (line != nullptr) {
        delete line;
    }

    if (node == nullptr) {
        cout << endl;
        cout << "Студент не найден" << endl;
        return;
    }
    else { //Само удаление
        node->printStudentCard();
        cout << endl;

        char key;
        bool run = 1;
        cout << "Продолжить удаление?" << endl;
        cout << "1 Да" << endl;
        cout << "2 Нет" << endl;
        cout << endl;

        while (run) {
            key = _getch();
            switch (key) {
            case kESC:
            case k2:
                system("CLS");
                cout << "Удаление остановлено" << endl;
                run = 0;
                break;
            case kENTER:
            case k1:
                institute.deleteOneStydent(node);
                cout << endl;
                cout << "Студент удалён" << endl;
                run = 0;
                break;
            default:
                break;
            }
        }
    }
}

void printStydent(InstituteNode& institute) {
    LineNode* line = new LineNode;
    system("CLS");

    int outFlag = line->findStydent(line);
    if (outFlag) {
        cout << endl;
        cout << "Поиск студента отменён" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    cout << endl;
    cout << "Поиск студента..." << endl;
    StudentNode* node = institute.findStudent(line);
    if (line != nullptr) {
        delete line;
    }

    if (node == nullptr) {
        cout << endl;
        cout << "Указанный студент не найден" << endl;
        return;
    }
    else {
        node->printStudentCard();

        RecordNode* record = institute.headRecordsList;
        cout << endl;
        while (record != nullptr) {
            if ((institute.compareNumber(node->number, record->number) == 1) && (record->value != "-")) {
                institute.operationSuccess++;
                record->printStudentOne();
            }
            record = record->nextNode();
        }

        if (institute.operationSuccess == 0) {
            cout << "На данного студента не найдены ведомости" << endl;
        }
        institute.resetSM();
    }
}

void createRecord(InstituteNode& institute) {
    LineNode* line = new LineNode; //Сначала поиск группы
    system("CLS");

    int outFlag = line->findGroup(line);
    if (outFlag) {
        cout << endl;
        cout << "Поиск группы отменён" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    cout << endl;
    cout << "Поиск группы..." << endl;
    StudentNode* node = institute.findGroup(line);

    if (node == nullptr) {
        cout << endl;
        cout << "Указанная группа не найдена" << endl;
        return;
    }
    else { //Если группа найдена, то продолжаем создавать ведомость
        system("CLS");

        int outFlag = line->fillRecord(line);
        if (outFlag) {
            cout << "Создание новой ведомости отменено" << endl;
            if (line != nullptr) {
                delete line;
            }
            return;
        }

        cout << "Создание новой ведомости..." << endl;

        line->training = node->training;
        line->payment = node->payment;
        line->year = node->year;
        line->department = node->department;
        line->room = institute.generateRecordRoom();

        StudentNode* node = institute.headStudentsList;
        while (node != nullptr) {
            if ((node->institute == line->institute) && (node->faculty == line->faculty) && (node->course == line->course) && (node->group == line->group)) {
                LineNode* temp = line->copyLineNode();
                copyNumber(node->number, temp->number);
                temp->checksumNumber = node->checksumNumber;
                temp->surname = node->surname;
                temp->name = node->name;
                temp->patronymic = node->patronymic;

                string data = "";
                data = data + temp->type + getNumber(temp->number) + temp->checksumNumber + temp->surname + temp->name + temp->patronymic + temp->institute + temp->faculty + temp->training + temp->course + temp->group + temp->payment + temp->year + temp->department + temp->date;
                data = data + temp->subject + temp->teacherSurname + temp->teacherName + temp->teacherPatronymic + temp->value + temp->room;
                temp->checksumData = getChecksum(data);

                institute.add(temp);
                institute.resetSM();
            } //if

            node = node->nextNode();
        } //while

        cout << "Новая ведомость успешно создана!" << endl;
        cout << "Уникальный номер:" << line->room << endl;

        if (node != nullptr) { delete node; }
        if (line != nullptr) { delete line; }
        return;
    } //else
}

void editRecord(InstituteNode& institute) {
    LineNode* line = new LineNode;
    system("CLS");

    int outFlag = line->findRecord(line);
    if (outFlag) {
        cout << endl;
        cout << "Редактирование ведомости отменено" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    cout << endl;
    cout << "Поиск ведомости..." << endl;
    RecordNode* record = institute.findRecord(line);
    if (line != nullptr) {
        delete line;
    }

    if (record == nullptr) {
        cout << endl;
        cout << "Указанная ведомость не найдена" << endl;
        return;
    }
    else {
        record->printHeadRecordCard();

        char key;
        bool run = 1;
        cout << endl;
        cout << "Продолжить редактирование?" << endl;
        cout << "1 Да" << endl;
        cout << "2 Нет" << endl;
        cout << endl;

        while (run) {
            key = _getch();
            switch (key) {
            case kESC:
            case k2:
                system("CLS");
                cout << "Редактирование остановлено" << endl;
                run = 0;
                break;
            case kENTER:
            case k1: {
                system("CLS");
                record->printHeadRecordCard();
                record->printHeadRecordCardSNP();
                RecordNode* node = institute.headRecordsList;

                while (node != nullptr) { //while для прохода по всем ведомостям и печати полей этой ведомости
                    if (node->room == record->room) {
                        institute.operationSuccess++;
                        node->printEditRecordOne(institute.operationSuccess);
                    }
                    node = node->nextNode();
                }

                node = institute.headRecordsList;
                LineNode* line = new LineNode;
                while (node != nullptr) { //while для прохода по всем ведомостям и редактирования оценок
                    if (node->room == record->room) {
                        institute.operationMistake++;

                        line->value = node->value;
                        outFlag = node->editRecord(line, institute.operationSuccess, institute.operationMistake);
                        if (outFlag) {
                            cout << endl;
                            cout << "Редактирование ведомости отменено, все уже внесённые изменения сохранены" << endl;
                            if (line != nullptr) { delete line; }
                            institute.resetSM();
                            return;
                        }

                        node->value = line->value;

                        string data = ""; // Подсчёт новой контрольной суммы данных
                        data = data + "R" + getNumber(node->number) + node->checksumNumber + node->surname + node->name + node->patronymic + node->institute + node->faculty + node->training + node->course + node->group + node->payment + node->year + node->department + node->date;
                        data = data + node->subject + node->teacherSurname + node->teacherName + node->teacherPatronymic + node->value + node->room;
                        node->checksumData = getChecksum(data);
                    }
                    node = node->nextNode();
                }
                institute.resetSM();

                if (line != nullptr) { delete line; }

                cout << endl;
                cout << "Изменения в ведомость успешно внесены!" << endl;

                run = 0;
                break;
            }
            default:
                break;
            }
        } //while
    }
}

void deleteRecord(InstituteNode& institute) {
    LineNode* line = new LineNode;
    system("CLS");

    int outFlag = line->findRecord(line);
    if (outFlag) {
        cout << endl;
        cout << "Удаление ведомости отменено" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    cout << endl;
    cout << "Поиск ведомости..." << endl;
    RecordNode* node = institute.findRecord(line);
    if (line != nullptr) {
        delete line;
    }

    if (node == nullptr) {
        cout << endl;
        cout << "Указанная ведомость не найдена" << endl;
        return;
    }
    else {
        node->printHeadRecordCard();

        char key;
        bool run = 1;
        cout << endl;
        cout << "Продолжить удаление?" << endl;
        cout << "1 Да" << endl;
        cout << "2 Нет" << endl;
        cout << endl;

        while (run) {
            key = _getch();
            switch (key) {
            case kESC:
            case k2:
                system("CLS");
                cout << "Удаление остановлено" << endl;
                run = 0;
                break;
            case kENTER:
            case k1: {
                LineNode* line = node->copyRecord();
                institute.deleteRecord(line);
                cout << endl;
                cout << "Ведомость удалена" << endl;
                if (line != nullptr) {
                    delete line;
                }

                run = 0;
                break;
            }
            default:
                break;
            }
        } //while
    }
}

void printRecord(InstituteNode& institute) {
    LineNode* line = new LineNode;
    system("CLS");

    int outFlag = line->findRecord(line);
    if (outFlag) {
        cout << endl;
        cout << "Поиск ведомости отменён" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    cout << endl;
    cout << "Поиск ведомости..." << endl;
    RecordNode* node = institute.findRecord(line);
    if (line != nullptr) {
        delete line;
    }

    if (node == nullptr) {
        cout << endl;
        cout << "Указанная ведомость не найдена" << endl;
        return;
    }
    else {
        node->printHeadRecordCard();
        node->printHeadRecordCardSNP();

        RecordNode* record = institute.headRecordsList;
        while (record != nullptr) {
            if (node->room == record->room) {
                if (getValue(node->value) != "") {
                    institute.operationSuccess++;
                    record->printRecordOne(institute.operationSuccess);
                }
            }
            record = record->nextNode();
        }
        institute.resetSM();
    }
}

void deleteGroup(InstituteNode& institute) {
    LineNode* line = new LineNode;
    system("CLS");

    int outFlag = line->findGroup(line);
    if (outFlag) {
        cout << endl;
        cout << "Удаление группы отменено" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    cout << endl;
    cout << "Поиск группы..." << endl;
    StudentNode* node = institute.findGroup(line);
    if (line != nullptr) {
        delete line;
    }

    if (node == nullptr) {
        cout << endl;
        cout << "Указанная группа не найдена" << endl;
        return;
    }
    else {
        node->printHeadGroupCard();

        char key;
        bool run = 1;
        cout << endl;
        cout << "Продолжить удаление?" << endl;
        cout << "1 Да" << endl;
        cout << "2 Нет" << endl;
        cout << endl;

        while (run) {
            key = _getch();
            switch (key) {
            case kESC:
            case k2:
                system("CLS");
                cout << "Удаление остановлено" << endl;
                run = 0;
                break;
            case kENTER:
            case k1: {
                LineNode* line = node->copyStudent();
                institute.deleteGroup(line);
                cout << endl;
                cout << "Группа удалена" << endl;
                if (line != nullptr) {
                    delete line;
                }

                run = 0;
                break;
            }
            default:
                break;
            }
        } //while
    }
}

void printGroup(InstituteNode& institute) {
    LineNode* line = new LineNode;
    system("CLS");

    int outFlag = line->findGroup(line);
    if (outFlag) {
        cout << endl;
        cout << "Поиск группы отменён" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    cout << endl;
    cout << "Поиск группы..." << endl;
    StudentNode* node = institute.findGroup(line);
    if (line != nullptr) {
        delete line;
    }

    if (node == nullptr) {
        cout << endl;
        cout << "Указанная группа не найдена" << endl;
        return;
    }
    else {
        node->printHeadGroupCard();

        StudentNode* student = institute.headStudentsList;
        while (student != nullptr) {
            if ((node->institute == student->institute) && (node->faculty == student->faculty) && (node->course == student->course) && (node->group == student->group)) {
                institute.operationSuccess++;
                student->printStudentOne(institute.operationSuccess);
            }
            student = student->nextNode();
        }
        if (student != nullptr) { delete student; }

        institute.resetSM();
    }
}

InstituteNode createInstitutesList() {
    InstituteNode institute;
    institute.fileToWork = institute.path + institute.file + institute.expansion;
    institute.fileTheName = institute.path + institute.file + institute.expansion;

    readFromFile(institute);

    institute.printLineStudents();
    institute.printLineRecords();

    return institute;
}