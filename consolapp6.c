#include <stdio.h>
#include <stdlib.h>

// Задание №1.

char * bracesCheck(const char * st)
{
    switch ( *st )
    {
        case '\0':
        case ']' :
        case ')' :
        case '}' :
            return (char*)st;
        case '[' : {
            char * ret = bracesCheck(st + 1);
            return ( *ret == ']' ) ? bracesCheck(ret + 1) : (char*)st;
        }
        case '(' : {
            char * ret = bracesCheck(st + 1);
            return ( *ret == ')' ) ? bracesCheck(ret + 1) : (char*)st;
        }
        case '{' : {
            char * ret = bracesCheck(st + 1);
            return ( *ret == '}' ) ? bracesCheck(ret + 1) : (char*)st;
        }
        default :
            return bracesCheck(st + 1);
    }
}

int main(void)
{
    char arr[BUFSIZ];
    while ( printf("Print the sequence: ") && fgets(arr, BUFSIZ, stdin) && *arr != '\n' )
        printf("%s\n", ( *bracesCheck(arr) ) ? "False" : "True");

    return 0;
}

// Задание №2.

#include <iostream>

using namespace std;
struct NODE {
    char value;
    struct NODE* next;
};

struct DbCircleList {
    size_t size;
    struct NODE* head;
};

void addNode(DbCircleList* list, char elem)
{
    NODE* newElem = new NODE;
    newElem->value = elem;
    if (list->size == 0)
    {
        list->head = newElem;
        list->head->next = list->head;
    }
    else
    {
        struct NODE* temp;
        temp = list->head;
        list->head = newElem;
        newElem->next = temp;
    }
    ++list->size;
}



void printList(DbCircleList* list)
{
    NODE* tmp = list->head;
   cout << "List values: " << endl;
    for (int i = 0; i < list->size; ++i)
    {
        cout << "Value: " << tmp->value << endl;
        tmp = tmp->next;
    }
}

int main()
{
    DbCircleList* list = new DbCircleList;
    list->size = 0;
    list->head = NULL;
    DbCircleList* list1 = new DbCircleList;
    list1->size = 0;
    list1->head = NULL;
    DbCircleList* list2 = new DbCircleList;
    list2->size = 0;
    list2->head = NULL;


    addNode(list, 'b');
    addNode(list, 'b');
    addNode(list, '3');
    addNode(list, 'c');
    addNode(list, '3');
    addNode(list, '7');

    printList(list);


    printList(list1);
    printList(list2);





    delete list;
    delete list1;
    delete list2;
    return 0;
}
