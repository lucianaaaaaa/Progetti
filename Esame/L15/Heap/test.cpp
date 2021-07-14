#include <iostream>
#include "Heap.h"

using std::cout;

int main () {
    Heap<int> pq; //heap
    pq.insert(10);
    pq.insert(30);
    pq.insert(20);
    pq.insert(5);

    std::cout << "pq.size(): " << pq.size() << std::endl;
    while (!pq.empty()) {
        std::cout << pq.top() << "\t";
        pq.extract_max();
    }
    return 0;
}