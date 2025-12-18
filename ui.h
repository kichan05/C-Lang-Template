//
// Created by 바키찬 on 2025-10-13.
//

#ifndef C_UI_H
#define C_UI_H

#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>

enum CURSOR_TYPE { HIDE, UNDERBAR, BLOCK };

int getWindowWidth();
int getWindowHeight();

void gotoxy(int x, int y);
void movexy(int x, int y);
int currentX();
int currentY();

void setCursor(enum CURSOR_TYPE curType);

void printCenter(char *fmp, ...);

#endif //C_UI_H
