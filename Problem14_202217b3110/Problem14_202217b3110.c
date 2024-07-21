#include <stdio.h>

int maxNode = 15;
char tree[] = {'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0', 'V', '\0', 'J', 'L'};

int getRightChild(int index) {
    if (tree[index] != '\0' && ((2 * index) + 1) <= maxNode)
        return (2 * index) + 1;
    return -1;
}

int getLeftChild(int index) {
    if (tree[index] != '\0' && (2 * index) <= maxNode)
        return 2 * index;
    return -1;
}

void preorder(int index) {
    if (index > 0 && tree[index] != '\0') {
        printf(" %c ", tree[index]);
        preorder(getLeftChild(index));
        preorder(getRightChild(index));
    }
}

void postorder(int index) {
    if (index > 0 && tree[index] != '\0') {
        postorder(getLeftChild(index));
        postorder(getRightChild(index));
        printf(" %c ", tree[index]);
    }
}

void inorder(int index) {
    if (index > 0 && tree[index] != '\0') {
        inorder(getLeftChild(index));
        printf(" %c ", tree[index]);
        inorder(getRightChild(index));
    }
}

int main() {
    printf("Preorder:\n");
    preorder(1);
    printf("\nPostorder:\n");
    postorder(1);
    printf("\nInorder:\n");
    inorder(1);
    printf("\n");
    return 0;
}
