#include "trees.h"

binary_tree::binary_tree(const int tn)
{
  root = new tree_node;
  if (!root)
	{
	 cout << "Out of memory \n";
	 exit(1);
	}
	else {
	 root->data = tn;
	 root->left = root->rigth = NULL;
	}
}
//binary_tree::~binary_tree() o.k.

binary_tree::~binary_tree()
{
  free_tree(root);
}
//-----------------------------------------------

//binary_tree::free_tree o.k.
void
binary_tree::free_tree(tree_node * free_pt)
{
  tree_node * tnp = free_pt;
  if (!tnp)
	 {
		free_tree (tnp->left);
		free_tree (tnp->rigth);
		delete tnp;
	 }
}
//-----------------------------------------------

//binary_tree::print_tree o.k.
void
binary_tree::print_tree_inorder()
{
  if (root)
	  root->print_tree_inorder();
  cout << "\n";	  
}
//-----------------------------------------------
//binary_tree::print_tree o.k.
void
binary_tree::print_tree_preorder()
{
  if (root)
	  root->print_tree_preorder();
  cout << "\n";
}
//------------------------------------------------
//binary_tree::print_tree o.k.
void
binary_tree::print_tree_postorder()
{
  if (root)
	  root->print_tree_postorder();
  cout <<"\n";
}
//------------------------------------------------
int
binary_tree::insert_node(int ins_data)
{
	int ret;
	if (!root)
  {
	  root = new tree_node;
	  if (root)
		 {
		  ret = 1;
		  root->data = ins_data;
		  root->left = root->rigth = NULL;
		 }
		else
		  ret = -1;
  }
  else {
	if (root -> data == ins_data)
		 ret = 0; // Datum schon vorhanden
	  else {
		 if (root -> data > ins_data)
			if (root->left)
			 ret = root->left->insert_node(ins_data);
			 else
			  {
				 root->left = root->newnode(ins_data);
				 if (root->left)
					ret = 1;
				  else
					ret = -1;
			  }
			else
			  if (root->rigth)
				 ret = root->rigth->insert_node(ins_data);
				else
				 {
					root->rigth = root->newnode(ins_data);
					if (root->rigth)
					  ret = 1;
					 else
					  ret = -1;
				 }
	  }
  }
return ret;
}


int
tree_node::insert_node(int insert_data)
{
  if (data == insert_data)
	 return 0;
	 else{
	  if (data > insert_data)
		 {
			if (left)
				return left->insert_node(insert_data);
			  else{
				left = newnode(insert_data);
				if (left)
				  return 1;
				 else return -1;
				}
		 }
		else
		 {
			if (rigth)
				return rigth->insert_node(insert_data);
			  else{
				rigth = newnode(insert_data);
				if (rigth)
				  return 1;
				 else return -1;
				}
		 }
	}
}
//--------------------------------------------------

//tree_node::print_tree o.k.
void
tree_node::print_tree_inorder(void)
{
	if (left)
	 left->print_tree_inorder();
  cout << data << " ";
	if (rigth)
	 rigth->print_tree_inorder();
}
//--------------------------------------------------
//tree_node::print_tree o.k.
void
tree_node::print_tree_preorder(void)
{
	cout << data << " ";
	if (left)
	 left->print_tree_preorder();
	if (rigth)
	 rigth->print_tree_preorder();
}
//--------------------------------------------------
//tree_node::print_tree o.k.
void
tree_node::print_tree_postorder(void)
{
	if (left)
	 left->print_tree_postorder();
	if (rigth)
	 rigth->print_tree_postorder();
	cout << data << " ";
}
//--------------------------------------------------

tree_node *
tree_node::newnode(int newint)
{
  tree_node * tmp;
  tmp = new tree_node;
  tmp -> data = newint;
  tmp -> left = tmp -> rigth = NULL;
  return tmp;
}
