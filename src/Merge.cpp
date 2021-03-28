
#include "../inc/Merge.h"

Merge::Merge(int** tab, const int n, const int nn)
{
    m_array = tab;
    m_array_rows = n;
    m_array_length = nn;
}

void Merge::merge(int p, int q, int r, int ind) const
{
    int n = q - p + 1; //Długość pierwszej tablicy
    int m = r - q; //Długość drugiej tablicy

    int* tab_n = new int [n]; //Tablica od p do q
    int* tab_m = new int [m]; //Tablica od q+1 do r

    for (int i = 0; i < n; ++i)
    {
        tab_n[i] = m_array[ind][p+i]; //Wypełnianie tablicy wartościami od p do q
    }

    for (int j = 0; j < m; ++j)
    {
        tab_m[j] = m_array[ind][q+1+j]; //Wypełnianie tablicy wartościami od q+1 do r
    }

    int i = 0; //Zmienna do przemieszczania się po tablicy tab_n
    int j = 0; //Zmienna do przemieszczania się po tablicy tab_m

    for (int k = p; k <= r; ++k) //Zmienna k przechodzi całą tablicę tab od p do r
    {
        if (i < n && j < m) //Musimy wiedzieć kiedy któraś z tablic się kończy
        {
            if (tab_n[i] >= tab_m[j])
            {
                m_array[ind][k] = tab_m[j];
                ++j;
            }
            else
            {
                m_array[ind][k] = tab_n[i];
                ++i;
            }
        }
        else if (i >= n) //Kiedy kończy się zakres tablicy tab_n dołączamy pozostałe elementy do tab z tablicy tab_m
        {
            m_array[ind][k] = tab_m[j];
            ++j;
        }
        else if (j >= m) //Kiedy kończy się zakres tablicy tab_m dołączamy pozostałe elementy do tab z tablicy tab_n
        {
            m_array[ind][k] = tab_n[i];
            ++i;
        }
    }
    delete [] tab_n;
    delete [] tab_m;
}

void Merge::merge_sort(int p, int r, int ind) const
{
    if (p < r)
    {
        int q = static_cast<int>((p + r) / 2); //Obliczanie środkowego elementu
        merge_sort(p, q, ind); //Rekurencyjne wywołanie
        merge_sort(q+1, r, ind); //Rekurencyjne wywołanie
        merge(p, q, r, ind); //Scalanie tablic
    }
}