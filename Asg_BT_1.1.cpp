#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int score;
    Node *next;
};

Node *sortedMerge(Node *a, Node *b){
    Node *ans = NULL;
    if(a == NULL) {
        return (b);
    } else if(b == NULL){
        return(a);
    } 
    if (a->score <= b->score){ 
        ans = a; 
        ans->next = sortedMerge(a->next, b); 
    } 
    else { 
        ans = b; 
        ans->next = sortedMerge(a, b->next); 
    } 
    return(ans); 
} 

void push(struct Node **Head, int newScore){
    Node* createNode = (Node*) malloc(sizeof(Node)); 
    createNode->score  = newScore;
    createNode->next  = (*Head); 
    (*Head) = createNode;
}

void printLinkedList(Node *Node){
    while(Node){
        printf("%d -> ", Node->score);
        Node = Node->next;
    } 
    puts("NULL");
}

int main(){
    Node *a = NULL;
    Node *b = NULL;
    Node *res = NULL;

    push(&a, 20);
    push(&a, 19);
    push(&a, 17);

    push(&b, 25);
    push(&b, 18);
    push(&b, 15);

   // res = sortedMergemerge(a , b);
    printLinkedList( sortedMerge(a , b));
    puts("");
    return 0;
}