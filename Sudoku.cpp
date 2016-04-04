#include "Sudoku.h"

using namespace std;



	void Sudoku::giveQuestion(){

		cout << "0 8 0 0 0 0 5 9 0" << endl;
		cout << "9 0 4 0 0 0 7 0 0" << endl;
		cout << "0 0 6 5 0 4 0 0 0" << endl;
		cout << "0 1 2 4 0 0 0 0 0" << endl;
		cout << "0 0 3 0 0 0 0 6 8" << endl;
		cout << "0 0 0 0 0 0 0 5 0" << endl;
		cout << "0 0 0 6 0 5 0 0 0" << endl;
		cout << "0 4 0 0 0 8 6 1 0" << endl;
		cout << "0 4 0 1 0 7 0 0 0" << endl;
	}


	void Sudoku::readIn(){
	
		cout << "Enter a sudoku:" << endl; 

		//初始化數獨板
		board.reserve(82);
		board.push_back(0);

		//把數字讀入數獨板
		while(board.size() != 82){

			int e;
			cin >> e;
			board.push_back(e);
		}

		cout << "Import a sudoku successfully!" << endl;
		
	}




 	void Sudoku::changeNum(int a, int b){

		int newBoard[10][10];

		int i, j;
		for(i = 1 ; i < 82 ; i++)				//新的數獨板（二維）
		  newBoard[(i-1)/9+1][i-(i-1)/9*9] = temp[i];


		for(i = 1 ; i < 10 ; i++)
		for(j = 1 ; j < 10 ; j++){
		  if(newBoard[i][j] == b) result1[i][j] = a;			//數字交換
		  else if(newBoard[i][j] == a) result1[i][j] = b;
		  else result1[i][j] = newBoard[i][j];
		}

		/*cout << "result1:" << endl;
		for(i = 1 ; i < 10 ; i++)
		  for(j = 1 ; j < 10 ; j++)
		    j == 9 ? cout << result1[i][j] << endl : cout << result1[i][j] << " ";*/
	}

 	void Sudoku::changeRow(int a, int b){
		
		int i, j;

		if((a==0&&b==1)||(a==1&&b==0)){

			for(i = 1 ; i < 4 ; i++)
			  for(j = 1 ; j < 10 ; j++){
			    result2[i+3][j] = result1[i][j];
			    result2[i][j] = result1[i+3][j];
			  }
			for(i = 7 ; i < 10 ; i++)
			  for(j = 1 ; j < 10 ; j++)
			    result2[i][j] = result1[i][j];
		}

		if((a==0&&b==2)||(a==2&&b==0)){

			for(i = 1 ; i < 4 ; i++)
			  for(j = 1 ; j < 10 ; j++){
			    result2[i+6][j] = result1[i][j];
			    result2[i][j] = result1[i+6][j];
			  }
			for(i = 4 ; i < 7 ; i++)
			  for(j = 1 ; j < 10 ; j++)
			    result2[i][j] = result1[i][j];
		}

		if((a==1&&b==2)||(a==2&&b==1)){

			for(i = 4 ; i < 7 ; i++)
			  for(j = 1 ; j < 10 ; j++){
			    result2[i+3][j] = result1[i][j];
			    result2[i][j] = result1[i+3][j];
			  }
			for(i = 1 ; i < 4 ; i++)
			  for(j = 1 ; j < 10 ; j++)
			    result2[i][j] = result1[i][j];
		}

		if(a==b){

			for(i = 1 ; i < 10 ; i++)
			  for(j = 1 ; j < 10 ; j++)
			    result2[i][j] = result1[i][j];
		}

		/*cout << "result2:" << endl;
		for(i = 1 ; i < 10 ; i++,cout << endl)
		  for(j = 1 ; j < 10 ; j++)
		    cout << result2[i][j] << " ";*/
	}

	void Sudoku::changeCol(int a, int b){

		
		int i, j;
		/*for(i = 1 ; i < 10 ; i++)
		  for(j = 1 ; j < 10 ; j++)
		    result3[i][j]=0;*/

		if((a==0&&b==1)||(a==1&&b==0)){

			for(i = 1 ; i < 4 ; i++)
			  for(j = 1 ; j < 10 ; j++){
			    result3[j][i+3] = result2[j][i];
			    result3[j][i] = result2[j][i+3];
			  }
			for(i = 7 ; i < 10 ; i++)
			  for(j = 1 ; j < 10 ; j++)
			    result3[j][i] = result2[j][i];
		}

		if((a==0&&b==2)||(a==2&&b==0)){

			for(i = 1 ; i < 4 ; i++)
			  for(j = 1 ; j < 10 ; j++){
			    result3[j][i+6] = result2[j][i];
			    result3[j][i] = result2[j][i+6];
			  }
			for(i = 4 ; i < 7 ; i++)
			  for(j = 1 ; j < 10 ; j++)
			    result3[j][i] = result2[j][i];
		}

		if((a==1&&b==2)||(a==2&&b==1)){

			for(i = 4 ; i < 7 ; i++)
			  for(j = 1 ; j < 10 ; j++){
			    result3[j][i+3] = result2[j][i];
			    result3[j][i] = result2[j][i+3];
			  }
			for(i = 1 ; i < 4 ; i++)
			  for(j = 1 ; j < 10 ; j++)
			    result3[j][i] = result2[j][i];
		}

		if(a==b){

			for(i = 1 ; i < 10 ; i++)
			  for(j = 1 ; j < 10 ; j++)
			    result3[i][j] = result2[i][j];
		}

		/*cout << "result3:" << endl;
		for(i = 1 ; i < 10 ; i++,cout << endl)
		  for(j = 1 ; j < 10 ; j++)
		    cout << result3[i][j] << " ";*/

	}

	void Sudoku::rotate(int n){

		int resultA[10][10], resultB[10][10], resultC[10][10];
		
		int i, j;

		int degree = n % 4;


		for(i = 1 ; i < 10 ; i++)				//順時鐘旋轉90度第一次
		  for(j = 1 ; j < 10 ; j++)
		    resultA[j][9-(i-1)] = result3[i][j];
		for(i = 1 ; i < 10 ; i++)				//順時鐘旋轉90度第二次
		  for(j = 1 ; j < 10 ; j++)
		    resultB[j][9-(i-1)] = resultA[i][j];
		for(i = 1 ; i < 10 ; i++)				//順時鐘旋轉90度第三次
		  for(j = 1 ; j < 10 ; j++)
		    resultC[j][9-(i-1)] = resultB[i][j];

		if(degree == 0)
		for(i = 1 ; i < 10 ; i++)
		  for(j = 1 ; j < 10 ; j++){
		    result4[i][j] = result3[i][j];
		  }
		if(degree == 1)
		for(i = 1 ; i < 10 ; i++)
		  for(j = 1 ; j < 10 ; j++){
		    result4[i][j] = resultA[i][j];
		  }
		if(degree == 2)
		for(i = 1 ; i < 10 ; i++)
		  for(j = 1 ; j < 10 ; j++){
		    result4[i][j] = resultB[i][j];
		  }
		if(degree == 3)
		for(i = 1 ; i < 10 ; i++)
		  for(j = 1 ; j < 10 ; j++){
		    result4[i][j] = resultC[i][j];
		  }

		/*cout << "result4:" << endl;
		for(i = 1 ; i < 10 ; i++)
		  for(j = 1 ; j < 10 ; j++)
		    j == 9 ? cout << result4[i][j] << endl : cout << result4[i][j] << " ";*/
	}

	void Sudoku::flip(int n){

		
		int i, j;

		if(n == 1)						//水平翻轉
		for(i = 1 ; i < 10 ; i++)
		  for(j = 1 ; j < 10 ; j++)
		    result5[i][10-j] = result4[i][j];
		if(n == 0)						//垂直翻轉
		for(i = 1 ; i < 10 ; i++)
		  for(j = 1 ; j < 10 ; j++)
		    result5[10-i][j] = result4[i][j];

		/*cout << "result5:" << endl;
		for(i = 1 ; i < 10 ; i++)
		  for(j = 1 ; j < 10 ; j++)
		    j == 9 ? cout << result5[i][j] << endl : cout << result5[i][j] << " ";*/
  	}
	
	void Sudoku::transform(){
		srand(time(NULL));

		changeNum(rand() % 9 + 1, rand() % 9 +1);
		changeRow(rand() % 3, rand() % 3);
		changeCol(rand() % 3, rand() % 3);
		rotate(rand() % 101);
		flip(rand() % 2);

		int i, j;
		for(i = 1 ; i < 10 ; i++)
		  for(j = 1 ; j < 10 ; j++)
		    j == 9 ? cout << result5[i][j] << endl : cout << result5[i][j] << " ";

	}
	void Sudoku::checkQuestion(){

		int i, c = 0;
		for(i = 1 ; i < 82 ; i++)
		  if(board[i] != 0) {unavail[i] = 1, c++;}
		  else unavail[i] = 0;
		if(c == 2) {cout << "0" << endl; exit(1);}
		//if(c == 81) {cout << "1" << endl; temp = board; transform(); return;}
	}

	int Sudoku::check(int p){

		if(unavail[p] == 1) return 2;				//格子內已有題目數字

		int i, c = 0;
		for(i = (p-1)/9*9+1 ; c < 9 ; i++, c++)			//檢查列	
		  if(num == board[i]) return 0;
		c = 0;

		for(i = (p-1)%9+1 ; c < 9 ; i+=9, c++)			//檢查行
		  if(num == board[i]) return 0;
		c = 0;

		for(i = 1+(p-1)/9/3*27+(p-1)%9/3*3 ; c < 9 ; (c+1)%3==0 ? i+=7 : i++, c++)	//檢查塊
		  if(num == board[i]) return 0;

		return 1;						//不會發生衝突,可以填
	}

		void Sudoku::solve(){

		int p = 1, flag = 0, backward = 0, i;

		checkQuestion();

		while(1){

			start:

			if(check(p) == 2){

				if(p == 1){

					if(backward == 0){p++; continue;}
					if(backward == 1){
					
						if(flag == 0){cout << "0" << endl; break;}
						if(flag == 1){

							cout << "1" << endl;
							for(i = 1 ; i < 82 ; i++)
							  i%9 == 0 ? cout << temp[i] << endl : cout << temp[i] << " ";
							goto end;
						}
					}
				}

				if(p > 1 && p < 81){

					if(backward == 0){p++; continue;}
					if(backward == 1){p--; continue;}
				}

				if(p == 81){

					if(flag == 0){

						flag = 1;
						temp = board;
						p--;
						backward = 1;
						continue;
					}

					if(flag == 1){

						cout << "2" << endl;
						break;
					}
				}

			}

			if(check(p) != 2){

				if(p == 1){

					if(backward == 0)
					  for(num = 1 ; num < 10 ; num++){

					  	if(check(p) == 1){

							board[p] = num;
							p++;
							backward = 0;
							goto start;
						}

						if(check(p) == 0 && num == 9){

							cout << "0" << endl;
							goto end;
						}
					  }

					if(backward == 1){
					  if(board[p] == 9){

					  	if(flag == 0){

							cout << "0" << endl;
							goto end;
						}

						if(flag == 1){

							cout << "1" << endl;
							for(i = 1 ; i < 82 ; i++)
							  i%9 == 0 ? cout << temp[i] << endl : cout << temp[i] << " ";
							goto end;
						}
					  }
					  for(num = board[p]+1, board[p] = 0 ; num < 10 ; num++){

					  	if(check(p) == 1){

							board[p] = num;
							p++;
							backward = 0;
							goto start;
						}

						if(check(p) == 0 && num == 9){

							if(flag == 0){

								cout << "0" << endl;
								goto end;
							}

							if(flag == 1){

								cout << "1" << endl;
								for(i = 1 ; i < 82 ; i++)
								  i%9 == 0 ? cout << temp[i] << endl : cout << temp[i] << " ";
								goto end;
							}
						}
					  }
					}
				}

				if(p > 1 && p < 81){

					if(backward == 0)
					  for(num = 1 ; num < 10 ; num++){

					  	if(check(p) == 1){

							board[p] = num;
							p++;
							backward = 0;
							goto start;
						}

						if(check(p) == 0 && num == 9){

							board[p] = 0;
							p--;
							backward = 1;
							goto start;
						}
					  }

					if(backward == 1)
					  if(board[p] == 9){

					  	board[p] = 0;
						p--;
						backward = 1;
						goto start;
					  }
					  for(num = board[p]+1, board[p] = 0 ; num < 10 ; num++){

					  	if(check(p) == 1){

							board[p] = num;
							p++;
							backward = 0;
							goto start;
						}

						if(check(p) == 0 && num == 9){

							board[p] = 0;
							p--;
							backward = 1;
							goto start;
						}
					  }
				}

				if(p == 81){

					for(num = 1 ; num < 10 ; num++){

						if(check(p) == 1){

							board[p] = num;
							if(flag == 0){

								flag = 1;
								temp = board;
								board[p] = 0;
								p--;
								backward = 1;
								goto start;
							}

							if(flag == 1){

								cout << "2" << endl;
								goto end;
							}
						}

						if(check(p) == 0 && num == 9){

							board[p] = 0;
							p--;
							backward = 1;
							goto start;
						}
					}
				}
			}

		}

		end:;
	}


