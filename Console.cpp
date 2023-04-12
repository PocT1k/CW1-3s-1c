#include "Console.h"

using namespace std;


string getLetter(char key) {
    switch (key) {
    case -48:
        key = _getch();
        switch (key) {
        case -112:
            return "А";
        case -111:
            return "Б";
        case -110:
            return "В";
        case -109:
            return "Г";
        case -108:
            return "Д";
        case -107:
            return "Е";
        case -127:
            return "Ё";
        case -106:
            return "Ж";
        case -105:
            return "З";
        case -104:
            return "И";
        case -103:
            return "Й";
        case -102:
            return "К";
        case -101:
            return "Л";
        case -100:
            return "М";
        case -99:
            return "Н";
        case -98:
            return "О";
        case -97:
            return "П";
        case -96:
            return "Р";
        case -95:
            return "С";
        case -94:
            return "Т";
        case -93:
            return "У";
        case -92:
            return "Ф";
        case -91:
            return "Х";
        case -90:
            return "Ц";
        case -89:
            return "Ч";
        case -88:
            return "Ш";
        case -87:
            return "Щ";
        case -86:
            return "Ъ";
        case -85:
            return "Ы";
        case -84:
            return "Ь";
        case -83:
            return "Э";
        case -82:
            return "Ю";
        case -81:
            return "Я";
        case -80:
            return "а";
        case -79:
            return "б";
        case -78:
            return "в";
        case -77:
            return "г";
        case -76:
            return "д";
        case -75:
            return "е";
        case -74:
            return "ж";
        case -73:
            return "з";
        case -72:
            return "и";
        case -71:
            return "й";
        case -70:
            return "к";
        case -69:
            return "л";
        case -68:
            return "м";
        case -67:
            return "н";
        case -66:
            return "о";
        case -65:
            return "п";
        default:
            return "";
        }
    case -47:
        key = _getch();
        switch (key) {
        case -111:
            return "ё";
        case -128:
            return "р";
        case -127:
            return "с";
        case -126:
            return "т";
        case -125:
            return "у";
        case -124:
            return "ф";
        case -123:
            return "х";
        case -122:
            return "ц";
        case -121:
            return "ч";
        case -120:
            return "ш";
        case -119:
            return "щ";
        case -118:
            return "ъ";
        case -117:
            return "ы";
        case -116:
            return "ь";
        case -115:
            return "э";
        case -114:
            return "ю";
        case -113:
            return "я";
        default:
            return "";
        }
    case 32:
        return " ";
    case 44:
        return ",";
    case 45:
        return "-";
    case 46:
        return ".";
    case 47:
        return "/";
    case 48:
        return "0";
    case 49:
        return "1";
    case 50:
        return "2";
    case 51:
        return "3";
    case 52:
        return "4";
    case 53:
        return "5";
    case 54:
        return "6";
    case 55:
        return "7";
    case 56:
        return "8";
    case 57:
        return "9";
    default:
        return "";
    }
    return "";
}

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void consoleCursorGoToXY(short x, short y) {
    SetConsoleCursorPosition(hStdOut, { x, y });
}

void consoleCursorVisible(bool show) {
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = show;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

void consoleCoutLetter(string let, short w, short h, short hStart) { //Что выводить, сколько в ширь отступать, сколько выводить, сколько вниз отступить
    for (int i = 0; i < h; i++) {
        consoleCursorGoToXY(w, i + hStart);
        cout << let;
    }
}

void consoleCoutMesage(string arr[], short w, short h, short hStart) { //Что выводить, сколько  в ширь отступать, сколько выводить, сколько вниз отступить
    for (int i = 0; i < h; i++) {
        consoleCursorGoToXY(w, i + hStart);
        cout << arr[i];
    }
}

void consoleClearLine() {
    cout << "                                                                                                                                                           " << endl;
}

void consoleSpace(int num) {
    for (int i = 0; i < num; i++) {
        cout << " ";
    }
}

int getConsole(string& strLine, short w, short h, int maxLen, short hStart) { //Во что считывать, сколько отступать бок, сколько отступать низ, максимальная длинна считывания, сколько ещё вниз отступить
    int len = strLine.length();
    consoleCursorGoToXY(w + len, h + hStart); //Ставим курсор в зависимости от уже напечатанного
    consoleCursorVisible(true);

    char key;
    bool run = 1;
    while (run){
        key = _getch();
        switch (key) {
        case kESC: //Выход
            consoleCursorVisible(false);
            return 1;
        case kENTER: //Ввод
            deleteSpace(strLine);
            consoleCursorVisible(false);
            return 0;
        case kBACKSPACE: { //Стирание
            if (len > 0) {
                len--;
                strLine = strLine.substr(0, len);
                consoleCursorGoToXY(w + len, h + hStart);
                if (len >= maxLen) {
                    cout << " ";
                }
                else {
                    cout << "_";
                }
                consoleCursorGoToXY(w + len, h + hStart);
            }
        }
              break;
        default: { //Считывание клавиши
            if (len < maxLen) {
                string sym = getLetter(key);
                if (sym != "") {
                    strLine = strLine + sym;
                    if (sym == " ") {
                        cout << "_";
                    }
                    else {
                        cout << sym;
                    }
                    len++;
                }
            }
        }
        }
    }
}