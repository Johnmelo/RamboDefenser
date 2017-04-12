#include "Personagem.h"
#include "Estrutura.h"
#include "Inimigos.h"
#include "Item.h"

Personagem::Personagem()//gera perssonagem padrão
{
    this->image = al_load_bitmap("TheRambo.png");
    this->HP = 100;
    this->x = 650;
    this->y = 450;
    this->borda_x = 20;
    this->borda_y = 20;
    this->id = 0;
    this->speed = 2;
    this->colide = false;
    this->municao = 120;
    this->frame = 0;
    this->Aprimary = Arma(this->id,this->x,this->y + ((this->borda_y/2)-3),this->borda_x,this->borda_y);
    this->inventario = NULL;
}

void Personagem::printPersonagem(){//desenha na tela um personagem

    switch(this->frame){
        case 0:
            al_draw_bitmap_region(this->image,0,0,20,20,this->x,this->y,0);
            break;
        case 1:
            al_draw_bitmap_region(this->image,20,0,20,20,this->x,this->y,0);
            break;
        case 2:
            al_draw_bitmap_region(this->image,40,0,20,20,this->x,this->y,0);
            break;
        case 3:
            al_draw_bitmap_region(this->image,60,0,20,20,this->x,this->y,0);
            break;
        case 4:
            al_draw_bitmap_region(this->image,80,0,20,20,this->x,this->y,0);
            break;
        case 5:
            al_draw_bitmap_region(this->image,100,0,20,20,this->x,this->y,0);
            break;
        case 6:
            al_draw_bitmap_region(this->image,120,0,20,20,this->x,this->y,0);
            break;
        case 7:
            al_draw_bitmap_region(this->image,140,0,20,20,this->x,this->y,0);
            break;


    }
    //al_draw_filled_rectangle(this->x,this->y,this->x + this->borda_x,this->y + this->borda_y,al_map_rgb(0,255,0));
}

