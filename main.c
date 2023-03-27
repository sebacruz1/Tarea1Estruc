#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

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

typedef List List;