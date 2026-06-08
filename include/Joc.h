#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include "Carta.h"
#include "PilaCartes.h"
#include "Baralla.h"
#include "TaulaPiles.h"

class Joc
{
    public:
    //CONSTRUCTORS
        Joc();
        //Pre:--
        //Post: retorna el joc buit

        Joc(Baralla& b);
        //Pre:--
        //Post: inicialitza el joc repartint la baralla pel tauler i les piles

    //CONSULTORS
        void mostrar_estat() const;
        //Pre:--
        //Post: mostra l'estat del joc amb tots els seus elements

        bool no_te_descartades() const;
        //Pre:--
        //Post: retorna true si la pila de descartades est� buida, fals altrament

        bool es_pot_posar_ma_tauler(int columna) const;
        //Pre: 0<=columna<=7
        //Post: retorna true si la carta del cim de descartades es pot collocar a la columna del tauler indicada

        bool existeix_columna(int columna) const;
        //Pre: --
        //Post: retorna true si existeix la columna, fals altrament

        bool existeix_fila(int fila) const;
        //Pre:--
        //Post: retorna true si existeix la fila, fals altrament

        bool es_pot_posar_ma_pila() const;
        //Pre:--
        //Post: retorna true si es pot posar la carta del cim de descartades a una pila

        bool es_pot_moure_tauler(int columna, int fila, int desti) const;
        //Pre:--
        //Post: retorna true si la carta indicada es pot moure a la columna desti, fals altrament

        bool carta_visible(int columna, int fila) const;
        //Pre:--
        //Post: retorna true si la carta de la columna i fila indicada �s visible

        bool es_pot_posar_tauler_pila(int columna) const;
        //Pre:--
        //Post: retorna true si la �ltima carta de la columna indicada es pot posar a una de les piles, fals altrament

        bool pila_buida(int pila) const;
        //Pre:--
        //Posr: retorna true si la pila indicada est� buida, fals altrament

        bool es_pot_posar_pila_columna(int pila, int columna) const;
        //Pre: columna existeix i pila no buida
        //Post: retorna true si la carta del cim de la pila indicada es pot collocar a la columna indicada

        void espiar_tauler() const;
        //Pre:--
        //Post: es mostra el tauler amb totes les cartes destapades

        bool partida_guanyada() const;
        //Pre:--
        //Post: returna true si el cim de les 4 piles de Taula Piles tenen valor 'k'

    //MODIFICADORS
        void obrir_una_carta();
        //Pre:--
        //Post: posa la carta del cim de m� a la pila de descartades, si est� buida es reciclen les descartades

        void posar_ma_tauler(int columna);
        //Pre:--
        //Post: es posa la carta del cim de descartades al final de la columna indicada

        void posar_ma_pila();
        //Pre:--
        //Post: es posa la carta cim de descartades a TaulaPiles

        void moure_carta_tauler(int columna, int fila, int desti);
        //Pre: columna, fila i columna dest� existeixen
        //Post: s'han mogut la carta de la posici� columna, fil

        void moure_carta_tauler_pila(int columna);
        //Pre: la columna existeix
        //Post: mou la �ltima carta de la columna i les de darrera, sempre que es pugui, a les piles

        void posar_pila_tauler(int pila, int columna);
        //Pre: columna existeix i pila no buida
        //Post: col�loca la pila cel cim de la pila indicada al final de la columna

    private:
        PilaCartes a_ma;
        PilaCartes a_descartades;
        TaulaPiles a_tpiles;
        Tauler a_tauler;
};

#endif // JOC_H
