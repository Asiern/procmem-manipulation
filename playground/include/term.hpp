#ifndef _TERM_H
#define _TERM_H

#define WIDTH 10

#include <iostream>

class Term
{
private:
    int x;
    char symbols[WIDTH];


public:
    void print();
    void move(int x);
    Term();    
};

#endif