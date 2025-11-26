#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node *left;
struct node *right;
};
typedef struct node *NODE;

NODE createBST(NODE root,int key){
NODE temp,prev,cur;
temp=(NODE)malloc(sizeof(struct node));
temp->data=key;
temp->left=NULL;
temp->right=NULL;
if(root==NULL)
    return temp;
cur=root;
prev=NULL;
while(cur!=NULL){
    prev=cur;
    if(key<cur->data)
        cur=cur->left;
    else
        cur=cur->right;
}
if(key<prev->data)
    prev->left=temp;
else
    prev->right=temp;
return root;
}

void preorder(NODE root){
if(root!=NULL){
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
}

void inorder(NODE root){
if(root!=NULL){
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}
}
void postorder(NODE root){
if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}
}
int main()
{NODE root=NULL;
int key,ch;
for(;;){
    printf("\n 1-insert\n 2-preorder\n 3-inorder\n 4-postorder\n 5-exit\n");
    printf("enter the choice:");
    scanf("%d",&ch);
    switch(ch){
    case 1: printf("\nread key to be inserted :");
            scanf("%d",&key);
            root=createBST(root,key);
            break;
    case 2:
        printf("\n preorder traversal is\n:");
        preorder(root);
        break;
    case 3:
        printf("\n inorder traversal is\n:");
        inorder(root);
        break;
    case 4:
        printf("\n postorder traversal is\n:");
        postorder(root);
        break;
    default: exit(0);
    }
}
    return 0;
}
