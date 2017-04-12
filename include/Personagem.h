#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include "Arma.h"
#include "Colisao.h"
#include "Lista.h"

class Personagem
{
    public:
        ALLEGRO_BITMAP *image;
        Arma Aprimary;
        Lista<Arma> *inventario;
        int id;
        float x;
        float y;
        float borda_x;
        float borda_y;
        int speed;
        int HP;
        int municao;
        bool colide;
        int frame;
        Personagem();
        Personagem(int code,int posx,int posy);
        template<typename T>
        bool personagemColide(T obj);
        void changeImage(float mouse_x,float mouse_y);
        void printPersonagem();
        template<typename D,typename T,typename G>
        void movePersonagem(int x,int altura,int largura,Lista<D> *E,Lista<T> *I,Lista<G> *H);
        void personagemBaleado(int dano);
        void personagemReload();
        virtual ~Personagem();
    protected:
    private:
};

#endif // PERSONAGEM_H
