
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const ll MOD = 1e9 + 7;
const ll N = 2e5 + 5;   

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() {
        left = NULL;
        right = NULL;
        val = 0;
    }
    TreeNode(int data) {
        left = NULL;
        right = NULL;
        val = data;
    }
    TreeNode(int data, TreeNode *a, TreeNode *b){
        left = a;
        right = b;
        val = data;
    }
};

TreeNode *bst_insert(int x, TreeNode *root) 
{
    if(root == NULL)
        return new TreeNode(x);
    if(x < root -> val)
        root -> left = bst_insert(x, root -> left);
    else
        root -> right = bst_insert(x, root -> right);
    return root;
}

void bst_print(TreeNode *root)
{
    if(root == NULL)
        return;
    cout << root -> val << " ";
    bst_print(root -> left);
    bst_print(root -> right);
}

TreeNode *get(TreeNode *root) 
{
    TreeNode *cur = root;
    while(cur && cur -> left != NULL)
        cur = cur -> left;
    return cur;
}

TreeNode *bst_delete(int x, TreeNode *root)
{
    if(root == NULL)
        return root;

    if(x < root -> val)
        root -> left = bst_delete(x, root -> left);
    else if(x > root -> val)
        root -> right  = bst_delete(x, root -> right);
    else
    {
        if(root -> left == NULL && root -> right == NULL)
            return NULL;
        else if(root -> left == NULL)
        {
            TreeNode *temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL)
        {
            TreeNode *temp = root -> left;
            free(root);
            return temp;
        }
        TreeNode *inOrderSuccessor = get(root -> right);
        root -> val = inOrderSuccessor -> val;
        root -> right = bst_delete(inOrderSuccessor -> val, root -> right);
    }
    return root;
}

int main()
{
    IOS;
    ll q;
    cout << "Enter the number of queries you want to perform - ";
    cin >> q;
    cout << q << endl;
    TreeNode *root = NULL;

    while(q--)
    {
        ll num;
        cout << "Enter the number - ";
        cin >> num;
        cout << num << endl;

        // num = 1 -> if you want to insert in BST
        // num = 2 -> if you want to delete in BST
        // num = 3 -> if you want to print BST

        if(num == 1) 
        {
            cout << "Enter the value you want to insert - ";
            ll x; 
            cin >> x;
            cout << x << endl;
            root = bst_insert(x, root);
            // cout << root -> val << endl;
        }
        else if(num == 2)
        {
            cout << "Enter the value you want to delete - ";
            ll x; 
            cin >> x;
            cout << x << endl;
            root = bst_delete(x, root);
        }
        else if(num == 3)
        {
            bst_print(root);
            cout << endl;
        }
        else
        {
            cout << "Enter the right number";
        }
    }

}