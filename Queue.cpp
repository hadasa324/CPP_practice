#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value){
        this->value=value;
        next = nullptr;
       
    }
 
};


class  Queue
{
private:
    Node *first;
    Node *last;
    int length;
public:
     Queue(int value){
        Node *new_node = new Node(value);
        first = new_node;
        last = new_node;
        length =1 ;
     }

     void print_queue(){
        Node *temp = first;
        while (temp)
        {
           cout << temp->value << " ";
           temp = temp->next;
        }
        cout << endl;
        
     }

     void enqueue(int value){
        Node *new_node = new Node(value);
        if (length == 0 )
        {
            first =new_node;
            last = new_node;
        }
        else{
            last->next = new_node;
            last = new_node;
        }
        length++;
         
     }

     int dequeue(){
        if (length == 0) return INT_MIN;
        int first_item = first->value;
        if (length ==1){
            first =nullptr;
            last = nullptr ;
        }
        else{
            Node *temp = first;
            first = first->next;
            delete temp;
        }
        length--;
        return first_item;
        
     }


};

int main(){


    Queue *q = new Queue(5);
    q->print_queue();
    q->enqueue(4);
    q->print_queue();
    cout << q->dequeue() << endl;
    cout <<q->dequeue() << endl;
    q->print_queue();
}


