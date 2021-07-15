//customs.cpp
//customs management of containers and boxes

#include "Container.h"
#include "Box.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "LinkedList.h"
#include <string>
#include "Queue.h"

using std::cout; using std::endl;
using std::ifstream; using std::ios;
using std::string;
using std::getline;

void clearance(Queue<Container>&);

int main () {
    //open file containers.txt
    ifstream inFile ("containers.txt",ios::in);
    if (!inFile) {
        std::cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    //leggi input e memorizza in lista
    Queue<Container> contList;
    
    string id, state, carrier, n_box;
    string box_id, weight, value, perishable;
    while (!inFile.eof()) {
        //input container
        getline(inFile,id);
        getline(inFile,state,'\n');
        getline(inFile,carrier,'\n');
        getline(inFile,n_box,'\n');
        LinkedList<Box> boxList;

        for (int i=1; i<=std::stoi(n_box); i++) {
            //input box
            getline(inFile,box_id,'\n');
            getline(inFile,weight,'\n');
            getline(inFile,value,'\n');
            getline(inFile,perishable);
            Box b(std::stoi(box_id),std::stod(weight),std::stod(value),std::stoi(perishable)); //define box
            boxList.addFront(b);
        }
        Container c(std::stoi(id),state,carrier,boxList); //define container
        contList.enqueue(c); //add container to queue
    }
    clearance(contList); //#10101
    clearance(contList); //#19233
}

void clearance(Queue<Container>& q) {
    //estrai container
    Container c (q.front());
    LinkedList <Box> list(c.getBoxes());
    q.dequeue();

    double totalWeight=0;
    double totalValue=0;
    
    //calcola peso totale e valore totale
    for (int i=0; i<c.getNumberBoxes(); i++) {
        totalWeight += list[i].getWeight();
        totalValue += list[i].getValue();
    }

    cout << "Container #" << c.getId() << " was extracted" << endl;
    cout << "Total weight: " << totalWeight << endl;    
    cout << "Total value: " << totalValue << endl;

}