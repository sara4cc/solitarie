#ifndef TAULER_H
#define TAULER_H
#include "Tauler.h"
#include "Carta.h"
#include "PilaCartes.h"
#include "Baralla.h"
#include "TaulaPiles.h"
#include "Baralla.h"

class Tauler
{
    public:
    //CONSTRUCOTRS I DESTRUCTOR
        Tauler();
        //Pre.--
        //Post: tauler buit

        Tauler(Baralla &b);
        //Pre:--
        //Post: tauler ompler amb cartes del final de la baralla

        ~Tauler();
        //Pre:--
        //Post: mem�ria alliberada

    //CONSULTORS

        void mostrar() const;
        //Pre:--
        //Post: mostra el tauler

        Carta ultima_carta_columna(int columna) const;
        //Pre: 0<=columna<=a_m
        //Post: retorna la �ltima carta de la columna indicada

        bool existeix_columna(int columna) const;
        //Pre:--
        //Post: retorna true si existeix la columna, fals altrament

        bool existeix_fila(int fila) const;
        //Pre:--
        //Post: retorna true si existeix la fila, fals altrament

        bool es_visible(int columna, int fila) const;
        //Pre:--
        //Post: retorna true si la carta indicada �s visible, fals altrament

        Carta carta(int columna, int fila) const;
        //Pre: 0<columna<=a_m, 0<fila<=a_n
        //Post: retorna la carta de la posicio [columna][fila]

        void mostrar_destapades() const;
        //Pre:--
        //Post: mostra el tauler amb totes les cartes destapades

    //MODIFICADORS

        void posar_carta(int columna, const Carta &carta);
        //Pre: columna v�lida
        //Post: posa carta al final de la columna

        void moure_cartes(int columna, int fila, int desti);
        //Pre: columna, fila i columna dest� existeixen
        //Post: s'han mogut la carta a_mat[columna][desti] i totes les de darrera a la columna dest�

        void eliminar_ultima_carta(int columna);
        //Pre: columna existeix
        //Post: elimina la �ltima carta de la columna, si la fila queda buida s'elimina

    //OPERADOR
        Tauler &operator=(const Tauler &t);

    private:
        int a_n;
        int a_m;
        Carta** a_mat;
        int* a_longitud;
    //FUNCIONS DE CLASSE
        void allibera();
        void reserva();
        void copia(const Tauler &t);
        void expandeix_files();
        bool te_una_fila_buida();
        void eliminar_ultima_fila();
};

#endif // TAULER_H
