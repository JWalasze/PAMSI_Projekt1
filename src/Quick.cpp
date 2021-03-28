
#include "../inc/Quick.h"

Quick::Quick(int** tab, const int n, const int nn, char c)
{
    m_array = tab;
    m_array_rows = n;
    m_array_length = nn;
    m_tag = c;
}

Quick::Quick()
{
    char c = 'r';
    m_array = nullptr;
    m_array_rows = 0;
    m_array_length = 0;
    m_tag = c;
}

void Quick::quick_sort(int p, int r, int ind) const
{
    if (p < r)
    {
        int q = m_partition(p, r, ind); //Wybór pivota i podział tablicy na 2 części - jedne większe od pivota a drugie mniejsze
        quick_sort(p, q-1, ind); //Przy wywołaniu rekurencyjnym nie bierzemy pivota
        quick_sort(q+1, r, ind);
    }
}

int Quick::partition(int p, int r, int ind) const
{
    int pivot = m_array[ind][r]; //Jako pivot bierzemy ostatni element
    int i = p - 1; //Indeks i bezie reprezentować granicę pomiędzy elementami > i < od pivota
    if (m_tag == 'm')
    {
        for (int k = p; k < r; ++k)
        {
            if (m_array[ind][k] > pivot)
            {
                ++i;
                change_elem(i, k, ind);
            }
        }
    }
    else
    {
        for (int k = p; k < r; ++k)
        {
            if (m_array[ind][k] <= pivot)
            {
                ++i;
                change_elem(i, k, ind);
            }
        }
    }
    change_elem(i+1, r, ind); //Pivot ląduje w miejscu pomiędzy elementami > i < od niego
    return i+1; //Zwracamy indeks pivota
}

int Quick::m_partition(int p, int r, int ind) const
{
    if (( r - p + 1) >= 3)
    {
        int q = static_cast<int>((p + r) / 2);
        if ((m_array[ind][p] > m_array[ind][r] && m_array[ind][p] < m_array[ind][q]) || (m_array[ind][p] < m_array[ind][r] && m_array[ind][p] > m_array[ind][q]))
        {
            change_elem(p, r, ind);
        }
        if ((m_array[ind][q] > m_array[ind][r] && m_array[ind][q] < m_array[ind][p]) || (m_array[ind][q] < m_array[ind][r] && m_array[ind][q] > m_array[ind][p]))
        {
            change_elem(q, r, ind);
        }
    }
    return partition(p, r, ind);
}