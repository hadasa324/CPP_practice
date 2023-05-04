#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value){
        this->value = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *top;
    int height;
public:
    Stack(int value){
    Node *new_node = new Node(value);
    top = new_node;
    height = 1;
    }

    void print_stack(){
        Node *temp = top;
        while (temp)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void get_top(){
        cout << "Top: "<< top->value << endl;
    }

    void get_height(){
        cout << "Height: " << height << endl;
    }

    void push(int value){
        Node *new_node = new Node(value);
        new_node->next = top;
        top = new_node;
        height ++;
    }

    int pop(){
        if(height == 0)
        return INT_MIN;
        Node *temp = top;
        int pop_value = top->value;
        top = top->next;
        delete temp;
        height-- ;
        return pop_value;
    }

};





int main(){

    Stack *s = new Stack(8);
    s->get_height();
    s->get_top();
    s->print_stack();
    s->push(5);
    s->print_stack();
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << s->pop() << endl;

};