#include "iege_oral_ibrahim_ege_player.h"

// cs204
// ege 29299

//Initiliazing static id counter variabe to 0
template <class T>
int Player<T>::idCounter = 0;

//Constructor, takes a board, hold the board as reference variable
//Gives the object an id by pre-incremented idCounter static variable
template <class T>
Player<T>::Player(Board<T>& board) : board(board),id(++idCounter){
}

//Update a cell's value in given rown and column to given value
//If the cell is owned by this player updates the value, returns true
//If the cell is not owned updates the value and owns the cell, returns true
//If the cell is neither owned by this player nor not owned returns false
//Uses getter and setter functions of the board
template <class T>
bool Player<T>::updateCell(const int row,const int column,const T value) const{
    if(board.getCellOwner(row,column) == id){
        board.setCellValue(row,column,value);
        return true;
    }
    else if (board.getCellOwner(row,column) == 0 ){
        board.setCellOwner(row,column,id);
        board.setCellValue(row,column,value);
        return true;
    }
    return false;
}

//Update all of the cells' value owned by this player to given value
//Uses getter and setter functions of the board
template <class T>
void Player<T>::updateMyCells(const T value){
    for(int i=0;i<board.getRows();i++){
        for(int j=0;j<board.getColumns();j++){
            if(board.getCellOwner(i,j) == id) board.setCellValue(i,j,value);
        }
    }
}

//Unclaims ownership of a Cell in given rown and column 
//If the cell is not owned by this player returns false
//Uses getter and setter functions of the board
template <class T>
bool Player<T>::unclaimOwnership(const int row,const int column) const{
    if(board.getCellOwner(row,column) == id){
        board.setCellOwner(row,column,0);
        return true;
    }
    return false;
}

//Unclaims all of the cells owned by this player 
//Uses getter and setter functions of the board
template <class T>
void Player<T>::unclaimOwnerships(){
    for(int i=0;i<board.getRows();i++){
        for(int j=0;j<board.getColumns();j++){
            if(board.getCellOwner(i,j) == id) board.setCellOwner(i,j,0);
        }
    }
}
