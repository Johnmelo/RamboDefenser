#include "Arma.h"
#include "Estrutura.h"
#include "Inimigos.h"
#include "Item.h"
#include<allegro5/allegro_primitives.h>

Arma::Arma()
{

}

Arma::Arma(int x,float posx,float posy,float bx,float by)
{
    switch(x){
        case 0:
            this->id = 0;
            this->alcance = 100.0;
            this->municao = new Bala[30];
            this->direcao = 8;
            this->x = posx;
            this->y = posy;
            this->borda_x = 5;
            this->borda_y = 5;
            this->bordaP_x = bx;
            this->bordaP_y = by;
            for(int i = 0;i < 30;i++){
                this->municao[i] = Bala(this->id,this->x,this->y);
            }
            this->time_reload = 0;
            break;
        case 1:
            this->id = 1;
            this->alcance = 100.0;
            this->municao = new Bala[5];
            this->direcao = 8;
            this->x = posx;
            this->y = posy;
            this->borda_x = 5;
            this->borda_y = 5;
            this->bordaP_x = bx;
            this->bordaP_y = by;
            for(int i = 0;i < 5;i++){
                this->municao[i] = Bala(this->id,this->x,this->y);
            }
            this->time_reload = 10;
            break;
        case 2:
            this->id = 2;
            this->alcance = 100.0;
            this->municao = new Bala[5];
            this->direcao = 8;
            this->x = posx;
            this->y = posy;
            this->borda_x = 5;
            this->borda_y = 5;
            this->bordaP_x = bx;
            this->bordaP_y = by;
            for(int i = 0;i < 5;i++){
                this->municao[i] = Bala(this->id,this->x,this->y);
            }
            break;
    }
}

void Arma::printArma()
{
    al_draw_filled_rectangle(this->x,this->y,this->x + this->borda_x,this->y + this->borda_y,al_map_rgb(255,0,0));
}

void Arma::moveArma(float mouse_x,float mouse_y,float px,float py)
{
    if(mouse_x<px&&mouse_y<py){
        this->x = px - this->borda_x;
        this->y = py - this->borda_y;
        this->direcao = 1;
    }
    if((mouse_x> px)&&((mouse_x < px+this->bordaP_x)&&(mouse_y < py))){
        this->x = px + ((this->bordaP_x/2)-3);
        this->y = py - this->borda_y;;
        this->direcao = 2;
    }
    if((mouse_x>px+this->bordaP_x)&&(mouse_y < py)){
        this->x = px+this->bordaP_x - this->borda_x;
        this->y = py;
        this->direcao = 3;
    }
    if((mouse_x > px+this->bordaP_x)&&((mouse_y>py)&&(mouse_y<py+this->bordaP_y))){
        this->x = px + this->bordaP_x;//-this->borda_x;
        this->y = py + (this->bordaP_y/2)-3;
        this->direcao = 4;
    }
    if((mouse_x> px + this->bordaP_x)&&(mouse_y > py +this->bordaP_y)){
        this->x = px + this->bordaP_x;// - this->borda_x;
        this->y = py + this->bordaP_y;// - this->borda_y;
        this->direcao = 5;
    }
    if(((mouse_x> px)&&(mouse_x<px+this->bordaP_x))&&(mouse_y > py + this->bordaP_y)){
        this->x = px + ((this->bordaP_x/2)-3);
        this->y = py + this->bordaP_y ;//+ this->borda_y;
        this->direcao = 6;
    }
    if((mouse_x < px)&&(mouse_y > py + this->bordaP_y)){
        this->x = px;
        this->y = py + this->bordaP_y - this->borda_y;
        this->direcao = 7;
    }
    if((mouse_x < px)&&((mouse_y > py)&&(mouse_y < py + this->bordaP_y))){
        this->x = px;
        this->y = py + (this->bordaP_y/2)-3;
        this->direcao = 8;
    }
}

void Arma::atirar(int x,float mouse_x,float mouse_y)
{
    for(int i = 0; i < municao->quantidade;i++){
                if(!(this->municao[i].usada)){
                    this->municao[i].direcao = this->direcao;
                    this->municao[i].dx = mouse_x;
                    this->municao[i].dy = mouse_y;
                    this->municao[i].atirarBala(this->x,this->y);
                    this->municao[i].usada = true;
                    break;
                }
            }
}

template<>
void Arma::atualizarBala(int x,Lista<Estrutura> *E,Lista<Inimigos> *I,Personagem *P,Lista<Item> *H)
{
    for(int i = 0; i < municao->quantidade;i++){
                if(this->municao[i].usada&&(!this->municao[i].colidida)){
                    this->municao[i].moveBala(E,I,P,H);
                }
    }
}

void Arma::printProjetil(int x)
{
    for(int i = 0;i < this->municao->quantidade;i++){
                if(this->municao[i].usada&&(!this->municao[i].colidida)){
                    this->municao[i].printBala();
                }
    }
}

void Arma::reload(int x,int qnt)
{
    switch(x){
        case 0:
            for(int i = 0;i<municao->quantidade;i++){
                if(this->municao[i].usada){
                    this->municao[i].usada = false;
                    this->municao[i].colidida = false;
                    qnt--;
                }
                if(qnt == 0){
                    break;
                }
            }
            break;
        default:
            for(int i = 0;i<municao->quantidade;i++){
                if(this->municao[i].usada&&this->municao[i].colidida){
                    this->municao[i].usada = false;
                    this->municao[i].colidida = false;
                }
            }
            break;
    }
}

int Arma::Nmunicao(int x)
{
    int qnt = 0;
    for(int i = 0;i<municao->quantidade;i++){
            if(!this->municao[i].usada){
                qnt++;
            }
    }
    return qnt;
}
Arma::~Arma()
{
    //dtor
}
