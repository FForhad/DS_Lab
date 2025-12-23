#include<stdio.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


///Create a new node and recursively place it based on value comparison with the current node.
struct Node* insert(struct Node* node, int value) {
    if (node == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    return node;
}


///Traverse from root, moving left if target is smaller or right if larger, until found or NULL.
struct Node* search(struct Node* root, int target) {
    if (root == NULL || root->data == target)
        return root;
    if (target < root->data)
        return search(root->left, target);
    return search(root->right, target);
}

/**Handle three cases: leaf node (free it), one child (replace with child),
or two children (replace with inorder successor then delete successor).*/
/*
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
*/

///Traversals
///Use inorder (left-root-right) for sorted output, preorder (root-left-right), or postorder (left-right-root).

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

///main functions
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    inorder(root);  // Outputs: 30 50 70
    return 0;
}
