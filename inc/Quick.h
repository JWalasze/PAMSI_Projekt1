
#ifndef QUICK_H
#define QUICK_H

#include "../inc/Sort.h"

class Quick : public Sort
{
private:

    char m_tag;

public:

    Quick();
    Quick(int** tab, const int n, const int nn, char c);
    void quick_sort(int p, int r, int ind ) const;
    int partition(int p, int r, int ind ) const; //Funkcja wyboru pivota
    int m_partition(int p, int r, int ind ) const; //Funkcja partition z wyborem pivota (median-of-three)
};

#endif
