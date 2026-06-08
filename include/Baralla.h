#ifndef BARALLA_H
#define BARALLA_H
#include "Carta.h"

class Baralla
{
    public:
    //CONSTRUCTORS
        Baralla();
        //Pre:--; //Post: taula buida amb memoria reservada
        Baralla(const Baralla &t);
        //Pre:--; //Post: c�pia de b
        ~Baralla();
        //Pre: --; Post: mem�ria alliberada

    //OPERADORS
        Baralla &operator=(const Baralla &t);
        //Pre:--; Post: c�pia de b

    //CONSULTORS
        int maxim() const;
        //Pre:--; Post: retorna a_max

        Carta ultima() const;
        //Pre: 0<=n<=a_max
        //Post: retorna la darrera carta de la baralla


        void aleatori(int n, unsigned &xn, unsigned &aleatori) const;

        int nombre_cartes() const;
        //Pre:--
        //Post: retorna el nombre de cartes

    //MODIFICADORS
        void afegir(const Carta &c);
        //Pre:--; Post: c afegit a la baralla

        void barrejar(int llavor);

        void intercanvi(Carta &a, Carta &b);
        //Pre: a=A, b=B
        //Post: a=B, b=A

        void eliminar_ultima();
        //Pre:--
        //Post: elimina la �ltima carta de la baralla

    private:
        const unsigned A = 1103515245;
        const unsigned C = 12345;
        const unsigned M = 32768;

        int a_n;
        int a_max;
        Carta *a_t;

        void allibera();
        //Pre:-- Post: allibera a_t
        void copia(const Baralla &t);
        //Pre:-- Post: la baralla es una c�pia de t
        void reserva();
        //Pre:-- Post: reserva espai a la baralla
        void expandeix();
        //Pre:-- Post: expandeix la baralla (13 espais)
};

#endif // BARALLA_H
