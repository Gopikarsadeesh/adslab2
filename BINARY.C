#include<stdio.h>
#include<stdlib.h>
struct Node {
   int data;
   struct Node* left;
   struct Node* right;
};
   struct Node* createnode(int data) {
   struct Node* newNode=(struct node*)malloc(sizeof(struct Node));
   newnode->data= data;
   newnode->left= newNode->right=NULL;
   return newNode;
}
struct Node* insert(struct Node* root,int data) {
   if(root == NULL) {
   return createNode(data);
   }
   if(data < root->data) {
      root->left=insert(root->left,data);
   } else if(data>root->data) {
      root->right=insert(root->right,data);
   }
   return root;
   }
void inorderTraversal(struct Node* root) {
   if(root!=NULL) {
      inorderTraversal(root->left);
      printf("%d", root->data);
      inorderTraversal(root->right);
   }
}
void displayTree(struct Node* root, int space) {
    int COUNT= 5,i;
    if(root==NULL)
       return;
    }

    space += COUNT;

    displayTree(root->right, space);

    printf("\n");
    for(i =COUNT; i < space; i++) {
       printf(" ");
    }
    printf("%d\n", root->data);

    displayTree(root->left, space);
}

struct Node* search(struct Node* root, int key) {
    if(root == NULL || root->data == key) {
       return root;
    }
    if(key > root->data) {
       return search(root->right, key);
    }

    return search(root->left, key);
}
struct Node* findaMin(struct Node* node) {
    struct Node* current = node;

    while (current && current->left !=NULL) {
	current = current->left;
    }

    return current;
}

struct Node* deleteNode(struct Node* root,int key) {
    struct Node* temp = findMin(root->right);
    if (root == NULL) {
	return root;
    }
    if(key < root->data) {
       root->left = deleteNode(root->left, key);
   } else if(key > root->data) {
   root->right=deleteNode(root->right, key);
   } else {
       if(root->left==NULL) {
	  struct Node* temp = root->right;
	  free(root);
	  return temp;
   } else if(root->right == NULL) {
       struct Node* temp = root->left;
       free(root);
       return temp;
   }
     root->data=temp->data;
     root->right=deleteNode(root->right,temp->data);
   }
   return root;
}
int main() {
    struct Node* root = NULL;
    int choice, value;
    struct Node* result;

    while(1) {
      printf("\nBinary search tree operations:\n");
      printf("1.insert\n");
      printf("2.delete\n");
      printf("3.search\n");
      printf("4.search\n");
      printf("5.exit\n");
      printf("\n enter your choice: ");
      scanf("%d",&choice);
      switch(choice)
      {
      case 1:printf("enter data to insert:");
	     scanf("%d",&data);
	     root=insert(root,data);
	     printf("%d inserted \n",data);
	     break;
      case 2:printf("enter data to delete:");
	     scanf("%d",&data);
	     root=deleteNode(root,value);
	     break;
      case 3:printf("enter data to search:");
	     scanf("%d",&value);
	     result=search(root, value);
	     if(result !=NULL) {
	     printf("%d found in tree",value);
	     }
	     else
	     {
	     printf("%d no found in tree",value);
	     }
	     break;
     case 4:
	 printf("tree structure:\n");
	 displayTree(root, 0);
	 break;
    case 5:
	printf("exiting program.\n");
	break;

    default:printf("invalid choice");
	    break;
    }
}
return 0;