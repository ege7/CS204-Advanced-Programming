#include <fstream>
#include <string>
#include "iege_oral_ibrahim_ege_hw2_myfuncs.h"


#define lowerCaseA 97
#define lowerCaseZ 122

//  ege
// cs204 29299

static node* firstListHead = NULL;
static node* secondListHead = NULL;
 
// For this function, inserts a node pointer to the end of our list. Also, list is represented by its head
// If that list's head is NULL (which means our linkedlist is empty), then the node becomes list's head
inline void InsertEnd(node** head, char ch) {

    if(*head == NULL){
        *head = new node(ch);
        return;
    }

    node* ptr = *head;

    while(ptr->next != NULL) ptr = ptr->next;

    node* newNode = new node(ch);
    ptr->next = newNode;
}


// For this function, we delete each node on the linkedlist1 that contains character "ch"
// If our linkedlist is empty, we do nothing
// If our linkedlist's head contains the character, we shift the linkedlist's head node to the next node, then delete the previous node
// Otherwise, we create a previous pointer and normal pointer to track our pointers
// Whenever we find the "ch" , we delete the pointer's pointing node, then connecting our previous node with the next node of our deleted node
// We do this process until we won't find any "ch" in our linkedlist1. So I created a while loop.

inline void del1(char ch) {

    if(firstListHead == NULL){
        cout << "No deletion as the value " << ch << " was not found in the list." << endl;
        cout << endl;
        return;
    }
    bool deletedOnce = false;
    while(true){


        if(firstListHead == NULL){
            cout << "The current content of List1 is: ";
            printList(firstListHead);
            cout << endl;
            return;
        }

        if(firstListHead->ch == ch){
            node* deleteTarget = firstListHead;
            firstListHead = firstListHead->next;
            free(deleteTarget); // !!

            if(!deletedOnce){
                cout << "Deleting all occurrences of " << ch << " in List1." << endl;
                deletedOnce = true;
            }

        } else {
            node* ptr = firstListHead;
            node* prevPtr = firstListHead;
            while(ptr != NULL && ptr->ch != ch){

                if(ptr != firstListHead){
                    prevPtr = prevPtr->next;
                }
                ptr = ptr->next;
            }

            if(ptr == NULL){
                if(!deletedOnce){
                    cout << "No deletion as the value " << ch << " was not found in the list." << endl;
                    cout << endl;
                    return;
                }
                cout << "The current content of List1 is: ";
                printList(firstListHead);
                cout << endl;
                return;

            }

            if(!deletedOnce){
                cout << "Deleting all occurrences of " << ch << " in List1." << endl;
                deletedOnce = true;
            }

            node* nextPtr = ptr->next;
            free(ptr);
            prevPtr->next = nextPtr;
        }

    }


}


// For this function, we delete each node on the linkedlist2 that contains the character "ch"
// If our linkedlist is empty, we do nothing
// If our linkedlist's head contains the character, we shift the linkedlist's head node to the next node, then delete the previous node
// Otherwise, we create a previous pointer and normal pointer to track our pointers.
// Whenever we find the "ch", we delete the pointer's pointing node, then connecting our previous node with the next node of our deleted node.
// We do this process until we won't find any "ch" in our linkedlist2. So I created a while loop.
inline void del2(char ch) {

    if(secondListHead == NULL){
        cout << "No deletion as the value " << ch << " was not found in the list." << endl;
        cout << endl;
        return;
    }
    bool deletedOnce = false;
    while(true){


        if(secondListHead == NULL){
            cout << "The current content of List2 is: ";
            printList(secondListHead);
            cout << endl;
            return;
        }

        if(secondListHead->ch == ch){
            node* deleteTarget = secondListHead;
            secondListHead = secondListHead->next;
            free(deleteTarget);

            if(!deletedOnce){
                cout << "Deleting all occurrences of " << ch << " in List2." << endl;
                deletedOnce = true;
            }


        } else {
            node* ptr = secondListHead;
            node* prevPtr = secondListHead;
            while(ptr != NULL && ptr->ch != ch){

                if(ptr != secondListHead){
                    prevPtr = prevPtr->next;
                }
                ptr = ptr->next;
            }

            if(ptr == NULL){
                if(!deletedOnce){
                    cout << "No deletion as the value " << ch << " was not found in the list." << endl;
                    cout << endl;
                    return;
                }
                cout << "The current content of List2 is: ";
                printList(secondListHead);
                cout << endl;
                return;
            }

            if(!deletedOnce){
                cout << "Deleting all occurrences of " << ch << " in List2." << endl;
                deletedOnce = true;
            }

            node* nextPtr = ptr->next;
            free(ptr);
            prevPtr->next = nextPtr;
        }
    }

}

// For this functions, Inserts a node containing character "ch" , after the node that includes "occur" character.
// If there is no code containing the character "occur", then we add this node to the beginning of our linked list.
// Otherwise, we simply let our "occur" character node, connect to our new node; and we also connect our new node to the next node
// We do this to our firstLinkedList1, since this function's name is insert1.


inline void insert1(char ch, char occur) {

    if(firstListHead == NULL){
        cout << "Inserting " << ch << " after " << occur << " in List1." << endl;
        cout << "The node with " << occur << " value does not exist. Therefore, Inserting " << ch << " at the beginning of the list." << endl;
        InsertBeginning(&firstListHead, ch);
        cout << "The current content of List1 is: ";
        printList(firstListHead);
        cout << endl;
        return;
    }

    node* ptr = firstListHead;
    while(ptr->next != NULL && ptr->ch != occur) ptr = ptr->next;

    if(ptr->next == NULL && ptr->ch != occur){
        cout << "Inverting " << ch << " after " << occur << " in List2." << endl;
        cout << "The node with " << occur << " value does not exist. Therefore, Inserting " << ch << " a at the beginning of the list." << endl;
        InsertBeginning(&firstListHead, ch);
        cout << "The current content of List1 is: ";
        printList(firstListHead);
        return;
    }

    cout << "Inserting " << ch << " after " << occur << " in List1" << endl;


    node* newNode = new node(ch);
    node* nextNode = ptr->next;
    ptr->next = newNode;
    newNode->next = nextNode;

    cout << "The node with " << ch << " has been inserted after the first occurrence of a node with " << occur << " value." << endl;
    cout << "The current content of List1 is: ";
    printList(firstListHead);
    cout << endl;


}

