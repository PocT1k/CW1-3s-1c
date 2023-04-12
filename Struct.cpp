#include "Struct.h"

using namespace std;


void StudentNode::printStudentCard() {
    system("CLS");
    int size = 8;
    string arrFillIn[] = { "Студент", "Фамилия", "Имя", "Отчество", "Дата рождения", "Пол", "Адрес", "Статус обучения" };

    consoleCoutLetter("|", 0, size);
    consoleCoutLetter("|", 47, size);
    consoleCoutMesage(arrFillIn, 2, size);

    for (int i = 0; i < size; i++) {
        consoleCursorGoToXY(19, i);
        if (i == 0) {
            cout << getGroup();
        }
        if (i == 1) {
            cout << surname;
        }
        if (i == 2) {
            cout << name;
        }
        if (i == 3) {
            cout << patronymic;
        }
        if (i == 4) {
            cout << date;
        }
        if (i == 5) {
            cout << gender;
        }
        if (i == 6) {
            cout << address;
        }
        if (i == 7) {
            cout << getStatus(status);
        }
    }
    cout << endl;
}

void StudentNode::printHeadGroupCard() {
    system("CLS");
    consoleCoutLetter("|", 0, 1);
    consoleCoutLetter("|", 82, 1);
    consoleCursorGoToXY(2, 0);
    cout << "Группа";
    consoleCursorGoToXY(19, 0);
    cout << getGroup();
    consoleCursorGoToXY(0, 1);
}

void StudentNode::printStudentOne(int num) {
    consoleCoutLetter("|", 0, 1, num);
    consoleCoutLetter("|", 82, 1, num);
    consoleCursorGoToXY(2, 0 + num);
    cout << num;
    consoleCursorGoToXY(4, 0 + num);
    if (surname != "") {
        cout << surname << " ";
    }
    cout << name << " ";
    if (patronymic != "") {
        cout << patronymic << " ";
    }
    consoleCursorGoToXY(0, 1 + num);
}

int RecordNode::editRecord(LineNode* line, int all, int now) {
    int numFields = 1;
    string arrFieldsStudent[1] = { "___" };
    checkLine checkFunks[1] = { checkLine_Value };
    string strLines[1] = { line->value };
    Err arrErr[1] = { err_Value };

    for (int i = 0; i < (numFields); i++) {
        int outFlag = fillFiedls(line, strLines[i], checkFunks[i], arrErr[i], arrFieldsStudent[i], numFields, 84, i + now - 1, 5, all - 1);

        if (outFlag) {
            consoleCursorGoToXY(0, 5 + all);
            return 1;
        }
    }

    consoleCursorGoToXY(0, 5 + all);
    return 0;
}

void RecordNode::printRoom() {
    cout << addZero(room, 10);
}

void RecordNode::printHeadRecordCard() {
    system("CLS");
    consoleCoutLetter("|", 0, 4);
    consoleCoutLetter("|", 89, 4);
    consoleCursorGoToXY(2, 0);
    cout << "Ведомость№";
    consoleCursorGoToXY(14, 0);
    printRoom();
    consoleCursorGoToXY(45, 0);
    cout << "Дисциплина:";
    cout << subject;
    consoleCursorGoToXY(2, 1);
    cout << "Дата проведения:";
    cout << date;
    consoleCursorGoToXY(45, 1);
    cout << "Группа:";
    cout << getGroup();
    consoleCursorGoToXY(2, 2);
    cout << "Преподователь:";
    consoleCursorGoToXY(2, 3);
    if (teacherSurname != "") {
        cout << teacherSurname << " ";
    }
    cout << teacherName << " ";
    if (teacherPatronymic != "") {
        cout << teacherPatronymic << " ";
    }

    consoleCursorGoToXY(0, 4);
}

