#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> heap = {7, 4, 5, 2, 8, 1};
    for (auto x : heap) {std::cout << x << ", ";} std::cout << std::endl;
    
    // make_heap
    std::make_heap(heap.begin(), heap.end());
    for (auto x : heap) {std::cout << x << ", ";} std::cout << std::endl;

    // pop_heap
    std::pop_heap(heap.begin(), heap.end());
    heap.pop_back();
    for (auto x : heap) {std::cout << x << ", ";} std::cout << std::endl;
    
    // push_heap
    heap.push_back(10);
    std::push_heap(heap.begin(), heap.end());
    for (auto x : heap) {std::cout << x << ", ";} std::cout << std::endl;

    // is_heap
    std::cout << "is_heap(heap.begin(), heap.end()) " << is_heap(heap.begin(), heap.end()) << std::endl;
    
    // sort_heap
    std::sort_heap(heap.begin(), heap.end());
    for (auto x : heap) {std::cout << x << ", ";} std::cout << std::endl;
}
