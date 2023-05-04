#include <iostream>

using namespace std;


class Node
{
public:
    int data;
    Node *next;
    Node(int value);
};

Node::Node(int value){
    this->data = value;
    next = nullptr;
}

bool HavingLoop(Node *first);

class LinckedList
{
private:
    Node *first;
    Node *last;
    int length;
public:
    LinckedList(){first = nullptr; last = nullptr; length=0;}
    LinckedList(int A [] , int n);
    ~LinckedList();
    Node * GetFirst();
    Node * GetLast();
    void Display();
    void Append(int value);
    void AddFirst(int value);
    void Insert(int index , int x);
    int DeleteFirst();
    int DeleteLast();
    int Delete(int index);
    void Reverse();
   
    
};

LinckedList::LinckedList(int A[], int n)
{
    Node *temp = new Node(A[0]);
    first = temp;
    last = temp;
    length = 1 ;
    
    for (size_t i = 1; i < n; i++)
    {
        temp = new Node(A[i]);
        last->next = temp;
        last = temp;
        length++;
    }
  

}

LinckedList::~LinckedList()
{
    Node *temp = first ;
    while(first){
        first = first->next;
        delete temp;
        temp = first;
    }
}

Node * LinckedList::GetFirst(){
    return first;
    
}
Node * LinckedList::GetLast(){
    return last;
    
}


void LinckedList::Display(){
  Node *temp = first;
  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }

  cout << endl;
  
}

void LinckedList::Append(int value){
    Node *new_node = new Node(value);
    if (length == 0)
    {
      first = new_node;
      last = new_node;
    }
    else {
        last->next = new_node;
        last = new_node;
    }
     length++;

}

void LinckedList::AddFirst(int value){
    Node *new_node = new Node(value);
    if(length == 0){
        first = new_node;
        last = new_node;
    }
    else{
        new_node->next = first;
        first = new_node;
    }
    length ++;
    

}

void LinckedList::Insert(int index , int value){
    if (index < 0 || (index) > (length+1))
    return;
    if (index == 0)
        AddFirst(value);
    else if(index == length || index == (length+1))
        Append(value);
    else{
        Node *new_node = new Node(value);
        Node *temp = first;
        for (size_t i = 1; i < index; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        length++;
    }

}

int LinckedList::DeleteFirst(){
    int deleted_value = 0;
    if (length == 0)
    return INT_MIN;
    Node *temp = first;
    if(length == 1){
       first = nullptr;
       last = nullptr;
    }
    else
        first = first->next;
    length --;
    deleted_value = temp->data;
    delete temp;
    return deleted_value;
}

int LinckedList::DeleteLast(){
    int deleted_value = 0;
    if (length == 0)
    return INT_MIN;
    Node *temp = first;
    if(length == 1){
       first = nullptr;
       last = nullptr;
    }
    else{
        for (size_t i = 1; i < (length-1); i++)
            temp = temp->next;
        last = temp;
        temp = temp->next;
        last->next = nullptr;
    }
    length --;
    deleted_value = temp->data;
    delete temp;
    return deleted_value;
}

int LinckedList::Delete(int index){
    if (index < 0 || index > length )
    return INT_MIN;
    if(index == 0)
        return DeleteFirst();
    if (index == (length-1))
        return DeleteLast();
    int deleted_value = 0;
    Node *temp = first;
    Node *pre = first;
    for (size_t i = 1; i <= index; i++){
        pre = temp;
        temp = temp->next;
    }
    pre->next = temp->next;
    deleted_value = temp->data;
    delete temp;
    length -- ;
    return deleted_value;
}

void LinckedList::Reverse(){
    if (length <=1)
    return;
    Node *before = nullptr;
    Node *temp = nullptr;
    Node *after = first;
    while (after)
    {
        before = temp;
        temp = after;
        after = after->next;
        temp->next = before;
    }

    temp = first;
    first = last;
    last =temp;
        
}



bool HavingLoop(Node *first){
   

    Node *slow = first;
    Node *fast = first;
    do
    {
       slow = slow->next;
       fast = fast->next;
       fast = fast?fast->next:fast;
    } while (slow && fast && fast!=slow);
    if (slow == fast)
        return true;
    return false;
    
    
}

void SortList(Node *node ,Node *sorted){
    if (!sorted || node->data <sorted->data)
    {
        node->next = sorted;
        sorted =node;
    }
    else{
        Node *current = sorted;
        while (current->next && current->data < node->data)
            current =  current->next;
        node->next = current->next;
        current->next = node;
    }
    
}

void InsertionSortLinckedList(Node *first){
    Node *sorted = nullptr;
    Node *current = first;
    while (current)    
    {
        Node *next = current->next;
        SortList(current , sorted);
        current = next;
    }
    first = sorted;
}

int main(){
    int A [] {1,2,3,4,5,6};
    LinckedList l1 (A ,6);
    l1.Display();
    // l1.Reverse();
    // l1.Display();
    Node *temp = l1.GetFirst();
    InsertionSortLinckedList(temp);
    l1.Display();

    Node *first = new Node(1);
    Node *s = new Node(2);
    Node *h = new Node(5);
    first->next = s;
    s->next = h;
    // h->next = first;   
    // cout << "should give 1: "<< HavingLoop(first) << endl;
    // cout << "should give 1: "<< HavingLoop(temp) << endl;
    // delete first ,s ,h;
}


