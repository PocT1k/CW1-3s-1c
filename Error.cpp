#include "Error.h"

using namespace std;


string fileDam = ", файл повреждён";
void err_Lenght(int err) {
    if (err == 1) { cout << "Недостаточная длинна строки" << fileDam; return; }
    cout << "Необработанная ошибка 1:" << err;
}
void err_Syntax(int err) {
    if (err == 1) { cout << "Несоотвествие синтаксису файла" << fileDam; return; }
    cout << "Необработанная ошибка 2:" << err;
}
void err_Type(int err) {
    if (err == 1) { cout << "Некорректый тип записи" << fileDam; return; }
    cout << "Необработанная ошибка 3:" << err;
}
void err_AmountData(int err) {
    if (err == 1) { cout << "Недостаточное количество данных" << fileDam; return; }
    if (err == 2) { cout << "Недостаточное количество данных" << fileDam; return; }
    if (err == 3) { cout << "Недостаточное количество данных" << fileDam; return; }
    cout << "Необработанная ошибка 4:" << err;
}
void err_Number(int err) {
    if (err == 1) { cout << "Некорректный личный номер" << fileDam; return; }
    cout << "Необработанная ошибка 5:" << err;
}
void err_ChecksumNumber(int err) {
    if (err == 1) { cout << "Не совпадает контрольная сумма личного номера" << fileDam; return; }
    cout << "Необработанная ошибка 6:" << err;
}
void err_Surname(int err) {
    if (err == 1) { cout << "Фамилия начинается не с большой буквы"; return; }
    if (err == 2) { cout << "В фамилии присутсвуют недопустимые символы"; return; }
    cout << "Необработанная ошибка 7:" << err;
}
void err_Name(int err) {
    if (err == 1) { cout << "Отсутствует имя"; return; }
    if (err == 2) { cout << "Имя начинается не с большой буквы"; return; }
    if (err == 3) { cout << "В имени присутствуют недопустимые символы"; return; }
    cout << "Необработанная ошибка 8:" << err;
}
void err_Patronymic(int err) {
    if (err == 1) { cout << "Отчество начинается не с большой буквы"; return; }
    if (err == 2) { cout << "В отчестве присутсвуют недопустимые символы"; return; }
    cout << "Необработанная ошибка 9:" << err;
}
void err_Institute(int err) {
    if (err == 1) { cout << "Неправильная длинна значения института"; return; }
    if (err == 2) { cout << "Неправильный институт"; return; }
    cout << "Необработанная ошибка 10:" << err;
}
void err_Faculty(int err) {
    if (err == 1) { cout << "Недопустимая длинна значения факультета"; return; }
    if (err == 2) { cout << "В номере факультета присутсвует не число"; return; }
    if (err == 3) { cout << "Недопустимый номер факультета"; return; }
    cout << "Необработанная ошибка 11:" << err;
}
void err_Training(int err) {
    if (err == 1) { cout << "Недопустимое значени формы обучения"; return; }
    if (err == 2) { cout << "Недопустимое значени формы обучения"; return; }
    cout << "Необработанная ошибка 12:" << err;
}
void err_Course(int err) {
    if (err == 1) { cout << "Недопустимое значение курса"; return; }
    if (err == 2) { cout << "В номере курса присутсвует не число"; return; }
    if (err == 3) { cout << "Недопустимое значение курса"; return; }
    cout << "Необработанная ошибка 13:" << err;
}
void err_Group(int err) {
    if (err == 1) { cout << "Недопустимая длинна значения номера группы"; return; }
    if (err == 2) { cout << "В номере группа присутствует не число"; return; }
    if (err == 3) { cout << "Недопустимое значение номера группы"; return; }
    cout << "Необработанная ошибка 14:" << err;
}
void err_Payment(int err) {
    if (err == 1) { cout << "Недопустимое значение коммерцианализированности группы"; return; }
    if (err == 2) { cout << "Недопустимое значение коммерцианализированности группы"; return; }
    cout << "Необработанная ошибка 15:" << err;
}
void err_Year(int err) {
    if (err == 1) { cout << "Неправильная длинна значения года"; return; }
    if (err == 2) { cout << "В значении года присутствует не число"; return; }
    if (err == 3) { cout << "Недопустимое значение года"; return; }
    cout << "Необработанная ошибка 16:" << err;
}
void err_Department(int err) {
    if (err == 1) { cout << "Недопустимая длинна значения номера кафедры"; return; }
    if (err == 2) { cout << "В номере кафедры присутсвуют не числа"; return; }
    if (err == 3) { cout << "Недопустимое значение номера кафедры"; return; }
    cout << "Необработанная ошибка 17:" << err;
}
void err_Date(int err) {
    if (err == 1) { cout << "Недопустимое значение длинны даты"; return; }
    if (err == 2) { cout << "Не корректная форма записи даты"; return; }
    if (err == 3) { cout << "В значении даты присутсвуют не числа"; return; }
    if (err == 4) { cout << "Недопустимое значение года"; return; }
    if (err == 5) { cout << "Недопустимое зеначние месяца"; return; }
    if (err == 6) { cout << "Недопустимое значение дня"; return; }
    cout << "Необработанная ошибка 18:" << err;
}

