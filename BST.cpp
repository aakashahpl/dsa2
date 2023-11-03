#include<iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    // Constructor
    Node(int k) {
        key = k;
        left = right = NULL;
    }
};

class BinarySearchTree {
    Node* root;

public:
    // Constructor
    BinarySearchTree() {
        root = NULL;
    }

    // In-order traversal of the tree
    void inorder(Node* root) {
        if(root != NULL) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }

    // Function to insert a new node in the BST
    Node* insert(Node* root, int key) {
        if(root == NULL) {
            return new Node(key);
        }

        if(key < root->key) {
            root->left = insert(root->left, key);
        } else if(key > root->key) {
            root->right = insert(root->right, key);
        }
        return root;
    }

    // Function to search a key in the BST
    Node* search(Node* root, int key) {
        if(root == NULL || root->key == key) {
            return root;
        }
        
        if(root->key < key) {
            return search(root->right, key);
        }
        return search(root->left, key);
    }

    // Function to delete a node from the BST
    Node* deleteNode(Node* root, int key) {
        if(root == NULL) {
            return root;
        }

        if(key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if(key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            if(root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if(root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* temp = root->right;
                while(temp && temp->left != NULL) {
                    temp = temp->left;
                }
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }
        return root;
    }

    // Wrapper function to insert a new node in the BST
    void insert(int key) {
        root = insert(root, key);
    }

    // Wrapper function to search a key in the BST
    Node* search(int key) {
        return search(root, key);
    }

    // Wrapper function to delete a node from the BST
    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    // Wrapper function for in-order traversal of the tree
    void inorder() {
        inorder(root);
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(15);
    bst.insert(70);
    bst.insert(60);

    cout << "Original BST: ";
    bst.inorder();
    cout << endl;

    int key = 20;
    Node* result = bst.search(key);
    if(result != NULL) {
        cout << key << " found" << endl;
    } else {
        cout << key << " not found" << endl;
    }

    cout << "Delete node 30:" << endl;
    bst.deleteNode(30);
    bst.inorder();

    return 0;
}
