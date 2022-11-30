#include "iege_oral_ibrahim_ege_board.h"

// cs204
// ege 29299

//Parameterized constructor takes row and column as parameters and creates dynamic array of cells
template <class T>
Board<T>::Board(const int rows,const int columns){
    this->rows = rows;
    this->columns = columns;
    cells = new Cell<T>**[rows];
    for(int i=0;i<rows;i++){
        cells[i] = new Cell<T>*[columns];
        for(int j=0;j<columns;j++){
            cells[i][j] = new Cell<T>;
            cells[i][j]->owner = 0;
        }
    }
}

//Deep-Copy Constructor, creates a deep-copy of given board
template <class T>
Board<T>::Board(const Board& board){
    this->columns = board.getColumns();
    this->rows = board.getRows();
    cells = new Cell<T>**[rows];
    for(int i=0;i<rows;i++){
        cells[i] = new Cell<T>*[columns];
        for(int j=0;j<columns;j++){
            cells[i][j] = new Cell<T>;
            cells[i][j]->owner = board.getCellOwner(i,j);
            cells[i][j]->value = board.getCellValue(i,j);
        }
    }
    
}

//Destructor, frees all the memory allocted while creating dynamic cell array
template <class T>
Board<T>::~Board(){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            delete cells[i][j];
        }
        delete [] cells[i];
    }
    delete [] cells;
}

//Display all the cells in the board
template <class T>
void Board<T>::displayBoard(){
    cout << "Displaying the board: Each cell is shown as tuple (CURRENT OWNER ID, VALUE):" << endl;
    cout << "\t";
    for(int i=0;i<columns;i++) cout << i << "\t";
    cout << endl;
    for(int i=0;i<rows;i++){
        cout << i << "\t";
        for(int j=0;j<columns;j++) 
            cout << "(" << cells[i][j]->owner << "," << cells[i][j]->value << ")\t";
        cout << endl; 
    }
}

//Updates all the cells of the players to given value
template <class T>
void Board<T>::updateBoardCells(const int playerId, const T value){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(cells[i][j]->owner == playerId) cells[i][j]->value = value;
        }
    }
}

//Returns the number of cells owned by given player
template <class T>
int Board<T>::getPlayerCellsCount(const int playerId) const{
    int rtr = 0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(cells[i][j]->owner == playerId) rtr++;
        }
    }
    return rtr;
}

//Returns the owner of the cell in given row and column
template <class T>
int Board<T>::knowTheOwner(const int row,const int column) const { return cells[row][column]->owner; }

//Getter function, returns the value of the cell in given row and column
template <class T>
T Board<T>::getCellValue(const int row,const int column) const{ return cells[row][column]->value; }

//Getter function, Returns the owner of the cell in given row and column
template <class T>
int Board<T>::getCellOwner(const int row,const int column) const{ return cells[row][column]->owner; }

//Setter function, sets the value of the cell in given row and column to given value
template <class T>
void Board<T>::setCellValue(const int row,const int column,const T value){
    cells[row][column]->value = value;
}

//Setter function, sets the owner of the cell in given row and column to given owner id
template <class T>
void Board<T>::setCellOwner(const int row,const int column,const int owner){
    cells[row][column]->owner = owner;
}

//Getter function, Returns the number of rows
template <class T>
int Board<T>::getRows() const{ return rows; }

//Getter function, Returns the number of columns
template <class T>
int Board<T>::getColumns() const{ return columns; }
