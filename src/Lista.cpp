#include<iostream>
#include "Lista.h"
#include "Inimigos.h""
#include "Item.h"
#include "Estrutura.h"
#include<time.h>
#include<math.h>

template<typename T>
Lista<T>::Lista()
{
    //ctor
}
template<>
Lista<Estrutura>::Lista()
{

}
template<>
Lista<Inimigos>::Lista()
{

}
template<>
Lista<Item>::Lista()
{

}


///ESTRUTURA
template<>
void Lista<Estrutura>::insertFim(Estrutura obj)
{
    Noh<Estrutura> *aux = new Noh<Estrutura>;
    if(this->qnt == 0){
        aux->elemento = obj;
        aux->next = NULL;
        this->qnt++;
        this->head = aux;
        this->tail = aux;
    }else{
        aux->elemento = obj;
        aux->next = NULL;
        this->tail->next = aux;
        this->tail = aux;
        this->qnt++;
    }

}
template<>
void Lista<Estrutura>::removeLista(Estrutura* p)
{
    if(this->qnt > 0){
        Noh<Estrutura> *aux = this->head;
        Noh<Estrutura> *aux2;
        if(p == &this->head->elemento){
            this->head = aux->next;
            this->qnt--;
            delete aux;
        }
        else if( p == &this->tail->elemento){
                while(aux->next != this->tail){
                    aux = aux->next;
                }
                this->tail = aux;
                delete aux->next;
                this->tail->next = NULL;
                this->qnt--;

        }
        else{
            while(aux->next != NULL){
                if(&aux->elemento == p){
                    aux2 = aux;
                }
                aux = aux->next;
            }
            aux = this->head;
            while(aux->next != aux2){
                aux=aux->next;
            }
            aux->next = aux2->next;
            this->qnt--;
            delete aux2;
        }
    }
}
template<>
Noh<Estrutura>* Lista<Estrutura>::removeLi(Estrutura* p)
{
    if(this->qnt > 0){
        Noh<Estrutura> *aux = this->head;
        Noh<Estrutura> *aux2;
        if(p == &this->head->elemento){
            this->head = aux->next;
            this->qnt--;
            delete aux;
            return this->head;
        }
        else if( p == &this->tail->elemento){
            while(aux->next != this->tail){
                aux = aux->next;
            }
            this->tail = aux;
            delete aux->next;
            this->tail->next = NULL;
            this->qnt--;
            return this->tail;
        }
        else{
            while(aux->next != NULL){
                if(&aux->elemento == p){
                    aux2 = aux;
                }
                aux = aux->next;
            }
            aux = this->head;
            while(aux->next != aux2){
                aux=aux->next;
            }
            aux->next = aux2->next;
            delete aux2;
            this->qnt--;
            return aux;
        }
    }
}
template<>
Estrutura* Lista<Estrutura>::iterador(int idx)
{
    if(idx==0){
        return &this->head->elemento;
    }else{
        Noh<Estrutura>* aux = this->head;
        for(int i = 0;i<=idx;i++){
            if(i == idx){
                return &aux->elemento;
                break;
            }
            aux = aux->next;
        }
    }
}
template<>
void Lista<Estrutura>::print()
{
    if(this->qnt > 0){
        Noh<Estrutura> *aux = this->head;
        Noh<Estrutura> *aux2 = NULL;
        while(aux->next != NULL){
            if(aux->elemento.Destruida){
                aux = this->removeLi(&aux->elemento);
            }else{
                aux->elemento.printEstrutura();
                aux = aux->next;
            }
        }
        if(aux->elemento.Destruida){
            this->removeLista(&aux->elemento);
        }else{
            aux->elemento.printEstrutura();
        }
    }
}
template<>
int Lista<Estrutura>::verificahp()
{
    int hp = 0;
    if(this->qnt > 0){
    Noh<Estrutura> *aux = this->head ;
    while(aux->next != NULL){
        hp += aux->elemento.HP;
        aux = aux->next;
    }
    hp += aux->elemento.HP;
    }
    return hp;

}


