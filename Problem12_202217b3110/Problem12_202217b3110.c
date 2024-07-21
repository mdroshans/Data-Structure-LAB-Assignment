#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return root;
    }
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear) {
        Node* temp = queue[front++];
        if (temp->left == NULL) {
            temp->left = newNode(data);
            break;
        } else {
            queue[rear++] = temp->left;
        }
        if (temp->right == NULL) {
            temp->right = newNode(data);
            break;
        } else {
            queue[rear++] = temp->right;
        }
    }
    return root;
}

void deleteDeepest(Node* root, Node* deleteNode) {
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    Node* temp;
    while (front != rear) {
        temp = queue[front++];
        if (temp == deleteNode) {
            temp = NULL;
            free(deleteNode);
            return;
        }
        if (temp->right) {
            if (temp->right == deleteNode) {
                temp->right = NULL;
                free(deleteNode);
                return;
            } else {
                queue[rear++] = temp->right;
            }
        }
        if (temp->left) {
            if (temp->left == deleteNode) {
                temp->left = NULL;
                free(deleteNode);
                return;
            } else {
                queue[rear++] = temp->left;
            }
        }
    }
}

Node* deleteNode(Node* root, int key) {
    if (!root)
        return NULL;
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key)
            return NULL;
        else
            return root;
    }
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    Node* temp;
    Node* keyNode = NULL;
    while (front != rear) {
        temp = queue[front++];
        if (temp->data == key)
            keyNode = temp;
        if (temp->left)
            queue[rear++] = temp->left;
        if (temp->right)
            queue[rear++] = temp->right;
    }
    if (keyNode != NULL) {
        int x = temp->data;
        keyNode->data = x;
        deleteDeepest(root, temp);
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (!root)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (!root)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

void levelorderTraversal(Node* root) {
    if (root == NULL)
        return;
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear) {
        Node* temp = queue[front++];
        printf("%d ", temp->data);
        if (temp->left)
            queue[rear++] = temp->left;
        if (temp->right)
            queue[rear++] = temp->right;
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\nInorder traversal: ");
    inorderTraversal(root);
    printf("\nPostorder traversal: ");
    postorderTraversal(root);
    printf("\nLevel order traversal: ");
    levelorderTraversal(root);
    root = deleteNode(root, 20);
    printf("\nInorder traversal after deletion: ");
    inorderTraversal(root);
    return 0;
}
