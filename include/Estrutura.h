#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

using namespace std;


class Estrutura
{
    public:
        string name;
        ALLEGRO_BITMAP *image;
        float x;
        float y;
        float borda_x;
        float borda_y;
        int id;
        int HP;
        int frame;
        bool Destruivel;
        bool Destruida;
        void estruturaColidida(int id,int dano);
        Estrutura();
        Estrutura(int code,float x,float y);
        void deleta();
        void printEstrutura();
        virtual ~Estrutura();
    protected:
    private:
};

#endif // ESTRUTURA_H
