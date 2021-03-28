#include <ctime>
#include "inc/Merge.h"
#include "inc/Quick.h"
#include "inc/Intro.h"

int main()
{
    const int n = 10; //Ilość "wierszy"
    const int nn = 100; //Ilość elementów naszych "wierszy"

    const double l = 0.5; //Stała do zmiany ilości posortowań na początku

    const char m = 'm'; //Sort. malejąco
    const char r = 'r'; //Sort. rosnąco (każda inna literka też będzie OK)

    const int deep = static_cast<int>(2*log2(nn)); //Stała sprawdzająca głębokość rekursji

    int** tablica = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        tablica[i] = new int [nn];
    }

    /*Merge obiekt(tablica, n, nn);
    Quick obiekt_pom(tablica, n, nn, m);
    obiekt.set_values(1,5000000);
    for (int ind = 0; ind < n; ++ind)
    {
        obiekt.merge_sort(0,l*nn-1, ind);
    }
    obiekt_pom.write_out_elem();
    clock_t a = clock();
    for (int ind = 0; ind < n; ++ind)
    {
        obiekt.merge_sort(0,nn-1, ind);
    }
    clock_t b = clock();
    obiekt.is_sorted();*/

    /*Quick obiekt1(tablica, n, nn, r);
    obiekt1.set_values(1,5000000);
    Quick obiekt3(tablica, n, nn, m);
    for (int ind = 0; ind < n; ++ind)
    {
        obiekt3.quick_sort(0,nn-1, ind);
        //obiekt3.intro_sort(0,nn-1,deep,ind);
    }
    clock_t a = clock();
    for (int ind = 0; ind < n; ++ind)
    {
        obiekt1.quick_sort(0,nn-1, ind);
    }
    clock_t b = clock();
    obiekt1.is_sorted();*/

    /*Intro obiekt3(tablica, n, nn);
    Quick obiekt2(tablica, n, nn,m);
    obiekt3.set_values(1,5000000);
    //obiekt3.write_out_elem();
    for (int ind = 0; ind < n; ++ind)
    {
        obiekt2.quick_sort(0,nn-1, ind);
        //obiekt3.intro_sort(0,l*nn-1, deep, ind);
    }
    clock_t a = clock();
    for (int ind = 0; ind < n; ++ind)
    {
        obiekt3.intro_sort(0,nn-1, deep, ind);
    }
    clock_t b = clock();
    std::cout << std::endl;
    //obiekt3.write_out_elem();
    obiekt3.is_sorted();*/

    Heap obiekt2(tablica, n, nn);
    obiekt2.set_values(1, 50);
    obiekt2.write_out_elem();
    clock_t a = clock();
    for (int ind = 0; ind < n; ++ind)
    {
        obiekt2.heap_sort(0,nn-1, ind);
    }
    clock_t b = clock();
    std::cout << std::endl;
    obiekt2.write_out_elem();
    obiekt2.is_sorted();

    double x = static_cast<double>(b-a) / CLOCKS_PER_SEC;
    std::cout << std::endl << "Czas trwanie programu wynosi: " << x << std::endl;

    delete [] tablica;

    return 0;
}
