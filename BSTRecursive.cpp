#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}
bool recursiveSearch(Node* root, int key) {
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return recursiveSearch(root->left, key);
    else
        return recursiveSearch(root->right, key);
}
int main() {
    Node* root = NULL;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter nodes: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    if (recursiveSearch(root, key))
        cout << " After Recursive Searching: Element found\n";
    else
        cout << "After Recursive Searching: Not found\n";


    return 0;
}
