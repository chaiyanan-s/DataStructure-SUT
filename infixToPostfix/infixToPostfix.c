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

char stackpop() {
    if(top == NULL) {
        return 0;
    } else {
        return top->c;
    }
}

int checkpr(char temp) {
    int pr;
    if(temp == '*' || temp == '/') {
        return 2;
    } else if(temp == '^') {
        return 3;
    } else {
        return 1;
    }
}
int checkoper(char ck) {
    if(stackpop == NULL) {
        push(ck);
    } else {
        if(checkpr(ck) <= checkpr(stackpop())) {
            while(checkpr(ck) <= checkpr(stackpop()) && stackpop()!=0) {
                printf("%c", pop());
            }
        }
        push(ck);
    }
}

void main() {
    char ch;
    while((ch = getchar()) != '\n') {
        if(isdigit(ch) || isalpha(ch)) {
            printf("%c",ch);
        } else {
            checkoper(ch);
        }
    }
    while(stackpop() != 0){
        printf("%c", pop());
    }
}