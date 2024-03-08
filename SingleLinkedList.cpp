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

        void push_front(int n){
            //creates a new temporary node
            Node *tmp = new Node;
            tmp -> data = n;
            tmp -> next = head;
            head = tmp;
            num_items ++;
        }
        void push_back(int n){
            //creates a new temporary node
            Node *tmp = new Node;
            tmp->data = n;
            tmp->next = NULL;

            if(head == nullptr){
                //checks to see if list is empty
                head = tmp;
                tail = tmp;
            }
            else{
                //if the list isnt empty it pushes the new node to the back
                tail->next = tmp;
                tail = tail->next;
            }
            num_items++;
        }

        void pop_front(){
            //checks to see if the list is empty
            if (head == NULL){
                cout << "Empty\n";
            }
            Node* temp = head;
            head = head->next;
            delete temp;
            num_items --;
        }

        void pop_back(){
            //checks to see if list is empty and prints this to the user
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
            num_items --;
        }
        void front(){
            //prints data value of front
            cout << head->data << "\n";
        }
        void back(){
            //prints data value of tail
            cout << tail->data << "\n";
        }
        void empty(){
            //tells user that the list is empty or not empty
            if(head == NULL){
                cout << "Empty\n";
            }
            else{
                cout << "Not empty\n";
            }
        }

        Node* getNode(int data)
        {
            Node* newNode = new Node();
        
            newNode->data = data;
            newNode->next = NULL;
            return newNode;
        }
        
        void insertPos(Node** current, int pos, int data)
        {
            if (pos < 1 || pos > num_items + 1)
                cout << "Invalid position!" << endl;
            else {
                while (pos--) {
        
                    if (pos == 0) {
        
                        Node* temp = getNode(data);
        
                        temp->next = *current;
        
                        *current = temp;
                    }
                    else
                    current = &(*current)->next;
                }
                num_items++;
            }
        }
        bool delete_node(int position){
            //checks to see if the list is empty
            if(head == NULL){
                return false;
            }
            Node* temp = head;
            //checks to see if there is only one value in the list
            if(position == 0){
                head = temp->next;
                free(temp);
                num_items --;
                return true;
            }
            for(int i=0;temp != NULL && i< position - 1; i++){
                temp = temp->next;
            }
            if(temp == NULL || temp->next == NULL){
                num_items --;
                return true;
            }
            Node* next = temp->next->next;
            free(temp->next);
            temp->next = next;
        }
    void find(int item){
        Node* temp = head;
        int index = 0;
        //iterates through linked list to find the value
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
    list1.push_front(2);
    list1.empty();
    list1.front();
    list1.back();
    return 0;
}