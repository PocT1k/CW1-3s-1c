#include "Struct.h"

using namespace std;


string getStringBeforeSep(string& strLine, LineNode* line) {
    deleteSpace(strLine);
    int i = 0;
    while ((strLine[i] != '\0') && (strLine[i] != ';')) {
        i++;
    }
    string str = strLine.substr(0, i);
    line->subLen(i);
    if (strLine[i] != '\0') {
        strLine = strLine.substr(i + 1, strLine.length() - i - 1);
        deleteSpace(strLine);
    }
    else {
        strLine = "";
    }
    deleteSpace(str);

    return str;
}

int checkLine_Lenght(string& strLine, LineNode* line) {
    while (strLine[line->getLen()] != '\0') {
        if (strLine[line->getLen()] == line->sep) {
            line->amountDataThis++;
        }
        line->addLen(1);
    }
    if (line->getLen() < line->lenStrMin) {
        return 1;
    }
    return 0;
}

int checkLine_Syntax(string& strLine, LineNode* line) {
    if ((strLine[0] != '[') || (strLine[2] != ']') || (strLine[3] != ':') || (strLine[8] != '-') || (strLine[13] != '-') || (strLine[18] != '-') || (strLine[23] != '-') || (strLine[28] != '-') || (strLine[33] != '-') || (strLine[38] != '-') || (strLine[43] != ';') || (strLine[50] != ';')) {
        return 1;
    }
    return 0;
}

int checkLine_Type(string& strLine, LineNode* line) {
    if (strLine[1] == 'S') {
        line->type = 'S';
        return 0;
    }
    if (strLine[1] == 'R') {
        line->type = 'R';
        return 0;
    }
    return 1;
}

int checkLine_AmountData(string& strLine, LineNode* line) {
    if (line->type == 'S') {
        if (line->amountDataThis != line->amountDataMinStudent - 1) {
            return 1;
        }
        return 0;
    }
    if (line->type == 'R') {
        if (line->amountDataThis != line->amountDataMinRecord - 1) {
            return 2;
        }
        return 0;
    }
    if (line->amountDataThis != line->amountDataMin - 1) {
        return 3;
    }
}

int checkLine_Number(string& strLine, LineNode* line) {
    string number = getStringBeforeSep(strLine, line);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            //cout << number[4 + i * 5 + j] << " " << checkNumber(number[4 + i * 5 + j]) << " ";
            if ((checkNumber(number[4 + i * 5 + j])) == 1) {
                line->number[i][j] = number[4 + i * 5 + j];
            }
            else {
                return 1;
            }
        }
    }
    return 0;
}

int checkLine_ChecksumNumber(string& strLine, LineNode* line) {
    string number;
    string checksumNumber = getStringBeforeSep(strLine, line);
    if (checksumNumber.length() != 6) {
        return 1;
    }
    number = getNumber(line->number);

    //cout << getChecksum(number) << endl;

    if (getChecksum(number) != (checksumNumber)) {
        return 1;
    }
    line->checksumNumber = checksumNumber;
    return 0;
}

int checkLine_Surname(string& strLine, LineNode* line) {
    string surname = getStringBeforeSep(strLine, line);
    if (surname != "") {
        if (isBigRus(surname[0]) == 0) {
            return 1;
        }
        int i = 1;
        while (surname[i] != '\0') {
            if ((isSmallRus(surname[i]) != 1) && (isBigRus(surname[i]) != 1) && (surname[i] != '-') && (surname[i] != ' ')) {
                return 2;
            }
            i++;
        }
        line->surname = surname;
        return 0;
    }
    return 0;
}

int checkLine_Name(string& strLine, LineNode* line) {
    string name = getStringBeforeSep(strLine, line);
    if (name == "") {
        return 1;
    }
    if (isBigRus(name[0]) == 0) {
        return 2;
    }
    int i = 1;
    while (name[i] != '\0') {
        if ((isSmallRus(name[i]) != 1) && (isBigRus(name[i]) != 1) && (name[i] != '-') && (name[i] != ' ')) {
            return 3;
        }
        i++;
    }
    line->name = name;
    return 0;
}

