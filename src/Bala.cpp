#include "Bala.h"
#include "Inimigos.h"
#include "Estrutura.h"
#include "Item.h"
#include<allegro5/allegro_primitives.h>
#include<iostream>
Bala::Bala()
{

}
Bala::Bala(int id,float x,float y)
{
    switch(id){
        case 0:
            this->id = id;
            this->quantidade = 30;
            this->dano = 10;
            this->speed = 5;
            this->r = 2;
            this->cx = x;
            this->cy = y;
            this->x = cx - r;
            this->y = cy - r;
            this->borda_x = 2*this->r;
            this->borda_y = 2*this->r;
            this->usada = false;
            this->colide = false;
            this->colidida = false;
            break;
        case 1:
            this->id = id;
            this->quantidade = 1;
            this->dano = 5;
            this->speed = 5;
            this->r = 2;
            this->cx = x;
            this->cy = y;
            this->x = cx - r;
            this->y = cy - r;
            this->borda_x = 2*this->r;
            this->borda_y = 2*this->r;
            this->usada = false;
            this->colide = false;
            this->colidida = false;
            break;
        case 2:
            this->id = id;
            this->quantidade = 1;
            this->dano = 10;
            this->speed = 5;
            this->r = 2;
            this->cx = x;
            this->cy = y;
            this->x = cx - r;
            this->y = cy - r;
            this->borda_x = 2*this->r;
            this->borda_y = 2*this->r;
            this->usada = false;
            this->colide = false;
            this->colidida = false;
            break;
    }
}

void Bala::printBala()
{
    al_draw_filled_circle(this->cx,this->cy,this->r,al_map_rgb(255,255,255));
}

void Bala::atirarBala(float initX,float initY)
{
    this->cx = initX;
    this->cy = initY;

}
template<>
void Bala::moveBala(Lista<Estrutura> *E,Lista<Inimigos> *I,Personagem *P,Lista<Item> *H)
{//IMPLEMENTAR COLISAO DAS BALAS
    Estrutura* it = NULL;
    Inimigos* it2 = NULL;

    reta(this->cx,this->cy,this->dx,this->dy,this->speed,this->cx,this->cy);

    for(int i = 0;i<E->qnt;i++){
                it = E->iterador(i);
                if(this->balaColide(*it)){
                    this->colide = true;
                    //std::cout<<it->HP<<std::endl;
                    break;
                }
            }
            if(this->colide){
                this->colidida = true;
                it->estruturaColidida(this->id,this->dano);
            }else{
                for(int i = 0;i<I->qnt;i++){
                    it2 = I->iterador(i);
                    if(this->balaColide(*it2)){
                        this->colide = true;
                        std::cout<<it2->HP<<std::endl;
                        break;
                    }
                }
                if(this->colide){
                    this->colidida = true;
                    it2->inimigoColidido(this->id,this->dano,H);
                }
                if(balaColide(*P)){
                    this->colidida = true;
                    if(this->id == 1||this->id == 2)
                        P->personagemBaleado(this->dano);
                }
            }
            this->colide = false;
}
template<typename T>
bool Bala::balaColide(T obj)
{
    return(this->cx>obj.x&&this->cx<(obj.x + obj.borda_x)&&this->cy >obj.y&&this->cy <(obj.y + obj.borda_y));

}

void Bala::reta(float origem_x, float origem_y, float destino_x, float destino_y, float distancia, float &x, float &y)
{

  float DT = sqrt( pow(origem_x - destino_x, 2) + pow(origem_y - destino_y, 2) );

  if (distancia >= DT) {

    x = destino_x;
    y = destino_y;
    colidida = true;

    return;
  }

  float T = distancia / DT;


  x = (1 - T) * origem_x + T * destino_x;
  y = (1 - T) * origem_y + T * destino_y;


}

Bala::~Bala()
{

}
