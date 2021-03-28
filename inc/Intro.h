
#ifndef INTRO_H
#define INTRO_H

#include <algorithm>
#include "Quick.h"
#include "Heap.h"

class Intro :  public Heap
{
    int m_deep_recursion;

public:

    Intro(int** tab, const int n, const int nn);
    void intro_sort(int p, int r, int deep, int ind ) const;
};

#endif