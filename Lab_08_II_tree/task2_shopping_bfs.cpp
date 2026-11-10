#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Node {
public:
    string category;
    Node* left;
    Node* right;

    Node(const string& categoryName) : category(categoryName), left(nullptr), right(nullptr) {}
};

void displayBfs(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> nodes;
    nodes.push(root);
    bool first = true;

    while (!nodes.empty()) {
        Node* current = nodes.front();
        nodes.pop();

        if (!first) {
            cout << " -> ";
        }
        cout << current->category;
        first = false;

        if (current->left) {
            nodes.push(current->left);
        }
        if (current->right) {
            nodes.push(current->right);
        }
    }
    cout << '\n';
}

int main() {
    Node* shoppingRoot = new Node("Electronics");
    shoppingRoot->left = new Node("Clothing");
    shoppingRoot->right = new Node("Mobiles");
    shoppingRoot->left->left = new Node("Men");
    shoppingRoot->left->right = new Node("Women");
    shoppingRoot->right->left = new Node("Laptops");
    shoppingRoot->right->right = new Node("Accessories");

    cout << "TASK 2: ONLINE SHOPPING CATEGORIES - BFS\n";
    cout << "BFS Order: ";
    displayBfs(shoppingRoot);
    return 0;
}
