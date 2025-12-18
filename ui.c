//
// Created by 바키찬 on 2025-10-13.
//

#include "ui.h"
#include <stdarg.h>

int getWindowWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return -1;
    return (csbi.srWindow.Right - csbi.srWindow.Left + 1);
}

int getWindowHeight() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return -1;
    return (csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
}

void gotoxy(int x, int y) {
    static COORD pos = {0,};
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void movexy(int x, int y) {
    gotoxy(currentX() + x, currentY() + y);
}

void setCursor(enum CURSOR_TYPE curType) {
    static CONSOLE_CURSOR_INFO CurInfo = {0,};

    switch (curType) {
        case HIDE:
            CurInfo.dwSize = 1;
            CurInfo.bVisible = FALSE;
            break;
        case UNDERBAR:
            CurInfo.dwSize = 1;
            CurInfo.bVisible = TRUE;
            break;
        case BLOCK:
            CurInfo.dwSize = 100;
            CurInfo.bVisible = TRUE;
            break;
    }

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

int currentX() {
    static CONSOLE_SCREEN_BUFFER_INFO curInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    return curInfo.dwCursorPosition.X;
}

int currentY() {
    static CONSOLE_SCREEN_BUFFER_INFO curInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    return curInfo.dwCursorPosition.Y;
}

void printCenter(char *fmp, ...) {
    int width = getWindowWidth();

    char buffer[512];
    va_list args;
    va_start(args, fmp);
    vsnprintf(buffer, sizeof(buffer), fmp, args);
    va_end(args);

    int stringLength = strlen(buffer);

    gotoxy((width - stringLength) / 2, currentY());
    printf("%s", buffer);
}
