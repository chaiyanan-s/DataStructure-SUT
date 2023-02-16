#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct nd {
    char c;
    struct nd *next;
}node;
node *top = NULL;

void push(char x) {
    node *n = malloc(sizeof(node));
    n->next = top;
    top = n;
    n->c = x;
}

char pop() {
    char p;
    node *n;
    n = top;
    top = top->next;
    p = n->c;
    free(n);
    return p;
}

void convert(char ch[]) {
    strrev(ch);

    char temp[20]; int j = 0;

    for(int i = 0; ch[i] != '\0'; i++) {
        if(ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/') {
            push(ch[i]);
        } else {
            temp[j++] = ch[i];
            if(top != NULL) {
                temp[j++] = pop();
            }
        }
    }
    strrev(temp);
    puts(temp);
}

void main() {
    char ch[50];
    gets(ch);
    convert(ch);
}