void RecordNode::printHeadRecordCardSNP() {
    consoleCoutLetter("|", 0, 1, 4);
    consoleCoutLetter("|", 89, 1, 4);
    consoleCursorGoToXY(5, 4);
    cout << "ФИО";
    consoleCursorGoToXY(81, 4);
    cout << "Оценка";

    consoleCursorGoToXY(0, 5);
}

void RecordNode::printEditRecordOne(int num) {
    consoleCoutLetter("|", 0, 1, 4 + num);
    consoleCoutLetter("|", 89, 1, 4 + num);
    consoleCursorGoToXY(2, 4 + num);
    cout << num;
    consoleCursorGoToXY(5, 4 + num);
    if (surname != "") {
        cout << surname << " ";
    }
    cout << name << " ";
    if (patronymic != "") {
        cout << patronymic << " ";
    }
    consoleCursorGoToXY(84, 4 + num);
    cout << "___";
    consoleCursorGoToXY(84, 4 + num);
    cout << value;

    consoleCursorGoToXY(0, 5 + num);
}

void RecordNode::printStudentOne() {
    cout << "| ";
    cout << subject;
    consoleSpace(27 - (2 + subject.length()));
    cout << getValue(value);
    consoleSpace(47 - 27 - getValue(value).length());
    cout << "|";
    cout << endl;
}

void RecordNode::printRecordOne(int num) {
    consoleCoutLetter("|", 0, 1, 4 + num);
    consoleCoutLetter("|", 89, 1, 4 + num);
    consoleCursorGoToXY(2, 4 + num);
    cout << num;
    consoleCursorGoToXY(5, 4 + num);
    if (surname != "") {
    cout << surname << " ";
    }
    cout << name << " ";
    if (patronymic != "") {
        cout << patronymic << " ";
    }
    consoleCursorGoToXY(85, 4 + num);
    cout << getValue(value);

    consoleCursorGoToXY(0, 5 + num);
}

LineNode* StudentNode::copyStudent() {
    LineNode* line = new LineNode;
    line->type = 'S';
    copyNumber(this->number, line->number);
    line->checksumNumber = this->checksumNumber;
    line->surname = this->surname;
    line->name = this->name;
    line->patronymic = this->patronymic;
    line->institute = this->institute;
    line->faculty = this->faculty;
    line->training = this->training;
    line->course = this->course;
    line->group = this->group;
    line->payment = this->payment;
    line->year = this->year;
    line->department = this->department;
    line->date = this->date;
    line->gender = this->gender;
    line->address = this->address;
    line->status = this->status;
    line->checksumData = this->checksumData;

    return line;
}

LineNode* RecordNode::copyRecord() {
    LineNode* line = new LineNode;
    line->type = 'R';
    copyNumber(line->number, this->number);
    line->checksumNumber = this->checksumNumber;
    line->surname = this->surname;
    line->name = this->name;
    line->patronymic = this->patronymic;
    line->institute = this->institute;
    line->faculty = this->faculty;
    line->training = this->training;
    line->course = this->course;
    line->group = this->group;
    line->payment = this->payment;
    line->year = this->year;
    line->department = this->department;
    line->date = this->date;
    line->subject = this->subject;
    line->teacherSurname = this->teacherSurname;
    line->teacherName = this->teacherName;
    line->teacherPatronymic = this->teacherPatronymic;
    line->value = this->value;
    line->room = this->room;
    line->checksumData = this->checksumData;

    return line;
}

StudentNode* StudentNode::nextNode() {
    return this->next;
}

RecordNode* RecordNode::nextNode() {
    return this->next;
}

void InstituteNode::resetSM() {
    this->nodeSuccess = 0;
    this->nodeMistake = 0;
    this->operationSuccess = 0;
    this->operationMistake = 0;
}

int InstituteNode::checkUniqueSNP(LineNode* line) {
    StudentNode* node = headStudentsList;
    while (node != nullptr) {
        if (compareSNP(node, line) != 0) {
            return compareSNP(node, line); //В данной группе уже есть студент с таким ФИО
        }
        node = node->next;
    }
    return 0;
}

