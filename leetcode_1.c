#include <stdio.h>
#include <string.h>

void reversePrefix(char word[], char ch) {
    int n = strlen(word);
    int end = -1;

    for (int k = 0; k < n; k++) {
        if (word[k] == ch) {
            end = k;
            break;
        }
    }

    if (end == -1) return;

    char stack[end + 1];
    int top = -1;

    for (int k = 0; k <= end; k++) {
        stack[++top] = word[k];
    }

    for (int k = 0; k <= end; k++) {
        word[k] = stack[top--];
    }
}

int main() {
    char s[] = "abcdefd";
    reversePrefix(s, 'd');
    printf("%s\n", s);  
    return 0;
}