#include <stdio.h>
#include "common/color.h"
#include "ui.h"

int main() {
    setCursor(HIDE);
    while(1){
        system("cls");
        printCenter("%sHello World, %s By Heechan", COLOR_RED, COLOR_GREEN);
    }
    return 0;
}
