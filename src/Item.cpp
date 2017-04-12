#include "Item.h"

Item::Item()
{
    //ctor
}

Item::Item(int i,int v,float x,float y)
{
    switch(i){
        case 0:
            this->image = al_load_bitmap("AMMO.png");
            this->x = x;
            this->y = y;
            this->borda_x = 20;
            this->borda_y = 20;
            this->qnt = v;
            this->frame = 0;
            this->disponivel = true;
            this->timedrop = 3;
            this->id = 0;
            break;
        case 1:
            this->image = al_load_bitmap("VIDA.png");
            this->x = x;
            this->y = y;
            this->borda_x = 20;
            this->borda_y = 20;
            this->qnt = v;
            this->frame = 0;
            this->disponivel = true;
            this->timedrop = 3;
            this->id = 1;
            break;
    }
}

void Item::printItem()
{
    switch(this->id){
        case 0:
            if(this->frame<50){
                al_draw_bitmap_region(this->image,0,0,20,20,this->x,this->y,0);
                this->frame++;
            }else if(this->frame>=50&&this->frame<100){
                al_draw_bitmap_region(this->image,20,0,20,20,this->x,this->y,0);
                this->frame++;
            }else if(this->frame>=100&&this->frame<150){
                al_draw_bitmap_region(this->image,40,0,20,20,this->x,this->y,0);
                this->frame++;

            }else{
                this->frame = 0;
                this->timedrop--;
            }
            break;
        case 1:
            if(this->frame<50){
                al_draw_bitmap_region(this->image,0,0,20,20,this->x,this->y,0);
                this->frame++;
            }else if(this->frame>=50&&this->frame<100){
                al_draw_bitmap_region(this->image,20,0,20,20,this->x,this->y,0);
                this->frame++;
            }else if(this->frame>=100&&this->frame<150){
                al_draw_bitmap_region(this->image,40,0,20,20,this->x,this->y,0);
                this->frame++;

            }else{
                this->frame = 0;
                this->timedrop--;
            }
            break;
    }
//al_draw_bitmap(this->image,this->x,this->y,0);
}

Item::~Item()
{
    //dtor
}
