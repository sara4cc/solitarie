#include "Baralla.h"
#include "Carta.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
//MODIFICADORS
Baralla::Baralla()
{
    a_n = 0;
    a_max = 13;
    reserva();
}

Baralla::Baralla(const Baralla &t){
    copia(t);
}

Baralla::~Baralla()
{
    allibera();
}

Baralla &Baralla::operator=(const Baralla &t){
    if(this != &t){
        allibera();
        copia(t);
    }
    return *this;
}

//CONSULTORS

Carta Baralla::ultima() const{
    return a_t[a_n-1];
}

int Baralla::maxim() const {
    return a_max;
}

int Baralla::nombre_cartes() const{
    return a_n;
}



void Baralla::aleatori(int n, unsigned &xn, unsigned &aleatori) const{

    xn = A * xn + C;

    aleatori = ((xn/32)%M)%n;

}

//MODIFICADORS


void Baralla::afegir(const Carta &c){
    if(a_n == a_max) {
        expandeix();
    }
    a_t[a_n] = c;

    a_n++;

}



void Baralla::barrejar(int llavor){
        unsigned xn = llavor;

        unsigned pos;

        for (int i=52-1; i>0; i--) {
            aleatori(i+1, xn, pos);
            intercanvi(a_t[pos], a_t[i]);
        }

}

void Baralla::intercanvi(Carta &a, Carta &b){
    Carta aux = a;
    a = b;
    b = aux;
}

void Baralla::eliminar_ultima(){
    a_n--;
}

//FUNCIONS DE CLASSE

void Baralla::allibera(){
    delete [] a_t;
}

void Baralla::copia(const Baralla &t){
    a_n = t.a_n;
    a_max = t.a_max;
    reserva();
    for(int i=0; i<a_n; i++){
        a_t[i] = t.a_t[i];
    }
}

void Baralla::reserva(){
    a_t = new Carta[a_max];
}

void Baralla::expandeix(){
    Carta *aux = a_t;
    a_max += 13;
    reserva();

    for(int i = 0; i < a_n; i++){
        a_t[i] = aux[i];
    }

    delete [] aux;
}


