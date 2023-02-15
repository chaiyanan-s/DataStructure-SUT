#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

void convert

void main() {
    char ch[50];
    scanf("%s", &ch);
    convert(ch);
}