int checkLine_Patronymic(string& strLine, LineNode* line) {
    string patronymic = getStringBeforeSep(strLine, line);
    if (patronymic != "") {
        if (isBigRus(patronymic[0]) == 0) {
            return 1;
        }
        int i = 1;
        while (patronymic[i] != '\0') {
            if ((isSmallRus(patronymic[i]) != 1) && (isBigRus(patronymic[i]) != 1) && (patronymic[i] != '-') && (patronymic[i] != ' ')) {
                return 2;
            }
            i++;
        }
        line->patronymic = patronymic;
        return 0;
    }
    return 0;
}

int checkLine_Institute(string& strLine, LineNode* line) {
    string institute = getStringBeforeSep(strLine, line);
    if (institute.length() != 1) {
        return 1;
    }
    if ((institute[0] != 'М') && (institute[0] != 'M')) {
        return 2;
    }
    line->institute = "М";
    return 0;
}

int checkLine_Faculty(string& strLine, LineNode* line) {
    string faculty = getStringBeforeSep(strLine, line);
    if ((faculty.length() < 1) || (2 < faculty.length())) {
        return 1;
    }
    int i = 0;
    while (faculty[i] != '\0') {
        if (isDigit(faculty[i]) == 0) {
            return 2;
        }
        i++;
    }
    int facultyDigit = stoi(faculty);
    if ((facultyDigit < 1) || (facultyDigit > 14)) {
        return 3;
    }
    line->faculty = faculty;
    return 0;
}

int checkLine_Training(string& strLine, LineNode* line) {
    string training = getStringBeforeSep(strLine, line);
    if (training.length() == 1) {
        if ((training[0] == 'О') || (training[0] == 'O') || (training[0] == 'З')) {
            if (training[0] == 'З') {
                line->training = "З";
                return 0;
            }
            else {
                line->training = "О";
                return 0;
            }
        }
        return 1;
    }
    if ((training == "Оз") || (training == "Oз")) {
        line->training = "Оз";
        return 0;
    }
    return 2;
}

int checkLine_Course(string& strLine, LineNode* line) {
    string course = getStringBeforeSep(strLine, line);
    if (course.length() != 1) {
        return 1;
    }
    if (isDigit(course[0]) == 0) {
        return 2;
    }
    int courseDigit = stoi(course);
    if ((courseDigit < 0) || (8 < courseDigit)) {
        return 3;
    }
    line->course = course;
    return 0;
}

int checkLine_Group(string& strLine, LineNode* line) {
    string group = getStringBeforeSep(strLine, line);
    if ((group.length() != 1) && (group.length() != 2)) {
        return 1;
    }

    int i = 0;
    while (group[i] != '\0') {
        if (isDigit(group[i]) == 0) {
            return 2;
        }
        i++;
    }

    int groupDigit = stoi(group);
    if (groupDigit == 0) {
        return 3;
    }
    if ((group.length() == 2) && (group[0] == '0')) {
        group = group[1];
    }
    line->group = group;
    return 0;
}

int checkLine_Payment(string& strLine, LineNode* line) {
    string payment = getStringBeforeSep(strLine, line);
    if (payment.length() == 1) {
        if (payment[0] == 'А') {
            line->payment = "А";
            return 0;
        }
        if (payment[0] == 'М') {
            line->payment = "М";
            return 0;
        }
        if (payment[0] == 'Б') {
            line->payment = "Б";
            return 0;
        }
        if (payment[0] == 'С') {
            line->payment = "С";
            return 0;
        }
        return 1;
    }
    if (payment == "Бк") {
        line->payment = "Бк";
        return 0;
    }
    if (payment == "Ак") {
        line->payment = "Ак";
        return 0;
    }
    if (payment == "Мк") {
        line->payment = "Мк";
        return 0;
    }
    if (payment == "Ск") {
        line->payment = "Ск";
        return 0;
    }
    return 2;
}

int checkLine_Year(string& strLine, LineNode* line) {
    string year = getStringBeforeSep(strLine, line);
    if (year.length() != 4) {
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        if (isDigit(year[i]) == 0) {
            return 2;
        }
    }
    int yearDigit = stoi(year);
    if (yearDigit < 1930) {
        return 3;
    }
    line->year = year;
    return 0;
}

int checkLine_Department(string& strLine, LineNode* line) {
    string department = getStringBeforeSep(strLine, line);
    if (department.length() != 3) {
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        if (isDigit(department[i]) == 0) {
            return 2;
        }
    }
    int departmentDigit = stoi(department);
    if (departmentDigit == 0) {
        return 3;
    }
    line->department = department;
    return 0;
}

