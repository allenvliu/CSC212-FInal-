#include <iostream>
#include "splay.h"
#include <string>


Node::Node(int key){
    
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
}

Node* splayTree::insert(std::string key, Node* root){
    
    
    // if root is a nullptr, insert key into current node
    if(!root) {
        Node *temp = new Node(key);
        this->root = temp;
        return temp;
    }
 }
    

    if (key < root->key){

        // if node left of current node is not empty, continue down tree
        if(root->left != nullptr){
            
            // repeat using left node as current node
            this->insert(key, root->left)
        }
        
    } else{
        
        // if node is empty, insert key into node
        Node *temp = new Node(key);
        root->left = temp;
        return temp;
    }
    
    else{
        
        //greater, look for empty node to the right and continue down tree
        if(root->right != nullptr){
            
            //repeat with right node as the new curent node
            this->insert(key, root->right);
        }
        else{
            Node *temp = new Node(key);
            root->right = temp;
            return temp;
        }
    }
}


int splayTree::height(node* root) {
    
    // if root is a nullptr, decrease height by 1
    if (!root) {

        return -1;

    }

    int l_height = 0;
    int r_height = 0;

    l_height += this->height(root->left);
    r_height += this->height(root->right);

    return (1 + MAX(l_height, r_height));
}

void splayTree::Inorder(Node* root) {
    if (!root) {
        return NULL;
    }
    Inorder(root->left);
    std::cout << 
    Inorder(root->right);
}

Node* rotateRight{
    
    // creates temp variable that holds ptr to key (left of parent)
    node* k = parent->left;
    
    // node left of parent points to node right of key
    parent->left = k->right;
    
    // node right of key points to parent
    k-right-> = parent;
    
    // returns ptr of key
    return k;

}

Node* leftRotate(node *parent){
    //creates temp var holding ptr to key (right of parent)
    node* k = parent->right;
    
    //node right of parent points to node left of key
    parent->right = k->left;
    
    //node left of key points to parent
    k->left-> = parent;
    
    //returns ptr of key
    return k;
}


Node* Splay(std::string key, Node* root) {
    //if root is null or root is same as our key 
    if (root == NULL || root->key == key){
        return root;
    }
            // key is in left subtree
            if (key < root->key) {
                //if key is not in tree
                if (root->left == NULL){
                    return root;
                }
                //Left-left (Zag-zag)
                //key to the left of the root is greater than key being searched
                if (root->left->key > key) {
                    //two nodes under root to the left becomes the new root
                    root->left->left = splay(root->left->left, key);
                    //root is the zag-zag rotated tree. (if the grandparent of key is the root, base case is met and tree is done)
                    root = rotateRight(root);
                }
            //Left-right (Zag-zig)
            //key to left of root is less than key being searched, key resides to the right
            else if (root->left->key < key) {
                //key to the left, then right of root node becomes new root
                root->left->right = splay(root->left->right, key);
                //if there is a node to the right of the left of the root
                if (root->->right != NULL){
                //root is the zag-zig rotated tree.
                root->left = rotateLeft(root->left)
            }
            //if node to left of root is NULL return root (left node is direct child of root)
            if (root->left == NULL) {
                return root;
            }else {
                //Zig rotation 
                return rightRotate(root);
            }
        }
    }
        //key is in the right subtree
        else {
            //key is not in the tree
            if (root-> right == NULL){
                return root;
            }
            //Right-Right (Zig-Zig)
            //key of node to the right of root is less than key being searched
            if (root->right->key < key) {
                //node to the right to the right of the root becomes new root
                root->right->right = splay(right->right->right, key);
                //root becomes the left rotated tree
                root = rotateLeft(root)
            }
            //Right-Left (Zig-Zag)
            else if (root->right->key > key){
                //node to the left of the right of the root becomes new root
                root->right->left = splay(root->right->left, key);
                //first left rotation
                root = rotateLeft(root);
            }
            
            //if node to right of root is NULL return root (right node is direct child of root)
            if (root->right ==NULL){
                return root;
                //do a left rotation
            }else {
                return rotateLeft(root);
            }
    }
}

Node *search(Node *root, key)
{
    //if there is no root return nothing
    if(!root){
        return NULL;
    }
    //returns the new root of the tree
    //key is moved to root if it is present in the tree
    return splay(root, key);
}
