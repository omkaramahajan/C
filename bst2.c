#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *root = NULL;

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

struct node* findMinNode(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int height(struct node* root) {
    if (root == NULL)
        return -1;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

void printLevel(struct node* root, int level) {
    if (root == NULL)
        return;

    if (level == 0)
        printf("%d ", root->data);
    else {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

int countLevel(struct node* root, int level) {
    if (root == NULL)
        return 0;

    if (level == 0)
        return 1;

    return countLevel(root->left, level - 1) +
           countLevel(root->right, level - 1);
}

int findMin(struct node* root) {
    return findMinNode(root)->data;
}

int findMax(struct node* root) {
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

void main() {
    int choice = 0, value, n, i;

    while (choice != 10) {

        printf("\n\n=-=-=MENU for Binary Search Tree=-=-=\n");
        printf("\n 1. Create BST");
        printf("\n 2. Traverse BST");
        printf("\n 3. Insert");
        printf("\n 4. Delete");
        printf("\n 5. Search");
        printf("\n 6. Print Levelwise");
        printf("\n 7. Count Nodes at Each Level");
        printf("\n 8. Total Levels");
        printf("\n 9. Min and Max Value");
        printf("\n 10. Exit");

        printf("\n\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            root = NULL;
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            printf("Enter values:\n");
            for (i = 0; i < n; i++) {
                scanf("%d", &value);
                root = insert(root, value);
            }
            printf("BST Created!\n");
            break;

        case 2:
            if (root == NULL) {
                printf("BST is Empty!\n");
                break;
            }
            printf("\nInorder: ");
            inorder(root);
            printf("\nPreorder: ");
            preorder(root);
            printf("\nPostorder: ");
            postorder(root);
            printf("\n");
            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Inserted!\n");
            break;

        case 4:
            if (root == NULL) {
                printf("BST is Empty!\n");
                break;
            }
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("Deleted if existed!\n");
            break;

        case 5:
            if (root == NULL) {
                printf("BST is Empty!\n");
                break;
            }
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search(root, value) != NULL)
                printf("Element Found!\n");
            else
                printf("Element Not Found!\n");
            break;

        case 6:
            if (root == NULL) {
                printf("BST is Empty!\n");
                break;
            }
            for (i = 0; i <= height(root); i++) {
                printf("\nLevel %d: ", i);
                printLevel(root, i);
            }
            printf("\n");
            break;

        case 7:
            if (root == NULL) {
                printf("BST is Empty!\n");
                break;
            }
            for (i = 0; i <= height(root); i++) {
                printf("\nNodes at Level %d: %d", i,
                       countLevel(root, i));
            }
            printf("\n");
            break;

        case 8:
            if (root == NULL) {
                printf("BST is Empty!\n");
                break;
            }
            printf("Total Levels: %d\n", height(root) + 1);
            break;

        case 9:
            if (root == NULL) {
                printf("BST is Empty!\n");
                break;
            }
            printf("Minimum: %d\n", findMin(root));
            printf("Maximum: %d\n", findMax(root));
            break;

        case 10:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    }
}
