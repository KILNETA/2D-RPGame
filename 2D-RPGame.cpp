// 標頭檔 

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>  

// 簡化程式碼 

using namespace std;



int main()// 開始 執行程式 
{
	
	// 設定初始值 與 宣告變數名稱 
	
	char run ; // 電腦 & 玩家出拳  
	
	int run_x=6 , run_y=6 , x=1 , y=1 ;
	
	int start_input , end=0 ; // 控制 開始 
	
	int position ; // 
	
	bool start_output = true , validInput ; // bool 控制 是 與 否 
	
	srand( time(0) ); // 擷取現在 時間 當參數 
	
	//以下開始進入遊戲程序 
	
//	cout << "歡迎遊玩 \"野球拳\" 小遊戲" << endl << endl ; // 歡迎 與 規則介紹 
//	cout << "規則:" << endl ;
//	cout << "玩家與電腦 可穿1~5件衣服" << endl ;
//	cout << "選擇好衣服數後 遊戲即開始" << endl ;
//	cout << "猜拳 敗者脫一件 勝者不變" << endl << endl ;
	
	cout << "請輸入 -1 開始遊戲" << endl ;
	
	while(start_output) //判斷 遊戲開始 
	{
	cin >> start_input ;
	
	if(start_input == -1) //用 bool 讓遊戲開始
		{
			start_output = false ;
		}
	}//判斷 遊戲開始
	
	cout << endl ;
	
	validInput = true ;
	
	while (run != 'e' && run !='E' )
	{
		y=1 ;
		
		if (validInput)
		{
			while ( y <= 11 )
			{
				while ( x <= 11)
				{
					if(x != run_x || y != run_y)
					{
						if(x != 3 || y != 4)
						{
							cout << " 口" ;
						}
						else if(x == 3 && y == 4)
						{
							cout << " 民" ;
						}
					}
					else if(x == run_x && y == run_y)
					{
						cout << " 我" ;
					}
					x++	;
				}
				x=1;
				cout << endl ;
				y++ ;
			}
		} 
		
		cout << endl << endl << endl ;
		
		validInput = true ;
		
		cout << "請輸入 W A S D 控制方向 輸入 E 結束遊戲 " << endl ;
		cout << "(可一次輸入欲走之步數) (忽視大小寫)" << endl ; 
		cin >> run ;
		
		switch(run) // 判斷玩家出拳的結果 
		{ 
			case 'w' : 
				run_y-- ;
				if(run_y < 1 )
				{
					run_y++ ;
					cout << "                                        走不過去了 " << endl ;
				}
				if( run_x == 3 && run_y == 4 )
				{
					run_y++ ;
					cout << "                                        民 : 他的手可以穿過我的巴巴 到底是為什麼 " << endl ;
				}
				break ;
						 
			case 's' :
				run_y++ ;
				if(run_y > 11 )
				{
					run_y-- ;
					cout << "                                        走不過去了 " << endl ;
				}
				if( run_x == 3 && run_y == 4 )
				{
					run_y-- ;
					cout << "                                        民 : 他的手可以穿過我的巴巴 到底是為什麼 " << endl ;
				}
				break ;
						 
			case 'a' :
				run_x-- ;
				if(run_x < 1 )
				{
					run_x++ ;
					cout << "                                        走不過去了 " << endl ;
				}
				if( run_x == 3 && run_y == 4 )
				{
					run_x++ ;
					cout << "                                        民 : 他的手可以穿過我的巴巴 到底是為什麼 " << endl ;
				}
				break ;
				
			case 'd' :
				run_x++ ;
				if(run_x > 11 )
				{
					run_x-- ;
					cout << "                                        走不過去了 " << endl ;
				}
				if( run_x == 3 && run_y == 4 )
				{
					run_x-- ;
					cout << "                                        民 : 他的手可以穿過我的巴巴 到底是為什麼 " << endl ;
				}
				break ;
				
			case 'W' : 
				run_y-- ;
				if(run_y < 1 )
				{
					run_y++ ;
					cout << "                                        走不過去了 " << endl ;
				}
				if( run_x == 3 && run_y == 4 )
				{
					run_y++ ;
					cout << "                                        民 : 他的手可以穿過我的巴巴 到底是為什麼 " << endl ;
				}
				break ;
						 
			case 'S' :
				run_y++ ;
				if(run_y > 11 )
				{
					run_y-- ;
					cout << "                                        走不過去了 " << endl ;
				}
				if( run_x == 3 && run_y == 4 )
				{
					run_y-- ;
					cout << "                                        民 : 他的手可以穿過我的巴巴 到底是為什麼 " << endl ;
				}
				break ;
						 
			case 'A' :
				run_x-- ;
				if(run_x < 1 )
				{
					run_x++ ;
					cout << "                                        走不過去了 " << endl ;
				}
				if( run_x == 3 && run_y == 4 )
				{
					run_x++ ;
					cout << "                                        民 : 他的手可以穿過我的巴巴 到底是為什麼 " << endl ;
				}
				break ;
				
			case 'D' :
				run_x++ ;
				if(run_x > 11 )
				{
					run_x-- ;
					cout << "                                        走不過去了 " << endl ;
				}
				if( run_x == 3 && run_y == 4 )
				{
					run_x-- ;
					cout << "                                        民 : 他的手可以穿過我的巴巴 到底是為什麼 " << endl ;
				}
				break ;
					
			case 'e'  : //玩家放棄此局 
				cout << endl ;
				cout << "下次再來玩喔 ㄅㄅ" << endl << endl ;		
				break ;
				
			case 'E'  : //玩家放棄此局 
				cout << endl ;	
				cout << "下次再來玩喔 ㄅㄅ" << endl << endl ;	
				break ;
				
			default: 
				cout << "-----error-----請不要亂出-----error-----" << endl << endl ;
				validInput = false ; // 出拳 不合規
		}
		
	}
	
	while( end != -1 )
		{
			cout << "請輸入 (-1 離開遊戲)" << endl ;
			cin >> end ;
		}
	
}
