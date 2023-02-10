#include <stdio.h>
#include <stdlib.h>

typedef struct nd {
        char c;
        struct nd *next;
    }node;

    node *head = NULL;
    node *tail = NULL;
    int count = 0;

void append_list(char ch) {
    node *n = malloc(sizeof(node));
    n->next = NULL;
    if(head == NULL) {
        head = n;
    } else {
        tail->next = n;
    }
    tail = n;
    n->c = ch;
    count++;
}

void delete_node(char ch) {
    node *current;
    node *prev;
    current = head;
    if(head->c == ch) {
        head = head->next;
    } else {
        while((current != NULL) && (current->c!=ch)) {
            prev = current;
            current = current->next;
        } if(current->c == ch) {
            if(tail->c == ch) {
                tail = prev;
            }
            prev->next = current->next;
            current->next = NULL;
        }
    }
    if(current->c == ch) {
        count--;
    } else {
        printf("%c is not in the list\n", ch);
    }
    free(current);
}

void print_list() {
    node *current;
    current = head;
    while(current != NULL) {
        printf("%c", current->c);
        current=current->next;
    }
}
node *search_list(char ch) {
    node *current;
    current = head;

    while((current != NULL) && (current->c != ch)) {
        current = current->next;
    }
    return current;
}
int destroy_list() {
    node *ptr;
    while(count > 0) {
        ptr = head;
        head = head->next;
        count--;
        free(ptr);
    }
}

void append_beforeTail(char ch) {
    node *n = malloc(sizeof(node));
    /*ไม่มีข้อมูล*/
    if(head == NULL) {
        head = n;
        tail = n;
        n->next = NULL;
    /*มี 1 node*/
    } else if(head == tail) {
        n->next = head;
        head->next = NULL;
        tail = head;
        head = n;
    /*มี 2 node*/
    } else if(count == 2) {
        n->next = head->next;
        head->next = n;
        tail = n->next;
    /*มี 3 node ขึ้นไป*/
    } else {
        node *current;
        node *prev;
        current = head;
        while((current->next != NULL) && (current->next != tail) ) {
            current = current->next; 
        }
        if(current->next == tail) {
            current->next = n;
            n->next = tail;
        }
    }
    n->c = ch;
    count++;
}
/* ต่อท้าย node แรก*/
void append_behindHead(int ch){
    node *n = malloc(sizeof(node));
//in case an old list is empty
    if(head == NULL){
        head = n;
        tail = n;
        n->next = NULL;

    //in case an old list has only 1 node
    } else if (head == tail){
        n->next = head->next ; // will set n->next = NULL
        head->next = n;
        tail = n;

    //in case an old list has >= 2 nodes
    } else {
        n->next = head->next ;
        head->next = n; 
    }
        n->c = ch;
        count++;
}

// function for appending new node at the front of a list
void append_front(char ch) { 
    node *n = malloc(sizeof(node)); 
    if(head == NULL) { 
        head = n; 
        tail = n; 
        n->next = NULL; 
    } else { 
        n->next = head; 
        head = n; 
    } 
        n->c = ch; 
        count++ ;
}


int main(){
    printf("\n");
    // append_front
    append_front('a');
    append_front('a');
    append_front('b');
    printf("append front get: ");
    print_list();
    destroy_list();
    printf("\n===============================\n");
    // append_behindHead
    append_behindHead('a');
    printf("\nappend behind head without old node get: ");
    print_list();
    append_behindHead('b');
    printf("\nappend behind head an old node get: ");
    print_list();
    append_behindHead('b');
    append_behindHead('b');
    append_behindHead('b');
    append_behindHead('z');
    printf("\nappend behind head two or more old nodes get: ");
    print_list();

    destroy_list();
    printf("\n===============================\n");
    // append_beforeTail
    append_beforeTail('a');
    printf("\nappend before tail without old node get: ");
    print_list();
    append_beforeTail('b');
    printf("\nappend before tail with an old node get: ");
    print_list();
    append_beforeTail('c');
    printf("\nappend before tail with two old nodes get: ");
    print_list();
    append_beforeTail('c');
    append_beforeTail('c');
    append_beforeTail('c');
    append_beforeTail('z');
    printf("\nappend before tail with three ore more old nodes get: ");
    print_list();
    printf("\n===============================\n");
    // search_list
    printf("\na is located on> %p",search_list('a'));
    printf("\n===============================\n");
    // delete_node
    delete_node('z');
    printf("\nz is deleted and the list without z is: ");
    print_list();
    printf("\n===============================\n");
}