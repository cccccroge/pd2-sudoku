#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Sudoku {

	public:
	void giveQuestion();
	void readIn();
	void changeNum(int a,int b);
	void changeRow(int a,int b);
	void changeCol(int a,int b);
	void rotate(int n);
	void flip(int n);
	void transform();
	void checkQuestion();
	int  check(int p);
	void solve();

	private:

	vector<int> board,temp;
	int newBoard[10][10], result[10][10], temp1[10][10];
	int num;
	int unavail[82];

};
