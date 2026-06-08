#include "Joc.h"
#include "Baralla.h"
#include "Tauler.h"
#include "PilaCartes.h"
#include "TaulaPiles.h"
#include "Carta.h"
#include <iostream>
using namespace std;
Joc::Joc()
{

}

Joc::Joc(Baralla& b){
//Pre:--
//Post: inicialitza el joc repartint la baralla pel tauler i les piles
    a_tauler = Tauler(b);
    a_ma = PilaCartes(b);
    a_tpiles = TaulaPiles();
}

//CONSULTORS

void Joc::mostrar_estat() const{
//Pre:--
//Post: mostra l'estat del joc amb tots els seus elements
    cout << "ESTAT DEL JOC" <<endl;

    a_tpiles.mostrar();
    cout<< "   ";

    if(a_ma.es_buida()){
        cout<<"   ";
    }
    else a_ma.cim().mostrar();

    if(a_descartades.es_buida()){
        cout<<"   ";
    }
    else a_descartades.cim().mostrar();

    a_tauler.mostrar();
    cout<<"JOC EN CURS"<<endl;

}

bool Joc::no_te_descartades() const{
//Pre:--
//Post: retorna true si la pila de descartades est� buida, fals altrament
    return a_descartades.es_buida();
}

bool Joc::es_pot_posar_ma_tauler(int columna) const{
//Pre: columna v�lida
//Post: retorna true si la carta del cim de descartades es pot collocar a la columna del tauler indicada

    Carta carta = a_tauler.ultima_carta_columna(columna);

    return a_descartades.cim().es_casen(carta);
}

bool Joc::existeix_columna(int columna) const{
//Pre: --
//Post: retorna true si existeix la columna, fals altrament
    return a_tauler.existeix_columna(columna);
}

bool Joc::existeix_fila(int fila) const{
//Pre:--
//Post: retorna true si existeix la fila, fals altrament
    return a_tauler.existeix_fila(fila);
}

bool Joc::es_pot_posar_ma_pila() const{
//Pre:--
//Post: retorna true si es pot posar la carta del cim de descartades a una pila
    return a_tpiles.es_pot_posar(a_descartades.cim());
}

bool Joc::carta_visible(int columna, int fila) const{
//Pre:--
//Post: retorna true si la carta de la columna i fila indicada �s visible
    return a_tauler.es_visible(columna, fila);
}

bool Joc::es_pot_moure_tauler(int columna, int fila, int desti) const{
//Pre:--
//Post: retorna true si la carta indicada es pot moure a la columna desti, fals altrament
    Carta c_origen = a_tauler.carta(columna, fila);
    Carta c_desti = a_tauler.ultima_carta_columna(desti);

    return c_origen.es_casen(c_desti);
}

bool Joc::es_pot_posar_tauler_pila(int columna) const{
//Pre:--
//Post: retorna true si la �ltima carta de la columna indicada es pot posar a una de les piles, fals altrament

    Carta ultima_carta = a_tauler.ultima_carta_columna(columna);

    return a_tpiles.es_pot_posar(ultima_carta);
}

bool Joc::pila_buida(int pila) const{
//Pre:--
//Post: retorna true si la pila indicada est� buida, fals altrament
    return a_tpiles.pila_buida(pila);
}

bool Joc::es_pot_posar_pila_columna(int pila, int columna) const{
//Pre: columna existeix i pila no buida
//Post: retorna true si la carta del cim de la pila indicada es pot collocar a la columna indicada
    Carta c_origen = a_tpiles.cim(pila);
    Carta c_desti = a_tauler.ultima_carta_columna(columna);

    return c_origen.es_casen(c_desti);
}

void Joc::espiar_tauler() const{
//Pre:--
//Post: es mostra el tauler amb totes les cartes destapades
    cout << "ESTAT DEL JOC" <<endl;

    a_tpiles.mostrar();
    cout<< "   ";

    if(a_ma.es_buida()){
        cout<<"   ";
    }
    else a_ma.cim().mostrar();

    if(a_descartades.es_buida()){
        cout<<"   ";
    }
    else a_descartades.cim().mostrar();

    a_tauler.mostrar_destapades();
    cout<<"JOC EN CURS"<<endl;
}

bool Joc::partida_guanyada() const{
//Pre:--
//Post: returna true si el cim de les 4 piles de Taula Piles tenen valor 'k'
    return a_tpiles.partida_guanyada();
}

//MODIFICADORS

void Joc::obrir_una_carta(){
//Pre:--
//Post: posa la carta del cim de m� a la pila de descartades, si est� buida es reciclen les descartades

    if(a_ma.es_buida()){ //si la pila m� �s buida es recicla la pila descartades
        while(not a_descartades.es_buida()){
            a_ma.empila(a_descartades.cim());
            a_descartades.desempila();
            a_ma.canviar_visibilitat();
        }
    }

    else{
        a_descartades.empila(a_ma.cim());
        a_descartades.canviar_visibilitat();
        a_ma.desempila();
    }

    mostrar_estat();
}

void Joc::posar_ma_tauler(int columna){
//Pre:--
//Post: es posa la carta del cim de descartades al final de la columna indicada
    a_tauler.posar_carta(columna, a_descartades.cim());
    a_descartades.desempila();
}

void Joc::posar_ma_pila(){
//Pre:--
//Post: es posa la carta cim de descartades a TaulaPiles
    a_tpiles.posar_carta(a_descartades.cim());
    a_descartades.desempila();
}

void Joc::moure_carta_tauler(int columna, int fila, int desti){
//Pre: columna, fila i columna dest� existeixen
//Post: s'han mogut la carta de la posici� columna, fil
    a_tauler.moure_cartes(columna, fila, desti);
}

void Joc::moure_carta_tauler_pila(int columna){
//Pre: la columna existeix
//Post: mou la �ltima carta de la columna i les de darrera, sempre que es pugui, a les piles

    Carta ultima = a_tauler.ultima_carta_columna(columna);

    a_tpiles.posar_carta(ultima);
    a_tauler.eliminar_ultima_carta(columna);

}

void Joc::posar_pila_tauler(int pila, int columna){
//Pre: columna existeix i pila no buida
//Post: col�loca la pila cel cim de la pila indicada al final de la columna
    Carta carta = a_tpiles.cim(pila);

    a_tauler.posar_carta(columna, carta);

    a_tpiles.desempila(pila);
}
