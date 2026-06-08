#include "Carta.h"
#include <iostream>
using namespace std;

const char Carta::PALS[]={'P', 'c', 'd', 'T'};

Carta::Carta()
{
//Pre:-- Post: carta buida
    a_valor = 0;
    a_pal = ' ';
    a_visible = true;
}

Carta::Carta(int valor, int pal){
//Pre:-- Post: retorna carta amb el valor i pal corresponent

    a_pal = PALS[pal];
    a_valor = valor;
    a_visible = false;
}



void Carta::mostrar() const{
//Pre:-- Post: mostra la carta (si es buida mostra "   " i si no es visible mostra "** ")
    if(es_buida())cout<<"   "; //si est� buida

    else if(a_visible){

        if(a_valor==1) cout<<'A';
        else if(a_valor==10) cout<<'D';
        else if(a_valor==11) cout<<'J';
        else if(a_valor==12) cout<<'Q';
        else if(a_valor==13) cout<<'K';
        else cout<<a_valor;
        cout<< a_pal;
        cout<<" ";
    }
    else cout << "** ";
}

void Carta::mostrar_destapada() const{
//Pre:-- Post: mostra la carta, sempre ser� visible (si es buida mostra "   ")
    if(es_buida())cout<<"   "; //si est� buida

    else{

        if(a_valor==1) cout<<'A';
        else if(a_valor==10) cout<<'D';
        else if(a_valor==11) cout<<'J';
        else if(a_valor==12) cout<<'Q';
        else if(a_valor==13) cout<<'K';
        else cout<<a_valor;
        cout<< a_pal;
        cout<<" ";
    }
}

bool Carta::es_casen(const Carta &c) const{
//Pre:-- Post: retorna true si la carta es pot posar a sota de c (es casen)
    bool cert=false;

    if(c.es_buida()) cert = a_valor == 13;

    else{
        if(a_pal == 'P' or a_pal == 'T'){
            cert = c.a_pal == 'c' or c.a_pal == 'd';
        }
        else{
            cert = c.a_pal == 'P' or c.a_pal == 'T';
        }

        if(cert){
            cert= a_valor == (c.a_valor - 1);
        }
    }

    return cert;
}

char Carta::pal() const{
    return a_pal;
}

int Carta::valor() const{
    return a_valor;
}

bool Carta::es_visible() const{
    return a_visible;
}

bool Carta::es_buida() const{
//Pre:-- Post: retorna true si la carta �s buida, fals altrament

    return a_pal == ' ';
}

//MODIFICADORS
void Carta::canviar_visibilitat() {
    if(a_visible == false)  a_visible = true;
    else if(a_visible == true) a_visible = false;
}



bool Carta::operator==(const Carta &c) const{
    return a_valor == c.a_valor and a_pal == c.a_pal;

}
