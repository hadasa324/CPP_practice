#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value){
        this->value = value;
        next =  nullptr;
    }
};

int get_count(Node *head);
Node * getTostartPoint(Node *head , int num_of_steps);

int get_count(Node *head){
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
    
}

Node * getTostartPoint(Node *head , int num_of_steps){
    Node *temp = head;

    for (size_t i = 0; i < num_of_steps; i++)
    {
        if (!temp)
        break;
        temp = temp->next;
        
    }
    return temp;
    
    
}

int insectionPoint(Node *head1 , Node *head2){
    int length1 = get_count(head1);
    int length2 = get_count(head2);
    Node *temp1 = head1;
    Node *temp2 = head2;

    if (length1 > length2)
        temp1 = getTostartPoint(head1 ,length1-length2);
    else
        temp2 = getTostartPoint(head2 ,length2-length1);

    while (temp1 && temp2)
    {
        if (temp1 == temp2)
            return temp1->value;

        temp1 = temp1->next;
        temp2 = temp2->next;
        
    }

    return -1;
    
    
}

void print_list(Node *head){
    Node *temp = head;
    while (temp)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
    
}

void deleteList(Node *head){
    Node *temp = head;
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    
}


int main (){

    Node *head1 = new Node(1);
    Node *temp = head1;
    Node *last1 = nullptr;
    

    for (size_t i = 2; i <= 4; i++)
    {
        Node *new_node = new Node(i);
        temp->next = new_node;
        temp = temp->next;
        last1 =temp;
    }
    
    
    Node *head2 = new Node(5);
    temp = head2;
    
    
    Node *new_node = new Node(30);
    last1->next = new_node;
    

    temp->next = new_node;
    temp = new_node;

    for (size_t i = 6; i <= 10; i++)
    {
        Node *new_node = new Node(i);
        temp->next = new_node;
        temp = temp->next;
    }

    print_list(head1);
    print_list(head2);
    cout <<insectionPoint(head1 , head2) <<" ";


}


