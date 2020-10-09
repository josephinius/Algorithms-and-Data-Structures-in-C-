#include <iostream>
#include <vector>
#include "heap.hpp"

template<typename T>
void print_vector(const std::vector<T> &vec) {
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec1 = {2, 5, 7, 1, 0};
    std::cout << "vec1: ";
    print_vector(vec1);
    std::cout << "MinHeap<int> heap1(vec1);" << std::endl;
    MinHeap<int> heap1(vec1);
    std::cout << "vec1: ";
    print_vector(vec1);
    std::cout << "heap1.min(): " << heap1.min() << std::endl;
    
    std::vector<int> vec2 = {8, 10, -1, 9, 2, 7, 1, 0, 3, 1};
    std::cout << "vec2: ";
    print_vector(vec2);
    std::cout << "std::vector<int> vec2_sorted = heap_sort(vec2);" << std::endl;
    std::vector<int> vec2_sorted = heap_sort(vec2);
    std::cout << "vec2_sorted: ";
    print_vector(vec2_sorted);
        
    std::vector<float> vec3 = { 1.0, 3.14, 0.1 };
    std::cout << "vec3: ";
    print_vector(vec3);
    std::cout << "MinHeap<float> heap3(vec3);" << std::endl;
    MinHeap<float> heap3(vec3);
    std::cout << "vec3: ";
    print_vector(vec3);
    std::cout << "heap3.insert(2.5);" << std::endl;
    heap3.insert(2.5);
    std::cout << "vec3: ";
    print_vector(vec3);
    std::cout << "vec3 in sorted order:" << std::endl;
    while (heap3.size > 0) {
        std::cout << heap3.extract_min() << ", ";
    }
    std::cout << std::endl;
}
