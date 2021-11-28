#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
// create Node
struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
// checking if the tree is the BST
int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
// search Node in BST
struct node *searchIter(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}
// inset node in BST
void insert(struct node *root, int key)
{
    struct node *prev = NULL;

    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}
struct node *inOrderPre(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *inOrderPost(struct node *root)
{
    root = root->left;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// Delete Node in tree using InorderPrePredecessors
struct node *deleteNode(struct node *root, int key)
{
    struct node *iPre = NULL;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    // search the node
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    // Deletion strategy
    else
    {
        iPre = inOrderPre(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

// Delete Node in tree using InorderPostPredecessors
struct node *deleteNodePost(struct node *root, int key)
{
    struct node *iPost = NULL;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    // search the node
    if (key < root->data)
    {
        root->left = deleteNodePost(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNodePost(root->right, key);
    }
    // Deletion strategy
    else
    {
        iPost = inOrderPost(root);
        root->data = iPost->data;
        root->right = deleteNodePost(root->right, iPost->data);
    }
    return root;
}

int main()
{

    struct node *root = NULL;
    int data;
    printf("Enter the root data :");
    scanf("%d", &data);
    root = createNode(data);
    while (1)
    {
        printf("Enter the data : ");
        scanf("%d", &data);
        if (data == -1)
        {
            break;
        }
        insert(root, data);
    }
    printf("\n====InOrder Traversal====\n");
    inOrder(root);
    printf("\n====PostOrder Traversal====\n");
    postOrder(root);
    printf("\n====PreOrder Traversal====\n");
    preOrder(root);
    if (isBST(root) == 1)
    {
        printf("\nit is BST\n");
    }
    else
    {
        printf("\nIt is not BST\n");
    }
    // deletion using inorderPrePredessors
    printf("Enter the data to delete to node :");
    scanf("%d", &data);
    root = deleteNode(root, data);
    printf("\n");
    inOrder(root);
    // deletion using inorderPostPredessors
    printf("Enter the data to delete to node :");
    scanf("%d", &data);
    root = deleteNodePost(root, data);
    printf("\n");
    inOrder(root);
}
