#include <iostream>

using namespace std;

class Node{
    public:
    int value;
    Node *next;
    Node *prev;
    Node(int value){
     this->value = value;
     next = nullptr;
     prev = nullptr;
    }
};


class DoublyLonkedList {
    Node *head;
    Node *tail;
    int length ;
    public:
    DoublyLonkedList(int value){
        Node *new_node = new Node(value);
        head = new_node;
        tail = new_node;
        length =1 ;

    }

    void print_list(){
        Node *temp = head;
        for (size_t i = 0; i < length; i++)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl ;
        
    }

    void append(int value){
        Node *new_node = new Node(value);
        if (length == 0)
        {
            head = new_node ;
            tail = new_node;
        }
        else{
           tail->next = new_node;
           new_node->prev = tail;
           tail = new_node;
        }
        length++;
        
    }

    void delete_last(){
        if (length == 0)
        return;
        Node *temp = tail;
        if(length == 1){
            head = nullptr;
            tail = nullptr;
        }
        else{
            tail = tail->prev;
            tail->next =nullptr;
        }
        delete temp;
        length--;
    }

    void prepend(int value){
        Node *new_node = new Node(value);
        if(length == 0){
            head = new_node;
            tail = new_node;
        }
        else{
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        length++;
    }
    void delete_first(){
        if (length == 0)
        return;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else{
            Node *temp  = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        length--;
        
        
    }

    Node * get(int index){
        if (index < 0 || index >= length)
            return nullptr;
        Node *temp =head;
        if(index < length/2){
            for (size_t i = 0; i < index; i++)
            {
                temp = temp->next;
            }
        }
        else{
            temp = tail;
            for (size_t i = (length-1) ; i > index; i--)
            {
                temp = temp->prev;
            }
        }
        return temp;
        
    } 

    bool set(int index , int value){
        Node *temp = get(index);
        if (temp)
        {
            temp->value = value;
            return true;
        }
        return false;
        
    }

    bool insert(int index , int value){
        if (index < 0 || index > length)
          return false;
        if (index == 0)
            prepend(value);

        else if (index == length)
            append(value);
        else{
            Node *new_node = new Node(value);
            Node *pre = get(index - 1);
            Node *post = pre->next;
            new_node->next = post;
            new_node->prev = pre;
            post->prev = new_node;
            pre->next = new_node;
            length++;
        }
        return true;
            
    }

    void delete_node(int index){
        if (index < 0 || index >= length)
          return;
        if (index == 0) return delete_first();
        if (index == (length-1)) return delete_last();
        Node *temp = get(index);
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        length--;
        
    }

};


int main(){
    DoublyLonkedList *myDDL = new DoublyLonkedList(7);
    myDDL->append(6);
    myDDL->print_list();
    myDDL->delete_last();
    myDDL->print_list();
    myDDL->prepend(0);
    myDDL->print_list();
    cout << myDDL->get(0)->value << endl;
    cout << myDDL->get(1)->value << endl;
    myDDL->print_list();
    myDDL->insert(0,8);
    myDDL->insert(1,9);
    myDDL->print_list();
    myDDL->delete_node(0);
    myDDL->print_list();

}