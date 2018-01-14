#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node{
  int value;
  struct Node *left;
  struct Node *right;
  struct Node *parent;
  int nodeDepth;
};

struct Tree{
  struct Node *root;
  int size;
  int depth;
};


/*****************************************************
 **                   Max/min                       **
 ****************************************************/

int max_rec(struct Node *node, int max){
  if (node->right == NULL){
    return max;
  }
  else {
    max = max_rec(node->right, node->right->value);
  }
  return max;
}

int min_rec(struct Node *node, int min){
  if (node->left == NULL){
    return min;
  }
  else {
    min = min_rec(node->left, node->left->value);
  }
  return min;
}

void max(struct Tree *tree){
  int max = max_rec(tree->root, tree->root->value);
  printf("Max: %d\n", max);
}

void min(struct Tree *tree){
  int min = min_rec(tree->root, tree->root->value);
  printf("Min: %d\n", min);
}
/*****************************************************
 **                   Max/min                       **
 ****************************************************/



/*****************************************************
 **                   Node/Tree                     **
 ****************************************************/
struct Node* new_node(int value, struct Node* parent){
  struct Node *node = malloc(sizeof(struct Node));
  node->left = NULL;
  node->right = NULL;
  node->parent = parent;
  node->value = value;
  return node;
}

struct Tree* new_tree(int value){
  struct Tree *tree = malloc(sizeof(struct Tree));
  tree->root = new_node(value,NULL);
  tree->size = 1;
  tree->depth = 1;
  return tree; 
}



/*****************************************************
 **                   Node/Tree                     **
 ****************************************************/




/*****************************************************
 **                   Insert                        **
 ****************************************************/
void insert_rec(struct Node *node, int value, int depthCount){
  if (value <= node->value) {
    if (node->left != NULL) {
      insert_rec(node->left, value,depthCount);
    }
    else {
      node->left = new_node(value, node);
      node->left->nodeDepth = depthCount+1;
    }
  }
  else {
    if (node->right != NULL) {
      insert_rec(node->right, value, depthCount);
    }
    else {
      node->right = new_node(value, node);
      node->right->nodeDepth = depthCount +1;	    
    }
  }
}

void insert(struct Tree *tree, int value){
  int depthCount=0;
  if (value <= tree->root->value) {
    if (tree->root->left != NULL) {
      insert_rec(tree->root->left, value, depthCount);
    }
    else {
      tree->root->left = new_node(value, tree->root);
      tree->root->left->nodeDepth = depthCount +1;
      tree->depth = depthCount +1;
    }
  }
  else {
    if (tree->root->right != NULL) {
      insert_rec(tree->root->right, value, depthCount);
    }
    else {
      tree->root->right = new_node(value, tree->root);
      tree->root->right->nodeDepth = depthCount +1;
      tree->depth = depthCount +1;
    } 
  }
  printf("inserted: %d\n", value);
}
/*****************************************************
 **                   Insert                        **
 ****************************************************/




/*****************************************************
 **                   Delete                        **
 ****************************************************/
      /*
       4  
   2       6
1    3   5   7
    */

struct Node* delete_rec(struct Node *node, int value){
  struct Node* temp = NULL;
  if (node == NULL) {
    return node;
  }
  else if(node->value > value){
    node->left = delete_rec(node->left, value);
    //printf("1: %d\n",node->value);
  }
  else if(node->value < value){
    node->right = delete_rec(node->right, value);
    // printf("2: %d\n",node->value);
  }
  else {
    //    printf("3: %d\n",node->value);
    if (node->left == NULL) {
      temp = node;
      node = node->right;
      free(temp);
    }
    else if (node->right == NULL) {
      temp = node;
      node = node->left;
      free(temp);
    }
    else{
      //node->value = max_rec(node->left,value);
      node->value = max_rec(node->left,node->left->value);
      node->left = delete_rec(node->left, node->value);
    }
  }
  return node;
}


struct Tree* delete(struct Tree *tree, int value){
  tree->root = delete_rec(tree->root, value);
  printf("Deleted: %d\n", value);
  return tree;
}



/*****************************************************
 **                   Delete                        **
 ****************************************************/


/*****************************************************
 **                   Find                         **
 ****************************************************/ 


void find_rec(struct Node *node, int value){
  if (node == NULL) {
    printf("%d not in tree!\n",value);
  }
  else if (node->value == value) {
    printf("Found %d\n", value);
  }
  else if (node->value < value) {
    find_rec(node->right, value);
  }
  else {
    find_rec(node->left, value);
  }

}


void find(struct Tree *tree, int value){
  find_rec(tree->root, value);
}

/*****************************************************
 **                   Find                         **
 ****************************************************/ 


/*****************************************************
 **                   Traversal                     **
 ****************************************************/ 
void preorder_rec(struct Node *node){
  printf(" %d ",node->value);
  if (node->left != NULL) {
    preorder_rec(node->left);	
  }
  if (node->right != NULL){
    preorder_rec(node->right);
  }  
}

