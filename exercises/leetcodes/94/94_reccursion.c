#include<stdio.h>
#include<stdlib.h>

typedef struct _TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
}TreeNode;

TreeNode construct(void);

void visit(TreeNode*, int*, int*);

int* inorderTraversal(TreeNode*, int*);

int main(void){
    r = construct();

    return 0;
}

TreeNode construct(void){
    /* construct a tree: 1-> null
     *                    -> 2 -> -3,4
    */
    TreeNode root;
    root->val = 1;
    root->left = NULL;
    root->right->val = 2;
    root->right->left->val = -3;
    root->right->right->val = 4;
    root->right->left->left = null;
    root->right->right->left = null;
    root->right->left->right = null;
    root->right->right->right = null;

    return root;
}

void visit(TreeNode* root, int* ans, int* returnSize){
    if (!root) return NULL;
    visit(root->left);
    ans[(*returnSize)++] = root->val;
    visit(root->right);
}

int* inorderTraversal(TreeNode* root, int* returnSize){
    int* ans = (int*)malloc(300*sizeof(int));
    *returnSize = 0;
    visit(root, ans, returnSize)
    return ans;    
}