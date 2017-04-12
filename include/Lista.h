#ifndef LISTA_H
#define LISTA_H


#include "Noh.h"
//#include "Estrutura.h"

template<typename T>
class Lista
{
    public:
        int qnt;
        Noh<T> *head;
        Noh<T> *tail;
        void insertFim(T obj);
        void removeLista(T* p);
        Noh<T>* removeLi(T* p);
        T* iterador(int idx);
        template<typename G,typename C,typename D,typename A>
        void moveElemento(Lista<G> *E,C *P,Lista<D> *x,A *L);
        template<typename X,typename Y>
        void fire(X *E,Y *P);
        void printfire();
        void print();
        int verificahp();
        void libera(int x,Lista<T> *I);
        void clearlista(int x,Lista<T> *L);
        Lista();
        virtual ~Lista();
    protected:
    private:
};

#endif // LISTA_H
