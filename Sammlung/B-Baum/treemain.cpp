#include "trees.h"

main()
{
  binary_tree a(5);
  int ins;
  int erfolg;
  char ausw = 'J';
  while ((ausw == 'J')||(ausw == 'j'))
	{
		cout << "Eingabe Zahl \n";
		cin >> ins;
		erfolg = a.insert_node(ins);
		if (erfolg > 0)
		  cout << "Zahl " << ins << "eingefuegt \n";
		 else
		  if (erfolg == 0)
			 cout << "Zahl " << ins << "schon im Baum vorhanden   \n";
		  else
			 cout << "Zahl " << ins << "konnte nicht eingefuegt werden \n";
		cout << "Weiter [J/N] \n";
		cin >> ausw;

	}
	a.print_tree_inorder();
	a.print_tree_preorder();
	a.print_tree_postorder();
}

