#include <iostream>
#include <string>
#include "lista.hpp"
#include <memory>
using namespace std;

shared_ptr<Node> create_node(int value){
    shared_ptr<Node> new_node = make_unique<Node>();
    new_node->data = value;
    return new_node;
}

shared_ptr<List> create_list(){
    shared_ptr<List> new_list = make_unique<List>();
    new_list->size = 0;
    return new_list;
}

size_t size(shared_ptr<List>& list){
    return list->size;
}

void push_front(shared_ptr<List>& list, int value){
    shared_ptr<Node> new_node = create_node(value);
    new_node->next = move(list->head);
    list->head = move(new_node);
    list->size++;
}

void push_back(shared_ptr<List>& list, int value){
    if (!size(list)){
        push_front(list,value);
        return;
    }
    shared_ptr<Node> temp = move(list->head);
    while (temp->next != nullptr){
        temp = move(temp->next);
    }
    shared_ptr<Node> new_node = create_node(value);
    temp->next = move(new_node);
    list->size++;
}
void insert (shared_ptr<List>& list, int value, int position){  
    if (position >= size(list)-1){
        push_back(list,value);
        }
    else if (position <= 0){
        push_front(list,value);
        }
    else{
        shared_ptr<Node> new_node = create_node(value);
        shared_ptr<Node> temp = move(list->head);
        for (int i = 0; i < position - 1; i++){
            temp = move(temp->next);
        }
        new_node->next = move(temp->next);
        temp->next = move(new_node);
    }
    list->size++;
    return;
}

void pop_front(shared_ptr<List>& list){
    if (size(list) == 0){
        return;
    }
    list->head = move(list->head->next);
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
    else{
        shared_ptr<Node> temp = move(list->head);
        for (int i = 0; i < position - 1; i++){
            temp = move(temp->next);
        }
        temp->next = move(temp->next->next);
        }
    list->size--;
    return;
}

void print_list(shared_ptr<List>& list){
    shared_ptr<Node> temp = move(list->head);
    while (temp != nullptr){
        cout << temp->data;
        if (temp->next != nullptr){
            cout << " -> ";
        }
        temp = move(temp->next);
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