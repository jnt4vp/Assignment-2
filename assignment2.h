Node.h
#ifndef NODE_H_
#define NODE_H_
struct Node {
    Item_Type data;
    Node* next;
    Node(const Item_Type& data_item, Node* next_ptr = NULL) :
        data(data_item), next(next_ptr) {}
};
#endif