int checkLine_Date(string& strLine, LineNode* line) {
    string date = getStringBeforeSep(strLine, line);
    if (date.length() != 10) {
        return 1;
    }
    if ((date[2] != '.') || (date[5] != '.')) {
        return 2;
    }
    if ((isDigit(date[0]) == 0) || (isDigit(date[1]) == 0) || (isDigit(date[3]) == 0) || (isDigit(date[4]) == 0) || (isDigit(date[6]) == 0) || (isDigit(date[7]) == 0) || (isDigit(date[8]) == 0) || (isDigit(date[9]) == 0)) {
        return 3;
    }

    string date1str = date.substr(6, 4);
    int date1num = stoi(date1str);
    if (line->type == 'R') {
        if ((date1num < 1930) || (date1num > 2023)) {
            return 4;
        }
    }

    if (line->type == 'S') {
        if (date1num > 2023) {
            return 4;
        }
    }

    string date2str = date.substr(3, 2);
    int date2num = stoi(date2str);
    if ((date2num < 1) || (date2num > 12)) {
        return 5;
    }

    string date3str = date.substr(0, 2);
    int date3num = stoi(date3str);
    if ((date3num < 1) || (date3num > 31)) {
        return 6;
    }

    line->date = date;
    return 0;
}

int checkLine_Gender(string& strLine, LineNode* line) {
    string gender = getStringBeforeSep(strLine, line);
    if (gender.length() != 1) {
        return 1;
    }
    if ((gender[0] != 'М') && (gender[0] != 'M') && (gender[0] != 'Ж') && (gender[0] != 'С') && (gender[0] != 'C')) {
        return 2;
    }
    if ((gender[0] == 'М') || (gender[0] == 'M')) {
        line->gender = "М";
        return 0;
    }
    if ((gender[0] == 'С') || (gender[0] == 'C')) {
        line->gender = "С";
        return 0;
    }
    line->gender = "Ж";
    return 0;
}

int checkLine_Address(string& strLine, LineNode* line) {
    string address = getStringBeforeSep(strLine, line);
    if (address == "") {
        return 1;
    }
    int i = 0;
    while (address[i] != '\0') {
        if ((isDigit(address[i]) == 0) && (isSmallRus(address[i]) == 0) && (isBigRus(address[i]) == 0) && (address[i] != ' ') && (address[i] != '-') && (address[i] != '.') && (address[i] != ',')) {
            cout << address << " " << i << endl;
            return 2;
        }
        i++;
    }
    line->address = address;
    return 0;
}

int checkLine_Status(string& strLine, LineNode* line) {
    string status = getStringBeforeSep(strLine, line);
    if (status.length() != 1) {
        return 1;
    }
    if (isDigit(status[0]) == 0) {
        return 2;
    }
    int statusDigit = stoi(status);
    if ((statusDigit < 0) || (3 < statusDigit)) {
        return 3;
    }
    line->status = status;
    return 0;
}

int checkLine_Subject(string& strLine, LineNode* line) {
    string subject = getStringBeforeSep(strLine, line);
    if (subject == "") {
        return 1;
    }
    int i = 0;
    while (subject[i] != '\0') {
        if ((isDigit(subject[i]) == 0) && (isSmallRus(subject[i]) == 0) && (isBigRus(subject[i]) == 0) && (subject[i] != ' ') && (subject[i] != '-') && (subject[i] != '.') && (subject[i] != ',')) {
            return 2;
        }
        i++;
    }
    line->subject = subject;
    return 0;
}

int checkLine_TeacherSurname(string& strLine, LineNode* line) {
    string surname = getStringBeforeSep(strLine, line);
    if (surname != "") {
        if (isBigRus(surname[0]) == 0) {
            return 1;
        }
        int i = 1;
        while (surname[i] != '\0') {
            if ((isSmallRus(surname[i]) != 1) && (isBigRus(surname[i]) != 1) && (surname[i] != '-') && (surname[i] != ' ')) {
                return 2;
            }
            i++;
        }
        line->teacherSurname = surname;
        return 0;
    }
    return 0;
}

int checkLine_TeacherName(string& strLine, LineNode* line) {
    string name = getStringBeforeSep(strLine, line);
    if (name == "") {
        return 1;
    }
    if (isBigRus(name[0]) == 0) {
        return 2;
    }
    int i = 1;
    while (name[i] != '\0') {
        if ((isSmallRus(name[i]) != 1) && (isBigRus(name[i]) != 1) && (name[i] != '-') && (name[i] != ' ')) {
            return 3;
        }
        i++;
    }
    line->teacherName = name;
    return 0;
}

