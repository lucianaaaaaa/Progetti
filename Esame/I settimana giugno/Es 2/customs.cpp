//customs.cpp
//customs management of containers and boxes

#include "Container.h"
#include "Box.h"
#include "Date.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <queue>

#define max_value 150

using std::cout; using std::endl;
using std::ifstream; using std::ios;
using std::string;
using std::getline;

int main () {
    //open file containers.txt
    ifstream inFile ("containers.txt",ios::in);
    if (!inFile) {
        std::cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
    std::priority_queue<Container> queue;
    
    string id, state, carrier, n_box;
    string box_id, weight, value, perishable;
    string day,month,year; Date d;
    while (inFile) {
        //input container
        getline(inFile,id);
        getline(inFile,state,'\n');
        getline(inFile,carrier,'\n');
        getline(inFile,n_box,'\n');
        LinkedList<Box> boxLinkedList;

        for (int i=1; i<=std::stoi(n_box); i++) {
            //input box
            getline(inFile,box_id,'\n');
            getline(inFile,weight,'\n');
            getline(inFile,value,'\n');
            getline(inFile,perishable);

            if (std::stoi(perishable)==1) {
                //input
                getline (inFile,day,'/');
                getline (inFile,month,'/');
                getline (inFile,year);

                d.setDate(std::stoi(day),std::stoi(month),std::stoi(year));

                //pointer
                Box b (std::stoi(box_id),std::stod(weight),std::stod(value),true,d);
                boxLinkedList.addFront(b);

            }
            else {Box b(std::stoi(box_id),std::stod(weight),std::stod(value),false); //define box
                boxLinkedList.addFront(b);

        }
        }
        Container c(std::stoi(id),state,carrier,boxLinkedList); //define container
        queue.push(c); //add container to queue
    }
    while (!queue.empty()) {
        cout << "Container #" << queue.top().getId() << " : " << queue.top().calculateExpiry() << endl;
        queue.pop();
    }
}