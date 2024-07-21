#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *rightChild;
    struct TreeNode *leftChild;
};

struct TreeNode* createNode(int value) {
    struct TreeNode *newNode;
    newNode = malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

struct TreeNode* search(struct TreeNode *root, int value) {
    if (root == NULL || root->data == value)
        return root;
    else if (value > root->data)
        return search(root->rightChild, value);
    else
        return search(root->leftChild, value);
}

struct TreeNode* insert(struct TreeNode *root, int value) {
    if (root == NULL)
        return createNode(value);
    else if (value > root->data)
        root->rightChild = insert(root->rightChild, value);
    else
        root->leftChild = insert(root->leftChild, value);
    return root;
}

struct TreeNode* findMinimum(struct TreeNode *root) {
    if (root == NULL)
        return NULL;
    else if (root->leftChild != NULL)
        return findMinimum(root->leftChild);
    return root;
}

struct TreeNode* delete(struct TreeNode *root, int value) {
    if (root == NULL)
        return NULL;
    if (value > root->data)
        root->rightChild = delete(root->rightChild, value);
    else if (value < root->data)
        root->leftChild = delete(root->leftChild, value);
    else {
        if (root->leftChild == NULL && root->rightChild == NULL) {
            free(root);
            return NULL;
        } else if (root->leftChild == NULL || root->rightChild == NULL) {
            struct TreeNode *temp;
            if (root->leftChild == NULL)
                temp = root->rightChild;
            else
                temp = root->leftChild;
            free(root);
            return temp;
        } else {
            struct TreeNode *temp = findMinimum(root->rightChild);
            root->data = temp->data;
            root->rightChild = delete(root->rightChild, temp->data);
        }
    }
    return root;
}

void inorderTraversal(struct TreeNode *root) {
    if (root != NULL) {
        inorderTraversal(root->leftChild);
        printf(" %d ", root->data);
        inorderTraversal(root->rightChild);
    }
}

int main() {
    struct TreeNode *root;
    root = createNode(20);
    insert(root, 5);
    insert(root, 1);
    insert(root, 15);
    insert(root, 9);
    insert(root, 7);
    insert(root, 12);
    insert(root, 30);
    insert(root, 25);
    insert(root, 40);
    insert(root, 45);
    insert(root, 42);
    inorderTraversal(root);
    printf("\n");
    root = delete(root, 1);
    root = delete(root, 40);
    root = delete(root, 45);
    root = delete(root, 9);
    inorderTraversal(root);
    printf("\n");
    return 0;
}
