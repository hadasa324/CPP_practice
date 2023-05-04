#include <iostream>
using namespace std;

class Node
{
    public:
        int value;
        Node* next;
        Node(int value){
            this->value = value;
            next =nullptr;
        }


};

class Linked_List
{
private:
    Node* head ;
    Node* tail;
    int length;
public:
    Linked_List(int value){
        Node* new_node = new Node(value);
        head = new_node;
        tail = new_node;
        length = 1;
    }
    ~Linked_List(){
        Node *temp = head ;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
        
    }

    void print_list(){
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << " " ;
            temp = temp->next;
        }
        cout << endl ;
        
    }

    void get_head(){
        cout << "Head: "<< head->value << endl;
    }
    
    void get_tail(){
        cout << "Tail: "<< tail->value << endl;
    }

    void get_length(){
        cout << "Length: "<< length << endl;
    }

    void append(int value){
        Node *new_node = new Node(value);
        if (length == 0 ){
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        length++;
        
    }

    void delete_last(){
        if (length == 0)
           return;
        if(length == 1 ){
            head = nullptr;
            tail = nullptr;
        }
        else{
        Node *pre = head ;
        Node *temp = head;
        while (temp->next)
        {
            pre = temp;
            temp = temp->next;
        }

        tail = pre;
        tail->next = nullptr ;
        length--;
        
        delete temp;

    }
        
    }

    void prepend(int value){
        Node *new_node = new Node(value);
        if (length == 0)
        {
            head =new_node;
            tail= new_node;
        }
        else{
            new_node->next= head;
            head = new_node ;
        }
        length ++;
        
    }

    void delete_first(){
        if (length == 0) return;
        Node *temp = head;
        if (length == 1){
            head = nullptr;
            tail = nullptr;
        }
        else
            head = head->next;
        delete temp ;
        length --;
        
    }

    Node* get(int index){
        if(index < 0 || index >= length)
           return nullptr;
        Node *temp = head ;
        for (size_t i=0; i<index ; ++i){
            temp = temp->next;
        }

        return temp;
    }

    bool set(int index , int value){
        Node *temp = get(index);
        if(temp){
        temp->value = value;
        return true;
        }
        return false;
    }

    bool insert(int index , int value){
        if (index < 0 || index > length)
        return false;
        if (index == 0){
        prepend(value);
        return true;
        }
        if (index == length)
        {
         append(value);
         return true;
        }
        
        Node *new_node = new Node(value);
        Node *pre = get(index-1);
        Node *temp = get(index);
        new_node->next = temp;
        pre->next = new_node;
        return true;
    }

     void delete_node(int index){
        if (index < 0 || index > length)
        return;
        if (index == 0){
        return delete_first();
        }
        if (index == length)
        {
        return delete_last();
        }
        Node *pre = get(index-1);
        Node *temp = pre->next;
        pre->next = temp->next;
        delete temp;
        length--;

    }

    void reverse(){
        Node *temp = head ;
        head = tail ;
        tail = temp ;
        Node * after  = temp->next;
        Node *before = nullptr;
        for (size_t i = 0; i < length; i++)
        {   after = temp->next;
            temp->next = before;
            before = temp ;
            temp = after;

        }
        
        
    }


};

int main(){

    Linked_List *myLinkedList =  new Linked_List(4);
    // myLinkedList->get_head();
    // myLinkedList->get_length();
    // myLinkedList->get_tail();
    // myLinkedList->print_list();
    myLinkedList->append(2);
    myLinkedList->print_list();
    myLinkedList->delete_last();
    myLinkedList->print_list();
    myLinkedList->prepend(1);
    myLinkedList->print_list();
    myLinkedList->append(2);
    myLinkedList->append(2);
    myLinkedList->print_list();
    myLinkedList->set(2,8);
    // myLinkedList->delete_first();
    // myLinkedList->print_list();
    // myLinkedList->delete_first();
    // myLinkedList->delete_first();
    myLinkedList->print_list();
    cout << myLinkedList->get(2)->value << endl;
    myLinkedList->insert(0,9);
    myLinkedList->print_list();
    myLinkedList->delete_node(1);
    myLinkedList->print_list();
    myLinkedList->reverse();
    myLinkedList->print_list();



   delete myLinkedList;
}




