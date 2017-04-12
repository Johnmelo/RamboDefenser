#ifndef ITEM_H
#define ITEM_H

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
class Item
{
    public:
        ALLEGRO_BITMAP *image;
        float x;
        float y;
        float borda_x;
        float borda_y;
        int id;
        int qnt;
        int frame;
        bool disponivel;
        float timedrop;

        void printItem();
        Item();
        Item(int i,int v,float x,float y);
        virtual ~Item();
    protected:
    private:
};

#endif // ITEM_H
