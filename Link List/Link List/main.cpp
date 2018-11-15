//
//  main.cpp
//  Link List
//
//  Created by S M HEMEL on 3/5/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

/*#include <iostream>
#include <algorithm>
using namespace std;
struct node {
    int value;
    node *next, *prev;
    node(){
        next = NULL;
        prev = NULL;
    }
};
node *root=NULL, *till=NULL;
void print_forward() {
    if(root==NULL) return;
    node *now = root;
    while(now != NULL) {
        printf("%d ", now->value);
        now = now->next;
    }
    puts("");
}
void print_backward() {
    if(root==NULL) return;
    node *now = till;
    while(now != NULL) {
        printf("%d ", now->value);
        now = now->prev;
    }
    puts("");
}
void append(int value) {
    if(root==NULL) {
        root = new node();
        root->value = value;
        till = root;
    } else {
        node *New = new node();
        New->value = value;
        New->prev = till;
        till->next = New;
        till = till->next;
    }
}
void Delete(int num) {
    if(root==NULL) return;
    node *now = root;
    if(root->value==num) {
        if(root==till) {
            delete(root);
            root = NULL;
        } else {
            root = root->next;
            root->prev = NULL;
            delete(now);
        }
        return;
    }
    while(now->value!=num && now != NULL) {
        now = now->next;
    }
    if(now->value==num) {
        if(now==till) {
            till = now->prev;
            delete(now);
            till->next = NULL;
            return;
        }
        node *Prev = now->prev, *Next = now->next;
        Prev->next = Next;
        Next->prev = Prev;
        delete(now);
    }
}
bool is_valid(int num){
    if(root==NULL) return false;
    node *now = root;
    while(now != NULL){
        if(now->value==num) return true;
        now = now->next;
    }
    return false;
}
int main() {
    for(int i=0; i<10; i++) {
        append(i);
    }
    print_forward();
    print_backward();
    for(int i=5; i<11; i++) {
        if(is_valid(i)) puts("YES");
        else puts("NO");
    }
    for(int i=0; i<10; i++) {
        Delete(i);
        print_forward();
        print_backward();
    }
    return 0;
}*/
















#include <iostream>
using namespace std;
struct node {
    int value;
    node *next, *prev;
    node(){
        next = NULL;
        prev = NULL;
    }
};
node *root = NULL, *till = NULL;
void append(int value) {
    if(root==NULL) {
        root = new node();
        root->value = value;
        till = root;
    } else {
        node *New = new node();
        New->value = value;
        New->prev = till;
        till->next = New;
        till = till->next;
    }
}
int main(){
    for(int i=1; i<=10; i++)
        append(i);
    node *now = root;
    while(now != NULL) {
        printf("%d ", now->value);
        now = now->next;
    }
    puts("");
    return 0;
}
