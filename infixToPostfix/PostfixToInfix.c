#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX = 100;

typedef struct nd {
    char c;
    struct nd *next;
}node;

node *top = NULL;
int count = 0;

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
    for (int i = 0; ch[i] != '\0'; i++) {
	    if (ch[i] >= 'a'&& ch[i] <= 'z'|| ch[i] >= 'A' && ch[i] <= 'Z') {
            push(i);
        } else if(ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/' ||
                    ch[i] == '^') {
            char a =  pop();
            char b = pop();
            char p[5];
            p[0] = '(';
            p[1] = b;
            p[2] = ch[i];
            p[3] = a;
            p[4] = ')';

            strrev(p);
            for(int j = 0; j < 5; j++) {
                push(p[j]);
            }
        }
    }

}

void main() {
    char ch[50];
    scanf("%s", &ch);
    convert(ch);

    for(int i = 0; i < 5; i++) {
        printf("%c",pop());
    }
    
}