///INIMIGOS
template<>
void Lista<Inimigos>::insertFim(Inimigos obj)
{
    Noh<Inimigos> *aux = new Noh<Inimigos>;
    if(this->qnt == 0){
        aux->elemento = obj;
        //aux->previous = NULL;
        aux->next = NULL;
        this->qnt++;
        this->head = aux;
        this->tail = aux;
    }else{
        aux->elemento = obj;
        aux->next = NULL;
        //aux->previous = this->tail;
        this->tail->next = aux;
        this->tail = aux;
        this->qnt++;
    }

}
template<>
void Lista<Inimigos>::removeLista(Inimigos* p)
{
    if(this->qnt > 0){
        Noh<Inimigos> *aux = this->head;
        Noh<Inimigos> *aux2;
        if(p == &this->head->elemento){
            this->head = aux->next;
            this->qnt--;
            delete aux;
        }
        else if( p == &this->tail->elemento){
                while(aux->next != this->tail){
                    aux = aux->next;
                }
                this->tail = aux;
                delete aux->next;
                this->tail->next = NULL;
                this->qnt--;

        }
        else{
            while(aux->next != NULL){
                if(&aux->elemento == p){
                    aux2 = aux;
                }
                aux = aux->next;
            }
            aux = this->head;
            while(aux->next != aux2){
                aux=aux->next;
            }
            aux->next = aux2->next;
            this->qnt--;
            delete aux2;
        }
    }
}
template<>
Noh<Inimigos>* Lista<Inimigos>::removeLi(Inimigos* p)
{
    if(this->qnt > 0){
        Noh<Inimigos> *aux = this->head;
        Noh<Inimigos> *aux2;
        if(p == &this->head->elemento){
            this->head = aux->next;
            this->qnt--;
            delete aux;
            return this->head;
        }
        else if( p == &this->tail->elemento){
            while(aux->next != this->tail){
                aux = aux->next;
            }
            this->tail = aux;
            delete aux->next;
            this->tail->next = NULL;
            this->qnt--;
            return this->tail;
        }
        else{
            while(aux->next != NULL){
                if(&aux->elemento == p){
                    aux2 = aux;
                }
                aux = aux->next;
            }
            aux = this->head;
            while(aux->next != aux2){
                aux=aux->next;
            }
            aux->next = aux2->next;
            delete aux2;
            this->qnt--;
            return aux;
        }
    }
}
template<>
Inimigos* Lista<Inimigos>::iterador(int idx)
{
    if(idx==0){
        return &this->head->elemento;
    }else{
        Noh<Inimigos>* aux = this->head;
        for(int i = 0;i<=idx;i++){
            if(i == idx){
                return &aux->elemento;
                break;
            }
            aux = aux->next;
        }
    }
}
template<>
void Lista<Inimigos>::print()
{
    if(this->qnt > 0){
        Noh<Inimigos> *aux = this->head;
        while(aux->next != NULL){
            if(aux->elemento.HP < 0){
              // I->insertFim(aux->elemento.dropitem());
                aux = this->removeLi(&aux->elemento);
            }else{
                aux->elemento.printInimigos();
                aux = aux->next;
            }
        }
        if(aux->elemento.HP < 0){
            this->removeLista(&aux->elemento);
        }else{
            aux->elemento.printInimigos();
        }
    }
}

template<>template<>
void Lista<Inimigos>::fire(Estrutura *E,Personagem *P)
{
    if(this->qnt > 0){
        Noh<Inimigos> *aux = this->head;
        while(aux->next != NULL){
                if(aux->elemento.Aprimary.Nmunicao(aux->elemento.id)== 0){
                    aux->elemento.Aprimary.reload(aux->elemento.id,0);
                }
                if(aux->elemento.liberado){
                        if(sqrt(pow(aux->elemento.x - P->x,2)+(pow(aux->elemento.y - P->y,2))) <= 200){
                            aux->elemento.Aprimary.atirar(aux->elemento.id,P->x+1,P->y+1);
                        }else{
                            aux->elemento.Aprimary.atirar(aux->elemento.id,E->x+E->borda_x,E->y+E->borda_y);
                        }
                }
                aux = aux->next;
        }
        if(aux->elemento.Aprimary.Nmunicao(aux->elemento.id)==0){
            aux->elemento.Aprimary.reload(aux->elemento.id,0);
        }
        if(aux->elemento.liberado){
            aux->elemento.Aprimary.atirar(aux->elemento.id,E->x,E->y);
        }
    }
}
template<>
void Lista<Inimigos>::printfire()
{
    if(this->qnt > 0){
        Noh<Inimigos> *aux = this->head;
        while(aux->next != NULL){
                aux->elemento.Aprimary.printProjetil(aux->elemento.id);
                aux = aux->next;
        }
        aux->elemento.Aprimary.printProjetil(aux->elemento.id);
    }

}

template<>template<>
void Lista<Inimigos>::moveElemento(Lista<Estrutura> *E,Personagem *P,Lista<Item> *x,Estrutura *L)
{
    int direction = 0;
    srand(time(NULL));
    if(this->qnt > 0){
        Noh<Inimigos> *aux = this->head;
        while(aux->next != NULL){
                direction = aux->elemento.quadranteInimigo();
                if(aux->elemento.id == 2)
                    aux->elemento.moveSentinela(600,800,E,this,P);
                else
                    aux->elemento.moveInimigos(rand()%4,600,800,E,this,P);

                if((sqrt(pow(aux->elemento.x,2) - pow(P->x,2))<= 100)||(sqrt(pow(aux->elemento.y,2) - pow(P->y,2))<= 100))
                    aux->elemento.Aprimary.moveArma(P->x,P->y,aux->elemento.x,aux->elemento.y);
                else
                   aux->elemento.Aprimary.moveArma(L->x,L->y,aux->elemento.x,aux->elemento.y);

                aux->elemento.Aprimary.atualizarBala(aux->elemento.id,E,this,P,x);
                aux = aux->next;
        }
        direction = aux->elemento.quadranteInimigo();
        aux->elemento.moveInimigos(rand()%4,600,800,E,this,P);
        if((sqrt(pow(aux->elemento.x,2) - pow(P->x,2))<= 100)||(sqrt(pow(aux->elemento.y,2) - pow(P->y,2))<= 100))
                    aux->elemento.Aprimary.moveArma(P->x,P->y,aux->elemento.x,aux->elemento.y);
        else
                   aux->elemento.Aprimary.moveArma(L->x,L->y,aux->elemento.x,aux->elemento.y);
        aux->elemento.Aprimary.moveArma(800,600,aux->elemento.x,aux->elemento.y);
        aux->elemento.Aprimary.atualizarBala(aux->elemento.id,E,this,P,x);
        }
}
template<>
void Lista<Inimigos>::libera(int x,Lista<Inimigos> *I)
{   if(this->qnt > 0){
        Noh<Inimigos> *aux = this->head;
        int qnt = 0;
        bool done = false;
        while(aux->next != NULL&&!done){
            aux->elemento.liberarInimigos(x);
            aux = aux->next;
            qnt++;
            if(x == 1){
                if(qnt == 4)
                    done = true;
            }else{
                if(qnt == 5)
                    done = true;
            }
        }
        aux->elemento.liberarInimigos(x);
    }
}



