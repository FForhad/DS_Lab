#include <stdio.h>
#include <stdlib.h> // Required for malloc

#define MAX_SIZE 50 // Increased size to prevent queue overflow

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Define root globally so the insert function can access it directly
struct TreeNode* root = NULL;

// Helper function to create a new node
struct TreeNode* create(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->val = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert data in Level Order (Breadth-First)
void insert(int data) {
    // 1. If tree is empty, new node becomes root
    if (root == NULL) {
        root = create(data);
        return;
    }

    // 2. Use a queue to find the first available spot
    struct TreeNode* queue[MAX_SIZE];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* temp = queue[front++];

        // Check Left Child
        if (temp->left == NULL) {
            temp->left = create(data);
            return;
        } else {
            queue[rear++] = temp->left;
        }

        // Check Right Child
        if (temp->right == NULL) {
            temp->right = create(data);
            return;
        } else {
            queue[rear++] = temp->right;
        }
    }
}

// Inorder Traversal (Left -> Root -> Right)
void inorder(struct TreeNode* temp) {
    if (temp != NULL) {
        inorder(temp->left);
        printf("%d ", temp->val);
        inorder(temp->right);
    }
}

int main() {
    int choice, data;

    while (1) {
        printf("\n\n--- Binary Tree Menu ---\n");
        printf("1. Insert (Level Order)\n");
        printf("2. Display (Inorder)\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(data);
                printf("Inserted %d", data);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!");
        }
    }
    return 0;
}
