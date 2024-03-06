#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
using namespace std; 
  
struct Node {
    int data;
    Node*next;
};

class SingleLinkedList{
    private:
        Node *head, *tail;
        int num_items;
    public:
        void linked_list(){
            head = NULL;
            tail = NULL;
        }

        void push_front(int n){
            Node *tmp = new Node;
            tmp -> data = n;
            tmp -> next = head;
            head = tmp;
        }
        void push_back(int n){
            cout << n << "\n";
            Node *tmp = new Node;
            tmp->data = n;
            tmp->next = NULL;
            cout << tmp->data << "\n";

            if(head == NULL){
                cout << "NULL\n";
                head = tmp;
                tail = tmp;
            }
            else{
                cout << "Not Null\n";
                tail->next = tmp;
                cout << "Worked\n";
                tail = tail->next;
            }
        }

        void pop_front(){
            if (head == NULL){
                cout << "Empty\n";
            }
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        void pop_back(){
            if(head == NULL){
                cout << "Empty\n";
            }
            if(head->next == NULL){
                delete head;
            }
            Node* second_last = head;
            while (second_last->next->next != NULL){
                second_last = second_last->next;
            }
            delete(second_last->next);
            second_last->next = NULL;

        }
        void front(){
            cout << head->data << "\n";
        }
        void back(){
            cout << tail->data << "\n";
        }
        void empty(){
            if(head == NULL){
                cout << "Empty\n";
            }
            else{
                cout << "Not empty\n";
            }
        }

        Node* getNode(int data)
        {
            // allocating space
            Node* newNode = new Node();
        
            // inserting the required data
            newNode->data = data;
            newNode->next = NULL;
            return newNode;
        }
        
        // function to insert a Node at required position
        void insertPos(Node** current, int pos, int data)
        {
            // This condition to check whether the
            // position given is valid or not.
            if (pos < 1 || pos > num_items + 1)
                cout << "Invalid position!" << endl;
            else {
        
                // Keep looping until the pos is zero
                while (pos--) {
        
                    if (pos == 0) {
        
                        // adding Node at required position
                        Node* temp = getNode(data);
        
                        // Making the new Node to point to 
                        // the old Node at the same position
                        temp->next = *current;
        
                        // Changing the pointer of the Node previous 
                        // to the old Node to point to the new Node
                        *current = temp;
                    }
                    else
                    // Assign double pointer variable to point to the 
                    // pointer pointing to the address of next Node 
                    current = &(*current)->next;
                }
                num_items++;
            }
        }
        bool delete_node(int position){
            if(head == NULL){
                return false;
            }
            Node* temp = head;
            if(position == 0){
                head = temp->next;
                free(temp);
                return true;
            }
            for(int i=0;temp != NULL && i< position - 1; i++){
                temp = temp->next;
            }
            if(temp == NULL || temp->next == NULL){
                return true;
            }
            Node* next = temp->next->next;
            free(temp->next);
            temp->next = next;
        }
    void find(int item){
        Node* temp = head;
        int index = 0;
        while(temp != NULL){
            index ++;
            if(temp->data == item){
                cout << index << "\n";
            }
        }
    }

};


int main(){
    SingleLinkedList list1;
    list1.push_back(1);
    // list1.empty();
    // list1.front();
    // list1.back();
    return 0;
}