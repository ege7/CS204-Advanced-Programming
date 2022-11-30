#ifndef _TWODLINKEDLIST_H
#define _TWODLINKEDLIST_H
#include <iostream>
#include <limits>

using namespace std;

struct node{
    char data;
    node * right;
    node * down;
};

node * createNode(char data, node * right, node * down); // to create a node easily instead of new node;
    

class TwoDLinkedList{

public:
    node* head;
    TwoDLinkedList(){
        head = NULL;
    }
    void add_row_sorted(string word); // adds the rows sorted
    void displayFullMatrix(); // displays the full matrix 1.
    void displayFullMatrixReversed(); // displays the full matrix revered 2.
    void displayReverseRecursive(node*head);
    void display_rows_starting_with(char ch); // displays the rows starting with the specific character entered by the user 3.
    void display_cols_starting_with(char ch); // displays the columns starting with the specific character entered by the user 4.
    int delete_rows_starting_with(char ch); // deletes the rows that stars with the character entered by the user and displays the total num of rows deleted 5.
    int delete_cols_starting_with(char ch); // deletes the columns that stars with the character entered by the user and displays the total num of columns deleted 6.
    void clear(); // deletes all dynamic memory allocation and exits 7.
    
};


#endif 
