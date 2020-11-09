// 標頭檔 

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>  
#include <conio.h>
#include <stdio.h>

// 簡化程式碼 

using namespace std;

typedef struct R2
{
	int A = 0;
	int B = 0;
};


void map_main( int run_x , int run_y );// 地圖函式 
int bag_main( int B1 , int B2 , int B3 , int B4 , int B5 , int B6 , int B7 , int B8 , int B9 );// 背包函式
void help_main(  );// 操作提示清單函式
void situation_main( string name , int blood );// 自我狀況清單函式

R2 W_run( int run_x , int run_y , int task_yes);// 向上走函式
R2 S_run( int run_x , int run_y , int task_yes);// 向下走函式
R2 A_run( int run_x , int run_y , int task_yes);// 向左走函式
R2 D_run( int run_x , int run_y , int task_yes);// 向右走函式

/////////////////////////////////////////////////////////// npc函式
int npc_aka( int run_x , int run_y , int task_yes );
int npc_businessman(  );
int npc_farmer(  );
int npc_well(  );

/////////////////////////////////////////////////////////// 任務函式
int task_npc_aka_mussel( int B1 , int B2 , int B3 , int B4 , int B5 , int B6 , int B7 , int B8 , int B9 );

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////主遊戲函式 

int main()// 開始 執行程式  
{
	
	// 設定初始值 與 宣告變數名稱 
	
	R2 x;
	
	string name ;

	
	int blood = 100 ;
	
	int run_x=6 , run_y=6 ;
	
	int start_input , end=0 ; // 控制 開始 
	
	int position , button ; // 
	
	int B1=0 , B2=0 , B3=0 , B4=0 , B5=0 , B6=0 , B7=0 , B8=0 , B9=0 ;
	
	int task_yes = 0 ;
	
	bool validInput ; // bool 控制 是 與 否 
	
	srand( time(0) ); // 擷取現在 時間 當參數 
	
	//以下開始進入遊戲程序 
	
	cout << "歡迎遊玩 \"mini RPGame\" 小遊戲" << endl << endl ; // 歡迎 與 基本操作介紹 
	cout << "      基本操作:" << endl ;
	cout << "      W A S D 控制方向  |  E 開背包 " << endl << "      Esc 結束遊戲  |  ? 操作提示" << endl << endl;
	
	cout << "請輸入你的角色名字" << endl << endl ;
	cin >> name ;
	
	cout << " Enter 開始遊戲" << endl ;
	
	while (1)// 讀取玩家按鍵  // 控制遊戲開始
		{
            start_input = getch();// 讀取玩家按鍵 
            if (start_input == 13)
			{
				break; 
			}
    	}// 讀取玩家按鍵 
	
	system("cls"); // 清屏
		
	validInput = true ; //輸入正確 預設執行 
	
	cout << endl << endl ;
	map_main( run_x , run_y ); //第一次顯示地圖 
	
	while (validInput)// 判斷 遊戲操作 是否要結束 
	{
		task_yes = 0 ;
		button = 0 ;
		
		while (1) // 讀取玩家按鍵 // 控制操作 
		{
            button = getch();// 讀取玩家按鍵 
            if (button != 0)
			{
				break; 
			}
    	} // 讀取玩家按鍵 
		
		switch(button) // 判斷玩家按鍵輸入的結果 
		{ 
			case 119 : //按 W 
			{ 
				run_y-- ;// 向上走
				
				x = W_run(run_x , run_y , task_yes ) ;// 回傳 向上走函式值run_y  任務值 task_yes
				task_yes = x.A ;
				run_y = x.B ;
				
				switch(task_yes) // 判斷有無 任務 
				{ 
					case 1 : 
						B1 = task_npc_aka_mussel( B1 , B2 , B3 , B4 , B5 , B6 , B7 , B8 , B9 ) ;
					break ;
				}
				map_main( run_x , run_y );//運行 地圖函式
				break ;
			} 
						 
			case 115 : //按 S 
			{ 
				run_y++ ;// 向下走
				
				x = S_run(run_x , run_y , task_yes ) ;// 回傳 向下 走函式值run_y  任務值 task_yes
				task_yes = x.A ;
				run_y = x.B ;
				
				switch(task_yes) // 判斷有無 任務 
				{ 
					case 1 : 
						B1 = task_npc_aka_mussel( B1 , B2 , B3 , B4 , B5 , B6 , B7 , B8 , B9 ) ;
					break ;
				}
				map_main( run_x , run_y );//運行 地圖函式
				break ;
			} 
						 
			case 97:   //按 A 
			{ 
				run_x-- ;// 向左走
				x = A_run(run_x , run_y , task_yes ) ;// 回傳 向左 走函式值run_x  任務值 task_yes 
				task_yes = x.A ;
				run_x = x.B ;
				switch(task_yes) // 判斷有無 任務 
				{ 
					case 1 : 
						B1 = task_npc_aka_mussel( B1 , B2 , B3 , B4 , B5 , B6 , B7 , B8 , B9 ) ;
					break ;
				}
				map_main( run_x , run_y );//運行 地圖函式
				break ;
			} 
				
			case 100 : //按 D 
			{
				run_x++ ;// 向右走
				x = D_run(run_x , run_y , task_yes ) ;// 回傳 向右 走函式值run_x 任務值 task_yes 
				task_yes = x.A ;
				run_x = x.B ;
				switch(task_yes) // 判斷有無 任務 
				{ 
					case 1 : 
						B1 = task_npc_aka_mussel( B1 , B2 , B3 , B4 , B5 , B6 , B7 , B8 , B9 ) ;
					break ;
				}
				map_main( run_x , run_y );//運行 地圖函式
				break ;
			}
					
			case 27  : //玩家結束遊戲 
			{
				cout << endl ;	
				cout << "                                        下次再來玩喔 ㄅㄅ" << endl << endl ;
				validInput = false ;
				break ;
			}
				
			case 101  : //開啟背包 
			{
				system("cls");
				cout << endl ;
				cout << "                                        開起背包" << endl ; 
				bag_main( B1 , B2 , B3 , B4 , B5 , B6 , B7 , B8 , B9 );	//運行 包包函式 
				map_main( run_x , run_y ); //運行 地圖函式 
				break ;
			} 
			
			case 63  : //開啟操作提示清單 
			{
				system("cls");
				cout << endl ;
				cout << "                                        開起 操作提示清單" << endl ; 
				help_main();	//運行 操作提示清單函式 
				map_main( run_x , run_y );//運行 地圖函式
				break ;
			} 
				
			case 99  : //開啟自我狀況清單
			{
				system("cls");
				cout << endl ;
				cout << "                                        開起 自我狀況清單" << endl ; 
				situation_main( name , blood );	//運行 自我狀況清單函式 
				map_main( run_x , run_y );//運行 地圖函式
				break ;
			} 
				
			default: //無效鍵 
			{ 
				break ;
			} 
		}
	}
	cout << "再按一次 Esc 關閉介面" << endl ; 
	while (1) // 讀取玩家按鍵 // Esc 關閉介面
	{ 
		int END_button=0 ;
        END_button = getch();// 讀取玩家按鍵 
        if (END_button == 27)
		{
			break; 
		}
    } // 讀取玩家按鍵 
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 地圖函式



void map_main( int run_x , int run_y ) // 地圖函式
{
	int x=1 , y=1 ;

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
	cout << endl << endl ;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 操作提示清單函式



void help_main()// 操作提示清單函式 
{
	cout << "      基本操作:" << endl ;
	cout << "      W A S D 控制方向  |  E 開背包 " << endl << "      Esc 結束遊戲  |  ? 操作提示" << endl << endl ;
	cout << "      Esc 關閉提示" << endl ;
	int help_Esc ;
	
	while (help_Esc != 27)// 讀取玩家按鍵 // 控制 離開操作提示清單 操作
		{
            help_Esc = getch();// 讀取玩家按鍵 
    	}// 讀取玩家按鍵
    system("cls"); // 清屏
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 背包函式



void situation_main( string name , int blood )// 自我狀況清單函式
{
	cout << "      角色狀況: " << endl << endl ;
	cout << "      角色名稱: " << name << endl ;
	cout << "      角色血量: " << blood << endl ;
	/*cout << "      手部: " <<  << "      裝備: " << / << endl ;
	cout << "      金錢: " <<  ;
	cout << "      稱號: " << / << endl << endl ; */
	
	cout << "      Esc 關閉清單" << endl ;
	int situation_Esc ;
	
	while (situation_Esc != 27)// 讀取玩家按鍵 // 控制 離開操作提示清單 操作
		{
            situation_Esc = getch();// 讀取玩家按鍵 
    	}// 讀取玩家按鍵
    system("cls"); // 清屏
} 



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 背包函式



int bag_main( int B1 , int B2 , int B3 , int B4 , int B5 , int B6 , int B7 , int B8 , int B9 )// 背包函式
{
	int take;
	bool validInput_bag ;
	
	cout << "                      包 包" << endl << endl ;
	
	for(int z=1; z<=9 ; z++ ) //繪製包包 
	{
		switch(z) // 判斷玩家按鍵輸入的結果 
		{ 
			case 1 : // 第 1 格 
			{ 
				if(B1 != 0)
				{
					cout << " x" ;
				}
				else
				{
					cout << " 空" ; 
				}
				break ;
			}  
			
			case 2 : // 第 2 格 
			{ 
				if(B2 != 0)
				{
					cout << " x" ;
				}
				else
				{
					cout << " 空" ; 
				}
				break ;
			}  
			
			case 3 : // 第 3 格 
			{ 
				if(B3 != 0)
				{
					cout << " x" ;
				}
				else
				{
					cout << " 空" ; 
				}
				break ;
			}  
			
			case 4 : // 第 4 格 
			{ 
				if(B4 != 0)
				{
					cout << " x" ;
				}
				else
				{
					cout << " 空" ; 
				}
				break ;
			}  
			
			case 5 : // 第 5 格 
			{ 
				if(B5 != 0)
				{
					cout << " x" ;
				}
				else
				{
					cout << " 空" ; 
				}
				break ;
			}  
			
			case 6 : // 第 6 格 
			{ 
				if(B6 != 0)
				{
					cout << " x" ;
				}
				else
				{
					cout << " 空" ; 
				}
				break ;
			}  
			
			case 7 : // 第 7 格 
			{ 
				if(B7 != 0)
				{
					cout << " x" ;
				}
				else
				{
					cout << " 空" ; 
				}
				break ;
			}  
			
			case 8 : // 第 8 格 
			{ 
				if(B8 != 0)
				{
					cout << " x" ;
				}
				else
				{
					cout << " 空" ; 
				}
				break ;
			} 
			
			case 9 : // 第 9 格 
			{ 
				if( B9 != 0 )
				{
					
				}
				else
				{
					cout << " 空" ; 
				}
				break ;
			} 
		}
			
	} 

	cout << endl << " 1  2  3  4  5  6  7  8  9" << endl ; // 顯示 包包格編號 
	
	cout << "                                        輸入編號拿取物品 E 關閉包包" << endl ;
	
	validInput_bag = true ;
	
	while(validInput_bag)  // 判斷 包包操作 是否要結束
	{
		
		take = 0 ;
		while (1)// 讀取玩家按鍵 // 控制 包包 操作
		{
            take = getch();// 讀取玩家按鍵 
            if (take != 0)
			{
				break; 
			}
    	}// 讀取玩家按鍵  
    	
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
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 向上走函式



R2 W_run(int run_x , int run_y , int task_yes)
{ 
	R2 output ;
	
	system("cls"); // 清屏
	if(run_y < 1 ) // 遇到邊界
	{
		run_y++ ;
		cout << "走不過去了 " << endl ;
	}
	if( run_x == 3 && run_y == 4 ) //遇到 農民
	{
		run_y++ ;
		cout << "農民 : 他的手可以穿過我的巴巴 到底是為什麼 " << endl ;
	}
	if( run_x == 8 && run_y == 6 ) //遇到 商人
	{
		run_y++ ;
		cout << "商人 : 來看看新貨 " ;
	}
	if( run_x == 3 && run_y == 9 ) //遇到 水井
	{
		run_y++ ;
		cout << "os : 又深又黑 有點恐怖 " << endl ;
	}
	if( run_x == 6 && run_y == 2 ) //遇到 aka
	{ 
		run_y++ ;
		output.A = npc_aka( run_x , run_y , task_yes );
	}
	cout << endl << endl ;
	output.B = run_y  ;
	return output ;
}
		


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 向下走函式


			 
R2 S_run(int run_x , int run_y , int task_yes)
{ 
	R2 output ;

	system("cls"); // 清屏
	if(run_y > 11 ) // 遇到邊界
	{
		run_y-- ;
		cout << "走不過去了 " << endl ;
	}
	if( run_x == 3 && run_y == 4 ) //遇到 農民
	{
		run_y-- ;
		cout << "農民 : 他的手可以穿過我的巴巴 到底是為什麼 " << endl ;
	}
	if( run_x == 8 && run_y == 6 ) //遇到 商人
	{
		run_y-- ;
		cout << "商人 : 來看看新貨 " << endl ;
	}
	if( run_x == 3 && run_y == 9 ) //遇到 水井
	{
		run_y-- ;
		cout << "os : 又深又黑 有點恐怖 " << endl ;
	}
	if( run_x == 6 && run_y == 2 ) //遇到 aka
	{
		run_y-- ;
		output.A = npc_aka( run_x , run_y , task_yes );
	}
	cout << endl << endl ;
	output.B = run_y  ;
	return output ;
}
		


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 向左走函式


				 
R2 A_run(int run_x , int run_y , int task_yes)
{ 
	R2 output ;

	system("cls"); // 清屏
	if(run_x < 1 ) // 遇到邊界
	{
		run_x++ ;
		cout << "走不過去了 " << endl ;
	}
	if( run_x == 3 && run_y == 4 ) //遇到 農民
	{
		run_x++ ;
		cout << "農民 : 他的手可以穿過我的巴巴 到底是為什麼 " << endl ;
	}
	if( run_x == 8 && run_y == 6 ) //遇到 商人
	{
		run_x++ ;
		cout << "商人 : 來看看新貨 " << endl ;
	}
	if( run_x == 3 && run_y == 9 ) //遇到 水井
	{
		run_x++ ;
		cout << "os : 又深又黑 有點恐怖 " << endl ;
	}
	if( run_x == 6 && run_y == 2 ) //遇到 aka 
	{
		run_x++ ;
		output.A = npc_aka( run_x , run_y , task_yes );
	}
	cout << endl << endl ;
	output.B = run_x  ;
	return output ;
}
			


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 向右走函式


	
R2 D_run(int run_x , int run_y , int task_yes )
{ 
	R2 output ;
	
	system("cls"); // 清屏
	if(run_x > 11 ) // 遇到邊界 
	{
		run_x-- ;
		cout << "走不過去了 " << endl ;
	}
	if( run_x == 3 && run_y == 4 ) //遇到 農民 
	{
		run_x-- ;
		cout << "農民 : 他的手可以穿過我的巴巴 到底是為什麼 " << endl ;
	}
	if( run_x == 8 && run_y == 6 ) //遇到 商人 
	{
		run_x-- ;
		cout << "商人 : 來看看新貨 " << endl ;
	}
	if( run_x == 3 && run_y == 9 ) //遇到 水井 
	{
		run_x-- ;
		cout << "os : 又深又黑 有點恐怖 " << endl ;
	}
	if( run_x == 6 && run_y == 2 ) //遇到 aka 
	{
		run_x-- ;
		output.A = npc_aka( run_x , run_y , task_yes );
	}                             
	cout << endl << endl ;
	output.B = run_x  ;
	return output ;
}
			


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 包包欄 



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// npc函式 


int npc_aka( int run_x , int run_y , int task_yes ) // 暴徒npc函式
{
	int talk ;
	
	bool validInput_npc_aka = true ;
	
	while(validInput_npc_aka)
	{
		talk = 0 ;
		while (1)
		{
			cout << "台北爆徒 : 浪漫Duke" << endl << endl ;
			cout << " 1. 沒帶記憶卡 不早說。" << endl ; 
			cout << " 2. 抽煙?。" << endl ;
			cout << " 3. 懂海 海就會幫你。" << endl ;
				
            talk = getch();// 讀取玩家按鍵 
            if (talk != 0)
			{
				system("cls") ;
				break; 
			}
    	}
    	
		switch(talk) // 判斷玩家按鍵輸入的結果 
		{ 
			case 49 : 
				cout << "玩家 : 為什麼你沒帶記憶卡 不早說。" << endl << endl ; 
				cout << "台北爆徒 : 阿我就怕被罵嘛。" << endl ; 
				validInput_npc_aka = false ;
				break ;
				 
			case 50 : 
				cout << "玩家 : 抽煙 ? " << endl << endl ; 
				cout << "台北爆徒 : 抽煙 BAD ! ! ! " << endl ; 
				validInput_npc_aka = false ;
				break ;
			
			case 51 : 
				cout << "玩家 : 懂海 海就會幫你。 " << endl << endl ; 
				cout << "台北爆徒 : 我就喜歡這種直率的人" << endl << endl ;
				cout << "獲得  \"象蚌\"  " << endl ;
				validInput_npc_aka = false ;
				task_yes = 1 ;
				return task_yes ;
				break ;
			
			default:
				break ;
		} 
	} 
} // 暴徒npc函式



int npc_businessman(  ) // 商人npc 函式
{
	
}
 


int npc_farmer(  ) // 農夫npc 函式
{

} 



int npc_well(  ) // 水井物件 函式
{

} 


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 任務函式 


int task_npc_aka_mussel( int B1 , int B2 , int B3 , int B4 , int B5 , int B6 , int B7 , int B8 , int B9 ) // 偵測 象蚌要放那 
{
	if( B1==0 )
	{
		B1='蚌' ;
		return B1;
	}
	else if( B2==0 )
	{
		B2='蚌' ;
		return B2 ;
	}
	else if( B3==0 )
	{
		B3='蚌' ;
		return B3 ;
	}
	else if( B4==0 )
	{
		B4='蚌' ;
		return B4 ;
	}
	else if( B5==0 )
	{
		B5='蚌' ;
		return B5 ;
	}
	else if( B6==0 )
	{
		B6='蚌' ;
		return B6 ;
	}
	else if( B7==0 )
	{
		B7='蚌' ;
		return B7 ;
	}
	else if( B8==0 )
	{
		B8='蚌' ;
		return B8 ;
	}
	else if( B9==0 )
	{
		B9='蚌' ;
		return B9 ;
	}
}







