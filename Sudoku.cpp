#include "Sudoku.h"

using namespace std;



	void Sudoku::giveQuestion(){

		cout << "0 0 0 0 0 0 0 0 0" << endl;
		cout << "0 0 0 0 0 0 0 0 0" << endl;
		cout << "0 0 0 0 0 0 0 0 8" << endl;
		cout << "0 0 0 0 0 0 0 0 0" << endl;
		cout << "0 0 0 0 0 0 0 0 0" << endl;
		cout << "0 0 0 0 0 0 8 0 0" << endl;
		cout << "0 0 0 0 0 0 0 9 0" << endl;
		cout << "0 0 0 0 0 8 0 0 0" << endl;
		cout << "0 0 0 8 0 0 0 0 0" << endl;
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

		int i;
		temp1 = board;
		temp2.clear();
		temp2.reserve(82);
		temp2.resize(82,0);

		for(i = 1 ; i < 82 ; i++){

			if(temp1[i] == a)
			  temp2[i] = b;
			if(temp1[i] == b)
			  temp2[i] = a;
			if((temp1[i]!=a) && (temp1[i]!=b))
			  temp2[i] = temp1[i];
		}

		board = temp2;
	}

 	void Sudoku::changeRow(int a, int b){
		
		if(a == b) return;

		temp1 = board;

		int i;
		if(a==0&&b==1 || a==1&&b==0){

			for(i = 1 ; i <= 27 ; i++)
			  board[i+27] = temp1[i];
			for(i = 28 ; i <= 54 ; i++)
			  board[i-27] = temp1[i];
		}

		if(a==0&&b==2 || a==2&&b==0){

			for(i = 1 ; i <= 27 ; i++)
			  board[i+54] = temp1[i];
			for(i = 55 ; i <= 81 ; i++)
			  board[i-54] = temp1[i];
		}

		if(a==1&&b==2 || a==2&&b==1){

			for(i = 28 ; i <= 54 ; i++)
			  board[i+27] = temp1[i];
			for(i = 55 ; i <= 81 ; i++)
			  board[i-27] = temp1[i];
		}

	}

	void Sudoku::changeCol(int a, int b){

		if(a == b) return;

		temp1 = board;
		int i, j = 1;
		if(a==0&&b==1 || a==1&&b==0){

			for(i = 1 ; i <= 75 ; j%3==0 ? i+=7 : i++, j++)
			  board[i+3] = temp1[i];
			for(i = 4 ; i <= 78 ; j%3==0 ? i+=7 : i++, j++)
			  board[i-3] = temp1[i];
		}	
		if(a==0&&b==2 || a==2&&b==0){

			for(i = 1 ; i <= 75 ; j%3==0 ? i+=7 : i++, j++)
			  board[i+6] = temp1[i];
			for(i = 7 ; i <= 81 ; j%3==0 ? i+=7 : i++, j++)
			  board[i-6] = temp1[i];
		}
		if(a==2&&b==1 || a==1&&b==2){

			for(i = 4 ; i <= 78 ; j%3==0 ? i+=7 : i++, j++)
			  board[i+3] = temp1[i];
			for(i = 7 ; i <= 81 ; j%3==0 ? i+=7 : i++, j++)
			  board[i-3] = temp1[i];
		}

	}

	void Sudoku::rotate(int n){
		
		int i, j, k, l, m, r = n % 4;

		if(r == 0) return;
		for(i = 1 ; i <= r ; i++){

			temp1 = board;
			for(j = 0, k = 0 ; j <= 72 ; j+=9, k--)
			 for(l = 1, m = 9 ; l <= 9 ; l++, m+=9)
			   board[m+k] = temp1[l+j];
		}

	}

	void Sudoku::flip(int n){

		temp1 = board;
		int i, j, k, l;

		if(n == 0)
		for(k = 0, l = 0 ; k <= 27 ; k+=9, l-=9)
		 for(i = 1, j = 73 ; i <= 9 ; i++, j++){
		   board[j+l] = temp1[i+k];
		   board[i+k] = temp1[j+l];}
		if(n == 1)
		for(k = 0, l = 0 ; k <= 3 ; k++, l--)
		 for(i = 1, j = 9 ; i <= 73 ; i+=9, j+=9){
		   board[j+l] = temp1[i+k];
		   board[i+k] = temp1[j+l];}
  	}
	
	void Sudoku::transform(){

		srand(time(NULL));

		changeNum(rand() % 9 + 1, rand() % 9 +1);
		changeRow(rand() % 3, rand() % 3);
		changeCol(rand() % 3, rand() % 3);
		rotate(rand() % 101);
		flip(rand() % 2);

		//changeNum(1, 2);
		//changeRow(0, 1);
		//changeCol(0, 1);
		//rotate(2);
		//flip(1);

		int i;
		for(i = 1 ; i < 82 ; i++)
		  i%9==0?cout << board[i]<<endl:cout<<board[i]<<" ";

	}
	void Sudoku::checkQuestion(){

		int i, c = 0;
		for(i = 1 ; i < 82 ; i++)
		  if(board[i] != 0) {unavail[i] = 1, c++;}
		  else unavail[i] = 0;

		if(c == 2) {cout << "0" << endl; exit(1);}
		//if(c == 81) {cout << "1" << endl; temp = board; transform(); }
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
							
							board = temp;
							cout << "1" << endl;
							for(i = 1 ; i < 82 ; i++)
							  i%9 == 0 ? cout << board[i] << endl : cout << board[i] << " ";
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

							board = temp;
							cout << "1" << endl;
							for(i = 1 ; i < 82 ; i++)
							  i%9 == 0 ? cout << board[i] << endl : cout << board[i] << " ";
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

								board = temp;
								cout << "1" << endl;
								for(i = 1 ; i < 82 ; i++)
								  i%9 == 0 ? cout << board[i] << endl : cout << board[i] << " ";
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



