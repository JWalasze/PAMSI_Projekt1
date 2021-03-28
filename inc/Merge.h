//
// Created by Kuba Walaszek on 24.03.2021.
//

#ifndef MERGE_H
#define MERGE_H

#include "Sort.h"

class Merge : public Sort
{
public:

    Merge(int** tab, const int n, const int nn);
    void merge(int p, int q, int r, int ind) const;
    void merge_sort(int p, int r, int ind) const;

};

#endif
