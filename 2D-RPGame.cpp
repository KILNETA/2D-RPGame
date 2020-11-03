// 標頭檔 

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>  
#include <conio.h>

// 簡化程式碼 

using namespace std;

void map_main( int run_x , int run_y , bool validInput );// 地圖函式 
void bag_main( int run_x , int run_y , bool validInput );// 背包函式

int W_run( int run_x , int run_y );// 向上走函式
int S_run( int run_x , int run_y );// 向下走函式
int A_run( int run_x , int run_y );// 向左走函式
int D_run( int run_x , int run_y );// 向右走函式

int one_bag   ();
int two_bag   ();
int three_bag ();
int four_bag  ();
int five_bag  ();
int six_bag   ();
int seven_bag ();
int eight_bag ();
int nine_bag  ();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////主遊戲函式 

int main()// 開始 執行程式 
{
	
	// 設定初始值 與 宣告變數名稱 
	
	int run_x=6 , run_y=6 ;
	
	int start_input , end=0 ; // 控制 開始 
	
	int position , button ; // 
	
	bool validInput ; // bool 控制 是 與 否 
	
	srand( time(0) ); // 擷取現在 時間 當參數 
	
	//以下開始進入遊戲程序 
	
	cout << "歡迎遊玩 \"mini RPGame\" 小遊戲" << endl << endl ; // 歡迎 與 基本操作介紹 
	cout << "      基本操作:" << endl ;
	cout << "      輸入 W A S D 控制方向  |  輸入 E 看背包  |  輸入 Q 結束遊戲" << endl;
	cout << "      (可一次輸入欲走之步數) (忽視大小寫)" << endl << endl ; 
	
	cout << " Enter 開始遊戲" << endl ;
	
	while (1)//判斷 遊戲開始
		{
            start_input = getch();//使用_getch()函??取按下的?值
            if (start_input == 13)
			{
				break; 
			}
    	}//判斷 遊戲開始
	
	system("cls"); // 清屏
		
	validInput = true ; //輸入正確 預設執行 
	
	cout << endl << endl ;
	map_main( run_x , run_y , validInput ); //第一次顯示地圖 
	
	while (validInput)
	{
		button = 0 ;
		while (1)
		{
            button = getch();// 讀取玩家按鍵 
            if (button != 0)
			{
				break; 
			}
    	}
		
		switch(button) // 判斷玩家按鍵輸入的結果 
		{ 
			case 119 : 
				run_y-- ;// 向上走
				run_y = W_run(run_x , run_y );// 回傳 向上走函式值run_y
				map_main( run_x , run_y , validInput );//運行 地圖函式
				break ;
						 
			case 115 :
				run_y++ ;// 向下走
				run_y = S_run(run_x , run_y );// 回傳 向上走函式 值run_y
				map_main( run_x , run_y , validInput );//運行 地圖函式
				break ;
						 
			case 97:
				run_x-- ;// 向左走
				run_x = A_run(run_x , run_y);// 回傳 向上走函式 值run_x 
				map_main( run_x , run_y , validInput );//運行 地圖函式
				break ;
				
			case 100 :
				run_x++ ;// 向右走
				run_x = D_run(run_x , run_y );// 回傳 向上走函式 值run_x 
				map_main( run_x , run_y , validInput );//運行 地圖函式
				break ;
					
			case 27  : //玩家結束遊戲 
				cout << endl ;	
				cout << "                                        下次再來玩喔 ㄅㄅ" << endl << endl ;
				validInput = false ;
				break ;
				
			case 101  : //開啟背包 
				system("cls");
				cout << endl ;
				cout << "                                        開起背包" << endl ; 
				bag_main( run_x , run_y , validInput );	//運行 包包函式 
				break ;
				
			default:
				break ; 
			
		}
	}
	while( end != -1 ) //關閉視窗 
	{
			cout << "請輸入 (-1 關閉視窗)" << endl ;
			cin >> end ;
	}
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 地圖函式



void map_main( int run_x , int run_y , bool validInput ) // 地圖函式
{
	int x=1 , y=1 ;
	
	if (validInput)
	{
		cout << "                         村莊地圖" << endl << endl ;
		for(; y<=11 ; y++ )
		{
			for(; x<=11 ; x++ )
			{
				if(x == 3 && y == 4) //顯示 農民 
				{
					cout << " 農" ;
				}
				else if(x == 8 && y == 6) //顯示 商人 
				{
					cout << " 商" ;
				}
				else if(x == 3 && y == 9) //顯示 水井 
				{
					cout << " 井" ;
				}
				else if(x == 6 && y == 2) //顯示 暴徒 
				{
					cout << "aka" ;
				}
				else if(x == run_x && y == run_y) //顯示 玩家 
				{
					cout << " 我" ;
				}
				else if(x <= 5 && y >= 6) //顯示 農田 
				{
					cout << " 艸" ;
				}
				else                      //顯示 道路 
				{
					cout << " 口" ;
				}
			}
			x=1;
			cout << endl ;
		}
	} 
	cout << endl << endl ;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 背包函式



void bag_main( int run_x , int run_y , bool validInput )// 背包函式
{
	int take;
	bool validInput_bag ;
	
	cout << "                      包 包" << endl << endl ;
	
	for(int z=1; z<=9 ; z++ )
	{
		cout << " 空" ; 
	} 

	cout << endl << " 1  2  3  4  5  6  7  8  9" << endl ; // 顯示 包包格編號 
	
	cout << "                                        輸入編號拿取物品 E 關閉包包" << endl ;
	
	validInput_bag = true ;
	
	while(validInput_bag)
	{
		
		take = 0 ;
		while (1)
		{
            take = getch();// 讀取玩家按鍵 
            if (take != 0)
			{
				break; 
			}
    	}
    	
		switch(take) // 判斷玩家按鍵輸入的結果 
		{ 
			case 49 : 
				cout << "                                        拿取 1" << endl ; 
				validInput_bag = false ;
				break ;
				 
			case 50 : 
				cout << "                                        拿取 2" << endl ; 
				validInput_bag = false ;
				break ;
			
			case 51 : 
				cout << "                                        拿取 3" << endl ; 
				validInput_bag = false ;
				break ;
			
			case 52 : 
				cout << "                                        拿取 4" << endl ;
				validInput_bag = false ;
				break ;
				
			case 53 : 
				cout << "                                        拿取 5" << endl ; 
				validInput_bag = false ;
				break ;
				 
			case 54 : 
				cout << "                                        拿取 6" << endl ; 
				validInput_bag = false ;
				break ;
			
			case 55 : 
				cout << "                                        拿取 7" << endl ; 
				validInput_bag = false ;
				break ;
			
			case 56 : 
				cout << "                                        拿取 8" << endl ; 
				validInput_bag = false ;
				break ;
				
			case 57 : 
				cout << "                                        拿取 9" << endl ; 
				validInput_bag = false ;
				break ;
				
			case 101 : 
				cout << endl << "                                        關閉背包" << endl ; 
				validInput_bag = false ;
				break ;
			
			default:
				break ;
		} 
	}
	_sleep(750); // 停留0.75秒 
	system("cls"); // 清屏 
	cout << endl << endl ;
	map_main( run_x , run_y , validInput ); //運行 地圖函式 
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 向上走函式



int W_run(int run_x , int run_y )
{ 
	system("cls"); // 清屏
	if(run_y < 1 )
	{
		run_y++ ;
		cout << "走不過去了 " ;
	}
	if( run_x == 3 && run_y == 4 )
	{
		run_y++ ;
		cout << "農民 : 他的手可以穿過我的巴巴 到底是為什麼 " ;
	}
	if( run_x == 8 && run_y == 6 )
	{
		run_y++ ;
		cout << "商人 : 來看看新貨 " ;
	}
	if( run_x == 3 && run_y == 9 )
	{
		run_y++ ;
		cout << "os : 又深又黑 有點恐怖 " ;
	}
	if( run_x == 6 && run_y == 2 )
	{
		run_y++ ;
		cout << "台北爆徒 : 阿我就怕被罵嘛" ;
	}
	cout << endl << endl ;
	return run_y ;
}
		


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 向下走函式


			 
int S_run(int run_x , int run_y )
{ 
	system("cls"); // 清屏
	if(run_y > 11 )
	{
		run_y-- ;
		cout << "走不過去了 " ;
	}
	if( run_x == 3 && run_y == 4 )
	{
		run_y-- ;
		cout << "農民 : 他的手可以穿過我的巴巴 到底是為什麼 " ;
	}
	if( run_x == 8 && run_y == 6 )
	{
		run_y-- ;
		cout << "商人 : 來看看新貨 " ;
	}
	if( run_x == 3 && run_y == 9 )
	{
		run_y-- ;
		cout << "os : 又深又黑 有點恐怖 " ;
	}
	if( run_x == 6 && run_y == 2 )
	{
		run_y-- ;
		cout << "台北爆徒 : 阿我就怕被罵嘛" ;
	}
	cout << endl << endl ;
	return run_y ;
}
		


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 向左走函式


				 
int A_run(int run_x , int run_y )
{ 
	system("cls"); // 清屏
	if(run_x < 1 )
	{
		run_x++ ;
		cout << "走不過去了 " ;
	}
	if( run_x == 3 && run_y == 4 )
	{
		run_x++ ;
		cout << "農民 : 他的手可以穿過我的巴巴 到底是為什麼 " ;
	}
	if( run_x == 8 && run_y == 6 )
	{
		run_x++ ;
		cout << "商人 : 來看看新貨 " ;
	}
	if( run_x == 3 && run_y == 9 )
	{
		run_x++ ;
		cout << "os : 又深又黑 有點恐怖 " ;
	}
	if( run_x == 6 && run_y == 2 )
	{
		run_x++ ;
		cout << "台北爆徒 : 阿我就怕被罵嘛" ;
	}
	cout << endl << endl ;
	return run_x ;
}
			


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 向右走函式


	
int D_run(int run_x , int run_y )
{ 
	system("cls"); // 清屏
	if(run_x > 11 )
	{
		run_x-- ;
		cout << "走不過去了 " ;
	}
	if( run_x == 3 && run_y == 4 )
	{
		run_x-- ;
		cout << "農民 : 他的手可以穿過我的巴巴 到底是為什麼 " ;
	}
	if( run_x == 8 && run_y == 6 )
	{
		run_x-- ;
		cout << "商人 : 來看看新貨 " ;
	}
	if( run_x == 3 && run_y == 9 )
	{
		run_x-- ;
		cout << "os : 又深又黑 有點恐怖 " ;
	}
	if( run_x == 6 && run_y == 2 )
	{
		run_x-- ;
		cout << "台北爆徒 : 阿我就怕被罵嘛" ;
	}
	cout << endl << endl ;
	return run_x ;
}
			


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 包包欄 



int one_bag   ()
{
	
} 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 1 
int two_bag   ()
{
	
} 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 2 
int three_bag ()
{
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 3 
int four_bag  ()
{
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 4 
int five_bag  ()
{
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 5 
int six_bag   ()
{
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 6 
int seven_bag ()
{
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 7 
int eight_bag ()
{
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 8 
int nine_bag  () 
{
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 9 









