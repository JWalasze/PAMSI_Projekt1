
#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <random>

class Sort
{
protected:

    int m_array_rows; //Liczba "wierszy" tablicy
    int m_array_length; //Liczba elementów każdego "wiersza"
    int** m_array; //Dwuwymiarowa tablica

public:

    void change_elem( int a, int b, int ind ) const; //Zamienianie 2 elementów w tablicy
    bool is_sorted() const; //Sprawdzenie czy tablica jest posortowana
    void set_values(int lower, int upper) const; //Ustawienie losowych wartości tablicy
    void write_out_elem() const;
};

#endif
