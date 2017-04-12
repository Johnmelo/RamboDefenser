#ifndef ARMA_H
#define ARMA_H

#include<iostream>
#include "Bala.h"
//#include "Estrutura.h"
#include "Lista.h"

using namespace std;

class Arma
{
    public:

        string name;
        int id;
        Bala *municao;
        int dano;
        float alcance;
        float x;
        float y;
        float borda_x;
        float borda_y;
        float bordaP_x;
        float bordaP_y;
        int direcao;
        int time_reload;
        int time;
        Arma();
        Arma(int x,float posx,float posy,float bx,float by);
        void moveArma(float mouse_x,float mouse_y,float px,float py);
        void atirar(int x,float mouse_x,float mouse_y);
        void reload(int x,int qnt);
        template<typename T,typename C,typename F,typename G>
        void atualizarBala(int x,Lista<T> *E,Lista<C> *I,F *P,Lista<G> *H);
        void printProjetil(int x);
        void printArma();
        int Nmunicao(int x);
        virtual ~Arma();
    protected:
    private:
};

#endif // ARMA_H
