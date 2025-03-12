#include <iostream>
#include <string>
#include <memory>
using namespace std;

struct Node{
    int data;
    shared_ptr<Node> next;
};
struct List{
    shared_ptr<Node> head;
    size_t size;
};

shared_ptr<Node> create_node(int value);
shared_ptr<List> create_list();
void push_front(shared_ptr<List>& list, int value);
void push_back(shared_ptr<List>& list, int value);
void insert(shared_ptr<List>& list, int value, int position);
void pop_front(shared_ptr<List>& list);
void erase(shared_ptr<List>& list, int position);
void print_list(shared_ptr<List>& list);
void clear_list(shared_ptr<List>& list);
size_t size(shared_ptr<List>& list);