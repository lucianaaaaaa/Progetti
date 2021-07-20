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
#include "BoxPlus.h"

#define max_value 150

using std::cout; using std::endl;
using std::ifstream; using std::ios;
using std::string;
using std::getline;

void clearance(Queue<Container>&, LinkedList<BoxPlus>& stay);
void clearance_excess(LinkedList<BoxPlus>& stay, int id);

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

    LinkedList<BoxPlus> stay;
    clearance(contList,stay); //#10101
    clearance(contList,stay); //#19233
    clearance_excess(stay,19233);
}

void clearance(Queue<Container>& q, LinkedList<BoxPlus>& stay) {
    //estrai container
    Container c (q.front());
    LinkedList <Box> boxList(c.getBoxes());
    q.dequeue();

    double totalWeight=0;
    double totalValue=0;
    
    //calcola peso totale e valore totale
    for (int i=0; i<c.getNumberBoxes(); i++) {
        totalWeight += boxList[i].getWeight();
        totalValue += boxList[i].getValue();
    }

    cout << "Container #" << c.getId() << " was extracted" << endl;
    cout << "Total weight: " << totalWeight << endl;    
    cout << "Total value: " << totalValue << endl;

    if (totalValue>max_value) {
        LinkedList<Box> utility; //utility list
        for (int i=0; i<c.getNumberBoxes(); i++) { //scorro lista
            //escludere dalla lista dei pacchi quelli che non sono deteriorabili
            if ((boxList.front()).isPerishable())
                utility.addFront(boxList.front());
            else {
                cout << "Box #" << (boxList.front()).getId() << " was excluded from box list" << endl;
                BoxPlus b (boxList.front(),c.getId());
                stay.addFront(b); //inserirli in stay
            }
            boxList.removeFront();
        }
        //ripristino container
        c.setBoxes(utility);
    }
    cout << "\n";
}

void clearance_excess(LinkedList<BoxPlus>& stay, int id) {
    LinkedList<BoxPlus> utility; //utility list
    cout << "Removing boxes in container #" << id << " from stay list" << endl;
    for (int i=stay.size()-1; i>=0; i--) {
        //scorro lista
        if (stay.front().getId()==id) {
            cout << "Box #" << stay.front().getBox().getId() 
                << " was removed from stay list" << endl;
        }
        else utility.addFront(stay.front());
        stay.removeFront();
    }
    stay = utility;
    cout << "\n";
}