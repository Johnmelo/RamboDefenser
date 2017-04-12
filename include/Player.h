#ifndef PLAYER_H
#define PLAYER_H

#include "Personagem.h"
class Player
{
    public:
        Personagem character;
        int vidas;
        int pontos;
        Player();
        virtual ~Player();
    protected:
    private:
};

#endif // PLAYER_H
