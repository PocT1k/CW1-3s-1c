#include "Console.h"

using namespace std;


string getLetter(char key) {
    switch (key) {
    case -48:
        key = _getch();
        switch (key) {
        case -112:
            return "�";
        case -111:
            return "�";
        case -110:
            return "�";
        case -109:
            return "�";
        case -108:
            return "�";
        case -107:
            return "�";
        case -127:
            return "�";
        case -106:
            return "�";
        case -105:
            return "�";
        case -104:
            return "�";
        case -103:
            return "�";
        case -102:
            return "�";
        case -101:
            return "�";
        case -100:
            return "�";
        case -99:
            return "�";
        case -98:
            return "�";
        case -97:
            return "�";
        case -96:
            return "�";
        case -95:
            return "�";
        case -94:
            return "�";
        case -93:
            return "�";
        case -92:
            return "�";
        case -91:
            return "�";
        case -90:
            return "�";
        case -89:
            return "�";
        case -88:
            return "�";
        case -87:
            return "�";
        case -86:
            return "�";
        case -85:
            return "�";
        case -84:
            return "�";
        case -83:
            return "�";
        case -82:
            return "�";
        case -81:
            return "�";
        case -80:
            return "�";
        case -79:
            return "�";
        case -78:
            return "�";
        case -77:
            return "�";
        case -76:
            return "�";
        case -75:
            return "�";
        case -74:
            return "�";
        case -73:
            return "�";
        case -72:
            return "�";
        case -71:
            return "�";
        case -70:
            return "�";
        case -69:
            return "�";
        case -68:
            return "�";
        case -67:
            return "�";
        case -66:
            return "�";
        case -65:
            return "�";
        default:
            return "";
        }
    case -47:
        key = _getch();
        switch (key) {
        case -111:
            return "�";
        case -128:
            return "�";
        case -127:
            return "�";
        case -126:
            return "�";
        case -125:
            return "�";
        case -124:
            return "�";
        case -123:
            return "�";
        case -122:
            return "�";
        case -121:
            return "�";
        case -120:
            return "�";
        case -119:
            return "�";
        case -118:
            return "�";
        case -117:
            return "�";
        case -116:
            return "�";
        case -115:
            return "�";
        case -114:
            return "�";
        case -113:
            return "�";
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

void consoleCoutLetter(string let, short w, short h, short hStart) { //��� ��������, ������� � ���� ���������, ������� ��������, ������� ���� ���������
    for (int i = 0; i < h; i++) {
        consoleCursorGoToXY(w, i + hStart);
        cout << let;
    }
}

void consoleCoutMesage(string arr[], short w, short h, short hStart) { //��� ��������, �������  � ���� ���������, ������� ��������, ������� ���� ���������
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

int getConsole(string& strLine, short w, short h, int maxLen, short hStart) { //�� ��� ���������, ������� ��������� ���, ������� ��������� ���, ������������ ������ ����������, ������� ��� ���� ���������
    int len = strLine.length();
    consoleCursorGoToXY(w + len, h + hStart); //������ ������ � ����������� �� ��� �������������
    consoleCursorVisible(true);

    char key;
    bool run = 1;
    while (run){
        key = _getch();
        switch (key) {
        case kESC: //�����
            consoleCursorVisible(false);
            return 1;
        case kENTER: //����
            deleteSpace(strLine);
            consoleCursorVisible(false);
            return 0;
        case kBACKSPACE: { //��������
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
        default: { //���������� �������
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