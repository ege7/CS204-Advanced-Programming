#ifndef _IEGE_ORAL_IBRAHIM_EGE_BOARD_H
#define _IEGE_ORAL_IBRAHIM_EGE_BOARD_H          
#include <iostream>
using namespace std;	

// cs204
// ege 29299

//Templated Cell Structure
template <class T>
struct Cell{
    T value;
    int owner;
};

//Templated Board class
template <class T>
class Board{
    private:
        int rows;
        int columns;
        Cell<T> ***cells;
    public:
        Board(const int rows,const int columns); // parameterized constructor
        Board(const Board& board); // deep-copy
        ~Board(); // Destructor
        void displayBoard(); // displays the board
        void updateBoardCells(const int playerId,const  T value); // updates all the cells of players
        int getPlayerCellsCount(const int playerId) const; // number of cells
        int knowTheOwner(const int row,const int column) const; // returns the owner of the cell in the given row and column
        T getCellValue(const int row,const int column) const; // getter func
        int getCellOwner(const int row,const int column) const; // getter func
        void setCellValue(const int row,const int column,const T value); // setter func
        void setCellOwner(const int row,const int column,const int owner); // setter func
        int getRows() const; // returns number of rows
        int getColumns() const; // returns number of columns

};

#include "iege_oral_ibrahim_ege_board.cpp"

#endif 
