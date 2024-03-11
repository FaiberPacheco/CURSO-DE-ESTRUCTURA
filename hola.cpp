#include <iostream>
using namespace std;

struct nodo{ 
    string nombre;
    int documento;
    nodo *sig;
};

nodo *cab = NULL, *aux = NULL;

int registrar(){
    aux = new nodo;
    cout << "Ingrese el nombre del paciente: ";
    cin >> aux->nombre;
    cout << "Ingrese el número de documento del paciente: ";
    cin >> aux->documento;
    aux->sig = NULL;
    
    if (cab == NULL){ 
        cab = aux;
    } else { 
        nodo *temp = cab;
        while (temp->sig != NULL) {
            temp = temp->sig;
        }
        temp->sig = aux;
    }
    
    return 0;
}

int mostrar(){ 
    int contador = 1;
    for (aux = cab; aux != NULL; aux = aux->sig){ 
        cout << contador << ". ";
        cout << "Nombre: " << aux->nombre << ", Documento: " << aux->documento << endl;
        contador++;
    }
    return 0;
}

int main(){
    int opc = 0;
    do{
        cout << "Menu" << endl;
        cout << "1. Registrar paciente" << endl;
        cout << "2. Ver pacientes registrados" << endl;
        cout << "3. Salir" << endl;
        cin >> opc;
        switch (opc)
        {
            case 1: registrar(); break;
            case 2: mostrar(); break;
            case 3: cout << "Good bye"; break;
            default: cout << "Opción incorrecta, intentelo de nuevo" << endl;
        }
    } while(opc != 3);
    
    // Liberar memoria al finalizar el programa
    aux = cab;
    while (aux != NULL) {
        nodo *temp = aux;
        aux = aux->sig;
        delete temp;
    }
    
    return 0;
}