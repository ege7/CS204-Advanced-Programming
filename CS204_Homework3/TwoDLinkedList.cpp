#include "TwoDLinkedList.h"


node * createNode(char data, node * right, node * down){ // function to create a node and return it
    // easier than doing x = new node(); and x -> data = data etc everytime we want to create a node
    node* newNode = new node();
    newNode -> data = data;
    newNode -> right = right;
    newNode -> down = down;
    return newNode;
}


void TwoDLinkedList::displayFullMatrix(){
    // function to display the whole matrix linkedlist
    // in the outer loop, we traverse the rows
    // in the inner loop, we traverse columns
    node* ptr = head; // pointerımızı oluşturuyoruz
    while(ptr != NULL){
        node*traversePtr = ptr; // yeni pointer oluşturuyoruz ki birisi başta kalsın diğeri traverselesin listi, right now ikisi de aynı yeri point ediyor(listenin başı)
        while(traversePtr != NULL){
            cout << traversePtr -> data; // traverseptr bir nevi iterator olarak düşün
            traversePtr = traversePtr -> right;
        }
        cout << endl;
        ptr = ptr->down; // bir aşağı rowa iniyoruz until ptr null olana kadar yani boş
    }
    
}

void TwoDLinkedList::display_rows_starting_with(char ch){
    // function to display rows in matrix linked list, that starts witch parameter character.
    // In outer loop, we traverse our rows. If we occur a word that starts with our parameter;
    // Then we traverse that words' corresponding columns, and printing them.
    node*ptr = head; // pointer oluştur
    while(ptr != NULL){
        node*traversePtr = ptr;
        if(traversePtr -> data == ch){
            while(traversePtr != NULL){
                cout << traversePtr -> data;
                traversePtr = traversePtr -> right;
            }
            cout << endl;
        }
        ptr = ptr -> down;
    }
}

void TwoDLinkedList::display_cols_starting_with(char ch){
    // function to display rows in matrix linked list, that starts witch parameter character.
    // In outer loop, we traverse our head's corresponding columns. If we occur a char data that is equal to our parameter;
    // Then we traverse the entire row by going down pointer by down.

    node* ptr = head;
    while(ptr!= NULL){
        node*traversePtr = ptr;
        if(traversePtr -> data == ch){
            while(traversePtr != NULL){
                cout << traversePtr -> data << endl;
                traversePtr = traversePtr -> down;
            }
            cout << endl;
        }
        ptr = ptr -> right;
    }
}


void TwoDLinkedList::displayFullMatrixReversed(){
    // function to display the whole matrix linkedlist reversed
    // It calls an utility function related to our data, called displayRecursive
    // had to use the recursive under matrixreversed because can't change anything in the main.cpp
    
    displayReverseRecursive(head);
}

void TwoDLinkedList::displayReverseRecursive(node*head){
    // in this function, we try to traverse recursively, until our last row
    // then, we print that row
    // after the previous recursive call, we also print our previous row, and it goes until our matrix linkedlist is completely printed
    if(head -> down == NULL){
        node* wordPtr = head;
        while(wordPtr != NULL){
            cout << wordPtr -> data;
            wordPtr = wordPtr -> right;
        }
        cout << endl;
        return;
    }
    
    displayReverseRecursive(head -> down);
    
    node* wordPtr = head;
    while(wordPtr != NULL){
        cout << wordPtr -> data;
        wordPtr = wordPtr-> right;
    }
    cout << endl;
}

