#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Node
{
    char* data;
    struct Node* next;
} node;


node* initNode(char* data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = strdup(data);
    temp->next = NULL;
    return temp;
}


int nodecount(node* head)
{
    node* temp = head;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp -> next;
    }
    return count;
}


void displayNode(node* head)
{
    node* temp = head;
    for(int i = 1; i <= nodecount(head); i++)
    {
        printf((i < 10) ? " %d %s\n" : "%d %s\n", i, temp -> data);
        temp = temp -> next;
    }
}


void pushNode(node** head, char* data)
{
    node* temp = *head;
    node* newNode = initNode(data);

    if (strcmp(temp->data, "") == 0)
    {
        free(temp->data);
        size_t len = strlen(data);
        while (len > 0 && (data[len - 1] == '\n' || data[len - 1] == ' ' || data[len - 1] == '\t'))
            len--;

        temp->data = strdup(data);
    }
    else 
    {
        while (temp->next != NULL)
            temp = temp->next;

        size_t len = strlen(data);
        if (len > 0 && data[len - 1] == '\n')
            data[len - 1] = '\0';

        temp->next = newNode;
    }
}




void insertNode(node** head, int index, char* data)
{
    int len = nodecount(*head);
    node* newNode = initNode(data);
    node* temp = *head;
    if(index <= len)
    {
        for(int i = 1; i < index; i++)
            temp = temp -> next;
        if (strcmp(temp->data, "") == 0)
        {
            free(temp->data);
            temp->data = strdup(data);
        }
        else
        {
            node* blah = temp -> next;
            temp -> next = newNode;
            newNode -> next = blah;
        }
    }
    else
    {
        int i = 1;
        while(temp -> next != NULL)
        {
            i++;
            temp = temp -> next;
        }
        for(; i < index; i++)
        {
            node* foo = initNode("");
            temp -> next = foo;
            temp = temp -> next;
        }
        temp -> data = data;
    }
}


void removeNode(node** head, int index)
{
    node* temp = *head;
    if(index > nodecount(*head))
        printf("Invalid");
    else
    {
        if(temp -> next == NULL)
            temp -> data = "";
        else
        {
            for(int i = 2; i < index; i++)
                temp = temp -> next;
            node* blah = temp -> next -> next;
            node* foo = temp -> next;
            free(foo);
            temp -> next = blah;
        }
    }
}


void replaceNode(node** head, int index, char* data)
{
    node* temp = *head;
    if(index > nodecount(*head))
        printf("Invalid\n");
    else
    {
        for(int i = 1; i < index; i++)
            temp = temp -> next;
        temp -> data = data;
    }
}


void clearNode(node** head, int index)
{
    replaceNode(head, index, "");
}


void save(node *head , char *file_name){
    FILE *fp;
    fp = fopen(file_name , "w" );
    if(fp==NULL)
    {
        return;
    }
    node *temp = head;
    while(temp!=NULL)
    {
        fprintf(fp , "%s\n" , temp -> data);
        temp=temp->next;
    }
    fclose(fp);
}



node* load(char *file_name) {
    FILE *fp;
    fp = fopen(file_name, "r");

    node* temp = NULL;
    if (fp == NULL)
        return NULL;

    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        size_t len = strlen(line);
        while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == ' ' || line[len - 1] == '\t'))
            len--;

        if (temp == NULL)
            temp = initNode(strdup(line));
        else
            pushNode(&temp, strdup(line));
    }
    fclose(fp);
    return temp;
}
int main()
{
    node* head = initNode("");
    insertNode(&head, 1, "hello");
    insertNode(&head, 20, "blah");
    insertNode(&head, 3, "foo");
    // displayNode(head);
    save(head, "lmao.txt");
    head = load("lmao.txt");
    displayNode(head);
    return 0;
}