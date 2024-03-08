#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
using namespace std; 
  
struct Node {
    int data;
    Node* next;
};

class SingleLinkedList{
    private:
        Node* head;
        Node* tail;
        int num_items;
    public:
        SingleLinkedList() : head(nullptr), tail(nullptr), num_items(0){

        }

        void push_front(int n);
        //Pushes a new node to the front of the list
        void push_back(int n);
        //Pushes a new node to the end of the list
        void pop_front();
        //Deletes the front node
        void pop_back();
        //Deletes the back node
        void front();
        //Prints out the front node data value
        void back();
        //Prints out the back node data value
        void empty();
        //Tells the user whether the list is empty
        Node* getNode;
        //Creates a new node
        void insertPos(Node** current, int pos, int data);
        //Inserts new node at a specific position
        bool delete_node(int position);
        //Deletes node at a specific position
        void find(int item);
        //Finds node with data value specified
};