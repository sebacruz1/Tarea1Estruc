#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    void *data;
    Node *next;
    Node *prev;
};

struct List 
{
    Node *head;
    Node *tail;
    Node *current;
};