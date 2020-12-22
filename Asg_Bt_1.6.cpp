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

void printLinkedList(){
    Node *curr = head;
    while(curr){
        printf("%d -> ", curr->score);
        curr = curr->next;
    } 
    puts("NULL");
}

int main() {
    pushHead(5);
    pushTail(10);
    pushHead(2);
    pushTail(18);
    printLinkedList();
    return 0;
}