#include <iostream>
#include <vector>
#include <stdexcept>

/*
template<typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
 */

template <typename T>
class MinHeap {
public:
    std::vector<T> &data;
    int size;
    
    MinHeap(std::vector<T> &input);
    void build_heap();
    int parent(int i);
    int left(int i);
    int right(int i);
    void heapify(int i);
    T min();
    T extract_min();
    void insert(T x);
    bool ri_check(int i=1);
};

template <typename T>
MinHeap<T>::MinHeap(std::vector<T> &input) : data(input), size(input.size()) {
    std::cout << "In constructor, size: " << size << std::endl;
    build_heap();
    try {
        ri_check();
    }
    catch (std::logic_error &error) {
      std::cerr << error.what() << std::endl;
    }
}

template <typename T>
void MinHeap<T>::build_heap() {
    for (int i = size / 2; i > 0; i--)
        heapify(i);
}

template <typename T>
int MinHeap<T>::parent(int i) {
    if (i == 1)
        return -1;
    return i / 2;
}

template <typename T>
int MinHeap<T>::left(int i) {
    return 2 * i;
    
}

template <typename T>
int MinHeap<T>::right(int i) {return 2 * i + 1;}

template <typename T>
void MinHeap<T>::heapify(int i) {
    int smallest = i;
    int l = left(i);
    int r = right(i);
    if (l <= size && data[l - 1] < data[smallest - 1])
        smallest = l;
    if (r <= size && data[r - 1] < data[smallest - 1])
        smallest = r;
    if (i != smallest) {
        std::swap<T>(data[i-1], data[smallest-1]);
        heapify(smallest);
    }
}

template <typename T>
T MinHeap<T>::min() {return data[0];}

template <typename T>
T MinHeap<T>::extract_min() {
    T rv = data[0];
    data[0] = data[size-1];
    data.pop_back();
    size -= 1;
    heapify(1);
    try {
        ri_check();
    }
    catch (std::logic_error &error) {
      std::cerr << error.what() << std::endl;
    }
    return rv;
}

template <typename T>
void MinHeap<T>::insert(T x) {
    data.push_back(x);
    size += 1;
    int current = size;
    int upper = parent(current);
    while (upper != -1 && data[current-1] < data[upper-1]) {
        std::swap<T>(data[upper-1], data[current-1]);
        current = upper;
        upper = parent(upper);
    }
    try {
        ri_check();
    }
    catch (std::logic_error &error) {
      std::cerr << error.what() << std::endl;
    }
}

template <typename T>
bool MinHeap<T>::ri_check(int i) {
    if (i > size)
        return true;
    int l = left(i);
    int r = right(i);
    if (l <= size && data[l - 1] < data[i - 1]) {
        throw std::logic_error("rep invariant not satisfied!");
        return false;
    }
    if (r <= size && data[r - 1] < data[i - 1]) {
        throw std::logic_error("rep invariant not satisfied!");
        return false;
    }
    if (!(ri_check(l) && ri_check(r)))
        return false;
    return true;
}

template<typename T>
std::vector<T> heap_sort(std::vector<T> vector_to_sort) {
    MinHeap<T> min_heap(vector_to_sort);
    std::vector<T> sorted_vector;
    while (min_heap.size > 0) {
        sorted_vector.push_back(min_heap.extract_min());
    }
    return sorted_vector;
}
