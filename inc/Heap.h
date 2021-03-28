
#ifndef PROJEKT1_HEAP_H
#define PROJEKT1_HEAP_H

#include "Sort.h"
#include "Quick.h"

class Heap : public Quick
{
public:

    Heap(int** tab, const int n, const int nn);
    int left_son( int i ) const{ return (2*i+1); }
    int right_son( int i ) const{ return (2*i+2); }
    void max_heapify(int i, int heap, int ind, int p) const;
    void build_max_heapify(int heap, int ind, int p) const;
    void heap_sort(int p, int r, int ind) const;
};

#endif