int checkLine_TeacherPatronymic(string& strLine, LineNode* line) {
    string patronymic = getStringBeforeSep(strLine, line);
    if (patronymic != "") {
        if (isBigRus(patronymic[0]) == 0) {
            return 1;
        }
        int i = 1;
        while (patronymic[i] != '\0') {
            if ((isSmallRus(patronymic[i]) != 1) && (isBigRus(patronymic[i]) != 1) && (patronymic[i] != '-') && (patronymic[i] != ' ')) {
                return 2;
            }
            i++;
        }
        line->teacherPatronymic = patronymic;
        return 0;
    }
    return 0;
}

int checkLine_Value(string& strLine, LineNode* line) {
    string value = getStringBeforeSep(strLine, line);
    if (value == "") {
        line->value = "-";
        return 0;
    }
    if (value.length() == 1) {
        if (value[0] == '-') {
            line->value = "-";
            return 0;
        }
        if (isDigit(value[0]) == 0) {
            return 1;
        }
        int valueDigit = stoi(value);
        if ((valueDigit < 2) || (5 < valueDigit)) {
            return 2;
        }
        line->value = value;
        return 0;
    }
    if (value.length() == 3) {
        if (value == "н/я") {
            line->value = "н/я";
            return 0;
        }
        if (value == "н/д") {
            line->value = "н/д";
            return 0;
        }
        if (value == "н/к") {
            line->value = "н/к";
            return 0;
        }
    }
    return 3;
}

int checkLine_Room(string& strLine, LineNode* line) {
    string room = getStringBeforeSep(strLine, line);
    if (room == "") {
        return 1;
    }
    int i = 0;
    while (room[i] != '\0') {
        if (isDigit(room[i]) == 0) {
            return 2;
        }
        i++;
    }
    line->room = room;
    return 0;
}

int checkLine_ChecksumData(string& strLine, LineNode* line) {
    string data = "";
    string checksumData = getStringBeforeSep(strLine, line);
    if (checksumData.length() != 6) {
        return 1;
    }
    data = data + line->type + getNumber(line->number) + line->checksumNumber + line->surname + line->name + line->patronymic + line->institute + line->faculty + line->training + line->course + line->group + line->payment + line->year + line->department + line->date;
    if (line->type == 'S') {
        data = data + line->gender + line->address + line->status;
    }
    if (line->type == 'R') {
        data = data + line->subject + line->teacherSurname + line->teacherName + line->teacherPatronymic + line->value + line->room;
    }

    //cout << getChecksum(data) << endl;

    if (getChecksum(data) != (checksumData)) {
        return 1;
    }
    line->checksumData = checksumData;
    return 0;
}


string Node::getGroup() {
    string str = "";
    str = str + institute + faculty + training + "-" + course + addZero(group, 2) + payment + "-" + year + " (каф." + department + ")";
    return str;
}

void Node::printLineGeneral() {
    cout << getGroup();
    consoleSpace(29 - getGroup().length());
    if (surname != "") {
        cout << surname << " ";
    }
    cout << name << " ";
    if (patronymic != "") {
        cout << patronymic << " ";
    }
}

void Node::writeGeneral(ostream& stream, Node* node) {
    stream << ";" << node->checksumNumber << ";" << node->surname << ";" << node->name << ";" << node->patronymic << ";" << node->institute << ";" << node->faculty << ";" << node->training << ";" << node->course << ";" << node->group << ";" << node->payment << ";" << node->year << ";" << node->department << ";" << node->date;
    stream << ";";
}

void LineNode::coutError() {
    for (int i = 0; i < quantityErrorLine; i++) {
        cout << errorLine[i];
    }
    cout << " ";
    for (int i = 0; i < quantityErrorStudent; i++) {
        cout << errorStudent[i];
    }
    cout << " ";
    for (int i = 0; i < quantityErrorRecord; i++) {
        cout << errorRecord[i];
    }
    cout << " " << err << endl;
}

void LineNode::setErr() {
    for (int i = 0; i < quantityErrorLine; i++) {
        if (this->errorLine[i] != 0) { this->err = 1; }
    }
    for (int i = 0; i < quantityErrorStudent; i++) {
        if (this->errorStudent[i] != 0) { this->err = 1; }
    }
    for (int i = 0; i < quantityErrorRecord; i++) {
        if (this->errorRecord[i] != 0) { this->err = 1; }
    }
}

