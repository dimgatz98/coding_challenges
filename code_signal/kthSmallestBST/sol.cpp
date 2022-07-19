#include <iostream>

using namespace std;

int counter = 0, res;

//
// Binary trees are already defined with this interface:
template<typename T>
struct Tree {
  Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
  T value;
  Tree *left;
  Tree *right;
};

Tree<int>* insertIntoBST(Tree<int> * root, int val) {
    if(root == nullptr) return new Tree<int>(val);
    if(root->value > val){
        root->left = insertIntoBST(root->left, val);
    }
    else root->right = insertIntoBST(root->right, val);
    return root;
}

void inorder (Tree<int> * t, int k) {
    if (t->left != nullptr)
        inorder(t->left, k);

    counter++;
    if (counter == k) {
        res = t->value;
    }

    if (t->right != nullptr)
        inorder(t->right, k);
}

void print_tree (Tree<int> * t) {
    if (t == nullptr) {
        return;
    }

    print_tree (t->left);
    cout << t->value << endl;
    print_tree (t->right);
}

int solution(Tree<int> * t, int k) {
    inorder (t, k);

    return res;
}

int main () {
    int n, k, tmp;
    Tree<int> * t = nullptr;
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> tmp;
        t = insertIntoBST(t, tmp);
    }
    cin >> k;
    // print_tree (t);
    cout << solution (t, k) << endl;

    return 0;
}