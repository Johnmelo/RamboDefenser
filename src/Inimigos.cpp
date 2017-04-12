#include "Inimigos.h"
#include "Item.h"
#include<time.h>

Inimigos::Inimigos()
{

}
Inimigos::Inimigos(int i,int posx,int posy)
{
    switch(i){
    case 1:
        this->HP = 50;
        this->image = al_load_bitmap("DroneE.png");
        this->x = posx;
        this->y = posy;
        this->borda_x = 20;
        this->borda_y = 20;
        this->id = 1;
        this->speed = 1;
        this->colide = false;
    //this->direcao = 0;
        this->frame = 0;
        this->liberado = false;
        this->Aprimary = Arma(this->id,this->x,this->y + ((this->borda_y/2)-3),this->borda_x,this->borda_y);
        break;
    case 2:
        this->HP = 50;
        this->image = al_load_bitmap("Drone02B.png");
        this->x = posx;
        this->y = posy;
        this->borda_x = 20;
        this->borda_y = 20;
        this->id = 2;
        this->speed = 1;
        this->colide = false;
        //this->direcao = 0;
        this->frame = 0;
        this->liberado = false;
        this->Aprimary = Arma(this->id,this->x,this->y + ((this->borda_y/2)-3),this->borda_x,this->borda_y);
        break;
    }
}

void Inimigos::printInimigos(){
    //al_draw_bitmap(this->image,this->x,this->y,0);
    //al_draw_filled_rectangle(this->x,this->y,this->x + this->borda_x,this->y + this->borda_y,al_map_rgb(255,255,0));
    switch(this->id){
        case 1:
            if(!this->frame){
                al_draw_bitmap_region(this->image,0,0,20,20,this->x,this->y,0);
                    this->frame = 1;
            }
            else{
                al_draw_bitmap_region(this->image,20,0,20,20,this->x,this->y,0);
                this->frame = 0;
            }
        break;
        case 2:
                switch(this->frame){
                    case 0:
                        al_draw_bitmap_region(this->image,0,0,20,20,this->x,this->y,0);
                        this->frame++;
                    break;
                    case 1:
                        al_draw_bitmap_region(this->image,20,0,20,20,this->x,this->y,0);
                        this->frame++;
                    break;
                    case 2:
                        al_draw_bitmap_region(this->image,40,0,20,20,this->x,this->y,0);
                        this->frame++;
                    break;
                    case 3:
                        al_draw_bitmap_region(this->image,60,0,20,20,this->x,this->y,0);
                        this->frame++;
                    break;
                    case 4:
                        al_draw_bitmap_region(this->image,80,0,20,20,this->x,this->y,0);
                        this->frame++;
                    break;
                    case 5:
                        al_draw_bitmap_region(this->image,100,0,20,20,this->x,this->y,0);
                        this->frame++;
                    break;
                    case 6:
                        al_draw_bitmap_region(this->image,120,0,20,20,this->x,this->y,0);
                        this->frame++;
                    break;
                    case 7:
                        al_draw_bitmap_region(this->image,140,0,20,20,this->x,this->y,0);
                        this->frame = 0;
                    break;
                }
        break;

    }
}

