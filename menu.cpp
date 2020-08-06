#include <iostream>
//#include <windows.h>
#include "grafo_Estructura.cpp"

using namespace std;

int main()
{
    Grafo G;
    G.Inicializa();
    int opc;

/*
    G.InsertaVertice("TIJ");
    G.InsertaVertice("MTY");
    G.InsertaVertice("MZT");
    G.InsertaVertice("BJX");
    G.InsertaVertice("GDL");
    G.InsertaVertice("SAN");
    G.InsertaVertice("TAM");
    G.InsertaVertice("MEX");
    G.InsertaVertice("CUN");
    G.InsertaVertice("MID");

    G.InsertaArista(G.GetVertice("TIJ"), G.GetVertice("MTY"), 800);
    G.InsertaArista(G.GetVertice("MZT"), G.GetVertice("TIJ"), 400);
    G.InsertaArista(G.GetVertice("MZT"), G.GetVertice("BJX"), 300);
    G.InsertaArista(G.GetVertice("MTY"), G.GetVertice("BJX"), 700);
    G.InsertaArista(G.GetVertice("BJX"), G.GetVertice("SAN"), 900);
    G.InsertaArista(G.GetVertice("BJX"), G.GetVertice("TAM"), 400);
    G.InsertaArista(G.GetVertice("BJX"), G.GetVertice("MEX"), 350);
    G.InsertaArista(G.GetVertice("GDL"), G.GetVertice("MZT"), 500);
    G.InsertaArista(G.GetVertice("GDL"), G.GetVertice("MTY"), 450);
    G.InsertaArista(G.GetVertice("GDL"), G.GetVertice("BJX"), 250);
    G.InsertaArista(G.GetVertice("GDL"), G.GetVertice("MEX"), 500);
    G.InsertaArista(G.GetVertice("SAN"), G.GetVertice("MID"), 1200);
    G.InsertaArista(G.GetVertice("TAM"), G.GetVertice("MID"), 450);
    G.InsertaArista(G.GetVertice("MEX"), G.GetVertice("MID"), 450);
    G.InsertaArista(G.GetVertice("MEX"), G.GetVertice("CUN"), 650);
    G.InsertaArista(G.GetVertice("CUN"), G.GetVertice("GDL"), 650);
*/
    do
    {
        system("cls");
        cout<<"1. Ingresar Vertice"<<endl;
        cout<<"2. Ingresar arista"<<endl;
        cout<<"3. Lista de adyacencia"<<endl;
        cout<<"4. Tama�o"<<endl;
        cout<<"5. Eliminar vertice"<<endl;
        cout<<"6. Eliminar arista"<<endl;
        cout<<"7. Anular"<<endl;
        cout<<"8. Recorrido en anchura"<<endl;
        cout<<"9. Recorrido en profundidad"<<endl;
        cout<<"10. Primero en anchura"<<endl;
        cout<<"11. Primero en profundidad"<<endl;
        cout<<"12. Primero el mejor"<<endl;
        cout<<"13. Salir"<<endl;
        cout<<endl<<"Elija una opcion: ";
        cin>>opc;
        switch(opc)
        {
        case 1:
        {
            string nombre;
            system("cls");
            cout<<"Ingrese el nombre del vertice: ";
            cin.ignore();
            getline(cin, nombre, '\n');
            G.InsertaVertice(nombre);
            cin.get();
            cin.get();
            break;
        }
        case 2:
        {
            string origen, destino;
            int peso;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese del nombre del vertice origen: ";
                cin.ignore();
                getline(cin, origen, '\n');
                cout<<"Ingrese el nombre del vertice destino: ";
                getline(cin, destino, '\n');
                cout<<"Ingrese el peso: ";
                cin>>peso;

                if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                {
                    cout<<"Uno de los vertices no es valido"<<endl;
                }
                else
                {
                    G.InsertaArista(G.GetVertice(origen), G.GetVertice(destino), peso);
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 3:
        {
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                G.ListaAdyacencia();
            }
            cin.get();
            cin.get();
            break;
        }
        case 4:
        {
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Tamano: "<<G.Tamano()<<endl;
            }
            cin.get();
            cin.get();
            break;
        }
        case 5:
        {
            string nombre;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese el nombre del vertice a eliminar: ";
                cin.ignore();
                getline(cin, nombre, '\n');
                if(G.GetVertice(nombre) == NULL)
                {
                    cout<<"Vertice invalido"<<endl;
                }
                else
                {
                   //G.EliminarVertice(G.GetVertice(nombre));
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 6:
        {
            string origen, destino;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese del nombre del vertice origen: ";
                cin.ignore();
                getline(cin, origen, '\n');
                cout<<"Ingrese el nombre del vertice destino: ";
                getline(cin, destino, '\n');
                if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                {
                    cout<<"Vertices no validos"<<endl;
                }
                else
                {
                    //G.EliminarArista(G.GetVertice(origen), G.GetVertice(destino));
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 7:
        {
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
               G.Anular();
            }
            cin.get();
            cin.get();
            break;
        }
        case 8:
        {
            string nombre;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese el nombre del vertice inicial: ";
                cin.ignore();
                getline(cin, nombre, '\n');
                if(G.GetVertice(nombre) == NULL)
                {
                    cout<<"Ese vertice es invalido"<<endl;
                }
                else
                {
                    //G.RecorridoAnchura(G.GetVertice(nombre));
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 9:
        {
            string nombre;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese el nombre del vertice inicial: ";
                cin.ignore();
                getline(cin, nombre, '\n');
                if(G.GetVertice(nombre) == NULL)
                {
                    cout<<"Ese vertice es invalido"<<endl;
                }
                else
                {
                    //G.RecorridoProfundidad(G.GetVertice(nombre));
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 10:
        {
            string origen, destino;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese el nombre del vertice origen: ";
                cin.ignore();
                getline(cin, origen, '\n');
                cout<<"Ingrese el nombre del vertice destino: ";
                getline(cin, destino, '\n');
                if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                {
                    cout<<"Vertices invalidos"<<endl;
                }
                else
                {
                    //G.PrimeroAnchura(G.GetVertice(origen), G.GetVertice(destino));
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 11:
        {
            string origen, destino;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese el nombre del vertice origen: ";
                cin.ignore();
                getline(cin, origen, '\n');
                cout<<"Ingrese el nombre del vertice destino: ";
                getline(cin, destino, '\n');
                if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                {
                    cout<<"Vertices invalidos"<<endl;
                }
                else
                {
                    //G.PrimeroProfundidad(G.GetVertice(origen), G.GetVertice(destino));
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 12:
        {
            string origen, destino;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese el nombre del vertice origen: ";
                cin.ignore();
                getline(cin, origen, '\n');
                cout<<"Ingrese el nombre del vertice destino: ";
                getline(cin, destino, '\n');
                if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                {
                    cout<<"Vertices invalidos"<<endl;
                }
                else
                {
                    //G.PrimeroMejor(G.GetVertice(origen), G.GetVertice(destino));
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 13:
        {
            break;
        }
        default:
        {
            cout<<"Elija una opcion valida"<<endl;
        }
        }
    }
    while(opc != 13);
    return 0;
}
