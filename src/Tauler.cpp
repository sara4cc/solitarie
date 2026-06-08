#include "Tauler.h"
#include "Carta.h"
#include "PilaCartes.h"
#include "Baralla.h"
#include "TaulaPiles.h"
#include <iostream>
using namespace std;

//CONSTRUCTORS I DESTRUCTOR

Tauler::Tauler()
//Pre:--
//Post: tauler buit
{
    a_n = 0;
    a_m = 0;
    a_mat = NULL;
}

Tauler::Tauler(Baralla &b){
//Pre:--
//Post: tauler ompler amb cartes del final de la baralla
    a_n = 7;
    a_m = 7;
    reserva();
    for(int i=0; i<a_n; i++){
        for(int j=0; j<=i; j++){
            Carta c = b.ultima();
            a_mat[i][j] = c;
            b.eliminar_ultima();
            if(i == j) a_mat[i][j].canviar_visibilitat();
        }
        for(int b=i+1; b<a_m; b++){
            a_mat[i][b] = Carta();
        }

    }
}



Tauler::~Tauler()
//Pre:--
//Post: mem�ria alliberada
{
    allibera();
}

//OPERADOR

Tauler &Tauler::operator=(const Tauler &t){
    if(this != &t){
        allibera();
        copia(t);
    }
    return *this;
}

//CONSULTORS
void Tauler::mostrar() const{
//Pre:--
//Post: mostra el tauler
    cout<<endl;
    cout<<"c1 c2 c3 c4 c5 c6 c7    "<<endl;

    for(int i=0; i<a_m; i++){
        for(int j=0; j<a_n; j++){
            a_mat[j][i].mostrar();
        }
        cout << 'f' << i+1 << ' ' <<endl;
    }

}

void Tauler::mostrar_destapades() const{
//Pre:--
//Post: mostra el tauler amb totes les cartes destapades
    cout<<endl;
    cout<<"c1 c2 c3 c4 c5 c6 c7    "<<endl;

    for(int i=0; i<a_m; i++){
        for(int j=0; j<a_n; j++){
            a_mat[j][i].mostrar_destapada();
        }
        cout << 'f' << i+1 << ' ' <<endl;
    }
}

Carta Tauler::ultima_carta_columna(int columna) const{
//Pre: 0<=columna<=a_m
//Post: retorna la �ltima carta de la columna indicada
    int i=0;
    if(a_mat[columna-1][i].es_buida()) return a_mat[columna-1][i];

    else{
        bool trobat=false;
        while(i<a_m and not trobat){
            if(a_mat[columna-1][i]==Carta()) trobat=true;
            else i++;
        }
        return a_mat[columna-1][i-1];
    }
}

bool Tauler::existeix_columna(int columna) const{
//Pre:--
//Post: retorna true si existeix la columna, fals altrament
    return columna <= a_n and columna>0;
}

bool Tauler::existeix_fila(int fila) const{
//Pre:--
//Post: retorna true si existeix la fila, fals altrament
    return fila <= a_m and fila>0;
}

bool Tauler::es_visible(int columna, int fila) const{
//Pre:--
//Post: retorna true si la carta indicada �s visible, fals altrament
    return a_mat[columna-1][fila-1].es_visible();
}

Carta Tauler::carta(int columna, int fila) const{
//Pre: 0<columna<=a_m, 0<fila<=a_n
//Post: retorna la carta de la posicio [columna][fila]
    return a_mat[columna-1][fila-1];
}

//MODIFICADORS

void Tauler::posar_carta(int columna, const Carta &carta){
//Pre: columna v�lida
//Post: posa carta al final de la columna
    int pos=0;
    bool trobat = false;
    Carta c = carta;

    while(pos<a_m and not trobat){
        if(a_mat[columna-1][pos].es_buida()) trobat=true;
        else pos++;
    }

    if(not trobat){
        expandeix_files();
    }

    a_mat[columna-1][pos] = c;
}

void Tauler::moure_cartes(int columna, int fila, int desti){
//Pre: columna, fila i columna dest� existeixen
//Post: s'han mogut la carta a_mat[columna][desti] i totes les de darrera a la columna dest�
    int i=columna-1;
    int j=fila-1;

    while(j<a_m and not a_mat[i][j].es_buida()){
        posar_carta(desti, a_mat[i][j]);
        a_mat[i][j] = Carta();
        j++;
    }

    while(te_una_fila_buida()){
        a_m--; //borrar fila
    }

    if(not a_mat[i][fila-2].es_visible())
        a_mat[i][fila-2].canviar_visibilitat();
}

void Tauler::eliminar_ultima_carta(int columna){
//Pre: columna existeix
//Post: elimina la �ltima carta de la columna, si la fila queda buida s'elimina

    int pos = 0;
    bool trobat = false;

    while(pos<a_m and not trobat){
        if(a_mat[columna-1][pos].es_buida()) trobat = true;
        else pos++;
    }

    a_mat[columna-1][pos-1] = Carta();

    if(te_una_fila_buida()){
        a_m--;
    }

    if(not a_mat[columna-1][pos-2].es_visible()){
        a_mat[columna-1][pos-2].canviar_visibilitat();
    }
}

//FUNCIONS DE CLASSE

void Tauler::reserva() {
    a_mat = new Carta*[a_n];
    for(int i=0; i<a_n; i++){
        a_mat[i] = new Carta[a_m];
    }
}

void Tauler::copia(const Tauler &t) {
    a_n = t.a_n;
    a_m = t.a_m;
    reserva();
    for(int i=0; i<a_n; i++){
        for(int j=0; j<a_m; j++){
            a_mat[i][j] = t.a_mat[i][j];
        }
    }
}

void Tauler::allibera() {
    for(int i=0; i<a_n; i++){
        delete [] a_mat[i];
    }
    delete [] a_mat;
}

void Tauler::expandeix_files(){
//Pre:--
//Post: afageix una fila
    Tauler aux = *this;
    a_m++;
    reserva();
    for(int i=0; i<a_m; i++){
        for(int j=0; j<a_n; j++){
            if(i==a_m-1) a_mat[j][i] = Carta();
            else a_mat[j][i] = aux.a_mat[j][i];
        }
    }
}

bool Tauler::te_una_fila_buida(){
//Pre:--
//Post: retorna true si tots els elements de la �ltima fila son buits
    bool cert=true;
    int i=0;
    while(i<a_n and cert){ //busca a la �ltima fila, si troba una carta no buida torna false
        if(not a_mat[i][a_m-1].es_buida()) cert=false;
        i++;
    }
    return cert;
}


