#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <string>

using namespace std;
const int NUM_CHARS = 256;

struct Node {
    unordered_map<char, Node*> children;
    bool completeWord;    
};

class Dictionary {
private:
    Node* root;

    Dictionary() {
        root = new Node;
        root->children.clear();
        root->completeWord = false;
    }

    ~Dictionary() {
        deleteNode(root);
    }

    void deleteNode(Node* node) {
        if (node == nullptr) {
            return;
        }

        for (auto& child : node->children) {
            deleteNode(child.second);
        }

        delete node;
    }

    bool insert(Node *root, char *text) {
        if (root == nullptr) {
            root = new Node;
        }
        
        Node* ptr = root;

        for (int i = 0; i < strlen(text); i++) {
            if (ptr->children.find(text[i]) == ptr->children.end()) {
                ptr->children[text[i]] = new Node; 
            }
            ptr = ptr->children[text[i]];
        }

        if (ptr->completeWord == false) {
            return false;
        } else {
            ptr->completeWord = true;
            return true;
        }

        return true;
    }

    void search() {

    }

    bool remove(Node* root, char* text) {
        if (root == nullptr) {
            return false;
        }

        Node* ptr = root;

        for (int i = 0; i < strlen(text); i++) {
            if (ptr->children.find(text[i]) != ptr->children.end()) {
                return false;
            } 
            ptr = ptr->children[text[i]];
        }

        if (ptr->completeWord) {
            remove_recurse(root, text, 0);
            return true;
        }

        return false;
    }

    void remove_recurse(Node* node, char* text, int index) {
        if (node == nullptr) {
            return;
        }

        if (text[index] == '\0') {
            node->completeWord = false;

            if (node->children.empty()) {
                delete node;
            }

            return;
        }

        char currentChar = text[index];

        if (node->children.find(currentChar) != node->children.end()) {
            remove_recurse(node->children[currentChar], text, index + 1);

            Node* childNode = node->children[currentChar];

            if (childNode->children.empty() && !childNode->completeWord) {
                delete childNode;
                node->children.erase(currentChar);
            }
        }
    }

    void print_recurs(Node* node, char *prefix, int length) {
        char newpre[length+2];
        memcpy(newpre, prefix, length); 
        newpre[length+1] = 0;

        if (node->completeWord == true) {
            cout << "WORD: " << prefix << endl;
        }

        for (int i = 0; i < NUM_CHARS; i++) {
            if (node->children[i] != NULL) {
                newpre[length] = i;
                print_recurs(node->children[i], newpre, length+i);
            }
        }
    }
    
    void print(Node* root) {
        if (root == nullptr) {
            cout << "Trie is Empty.\n";
            return;
        }

        print_recurs(root, NULL, 0);
    }
};


#endif