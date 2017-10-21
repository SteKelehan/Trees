#include <iostream>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};


int flag = 0;

void preOrder(node *root) {
    if (root == NULL)
     {
        cout << endl << "The list is empty" << endl; 
         return;
     }
     else
     {
         cout << root->data << " ";
         if (root->left)
         {
             preOrder(root->left);
             
         }
         if (root -> right)
         {
             preOrder(root->right);
         }
         return;
     }
 }
 


 void postOrder(Node* root)
 {
     if(root == NULL)
     {
         cout << "Tree is empty" << endl;
         return;
     }
     else
     {
         if (root->left)
         {
             postOrder(root->left);
         }
         cout << root -> data << " ";
         if (root -> right)
         {
             postOrder(root->right);
         }
         cout << root -> data << " ";
         return;
     }
 }



void InOrder(Node* root)
{
    if(root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    else
    {
        if (root->left)
        {
            inOrder(root->left);
        }
        cout << root -> data << " ";
        if (root -> right)
        {
            inOrder(root->right);
        }
        
        return;
    }
}

        
        
// data to the right is greater// data to the left of each node is less

bool checkBST(Node* root)
{
    if(root == NULL)
    {
        return true;
    }
    else
    {
        if(root -> left)
        {
            if(root -> data > (root -> left) -> data)
            {
                return checkBST(root -> left);
            }
            else
            {
                flag = 1;
            }
        }
        if(root -> right)
        {
            if(root -> data < (root -> right) -> data)
            {
                return checkBST(root -> right);
            }
            else
            {
                flag = 1;
            }
        }
    }
    if(flag == 0)
    {
        return true;
    }
    else{
        return false;
    }
}

int main()
{

    return 0;
}
