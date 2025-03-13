#include <iostream>
#include <string>
#include "lista.hpp"
#include <memory>
using namespace std;

shared_ptr<Node> create_node(int value){
    shared_ptr<Node> new_node = make_shared<Node>();
    new_node->data = value;
    return new_node;
}

shared_ptr<List> create_list(){
    shared_ptr<List> new_list = make_shared<List>();
    new_list->size = 0;
    return new_list;
}

size_t size(shared_ptr<List>& list){
    return list->size;
}

void push_front(shared_ptr<List>& list, int value){
    shared_ptr<Node> new_node = create_node(value);
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void push_back(shared_ptr<List>& list, int value){
    if (!size(list)){
        push_front(list,value);
        return;
    }
    shared_ptr<Node> temp = list->head;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    shared_ptr<Node> new_node = create_node(value);
    temp->next = new_node;
    list->size++;
}
void insert (shared_ptr<List>& list, int value, int position){  
    if (position >= size(list)){
        push_back(list,value);
        }
    else if (position <= 0){
        push_front(list,value);
        }
    else{
        shared_ptr<Node> new_node = create_node(value);
        shared_ptr<Node> temp = list->head;
        for (int i = 0; i < position - 1; i++){
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    list->size++;
    return;
}

void pop_front(shared_ptr<List>& list){
    if (size(list) == 0){
        return;
    }
    list->head = list->head->next;
    list->size--;
    return;
}

void erase(shared_ptr<List>& list, int position){
    if (size(list) == 0){
        return;
    }
    if (position == 0){
        pop_front(list);
    }
    if (position >= size(list)){
        position = size(list) - 1;
    }
    else{
        shared_ptr<Node> temp = list->head;
        for (int i = 0; i < position - 1; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        }
    list->size--;
    return;
}

void print_list(shared_ptr<List>& list){
    cout<<"Lista: ";
    shared_ptr<Node> temp = list->head;
    while (temp != nullptr){
        cout << temp->data;
        if (temp->next != nullptr){
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
    return;
}

void clear_list(shared_ptr<List>& list){
    while (size(list) != 0){
        pop_front(list);
    }
    return;
}

void correr_lista(){
    int Decision = 0;
    shared_ptr<List> Lista = create_list();
    while (Decision != 9){
        cout<< "Que desea hacer con la lista" << endl;
        cout<< "Insertar al inicio [1]" << endl;
        cout<< "Insertar al final [2]" << endl;
        cout<< "Insertar en una posicion deseada [3]" << endl;
        cout<< "Eliminar el primer elemento [4]" << endl;
        cout<< "Eliminar un elemento en una posicion deseada [5]" << endl;
        cout<< "Imprimir la lista [6]" << endl;
        cout<< "Imprimir el tamaño de la lista [7]" << endl;
        cout<< "Crear una nueva lista [8]" << endl;
        cout<< "Salir [9]" << endl;
        cin >> Decision;
        switch (Decision){
            case 1:{
                int Numero;
                cout << "Ingrese el numero que desea insertar: ";
                cin >> Numero;
                push_front(Lista, Numero);
                break;
            }
            case 2:{
                int Numero;
                cout << "Ingrese el numero que desea insertar: ";
                cin >> Numero;
                push_back(Lista, Numero);
                break;
            }
            case 3:{
                int Numero;
                cout << "Ingrese el numero que desea insertar: ";
                cin >> Numero;
                int Posicion;
                cout << "Ingrese la posicion en la que desea insertar: ";
                cin >> Posicion;
                insert(Lista, Numero, Posicion);
                break;
            }
            case 4:{
                pop_front(Lista);
                break;
            }
            case 5:{
                int Posicion;
                cout << "Ingrese la posicion que desea eliminar: ";
                cin >> Posicion;
                erase(Lista, Posicion);
                break;
            }
            case 6:{
                print_list(Lista);
                break;
            }
            case 7:{
                cout << "El tamaño de la lista es: " << size(Lista) << endl;
                break;
            }
            case 8:{
                if (size(Lista) != 0){
                    clear_list(Lista);
                }
                break;
            }
            case 9:{
                return;
                break;
            }
            default:{
                cout << "Ingrese un valor valido" << endl;
                break;
            }
        }
    }
    return;
}