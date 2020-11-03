// 標頭檔 

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>  

// 簡化程式碼 

using namespace std;

void run_main( int x ,int y, int run_x , int run_y , bool validInput ,char run );// 地圖函式 
void bag_main();// 背包函式

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////主遊戲函式 

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
	
	cout << "歡迎遊玩 \"mini RPGame\" 小遊戲" << endl << endl ; // 歡迎 與 基本操作介紹 
	cout << "      基本操作:" << endl ;
	cout << "      輸入 W A S D 控制方向  |  輸入 E 看背包  |  輸入 Q 結束遊戲" << endl;
	cout << "      (可一次輸入欲走之步數) (忽視大小寫)" << endl << endl ; 
	
	cout << "請輸入 -1 開始遊戲" << endl ;
	
	while(start_output) //判斷 遊戲開始 
	{
	cin >> start_input ;
	
	if(start_input == -1) //用 bool 讓遊戲開始
		{
			start_output = false ;
		}
	}//判斷 遊戲開始
	
	cout << endl << endl << endl ;
		
	validInput = true ; //輸入正確 預設執行 
	
	run_main( x , y , run_x , run_y , validInput , run ); //第一次顯示地圖 
	
	while (validInput)
	{
		
		cin >> run ;//玩家輸入操作 
		
		switch(run) // 判斷玩家輸入的結果 
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
				run_main( x , y , run_x , run_y , validInput , run );
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
				run_main( x , y , run_x , run_y , validInput , run );
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
				run_main( x , y , run_x , run_y , validInput , run );
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
				run_main( x , y , run_x , run_y , validInput , run );
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
				run_main( x , y , run_x , run_y , validInput , run );
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
				run_main( x , y , run_x , run_y , validInput , run );
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
				run_main( x , y , run_x , run_y , validInput , run );
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
				run_main( x , y , run_x , run_y , validInput , run );
				break ;
					
			case 'q'  : //玩家放棄此局 
				cout << endl ;
				cout << "                                        下次再來玩喔 ㄅㄅ" << endl << endl ;	
				validInput = false ;	
				break ;
				
			case 'Q'  : //玩家放棄此局 
				cout << endl ;	
				cout << "                                        下次再來玩喔 ㄅㄅ" << endl << endl ;
				validInput = false ;
				break ;
				
			case 'e'  : //開啟背包 
				cout << endl ;
				bag_main();
				cout << endl << endl ;		
				break ;
				
			case 'E'  : //開啟背包
				cout << endl ;	
				bag_main();
				cout << endl << endl ;
				break ;
				
			default: 
				cout << "                                        -----error-----請不要亂出-----error-----" << endl << endl ;
				validInput = false ; // 輸入 不合規
		}
	}
	while( end != -1 ) //關閉視窗 
	{
			cout << "請輸入 (-1 關閉視窗)" << endl ;
			cin >> end ;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////地圖函式

void run_main( int x ,int y, int run_x , int run_y , bool validInput ,char run ) // 地圖函式
{
	if (validInput)
	{
		cout << "                         村莊地圖" << endl << endl ;
		for(; y<=11 ; y++ )
		{
			for(; x<=11 ; x++ )
			{
				if(x != run_x || y != run_y)//顯示 路 
				{
					if(x != 3 || y != 4)
					{
						cout << " 口" ;
					}
					else if(x == 3 && y == 4) //顯示 村民 
					{
						cout << " 民" ;
					}
				}
				else if(x == run_x && y == run_y) //顯示 玩家 
				{
					cout << " 我" ;
				}
			}
			x=1;
			cout << endl ;
		}
	} 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////背包函式

void bag_main()// 背包函式
{
	int take;
	
	cout << "                      包 包" << endl << endl ;
	
	for(int z=1; z<=9 ; z++ )
	{
		cout << " 空" ; 
	} 
	cout << endl ;

	cout << " 1  2  3  4  5  6  7  8  9" ; 
		
	cout << endl ;
	
	cout << "                                        輸入編號拿取物品 -1關閉包包" << endl ;
	
	cin >> take ;
	
	switch(take) // 判斷玩家輸入的結果 
		{ 
			case 1 : 
				cout << "                                        拿取 1" << endl ; 
				break ;
				 
			case 2 : 
				cout << "                                        拿取 2" << endl ; 
				break ;
			
			case 3 : 
				cout << "                                        拿取 3" << endl ; 
				break ;
			
			case 4 : 
				cout << "                                        拿取 4" << endl ; 
				break ;
				
			case 5 : 
				cout << "                                        拿取 5" << endl ; 
				break ;
				 
			case 6 : 
				cout << "                                        拿取 6" << endl ; 
				break ;
			
			case 7 : 
				cout << "                                        拿取 7" << endl ; 
				break ;
			
			case 8 : 
				cout << "                                        拿取 8" << endl ; 
				break ;
				
			case 9 : 
				cout << "                                        拿取 9" << endl ; 
				break ;
				
			case 0 : 
				cout << "                                        關閉背包" << endl ; 
				break ;
			
			default: 
				cout << "                                        -----error-----請不要亂出-----error-----" << endl << endl ;
		}
}