// function to add row, by sorted
void TwoDLinkedList::add_row_sorted(string word){
    int wordIndex = 0;
    
    if(head == NULL){ // liste boşsa kelimeyi ekliyoruz // if our matrix linked list is empty
        head = createNode(word[0], NULL, NULL);
        wordIndex = 1;
        
        while(word[wordIndex] != '\0'){ // '\0' == null
            node* ptr = head;
            while(ptr-> right != NULL){
                ptr = ptr -> right;
                
            }
            ptr -> right = createNode(word[wordIndex], NULL, NULL);
            wordIndex++;
            
        }
        return;
        
        
        
        
    }
    node* currentPtr = head;
    node* prevPtr = head;
    bool onFirstNode = true;
    
    // if our matrix linkedlist is not empty, we try to move our pointer down by down
    // until finding a node which has a smaller data(by ascii) that is bigger or equal to our node
    // or to detect the last row of the matrix
    // while we are doing this, we have two pointers, currentPtr and "prev"Ptr
    // prevPtr will point out the first letter of the previous row, and currentPtr will point to the first letter of the current row.
    while(currentPtr -> down != NULL && word[0] > currentPtr -> data){
        currentPtr = currentPtr -> down;
        if(!onFirstNode){
            prevPtr = prevPtr->down;
            
        }
        else{
            onFirstNode = false;
            
        }
    }
    // if we went down to the last row
    if(currentPtr->down == NULL){
        // if that node's char data is bigger or equal to our word's first letter,
        // then we'll place it to the above of that row
        if(word[0] <= currentPtr -> data){
            node* newNode;
            
            // if our matrix list only has one word, we'll insert the word, then we'll make our new word's first letter as our new head
            if(onFirstNode){
                newNode = createNode(word[0],NULL,currentPtr);
                head = newNode;
                currentPtr = currentPtr -> right;
                wordIndex = 1;
                // traverse our word to insert each character by their node.
                // we'll traverse our current Ptr at the same time
                
                while(word[wordIndex] != '\0'){
                    node* ptr = head;
                    while(ptr -> right != NULL){
                    ptr = ptr -> right;
                    }
                    ptr -> right = createNode(word[wordIndex], NULL, currentPtr);
                    currentPtr = currentPtr -> right;
                    wordIndex ++;
                }
                // else, we'll just place our word between our currentPtr's word and prevPtr's word
                
            }
            else{
                newNode = createNode(word[0], NULL, currentPtr);
                prevPtr -> down = newNode;
                currentPtr = currentPtr -> right;
                prevPtr = prevPtr -> right;
                wordIndex = 1;
                
                // traverse our word to insert each character by their node.
                // we'll traverse our prev and current ptr's at the same time
                
                while(word[wordIndex] != '\0'){
                    node* ptr = newNode;
                    while(ptr-> right != NULL){
                        ptr = ptr -> right;
                    }
                    ptr -> right = createNode(word[wordIndex], NULL, currentPtr);
                    prevPtr -> down = ptr;
                    currentPtr = currentPtr -> right;
                    prevPtr = prevPtr -> right;
                    newNode = newNode -> right;
                    wordIndex++;
                }
            }
            // if that node's char data is less than our word's first letter,
            // then we'll place it to under that row
            
        }
        else{
            node* newNode = createNode(word[0], NULL, NULL);
            currentPtr -> down = newNode;
            
            currentPtr = currentPtr -> right;
            wordIndex = 1;
            
            // traverse our word to insert each character by their node
            // we'll traverse our current Ptr at the same time
            while(word[wordIndex] != '\0'){
                node* ptr = newNode;
                
                while(ptr->right != NULL){
                    ptr = ptr -> right;
                }
                ptr-> right = createNode(word[wordIndex], NULL, NULL);
                currentPtr -> down = ptr;
                
                currentPtr = currentPtr -> right;
                newNode = newNode -> right;
                wordIndex++;
            }
        }
        return;
    }
    // if we get out of that traversal loop just because there's a node that its char data is bigger or equal to our word's first letter
    // we'll be placing our word under prevPtr's word and above currentPtr's word
    if(word[0] <= currentPtr -> data){
        node* newNode = createNode(word[0], NULL, currentPtr);
        prevPtr -> down = newNode;
        
        currentPtr = currentPtr -> right;
        prevPtr = prevPtr->right;
        
        wordIndex = 1;
        
        // traverse our word to insert each character by their node
        // we'll traverse our prev and current Ptr's at the same time
        while(word[wordIndex] != '\0'){
            node* ptr = newNode;
            while(ptr-> right != NULL){
                ptr = ptr -> right;
                
            }
            ptr -> right = createNode(word[wordIndex], NULL, currentPtr);
            prevPtr -> down = ptr;
            
            currentPtr = currentPtr -> right;
            prevPtr = prevPtr -> right;
            newNode = newNode -> right;
            
            wordIndex ++;
        }
    }
}