void LineNode::resetErr() {
    this->err = 0;
}

bool LineNode::getErr() {
    return this->err;
}

void LineNode::coutErr() {
    cout << this->err << endl;
}

void LineNode::createStr(string str) {
    this->str = str;
}

void LineNode::coutStr() {
    cout << this->str << endl;
}

string LineNode::getStr() {
    return this->str;
}

void LineNode::createLen(int len) {
    this->len = len;
}

void LineNode::addLen(int num) {
    this->len = this->len + num;
}

void LineNode::subLen(int num) {
    this->len = this->len - num;
}

int LineNode::getLen() {
    return this->len;
}

LineNode* LineNode::copyLineNode() {
    LineNode* line = new LineNode;
    line->type = this->type;
    copyNumber(line->number, this->number);
    line->checksumNumber = this->checksumData;
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
    line->subject = this->subject;
    line->teacherSurname = this->teacherSurname;
    line->teacherName = this->teacherName;
    line->teacherPatronymic = this->teacherPatronymic;
    line->value = this->value;
    line->room = this->room;
    line->checksumData = this->checksumData;

    return line;
}

void LineNode::printErr(LineNode* node) {
    Err err_Total[] = { err_Lenght, err_Syntax, err_Type, err_AmountData, err_Number, err_ChecksumNumber, err_Surname, err_Name, err_Patronymic, err_Institute, err_Faculty, err_Training, err_Course, err_Group, err_Payment, err_Year, err_Department, err_Date, err_ChecksumData };
    Err err_Student[] = { err_Gender, err_Address, err_Status };
    Err err_Record[] = { err_Subject, err_TeacherSurname, err_TeacherName, err_TeacherPatronymic, err_Value, err_Room };
    Err err_Unique[] = { err_UniqueGroup, err_UniqueNumber, err_UniqueSNA, err_UniqueRoom };

    string sep = "  ";
    for (int i = 0; i < node->quantityErrorLine; i++) {
        if (node->errorLine[i] != 0) {
            cout << sep;
            err_Total[i](node->errorLine[i]);
            cout << endl;
        }
    }
    for (int i = 0; i < node->quantityErrorStudent; i++) {
        if (node->errorStudent[i] != 0) {
            cout << sep;
            err_Student[i](node->errorStudent[i]);
            cout << endl;
        }
    }
    for (int i = 0; i < node->quantityErrorRecord; i++) {
        if (node->errorRecord[i] != 0) {
            cout << sep;
            err_Record[i](node->errorRecord[i]);
            cout << endl;
        }
    }
    for (int i = 0; i < node->quantityErrorUnique; i++) {
        if (node->errorUnique[i] != 0) {
            cout << sep;
            err_Unique[i](node->errorUnique[i]);
            cout << endl;
        }
    }
}

/*Функция считывания, обработки и записи полученного значения
Куда записывать, что было в начале, функция проверки корретности данных, функция печати ошибки о некорректности, заполняемое поле, кол-во заполняемых полей(для печати ошибки внизу), отспуп по ширине, какой по счёту(для понимая сколько от всего введённого отспуать вниз), сколько ещё взять вниз для заполнения, сколько ещё взять вниз для вывода ошибки*/
int fillFiedls(LineNode* line, string strLine, checkLine checkFunk, Err checkErr, string field, int numFields, short w, short i, short hStart, short down) {
    string copeLine = "";
    int run = 1;
    while (run) { //Вводи данное поле, пока оно не станет корректным
        consoleCursorGoToXY(w, i + hStart); //Печатаем редактируемое значение
        cout << field;
        consoleCursorGoToXY(w, i + hStart);
        cout << strLine;
        consoleCursorGoToXY(w, i + hStart);
        int outFlag = getConsole(strLine, w, i + hStart, field.length()); //Считываем данные
        copeLine = strLine;
        consoleCursorGoToXY(0, numFields + hStart + down);
        if (outFlag) {
            return 1;
        }

        run = checkFunk(strLine, line); //Проверяем данные на корректномть
        consoleClearLine();
        consoleCursorGoToXY(0, numFields + hStart + down);
        if (run != 0) { //Печатаем если ошибка
            checkErr(run);
            cout << endl;
        }
    }
    consoleCursorGoToXY(w, i + hStart); //Вывод полученного
    cout << field;
    consoleCursorGoToXY(w, i + hStart);
    cout << copeLine;
    consoleCursorGoToXY(0, numFields + hStart + down); //Очистка после возможного вывода ошибок
    consoleClearLine();
    consoleCursorGoToXY(0, numFields + hStart + down);
    return 0;
}

