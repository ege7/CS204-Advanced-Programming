#include "iege_oral_ibrahim_ege_hw5_myfuncs.h"
#include <fstream>
Deck::Deck(){
    
    size = 0;
    cards = nullptr;
}

Deck::Deck(const Deck &d){
    
    size = d.size;
    if(size > 0){
        cards = new Card[size];
        for(int i=0;i<size;i++){
            cards[i] = d.cards[i];
        }
    }
}

Deck::~Deck(){
    if(size > 0) delete [] cards;
}

ostream& operator <<(ostream&output,Deck &d){
    if(d.size == 0){
        return output;
    }
    for(int i=0;i<d.size;i++){
        output << i + 1 << ": " << d.cards[i].name << " - " << d.cards[i].energy << endl;
    }
    return output;
}

Deck Deck::operator +(const Card& c){
    Deck deck;
    deck.size = size + 1;
    deck.cards = new Card[deck.size];
    for(int i=0;i<deck.size-1;i++){
        deck.cards[i] = cards[i];
    }
    deck.cards[deck.size-1] = c;
    return deck;
}

Deck Deck::operator +(const Deck& d){
    Deck deck;
    deck.size = size + d.size;
    deck.cards = new Card[deck.size];
    int i;
    for(i=0;i<size;i++){
        deck.cards[i] = cards[i];
    }
    for(int j=0;j<d.size;j++){
        deck.cards[i] = d.cards[j];
        i++;
    }
    return deck;
}

Deck& Deck::operator +=(const Deck& d){
    *this = *this + d;
    return *this;
}

Deck& Deck::operator =(const Deck& d){
    size = d.size;
    cards = new Card[size];
    for(int i=0;i<size;i++){
        cards[i] = d.cards[i];
    }
    return *this;
}

Deck Deck::operator -(const int many){
    Deck deck;
    if(size == 0 && (size-many <= 0)) return deck;
    deck.size = size - many;
    deck.cards = new Card[deck.size];
    for(int i=0;i<deck.size;i++){
        deck.cards[i] = cards[many+i];
    }
    return deck;
 }

bool operator ==(const Deck&d1,const Deck&d2){
    int e1 = 0,e2 = 0;
    for(int i=0;i<d1.size;i++) e1 += d1.cards[i].energy;
    for(int i=0;i<d2.size;i++) e2 += d2.cards[i].energy;
    return e1 == e2;
}

bool operator <(const Deck&d1,const Deck&d2){
    int e1 = 0,e2 = 0;
    for(int i=0;i<d1.size;i++) e1 += d1.cards[i].energy;
    for(int i=0;i<d2.size;i++) e2 += d2.cards[i].energy;
    return e1 < e2;
}

bool operator >(const Deck&d,const int many){
    return d.size > many;
}

bool operator <=(const Card&c,const Deck&d){
    for(int i=0;i<d.size;i++){
        if(d.cards[i].energy == c.energy && d.cards[i].name == c.name) return true;
    }
    return false;
}

Card& Deck::operator[](const int index) const{
    return cards[index];
}
