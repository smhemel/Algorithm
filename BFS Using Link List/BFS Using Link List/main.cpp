//
//  main.cpp
//  BFS Using Link List
//
//  Created by S M HEMEL on 22/1/18.
//  Copyright © 2018 Eastern University. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define NUM_VERTEX 10
struct Vertex {
    char name;
    int mark;
    struct Node* list;
};
struct Node {
    struct Vertex* vertex;
    struct Node* next;
};
typedef struct Vertex Vertex;
typedef struct Node Node;

Vertex* new_vertex(char name) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->name = name;
    vertex->list = 0;
    return vertex;
}

void do_connect(Vertex* a, Vertex* b) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = b;
    //node->next = a->list;
    Node* temp = (Node*)malloc(sizeof(Node));
    temp = a->list;
    if(a->list==0){
        a->list = node;
        node->next = 0;
    }
    else{
        while(temp->next!=0){
           // printf("  %c",temp->vertex->name);
            temp = temp->next;
        }
        temp->next = node;
        node->next = 0;
    }
    //node->next = 0;
    //a->list = node;
}

void connect(Vertex* a, Vertex* b) {
    do_connect (a, b);
    do_connect (b, a);
}

void visit(Vertex* vertex) {
    printf ("\n%5d. %c", vertex->mark, vertex->name);
}
void do_bfs(Vertex *vertex, int* count) {
    Node *initialQueue, *front, *rear, *p, *temp;
    Vertex *w;
    vertex->mark = ++(*count);
    visit (vertex);
    initialQueue = (Node*)malloc(sizeof(Node));
    initialQueue->vertex = vertex;
    initialQueue->next = 0;
    front = initialQueue;
    rear  = initialQueue;
    while (front != 0) {
        p = front->vertex->list;
        while (p != 0) {
            w = p->vertex;
            if (w->mark == 0) {
                Node* nextQueue;
                w->mark = ++(*count);
                visit (w);
                nextQueue = (Node*)malloc(sizeof(Node));
                nextQueue->vertex = w;
                nextQueue->next = 0;
                rear->next = nextQueue;
                rear = nextQueue;
            }
            p = p->next;
        }
        temp = front;
        front = front->next;
        free (temp);
    }
}
void bfs(Vertex *graph[]) {
    int count = 0;
    for (int i=0; i<NUM_VERTEX; i++)
        graph[i]->mark = 0;
    for (int i=0; i < NUM_VERTEX; i++)
        if(!graph[i]->mark)
            do_bfs (graph[i], &count);
}
int main() {
    
    Vertex *graph[NUM_VERTEX] = {
        new_vertex('A'), //[0]
        new_vertex('B'), //[1]
        new_vertex('C'), //[2]
        new_vertex('D'), //[3]
        new_vertex('E'), //[4]
        new_vertex('F'), //[5]
        new_vertex('G'), //[6]
        new_vertex('H'), //[7]
        new_vertex('I'), //[8]
        new_vertex('J')  //[9]
    };
    Vertex **p = graph;
    for(int i=0;i<10;i++){
        printf ("%c %5d   \n",(*p)->name,(*p)->mark );
        p++;
    }
    connect(graph[0], graph[2]);
    connect(graph[0], graph[3]);
    connect(graph[0], graph[4]);
    connect(graph[1], graph[4]);
    connect(graph[1], graph[5]);
    connect(graph[2], graph[3]);
    connect(graph[2], graph[5]);
    connect(graph[4], graph[5]);
    connect(graph[6], graph[7]);
    connect(graph[6], graph[9]);
    connect(graph[7], graph[8]);
    connect(graph[8], graph[9]);
    
    printf ("\n\n");
    printf ("BFS: ");
    bfs (graph);
    p = graph;
    for(int i=0; i<10; i++){
        printf ("\n%c    %5d   ",(*p)->name,(*p)->mark);
        Node * temp = (*p)->list;
        while(temp != 0){
            printf("  %c",temp->vertex->name);
            temp = temp->next;
        }
        printf("\n");
        p++;
    }
    return 0;
}
