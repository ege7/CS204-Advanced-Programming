#ifndef _IEGE_ORAL_IBRAHIM_EGE_HW5_MYFUNCS_H
#define _IEGE_ORAL_IBRAHIM_EGE_HW5_MYFUNCS_H

#include<iostream>
using namespace std;

typedef struct Card{
    string name;
    int energy;
} Card;

class Deck{
    public:
        //Default constructor
        Deck();
        //Deep Copy Constructor
        Deck(const Deck &d);
        //Destructor
        ~Deck();

        friend ostream& operator <<(ostream&output,Deck &d);
        friend bool operator ==(const Deck&d1,const Deck&d2);
        friend bool operator <(const Deck&d1,const Deck&d2);
        friend bool operator >(const Deck&d,const int many);
        friend bool operator <=(const Card&c,const Deck&d);
        Deck operator +(const Card& c);
        Deck operator +(const Deck& d);
        Deck operator -(const int many);
        Deck& operator =(const Deck& d);
        Deck& operator +=(const Deck& d);
        Card& operator [](const int index) const;
    

    private:
        int size;
        Card *cards;
};




#endif