void preorder(struct Tree *tree){
  printf("Preorder: ");
  struct Node *root = tree->root;
  printf(" %d ",root->value);
  if (root->left != NULL) {
    preorder_rec(root->left);	
  }  
  if (root->right != NULL){
    preorder_rec(root->right);
  }
  printf("\n");

}

void inorder_rec(struct Node *node){
  if (node->left != NULL) {
    inorder_rec(node->left);	
  }
  printf(" %d ",node->value);
  if (node->right != NULL){
    inorder_rec(node->right);
  }  
}
void inorder(struct Tree *tree){
  printf("Inorder: ");
  struct Node *root = tree->root;
  if (root->left != NULL) {
    inorder_rec(root->left);	
  }
  printf(" %d ",root->value);
  if (root->right != NULL){
    inorder_rec(root->right);
  }
  printf("\n");
}


void postorder_rec(struct Node *node){
  if (node->left != NULL) {
    postorder_rec(node->left);	
  }

  if (node->right != NULL){
    postorder_rec(node->right);
  }
  printf(" %d ",node->value);
}

void postorder(struct Tree *tree){
  printf("Postorder: ");
  struct Node *root = tree->root;
  if (root->left != NULL) {
    postorder_rec(root->left);	
  }  
  if (root->right != NULL){
    postorder_rec(root->right);
  }
  printf(" %d ",root->value);
  printf("\n");

}

/*****************************************************
 **                   Traversal                     **
 ****************************************************/ 



int main(){

  bool run = true;
  struct Tree *tree; 
  int choice = 0;
  int value = 0;

  /*  
  printf("\n Insert what value?");
  printf("\n Value: ");
  scanf("%d", &value);
  tree = new_tree(value);
  printf("\nTree created... \n");
  printf("\n Value %d inserted...\n\n", value);
  printTree(tree);
  */

  /*
                7
	1               9
    0       3         8   10
         2     5
             4   6

   */
  printf("\ntree created with root 7\n");
  tree = new_tree(7);
  insert(tree, 1);
  insert(tree, 9);
  insert(tree, 0);
  insert(tree, 3);
  insert(tree, 8);
  insert(tree, 10); 
  insert(tree, 2);
  insert(tree, 5);
  insert(tree, 4);
  insert(tree, 6);
  max(tree);
  min(tree);
  inorder(tree);  //1 2 3 4 5 6..
  preorder(tree);
  postorder(tree);

  tree = delete(tree, 5);
  inorder(tree); 
  preorder(tree);
  postorder(tree);

  find(tree,6);
  tree = delete(tree, 6);
  find(tree,6);
  inorder(tree); 
  preorder(tree);
  postorder(tree);
  tree = delete(tree, 0);
  tree = delete(tree, 1);
  tree = delete(tree, 2);
  tree = delete(tree, 3);
  tree = delete(tree, 4);
  tree = delete(tree, 7);
  tree = delete(tree, 8);
  tree = delete(tree, 9);

  inorder(tree); 
  preorder(tree);
  postorder(tree);
  
  insert(tree, 1);
  insert(tree, 9);
  insert(tree, 0);
  insert(tree, 3);
  insert(tree, 8);
  insert(tree, 10); 
  insert(tree, 2);
  insert(tree, 5);
  insert(tree, 4);
  insert(tree, 6);
  inorder(tree); 
  preorder(tree);
  postorder(tree);
  
  while(run){
    
    printf("\nEnter command:");
    printf("\n [1] Insert element");
    printf("\n [2] delete element");
    printf("\n [3] find element");
    printf("\n [4] preorder print");
    printf("\n [5] inorder print");
    printf("\n [6] postorder print");
    printf("\n [7] find minimum");
    printf("\n [8] find maximum");
    printf("\n [9] quit");

    printf("\nEnter integer (1-9):");

    scanf("%d", &choice);
    printf("\n");
	  
    
    switch (choice) {
    case 1: {
      
      printf("\n Insert what value?");
      printf("\n Value: ");
      scanf("%d", &value);
      insert(tree, value);
      printf("\n Value %d inserted...\n\n", value);
 
      break;
    }
    case 2: {
      
      printf("\n Delete what value?");
      printf("\n Value: ");
      scanf("%d", &value);
      tree = delete(tree, value); 
      break;
    }
    case 3: {    
      
      printf("\n Find what value?");
      printf("\n Value: ");
      scanf("%d", &value);
      find(tree, value);
      break;
    }
    case 4: {
      
      preorder(tree);
    }
      
    case 5: {
      
      inorder(tree);
      break;
    }
    case 6: {
      postorder(tree);
      break;
    }
    case 7: {
      min(tree);
      break;
    } 
    case 8: {
      max(tree);
      break;
    } 
      
    default:
      run = false;
      break;
    }

  }
  
  return 0;
}
