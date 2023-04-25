#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
  // If the tree is empty, return a new node
  if (root == NULL) {
    struct node *temp = new node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
  }

  // Otherwise, recur down the tree
  if (key < root->key)
    root->left = insertNode(root->left, key);
  else if (key > root->key)
    root->right = insertNode(root->right, key);

  // Return the (unchanged) node pointer
  return root;
}

// Helper function to find the minimum value node in a tree
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  /* loop down to find the leftmost leaf */
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // base case
  if (root == NULL) return root;

  // If the key to be deleted is smaller than the root's key,
  // then it lies in left subtree
  if (key < root->key)
    root->left = deleteNode(root->left, key);

  // If the key to be deleted is greater than the root's key,
  // then it lies in right subtree
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  // if key is same as root's key, then This is the node
  // to be deleted
  else {
    // node with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      delete root;
      return temp;
    }

    // node with two children: Get the inorder successor (smallest
    // in the right subtree)
    struct node *temp = minValueNode(root->right);

    // Copy the inorder successor's content to this node
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
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
  return 0;
}
