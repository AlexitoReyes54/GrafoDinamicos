#include<iostream>
#include<stdlib.h>

using namespace std;

class Arista;

class Vertice{
    Vertice *sig;
    Arista *ady;
    string nombre;
    friend class Grafo;
};

class Arista{
    Arista *sig;
    Vertice *ady;
    int peso;
    friend class Grafo;
};

class Grafo{
    Vertice *h;
    public:
        void Inicializa();
        bool Vacio();
        int Tamano(); 
        Vertice *GetVertice(string nombre);
        void InsertaArista(Vertice *origen,Vertice *destino, int peso);
        void InsertaVertice(string nombre);
        void ListaAdyacencia();
        void EliminarArista(Vertice *origen,Vertice *destino);
        void Anular();
};

void Grafo::Inicializa()
{
    h = NULL;
};

bool Grafo::Vacio()
{
    if (h == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
};

int Grafo::Tamano()
{
    int cont = 0;
    Vertice *aux;
    aux = h; 
    while (aux != NULL )
    {
        cont++;
        aux = aux->sig;
    }
    return cont;
};

Vertice *Grafo::GetVertice(string nombre)
{
    Vertice *aux;
    aux = h;
    while (aux != NULL)
    {
        if(aux->nombre == nombre)
        {
            return aux;
        }
        aux = aux->sig;
    }
    
};

void Grafo::InsertaVertice(string nombre)
{
    Vertice *nuevo = new Vertice;
    nuevo->nombre = nombre;
    nuevo->sig = NULL;
    nuevo->ady = NULL;

    if(Vacio())
    {
        h = nuevo;
    }
    else
    {
        Vertice *aux;
        aux = h; 
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
};

void Grafo::InsertaArista(Vertice *origen,Vertice *destino, int peso)
{
    Arista *nueva = new Arista;
    nueva->peso = peso;
    nueva->sig = NULL;
    nueva->ady = NULL;

    Arista *aux;

    aux = origen->ady;

    if (aux == NULL)
    {
        origen->ady = nueva;
        nueva->ady = destino;
    }
    else
    {
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nueva;
        nueva->ady = destino;
        
    }
    
};

void Grafo::ListaAdyacencia()
{
    Vertice *VerAux;
    Arista *ArisAux;

    VerAux = h;
    while (VerAux != NULL)
    {
        cout<<VerAux->nombre<<"-->";
        ArisAux = VerAux->ady;
        while (ArisAux != NULL)
        {
            cout<<ArisAux->ady->nombre<<"-->";
            ArisAux = ArisAux;
        }
        VerAux = VerAux->sig;
        cout<<endl;
    }     
};

void Grafo::Anular()
{
    Vertice *aux;
    while (h != NULL)
    {
        aux = h;
        h = h->sig;
        delete(aux);
    }
    
};

void Grafo::EliminarArista(Vertice *origen, Vertice *destino)
{
    int band = 0;
    Arista *actual, *anterior;
    actual = origen->ady;

    if (actual == NULL)
    {
        cout<<"El vertice origen no tiene artista"<<endl;
    }
    else if(actual->ady == destino)
    {
        origen->ady = actual->sig;
        delete(actual);
    }
    else
    {
        while (actual->ady != destino)
        {
            if (actual->ady == destino)
            {
                band = 1;
                anterior->sig = actual->sig;
                delete(actual);
                break;

            }   
            anterior = actual;
            actual = actual->sig;
        }
        if (band == 0)
        {
            cout<<"Esos dos vertices no estan conectados"<<endl;
        }
        
    }
    
    
}

/*
int main(){
    return 0;
}*/