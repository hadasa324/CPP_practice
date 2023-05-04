#include <iostream>

using namespace std;


class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int value){
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
public:
    Node *root;
    BinaryTree(){
        root = nullptr;
    }

    void destroy(Node* currentNode) {
            if (currentNode->left) destroy(currentNode->left);
            if (currentNode->right) destroy(currentNode->right);
            delete currentNode;
        }

    ~BinaryTree() { destroy(root); }

    bool insert(int value){
        Node *new_node = new Node(value);
        if (root == nullptr){
            root =new_node;
            return true;
        }
        Node *temp = root;
        while (true)
        {
            if(new_node->value == temp->value) return false;
            if (new_node->value < temp->value){
                if (temp->left == nullptr)
                {
                    temp->left = new_node;
                    return true;
                }
                temp= temp->left;
            }
            else{
                if (temp->right == nullptr)
                {
                    temp->right = new_node;
                    return true;
                }
                temp= temp->right;
            }
            
        }
       
        
    }


    bool contains(int value) {
            if (root == nullptr) return false;
            Node* temp = root;
            while (temp) {
                if (value < temp->value) {
                    temp = temp->left;
                } else if (value > temp->value) {
                    temp = temp->right;
                } else {
                    return true;
                }
            }
            return false;
        }
    


    
};


int main(){
    BinaryTree *bt = new BinaryTree();
     bt->insert(47) ;
     bt->insert(21) ;
     bt->insert(76) ;
     bt->insert(18) ;
     bt->insert(52) ;
     bt->insert(82) ;
     bt->insert(27) ;
    cout << "27: " << endl;
    cout <<bt->root->left->right->value << endl ;
    cout << " should be 1 ,Contatins 21: " <<bt->contains(21) << endl;
    cout << "should be 0 ,Contatins 0: " <<bt->contains(0) << endl;

    delete bt ;
};