int InstituteNode::compareSNP(StudentNode* node, LineNode* line) {
    if ((node->institute == line->institute) && (node->faculty == line->faculty) && (node->course == line->course) && (node->group == line->group)) {
        if ((node->surname != "") && (line->surname != "") && (node->patronymic != "") && (line->patronymic != "")) {
            if (node->surname != line->surname) {
                return 0;
            }
            if (node->name != line->name) {
                return 0;
            }
            if (node->patronymic != line->patronymic) {
                return 0;
            }
            return 1;
        }

        if (((node->surname == "") && (node->patronymic == "")) || ((line->surname == "") && (line->patronymic == ""))) {
            if (node->name != line->name) {
                return 0;
            }
            return 1;
        }

        if ((node->surname == "") || (line->surname == "")) {
            if (node->name != line->name) {
                return 0;
            }
            if (node->patronymic != line->patronymic) {
                return 0;
            }
            return 1;
        }

        if ((node->patronymic == "") || (line->patronymic == "")) {
            if (node->name != line->name) {
                return 0;
            }
            if (node->surname != line->surname) {
                return 0;
            }
            return 1;
        }

        return 1; //В данной группе уже есть студент с таким ФИО
    }
    else {
        return 0;
    }
}

int InstituteNode::checkUniqueGroup(LineNode* line) {
    StudentNode* node = headStudentsList;
    while (node != nullptr) {
        if (compareGroup(node, line) != 0) {
            return compareGroup(node, line); //Номера совпали
        }
        node = node->next;
    }
    return 0;
}

int InstituteNode::compareGroup(StudentNode* node, LineNode* line) {
    if ((node->institute == line->institute) && (node->faculty == line->faculty) && (node->course == line->course) && (node->group == line->group)) {
        if (node->training != line ->training) {
            return 1; //Некоторые данные у одинаковых групп не совпали
        }
        if (node->payment != line->payment) {
            return 2; //Некоторые данные у одинаковых групп не совпали
        }
        if (node->year != line->year) {
            return 3; //Некоторые данные у одинаковых групп не совпали
        }
        if (node->department != line->department) {
            return 4; //Некоторые данные у одинаковых групп не совпали
        }
        return 0;
    }
    return 0;
}

int InstituteNode::checkUniqueNumber(string* str) {
    StudentNode* node = headStudentsList;
    while (node != nullptr) {
        if ((compareNumber(node->number, str)) == 1) {
            return 1; //Номера совпали
        }
        node = node->next;
    }
    return 0;
}

int InstituteNode::compareNumber(string* str1, string* str2) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            if (str1[i][j] != str2[i][j]) {
                return 0; //Не равны
            }
        }
    }
    return 1;
}

int InstituteNode::checkUniqueRoom(LineNode* line) {
    RecordNode* node = headRecordsList;
    while (node != nullptr) {
        if ((compareRoom(node, line)) != 0) {
            return 1; //Разные ведомости
        }
        node = node->next;
    }
    return 0;
}

int InstituteNode::compareRoom(RecordNode* node, LineNode* line) {
    if (line->room == node->room) {
        if (line->date != node->date) {
            return 1;
        }
        if (line->subject != node->subject) {
            return 2;
        }
        if (line->teacherSurname != node->teacherSurname) {
            return 3;
        }
        if (line->teacherName != node->teacherName) {
            return 4;
        }
        if (line->teacherPatronymic != node->teacherPatronymic) {
            return 5;
        }
    }
    return 0; //Ведомости равны
}

string InstituteNode::generateRecordRoom() {
    RecordNode* node = headRecordsList;
    int num = 0;
    while (node != nullptr) {
        if (stoi(node->room) > num) {
            num = stoi(node->room);
        }
        node = node->next;
    }
    return to_string(num + 1);
}

