#include "Baralla.h"
#include "Joc.h"
#include <iostream>
using namespace std;

const int MAX = 52;

void barrejar_baralla(Baralla& b){
//Pre: --
//Post: barreja la baralla a partir d'una llavor
    cout << "ENTRA LA LLAVOR:" <<endl;
    int llavor;
    cin >> llavor;

    b.barrejar(llavor);
}

void crear_baralla_barrejada(Baralla& b){
//Pre:--
//Post: crea una baralla de 52 cartes
    for(int i=0; i<4; i++){
        for(int j=0; j<13; j++){
            Carta c(j+1,i);
            b.afegir(c);
        }
    }

    barrejar_baralla(b);
}

int inserir_opcio(){
//Pre:--
//Post: retorna la opci� escrita per l'usuari
    char opcio;
    cout << "OPCIO:" << endl;
    cin >> opcio;

    return opcio;
}

void mostrar_menu(){
//Pre:--
//Post: es mostra el men� per pantalla
    cout << "MENU" <<endl;
    cout << "1. OBRIR UNA CARTA (O TORNAR A COMENCAR)" <<endl;
    cout << "2. POSAR UNA CARTA (MA->TAULER)" <<endl;
    cout << "3. POSAR UNA CARTA (MA->PILA)" <<endl;
    cout << "4. MOURE UNA CARTA (TAULER->TAULER)" <<endl;
    cout << "5. MOURE UNA CARTA (TAULER->PILA)" <<endl;
    cout << "6. RECUPERAR UNA CARTA (PILA->TAULER)" <<endl;
    cout << "E. ESPIAR EL TAULER" <<endl;
    cout << "M. MOSTRAR EL MENU" <<endl;
    cout << "A. ABANDONAR LA PARTIDA" <<endl;
}

void posar_carta_ma_tauler(Joc& j){
//Pre: --
//Post: posa la carta del cim de la pila de descartades al tauler, si �s possible, sin�, mostra error
    if(j.no_te_descartades()) cout<<"NO HI HA CAP CARTA PER AGAFAR"<<endl;

    else{
        int columna;
        cout << "A QUINA COLUMNA LA VOLS POSAR:"<<endl;
        cin >> columna;

        if(j.existeix_columna(columna) and j.es_pot_posar_ma_tauler(columna)){
            j.posar_ma_tauler(columna);
        }

        else cout << "LA CARTA NO ES POT POSAR A LA COUMNA " <<columna<<endl;
        j.mostrar_estat();

    }
}

void posar_carta_ma_pila(Joc& j){
//Pre:--
//Post: posa la carta del cim de descartades a la pila que li pertoca, si �s possible, sin�, mostra error
    if(j.no_te_descartades()) cout << "NO HI HA CAP CARTA PER AGAFAR" <<endl;

    else{
        if(j.es_pot_posar_ma_pila()){
           j.posar_ma_pila();
        }
        else cout << "LA CARTA NO ES POT APILAR" <<endl;
    }
    j.mostrar_estat();

}

void moure_carta_tauler(Joc& j){
//Pre:--
//Post: mou una carta del tauler a una altra columna del tauler si �s possible, sin�, mostra error
    int columna;
    int fila;
    cout << "ENTRA LA COLUMNA ORIGEN I LA FILA ORIGEN:" <<endl;
    cin >> columna;
    cin >> fila;
    if(j.existeix_columna(columna) and j.existeix_fila(fila) and j.carta_visible(columna, fila)){
        int desti;
        cout << "ENTRA LA COLUMNA DESTI:" <<endl;
        cin >> desti;
        if(j.existeix_columna(desti) and j.es_pot_moure_tauler(columna, fila, desti)){
            j.moure_carta_tauler(columna, fila, desti);
        }
        else cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << desti <<endl;
    }
    else cout << "LA CARTA NO ES POT MOURE" <<endl;
    j.mostrar_estat();

}

void moure_carta_tauler_pila(Joc &j){
//Pre:--
//Post: donada una columna, agafa la �ltima carta de la culumna i la apila a la pila corresponent, si es possible
    int columna;
    cout << "ENTRA LA COLUMNA ORIGEN:" <<endl;
    cin >> columna;

    if(j.existeix_columna(columna) and j.es_pot_posar_tauler_pila(columna)){
        j.moure_carta_tauler_pila(columna);
    }
    else cout << "LA CARTA NO ES POT APILAR" <<endl;
    j.mostrar_estat();

}

void recuperar_carta_pila_tauler(Joc &j) {
//Pre:--
//Post: donada una pila i una columna, es posa la carta del cim de la pila a la columna, si �s possible
    int pila;

    cout << "ENTRA LA PILA:" << endl;
    cin >> pila;

    if(pila>0 and pila<=4 and not j.pila_buida(pila)){ //si pila v�lida i no buida
        int columna;
        cout << "A QUINA COLUMNA LA VOLS POSAR:" <<endl;
        cin >> columna;
        if(j.existeix_columna(columna) and j.es_pot_posar_pila_columna(pila, columna)){
            j.posar_pila_tauler(pila, columna);
        }
        else cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << columna <<endl;

    }
    else cout << "A LA PILA NO HI HA CAP CARTA PER RECUPERAR" <<endl;
    j.mostrar_estat();

}


int main()
{
    Baralla b;

    crear_baralla_barrejada(b);
    Joc j = Joc(b);
    j.mostrar_estat();

    mostrar_menu();

    char opcio = inserir_opcio();

    while(opcio != 'A' and not j.partida_guanyada()){

        if(opcio == '1') j.obrir_una_carta();

        else if(opcio == '2') posar_carta_ma_tauler(j);

        else if(opcio == '3') posar_carta_ma_pila(j);

        else if(opcio == '4') moure_carta_tauler(j);

        else if(opcio == '5') moure_carta_tauler_pila(j);

        else if(opcio == '6') recuperar_carta_pila_tauler(j);

        else if(opcio == 'E') j.espiar_tauler();

        else if(opcio == 'M') mostrar_menu();

        else{
            cout << "OPCIO NO DEFINIDA " << opcio;
            mostrar_menu();
            j.mostrar_estat();
        }

        opcio = inserir_opcio();
    }

    if(opcio == 'A') cout << "HAS ABANDONAT LA PARTIDA!";

    else if(j.partida_guanyada()) cout << "HAS GUANYAT LA PARTIDA!";
    return 0;
}