void Inimigos::moveInimigos(int x,int altura,int largura,Lista<Estrutura> *E,Lista<Inimigos> *I,Personagem *P)
{
    if(this->liberado){
    Estrutura* it = NULL;
    Inimigos* it2 = NULL;
    switch(x){
        case 0:
                this->y -= this->speed;
                this->Aprimary.y -=this->speed;
                for(int i = 0;i<E->qnt;i++){
                    it = E->iterador(i);
                    if(this->inimigoColide(*it)){
                        this->colide = true;
                        break;
                    }
                }
                if(this->colide){
                    this->y += this->speed;
                    this->Aprimary.y +=this->speed;
                }else{
                    for(int i = 0;i<I->qnt;i++){
                        it2 = I->iterador(i);
                        if(this->inimigoColide(*it2)&&this!=it2){
                            this->colide = true;
                            break;
                        }
                    }
                   if(this->colide){
                        this->y += this->speed;
                        this->Aprimary.y +=this->speed;
                    }
                   if(this->inimigoColide(*P))
                        this->colide = true;
                    if(this->colide){
                        this->y += this->speed;
                        this->Aprimary.y +=this->speed;
                    }
                    if(this->y < 0){
                        this->y = 0;
                        this->Aprimary.y = 0;
                    }
                }
                this->colide = false;
        break;
        case 1:
            this->y += this->speed;
            this->Aprimary.y += this->speed;
            for(int i = 0;i<E->qnt;i++){
                it = E->iterador(i);
                if(this->inimigoColide(*it)){
                    this->colide = true;
                    break;
                }
            }
            if(this->colide){
                    this->y -= this->speed;
                    this->Aprimary.y -= this->speed;
            }else{
                    for(int i = 0;i<I->qnt;i++){
                        it2 = I->iterador(i);
                        if(this->inimigoColide(*it2)&&this!=it2){
                            this->colide = true;
                            break;
                        }
                    }
                    if(this->colide){
                        this->y -= this->speed;
                        this->Aprimary.y -= this->speed;
                    }
                    if(this->inimigoColide(*P))
                        this->colide = true;
                    if(this->colide){
                        this->y -= this->speed;
                        this->Aprimary.y -= this->speed;
                    }
                    if(this->y > altura - this->borda_y){
                        this->y = altura - this->borda_y;
                        this->Aprimary.y = altura - this->borda_y;
                    }
            }
            this->colide = false;
        break;
        case 2:
            this->x -= this->speed;
            this->Aprimary.x -= this->speed;
            for(int i = 0;i<E->qnt;i++){
                it = E->iterador(i);
                if(this->inimigoColide(*it)){
                    this->colide = true;
                    break;
                }
            }
            if(this->colide){
                    this->x += this->speed;
                    this->Aprimary.x += this->speed;
            }else{
                for(int i = 0;i<I->qnt;i++){
                    it2 = I->iterador(i);
                    if(this->inimigoColide(*it2)&&this!=it2){
                        this->colide = true;
                        break;
                    }
                }
                if(this->colide){
                        this->x += this->speed;
                        this->Aprimary.x += this->speed;
                }
                if(this->inimigoColide(*P))
                        this->colide = true;
                if(this->colide){
                        this->x += this->speed;
                        this->Aprimary.x += this->speed;
                }
                if(this->x < 0){
                    this->x = 0;
                    this->Aprimary.x = 0;
                }
            }
            this->colide = false;
        break;
        case 3:
            this->x += this->speed;
            this->Aprimary.x += this->speed;
            for(int i = 0;i<E->qnt;i++){
                it = E->iterador(i);
                if(this->inimigoColide(*it)){
                    this->colide = true;
                    break;
                }
            }
            if(this->colide){
                    this->x -= this->speed;
                    this->Aprimary.x -= this->speed;
            }else{
                for(int i = 0;i<I->qnt;i++){
                    it2 = I->iterador(i);
                    if(this->inimigoColide(*it2)&&this!=it2){
                        this->colide = true;
                        break;
                    }
                }
                if(this->colide){
                        this->x -= this->speed;
                        this->Aprimary.x -= this->speed;
                }
                if(this->inimigoColide(*P))
                        this->colide = true;
                if(this->colide){
                        this->x -= this->speed;
                        this->Aprimary.x -= this->speed;
                }
                if(this->x > largura - this->borda_x){
                    this->x = largura - this->borda_x;
                    this->Aprimary.x = largura - this->borda_x;
                }
            }
            this->colide = false;
        break;
    }
    }

}

void Inimigos::moveSentinela(int altura,int largura,Lista<Estrutura> *E,Lista<Inimigos> *I,Personagem *P)
{
    if(this->liberado){
        Estrutura* it = NULL;
        Inimigos* it2 = NULL;
        float aux_x = this->x;
        float aux_y = this->y;
        setDestino(this->x,this->y,P->x,P->y,this->speed,this->x,this->y);
        for(int i = 0;i<E->qnt;i++){
                it = E->iterador(i);
                if(this->inimigoColide(*it)){
                    this->colide = true;
                    break;
                }
        }
        if(this->colide){
            setDestino(this->x,this->y,aux_x,aux_y,this->speed,this->x,this->y);
        }else{
            for(int i = 0;i<I->qnt;i++){
                    it2 = I->iterador(i);
                    if(this->inimigoColide(*it2)&&this!=it2){
                        this->colide = true;
                        break;
                    }
            }
            if(this->colide){
                setDestino(this->x,this->y,aux_x,aux_y,this->speed,this->x,this->y);
            }
            if(this->inimigoColide(*P)){
                this->colide = true;
                if(this->colide){
                    setDestino(this->x,this->y,aux_x,aux_y,this->speed,this->x,this->y);
                }
                /*aif(this->y < 0){
                    this->y = 0;
                    this->Aprimary.y = 0;
                }*/
            }
            this->colide = false;
    }
}
}

