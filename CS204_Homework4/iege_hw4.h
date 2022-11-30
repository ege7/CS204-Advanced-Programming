#ifndef _IEGE_HW4_H
#define _IEGE_HW4_H
struct StackNode
{
    char symbol;
    int line_number;
    StackNode *next;
    StackNode() : next(nullptr){}
};

class DynStack
{
private:
    StackNode *top;
    void clear();
    StackNode* clone() const;

public:
    DynStack(void);
    DynStack(const DynStack&);
    const DynStack& operator=(const DynStack&);
    void push(char, int);
    void pop(char &, int &);
    bool isEmpty(void);
    ~DynStack();
};

#endif /* iege_hw4_h */
