#ifndef __BASICS_H
#define __BASICS_H

typedef struct Node Node;

Node *new_Node(int num);

void free_Node(Node *node);

void free_All(Node *head);

int getNumber(Node *node);

void setNext(Node *before, Node *after);

void overwriteNext(Node *before, Node *after);

Node *getNext(Node *node);

int gcd(int a, int b);

int lcm(Node *head);

static int squared(int x);

int repeatSquaring(int x, int n);

#endif