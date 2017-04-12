#ifndef INIMIGOS_H
#define INIMIGOS_H

#include <Personagem.h>


class Inimigos : public Personagem
{
    public:
        int direcao;
        int quadrante;
        bool liberado;

        Inimigos();
        Inimigos(int i,int posx,int posy);
        void printInimigos();
        void moveInimigos(int x,int altura,int largura,Lista<Estrutura> *E,Lista<Inimigos> *I,Personagem *P);
        void moveSentinela(int altura,int largura,Lista<Estrutura> *E,Lista<Inimigos> *I,Personagem *P);
        void setDestino(float origem_x, float origem_y, float destino_x, float destino_y, float distancia, float &x, float &y);
        void fire();
        void liberarInimigos(int x);
        template<typename T>
        void inimigoColidido(int id,int dano,Lista<T> *I);
        template<typename T>
        bool inimigoColide(T obj);
        template<typename T>
        void dropitem(Lista<T> *L);
        int quadranteInimigo();
        virtual ~Inimigos();
    protected:
    private:
};

#endif // INIMIGOS_H
