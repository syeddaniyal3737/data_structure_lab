#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int token;
    Node* left;
    Node* right;
    int height;

    Node(int appointmentToken)
        : token(appointmentToken), left(nullptr), right(nullptr), height(1) {}
};

int height(Node* node) {
    return node ? node->height : 0;
}

int balanceFactor(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

void updateHeight(Node* node) {
    node->height = 1 + max(height(node->left), height(node->right));
}

Node* rightRotate(Node* unbalanced) {
    Node* newRoot = unbalanced->left;
    Node* transferredSubtree = newRoot->right;

    newRoot->right = unbalanced;
    unbalanced->left = transferredSubtree;

    updateHeight(unbalanced);
    updateHeight(newRoot);
    return newRoot;
}

Node* leftRotate(Node* unbalanced) {
    Node* newRoot = unbalanced->right;
    Node* transferredSubtree = newRoot->left;

    newRoot->left = unbalanced;
    unbalanced->right = transferredSubtree;

    updateHeight(unbalanced);
    updateHeight(newRoot);
    return newRoot;
}

Node* insert(Node* root, int token) {
    if (root == nullptr) {
        return new Node(token);
    }

    if (token < root->token) {
        root->left = insert(root->left, token);
    } else if (token > root->token) {
        root->right = insert(root->right, token);
    } else {
        return root;
    }

    updateHeight(root);
    int balance = balanceFactor(root);

    if (balance > 1 && token < root->left->token) {
        return rightRotate(root);
    }
    if (balance < -1 && token > root->right->token) {
        return leftRotate(root);
    }
    if (balance > 1 && token > root->left->token) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && token < root->right->token) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void displayInorder(Node* root, vector<int>& result) {
    if (root) {
        displayInorder(root->left, result);
        result.push_back(root->token);
        displayInorder(root->right, result);
    }
}

void displayTree(Node* root, int level = 0, const string& position = "Root") {
    if (root == nullptr) {
        return;
    }

    cout << string(level * 4, ' ') << position << ": " << root->token
         << " (Height=" << root->height
         << ", Balance Factor=" << balanceFactor(root) << ")\n";
    displayTree(root->left, level + 1, "Left");
    displayTree(root->right, level + 1, "Right");
}

int main() {
    vector<int> tokens = {15, 25, 35, 45, 55, 65, 75};
    Node* avlRoot = nullptr;

    for (int token : tokens) {
        avlRoot = insert(avlRoot, token);
    }

    vector<int> inorderResult;
    displayInorder(avlRoot, inorderResult);

    cout << "TASK 4: HOSPITAL APPOINTMENT SYSTEM - AVL TREE\n";
    cout << "In-order Traversal: ";
    for (size_t i = 0; i < inorderResult.size(); ++i) {
        if (i > 0) {
            cout << " -> ";
        }
        cout << inorderResult[i];
    }
    cout << "\n\nFinal Balanced AVL Tree:\n";
    displayTree(avlRoot);
    return 0;
}
