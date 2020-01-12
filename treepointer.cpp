# dsa
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* insert(struct node* root,int data)
{
    
    if(root==NULL)
    {
        struct node* temp = (struct node*) malloc (sizeof(struct node));
        temp->data=data;
        temp->left=NULL;
        temp->right=NULL;
        root=temp;
    }
    else
    {
        if(data > root->data)
        {
            root->right = insert(root->right,data);
        }
        else
        {
            root->left = insert(root->left,data);
        }
        
    }
    return root;
}


bool search(struct node* root,int data)
{
    if(root==NULL)
    {
        return false;
    }
    else if(data==root->data)
    {
        return true;
    }
    else
    {
        if(data > root->data)
        {
            return search(root->right,data);
        }
        else
        {
            return search(root->left,data);
        }
        
    }
    
}


void preorder(struct node* root)
{
    if(root==NULL)
    {
        return ;
    }
    else
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void inorder(struct node* root)
{
    if(root==NULL)
    {
        return ;
    }
    else
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
    
}


void postorder(struct node* root)
{
    if(root==NULL)
    {
        return ;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}


int heightoftree(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int k=heightoftree(root->left);
        int l=heightoftree(root->right);
        if(k>l)
        {
            return k+1;
        }
        else
        {
            return l+1;
        }
    }
}


int numberofnodes(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return numberofnodes(root->left)+numberofnodes(root->right)+1;
    }
    
}


int findmin(struct node* root)
{
    if(root==NULL)
    {
        return -1;
    }
    else
    {
        while(root->left!=NULL)
        {
            root = root->left;
        }
    }
    return root->data;
    
}


int findmax(struct node* root)
{
    if(root==NULL)
    {
        return -1;
    }
    else
    {
        while(root->right!=NULL)
        {
            root = root->right;
        }
    }
    return root->data;
    
}


struct node* deletenodes(struct node* root, int data)
{
    if(root==NULL)
    {
        return root;
    }
    else if (data > root->data)
    {
        root->right = deletenodes(root->right,data);
    }
    else if (data < root->data)
    {
        root->left = deletenodes(root->left,data);
    }
    else
    {
        //No child
        if (root->left==NULL && root->right==NULL)
        {
            free(root);
            root=NULL;
        }
        //1 children
        else if (root->left==NULL)
        {
            struct node* temp=root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct node* temp=root;
            root = root->left;
            free(temp);
        }
        //2 child
        else
        {
            struct node* temp = findmin(root->right);
            root->data = temp->data;
            root->right = deletenodes(root->right,temp->data);
        }
        
        
    }
    return root;
}


int main()
{
    struct node* root=NULL;
    int i,j,n,t;
    while (1)
    {
        printf("Enter your choice\n");
        printf("1.Insert     2.Search    3.Preorder     4.Inorder    5.Postorder    6.Height    7.Number of nodes   8.Delete    9.Maximum    10.Minimum     11.Exit\n");
        scanf("%d",&n);
        if(n>10 || n<1)
        {
            return 0;
        }
        switch(n)
        {
            case 1:
            {
                int data;
                printf("\nEnter the element you want to enter \n");
                scanf("%d",&data);
                root = insert(root,data);
                break;
            }
            case 2:
            {
                int data;
                printf("\nEnter the element you want to search \n");
                scanf("%d",&data);
                if(search(root,data))
                {
                    printf("\nElement found\n");
                }
                else
                {
                    printf("\nElement not found\n");
                }
                break;
            }
            case 3:
            {
                preorder(root);
                printf("\n\n");
                break;
            }
            case 4:
            {
                inorder(root);
                printf("\n\n");
                break;
            }
            case 5:
            {
                postorder(root);
                printf("\n\n");
                break;
            }
            case 6:
            {
                printf("\n%d\n",heightoftree(root));
                break;
            }
            case 7:
            {
                printf("\n%d\n",numberofnodes(root));
                break;
            }
            case 8:
            {
                int data;
                printf("\nEnter the element you want to delete\n");
                scanf("%d",&data);
                root = deletenodes(root,data);
                break;
            }
            case 9:
            {
                printf("\n%d\n",findmax(root));
                break;
            }
            case 10:
            {
                printf("\n%d\n",findmin(root));
                break;
            }
            case 11:
            {
                exit(0);
            }
        }
    }
    


    return 0;
}
