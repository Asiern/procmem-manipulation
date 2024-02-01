#include "term.hpp"

void Term::print()
{
    system("cls");
    for (int i = 0; i < WIDTH; i++){
        if (i == this->x)
            std::cout << "O";
        else
            std::cout << "_";
    }
}

void Term::move(int x)
{
    this->x = (this->x + x) % WIDTH;
}

Term::Term()
{
    this->x = 0;
    for (int i = 0; i < WIDTH; i++)
    {
        this->symbols[i] = '_';
    }
}
