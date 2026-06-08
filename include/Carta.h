#ifndef CARTA_H
#define CARTA_H


class Carta
{
    public:
    //CONSTRUCTORS
        Carta();
        //Pre:-- Post: carta buida

        Carta(int valor, int pal);
        //Pre:-- Post: retorna carta amb el valor i pal corresponent

    //CONSULTORS
        void mostrar() const;
        //Pre:-- Post: mostra la carta (si es buida mostra "   " i si no es visible mostra "** ")

        void mostrar_destapada() const;
        //Pre:-- Post: mostra la carta, sempre ser� visible (si es buida mostra "   ")

        bool es_casen(const Carta &c) const;
        //Pre:-- Post: retorna true si la carta es pot posar a sota de c (es casen)

        char pal() const;
        //Pre:-- Post: retorna a_pal

        int valor() const;
        //Pre:-- Post: retorna a_valor

        bool es_visible() const;
        //Pre:-- Post: retorna true si �s visible, fals altrament

        bool es_buida() const;
        //Pre:-- Post: retorna true si la carta �s buida, fals altrament

    //MODIFICADORS
        void canviar_visibilitat();
        //Pre:-- Post: si carta no es visible es fa visible i a l'inversa

    //OPERADORS
        bool operator==(const Carta &c) const;

    private:
        static const char PALS[];
        char a_pal;
        int a_valor;
        bool a_visible;
};

#endif // CARTA_H