void InstituteNode::generateNumber(LineNode* line) {
    string surname = toBigRus(line->surname);
    for (int i = 0; i < 4; i++) {
        if (surname[i] == '\0') {
            break;
        }
        line->number[0][i] = surname[i];
    }

    string name = toBigRus(line->name);
    for (int i = 0; i < 4; i++) {
        if (name[i] == '\0') {
            break;
        }
        line->number[1][i] = name[i];
    }

    string patronymic = toBigRus(line->patronymic);
    for (int i = 0; i < 4; i++) {
        if (patronymic[i] == '\0') {
            break;
        }
        line->number[2][i] = patronymic[i];
    }

    tm ptm;
    time_t t = time(0);
    gmtime_s(&ptm, &t);
    string date = "";
    date = date + addZero(to_string(ptm.tm_mday), 2) + addZero(to_string(ptm.tm_mon + 1), 2) + addZero(to_string(ptm.tm_year + 1900), 4) + addZero(to_string(ptm.tm_min + 1), 2) + addZero(to_string(ptm.tm_sec + 1), 2);

    for (int i = 0; i < 4; i++) {
        line->number[3][i] = date[i];
    }

    for (int i = 0; i < 4; i++) {
        line->number[4][i] = date[i + 4];
    }

    for (int i = 0; i < 4; i++) {
        line->number[5][i] = date[i + 8];
    }

    string str = "";
    do {
        str = addZero(to_string(rand() % 10000), 4);
        for (int i = 0; i < 4; i++) {
            line->number[6][i] = str[i];
        }

        str = addZero(to_string(rand() % 10000), 4);
        for (int i = 0; i < 4; i++) {
            line->number[7][i] = str[i];
        }
    } while (checkUniqueNumber(line->number) == 1);
}

StudentNode* InstituteNode::findStudent(LineNode* line) {
    StudentNode* node = headStudentsList;
    while (node != nullptr) {
        if ((line->surname == node->surname) && (line->name == node->name) && (line->patronymic == node->patronymic) && (line->institute == node->institute) && (line->faculty == node->faculty) && (line->course == node->course) && (line->group == node->group)) {
            return node;
        }
        node = node->next;
    }
    return nullptr;
}

RecordNode* InstituteNode::findRecord(LineNode* line) {
    RecordNode* node = headRecordsList;
    while (node != nullptr) {
        if (line->room == node->room) {
            return node;
        }
        node = node->next;
    }
    return nullptr;
}

StudentNode* InstituteNode::findGroup(LineNode* line) {
    StudentNode* node = headStudentsList;
    while (node != nullptr) {
        if ((line->institute == node->institute) && (line->faculty == node->faculty) && (line->course == node->course) && (line->group == node->group)) {
            return node;
        }
        node = node->next;
    }
    return nullptr;
}

void InstituteNode::add(LineNode* line) {
    if (line->getErr() == 0) {
        line->errorUnique[0] = checkUniqueGroup(line);
        if (line->errorUnique[0] == 0) {
            if (line->type == 'S') {
                addStudent(line);
                return;
            }

            if (line->type == 'R') {
                addRecord(line);
                return;
            }
        }
        else {
            addFail(line);
            return;
        }
    }

    else {
        addFail(line);
        return;
    }
    return;
}

