#include <iostream>
#include <fstream> 
#include "sudoku.h"
using namespace std;
int main()
{
 	Sudoku su;
	int m[Sudoku::size][Sudoku::size];
	ifstream fin("map", ios::in);
	for(int i = 0; i < Sudoku::size; i++)
		for(int j = 0; j < Sudoku::size; j++)
			fin >> m[i][j];
	su.setmap(m);
	su.print_map();
	int mode = 1;
	while(mode)
	{
		int x, y;
	 	cin >> mode;
		switch(mode)
		{
		 	case 1:
				cin >> x >> y;
				su.swapNum(x, y);
				break;
			case 2:
				cin >> x >> y;
				su.swapRow(x,y);
				break;
			case 3:
				cin >> x >> y;
				su.swapCol(x, y);
				break;
			case 4:
				cin >> x;
				if(x % 4)
					su.rotate(x % 4);
				break;
			case 5:
				cin >> x;
				su.flip(x);
				break;
		
		}
		su.print_map();
	}
}
