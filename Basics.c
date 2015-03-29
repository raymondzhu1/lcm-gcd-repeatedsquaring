#include <stdio.h>
#include <stdlib.h>
#include "Basics.h"

struct Node{
    int number;
    Node *next;
};

Node *new_Node(int num){
    /* Returns a new node with the node's number initialized by the parameter */
    Node *node = (Node *)(malloc(sizeof(Node)));
    node->number = num;
    return node;
}

void free_Node(Node *node){
    /* Frees a single node from memory */
    if(node != NULL){
        node->number = 0;
        free(node);
    }
}

void free_All(Node *head){
    /** 
     * Frees the node given by the parameter and any nodes after it
     * 
     * This is best used with the head of a linked list
     */
       
    if(head != NULL){
        head->number = 0;
        free_All(head->next);
        free_Node(head);
    }
}

int getNumber(Node *node){
    /* Returns the parameter's number */
    return node->number;
}

void setNext(Node *before, Node *after){
    /* Helps set the next node for the first parameter's node. */
    if(before->next == NULL){
        before->next = after;
    }
}

void overwriteNext(Node *before, Node *after){
    /** 
     * Overwrites the next node of the first parameter's node.
     * If the node has a next next node we replace the next node
     * and reattach the connection.
     */
    if(before->next != NULL){
        if(before->next->next != NULL){
            Node *tmp = before->next->next;
            before->next = after;
            after->next = tmp;
        }
        else{
            before->next = after;
        }
    }
}

Node *getNext(Node *node){
    /* Returns the parameter's next node */
    return node->next;
}

int gcd(int a, int b){
    /* Computes the greatest common divisor using Euclid's algorithm */
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a % b);
    }
}

int lcm(Node *head){
    /* Finds the least common multiple given a linked list of numbers, will return 0 if lcm function failed. */
    if(head == NULL){
        return 0;
    }
    if(head->next == NULL){
        return head->number;
    }
    Node *current = head;
    int hold = head->number;
    /** 
     * We are ensured that the outputs will be integers because we're 
     * dividing by the product's gcd.
     */
    while(current->next->next != NULL){
        hold = (hold * current->next->number)/gcd(hold, current->next->number);
        current = current->next;
    }
    return (hold * current->next->number)/gcd(hold, current->next->number);
}

static int squared(int x){
    /* A simple squaring operation */
    return x*x;
}

int repeatSquaring(int x, int n){
    /** 
     * Demonstrates the basics of repeated squaring.
     * 
     * n is the exponent and x is the base. 
     */
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return x;
    }
    if(n % 2 == 0){
        return repeatSquaring(squared(x), n/2);
    }
    else{
        /* The n-1 ensures we don't run into an odd integer */
        return x * repeatSquaring(squared(x), (n-1)/2);
    }
}