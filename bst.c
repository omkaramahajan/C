#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lc, *rc;
};

struct node *root = NULL;

// Create Node
struct node *createNode(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->lc = temp->rc = NULL;
    return temp;
}

// Insert Node
struct node *insert(struct node *root, int val)
{
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->lc = insert(root->lc, val);
    else if (val > root->data)
        root->rc = insert(root->rc, val);

    return root;
}

// Search Node
int search(struct node *root, int key)
{
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;
    else if (key < root->data)
        return search(root->lc, key);
    else
        return search(root->rc, key);
}

// Traversals
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->lc);
    printf("%d ", root->data);
    inorder(root->rc);
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->lc);
    preorder(root->rc);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->lc);
    postorder(root->rc);
    printf("%d ", root->data);
}

// Count Total Nodes
int countNodes(struct node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->lc) + countNodes(root->rc);
}

// Count Leaf Nodes
int countLeaf(struct node *root)
{
    if (root == NULL)
        return 0;
    if (root->lc == NULL && root->rc == NULL)
        return 1;
    return countLeaf(root->lc) + countLeaf(root->rc);
}

// Copy Tree
struct node *copyTree(struct node *root)
{
    if (root == NULL)
        return NULL;
    struct node *newNode = createNode(root->data);
    newNode->lc = copyTree(root->lc);
    newNode->rc = copyTree(root->rc);
    return newNode;
}

// Compare Two Trees
int compareTree(struct node *r1, struct node *r2)
{
    if (r1 == NULL && r2 == NULL)
        return 1;
    if (r1 == NULL || r2 == NULL)
        return 0;
    if (r1->data != r2->data)
        return 0;

    return compareTree(r1->lc, r2->lc) && compareTree(r1->rc, r2->rc);
}

// Find Minimum Node
struct node *findMin(struct node *root)
{
    while (root->lc != NULL)
        root = root->lc;
    return root;
}

// Delete Node
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->lc = deleteNode(root->lc, key);
    else if (key > root->data)
        root->rc = deleteNode(root->rc, key);
    else
    {
        // Case 1 & 2: Node with one or no child
        if (root->lc == NULL)
        {
            struct node *temp = root->rc;
            free(root);
            return temp;
        }
        else if (root->rc == NULL)
        {
            struct node *temp = root->lc;
            free(root);
            return temp;
        }

        // Case 3: Node with two children
        struct node *temp = findMin(root->rc);
        root->data = temp->data;
        root->rc = deleteNode(root->rc, temp->data);
    }
    return root;
}

// Main Function
int main()
{
    int ch, val;
    struct node *copyRoot = NULL;

    while (1)
    {
        printf("\n--- BST MENU ---");
        printf("\n1.Insert");
        printf("\n2.Search");
        printf("\n3.Inorder");
        printf("\n4.Preorder");
        printf("\n5.Postorder");
        printf("\n6.Count Nodes");
        printf("\n7.Count Leaf Nodes");
        printf("\n8.Copy Tree");
        printf("\n9.Compare Tree");
        printf("\n10.Delete Node");
        printf("\n0.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            root = insert(root, val);
            break;

        case 2:
            printf("Enter value to search: ");
            scanf("%d", &val);
            if (search(root, val))
                printf("Found");
            else
                printf("Not Found");
            break;

        case 3:
            printf("Inorder: ");
            inorder(root);
            break;

        case 4:
            printf("Preorder: ");
            preorder(root);
            break;

        case 5:
            printf("Postorder: ");
            postorder(root);
            break;

        case 6:
            printf("Total Nodes = %d", countNodes(root));
            break;

        case 7:
            printf("Leaf Nodes = %d", countLeaf(root));
            break;

        case 8:
            copyRoot = copyTree(root);
            printf("Tree Copied Successfully");
            break;

        case 9:
            if (compareTree(root, copyRoot))
                printf("Both Trees are Same");
            else
                printf("Trees are Different");
            break;

        case 10:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            root = deleteNode(root, val);
            break;

        case 0:
            exit(0);
        }
    }
}
