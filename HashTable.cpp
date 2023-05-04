#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Node
{

public:
    string key;
    int value;
    Node *next;
    Node(string key , int value){
        this->key = key;
        this->value = value;
        next = nullptr;
    }


};


class HashTable
{
private:
    static const int SIZE = 7;
    Node *data_map[SIZE];
public:
   

   void print_table(){
    for (size_t i = 0; i < SIZE; i++)
    {
        cout << i << ": " ;
        if(data_map[i]){
            Node *temp = data_map[i];
            while (temp)
            {
                cout <<"key: " << temp->key << "value: " <<temp->value ;
                temp = temp->next;
            }
            
        }
         cout << endl;
    }
    cout <<endl;
    
   }


   int hash(string key){
    int hash =0 ;
    for (size_t i = 0; i < key.length(); i++)
    {
        int ascii_vale = int(key[i]);
        hash = (hash + ascii_vale*23)% SIZE;
    }
    return hash;
   }

   void set(string key , int value){
    int index = hash(key);
    Node *new_node = new Node(key , value);
    if (!data_map[index])
       data_map[index] = new_node;
    else{
        Node *temp = data_map[index];
        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = new_node;
        
    }
    
   }

   int get(string key){
    int index = hash(key);
    Node *temp = data_map[index];
     while (temp)
        {
            if (temp->key == key) return temp->value;
            temp = temp->next;
        }

        return INT_MIN;
    }

    vector<string> keys(){
        vector <string> all_keys;
        for (size_t i = 0; i < SIZE; i++)
        {
             Node *temp =data_map[i];
            while (temp)
            {
                all_keys.push_back(temp->key);
                temp = temp->next;
            }
            
        }
        return all_keys;

    }

   
};

bool item_incommon(vector <int>  vect1 , vector <int> vect2){
    unordered_map<int , bool> my_map;
    for (auto i : vect1)
    {
        my_map.insert({i ,true});
    }
    for (auto j : vect2)
        if (my_map[j]) return true;
        
    return false;
    
}

int main(){

    HashTable *ht = new HashTable();
    ht->print_table();
    ht->set("bbb" , 1);
    ht->set("kjbkjh" , 5);
    ht->print_table();
    cout << "should return 1: " << ht->get("bbb") << endl;
    cout << "should return " << INT_MIN <<": " << ht->get("jknhki") << endl;

    vector<string> keys = ht->keys();
    for(auto k : keys )
      cout << k << " ";
    cout << endl;

    delete ht;

    vector <int>  v1{1,2,3};
    vector <int>  v2{5,5,5};

    cout << item_incommon(v1 , v2) << endl;
}

