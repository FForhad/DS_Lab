#include <stdio.h>
//#include <stdlib.h>

// 1. Structure Definition
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// 2. Function to create a new node (The "Box" maker)
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 3. Insert Function (Recursive - The Logic)
// Logic: Smaller data goes Left, Larger data goes Right
struct Node* insert(struct Node* root, int value) {
    // Case 1: If the spot is empty, put the node here
    if (root == NULL) {
        return createNode(value);
    }

    // Case 2: If value is smaller, go to the left sub-tree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // Case 3: If value is larger, go to the right sub-tree
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// 4. Inorder Traversal (To print and verify)
// Logic: Left -> Root -> Right
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);       // Visit Left
        printf("%d ", root->data); // Print Root
        inorder(root->right);      // Visit Right
    }
}

int main() {
    struct Node* root = NULL;

    // Hardcoding inputs to demonstrate the logic simply
    // Tree Structure creation:
    //        50
    //       /  \
    //     30    70

    root = insert(root, 50); // The Root
    insert(root, 30);        // Smaller -> Goes Left
    insert(root, 70);        // Larger  -> Goes Right
    insert(root, 90);        // Smaller than 50, Smaller than 30 -> Left-Left
    insert(root, 12);
    //insert(root, 22);

    printf("Tree contents (sorted): ");
    inorder(root);
    printf("\n");

    return 0;
}


