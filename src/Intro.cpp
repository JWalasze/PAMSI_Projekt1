
#include "../inc/Intro.h"

Intro::Intro(int **tab, const int n, const int nn) : Heap(tab,n,nn)
{
    m_deep_recursion = static_cast<int>(2*log2(nn));
}

void Intro::intro_sort(int p, int r, int deep, int ind) const
{
    if (deep <= 0)
    {
        heap_sort(p, r, ind);
    }
    else
    {
        if (p<r)
        {
            int q = m_partition(p, r, ind);
            intro_sort( p, q-1, --deep, ind);
            intro_sort( q+1, r, --deep, ind);
        }
    }
}