void InstituteNode::addStudent(LineNode* line) {
    line->errorUnique[1] = checkUniqueNumber(line->number);
    if (line->errorUnique[1] == 0) {
        line->errorUnique[2] = checkUniqueSNP(line);
        if (line->errorUnique[2] == 0) {
            nodeSuccess++;
            StudentNode* newStydent = new StudentNode(line);
            //Добавление в алфавитном порядке снизу
            if (headStudentsList == nullptr) {
                headStudentsList = newStydent;
                endStudentsList = newStydent;
            }
            else {
                StudentNode* node = endStudentsList;
                string FIO1 = "";
                string FIO2 = "";
                FIO1 = newStydent->surname + newStydent->name + newStydent->patronymic;
                FIO2 = node->surname + node->name + node->patronymic;

                bool comp = 0;
                while (true) {
                    if (compareString(toSmallRus(FIO1), toSmallRus(FIO2)) != 2) {
                        comp = 1;
                        break;
                    }
                    if (node->prev != nullptr) {
                        node = node->prev;
                        FIO2 = node->surname + node->name + node->patronymic;
                    }
                    else {
                        break;
                    }
                }

                if (!comp) { //Остановка из-за того, что nullptr
                    addStartStudent(newStydent);
                }
                else {
                    addAfterStudent(node, newStydent);
                }
            }
            return;
        }
    }
    addFail(line);
}

void InstituteNode::addRecord(LineNode* line) {
    line->errorUnique[3] = checkUniqueRoom(line);
    if (line->errorUnique[3] == 0) {
        nodeSuccess++;
        RecordNode* newRecord = new RecordNode(line);
        //Добавление в алфавитном порядке снизу
        if (headRecordsList == nullptr) {
            headRecordsList = newRecord;
            endRecordsList = newRecord;
        }
        else {
            RecordNode* node = endRecordsList;
            string FIO1 = "";
            string FIO2 = "";
            FIO1 = newRecord->surname + newRecord->name + newRecord->patronymic;
            FIO2 = node->surname + node->name + node->patronymic;

            bool comp = 0;
            while (true) {
                if (compareString(toSmallRus(FIO1), toSmallRus(FIO2)) != 2) {
                    comp = 1;
                    break;
                }
                if (node->prev != nullptr) {
                    node = node->prev;
                    FIO2 = node->surname + node->name + node->patronymic;
                }
                else {
                    break;
                }
            }

            if (!comp) { //Остановка из-за того, что nullptr
                addStartRecord(newRecord);
            }
            else {
                addAfterRecord(node, newRecord);
            }
        }
        return;
    }
    addFail(line);
}

void InstituteNode::addFail(LineNode* line) {
    nodeMistake++;
    if (failList == nullptr) {
        failList = line;
        lastFailList = line;
    }
    else {
        lastFailList->next = line;
        lastFailList = line;
    }
    return;
}

void InstituteNode::deleteAll() {
    cout << endl;
    cout << "Начало удачения данных" << endl;

    StudentNode* nodeS = headStudentsList;
    while (nodeS != nullptr) {
        nodeS = headStudentsList->next;
        delete headStudentsList;
        headStudentsList = nodeS;
        nodeSuccess++;
    }

    RecordNode* nodeR = headRecordsList;
    while (nodeR != nullptr) {
        nodeR = headRecordsList->next;
        delete headRecordsList;
        headRecordsList = nodeR;
        nodeSuccess++;
    }

    LineNode* nodeF = failList;
    while (nodeF != nullptr) {
        nodeF = failList->next;
        delete failList;
        failList = nodeF;
        nodeSuccess++;
    }

    cout << "Удаление завершено, удалено " << nodeSuccess << " " << worlEnd_запись[getWordEnd(nodeSuccess)] << " (в том числе некорректных)" << endl;
    resetSM();
}

void InstituteNode::deleteOneStydent(string* number) {
    StudentNode* node = headStudentsList;
    while (node != nullptr) {
        if (compareNumber(number, node->number) == 1) {
            if (node != nullptr) {

                if (node == headStudentsList) {
                    headStudentsList = node->next;
                }

                if (node == endStudentsList) {
                    endStudentsList = node->prev;

                }

                if (node->next != nullptr) {
                    node->next->prev = node->prev;
                }

                if (node->prev != nullptr) {
                    node->prev->next = node->next;
                }

                delete node;
            }
            return;
        }
        node = node->next;
    }
}

