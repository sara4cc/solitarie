#include "Tauler.h"
#include "Carta.h"
#include "PilaCartes.h"
#include "Baralla.h"
#include <iostream>
using namespace std;
//CONSTRUCTORS I DESTRUCTOR

PilaCartes::PilaCartes()
//Pre:--
//Post: pila buida
{
    a_cim = NULL;

}

PilaCartes::PilaCartes(Baralla &b){
//Pre:--
//Post: omple la pila amb les cartes de la baralla, comen�ant per darrera
    a_cim = NULL;

    while(b.nombre_cartes()>0){
        empila(b.ultima());
        b.eliminar_ultima();
    }
}

PilaCartes::PilaCartes(const PilaCartes& p){
//Pre: --
//Post: aquesta pila �s c�pia de la pila o
    a_cim = NULL;
    copia(p);
}

PilaCartes::~PilaCartes()
//Pre:--
//Post: mem�ria alliberada
{
    allibera();
}

//CONSULTORS

bool PilaCartes::es_buida() const{
//Pre: --
//Post: retorna cert si la pila �s buida, fals altrament
    return a_cim == NULL;
}

Carta PilaCartes::cim() const{
//Pre: --
//Post: retorna el valor del cim de la pila
    return a_cim->carta;
}



//MODIFICADORS

void PilaCartes::empila(const Carta &c){
//Pre:--
//Post: ha afegit c a dalt de la pila

    Node* nou = new Node;
    nou->carta = c;
    nou->seg = a_cim;
    a_cim = nou;
}

void PilaCartes::desempila(){
//Pre: pila no buida;
//Post: ha eliminat la carta de dalt de la pila
    Node* aux = a_cim;
    a_cim = a_cim->seg;
    delete aux;
}

void PilaCartes::canviar_visibilitat(){
    a_cim->carta.canviar_visibilitat();
}


//OPERADOR

PilaCartes& PilaCartes::operator=(const PilaCartes& p){
    if(this != &p){
        allibera();
        copia(p);
    }
    return *this;
}

//M�TODE PRIVAT

void PilaCartes::allibera(){
    while(!es_buida()){
        Node* aux = a_cim;
        a_cim = a_cim->seg;
        delete aux;
    }
}

void PilaCartes::copia(const PilaCartes& o){
    if(!o.es_buida()){
        Node *p, *q, *aux;
        p = new Node;
        a_cim = p;
        aux = o.a_cim;
        p->carta = aux->carta;
        p->seg = NULL;
        q = p;
        aux = aux->seg;
        while(aux!=NULL){
            p = new Node;
            q->seg = p;
            p->carta = aux->carta;
            p->seg = NULL;
            q = p;
            aux = aux->seg;
        }
    }
}






