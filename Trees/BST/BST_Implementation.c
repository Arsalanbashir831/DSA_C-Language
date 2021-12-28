#include <stdio.h>
#include <stdlib.h>

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

// search Node in BST
struct node *searchIter(struct node *root, int key)
{
    struct node *ptr=root;
    while (ptr != NULL)
    {
        if (key == ptr->data)
        {
            printf("  %d  FOUND ",ptr->data);
            return root;
        }
        else if (key < ptr->data)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
    return root;
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




int findSmallest(struct node *root)
{
    struct node* ptr = root;
    while (ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    return ptr->data;
    
}
int findLargest(struct node *root)
{
    struct node* ptr = root;
    while (ptr->right != NULL)
    {
        ptr = ptr->right;
    }
    return ptr->data;
    
}
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    else if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp;
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->left != NULL)
        {
            struct node *temp;
            temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp;
        temp->data= findSmallest(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
}
// int  findLargest(struct node *root){
//     struct node *ptr=root;
//     while (ptr->left!=NULL&&ptr!=NULL)
//     {   
//         ptr=ptr->left;
//     }
//     int large=ptr->data;
//     return large;
// }


int main()
{
    struct node *root = NULL;
    // hardcoded values 
    root = createNode(40);
   insert(root,10);
   insert(root,65);
   insert(root,25);
   insert(root,90);
   insert(root,5);
   insert(root,34);
   insert(root,20);
   insert(root,110);
   insert(root,15);
//part A
    deleteNode(root,25);
    deleteNode(root,90);
    //part B
    printf("\n====InOrder Traversal====\n");
    inOrder(root);
    printf("\n====PostOrder Traversal====\n");
    postOrder(root);
    printf("\n====PreOrder Traversal====\n");
    preOrder(root);

   
    // part d
    insert(root,45);
    insert(root,100);
    printf("\nTraversal After insertion of 45 and 100\n");
    inOrder(root);
     //part c 
    printf("\nSearching For 45\n");
    root = searchIter(root,45);
    //Part d
printf("\nlargest : %d",findLargest(root));    
printf("\nSmallest : %d",findSmallest(root));    
    
    return 0;
}