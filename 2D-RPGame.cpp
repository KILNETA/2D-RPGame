// 標頭檔 

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>  
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <locale>

// 簡化程式碼 

using namespace std;

/*
typedef struct R2
{
	int A = 0;
	int B = 0;
};
*/

void map_main( int run_x , int run_y );// 地圖函式 
int bag_main();// 背包函式
int take_bag_main();// 拿背包函式
void item_main(int take_Width,int take_Height);//物品詳情函式
void help_main(  );// 操作提示清單函式
void situation_main( string name , int blood );// 自我狀況清單函式

void W_run();// 向上走函式
void S_run();// 向下走函式
void A_run();// 向左走函式
void D_run();// 向右走函式

/////////////////////////////////////////////////////////// npc函式
int npc_aka( );
int npc_businessman(  );
int npc_farmer(  );
int npc_well(  );

/////////////////////////////////////////////////////////// 任務函式
int task_npc_aka_mussel();

//////////////////////////////////////////////////////////////////////外部變數 
int run_x=6 , run_y=6 ;
const int bag_Width=9 ,bag_Height=3;//包包大小 寬/高 

int blood = 100 ; // 血量 
string bag[bag_Width][bag_Height] = {} ; // 背包 

//////////////////////////////////////////////////////////////////////主遊戲函式 

