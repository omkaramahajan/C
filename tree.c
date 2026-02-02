#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lc, *rc;
};

struct node *root = NULL;

/* Function to create tree */
struct node* createTree()
{
    int val;
    struct node *temp;

    printf("Enter value (-1 for no node): ");
    scanf("%d", &val);

    if (val == -1)
        return NULL;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;

    printf("Enter left child of %d\n", val);
    temp->lc = createTree();

    printf("Enter right child of %d\n", val);
    temp->rc = createTree();

    return temp;
}

/* Inorder Traversal */
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->lc);
        printf("%d ", root->data);
        inorder(root->rc);
    }
}

/* Preorder Traversal */
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->lc);
        preorder(root->rc);
    }
}

/* Postorder Traversal */
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->lc);
        postorder(root->rc);
        printf("%d ", root->data);
    }
}

/* Count total nodes */
int countNodes(struct node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->lc) + countNodes(root->rc);
}

/* Count leaf nodes */
int countLeaf(struct node *root)
{
    if (root == NULL)
        return 0;
    if (root->lc == NULL && root->rc == NULL)
        return 1;
    return countLeaf(root->lc) + countLeaf(root->rc);
}

/* Height of tree */
int height(struct node *root)
{
    if (root == NULL)
        return 0;

    int lh = height(root->lc);
    int rh = height(root->rc);

    return (lh > rh ? lh : rh) + 1;
}

/* Mirror Tree */
void mirror(struct node *root)
{
    if (root == NULL)
        return;

    struct node *temp;
    temp = root->lc;
    root->lc = root->rc;
    root->rc = temp;

    mirror(root->lc);
    mirror(root->rc);
}

/* Copy Tree */
struct node* copyTree(struct node *root)
{
    if (root == NULL)
        return NULL;

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = root->data;
    newnode->lc = copyTree(root->lc);
    newnode->rc = copyTree(root->rc);

    return newnode;
}

/* MAIN FUNCTION */
int main()
{
    int ch;
    struct node *copyRoot = NULL;

    do
    {
        printf("\n---------------- TREE MENU ----------------");
        printf("\n1. Create Tree");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Count Total Nodes");
        printf("\n6. Count Leaf Nodes");
        printf("\n7. Height of Tree");
        printf("\n8. Mirror Tree");
        printf("\n9. Copy Tree");
        printf("\n10. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (root == NULL)
                root = createTree();
            else
                printf("Tree already exists!");
            break;

        case 2:
            printf("Inorder: ");
            inorder(root);
            break;

        case 3:
            printf("Preorder: ");
            preorder(root);
            break;

        case 4:
            printf("Postorder: ");
            postorder(root);
            break;

        case 5:
            printf("Total Nodes = %d", countNodes(root));
            break;

        case 6:
            printf("Leaf Nodes = %d", countLeaf(root));
            break;

        case 7:
            printf("Height = %d", height(root));
            break;

        case 8:
            mirror(root);
            printf("Tree Mirrored!");
            break;

        case 9:
            copyRoot = copyTree(root);
            printf("Tree Copied! Inorder of Copy: ");
            inorder(copyRoot);
            break;

        case 10:
            printf("Exiting...");
            break;

        default:
            printf("Invalid Choice!");
        }

    } while (ch != 10);

    return 0;
}
