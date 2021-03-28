cmake_minimum_required(VERSION 3.17)
project(Projekt1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projekt1 main.cpp src/MergeSort.cpp inc/MergeSort.h src/QuickSort.cpp inc/QuickSort.h src/IntroSort.cpp inc/IntroSort.h src/HeapSort.cpp inc/HeapSort.h src/Merge.cpp inc/Merge.h src/Quick.cpp inc/Quick.h src/Intro.cpp inc/Intro.h src/Heap.cpp inc/Heap.h src/Sort.cpp inc/Sort.h)