///ITENS
template<>
void Lista<Item>::insertFim(Item obj)
{
    Noh<Item> *aux = new Noh<Item>;
    if(this->qnt == 0){
        aux->elemento = obj;
        aux->next = NULL;
        this->qnt++;
        this->head = aux;
        this->tail = aux;
    }else{
        aux->elemento = obj;
        aux->next = NULL;
        this->tail->next = aux;
        this->tail = aux;
        this->qnt++;
    }

}
template<>
void Lista<Item>::removeLista(Item* p)
{
    if(this->qnt > 0){
        Noh<Item> *aux = this->head;
        Noh<Item> *aux2;
        if(p == &this->head->elemento){
            this->head = aux->next;
            this->qnt--;
            delete aux;
        }
        else if( p == &this->tail->elemento){
                while(aux->next != this->tail){
                    aux = aux->next;
                }
                this->tail = aux;
                delete aux->next;
                this->tail->next = NULL;
                this->qnt--;

        }
        else{
            while(aux->next != NULL){
                if(&aux->elemento == p){
                    aux2 = aux;
                }
                aux = aux->next;
            }
            aux = this->head;
            while(aux->next != aux2){
                aux=aux->next;
            }
            aux->next = aux2->next;
            this->qnt--;
            delete aux2;
        }
    }
}
template<>
Noh<Item>* Lista<Item>::removeLi(Item* p)
{
    if(this->qnt > 0){
        Noh<Item> *aux = this->head;
        Noh<Item> *aux2;
        if(p == &this->head->elemento){
            this->head = aux->next;
            this->qnt--;
            delete aux;
            return this->head;
        }
        else if( p == &this->tail->elemento){
            while(aux->next != this->tail){
                aux = aux->next;
            }
            this->tail = aux;
            delete aux->next;
            this->tail->next = NULL;
            this->qnt--;
            return this->tail;
        }
        else{
            while(aux->next != NULL){
                if(&aux->elemento == p){
                    aux2 = aux;
                }
                aux = aux->next;
            }
            aux = this->head;
            while(aux->next != aux2){
                aux=aux->next;
            }
            aux->next = aux2->next;
            delete aux2;
            this->qnt--;
            return aux;
        }
    }
}
template<>
Item* Lista<Item>::iterador(int idx)
{
    if(idx==0){
        return &this->head->elemento;
    }else{
        Noh<Item>* aux = this->head;
        for(int i = 0;i<=idx;i++){
            if(i == idx){
                return &aux->elemento;
                break;
            }
            aux = aux->next;
        }
    }
}
template<>
void Lista<Item>::print()
{
    if(this->qnt > 0){
        Noh<Item> *aux = this->head;
        while(aux->next != NULL){
            if(!aux->elemento.disponivel||aux->elemento.timedrop == 0){
                aux = this->removeLi(&aux->elemento);
            }else{
                aux->elemento.printItem();
                aux = aux->next;
            }
        }
        if(!aux->elemento.disponivel||aux->elemento.timedrop == 0){
            this->removeLista(&aux->elemento);
        }else{
            aux->elemento.printItem();
        }
    }
}
template<>
void Lista<Estrutura>::clearlista(int x,Lista<Estrutura> *L)
{
    Noh<Estrutura> *aux = L->head;
    if(x > 0){
        while(aux->next != NULL){
            aux = aux->next;
        }
        L->removeLista(&aux->elemento);
        L->clearlista(this->qnt,L);
    }
}

template<>
void Lista<Inimigos>::clearlista(int x,Lista<Inimigos> *L)
{
    Noh<Inimigos> *aux = L->head;
    if(x > 0){
        while(aux->next != NULL){
            aux = aux->next;
        }
        L->removeLista(&aux->elemento);
        L->clearlista(this->qnt,L);
    }
}

template<typename T>
Lista<T>::~Lista()
{
    delete head;
    delete tail;
}
