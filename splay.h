#ifndef __SPLAY_H__
#define __SPLAY_H__

#include <iostream>
#include <sstream>

class Node {
    
    private:
    std::string key;
    Node* left;
    Node* right;
    
    public:
    Node(std::string key)
    ~Node();
    
    friend class splayTree;
};

class splayTree {
    
    public:
    
        splayTree();
        ~splayTree();
        
        void insert(std::string)
        int height();

        bool search(std::string key)
    
    private:
    
        Node* root;
        
        Node* insert(std::string key, Node* root);
        
        int height(Node* root)
        void preorder(Node* root, std::cout)
        void delete(Node* key);
        bool search(std::string key, Node* root);
};

#endif
