#ifndef TREENODE_H
#define TREENODE_H

#include <memory>
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <iterator>
#include <queue>
#include <algorithm>
#include <bitset>

using namespace std;

class TreeNode {
public:

    char letter;
    double freq;
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;

  TreeNode();

  // Create T
  TreeNode(char l, double f);

  // Generate tree
  TreeNode generateTree(TreeNode newNode1, TreeNode newNode2);

  char reference(TreeNode newNode1, TreeNode newNode2);

  bool isLeaf(shared_ptr<TreeNode> root);
};

class Tree {
public:
  
private:
  shared_ptr<TreeNode> root;
};


#endif // TREENODE.H