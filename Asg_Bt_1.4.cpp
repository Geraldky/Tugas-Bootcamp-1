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

void removeDuplicates() 
{ 
    
    Node* curr = head; 
    Node* next_next;  
    if (curr == NULL)  return;   
    while (curr->next)  
    { 
       
       if (curr->score == curr->next->score)  
       {                    
           next_next = curr->next->next; 
           free(curr->next); 
           curr->next = next_next;   
       } 
       else 
       { 
          curr = curr->next;  
       } 
    } 
} 

int main (){
    pushTail (22);
    pushHead (9);
    pushHead (15);
    pushTail (23);
    pushTail (21);
    pushTail (21);
    pushHead (15);
    pushHead (9);
    printf ("Before Duplicate removal:");
    printLinkedList();
    puts("");
    removeDuplicates();
    printf ("After Duplicate Removal:");
    printLinkedList ();

    return 0;
}
