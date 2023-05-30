// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <algorithm>
#include <vector>

struct Node {
    char num;
    std::vector<Node*> lil;
};

class Tree {
 private:
    Node* root;
    std::vector<std::vector<char>> permutations;
    void createPerm(const std::vector<char>& posl) {
        addLil(root, posl);
        readTree(root, {});
    }
    void readTree(Node* ptr, std::vector<char> posl) {
        if (ptr != nullptr && ptr->num != '\0') posl.push_back(ptr->num);
        if (ptr->lil.empty()) permutations.push_back(posl);
        for (Node* pot : ptr->lil) {
            readTree(pot, posl);
        }
    }
    void addLil(Node* ptr, const std::vector<char>& posl) {
        if (ptr == nullptr) {
            root = ptr;
            root = new Node;
        }
        for (char num : posl) {
            Node* tm = new Node(num);
            ptr->lil.push_back(tm);
            std::vector<char> updatedPosl(posl);
            updatedPosl.erase \
                (std::find(updatedPosl.begin(), updatedPosl.end(), num));
            addLil(tm, updatedPosl);
        }
    }

 public:
     explicit Tree(const std::vector<char>& init):root(nullptr) {
         createPerm(init);
     }
     std::vector<std::vector<char>> getpermutations() const {
         return permutations;
     }
};
#endif  // INCLUDE_TREE_H_
