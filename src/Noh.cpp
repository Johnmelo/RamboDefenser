#include<iostream>
#include "Noh.h"
#include "Estrutura.h"
#include "Bala.h"
#include "Inimigos.h"
#include "Item.h"
#include "Arma.h"
template<typename T>
Noh<T>::Noh()
{
    this->next = NULL;
}
template<>
Noh<Bala>::Noh()
{
    this->next = NULL;
}
template<>
Noh<Estrutura>::Noh()
{
    this->next = NULL;
}
template<>
Noh<Inimigos>::Noh()
{
    this->next = NULL;
}

template<>
Noh<Item>::Noh()
{
    this->next = NULL;
}
template<>
Noh<Arma>::Noh()
{
    this->next = NULL;
}

template<typename T>
Noh<T>::~Noh()
{
    //dtor
}
