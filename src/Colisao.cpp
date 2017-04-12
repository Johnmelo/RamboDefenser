#include "Colisao.h"
template<typename T,typename C>
Colisao<T,C>::Colisao()
{
    //ctor
}
template<typename T,typename C>
bool Colisao<T,C>::Colide(T obj1,C obj2)
{
    if((((obj1.x + obj1.borda_x)>= obj2.x)&&(obj1.x<=obj2.x))&&(obj1.y >= obj2.y && obj1.y <= obj2.y + obj2.borda_y)){
        return true;
    }
}
template<typename T,typename C>
Colisao<T,C>::~Colisao()
{
    //dtor
}
