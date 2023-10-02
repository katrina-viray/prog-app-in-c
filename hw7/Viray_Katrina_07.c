#include <stdio.h>
#include <string.h>

// read in sentence into character array until '\n' is reached.
void sentence(char s[201]){
    char ch;
    int i = 0;
    
    printf("Enter a sentence (up to 200 characters):\n");
    
    while ((ch = getchar()) != '\n' && i < 200) {
        s[i++] = ch;
    }
    
    s[i] = '\0';
}

// print sentence in reverse order. 

void reverse(char s[201]){
    int l = strlen(s);
    for(int i = l - 1; i >= 0; i--){
        putchar(s[i]);
    }
}

int main() {
    // char array of 201 cells for 200 characters + string termination '\0'
    char s [201];

    printf("please enter a sentence of at most 200 characters:\n");
    sentence(s);
    reverse(s);
}
