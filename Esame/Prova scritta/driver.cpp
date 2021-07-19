//driver.cpp
//test Measurer class

#include <iostream>
#include "Measurer.h"
#include "Measurement.h"
#include "DLinkedList.h"
#include "Date.h"
#include <vector>

using std::vector;
using std::cout; using std::endl;

void addMeasurement(vector<Measurer>& v, int id, const Date& d, double ppm);
double meanCO2Zone(const Date& d1, const Date& d2, vector<Measurer>& v, int x, int y);
bool isInZone(const Measurer& m, int x1, int y1, int x2, int y2);
bool isWithinDates(const Measurement& m, const Date& d1, const Date& d2);

int main () {
    //test classe measurement

    //lista di misurazioni
    DLinkedList<Measurement> meas_list;
    Date d1(16,7,2021);
    double ppm1{23.1};
    Date d2(15,7,2021);
    double ppm2{24.1};
    Date d3(16,7,2021);
    double ppm3{25.1};
    Measurement m1(ppm1,d1);
    Measurement m2(ppm2,d2);
    Measurement m3(ppm3,d3);

    //inserimento in ordine
    meas_list.insertOrder(m1);
    meas_list.insertOrder(m2);
    meas_list.insertOrder(m3);

    //test misurazioni: inserite in ordine
    cout << "Misurazioni in meas_list" << endl;
    while (!meas_list.empty()) {
    cout << meas_list.front().getDate() << " : " << meas_list.front().getPpm() << "ppm" << endl;
    meas_list.removeFront();}

    vector<Measurement> meas_vect {m1,m2,m3};

    vector<Measurer> measurers;
    Measurer m (101,0,0,meas_vect);
    measurers.push_back(m);
    cout << measurers[0].getMeasurements().front().getDate();
    Date d4 (12,7,2021);
    addMeasurement(measurers,101,d4,30);
    cout << measurers[0].getMeasurements().front().getDate();
}

void addMeasurement(vector<Measurer>& v, int id, const Date& d, double ppm) {
    //dichiaro misuratore e iteratore
    Measurer m;
    vector<Measurer>::iterator p;

    for ( p=v.begin(); p!=v.end(); p++) { //scorro vettore
        if ((*p).getId()==id) {
            m = *p;
            v.erase(p); //estraggo rilevatore
        }
    }
    Measurement meas (ppm,d); //dichiaro rilevazione
    DLinkedList<Measurement> list (m.getMeasurements()); //dichiaro lista di rilevazioni
    list.insertOrder(meas); //aggiungo rilevazione alla lista

    vector<Measurement> v2;
    while (!list.empty()) {
        v2.push_back(list.front());
        list.removeFront();
    }

    m.setMeasurements(v2); //imposto lista di rilevazioni nel rilevatore

    v.push_back(m); //inserisco di nuovo il rilevatore
}

double meanCO2Zone(const Date& d1, const Date& d2, vector<Measurer>& v, int x1, int y1, int x2, int y2) {
    //scorri vettore
    Measurer m;
    vector<Measurer>::iterator p;
    vector<double> meanVector; //vettore delle medie

    for (p=v.begin(); p!=v.end(); p++) { //scorro vettore
        if (isInZone(*p,x1,y1,x2,y2)) {
            m = *p;
            for (int i=0; i<m.getMeasurements().size(); i++) { //scorro rilevamenti

                
                //dichiaro rilevamento
                Measurement meas;
                //meas =  (m.getMeasurements())[i]; genera errore di compilazione

                //se la data corrisponde, aggiungo la ppm al vettore
                if (isWithinDates(meas,d1,d2))
                    meanVector.push_back(meas.getPpm()); 
            }
        }
    }

    //restituisce 0 se non ci sono rilevamenti che soddisfino le condizioni
    if (meanVector.empty()) return 0;

    //calcolo media
    double mean{0};
    for (int i=0; i<meanVector.size(); i++) {
        mean += meanVector[i]; //sommo i rilevamenti
    }
    return mean /= meanVector.size(); //divido per il numero di rilevamenti

}

bool isInZone(const Measurer& m, int x1, int y1, int x2, int y2) { //restituisce vero se il rilevatore è nella zona
    //coordinate in alto a sx: (x1,y1)
    //coordinate in basso a dx: (x2,y2)
    if ((m.getCoordX()>=x1 && m.getCoordX()<=x2) && (m.getCoordY()>=y1&&m.getCoordY()<=y2))
    return true;
    return false;
}

bool isWithinDates(const Measurement& m, const Date& d1, const Date& d2) {
    //data compresa tra d1 e d2
    if (m.getDate()>=d1 && m.getDate()<=d2) return true;
    return false;
}