#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using std::cout;
using std::endl;

void DisplayIntro ();
void MoveTortoise (int* const Tptr);
void MoveHare (int* const Hptr);
void DisplayLine (const int* const Tptr, const int* const Hptr);

int main () {
    //seme random
    srand(static_cast<unsigned int>(time(0)));

    //inizializzo dati e puntatori
    int T{0};
    int H{0};
    int* Tptr{&T};
    int* Hptr{&H};

    //GARA
    DisplayIntro();
    while (T<40 && H<40) {
        MoveTortoise (Tptr);
        MoveHare (Hptr);
        if (T==H) {
            cout << "TORTIMER HA MORSO GASTON! OUCH!" << endl;
        }
        DisplayLine(Tptr,Hptr);
    }
    if ((T>=40 && H>=40)==false) {
        if (T>=40) 
        cout << "VINCE TORTIMER!";
        else 
        cout << "VINCE GASTON!";
    }
    else
    cout << "SONO PARI!";
}

void MoveTortoise (int* const Tptr) {
    int i {1 + rand() % 50};
    switch (i) {
        case 1 ... 25:
            cout << "TORTIMER VA A PASSO SPEDITO!" << endl;
            *Tptr = *Tptr + 3;
            break;
        case 26 ... 33:
            cout << "OH NO! TORTIMER E\' SCIVOLATO!" << endl;
            *Tptr = *Tptr -1;
            break;
        case 34 ... 50:
            cout << "TORTIMER FA UN PASSETTO VERSO LA META!" << endl;
            *Tptr = *Tptr +1;
            break;
        default:
        cout << "QUESTO NON DOVREBBE SUCCEDERE!" << endl;
    }
    if (*Tptr<0) {
        *Tptr=0;
    }
}

void MoveHare (int* const Hptr) {
    int i {1 + rand() % 50};
    switch (i) {
        case 1 ... 19:
            cout << "GASTON DORME!" << endl;
            break;
        case 20 ... 27:
            cout << "GASTON HA VOGLIA DI VINCERE!" << endl;
            *Hptr = *Hptr +11;
            break;
        case 28 ... 35:
            cout << "CHE SCIVOLONE, GASTON!" << endl;
            *Hptr = *Hptr -9;
            break;
        case 36 ... 45:
            cout << "GASTON PROCEDE CON CALMA..." << endl;
            *Hptr = *Hptr +1;
            break;
        case 46 ... 50:
            cout << "STAI ATTENTO, GASTON!" << endl;
            *Hptr = *Hptr -2;
            break;
        default:
        cout << "QUESTO NON DOVREBBE SUCCEDERE!" << endl;
    }
        if (*Hptr<0) {
        *Hptr=0;
    }
}

void DisplayLine (const int* const Tptr, const int* const Hptr) {
    //prima linea
    for (int i=1; i<=40; i++) {
        cout << std::setw(2) << i << "--";
    }
    if (*Tptr != *Hptr) {
        static int spT{0};
        spT = 4*(*Tptr-1);
        cout << std::setw(spT) << "T" << endl; 
        static int spH{0};
        spH = 4*(*Hptr-1);
        cout << std::setw(spH) << "H" << endl; 
    }
    else {
        static int spT{0};
        spT = 4*(*Tptr-1) + 1;
        cout << std::setw(spT) << "OUCH!" << endl; 
    }
    cout << "\n";
}

void DisplayIntro () {    
    cout << "BUONASERA SIGNORE E SIGNORI" << endl;
    cout << "HO IL PIACERE DI PRESENTARVI QUEST\'INCREDIBILE GARA!" << endl;
    cout << "ECCO I NOSTRI SFIDANTI!" << endl; 
    cout << "ALLA MIA DESTRA, TORTIMER LA TARTARUGA. E ALLA MIA SINISTRA, GASTON IL CONIGLIO COI BAFFI!" << endl;
    cout << "\n\n CHE LA GARA ABBIA INIZIO!!!" << endl;
}