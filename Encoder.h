#ifndef ENCODER_H
#define ENCODER_H

#include "TreeNode.h"

class Encoder {
public:
    //public constructor passing array of letter frequencies.
    Encoder(shared_ptr<vector<int> > vectorPtr);

    //Encode std::string into a sequence of bytes.
    shared_ptr<vector<char> > Encode(string); 

    //Decode an array of bytes into a std::string.
    string Decode(shared_ptr<vector<char> >);

    void makeTree();

    void printCodes(shared_ptr<TreeNode> root, int arr[], int top);

    char pack(vector<int> k);

private:
    // Create a shared point of the queue
    vector<TreeNode> treeVector;

    TreeNode newTree;

    // Create a copy of the vector
    shared_ptr<vector<int> > frequency;

    vector<pair<char, string> > v;

    vector<char> letterVector = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
};

#endif // ENCODER.H