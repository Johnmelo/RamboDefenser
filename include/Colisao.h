#ifndef COLISAO_H
#define COLISAO_H

#include "Personagem.h"
#include "Estrutura.h"
#include "Bala.h"
template<typename T,typename C>
class Colisao
{
    public:

        bool Colide(T obj1,C obj2);
        Colisao();
        virtual ~Colisao();
    protected:
    private:
};

#endif // COLISAO_H