void err_Gender(int err) {
    if (err == 1) { cout << "Недопустимая длинна значения пола"; return; }
    if (err == 2) { cout << "Недопустимое значение пола"; return; }
    cout << "Необработанная ошибка 19:" << err;
}
void err_Address(int err) {
    if (err == 1) { cout << "Отсутствует адрес"; return; }
    if (err == 2) { cout << "В значении адреса присутсвуеют недопустимые символы"; return; }
    cout << "Необработанная ошибка 20:" << err;
}
void err_Status(int err) {
    if (err == 1) { cout << "Недопустимая длинна значения статуса обучения"; return; }
    if (err == 2) { cout << "В значении статуса обучения присутсвуют не числа"; return; }
    if (err == 3) { cout << "Недопустимое значение статуса обучения"; return; }
    cout << "Необработанная ошибка 21:" << err;
}

void err_Subject(int err) {
    if (err == 1) { cout << "Отсутсвует предмет"; return; }
    if (err == 2) { cout << "В значении предмета присутсвуют недопустимые символы"; return; }
    cout << "Необработанная ошибка 22:" << err;
}
void err_TeacherSurname(int err) {
    if (err == 1) { cout << "Фамилия преподователя начинается не с большой буквы"; return; }
    if (err == 2) { cout << "В фамилии преподователя присутствуют недопустимые символы"; return; }
    cout << "Необработанная ошибка 23:" << err;
}
void err_TeacherName(int err) {
    if (err == 1) { cout << "Отсутсвует имя преподователя"; return; }
    if (err == 2) { cout << "Имя преподователя начинается не с большой буквы"; return; }
    if (err == 3) { cout << "В имени преподователя присутствуют недопустимые символы"; return; }
    cout << "Необработанная ошибка 24:" << err;
}
void err_TeacherPatronymic(int err) {
    if (err == 1) { cout << "Отчество преподователя начинается не с большой буквы"; return; }
    if (err == 2) { cout << "В отчестве преподователя присутствуют недопустимые символы"; return; }
    cout << "Необработанная ошибка 25:" << err;
}
void err_Value(int err) {
    if (err == 1) { cout << "В значении оценки присутсвует не число"; return; }
    if (err == 2) { cout << "Недопустимое значение оценки"; return; }
    if (err == 3) { cout << "Недопустимое значение оценки"; return; }
    cout << "Необработанная ошибка 26:" << err;
}
void err_Room(int err) {
    if (err == 1) { cout << "Отсутствует номер ведомости"; return; }
    if (err == 2) { cout << "В номере ведомости присутствует не число"; return; }
    cout << "Необработанная ошибка 27:" << err;
}

void err_ChecksumData(int err) {
    if (err == 1) { cout << "Не совпадает контрольная сумма всех значений" << fileDam; return; }
    cout << "Необработанная ошибка 28:" << err;
}

void err_UniqueGroup(int err) {
    if (err == 1) { cout << "У одинаковых групп разные данные, отличается форма обучения"; return; }
    if (err == 2) { cout << "У одинаковых групп разные данные, отличается коммерцианализированность группы"; return; }
    if (err == 3) { cout << "У одинаковых групп разные данные, отличается год поступления"; return; }
    if (err == 4) { cout << "У одинаковых групп разные данные, отличается кафедра"; return; }
    cout << "Необработанная ошибка 29:" << err;
}
void err_UniqueNumber(int err) {
    if (err == 1) { cout << "Пользователь с таким уникальным номером уже существует" << fileDam; return; }
    cout << "Необработанная ошибка 30:" << err;
}
void err_UniqueSNA(int err) {
    if (err == 1) { cout << "В одной группе не допускается наличие студентов с одинаковами ФИО"; return; }
    cout << "Необработанная ошибка 31:" << err;
}
void err_UniqueRoom(int err) {
    if (err == 1) { cout << "У одинаковых ведомостей разные данные, отличается дата"; return; }
    if (err == 2) { cout << "У одинаковых ведомостей разные данные, отличается предмет"; return; }
    if (err == 3) { cout << "У одинаковых ведомостей разные данные, отличается фамилия преподователя"; return; }
    if (err == 4) { cout << "У одинаковых ведомостей разные данные, отличается имя преподователя"; return; }
    if (err == 5) { cout << "У одинаковых ведомостей разные данные, отличается отчество преподователя"; return; }
    cout << "Необработанная ошибка 32:" << err;
}