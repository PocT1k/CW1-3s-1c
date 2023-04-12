#include "Functions.h"

using namespace std;


void test() {
    cout << "------------------------------------" << endl;
    //cout << INT_MAX << endl;


    //char c = 't';
    //cout << c << endl;

    //ofstream fout;
    //fout.open("��������1.ins");
    //fout << "123 �� ��� Yes No";
    //fout.close();
    //ifstream fin;
    //fin.open("��������1.ins");
    //string str1;
    //getline(fin, str1);
    //cout << str1 << endl;


    cout << "------------------------------------" << endl;
}

void readLine(string& strLine, LineNode* line) { //��������� ���������� ����� �� �����
    //line->coutStr();

    checkLine checkLineFile_Start[] = { checkLine_Syntax, checkLine_Type, checkLine_AmountData }; //���������� �������� ������
    checkLine checkLineFile_Total[] = { checkLine_Number, checkLine_ChecksumNumber, checkLine_Surname, checkLine_Name, checkLine_Patronymic, checkLine_Institute, checkLine_Faculty, checkLine_Training , checkLine_Course, checkLine_Group, checkLine_Payment, checkLine_Year, checkLine_Department, checkLine_Date }; //����� �������� �����
    checkLine checkLineFile_Student[] = { checkLine_Gender, checkLine_Address, checkLine_Status }; //�������� �������� ��� �����
    checkLine checkLineFile_Record[] = { checkLine_Subject, checkLine_TeacherSurname, checkLine_TeacherName, checkLine_TeacherPatronymic, checkLine_Value, checkLine_Room }; //�������� ��������� ��� �����
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

void readFileLine(istream& stream, InstituteNode& institute) { //��������� ����� �� �����
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
        cout << "������ ������ ����� " << institute.fileToWork << endl;
        return;
    }
    if (!instituteDataFile.is_open()) {
        cout << "������ �������� ����� " << institute.fileToWork << endl;
        return;
    }
    cout << "������ ���� " << institute.fileToWork << endl;

    istream* stream = nullptr;
    stream = &instituteDataFile;

    while (!stream->eof()) {
        readFileLine(*stream, institute);
    }
    instituteDataFile.close();

    cout << "������ ����� " << institute.fileToWork << " ���������" << endl;
    if (institute.nodeSuccess != 0) {
        cout << "������� ��������� " << institute.nodeSuccess << " " << institute.worlEnd_������[getWordEnd(institute.nodeSuccess)] << endl;

        if (institute.nodeMistake != 0) {
            cout << "�� ������� ��������� " << institute.nodeMistake << " " << institute.worlEnd_������[getWordEnd(institute.nodeMistake)] << endl;
            cout << "������ �� ����������� �������:" << endl;
            cout << endl;
        }
        else {
            cout << "�� ����������� ������� ���" << endl;
        }
    }
    else {
        cout << "���� ����" << endl;
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
        cout << "������ �������� ����� " << institute.fileToWork << endl;
        return;
    }
    if (!instituteDataFile.is_open()) {
        cout << "������ �������� ����� " << institute.fileToWork << endl;
        return;
    }
    cout << "������ ���� " << institute.fileToWork << endl;

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

    cout << "����� ����� " << institute.fileToWork << " ���������" << endl;
    cout << "������� ��������� " << institute.nodeSuccess << " " << institute.worlEnd_������[getWordEnd(institute.nodeSuccess)];
    if (institute.nodeMistake != 0) {
        cout << " � " << institute.nodeMistake << " �� ������������� " << institute.worlEnd_������[getWordEnd(institute.nodeMistake)];
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
        cout << "�������� ������ �������� ��������" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    line->errorUnique[0] = institute.checkUniqueGroup(line);
    if (line->errorUnique[0] == 0) {
        line->errorUnique[2] = institute.checkUniqueSNP(line);
        if (line->errorUnique[2] == 0) { //���� ����������
            cout << endl;
            cout << "���������� ������ ��������..." << endl;

            institute.generateNumber(line);
            line->checksumNumber = getChecksum(getNumber(line->number));
            string data = "";
            data = data + line->type + getNumber(line->number) + line->checksumNumber + line->surname + line->name + line->patronymic + line->institute + line->faculty + line->training + line->course + line->group + line->payment + line->year + line->department + line->date;
            data = data + line->gender + line->address + line->status;
            line->checksumData = getChecksum(data);

            institute.add(line);
            institute.resetSM();

            cout << "����� ������� ������� ��������!" << endl;
            return;
        }
        else { //errU 2
            line->printErr(line);
            cout << "������� �� ������" << endl;
        }
    }
    else { //errU 0
        line->printErr(line);
        cout << "������� �� ������" << endl;
    }
}

void editStydent(InstituteNode& institute) {
    LineNode* line = new LineNode;
    system("CLS");

    int outFlag = line->findStydent(line);
    if (outFlag) {
        cout << endl;
        cout << "�������������� �������� ��������" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    cout << endl;
    cout << "����� ��������..." << endl;
    StudentNode* node = institute.findStudent(line);
    if (line != nullptr) {
        delete line;
    }

    if(node == nullptr) {
        cout << endl;
        cout << "������� �� ������" << endl;
        return;
    }
    else { //���� ��������������
        node->printStudentCard();
        cout << endl;

        char key;
        bool run = 1;
        cout << "���������� ��������������?" << endl;
        cout << "1 ��" << endl;
        cout << "2 ���" << endl;
        cout << endl;

        while (run) {
            key = _getch();
            switch (key) {
            case kESC:
            case k2:
                system("CLS");
                cout << "�������������� �����������" << endl;
                run = 0;
                break;
            case k1:
            case kENTER: { //��������������
                LineNode* line = node->copyStudent();
                system("CLS");

                int outFlag = line->fillStydent(line, 1);
                if (outFlag) {
                    cout << endl;
                    cout << "�������������� �������� ��������" << endl;
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
                        cout << "�������� ���������..." << endl;

                        string data = "";
                        data = data + line->type + getNumber(line->number) + line->checksumNumber + line->surname + line->name + line->patronymic + line->institute + line->faculty + line->training + line->course + line->group + line->payment + line->year + line->department + line->date;
                        data = data + line->gender + line->address + line->status;
                        line->checksumData = getChecksum(data);

                        institute.deleteOneStydent(node->number);

                        institute.add(line);
                        institute.resetSM();

                        cout << "������� ������� ��������������!" << endl;
                        return;
                    }
                    else { //errU 2
                        line->printErr(line);
                        cout << endl;
                        cout << "������� �� ��������������" << endl;
                    }
                }
                else { //errU 0
                    line->printErr(line);
                    cout << endl;
                    cout << "������� �� ��������������" << endl;
                }
                run = 0;
                break;
            } //��������������
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
        cout << "�������� �������� ��������" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    cout << endl;
    cout << "����� ��������..." << endl;
    StudentNode* node = institute.findStudent(line);
    if (line != nullptr) {
        delete line;
    }

    if (node == nullptr) {
        cout << endl;
        cout << "������� �� ������" << endl;
        return;
    }
    else { //���� ��������
        node->printStudentCard();
        cout << endl;

        char key;
        bool run = 1;
        cout << "���������� ��������?" << endl;
        cout << "1 ��" << endl;
        cout << "2 ���" << endl;
        cout << endl;

        while (run) {
            key = _getch();
            switch (key) {
            case kESC:
            case k2:
                system("CLS");
                cout << "�������� �����������" << endl;
                run = 0;
                break;
            case kENTER:
            case k1:
                institute.deleteOneStydent(node);
                cout << endl;
                cout << "������� �����" << endl;
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
        cout << "����� �������� ������" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    cout << endl;
    cout << "����� ��������..." << endl;
    StudentNode* node = institute.findStudent(line);
    if (line != nullptr) {
        delete line;
    }

    if (node == nullptr) {
        cout << endl;
        cout << "��������� ������� �� ������" << endl;
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
            cout << "�� ������� �������� �� ������� ���������" << endl;
        }
        institute.resetSM();
    }
}

void createRecord(InstituteNode& institute) {
    LineNode* line = new LineNode; //������� ����� ������
    system("CLS");

    int outFlag = line->findGroup(line);
    if (outFlag) {
        cout << endl;
        cout << "����� ������ ������" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    cout << endl;
    cout << "����� ������..." << endl;
    StudentNode* node = institute.findGroup(line);

    if (node == nullptr) {
        cout << endl;
        cout << "��������� ������ �� �������" << endl;
        return;
    }
    else { //���� ������ �������, �� ���������� ��������� ���������
        system("CLS");

        int outFlag = line->fillRecord(line);
        if (outFlag) {
            cout << "�������� ����� ��������� ��������" << endl;
            if (line != nullptr) {
                delete line;
            }
            return;
        }

        cout << "�������� ����� ���������..." << endl;

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

        cout << "����� ��������� ������� �������!" << endl;
        cout << "���������� �����:" << line->room << endl;

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
        cout << "�������������� ��������� ��������" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    cout << endl;
    cout << "����� ���������..." << endl;
    RecordNode* record = institute.findRecord(line);
    if (line != nullptr) {
        delete line;
    }

    if (record == nullptr) {
        cout << endl;
        cout << "��������� ��������� �� �������" << endl;
        return;
    }
    else {
        record->printHeadRecordCard();

        char key;
        bool run = 1;
        cout << endl;
        cout << "���������� ��������������?" << endl;
        cout << "1 ��" << endl;
        cout << "2 ���" << endl;
        cout << endl;

        while (run) {
            key = _getch();
            switch (key) {
            case kESC:
            case k2:
                system("CLS");
                cout << "�������������� �����������" << endl;
                run = 0;
                break;
            case kENTER:
            case k1: {
                system("CLS");
                record->printHeadRecordCard();
                record->printHeadRecordCardSNP();
                RecordNode* node = institute.headRecordsList;

                while (node != nullptr) { //while ��� ������� �� ���� ���������� � ������ ����� ���� ���������
                    if (node->room == record->room) {
                        institute.operationSuccess++;
                        node->printEditRecordOne(institute.operationSuccess);
                    }
                    node = node->nextNode();
                }

                node = institute.headRecordsList;
                LineNode* line = new LineNode;
                while (node != nullptr) { //while ��� ������� �� ���� ���������� � �������������� ������
                    if (node->room == record->room) {
                        institute.operationMistake++;

                        line->value = node->value;
                        outFlag = node->editRecord(line, institute.operationSuccess, institute.operationMistake);
                        if (outFlag) {
                            cout << endl;
                            cout << "�������������� ��������� ��������, ��� ��� �������� ��������� ���������" << endl;
                            if (line != nullptr) { delete line; }
                            institute.resetSM();
                            return;
                        }

                        node->value = line->value;

                        string data = ""; // ������� ����� ����������� ����� ������
                        data = data + "R" + getNumber(node->number) + node->checksumNumber + node->surname + node->name + node->patronymic + node->institute + node->faculty + node->training + node->course + node->group + node->payment + node->year + node->department + node->date;
                        data = data + node->subject + node->teacherSurname + node->teacherName + node->teacherPatronymic + node->value + node->room;
                        node->checksumData = getChecksum(data);
                    }
                    node = node->nextNode();
                }
                institute.resetSM();

                if (line != nullptr) { delete line; }

                cout << endl;
                cout << "��������� � ��������� ������� �������!" << endl;

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
        cout << "�������� ��������� ��������" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    cout << endl;
    cout << "����� ���������..." << endl;
    RecordNode* node = institute.findRecord(line);
    if (line != nullptr) {
        delete line;
    }

    if (node == nullptr) {
        cout << endl;
        cout << "��������� ��������� �� �������" << endl;
        return;
    }
    else {
        node->printHeadRecordCard();

        char key;
        bool run = 1;
        cout << endl;
        cout << "���������� ��������?" << endl;
        cout << "1 ��" << endl;
        cout << "2 ���" << endl;
        cout << endl;

        while (run) {
            key = _getch();
            switch (key) {
            case kESC:
            case k2:
                system("CLS");
                cout << "�������� �����������" << endl;
                run = 0;
                break;
            case kENTER:
            case k1: {
                LineNode* line = node->copyRecord();
                institute.deleteRecord(line);
                cout << endl;
                cout << "��������� �������" << endl;
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
        cout << "����� ��������� ������" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    cout << endl;
    cout << "����� ���������..." << endl;
    RecordNode* node = institute.findRecord(line);
    if (line != nullptr) {
        delete line;
    }

    if (node == nullptr) {
        cout << endl;
        cout << "��������� ��������� �� �������" << endl;
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
        cout << "�������� ������ ��������" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    cout << endl;
    cout << "����� ������..." << endl;
    StudentNode* node = institute.findGroup(line);
    if (line != nullptr) {
        delete line;
    }

    if (node == nullptr) {
        cout << endl;
        cout << "��������� ������ �� �������" << endl;
        return;
    }
    else {
        node->printHeadGroupCard();

        char key;
        bool run = 1;
        cout << endl;
        cout << "���������� ��������?" << endl;
        cout << "1 ��" << endl;
        cout << "2 ���" << endl;
        cout << endl;

        while (run) {
            key = _getch();
            switch (key) {
            case kESC:
            case k2:
                system("CLS");
                cout << "�������� �����������" << endl;
                run = 0;
                break;
            case kENTER:
            case k1: {
                LineNode* line = node->copyStudent();
                institute.deleteGroup(line);
                cout << endl;
                cout << "������ �������" << endl;
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
        cout << "����� ������ ������" << endl;
        if (line != nullptr) {
            delete line;
        }
        return;
    }

    cout << endl;
    cout << "����� ������..." << endl;
    StudentNode* node = institute.findGroup(line);
    if (line != nullptr) {
        delete line;
    }

    if (node == nullptr) {
        cout << endl;
        cout << "��������� ������ �� �������" << endl;
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