#ifndef BALA_H
#define BALA_H
#include "Lista.h"
#include <math.h>

class Bala
{
    public:
        int id;
        float cx;
        float cy;
        float r;
        float x;
        float y;
        float borda_x;
        float borda_y;
        ///modificao
        float dx;//
        float dy;//
        int direcao;
        int dano;
        int speed;
        bool usada;
        bool colide;
        bool colidida;
        int quantidade;
        Bala();
        Bala(int id,float x,float y);
        void printBala();
        void atirarBala(float initX,float initY);

        template<typename T,typename C,typename F,typename G>
        void moveBala(Lista<T> *E,Lista<C> *I,F *P,Lista<G> *H);

        template<typename T>
        bool balaColide(T obj);

        void reta(float origem_x, float origem_y, float destino_x, float destino_y, float distancia, float &x, float &y);
        virtual ~Bala();
    protected:
    private:
};

#endif // BALA_H
