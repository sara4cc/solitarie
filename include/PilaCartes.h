#ifndef PILACARTES_H
#define PILACARTES_H
#include "Tauler.h"
#include "Carta.h"
#include "Baralla.h"

class PilaCartes
{
    public:
    //CONSTRUCTORS I DESTRUCTOR
        PilaCartes();
        //Pre:--
        //Post: pila buida

        PilaCartes(Baralla &b);
        //Pre:--
        //Post: omple la pila amb les cartes de la baralla, comen�ant per darrera

        PilaCartes(const PilaCartes& p);
        //Pre: --
        //Post: aquesta pila �s c�pia de la pila o

        ~PilaCartes();
        //Pre:--
        //Post: mem�ria alliberada

    //CONSULTORS
        bool es_buida() const;
        //Pre: --
        //Post: retorna cert si la pila �s buida, fals altrament

        Carta cim() const;
        //Pre: --
        //Post: retorna el valor del cim de la pila

    //MODIFICADORS
        void empila(const Carta &c);
        //Pre:--
        //Post: ha afegit c a dalt de la pila

        void desempila();
        //Pre: pila no buida;
        //Post: ha eliminat la carta de dalt de la pila

        void canviar_visibilitat();


    //OPERADOR
        PilaCartes& operator=(const PilaCartes& p);
        //Pre:--
        //Post: aquesta pila �s c�pia de la pila p i la seva mem�ria ha estat alliberada

    private:
        struct Node{
            Carta carta;
            Node* seg;
        };

        //ATRIBUTS

        Node* a_cim;

        //M�TODES PRIVATS
        void copia(const PilaCartes& p);
        //Pre: --
        //Post: aquesta pila �s c�pia de la pila p

        void allibera();
        //Pre:--
        //Post: mem�ria alliberada
};

#endif // PILACARTES_H
