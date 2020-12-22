#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int score, ind;
    Node *next;
} * head, *tail;

Node *createNode(int score)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

void pushTail(int score)
{
    Node *temp = createNode(score);

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
    Node *temp = createNode(score);

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

void printLinkedList()
{
    Node *curr = head;
    while (curr)
    {
        printf("%d -> ", curr->score);
        curr = curr->next;
    }
    puts("NULL");
}

void printNth(int n)
{
    Node *main = head;
    Node *ref = head;
    int idx = 0;
    if (head)
    {
        while (idx < n)
        {
            if (!ref)
            {
                printf("%d is not in the number of nodes in list\n", n);
                return;
            }
            ref = ref->next;
            idx++;
        }
        if (!ref)
        {
            head = head->next;
            if (head)
                printf("Node number %d from last is %d \n", n, main->score);
        }
        else
        {
            while (ref)
            {
                main = main->next;
                ref = ref->next;
            }
            printf("Node number %d from last is %d \n", n, main->score);
        }
    }
}

int main()
{

    pushHead(12);
    pushHead(98);
    pushHead(19);
    pushHead(37);
    pushHead(65);
    pushHead(78);
    pushHead(14);
    //printLinkedList();

    printNth(4);
    return 0;
}