int TwoDLinkedList::delete_rows_starting_with(char ch){
    // no comments at the moment
    node* currentPtr = head; // current
    node* prevPtr = head; // next
    bool onFirstNode = true;
    int count = 0;
    if(currentPtr == NULL){
        cout << "The number of deleted rows is: 0" << endl;
    }
    while(currentPtr != NULL){
        node* previousTraversePtr = prevPtr;
        node* currentTraversePtr = currentPtr;
        if(currentTraversePtr->data == ch){
            while(currentTraversePtr -> down != NULL){
                node* deleteTarget = currentTraversePtr;
                // previousTraversePtr = previousTraversePtr -> down;
                
                count++;
                
            }
            if(!onFirstNode){
                cout << "The number of deleted rows is: " << count << endl;
            }
        }
        else{
            
        }
        currentPtr = currentPtr->down;
        if(!onFirstNode){
            prevPtr = prevPtr->down;
        }
        else{
            onFirstNode = false;
        }
    }
    return 1;
}

int TwoDLinkedList::delete_cols_starting_with(char ch){
    node* currentPtr = head; // current
    node* prevPtr = head; // next
    bool onFirstNode = true;
    int count = 0;
    if(currentPtr == NULL){
        cout << "The number of deleted columns is: 0" << endl;
    }
    while(currentPtr != NULL){
        node* previousTraversePtr = prevPtr;
        node* currentTraversePtr = currentPtr;
        if(currentTraversePtr->data == ch){
            while(currentTraversePtr -> right != NULL){
                node* deleteTarget = currentTraversePtr;
                
                // previousTraversePtr = previousTraversePtr -> right;
                
                count++;
                
            }
            if(!onFirstNode){
                cout << "The number of deleted columns is: " << count << endl;
            }
        }
        else{
            
        }
        currentPtr = currentPtr->right;
        if(!onFirstNode){
            prevPtr = prevPtr->right;
        }
        else{
            onFirstNode = false;
        }
    }
    return 1;
}
void TwoDLinkedList::clear(){
    // no comments at the moment
    
    // i create 3 pointers excluding head
    // currentPtr -> shows the start of the row and the current location of it
    // prevPtr -> showing the head of the previous ptr
    // we create 2 more PTRs that shows the current locations of prevPtr and CurrentPtr after finding the ch that needs to be deleted
    // we put them in a loop through the row and delete with currentPtr
    // we then, connect with the node below currentPtr and prevPtr

    node* currentPtr = head; // silmek istediğim row'un headini göstericek
    
    node* prevPtr = head -> down; // silmek istediğim rowdan öncek rowun headını göstericek

    

    // after deleting the row, we connect the current pointer with the pointer that comes after the one we deleted, so that they connect
    // then we say next, we get to the next pointer
    while(currentPtr -> right != NULL){
        node* currentLocationPtr = currentPtr; // shows the location of the current ptr, we will use this ptr to delete the columns and clear them etc
        node* prevLocationPtr = prevPtr; // shows the location of the previous ptr, we will use this ptr to delete the rows and clear them etc
        while(prevPtr != NULL){
            free(currentLocationPtr);
        }
        prevLocationPtr = prevPtr -> right;
        currentLocationPtr = currentPtr -> down;
    }
    
}



