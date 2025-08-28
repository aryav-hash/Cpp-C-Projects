#include<stdio.h>
#include<unistd.h>
int main() {
    // Recording the key presses from the user.
    char c;
    // read 1 byte from the standard input and store it in the c variable and continue till we get
    // inputs to read.
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
    return 0;
}