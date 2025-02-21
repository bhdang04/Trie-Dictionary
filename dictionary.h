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

public:
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

    bool insert(char *text) {
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

        if (ptr->completeWord) {
            return false;
        } else {
            ptr->completeWord = true;
            return true;
        }

        return true;
    }

    bool search(char* text) {
        if (root == nullptr) {
            return false;
        }

        Node* ptr = root;

        for (int i = 0; i < strlen(text); i++) {
            if (ptr->children.find(text[i]) == ptr->children.end()) {
                cout << "Not Found\n";
                return false;
            } else {
                ptr = ptr->children[text[i]];
            }
        }

        return true;
    }

    bool remove(char* text) {
        if (root == nullptr) {
            return false;
        }

        Node* ptr = root;

        for (int i = 0; i < strlen(text); i++) {
            if (ptr->children.find(text[i]) == ptr->children.end()) {
                return false;
            } 
            ptr = ptr->children[text[i]];
        }

        if (ptr->completeWord) {
            remove_recurse(ptr, text, 0);
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

    void print_recurs(Node* node, char *prefix) {
        if (!node) {
            return;
        }

        if (node->completeWord) {
            cout << "WORD: " << prefix << endl;
        }

        for (auto& pair : node->children) {
            print_recurs(pair.second, prefix + pair.first);
        }
    }
    
    void print() {
        if (root == nullptr) {
            cout << "Trie is Empty.\n";
            return;
        }

        print_recurs(root, "");
    }
};


#endif