int main()// 開始 執行程式  
{
	
	// 設定初始值 與 宣告變數名稱 
	
	string exname ;
	
	int start_input , end=0 ; // 控制 開始 
	
	int position , button ; // 
	
	
	bool validInput ; // bool 控制 是 與 否 
	
	srand( time(0) ); // 擷取現在 時間 當參數 
	
	//以下開始進入遊戲程序 
	
	cout << "歡迎遊玩 \"mini RPGame\" 小遊戲" << endl << endl ; // 歡迎 與 基本操作介紹 
	cout << "      基本操作:" << endl ;
	cout << "      W A S D 控制方向  |  E 開背包 " << endl << "      Esc 結束遊戲  |  ? 操作提示" << endl << endl;
	
	cout << "請輸入你的角色名字" << endl << endl ;
	cin >> exname ;
	
	const string name = exname ; //使名子無法再更改 
	
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
				W_run() ;// 回傳 向上走函式值run_y  任務值 task_yes
				map_main( run_x , run_y );//運行 地圖函式
				break ;
			} 
						 
			case 115 : //按 S 
			{ 
				run_y++ ;// 向下走
				S_run() ;// 回傳 向下 走函式值run_y  任務值 task_yes
				map_main( run_x , run_y );//運行 地圖函式
				break ;
			} 
						 
			case 97:   //按 A 
			{ 
				run_x-- ;// 向左走
				A_run() ;// 回傳 向左 走函式值run_x  任務值 task_yes 
				map_main( run_x , run_y );//運行 地圖函式
				break ;
			} 
				
			case 100 : //按 D 
			{
				run_x++ ;// 向右走
				D_run() ;// 回傳 向右 走函式值run_x 任務值 task_yes 
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
				bag_main();	//運行 包包函式 
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



int bag_main()// 背包函式
{
	int Width,Height;//印包包
	int take_Height,take_Width;//拿包包
	bool validInput_bag ;//是否關包包 
	
	cout << "                      包 包" << endl << endl ;
	
	for(int Height=0; Height<bag_Height ; Height++ ) //繪製包包 
	{
		cout<<" "<<Height+1<<"  ";
		for(int Width=0; Width<bag_Width ; Width++ )
		{
			if(bag[Width][Height]=="")
			{
				cout<<"空 "; //包包內容為空 
			}
			else
			{
				cout<<bag[Width][Height] <<" "; //印包包內容 
			}
		}
		cout<<endl;
	} 

	cout << endl << "     1  2  3  4  5  6  7  8  9" << endl ; // 顯示 包包格編號 
	
	cout << "                                        輸入編號拿取物品 E 關閉包包" << endl ;
	cout << "                                             選擇 排" << endl ;
	
	validInput_bag = true ; //預設開包包 
	
	while(validInput_bag)  // 判斷 包包操作 是否要結束
	{
		
		take_Height = 0 ;
		while (1)// 讀取玩家按鍵 // 控制 包包 操作
		{
            take_Height = getch();// 讀取玩家按鍵 
            if (take_Height != 0)
			{
				break; 
			}
    	}// 讀取玩家按鍵  
    	
		switch(take_Height) // 判斷玩家按鍵輸入的結果 
		{ 
			case 49 : 
				cout << "                                        第1排" << endl ;
				take_Height = 0;
				take_Width = take_bag_main();
				item_main(take_Width,take_Height);
				validInput_bag = false ;
				break ;
				 
			case 50 : 
				cout << "                                        第2排" << endl ; 
				take_Height = 1;
				take_Width = take_bag_main();
				item_main(take_Width,take_Height);
				validInput_bag = false ;
				break ;
			
			case 51 : 
				cout << "                                        第3排" << endl ; 
				take_Height = 2;
				take_Width = take_bag_main();
				item_main(take_Width,take_Height);
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
	if(take_Width!=0) //開啟物品介紹 
	{
	}
	
	_sleep(750); // 停留0.75秒 
	system("cls"); // 清屏 
	cout << endl << endl ;
}

int take_bag_main()//拿取第X格 函式 
{
	int take_Width;
	
	cout << "                                             選擇 格" << endl ;
	
	while (1)// 讀取玩家按鍵 // 控制 包包 操作
		{
            take_Width = getch();// 讀取玩家按鍵 
            if (take_Width != 0)
			{
				break; 
			}
    	}// 讀取玩家按鍵
    	
    switch (take_Width)
    {
    	case 49 : 
			cout << "                                        第1格" << endl ;
			return 0;
				 
		case 50 : 
			cout << "                                        第2格" << endl ; 
			return 1;
		
		case 51 : 
			cout << "                                        第3格" << endl ; 
			return 2;
			
		case 52 : 
			cout << "                                        第4格" << endl ;
			return 3;
				 
		case 53 : 
			cout << "                                        第5格" << endl ; 
			return 4;
		
		case 54 : 
			cout << "                                        第6格" << endl ; 
			return 5;
			
		case 55 : 
			cout << "                                        第7格" << endl ;
			return 6;
				 
		case 56 : 
			cout << "                                        第8格" << endl ; 
			return 7;
		
		case 57 : 
			cout << "                                        第9格" << endl ; 
			return 8;
			
		case 101 : 
			cout << endl << "                                        關閉背包" << endl ;
			return 0;
		
		default:
			break ;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 項目查詢 

void item_main(int take_Width,int take_Height)//物品詳情函式
{
	
    if(bag[take_Width][take_Height]=="")
    {
    	cout << "目前這裡，沒有被放置任何東西。" << endl ;
	}
	if(bag[take_Width][take_Height]=="蚌")
	{
		cout << "\"象蚌\"" << endl ; 
		cout << "東太平洋漁場時價分析師兼操盤手暨洋流講師海龍王彼得 : 時價650。" << endl ;
		cout << "象拔蚌的殼一般長15-20厘米，" << endl ;
		cout << "但是其虹管可長達一米，形似象鼻，" << endl ;
		cout << "又大又多肉，因此被稱為「象拔蚌」。" << endl ;
		cout << "中文學名 : 太平洋潛泥蛤。" << endl ;
	}	
	cout << endl << "                                        按任一鍵離開" << endl ;
	
	while (1)// 讀取玩家按鍵 // 控制 包包 操作
	{
        int take_Width = getch();// 讀取玩家按鍵 
    	if (take_Width != 0)
		{
			break; 
		}
    }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 向上走函式



void W_run()
{ 
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
		npc_aka();
	}
	cout << endl << endl ;
}
		


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 向下走函式


			 
void S_run()
{ 
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
		npc_aka();
	}
	cout << endl << endl ;
}
		


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 向左走函式


				 
void A_run()
{ 
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
		npc_aka();
	}
	cout << endl << endl ;
}
			


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 向右走函式


	
void D_run()
{ 
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
		npc_aka();
	}                             
	cout << endl << endl ;
}
			


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 包包欄 



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// npc函式 


int npc_aka() // 暴徒npc函式
{
	int talk ;
	static bool aka_Ok=true;
	
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
				if(aka_Ok)
				{
					cout << "玩家 : 懂海 海就會幫你。 " << endl << endl ; 
					cout << "台北爆徒 : 我就喜歡這種直率的人" << endl << endl ;
					cout << "獲得  \"象蚌\"  " << endl ;
					aka_Ok=false;
					task_npc_aka_mussel();
				}
				else
				{
					cout << "玩家 : 懂海 海就會幫你。 " << endl << endl ;
					cout << "台北爆徒 : 我給過你\"象蚌\"了 反基因方程式 ! " << endl << endl ;
				}
				validInput_npc_aka = false ;
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

int task_npc_aka_mussel() // 偵測 aka_象蚌要放那 
{
	bool Esc=0;
	for(int Height=0; Height<bag_Height ; Height++ ) //繪製包包 
	{
		for(int Width=0; Width<bag_Width ; Width++ )
		{
			if(bag[Width][Height]=="")
			{
				bag[Width][Height]="蚌";//包包內容為空 可以放 
				Esc=1;
				break;
			}
		}
		if(Esc)
		{
			break;
		}
	} 
}