void LineNode::coutCreateStudentCart(string arrFields[], int size1, string strLines[]) {
    //cout << "| Отчество         12345678901234567890        |" << endl;
    string arrFillIn[] = { "Студент", "Фамилия", "Имя", "Отчество", "Институт", "Факультет", "Форма обучения", "Курс", "Группа", "Коммерц. группы", "Год поступления", "Кафедра", "Дата рождения", "Пол", "Адрес", "Статус обучения" };

    consoleCoutLetter("|", 0, size1 + 1);
    consoleCoutLetter("|", 47, size1 + 1);
    consoleCoutMesage(arrFillIn, 2, size1 + 1);
    consoleCoutMesage(arrFields, 19, size1, 1);
    consoleCoutMesage(strLines, 19, size1, 1);
}

void LineNode::coutFindStudentCart(string arrFields[], int size1) {
    string arrFillIn[] = { "Студент", "Фамилия", "Имя", "Отчество", "Институт", "Факультет", "Курс", "Группа" };
    consoleCoutLetter("|", 0, size1 + 1);
    consoleCoutLetter("|", 47, size1 + 1);
    consoleCoutMesage(arrFillIn, 2, size1 + 1);
    consoleCoutMesage(arrFields, 19, size1, 1);
}

void LineNode::coutCreateRecordCart(string arrFields[], int size1) {
    string arrFillIn[] = { "Ведомость", "Предмет", "Дата проведения", "Фамилия пр.", "Имя пр.", "Отчество пр." };
    consoleCoutLetter("|", 0, size1 + 1);
    consoleCoutLetter("|", 47, size1 + 1);
    consoleCoutMesage(arrFillIn, 2, size1 + 1);
    consoleCoutMesage(arrFields, 19, size1, 1);
}

void LineNode::coutFindGroupCart(string arrFields[], int size1) {
    string arrFillIn[] = { "Группа", "Институт", "Факультет", "Курс", "Группа" };
    consoleCoutLetter("|", 0, size1 + 1);
    consoleCoutLetter("|", 47, size1 + 1);
    consoleCoutMesage(arrFillIn, 2, size1 + 1);
    consoleCoutMesage(arrFields, 19, size1, 1);
}

void LineNode::coutFindRecordCart(string arrFields[], int size1) {
    string arrFillIn[] = { "Ведомость" };
    consoleCoutLetter("|", 0, size1);
    consoleCoutLetter("|", 47, size1);
    consoleCoutMesage(arrFillIn, 2, size1);
    consoleCoutMesage(arrFields, 19, size1);
}

int LineNode::fillStydent(LineNode* line, int operatinFlag) { //Функция заполнения полей для создания/редактирования студента
    this->type = 'S';

    int numFields = 15;
    string arrFieldsStudent[15] = { arrFields[0], arrFields[0], arrFields[0], arrFields[5], arrFields[4], arrFields[4], arrFields[5], arrFields[4], arrFields[4], arrFields[2], arrFields[3], arrFields[1], arrFields[5], arrFields[0], arrFields[5] };
    checkLine checkFunks[15] = { checkLine_Surname, checkLine_Name, checkLine_Patronymic, checkLine_Institute, checkLine_Faculty, checkLine_Training , checkLine_Course, checkLine_Group, checkLine_Payment, checkLine_Year, checkLine_Department, checkLine_Date, checkLine_Gender, checkLine_Address, checkLine_Status };
    string strLines[15] = { line->surname, line->name, line->patronymic, line->institute, line->faculty, line->training, line->course,line->group, line->payment, line->year, line->department, line->date, line->gender, line->address, line->status };
    Err arrErr[15] = { err_Surname, err_Name, err_Patronymic, err_Institute, err_Faculty, err_Training, err_Course, err_Group, err_Payment, err_Year, err_Department, err_Date, err_Gender, err_Address, err_Status };
    coutCreateStudentCart(arrFieldsStudent, numFields, strLines);

    for (int i = 0; i < (numFields); i++) {
        int outFlag = fillFiedls(line, strLines[i], checkFunks[i], arrErr[i], arrFieldsStudent[i], numFields, 19, i, 1);

        if (outFlag) {
            return 1;
        }
    }

    consoleCursorGoToXY(0, numFields + 1);
    return 0;
}