template<>
void Personagem::movePersonagem(int x,int altura,int largura,Lista<Estrutura> *E,Lista<Inimigos> *I,Lista<Item> *H){//movimenta o personagem
    Estrutura *it = NULL;
    Inimigos* it2 = NULL;
    Item *it3 = NULL;
    switch(x){
        case 0:
            this->y -= this->speed;
            this->Aprimary.y -=this->speed;
            for(int i = 0;i<E->qnt;i++){
                    it = E->iterador(i);
                    if(this->personagemColide(*it)){
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
                    if(this->personagemColide(*it2)){
                        this->colide = true;
                        break;
                    }
                }
                if(this->colide){
                    this->y += this->speed;
                    this->Aprimary.y +=this->speed;
                }else{
                    for(int i = 0;i<H->qnt;i++){
                        it3 = H->iterador(i);
                        if(this->personagemColide(*it3)){
                            if(!it3->id){
                                this->municao += it3->qnt;
                            }
                            else{
                                this->HP += it3->qnt;
                                if(this->HP > 100)
                                    this->HP = 100;
                            }
                            this->colide = true;
                            break;
                        }
                    }
                    if(this->colide){
                        it3->disponivel = false;
                    }
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
                if(this->personagemColide(*it)){
                    this->colide = true;
                    break;
                }
            }
            if(this->colide){
                    //std::cout<<"colidiu!!";
                    this->y -= this->speed;
                    this->Aprimary.y -= this->speed;
            }else{
                for(int i = 0;i<I->qnt;i++){
                    it2 = I->iterador(i);
                    if(this->personagemColide(*it2)){
                        this->colide = true;
                        break;
                    }
                }
                if(this->colide){
                    std::cout<<"colidiu!!";
                    this->y -= this->speed;
                    this->Aprimary.y -= this->speed;
                }else{
                        for(int i = 0;i<H->qnt;i++){
                            it3 = H->iterador(i);
                            if(this->personagemColide(*it3)){
                                if(!it3->id){
                            this->municao += it3->qnt;
                        }
                        else{
                            this->HP += it3->qnt;
                            if(this->HP > 100)
                                this->HP = 100;
                        }
                                this->colide = true;
                                break;
                            }
                        }
                        if(this->colide){

                                it3->disponivel = false;
                        }
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
                if(this->personagemColide(*it)){
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
                    if(this->personagemColide(*it2)){
                        this->colide = true;
                        break;
                    }
                }
                if(this->colide){
                    this->x += this->speed;
                    this->Aprimary.x += this->speed;
                }else{
                    for(int i = 0;i<H->qnt;i++){
                        it3 = H->iterador(i);
                        if(this->personagemColide(*it3)){
                            if(!it3->id){
                            this->municao += it3->qnt;
                        }
                        else{
                            this->HP += it3->qnt;
                            if(this->HP > 100)
                                this->HP = 100;
                        }
                            this->colide = true;
                            break;
                        }
                    }
                    if(this->colide){
                            it3->disponivel = false;
                    }
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
                if(this->personagemColide(*it)){
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
                    if(this->personagemColide(*it2)){
                        this->colide = true;
                        break;
                    }
                }
                if(this->colide){
                    this->x -= this->speed;
                    this->Aprimary.x -= this->speed;
                }else{
                    for(int i = 0;i<H->qnt;i++){
                        it3 = H->iterador(i);
                        if(this->personagemColide(*it3)){
                            if(!it3->id){
                            this->municao += it3->qnt;
                        }
                        else{
                            this->HP += it3->qnt;
                            if(this->HP > 100)
                                this->HP = 100;
                        }
                            this->colide = true;
                            break;
                        }
                    }
                    if(this->colide){
                            it3->disponivel = false;
                    }
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

void Personagem::changeImage(float mouse_x,float mouse_y)
{
    if(mouse_x<this->x&&mouse_y<this->y){
        //al_draw_bitmap_region(this->image,0,0,20,20,this->x,this->y,0);
        //this->image = al_load_bitmap("teste2.png");// 1;
        this->frame = 0;
    }
    else if(((mouse_x>= this->x)&&(mouse_x <= this->x+this->borda_x)&&(mouse_y < this->y))){
        //this->image = al_load_bitmap("teste3.png");//2;
        this->frame = 1;
    }
    else if((mouse_x>this->x+this->borda_x)&&(mouse_y < this->y)){
        //this->image = al_load_bitmap("teste4.png");//3;
        this->frame = 2;
    }
    else if((mouse_x > this->x+this->borda_x)&&((mouse_y>=this->y)&&(mouse_y<=this->y+this->borda_y))){
         //this->image = al_load_bitmap("teste5.png");//4;
        this->frame = 3;
    }
    else if((mouse_x> this->x + this->borda_x)&&(mouse_y > this->y +this->borda_y)){
        this->frame = 4;
        //this->image = al_load_bitmap("teste6.png");//5;
    }
    else if(((mouse_x>= this->x)&&(mouse_x<=this->x+this->borda_x))&&(mouse_y > this->y + this->borda_y)){
        this->frame = 5;
        //this->image = al_load_bitmap("teste7.png");//6;
    }
    else if((mouse_x < this->x)&&(mouse_y > this->y + this->borda_y)){
         this->frame = 6;
         //this->image = al_load_bitmap("teste8.png");//7;
    }
    else if((mouse_x < this->x)&&((mouse_y >= this->y)&&(mouse_y <= this->y + this->borda_y))){
         this->frame = 7;
         //this->image = al_load_bitmap("teste1.png");//8;
    }
}

//IMPLEMENTAR COLISOES
template<typename T>
bool Personagem::personagemColide(T obj)
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

void Personagem::personagemBaleado(int dano)
{
    if(this->HP > 0){
            this->HP -= dano;
    }
    if(this->HP < 0){
        this->HP = 0;
    }
}

void Personagem::personagemReload()
{
    if(this->municao > 0){
            int aux = 30 - this->Aprimary.Nmunicao(this->id);
            if(this->municao >= aux){
                this->Aprimary.reload(this->id,aux);
                this->municao -= aux;
            }else{
                this->Aprimary.reload(this->id,this->municao);
                this->municao  = 0;
            }
    }
}
Personagem::~Personagem()
{
    delete inventario;
}