void InstituteNode::deleteOneStydent(StudentNode* node) {
    if (node != nullptr) {

        if (node == headStudentsList) {
            headStudentsList = node->next;
        }

        if (node == endStudentsList) {
            endStudentsList = node->prev;

        }

        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }

        if (node->prev != nullptr) {
            node->prev->next = node->next;
        }

        delete node;
    }
}

void InstituteNode::deleteOneRecord(RecordNode* node) {
    if (node != nullptr) {

        if (node == headRecordsList) {
            headRecordsList = node->next;
        }

        if (node == endRecordsList) {
            endRecordsList = node->prev;

        }

        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }

        if (node->prev != nullptr) {
            node->prev->next = node->next;
        }

        delete node;
    }
}

void InstituteNode::deleteRecord(LineNode* line) {
    RecordNode* node = headRecordsList;
    while (node != nullptr) {
        if (node->room == line->room) {
            deleteOneRecord(node);
            node = headRecordsList;
        }
        else {
            node = node->next;
        }
    }
}

void InstituteNode::deleteGroup(LineNode* line) {
    StudentNode* node = headStudentsList;
    while (node != nullptr) {
        if ((node->institute == line->institute) && (node->faculty == line->faculty) && (node->course == line->course) && (node->group == line->group)) {
            deleteOneStydent(node);
            node = headStudentsList;
        }
        else {
            node = node->next;
        }
    }
}

void InstituteNode::addStartStudent(StudentNode* newStydent) {
    headStudentsList->prev = newStydent;
    newStydent->next = headStudentsList;
    headStudentsList = newStydent;
}

void InstituteNode::addAfterStudent(StudentNode* node, StudentNode* newStydent) {
    newStydent->prev = node;
    newStydent->next = node->next;
    node->next = newStydent;
    if (endStudentsList == node) {
        endStudentsList = newStydent;
    }
}

void InstituteNode::addStartRecord(RecordNode* newRecord) {
    headRecordsList->prev = newRecord;
    newRecord->next = headRecordsList;
    headRecordsList = newRecord;
}
void InstituteNode::addAfterRecord(RecordNode* node, RecordNode* newRecord) {
    newRecord->prev = node;
    newRecord->next = node->next;
    node->next = newRecord;
    if (endRecordsList == node) {
        endRecordsList = newRecord;
    }
}

void InstituteNode::printLineStudents() {
    cout << endl;
    cout << "Список студентов: " << endl;
    StudentNode* node = headStudentsList;
    while (node != nullptr) {
        node->printLineGeneral();
        cout << "    Рожд." << node->date << "   Пол:" << node->gender << "   Адрес:" << node->address;
        cout << "   ";
        cout << "(" << getStatus(node->status) << ")";
        if (true) {
            cout << endl;
        }

        node = node->next;
    }

    if (headStudentsList == nullptr) {
        cout << "Список студентов пуст" << endl;
    }
}

void InstituteNode::printLineRecords() {
    cout << endl;
    cout << "Список ведомостей: " << endl;
    RecordNode* node = headRecordsList;
    while (node != nullptr) {
        node->printLineGeneral();
        cout << "    Провед." << node->date << "   Предмет:" << node->subject << "   Оценка:";
        cout << getValue(node->value);

        cout << "   Преподователь:";
        if (node->teacherSurname != "") {
            cout << node->teacherSurname << " ";
        }
        cout << node->teacherName << " ";
        if (node->teacherPatronymic != "") {
            cout << node->teacherPatronymic << " ";
        }
        cout << "  Номер ведомости №" << node->room << endl;

        node = node->next;
    }

    if (headRecordsList == nullptr) {
        cout << "Список ведомостей пуст" << endl;
    }
}

void InstituteNode::printFailList(int num) {
    LineNode* node = failList;
    while (node != nullptr) {
        node->coutStr();
        if (num) {
            node->printErr(node);
        }
        node = node->next;
    }
}