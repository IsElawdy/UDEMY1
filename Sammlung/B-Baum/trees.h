#include <iostream>
#include <cstdlib>
using namespace std;

struct tree_node
{
  int data;
  tree_node *left, *rigth;
  void print_tree_inorder();
  void print_tree_preorder();
  void print_tree_postorder();
  int insert_node(int);
  tree_node * newnode(int);
};

class binary_tree
{
 private:
	 tree_node * root ;
	 void free_tree(tree_node *);
 public:
	 binary_tree() : root (NULL) {};
	 binary_tree(const int);
	 ~binary_tree();
	 void print_tree_inorder();
	 void print_tree_preorder();
	 void print_tree_postorder();
	 int insert_node(int);
};

