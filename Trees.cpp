#include <iostream>
#include <stack>
#include <string>

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

// Fing how many branches down the tree is!

int n, data, l, r;
int height(Node* root){
    if(root->left == NULL && root->right == NULL){
        return 0;
    }
    else{
        if(root->left){
            l=height(root->left);
        }
        if(root->right){
            r=height(root->right);
        }
        if(l>r){
            l++;
            return l;
        }
        else{
            r++;
            return r;
        }
    }
}

// Goal - print out the data on the ouside of the tree!
// This is completed with the following three functions

static void TopViewPostOrder(Node* root){
    if(root == NULL){
        return;
    }
    else{
        cout << root -> data << " ";
        TopViewPostOrder(root -> left);
    }
}

static void TopViewPreOrder(Node* root){
    if(root == NULL){
        return;
    }
    else{
        cout << root -> data << " ";
        TopViewPreOrder(root -> right);
    }
}


void TopView(Node* root){
    TopViewPostOrder(root);
    TopViewPreOrder(root -> right);
}

// To print the nodes in a level order we need to use a queue!

stack<Node*> queue;

void levelOrder(Node* root){
    if(root == NULL){
        return;
    }
    else{
        Node* curr = root;
        queue.push(curr);
        while(!queue.empty()){
            curr = queue.front();         // this returns the element at the front of the queue
            cout << curr -> data << " ";
            if(curr -> left){               // add childern to queue
                queue.push(curr->left)
            }
            if(curr -> right){
                queue.push(curr->right);
            }
            queue.pop();        // remove the front nodes as we have printed it
        }
    }
            

void InsertBST(Node* root, int data){
    Node* newNode = new Node;
    newNode -> rigth, newNode -> left = NULL;
    newNode -> data = data;
    if( root == NULL){
        newNode = root;
    }
    else{
        Node* curr = root;
        while(curr){
            if(newNode -> data < curr -> data){
                if(curr -> left){
                    curr = curr -> left;
                }
                else{
                    curr -> left = newNode;
                    break;
                }
            }
            else{
                if(curr -> right){
                    curr = curr -> right;
                }
                else{
                    curr -> right = newNode;
                    break;
                }
            }
        }
    }
}

// Huffman Decoding
// This requiers a second struc!
// This is a way of compressing data!

struct NodeH{
    int freq;
    char data;
    NodeH* right;
    NodeH* left;
};


void decode_huff(node* root, string s){
    if(root == NULL){
        return;
    }
    else{
        int i = 0;
        node* curr = root;
        for(i; i < s.length(); i++){
            int value = int(s[i]) - 48;
            if(value == 1){
                curr = curr -> right;
                if(curr -> data && curr -> freq > 0){
                    cout << curr -> data;
                    curr -> freq = (curr -> freq - 1);
                    curr = root;
                }
            }
            if(value == 0){
                curr = curr -> left;
                if(curr -> data && curr -> freq >0){
                    cout << curr -> data;
                    curr -> freq = (curr -> freq - 1);
                    curr = root;
                }
            }
        }
    }
}

// Lowest Common Ancestor
// This is to find the node that connects the two imputed numebrs

// need to map this out!!!


node* lca(node *root, int v1, int v2){
    if(root == NULL){
        return;
    }
    else{
        // this will get two pointers at the data points v1 and v2
        node *pointerV1 = root, *pointerV2 = root;
        node* arrayp = {pointerV1,pointerV2};
        int array = {v1,v2};
        for(int i = 0; i < 2; i++){
            while(arrayp[i]){
                if(arrayp[i] -> data < array[i]){
                    if(arrayp[i] -> left){
                        arrayp[i] = arrayp[i] -> left;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(arrayp[i] -> rigth){
                        arrayp[i] = arrayp[i] -> right;
                    }
                    else{
                        break;
                    }
                }
            }
            
            // out of the for loop
        }

    }

    return Common_Assender;

}


        



    }

}
    

int main()
{

    return 0;
}
