
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Create Node
struct node* createNode(int val)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert Node
struct node* insert(struct node* root, int val)
{
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// Find Minimum
struct node* findMin(struct node* root)
{
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

// Find Maximum
struct node* findMax(struct node* root)
{
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

// Level Order Traversal
void levelOrder(struct node* root)
{
    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    struct node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    printf("Level Order Traversal: ");

    while (front < rear)
    {
        struct node* temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left != NULL)
            queue[rear++] = temp->left;

        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }

    printf("\n");
}

int main()
{
    struct node* root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n------ Binary Search Tree Menu ------\n");
        printf("1. Insert\n");
        printf("2. Display Level Order\n");
        printf("3. Find Minimum\n");
        printf("4. Find Maximum\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Value inserted successfully.\n");
            break;

        case 2:
            levelOrder(root);
            break;

        case 3:
        {
            struct node* minNode = findMin(root);
            if (minNode != NULL)
                printf("Minimum value: %d\n", minNode->data);
            else
                printf("Tree is empty.\n");
            break;
        }

        case 4:
        {
            struct node* maxNode = findMax(root);
            if (maxNode != NULL)
                printf("Maximum value: %d\n", maxNode->data);
            else
                printf("Tree is empty.\n");
            break;
        }

        case 5:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
