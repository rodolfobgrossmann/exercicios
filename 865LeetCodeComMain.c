#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct TreeNode {
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
};

struct TreeNode* createNode(int val);
int FindHeight(struct TreeNode* root);
struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root);


int main()
{
    struct TreeNode* root = createNode(3);
    root->left = createNode(5);
    root->right = createNode(1);
    root->left->left = createNode(6);
    root->left->right = createNode(2);
    root->right->right = createNode(8);
    root->left->right->left = createNode(7);
    root->left->right->right = createNode(4);
    
    struct TreeNode* subtree = subtreeWithAllDeepest(root);
    printf("Raiz da menor subárvore contendo os nós mais profundos: %d\n", subtree->val);
}

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int FindHeight(struct TreeNode* root){
    if(root == NULL) return 0;
    return 1+fmax(FindHeight(root->left), FindHeight(root->right));
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    if(root == NULL) return root;
    int right, left;
    right = FindHeight(root->right);
    left = FindHeight(root->left);

    if(left == right) return root;
    if(right > left){
        return subtreeWithAllDeepest(root->right);
    }else{
        return subtreeWithAllDeepest(root->left);
    }
}
