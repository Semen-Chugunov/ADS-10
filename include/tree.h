// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <algorithm>
#include <vector>

struct Node {
    char num;
    std::vector<Node*> lil;
    explicit Node(char num_ = '\0'): num(num_) {}
};

class Tree {
 public:
    explicit Tree(const std::vector<char>& init):root(nullptr) {
        createPerm(init);
    }
    std::vector<std::vector<char>> getpermutations() const {
        return permutations;
    }

 private:
    Node* root;
    std::vector<std::vector<char>> permutations;

    void createPerm(const std::vector<char>& posl) {
        addLil(root, posl);
        readTree(root, {});
    }

    void addLil(Node* ptr, const std::vector<char>& posl) {
        if (ptr == nullptr) {
            root = ptr = new Node;
        }
        for (char num : posl) {
            Node* tm = new Node(num);
            ptr->lil.push_back(tm);
            std::vector<char> updatedposl(posl);
            updatedposl.erase \
                (std::find(updatedposl.begin(), updatedposl.end(), num));
            addLil(tm, updatedposl);
        }
    }

    void readTree(Node* ptr, std::vector<char> posl) {
        if (ptr != nullptr && ptr->num != '\0') posl.push_back(ptr->num);
        if (ptr->lil.empty()) permutations.push_back(posl);
        for (Node* pot : ptr->lil) {
            readTree(pot, posl);
        }
    }
};
#endif  // INCLUDE_TREE_H_
