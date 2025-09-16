#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MALLOC(p,s)\
    if(!((p)=malloc(s))){\
    fprintf(stderr,"Insufficient memory");\
    exit(EXIT_FAILURE);\
    }
typedef struct node *element;
struct node{
    char word[50],meaning[100];
    element left,right;
};
element createNode(char* word,char*meaning);
element insert(element root,char*word,char*meaning);
element search(element root,char*word);
void inorder(element root);

element createNode(char*word,char*meaning){
    element newNode=(element)malloc(sizeof(struct node));
    strcpy(newNode->word,word);
    strcpy(newNode->meaning,meaning);
    newNode->left=newNode->right=NULL;
    return newNode;
}
element insert(element root,char*word,char*meaning){
    if(root==NULL){
        return createNode(word,meaning);
    }
    if(strcmp(word,root->word)<0){
        root->left=insert(root,word,meaning);
    }
    else if(strcmp(word,root->word)>0){
        root->right=insert(root,word,meaning);
    }
    return root;
}
element search(element root,char*word){
    if(root==NULL||strcmp(word,root->word)==0){
return root;}
if(strcmp(word,root->word)<0){
    return search(root->left,word);
}
else{
    return search(root->right,word);
}
}
void inorder(element root){
    if(root!=NULL){
        inorder(root->left);
        printf("%s:%s\n",root->word,root->meaning);
        inorder(root->right);
    }
}
int main(){
    char searchel[50],word[50],meaning[100];
    int n;
    element root=NULL;

    root=insert(root,"table","a type of furniture");
    root=insert(root,"mits","college");
    root=insert(root,"cat","animal");
    printf("Dictionary in alphabetical order:\n");
    inorder(root);
    printf("enter word to search:\n");
    scanf("%s",searchel);
    element result=search(root,searchel);
    if(result){
        printf("meaning of %s",result->word,result->meaning);
    }
    else{
        printf("word not found");
    }
}


