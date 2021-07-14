#include "Stack.h"

void calculateSpan(int price[], int n, int S[]) {
    //S[] è il vettore dello span per ogni giorno
    //n il numero di giorni
    Stack <int> st; //store spans
    st.push(0);
    S[0] = 1;

    for (int i=1; i<n; i++) {
        while (!st.empty()  && price[st.top()]<=price[i]) 
            st.pop();
        
        //st.top() è il giorno che ha un prezzo maggiore di quello del giorno corrente
        S[i]= (st.empty()) ? (i+1) : (i-st.top());
        
        st.push(i);
    }
}