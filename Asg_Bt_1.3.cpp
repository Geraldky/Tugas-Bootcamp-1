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

void middle(){
    Node *slow = head;
    Node *fast = head;

    if(head){
        while(fast && fast->next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
         printf ("THe middle Element of the given linked list is %d\n\n", slow->score);
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

int main(){
    Node *head = NULL;
    for (int i=5;i>0;i--){
        printf ("Linked list:");
        pushHead(i);
        printLinkedList();
        middle();
    }
    return 0;
}