#include "Tauler.h"
#include "Carta.h"
#include "PilaCartes.h"
#include "TaulaPiles.h"
#include <iostream>
using namespace std;
//CONSTRUCTOR I DESTRUCTOR
TaulaPiles::TaulaPiles()
//Pre:--
//Post: taula buida amb mem�ria reservada per a a_max=4
{
    a_max = 4;
    a_n = 4;
    reserva();
}

TaulaPiles::~TaulaPiles()
//Pre:--
//Post: mem�ria alliberada
{
    allibera();
}

//CONSULTORS

void TaulaPiles::mostrar() const{
    for(int i=0; i<a_max; i++){
        if(a_t[i].es_buida()) cout<<"   ";
        else a_t[i].cim().mostrar();
    }
}

int TaulaPiles::posicio_pila(const Carta &carta) const{
//Pre:--
//Post: retorna la posici� de la pila on ha d'anar la carta segons el seu pal
    int pos;
    if(carta.pal()=='P') pos=0;
    else if(carta.pal()=='c') pos=1;
    else if(carta.pal()=='d') pos=2;
    else pos=3;

    return pos;
}

bool TaulaPiles::es_pot_posar(const Carta &carta) const{
//Pre:--
//Post: retorna true si es pot posar carta a una de les piles, fals altrament
    int pos = posicio_pila(carta);
    bool cert=false;

    if(a_t[pos].es_buida()){
        if(carta.valor()==1) cert=true;
    }
    else{
        if(a_t[pos].cim().valor() == carta.valor()-1) cert=true;
    }

    return cert;
}

bool TaulaPiles::pila_buida(int pila) const{
//Pre:--
//Post: retorna true si la pila indicada �s buida, fals altrament
    return a_t[pila-1].es_buida();
}

Carta TaulaPiles::cim(int pila) const{
//Pre:--
//Post: retorna la pila del cim de la pila indicada
    return a_t[pila-1].cim();
}

bool TaulaPiles::partida_guanyada() const{
//Pre:--
//Post: retorna true si les cartes cim de les 4 piles tenen valor 'k'
    bool cert=true;
    int i=0;
    while(i<4 and cert){
        if(a_t[i].es_buida()) cert=false;
        else if(a_t[i].cim().valor() != 13) cert = false;
    }
    return cert;
}

//MODIFICADOR
void TaulaPiles::posar_carta(const Carta &carta){
//Pre: --
//Post: s'afageix carta a la pila de cartes correspon
    int pos = posicio_pila(carta);

    a_t[pos].empila(carta);
}

void TaulaPiles::desempila(int pila){
//Pre: pila v�lida i no buida
//Post: desempila la pila indicada
    a_t[pila-1].desempila();
}

//OPERADOR
TaulaPiles &TaulaPiles::operator=(const TaulaPiles &t){
//Pre:--
//Post: aquesta taula �s c�pia de taula t i s'ha alliberat la mem�ria
    if(this != &t){
        allibera();
        copia(t);
    }
    return *this;
}

//FUNCIONS DE CLASSE
void TaulaPiles::allibera(){
    delete [] a_t;
}

void TaulaPiles::copia(const TaulaPiles &t){
    a_n = t.a_n;
    a_max = t.a_max;
    reserva();
    for(int i=0; i<a_n; i++){
        a_t[i] = t.a_t[i];
    }
}

void TaulaPiles::reserva(){
    a_t = new PilaCartes[a_max];
}






