#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Nodo.h"
using namespace std;


template <typename Tipo>
class Lista
{
public:
    Nodo<Tipo>* inicio;

    Lista()
    {
        inicio = NULL;
    }

    void imprimir()
    {
        for(Nodo<Tipo>* temp = inicio;
            temp!=NULL;
            temp = temp->sig)
        {
            cout<<temp->num<<endl;
        }
    }

    void agregarAlInicio(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            nuevo->sig = inicio;
            inicio = nuevo;
        }
    }

    void agregarAlFinal(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            Nodo<Tipo>*temp = inicio;
            while(temp->sig!=NULL)
            {
                temp=temp->sig;
            }
            temp->sig = nuevo;
        }
    }

    void borrar(Tipo valor_a_borrar)
    {
        if(inicio->num == valor_a_borrar)
        {
            Nodo<Tipo>* borrar = inicio;
            inicio = inicio->sig;
            delete borrar;
        }else
        {
            Nodo<Tipo>* temp = inicio;
            while(temp->sig->num!=valor_a_borrar)
            {
                temp=temp->sig;
                if(temp->sig==NULL)
                    return;
            }
            Nodo<Tipo>* borrar = temp->sig;
            temp->sig = temp->sig->sig;
            delete temp->sig;
        }
    }

    //Devuelve la cantidad de valores o nodos que existen en la lista
    int contarValores()
    {
            Nodo<Tipo>*contador = inicio; // se crea el nodo
            int counter = 0; //se inicializa el contador
            while(contador!=NULL) //mientras el contador sea distinto a null seguira ejecutandose
            {
                contador=contador->sig; //pasa al siguiente en la lista
                counter++; // agrega + 1 por cada vez que se ejecuta
            }
            return counter; //se devuelve el counter
    }


    //Asumiendo que los valores de lista son enteros naturales
    //Devuelve true si todos los valores de la lista son pares, de lo contrario devuelve false
    bool sonPares()
    {
        bool par;
        Nodo<Tipo>*couple = inicio;
        Nodo<Tipo> *pares;
        int a;
        while(couple->sig!=NULL)
        {
            pares = couple;
            if(pares%2 == 0)
            {
                par = true;
            }
            else
            {
                par = false;
            }
        }
        return par;
    }
};
#endif // LISTA_H