void Inimigos::setDestino(float origem_x, float origem_y, float destino_x, float destino_y, float distancia, float &x, float &y)
{

  float DT = sqrt( pow(origem_x - destino_x, 2) + pow(origem_y - destino_y, 2) );

  if (distancia >= DT) {

    x = destino_x;
    y = destino_y;
    //colidida = true;

    return;
  }

  float T = distancia / DT;


  x = (1 - T) * origem_x + T * destino_x;
  y = (1 - T) * origem_y + T * destino_y;


}

void Inimigos::fire()
{

}

void Inimigos::liberarInimigos(int x)
{
    switch(x){
        case 1:
            if(this->x == 0&&this->y == -40){
                this->y = 0;
                this->liberado = true;
        //this->quadrante = 1;
            }
            else if(this->x == 350&&this->y == -40){
                this->y = 0;
                this->liberado = true;
        //this->quadrante = 1;
            }
            else if(this->x == 700&&this->y == -40){
                this->y = 0;
                this->liberado = true;
        //this->quadrante = 2;
            }
            else if(this->x == -40&&this->y == 200){
                this->x = 0;
                this->liberado = true;
        //this->quadrante = 1;
            }
            else if(this->x == -40&&this->y == 400){
                this->x = 0;
                this->liberado = true;
        //this->quadrante = 3;
            }
        break;
        case 2:
            if(this->x == 0&&this->y == -40){
                this->y = 0;
                this->liberado = true;
        //this->quadrante = 1;
            }
            else if(this->x == -40 && this->y == 300){
                this->x = 0;
                this->liberado = true;
                //this->quadrante = 1;
            }
            else if(this->x == 0 && this->y == 640){
                this->y = 600 - this->borda_y;
                this->liberado = true;
        //this->quadrante = 1;
            }
            else if(this->x == 800 && this->y == -40){
                this->x = 800 - this->borda_x;
                this->y = 0;
                this->liberado = true;
        //this->quadrante = 1;
            }
            else if(this->x == 840 && this->y == 300){
                this->x = 800 - this->borda_x;
                this->liberado = true;
                //this->quadrante = 1;ssssssss
            }
            else if(this->x == 800 && this->y == 640){
                this->x = 800 - this->borda_x;
                this->y = 600 - this->borda_y;
                this->liberado = true;
            //this->quadrante = 1;
            }
            break;


    }





}
template<>
void Inimigos::inimigoColidido(int id,int dano,Lista<Item> *I)
{
    if(id == 0){
        this->HP -= dano;
    }
    if(this->HP < 0){
        this->dropitem(I);
    }

}

template<typename T>
bool Inimigos::inimigoColide(T obj)
{
    if((this->y+this->borda_y >= obj.y)&&(this->y+this->borda_y<=obj.y+obj.borda_y)&&(this->x+this->borda_x>=obj.x)&&(this->x+this->borda_x<=obj.x+obj.borda_x)){
        return true;
    }
    else{
        if((this->y>=obj.y)&&(this->y<=obj.y+obj.borda_y)&&(this->x+this->borda_x>=obj.x)&&(this->x+this->borda_x<=obj.x+obj.borda_x))
            return true;
        else
            if((this->y+this->borda_y >= obj.y)&&(this->y+this->borda_y<=obj.y+obj.borda_y)&&(this->x>=obj.x)&&(this->x<=obj.x+obj.borda_x))
                return true;
            else
                if((this->y>= obj.y)&&(this->y<=obj.y+obj.borda_y)&&(this->x>=obj.x)&&(this->x<=obj.x+obj.borda_x))
                    return true;
                else
                    return false;
        }
}

template<typename T>
void Inimigos::dropitem(Lista<T> *L)
{
    int r = 0,s = 0;
    srand(time(NULL));
    r = rand()%30;
    s = rand()%100;
    if(s % 5 == 0)
        s = 1;
    else
        s = 0;

    L->insertFim(Item(s,1+r,this->x,this->y));
}

int Inimigos::quadranteInimigo()
{
    if((this->x < 800/2)&&(this->y < 600/2))
        return 1;///800,600
    else if((this->x < 800/2)&&(this->y > 600/2))
                return 2;///800,this->y
    else if((this->x > 800/2)&&(this->y < 600/2))
                return 3;///this->x,600
    else if((this->x > 800/2)&&(this->x < (800/2+800)/2)&&(this->y > 600/2)&&(this->y < (600/2+600)/2))
                return 1;///800,600
    else if((this->x > 800/2)&&(this->x < (800/2+800)/2)&&(this->y > (600/2+600)/2)&&(this->y<600))
                return 2;///800,this->y

}

Inimigos::~Inimigos()
{
    //dtor
}
