#include <iostream>
using namespce std;
 
struct lelem{
   int a;
   lelem * left;
   lelem * right;
};

int insert_rek(lelem * & wurzel, int d)
{
  lelem * neu;
  if (wurzel)
   {
     if (wurzel -> a > d)
       {
         if (wurzel -> left)
           return insert_rek(wurzel->left, d);  //Weitersuchen
          else   //Blatt gefunden, neues Element
           {
             neu = new lelem;
             wurzel -> left = neu;
             neu -> a = d;
             neu -> left = neu -> right = NULL;
             return 1;
           }
        }
        else
         if (wurzel -> a < d)
           {
            if (wurzel -> right)
                return insert_rek(wurzel->right, d);  //Weitersuchen
              else   //Blatt gefunden, neues Element
               {
                  neu = new lelem;
                  wurzel -> right = neu;
                  neu -> a = d;
                  neu -> left = neu -> right = NULL;
                  return 1;
               }
            }
            else return 0;    // Datum schon da
     } 
    else
      {
       wurzel = new lelem;
       wurzel -> a = d;
       wurzel -> left = wurzel -> right = NULL;
       return 1;
      }
}      
          
void print_inorder(lelem * wurzel)
{
  if (wurzel -> left)
      print_inorder(wurzel -> left);
  cout << wurzel -> a << '\t';
  if (wurzel -> right)
      print_inorder(wurzel -> right);
}   
 
void print_preorder(lelem * wurzel)
{
  cout << wurzel -> a << '\t';
  if (wurzel -> left)
      print_preorder(wurzel -> left);
  if (wurzel -> right)
      print_preorder(wurzel -> right);
}

void print_postorder(lelem * wurzel)
{
  if (wurzel -> left)
      print_postorder(wurzel -> left);
  if (wurzel -> right)
      print_postorder(wurzel -> right);
  cout << wurzel -> a << '\t';
}

main()
 {
   lelem * root = NULL ;
   int i,j,k;
   lelem * neu;
   for (i = 1; i < 8; i++)
    {
      cin >> j;
      k = insert_rek(root,j);
      cout << i << ".tes Einfuegen\n";
      cout << endl;
    } 
   cout << "\n Inorder : \n";
   print_inorder (root);
   cout << "\n Preorder : \n";
   print_preorder (root);
   cout << "\n Postorder : \n";
   print_postorder (root);
 }
