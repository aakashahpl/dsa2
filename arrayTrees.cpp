#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int tree[MAX_SIZE];
int size = 0;

void createTree() {
    if (size > 0) {
        printf("Tree already exists. Please delete the current tree to create a new one.\n");
        return;
    }

    printf("Enter the root value: ");
    scanf("%d", &tree[0]);
    size++;
    printf("Tree created successfully!\n");
}

int getParentIndex(int index) {
    return (index - 1) / 2;
}

int getLeftChildIndex(int index) {
    return 2 * index + 1;
}

int getRightChildIndex(int index) {
    return 2 * index + 2;
}

void insertNode() {
    if (size == 0) {
        printf("Tree is not created. Please create the tree first.\n");
        return;
    }

    if (size >= MAX_SIZE) {
        printf("Tree is full. Cannot insert more nodes.\n");
        return;
    }

    int parentIndex, data, index;
    printf("Enter the parent value: ");
    scanf("%d", &data);

    for (index = 0; index < size; index++) {
        if (tree[index] == data) {
            break;
        }
    }

    if (index == size) {
        printf("Parent not found in the tree.\n");
        return;
    }

    if (getLeftChildIndex(index) >= MAX_SIZE || getRightChildIndex(index) >= MAX_SIZE) {
        printf("Parent node is full. Cannot insert more children.\n");
        return;
    }

    printf("Enter the value to insert: ");
    scanf("%d", &tree[getLeftChildIndex(index)]);
    size++;
    printf("Node inserted successfully!\n");
}

void deleteNode() {
    if (size == 0) {
        printf("Tree not created\n");
        return;
    }

    int data, index;
    printf("Enter the value to delete: ");
    scanf("%d", &data);

    for (index = 0; index < size; index++) {
        if (tree[index] == data) {
            break;
        }
    }

    if (index == size) {
        printf("Node not found\n");
        return;
    }

    tree[index] = -1;
    size--;
    printf("Node deleted\n");
}

void displayTree(int index, int level) {
    int i;
    if (index < size) {
        displayTree(getRightChildIndex(index), level + 1);
        for (i = 0; i < level; i++) {
            printf("   ");
        }
        printf("%d\n", tree[index]);
        displayTree(getLeftChildIndex(index), level + 1);
    }
}

int main() {
    int choice;
    printf("1. Create Tree\n");
    printf("2. Insert Node\n");
    printf("3. Delete Node\n");
    printf("4. Display Tree\n");
    printf("5. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            
                createTree();
                break;
            case 2:
                insertNode();
                break;
            case 3:
                deleteNode();
                break;
            case 4:
                printf("Binary Tree:\n");
                displayTree(0, 0);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}