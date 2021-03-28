//
// Created by Kuba Walaszek on 25.03.2021.
//

#include "../inc/Sort.h"

bool Sort::is_sorted() const
{
    for (int i = 0; i < m_array_rows; ++i)
    {
        if ( !std::is_sorted( m_array[i], m_array[i]+m_array_length-1 ) )
        {
            std::cout << std::endl << "Nasza tablica NIE jest posortowana :(" << std::endl;
            return false;
        }
    }
    std::cout << std::endl << "Nasza tablica jest posortowana!" << std::endl;
    return true;
}

void Sort::set_values(int lower, int upper) const
{
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(lower, upper);

    for (int i = 0; i < m_array_rows; ++i)
    {
        for (int j = 0; j < m_array_length; ++j)
        {
            m_array[i][j] = distribution(generator);
        }
    }
}

void Sort::change_elem(int a, int b, int ind) const
{
    int temp = m_array[ind][a];
    m_array[ind][a] = m_array[ind][b];
    m_array[ind][b] = temp;
}

void Sort::write_out_elem() const
{
    for (int i = 0; i < m_array_rows; ++i)
    {
        for (int j = 0; j < m_array_length; ++j)
        {
            std::cout << m_array[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}