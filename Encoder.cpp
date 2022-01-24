#include "Encoder.h"

 
// Implement class Encoder
Encoder::Encoder(shared_ptr<vector<int>> vectorPtr) {
    if(vectorPtr->size() != 26){
            throw invalid_argument("Constructor Error: Must have 26 Letter frequenices");
      }
    // Copy the vector
    this -> frequency = vectorPtr;
    makeTree();
}

void Encoder::makeTree() {
  vector<pair<int, char>> temp(frequency->size() + 1);
    for(int i = 0; i < frequency -> size(); i++) {
      if(this -> frequency -> at(i) <= 0) {
        throw invalid_argument("Error: Frequenices must be positive");
      }
      temp[i].first = this -> frequency -> at(i);
      temp[i].second = letterVector[i];
    }
    // Add delimiter
    temp.resize(temp.size() + 1);
    temp[27].first = 1;
    temp[27].second = '|';
  // Sort the vector
  sort(temp.begin(), temp.end());
  
  for(int i = 0; i < temp.size(); i++) {
    if(temp[i].first > 0) {
      TreeNode newNode(temp[i].second, temp[i].first);
      treeVector.push_back(newNode);
    }
  }
  while(treeVector.size() != 1) {
    sort(treeVector.begin(), treeVector.end(), [](const TreeNode &ts, const TreeNode &str){
      return tie(ts.freq, ts.letter) < tie(str.freq, str.letter);
    });
    //if equal lower in alphabet on left, greater on right
    if(treeVector[0].freq == treeVector[1].freq) {
      if(treeVector[0].letter < treeVector[1].letter) {
        TreeNode newNode = newTree.generateTree(treeVector[0], treeVector[1]);
        treeVector[1] = newNode;
        treeVector.erase(treeVector.begin());
      }
      else {
        TreeNode newNode = newTree.generateTree(treeVector[1], treeVector[0]);
        treeVector[1] = newNode;
        treeVector.erase(treeVector.begin());
      }
    }
    // if not equal, greater on left, smaller on right
    else {
      TreeNode newNode = newTree.generateTree(treeVector[1], treeVector[0]);
      treeVector[1] = newNode;
      treeVector.erase(treeVector.begin());
    }
  }
  shared_ptr<TreeNode> treePtr = make_shared<TreeNode>(treeVector[0]); 
  int arr[27], top = 0;
  printCodes(treePtr, arr, top);
  for(int i = 0; i < v.size(); i++) {
    cout << v[i].first << ": " << v[i].second << endl;
  }
}

void Encoder::printCodes(shared_ptr<TreeNode> root, int arr[], int top) {
    // Assign 0 to left edge and recur
    if (root->left != nullptr) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
 
    // Assign 1 to right edge and recur
    if (root->right != nullptr) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
 
    // If this is a leaf node, then it contains one of the
    // input characters, print the character and its code
    // from arr
    if (newTree.isLeaf(root)) {
        // cout << root -> letter << ": ";
        string bit = "";
        
        for(int i = 0; i < top; i++) {
          bit += to_string(arr[i]);
        }
        pair<char, string> foo;
        foo = make_pair(root -> letter, bit);
        v.push_back(foo);
    } 
}

shared_ptr<vector<char>> Encoder::Encode(string input) {
    vector<char> resultVtr;
    vector<int> temp;
    queue<int> p;
    int i = 1;
    input += "|";
    for(char c : input) {
      for(int i = 0; i < v.size(); i++) {
        if(c == v[i].first) {
          for(char d: v[i].second) {
            p.push((d - '0'));
          }
        }
      }
    }

    while(p.size() != 0) {
      if(i == 9) {
        char result = pack(temp);
        resultVtr.push_back(result);
        i = 1;
        temp.clear();
      }
      temp.push_back(p.front());
      p.pop();
      i++;
    }
    char result = pack(temp);
    resultVtr.push_back(result);

    shared_ptr<vector<char>> resultPtr = make_shared<vector<char>> (resultVtr);
    return resultPtr;
}

string Encoder::Decode(shared_ptr<vector<char>> vectorPtr) {
    string s = "";
    shared_ptr<TreeNode> treePtr = make_shared<TreeNode>(treeVector[0]); 
    for(int i = 0; i < vectorPtr -> size(); i++) {
      if(vectorPtr -> at(i) == '0') {
        treePtr = treePtr -> left;
      } else {
        treePtr = treePtr -> right;
      }

      if(newTree.isLeaf(treePtr)) {
        if(treePtr -> letter == '|') {
          return s;
        }
        s += treePtr -> letter;
        treePtr = make_shared<TreeNode>(treeVector[0]);
      }
    }
    return s;
}

char Encoder::pack(vector<int> k) {
  int result = 0;
  for(int i = 0; i < k.size() && i < 8; i++) {
    result = result << 1;
    if(k[i] == 1) {
      result = result | 1;
    }
  } 
  int shift = 8 - k.size();
  result = result << shift;
  return result;
}