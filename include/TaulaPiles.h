#ifndef TAULAPILES_H
#define TAULAPILES_H
#include "Tauler.h"
#include "Carta.h"
#include "Baralla.h"
#include "PilaCartes.h"

class TaulaPiles
{
    public:
    //CONSTRUCTORS I DESTRUCOTR
        TaulaPiles();
        //Pre:--
        //Post: taula buida amb mem�ria reservada per a a_max=4

        ~TaulaPiles();
        //Pre:--
        //Post: mem�ria alliberada

    //CONSULTORS
        void mostrar() const;
        //Pre:--
        //Post: mostrar la taula

        bool es_pot_posar(const Carta &carta) const;
        //Pre:--
        //Post: retorna true si es pot posar carta a una de les piles, fals altrament

        int posicio_pila(const Carta &carta) const;
        //Pre:--
        //Post: retorna la posici� de la pila on ha d'anar la carta segons el seu pal

        bool pila_buida(int pila) const;
        //Pre:--
        //Post: retorna true si la pila indicada �s buida, fals altrament

        Carta cim(int pila) const;
        //Pre:--
        //Post: retorna la pila del cim de la pila indicada

        bool partida_guanyada() const;
        //Pre:--
        //Post: retorna true si les cartes cim de les 4 piles tenen valor 'k'

    //MODIFICADORS
        void posar_carta(const Carta &carta);
        //Pre: --
        //Post: s'afageix carta a la pila de cartes correspon

        void desempila(int pila);
        //Pre: pila v�lida i no buida
        //Post: desempila la pila indicada

    //OPERADORS
        TaulaPiles &operator=(const TaulaPiles &t);
        //Pre:--
        //Post: aquesta taula �s c�pia de taula t i s'ha alliberat la mem�ria

    private:
        int a_max;
        int a_n;

        PilaCartes *a_t;

        //FUNCIONS DE CLASSE
        void allibera();
        //Pre:--
        //Post: mem�ria alliberada

        void copia(const TaulaPiles &t);
        //Pre: memoria alliberada
        //Post: aquesta taula es copia de la taula t

        void reserva();
        //Pre:--
        //Post: memoria reservada per a a_max piles

};

#endif // TAULAPILES_H
