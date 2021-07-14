//priority.cpp
//example of usage of stl priority queue

#include <iostream>
#include <queue>

int main () {
    std::priority_queue<int> pq; //heap
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    std::cout << "pq.size(): " << pq.size() << std::endl;
    std::cout << "pq.top(): " << pq.top() << std::endl;
    while (!pq.empty()) {
        std::cout << pq.top() << "\t";
        pq.pop();
    }
    return 0;
}