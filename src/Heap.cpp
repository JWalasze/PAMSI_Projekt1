
#include "../inc/Heap.h"

Heap::Heap(int **tab, const int n, const int nn)
{
    m_array = tab;
    m_array_rows = n;
    m_array_length = nn;
}

void Heap::max_heapify(int i, int heap, int ind, int p) const
{
    int l = left_son(i);
    int r = right_son(i);
    int largest;

    if (l<= heap && m_array[ind][l+p] > m_array[ind][i+p]) //Sprawdzamy czy lewy syn jest większy od ojca
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if (r<= heap && m_array[ind][r+p] > m_array[ind][largest+p]) //Sprawdzamy czy prawy syn jest większy od ojca albo lewego syna
    {
        largest = r;
    }

    if (largest != i)
    {
        change_elem(largest+p, i+p, ind);
        max_heapify(largest, heap, ind, p);
    }
}

void Heap::build_max_heapify(int heap, int ind, int p) const
{
    if ( heap % 2 == 0 )
    {
        for (int i = static_cast<int>((heap / 2)-1); i >= 0; --i)
        {
            max_heapify(i, heap, ind, p);
        }
    }
    else
    {
        for (int i = static_cast<int>(heap / 2); i >= 0; --i)
        {
            max_heapify(i, heap, ind, p);
        }
    }
}

void Heap::heap_sort(int p, int r, int ind) const
{
    int n = r - p + 1; //Rozmiar tablicy
    int heap_size = n-1; //Ostatni indeks kopca
    build_max_heapify(heap_size, ind, p);
    for (int i = n-1; i >= 1; --i)
    {
        change_elem(p, i+p, ind);
        --heap_size;
        max_heapify(0, heap_size, ind, p);
    }
}