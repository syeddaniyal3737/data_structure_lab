#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string folder;
    Node* left;
    Node* right;

    Node(const string& folderName) : folder(folderName), left(nullptr), right(nullptr) {}
};

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->folder << " -> ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root) {
        cout << root->folder << " -> ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->folder << " -> ";
    }
}

void printTraversal(void (*traversal)(Node*), Node* root) {
    traversal(root);
    cout << "END\n";
}

int main() {
    Node* fileRoot = new Node("Computer");
    fileRoot->left = new Node("Documents");
    fileRoot->right = new Node("Downloads");
    fileRoot->left->left = new Node("Assignments");
    fileRoot->left->right = new Node("Projects");
    fileRoot->right->left = new Node("Images");
    fileRoot->right->right = new Node("Videos");

    cout << "TASK 3: COMPUTER FILE EXPLORER - DFS\n";
    cout << "In-order   : ";
    printTraversal(inorder, fileRoot);
    cout << "Pre-order  : ";
    printTraversal(preorder, fileRoot);
    cout << "Post-order : ";
    printTraversal(postorder, fileRoot);
    return 0;
}