int LineNode::findStydent(LineNode* line) { //Функция заполнения полей для поиска студента
    int numFields = 7;
    string arrFieldsStudent[7] = { arrFields[0], arrFields[0], arrFields[0], arrFields[5], arrFields[4], arrFields[5], arrFields[4] };
    checkLine checkFunks[7] = { checkLine_Surname, checkLine_Name, checkLine_Patronymic, checkLine_Institute, checkLine_Faculty , checkLine_Course, checkLine_Group };
    string strLines[7] = { arrFields[6], arrFields[6], arrFields[6], arrFields[6], arrFields[6], arrFields[6], arrFields[6] };
    Err arrErr[7] = { err_Surname, err_Name, err_Patronymic, err_Institute, err_Faculty, err_Course, err_Group };
    coutFindStudentCart(arrFieldsStudent, 7);

    for (int i = 0; i < (numFields); i++) {
        int outFlag = fillFiedls(line, strLines[i], checkFunks[i], arrErr[i], arrFieldsStudent[i], numFields, 19, i, 1);

        if (outFlag) {
            return 1;
        }
    }

    consoleCursorGoToXY(0, numFields + 1);
    return 0;
}

int LineNode::fillRecord(LineNode* line) {//Функция заполнения полей для создания ведомости
    this->type = 'R';

    int numFields = 5;
    string arrFieldsStudent[5] = { arrFields[0], arrFields[1], arrFields[0], arrFields[0], arrFields[0] };
    checkLine checkFunks[5] = { checkLine_Subject, checkLine_Date, checkLine_TeacherSurname, checkLine_TeacherName, checkLine_TeacherPatronymic };
    string strLines[5] = { arrFields[6], arrFields[6], arrFields[6], arrFields[6], arrFields[6] };
    Err arrErr[5] = { err_Subject, err_Date, err_TeacherSurname, err_TeacherName, err_TeacherPatronymic };
    coutCreateRecordCart(arrFieldsStudent, 5);    

    for (int i = 0; i < (numFields); i++) {
        int outFlag = fillFiedls(line, strLines[i], checkFunks[i], arrErr[i], arrFieldsStudent[i], numFields, 19, i, 1);

        if (outFlag) {
            return 1;
        }
    }

    consoleCursorGoToXY(0, numFields + 1);
    return 0;
}

int LineNode::findRecord(LineNode* line) { //Функция заполнения полей для создания нахождения
    int numFields = 1;
    string arrFieldsStudent[1] = { arrFields[1] };
    checkLine checkFunks[1] = { checkLine_Room };
    string strLines[1] = { arrFields[6] };
    Err arrErr[1] = { err_Room };
    coutFindRecordCart(arrFieldsStudent, 1);

    for (int i = 0; i < (numFields); i++) {
        int outFlag = fillFiedls(line, strLines[i], checkFunks[i], arrErr[i], arrFieldsStudent[i], numFields, 19, i);

        if (outFlag) {
            return 1;
        }
    }

    consoleCursorGoToXY(0, numFields);
    return 0;
}

int LineNode::findGroup(LineNode* line) { //Функция заполнения полей для нахождения группы
    int numFields = 4;
    string arrFieldsStudent[4] = { arrFields[5], arrFields[4], arrFields[5], arrFields[4] };
    checkLine checkFunks[4] = { checkLine_Institute, checkLine_Faculty , checkLine_Course, checkLine_Group };
    string strLines[4] = { arrFields[6], arrFields[6], arrFields[6], arrFields[6] };
    Err arrErr[4] = { err_Institute, err_Faculty, err_Course, err_Group };
    coutFindGroupCart(arrFieldsStudent, 4);

    for (int i = 0; i < (numFields); i++) {
        int outFlag = fillFiedls(line, strLines[i], checkFunks[i], arrErr[i], arrFieldsStudent[i], numFields, 19, i, 1);

        if (outFlag) {
            return 1;
        }
    }

    consoleCursorGoToXY(0, numFields + 1);
    return 0;
}

LineNode* LineNode::nextNode(LineNode* node) {
    return node->next;
}