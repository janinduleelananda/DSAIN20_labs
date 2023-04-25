#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

node* newNode(int item)
{
    node* temp = new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root != NULL) {
        traverseInOrder(root->left);
        printf("%d ", root->key);
        traverseInOrder(root->right);
    }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insertNode(node->left, key);
    else
        node->right = insertNode(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL)
        return root;
 
    // Recursive calls for ancestors of
    // node to be deleted
    if (root->key > key) {
        root->left = deleteNode(root->left, key);
        return root;
    }
    else if (root->key < key) {
        root->right = deleteNode(root->right, key);
        return root;
    }
 
    // We reach here when root is the node
    // to be deleted.
 
    // If one of the children is empty
    if (root->left == NULL) {
        node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        node* temp = root->left;
        delete root;
        return temp;
    }
 
    // If both children exist
    else {
 
        node* succParent = root;
 
        // Find successor
        node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
 
        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        // Copy Successor Data to root
        root->key = succ->key;
 
        // Delete Successor and return root
        delete succ;
        return root;
    }
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}