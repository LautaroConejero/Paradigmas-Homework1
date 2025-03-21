#include "lista.hpp"

// Función para crear un nodo con un valor dado
shared_ptr<Node> create_node(int value) {
    shared_ptr<Node> new_node = make_shared<Node>(); 
    new_node->data = value; 
    return new_node; 
}

// Función para crear una lista vacía
shared_ptr<List> create_list() {
    shared_ptr<List> new_list = make_shared<List>(); 
    new_list->size = 0; 
    return new_list; 
}

// Función para obtener el tamaño de la lista
size_t size(shared_ptr<List>& list) {
    return list->size; 
}

// Función para insertar un valor al inicio de la lista
void push_front(shared_ptr<List>& list, int value) {
    shared_ptr<Node> new_node = create_node(value); 
    new_node->next = list->head; // Apuntar el nuevo nodo al primer nodo actual
    list->head = new_node; // Actualizar la cabeza de la lista al nuevo nodo
    list->size++; // Incrementar el tamaño de la lista
    cout << "Se ha insertado el elemento al inicio" << endl;
}

// Función para insertar un valor al final de la lista
void push_back(shared_ptr<List>& list, int value) {
    if (!size(list)) { // considero si la lista este vacia, asi reutilizo el codigo de push_front
        push_front(list, value); 
        return;
    }
    shared_ptr<Node> temp = list->head; // creo un iterador
    while (temp->next != nullptr) { // Recorrer hasta el último nodo
        temp = temp->next;
    }
    shared_ptr<Node> new_node = create_node(value); 
    temp->next = new_node; // Apuntar el último nodo al nuevo nodo
    list->size++; 
    cout << "Se ha insertado el elemento al final" << endl;
}

// Función para insertar un valor en una posición específica de la lista
void insert(shared_ptr<List>& list, int value, int position) {
    if (position >= size(list)) { // Si la posición es mayor o igual al tamaño de la lista lo inserto al final y doy mensaje de aviso
        push_back(list, value); 
        cout << "Ingresaste una posicion que no existe, se inserto al final" << endl;
        return;
    }
    else if (position <= 0) { // Si la posición es menor o igual a 0 lo inserto al principio y doy un mensaje de aviso
        push_front(list, value); 
        if (position < 0) cout << "Ingresaste una posicion que no existe, se inserto al inicio" << endl;
        return;
    } else {
        shared_ptr<Node> new_node = create_node(value); 
        shared_ptr<Node> temp = list->head; // iterador
        for (int i = 0; i < position - 1; i++) { // Recorrer hasta la posición anterior
            temp = temp->next;
        }
        new_node->next = temp->next; // Apuntar el nuevo nodo al siguiente nodo
        temp->next = new_node; // Apuntar el nodo anterior al nuevo nodo
        list->size++; 
    cout << "Se ha insertado el elemento en la posicion " << position << endl;
    return;
    }
}

// Función para eliminar el primer elemento de la lista
void pop_front(shared_ptr<List>& list) {
    if (size(list) == 0) { // Si la lista está vacía, doy un mensaje de aviso
        cout << "La lista esta vacia" << endl;
        return;
    }
    list->head = list->head->next; // Apuntar la cabeza al segundo nodo
    list->size--; 
    cout << "Se ha eliminado el primer elemento" << endl;
    return;
}

// Función para eliminar un elemento en una posición específica de la lista
void erase(shared_ptr<List>& list, int position) {
    if (size(list) == 0) { // idem que en pop_front
        cout << "La lista esta vacia" << endl;
        return;
    } else if (position == 0) { // Si la posición es 0, elimino el primer elemento
        pop_front(list); 
        return;
    }
    if (position >= size(list)) { // Si la posición es mayor o igual al tamaño de la lista
        position = size(list) - 1; // Eliminar el último elemento, pero doy mensaje de aviso
        cout << "Ingresaste una posicion que no existe, por lo tanto:"<< endl;
    }
    shared_ptr<Node> temp = list->head; // interador
    for (int i = 0; i < position - 1; i++) { // Recorrer hasta la posición anterior
        temp = temp->next;
    }
    temp->next = temp->next->next; // Apuntar el nodo anterior al siguiente nodo
    list->size--; 
    cout << "Se ha eliminado el elemento en la posicion " << position << endl;
    return;
}

// Función para imprimir la lista
void print_list(shared_ptr<List>& list) {
    cout << "Lista: ";
    shared_ptr<Node> temp = list->head; // iterador
    while (temp != nullptr) { // Recorrer la lista
        cout << temp->data; // Imprimir el valor del nodo
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next; 
    }
    cout << endl;
    return;
}

// Función para eliminar todos los elementos de la lista
void clear_list(shared_ptr<List>& list) {
    while (size(list) != 0) { // Mientras la lista no esté vacía
        pop_front(list); // Eliminar el primer elemento
    }
    cout << "La lista ha sido eliminada" << endl;
    return;
}

// Función principal para correr el programa de listas
void correr_lista() {
    int Decision = 0;
    shared_ptr<List> Lista = create_list(); // Crear una nueva lista
    while (Decision != 9) { // Mientras la decisión no sea salir
        cout << "Insertar al inicio [1]" << endl;
        cout << "Insertar al final [2]" << endl;
        cout << "Insertar en una posicion deseada [3]" << endl;
        cout << "Eliminar el primer elemento [4]" << endl;
        cout << "Eliminar un elemento en una posicion deseada [5]" << endl;
        cout << "Imprimir la lista [6]" << endl;
        cout << "Imprimir el tamaño de la lista [7]" << endl;
        cout << "Crear una nueva lista [8]" << endl;
        cout << "Salir [9]" << endl;
        cout << "Que desea hacer con la lista: ";
        cin >> Decision;
        switch (Decision) {
            case 1: {
                int Numero;
                cout << "Ingrese el numero que desea insertar: ";
                cin >> Numero;
                push_front(Lista, Numero);
                cout << endl;
                break;
            }
            case 2: {
                int Numero;
                cout << "Ingrese el numero que desea insertar: ";
                cin >> Numero;
                push_back(Lista, Numero); 
                cout << endl;
                break;
            }
            case 3: {
                int Numero;
                cout << "Ingrese el numero que desea insertar: ";
                cin >> Numero;
                int Posicion;
                cout << "Ingrese la posicion en la que desea insertar: ";
                cin >> Posicion;
                while (Posicion < 0) {
                    cout << "Ingrese una posicion valida: ";
                    cin >> Posicion;
                }
                insert(Lista, Numero, Posicion); 
                cout << endl;
                break;
            }
            case 4: {
                pop_front(Lista);
                cout << endl;
                break;
            }
            case 5: {
                int Posicion;
                cout << "Ingrese la posicion que desea eliminar: ";
                cin >> Posicion;
                erase(Lista, Posicion); 
                cout << endl;
                break;
            }
            case 6: {
                print_list(Lista); 
                cout << endl;
                break;
            }
            case 7: {
                cout << "El tamaño de la lista es: " << size(Lista) << endl; 
                cout << endl;
                break;
            }
            case 8: {
                if (size(Lista) != 0) {
                    clear_list(Lista); 
                }
                cout << "Se ha creado una nueva lista" << endl;
                cout << endl;
                break;
            }
            case 9: {
                return; 
                break;
            }
            default: {
                cout << "Ingrese un valor valido" << endl;
                cout << endl;
                break;
            }
        }
    }
    return;
}