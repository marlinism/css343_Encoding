#include "TreeNode.h"

// Implement class Encoder
TreeNode::TreeNode() {
  left = right = nullptr;
}

TreeNode::TreeNode(char l, double f) {
        letter = l;
        freq = f;
        left = right = nullptr;
    }

// Generate tree
TreeNode TreeNode::generateTree(TreeNode newNode1, TreeNode newNode2) {
    shared_ptr<TreeNode> left = make_shared<TreeNode> (newNode1);
    shared_ptr<TreeNode> right = make_shared<TreeNode> (newNode2);

    TreeNode node(reference(newNode1, newNode2), left -> freq + right -> freq);
    node.left = left;
    node.right = right;
 
    return node;
}

char TreeNode::reference(TreeNode newNode1, TreeNode newNode2) {
  if(newNode1.letter < newNode2.letter) {
    return newNode1.letter;
  } else {
    return newNode2.letter;
  }
}

bool TreeNode::isLeaf(shared_ptr<TreeNode> root) {
  return (root -> left == nullptr && root -> right == nullptr);
}