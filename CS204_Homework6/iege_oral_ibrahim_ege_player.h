#ifndef _IEGE_ORAL_IBRAHIM_EGE_PLAYER_H
#define _IEGE_ORAL_IBRAHIM_EGE_PLAYER_H

// cs204
// ege 29299

#include "iege_oral_ibrahim_ege_board.h"

//Templated Player Class
template <class T>
class Player{
    private:
        Board<T> &board;
        static int idCounter;
        int id;
    public:
        Player(Board<T>& board); // Constructor
        bool updateCell(const int row,const int column,const T value) const ; //Update a cell's value in given rown and column to given value
        void updateMyCells(const T value); //Updates all of the cells' value owned by this player to given value
        bool unclaimOwnership(const int row,const int column) const; //Unclaims ownership of a Cell in given rown and column
        void unclaimOwnerships(); //Unclaims all of the cells owned by this player 

};

#include "iege_oral_ibrahim_ege_player.cpp"
#endif
