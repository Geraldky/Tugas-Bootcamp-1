#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int score, ind;
    Node *next;
} *head, *tail;

Node *createNode(int score)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

void pushTail( int score)
{
    Node *temp = createNode( score);
    
    if (!head)
    {                       
        head = tail = temp; 
    }
    else
    {                      
        tail->next = temp; 
        tail = temp;       
    }
}

void pushHead(int score)
{
    Node *temp = createNode( score);
    
    if (!head)
    {                       
        head = tail = temp; 
    }
    else
    {                      
        temp->next = head; 
        head = temp;       
    }
}

bool findLoop(Node *h){
    while(h){
        if(h -> ind == 1) return 1;
        h -> ind = 1;
        h = h -> next;
    }
    return false;
}

int main(){

    pushHead(30);
    pushHead(25);
    pushHead(16);
    pushTail(29);
    pushHead(13);
    pushTail(5);
    pushHead(16);
    pushTail(41);

    head->next->next->next->next = head;
    if (findLoop(head)==1){
        puts("There is a cycle");
    }
    else{
         puts("No cycle");
    }
    return 0;
}
