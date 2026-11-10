#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(const string& memberName) : name(memberName), left(nullptr), right(nullptr) {}
};

void displayHierarchy(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->name << ": Left = "
         << (root->left ? root->left->name : "None")
         << ", Right = "
         << (root->right ? root->right->name : "None") << '\n';

    displayHierarchy(root->left);
    displayHierarchy(root->right);
}

int main() {
    Node* departmentRoot = new Node("HOD Dr. Ahmed");
    departmentRoot->left = new Node("Coordinator Dr. Fatima");
    departmentRoot->right = new Node("Coordinator Dr. Bilal");
    departmentRoot->left->left = new Node("Prof. Hassan");
    departmentRoot->left->right = new Node("Prof. Ayesha");
    departmentRoot->right->left = new Node("Prof. Usman");
    departmentRoot->right->right = new Node("Prof. Sara");

    cout << "TASK 1: UNIVERSITY DEPARTMENT HIERARCHY\n";
    displayHierarchy(departmentRoot);
    return 0;
}
