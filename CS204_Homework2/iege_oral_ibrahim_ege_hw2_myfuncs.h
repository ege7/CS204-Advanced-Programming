#ifndef IEGE_ORAL_IBRAHIM_EGE_HW2_MYFUNCS_IEGE_ORAL_IBRAHIM_EGE_HW2_MYFUNCS_
#define IEGE_ORAL_IBRAHIM_EGE_HW2_MYFUNCS_IEGE_ORAL_IBRAHIM_EGE_HW2_MYFUNCS_
#include <iostream>

using namespace std;


struct node{

    char ch;
    node *next;
    node(char ch){
        this->ch = ch;
        next = NULL;
    }
};


void InsertEnd(node** head, char ch);
void InsertBeginning(node** head, char ch);

void insert1(char ch, char occur);
void insert2(char ch, char occur);

void del1(char ch);
void del2(char ch);

void printList(node* head);

void sim();

void DeleteList (node *head);

void scanLinkedLists();
void setLinkedList_1(ifstream& file_1);
void setLinkedList_2(ifstream& file_2);


#endif
