#include "Estrutura.h"
int NUM = 0;
Estrutura::Estrutura()
{
    //ctor
}

Estrutura::Estrutura(int code,float x,float y)
{
    switch(code){
        case 0:
            this->id = code;
            this->image = al_load_bitmap("mapa3.png");
            this->x = x;
            this->y = y;
            this->Destruivel = false;
            this->frame = 0;
            break;
        case 1:
            this->id = code;
            this->image = al_load_bitmap("TijoladaConcreto.png");
            this->Destruivel = true;
            this->Destruida = false;
            this->x = x;
            this->y = y;
            this->borda_x = 30;
            this->borda_y = 30;
            this->HP = 100;
            this->frame = 0;
            break;
        case 2:
            this->id = code;
            this->image = al_load_bitmap("Fonte.png");
            this->x = x;
            this->y = y;
            this->borda_x = 30;
            this->borda_y = 30;
            this->HP = 50;
            this->Destruivel = true;
            this->Destruida = false;
            this->frame = 0;
            break;
        case 3:
            this->id = code;
            this->image = al_load_bitmap("terra.png");
            this->x = x;
            this->y = y;
            this->Destruivel = false;
            this->frame = 0;
            break;

    }
}

void Estrutura::printEstrutura()
{
    switch(this->id){
        case 0:
            switch(this->frame){
                case 0:
                    al_draw_bitmap_region(this->image,0,0,50,50,this->x,this->y,0);
                    break;
                case 1:
                    al_draw_bitmap_region(this->image,50,0,50,50,this->x,this->y,0);
                    break;
            }
            //al_draw_bitmap(this->image,this->x,this->y,0);
            break;
        case 1:
            switch(this->frame){
                case 0:
                    al_draw_bitmap_region(this->image,0,0,30,30,this->x,this->y,0);
                    break;
                case 1:
                    al_draw_bitmap_region(this->image,30,0,30,30,this->x,this->y,0);
                    break;
                case 2:
                    al_draw_bitmap_region(this->image,60,0,30,30,this->x,this->y,0);
                    break;
                case 3:
                    al_draw_bitmap_region(this->image,90,0,30,30,this->x,this->y,0);
                    this->frame = 4;
                    break;
                case 4:
                    al_draw_bitmap_region(this->image,120,0,30,30,this->x,this->y,0);
                    this->frame = 3;
                    break;
            }
            break;
        case 2:
            if(this->frame<25){
                al_draw_bitmap_region(this->image,0,0,30,30,this->x,this->y,0);
                this->frame++;
            }else if(this->frame>=25&&this->frame<50){
                al_draw_bitmap_region(this->image,30,0,30,30,this->x,this->y,0);
                this->frame++;
            }else if(this->frame>=50&&this->frame<75){
                al_draw_bitmap_region(this->image,60,0,30,30,this->x,this->y,0);
                this->frame++;
            }else if(this->frame>=75&&this->frame<100){
                al_draw_bitmap_region(this->image,90,0,30,30,this->x,this->y,0);
                this->frame++;
            }
            else{
                this->frame = 0;
            }
            //al_draw_bitmap(this->image,this->x,this->y,0);
            break;

    }
    //al_draw_bitmap(this->image,this->x,this->y,0);
}
//IMPLEMENTAR COLISAO
void Estrutura::estruturaColidida(int id,int dano)
{
    if(this->Destruivel&&id == 1){
        this->HP -=dano;
        if(this->HP>= 75&&this->HP <100)
            this->frame = 1;
        if(this->HP>= 50&&this->HP <75)
            this->frame = 2;
        if(this->HP> 0&&this->HP <25)
            this->frame = 3;
    }
    if(this->HP < 0){
        this->HP = 0;
    }
    if((this->Destruivel)&&(this->HP==0)){
        this->Destruida = true;
    }


}

void Estrutura::deleta()
{
   // delete this->image;
    //this->~Estrutura();
}

Estrutura::~Estrutura()
{

}