// Inserts a node containing character "ch", after the node that includes "occur" character.
// If there is no node containing the character "occur", then we add this node to the beginning of our linked list.
// Otherwise, we simply let our "occur" character node, connect to our new node; and we also connect our new node to the next node
// We do this to our secondLinkedList, since this function's name is insert2.

inline void insert2(char ch, char occur) {


    if(secondListHead == NULL){
        cout << "Inserting " << ch << " after " << occur << " in List2." << endl;
        cout << "The node with " << occur << " value does not exist. Therefore, Inserting " << ch << " at the beginning of the list." << endl;
        // check
        InsertBeginning(&secondListHead, ch);
        cout << "The current content of List1 is: ";
        printList(secondListHead);
        cout << endl;
        return;
    }

    node* ptr = secondListHead;
    while(ptr->next != NULL && ptr->ch != occur) ptr = ptr->next;

    if(ptr->next == NULL && ptr->ch != occur){
        cout << "Inserting " << ch << " after " << occur << " in List2." << endl;
        cout << "The node with " << occur << " value does not exist. Therefore, Inserting " << ch << " at the beginning of the list." << endl; // check
        InsertBeginning(&secondListHead, ch);
        cout << "The current content of List1 is: ";
        printList(secondListHead);
        cout << endl;
        return;
    }

    cout << "Inserting " << ch << " after " << occur << " in List2" << endl;

    node* newNode = new node(ch);
    node* nextNode = ptr->next;
    ptr->next = newNode;
    newNode->next = nextNode;

    cout << "The node with " << ch << " has been inserted after the first occurrence of a node with " << occur << " value." << endl;
    cout << "The current content of List2 is: ";
    printList(secondListHead);
    cout << endl;
}

// This function gets the word from the ifstream; that contains the file. And puts it to the first Linked List.

inline void setLinkedList_1(ifstream& file_1){

    if (file_1.is_open())
    {
        string line;
        cin.clear();
        cin.sync();
        while (getline(file_1, line))
        {
            char ch = line[0];
            InsertEnd(&firstListHead,ch);
        }
    }
    file_1.close();
}

// This function gets the word from the ifstream, that contains the file. And puts it to the second linked list.

inline void setLinkedList_2(ifstream& file_2){

    if (file_2.is_open())
    {
        string line;
        cin.clear();
        cin.sync();
        while (getline(file_2, line))
        {
            char ch = line[0];
            InsertEnd(&secondListHead,ch);
        }
    }
    file_2.close();
}


// This function simply asks the user to enter file names, then gets the words in those texts files and puts them into first and second linked lists, seperately.



inline void scanLinkedLists()
{
    ifstream file_1;
    do
    {
        cout << "Please enter the file 1 name: ";
        string qr_file_name;
        cin >> qr_file_name;
        file_1.open(qr_file_name);


    } while (!file_1.is_open());


    setLinkedList_1(file_1);


    ifstream file_2;
    do
    {
        cout << "Please enter the file 2 name: ";
        string qr_file_name;
        cin >> qr_file_name;
        file_2.open(qr_file_name);


    } while (!file_2.is_open());


    setLinkedList_2(file_2);

    cout << "List 1: ";
    printList(firstListHead);
    
    cout << "List 2: ";
    printList(secondListHead);
    cout << endl;


}
// This function traverses the both linked lists and searches for the common nodes
// This traversal continues until one of the linked lists are traversed completely.


inline void sim() {

    node* traverseFirst = firstListHead;
    node* traverseSecond = secondListHead;

    cout << "Displaying the contents of the two lists:" << endl;
    cout << "List 1: ";
    printList(firstListHead);
    cout << "List 2: ";
    printList(secondListHead);


    int commonCharacters = 0;

    while(traverseFirst != NULL && traverseSecond != NULL){
        if(traverseFirst->ch == traverseSecond->ch){
            commonCharacters++;
        }
        traverseFirst = traverseFirst->next;
        traverseSecond = traverseSecond->next;
    }

    if(commonCharacters == 0){
        cout << "There is/are 0 letter(s) matched in the same positions in both lists." << endl;
        cout << endl;
        return;
    }

    cout << "There is/are " << commonCharacters << " letter(s) matched in the same positions in both lists." << endl << endl;
}

// This function prints the linked list
// Also, head parameter represents the linked list's head pointer

inline void printList(node* head) {
    node* traversePtr = head;
    while(traversePtr != NULL){
        cout << traversePtr->ch;
        traversePtr = traversePtr->next;
    }
    cout << endl;
}

// This function deletes the list completely by recursion
// It simply traverses to the last node of the list, then deletes it. And repeats it until there's no node left


inline void DeleteList(node *head) {

    if (head == NULL)
        return;
    DeleteList(head->next);
    free(head);
}


// This function inserts a node to the beginning of the list
// Node gets created and connected to the head node
// After that, our head now starts to represent our new node.
// Also, head represents the linked list's head node

inline void InsertBeginning(node** head, char ch) {

    node* newNode = new node(ch);
    newNode->next = *head;
    *head = newNode;
}











