// ���Y�� 

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>  
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <locale>

// ²�Ƶ{���X 

using namespace std;

/*
typedef struct R2
{
	int A = 0;
	int B = 0;
};
*/

void map_main( int run_x , int run_y );// �a�Ϩ禡 
int bag_main();// �I�]�禡
int take_bag_main();// ���I�]�禡
void item_main(int take_Width,int take_Height);//���~�Ա��禡
void help_main(  );// �ާ@���ܲM��禡
void situation_main( string name , int blood );// �ۧڪ��p�M��禡

void W_run();// �V�W���禡
void S_run();// �V�U���禡
void A_run();// �V�����禡
void D_run();// �V�k���禡

/////////////////////////////////////////////////////////// npc�禡
int npc_aka( );
int npc_businessman(  );
int npc_farmer(  );
int npc_well(  );

/////////////////////////////////////////////////////////// ���Ȩ禡
int task_npc_aka_mussel();

//////////////////////////////////////////////////////////////////////�~���ܼ� 
int run_x=6 , run_y=6 ;
const int bag_Width=9 ,bag_Height=3;//�]�]�j�p �e/�� 

int blood = 100 ; // ��q 
string bag[bag_Width][bag_Height] = {} ; // �I�] 

//////////////////////////////////////////////////////////////////////�D�C���禡 

int main()// �}�l ����{��  
{
	
	// �]�w��l�� �P �ŧi�ܼƦW�� 
	
	string exname ;
	
	int start_input , end=0 ; // ���� �}�l 
	
	int position , button ; // 
	
	
	bool validInput ; // bool ���� �O �P �_ 
	
	srand( time(0) ); // �^���{�b �ɶ� ��Ѽ� 
	
	//�H�U�}�l�i�J�C���{�� 
	
	cout << "�w��C�� \"mini RPGame\" �p�C��" << endl << endl ; // �w�� �P �򥻾ާ@���� 
	cout << "      �򥻾ާ@:" << endl ;
	cout << "      W A S D �����V  |  E �}�I�] " << endl << "      Esc �����C��  |  ? �ާ@����" << endl << endl;
	
	cout << "�п�J�A������W�r" << endl << endl ;
	cin >> exname ;
	
	const string name = exname ; //�ϦW�l�L�k�A��� 
	
	cout << " Enter �}�l�C��" << endl ;
	
	while (1)// Ū�����a����  // ����C���}�l
		{
            start_input = getch();// Ū�����a���� 
            if (start_input == 13)
			{
				break; 
			}
    	}// Ū�����a���� 
	
	system("cls"); // �M��
		
	validInput = true ; //��J���T �w�]���� 
	
	cout << endl << endl ;
	map_main( run_x , run_y ); //�Ĥ@����ܦa�� 
	
	while (validInput)// �P�_ �C���ާ@ �O�_�n���� 
	{
		button = 0 ;
		
		while (1) // Ū�����a���� // ����ާ@ 
		{
            button = getch();// Ū�����a���� 
            if (button != 0)
			{
				break; 
			}
    	} // Ū�����a���� 
		
		switch(button) // �P�_���a�����J�����G 
		{ 
			case 119 : //�� W 
			{ 
				run_y-- ;// �V�W��
				W_run() ;// �^�� �V�W���禡��run_y  ���ȭ� task_yes
				map_main( run_x , run_y );//�B�� �a�Ϩ禡
				break ;
			} 
						 
			case 115 : //�� S 
			{ 
				run_y++ ;// �V�U��
				S_run() ;// �^�� �V�U ���禡��run_y  ���ȭ� task_yes
				map_main( run_x , run_y );//�B�� �a�Ϩ禡
				break ;
			} 
						 
			case 97:   //�� A 
			{ 
				run_x-- ;// �V����
				A_run() ;// �^�� �V�� ���禡��run_x  ���ȭ� task_yes 
				map_main( run_x , run_y );//�B�� �a�Ϩ禡
				break ;
			} 
				
			case 100 : //�� D 
			{
				run_x++ ;// �V�k��
				D_run() ;// �^�� �V�k ���禡��run_x ���ȭ� task_yes 
				map_main( run_x , run_y );//�B�� �a�Ϩ禡
				break ;
			}
					
			case 27  : //���a�����C�� 
			{
				cout << endl ;	
				cout << "                                        �U���A�Ӫ��� �t�t" << endl << endl ;
				validInput = false ;
				break ;
			}
				
			case 101  : //�}�ҭI�] 
			{
				system("cls");
				cout << endl ;
				cout << "                                        �}�_�I�]" << endl ; 
				bag_main();	//�B�� �]�]�禡 
				map_main( run_x , run_y ); //�B�� �a�Ϩ禡 
				break ;
			} 
			
			case 63  : //�}�Ҿާ@���ܲM�� 
			{
				system("cls");
				cout << endl ;
				cout << "                                        �}�_ �ާ@���ܲM��" << endl ; 
				help_main();	//�B�� �ާ@���ܲM��禡 
				map_main( run_x , run_y );//�B�� �a�Ϩ禡
				break ;
			} 
				
			case 99  : //�}�Ҧۧڪ��p�M��
			{
				system("cls");
				cout << endl ;
				cout << "                                        �}�_ �ۧڪ��p�M��" << endl ; 
				situation_main( name , blood );	//�B�� �ۧڪ��p�M��禡 
				map_main( run_x , run_y );//�B�� �a�Ϩ禡
				break ;
			} 
				
			default: //�L���� 
			{ 
				break ;
			} 
		}
	}
	cout << "�A���@�� Esc ��������" << endl ; 
	while (1) // Ū�����a���� // Esc ��������
	{ 
		int END_button=0 ;
        END_button = getch();// Ū�����a���� 
        if (END_button == 27)
		{
			break; 
		}
    } // Ū�����a���� 
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �a�Ϩ禡



void map_main( int run_x , int run_y ) // �a�Ϩ禡
{
	int x=1 , y=1 ;

	cout << "                         �����a��" << endl << endl ;
	for(; y<=11 ; y++ )
	{
		for(; x<=11 ; x++ )
		{
			if(x == 3 && y == 4) //��� �A�� 
			{
				cout << " �A" ;
			}
			else if(x == 8 && y == 6) //��� �ӤH 
			{
				cout << " ��" ;
			}
			else if(x == 3 && y == 9) //��� ���� 
			{
				cout << " ��" ;
			}
			else if(x == 6 && y == 2) //��� �ɮ{ 
			{
				cout << "aka" ;
			}
			else if(x == run_x && y == run_y) //��� ���a 
			{
				cout << " ��" ;
			}
			else if(x <= 5 && y >= 6) //��� �A�� 
			{
				cout << " �J" ;
			}
			else                      //��� �D�� 
			{
				cout << " �f" ;
			}
		}
		x=1;
		cout << endl ;
	}
	cout << endl << endl ;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �ާ@���ܲM��禡



void help_main()// �ާ@���ܲM��禡 
{
	cout << "      �򥻾ާ@:" << endl ;
	cout << "      W A S D �����V  |  E �}�I�] " << endl << "      Esc �����C��  |  ? �ާ@����" << endl << endl ;
	cout << "      Esc ��������" << endl ;
	int help_Esc ;
	
	while (help_Esc != 27)// Ū�����a���� // ���� ���}�ާ@���ܲM�� �ާ@
		{
            help_Esc = getch();// Ū�����a���� 
    	}// Ū�����a����
    system("cls"); // �M��
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �I�]�禡



void situation_main( string name , int blood )// �ۧڪ��p�M��禡
{
	cout << "      ���⪬�p: " << endl << endl ;
	cout << "      ����W��: " << name << endl ;
	cout << "      �����q: " << blood << endl ;
	/*cout << "      �ⳡ: " <<  << "      �˳�: " << / << endl ;
	cout << "      ����: " <<  ;
	cout << "      �ٸ�: " << / << endl << endl ; */
	
	cout << "      Esc �����M��" << endl ;
	int situation_Esc ;
	
	while (situation_Esc != 27)// Ū�����a���� // ���� ���}�ާ@���ܲM�� �ާ@
		{
            situation_Esc = getch();// Ū�����a���� 
    	}// Ū�����a����
    system("cls"); // �M��
} 



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �I�]�禡



int bag_main()// �I�]�禡
{
	int Width,Height;//�L�]�]
	int take_Height,take_Width;//���]�]
	bool validInput_bag ;//�O�_���]�] 
	
	cout << "                      �] �]" << endl << endl ;
	
	for(int Height=0; Height<bag_Height ; Height++ ) //ø�s�]�] 
	{
		cout<<" "<<Height+1<<"  ";
		for(int Width=0; Width<bag_Width ; Width++ )
		{
			if(bag[Width][Height]=="")
			{
				cout<<"�� "; //�]�]���e���� 
			}
			else
			{
				cout<<bag[Width][Height] <<" "; //�L�]�]���e 
			}
		}
		cout<<endl;
	} 

	cout << endl << "     1  2  3  4  5  6  7  8  9" << endl ; // ��� �]�]��s�� 
	
	cout << "                                        ��J�s���������~ E �����]�]" << endl ;
	cout << "                                             ��� ��" << endl ;
	
	validInput_bag = true ; //�w�]�}�]�] 
	
	while(validInput_bag)  // �P�_ �]�]�ާ@ �O�_�n����
	{
		
		take_Height = 0 ;
		while (1)// Ū�����a���� // ���� �]�] �ާ@
		{
            take_Height = getch();// Ū�����a���� 
            if (take_Height != 0)
			{
				break; 
			}
    	}// Ū�����a����  
    	
		switch(take_Height) // �P�_���a�����J�����G 
		{ 
			case 49 : 
				cout << "                                        ��1��" << endl ;
				take_Height = 0;
				take_Width = take_bag_main();
				item_main(take_Width,take_Height);
				validInput_bag = false ;
				break ;
				 
			case 50 : 
				cout << "                                        ��2��" << endl ; 
				take_Height = 1;
				take_Width = take_bag_main();
				item_main(take_Width,take_Height);
				validInput_bag = false ;
				break ;
			
			case 51 : 
				cout << "                                        ��3��" << endl ; 
				take_Height = 2;
				take_Width = take_bag_main();
				item_main(take_Width,take_Height);
				validInput_bag = false ;
				break ;
				
			case 101 : 
				cout << endl << "                                        �����I�]" << endl ; 
				validInput_bag = false ;
				break ;
			
			default:
				break ;
		} 
	}
	if(take_Width!=0) //�}�Ҫ��~���� 
	{
	}
	
	_sleep(750); // ���d0.75�� 
	system("cls"); // �M�� 
	cout << endl << endl ;
}

int take_bag_main()//������X�� �禡 
{
	int take_Width;
	
	cout << "                                             ��� ��" << endl ;
	
	while (1)// Ū�����a���� // ���� �]�] �ާ@
		{
            take_Width = getch();// Ū�����a���� 
            if (take_Width != 0)
			{
				break; 
			}
    	}// Ū�����a����
    	
    switch (take_Width)
    {
    	case 49 : 
			cout << "                                        ��1��" << endl ;
			return 0;
				 
		case 50 : 
			cout << "                                        ��2��" << endl ; 
			return 1;
		
		case 51 : 
			cout << "                                        ��3��" << endl ; 
			return 2;
			
		case 52 : 
			cout << "                                        ��4��" << endl ;
			return 3;
				 
		case 53 : 
			cout << "                                        ��5��" << endl ; 
			return 4;
		
		case 54 : 
			cout << "                                        ��6��" << endl ; 
			return 5;
			
		case 55 : 
			cout << "                                        ��7��" << endl ;
			return 6;
				 
		case 56 : 
			cout << "                                        ��8��" << endl ; 
			return 7;
		
		case 57 : 
			cout << "                                        ��9��" << endl ; 
			return 8;
			
		case 101 : 
			cout << endl << "                                        �����I�]" << endl ;
			return 0;
		
		default:
			break ;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// ���جd�� 

void item_main(int take_Width,int take_Height)//���~�Ա��禡
{
	
    if(bag[take_Width][take_Height]=="")
    {
    	cout << "�ثe�o�̡A�S���Q��m����F��C" << endl ;
	}
	if(bag[take_Width][take_Height]=="�F")
	{
		cout << "\"�H�F\"" << endl ; 
		cout << "�F�ӥ��v�����ɻ����R�v�ݾ޽L��[�v�y���v���s�����o : �ɻ�650�C" << endl ;
		cout << "�H�ްF���ߤ@���15-20���̡A" << endl ;
		cout << "���O��i�ޥi���F�@�̡A�Φ��H��A" << endl ;
		cout << "�S�j�S�h�סA�]���Q�٬��u�H�ްF�v�C" << endl ;
		cout << "����ǦW : �ӥ��v��d��C" << endl ;
	}	
	cout << endl << "                                        �����@�����}" << endl ;
	
	while (1)// Ū�����a���� // ���� �]�] �ާ@
	{
        int take_Width = getch();// Ū�����a���� 
    	if (take_Width != 0)
		{
			break; 
		}
    }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �V�W���禡



void W_run()
{ 
	system("cls"); // �M��
	if(run_y < 1 ) // �J�����
	{
		run_y++ ;
		cout << "�����L�h�F " << endl ;
	}
	if( run_x == 3 && run_y == 4 ) //�J�� �A��
	{
		run_y++ ;
		cout << "�A�� : �L����i�H��L�ڪ��ڤ� �쩳�O������ " << endl ;
	}
	if( run_x == 8 && run_y == 6 ) //�J�� �ӤH
	{
		run_y++ ;
		cout << "�ӤH : �Ӭݬݷs�f " ;
	}
	if( run_x == 3 && run_y == 9 ) //�J�� ����
	{
		run_y++ ;
		cout << "os : �S�`�S�� ���I���� " << endl ;
	}
	if( run_x == 6 && run_y == 2 ) //�J�� aka
	{ 
		run_y++ ;
		npc_aka();
	}
	cout << endl << endl ;
}
		


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �V�U���禡


			 
void S_run()
{ 
	system("cls"); // �M��
	if(run_y > 11 ) // �J�����
	{
		run_y-- ;
		cout << "�����L�h�F " << endl ;
	}
	if( run_x == 3 && run_y == 4 ) //�J�� �A��
	{
		run_y-- ;
		cout << "�A�� : �L����i�H��L�ڪ��ڤ� �쩳�O������ " << endl ;
	}
	if( run_x == 8 && run_y == 6 ) //�J�� �ӤH
	{
		run_y-- ;
		cout << "�ӤH : �Ӭݬݷs�f " << endl ;
	}
	if( run_x == 3 && run_y == 9 ) //�J�� ����
	{
		run_y-- ;
		cout << "os : �S�`�S�� ���I���� " << endl ;
	}
	if( run_x == 6 && run_y == 2 ) //�J�� aka
	{
		run_y-- ;
		npc_aka();
	}
	cout << endl << endl ;
}
		


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �V�����禡


				 
void A_run()
{ 
	system("cls"); // �M��
	if(run_x < 1 ) // �J�����
	{
		run_x++ ;
		cout << "�����L�h�F " << endl ;
	}
	if( run_x == 3 && run_y == 4 ) //�J�� �A��
	{
		run_x++ ;
		cout << "�A�� : �L����i�H��L�ڪ��ڤ� �쩳�O������ " << endl ;
	}
	if( run_x == 8 && run_y == 6 ) //�J�� �ӤH
	{
		run_x++ ;
		cout << "�ӤH : �Ӭݬݷs�f " << endl ;
	}
	if( run_x == 3 && run_y == 9 ) //�J�� ����
	{
		run_x++ ;
		cout << "os : �S�`�S�� ���I���� " << endl ;
	}
	if( run_x == 6 && run_y == 2 ) //�J�� aka 
	{
		run_x++ ;
		npc_aka();
	}
	cout << endl << endl ;
}
			


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �V�k���禡


	
void D_run()
{ 
	system("cls"); // �M��
	if(run_x > 11 ) // �J����� 
	{
		run_x-- ;
		cout << "�����L�h�F " << endl ;
	}
	if( run_x == 3 && run_y == 4 ) //�J�� �A�� 
	{
		run_x-- ;
		cout << "�A�� : �L����i�H��L�ڪ��ڤ� �쩳�O������ " << endl ;
	}
	if( run_x == 8 && run_y == 6 ) //�J�� �ӤH 
	{
		run_x-- ;
		cout << "�ӤH : �Ӭݬݷs�f " << endl ;
	}
	if( run_x == 3 && run_y == 9 ) //�J�� ���� 
	{
		run_x-- ;
		cout << "os : �S�`�S�� ���I���� " << endl ;
	}
	if( run_x == 6 && run_y == 2 ) //�J�� aka 
	{
		run_x-- ;
		npc_aka();
	}                             
	cout << endl << endl ;
}
			


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �]�]�� 



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// npc�禡 


int npc_aka() // �ɮ{npc�禡
{
	int talk ;
	static bool aka_Ok=true;
	
	bool validInput_npc_aka = true ;
	
	while(validInput_npc_aka)
	{
		talk = 0 ;
		while (1)
		{
			cout << "�x�_�z�{ : ����Duke" << endl << endl ;
			cout << " 1. �S�a�O�Хd �������C" << endl ; 
			cout << " 2. ���?�C" << endl ;
			cout << " 3. ���� ���N�|���A�C" << endl ;
				
            talk = getch();// Ū�����a���� 
            if (talk != 0)
			{
				system("cls") ;
				break; 
			}
    	}
    	
		switch(talk) // �P�_���a�����J�����G 
		{ 
			case 49 : 
				cout << "���a : ������A�S�a�O�Хd �������C" << endl << endl ; 
				cout << "�x�_�z�{ : ���ڴN�ȳQ�|���C" << endl ; 
				validInput_npc_aka = false ;
				break ;
				 
			case 50 : 
				cout << "���a : ��� ? " << endl << endl ; 
				cout << "�x�_�z�{ : ��� BAD ! ! ! " << endl ; 
				validInput_npc_aka = false ;
				break ;
			
			case 51 : 
				if(aka_Ok)
				{
					cout << "���a : ���� ���N�|���A�C " << endl << endl ; 
					cout << "�x�_�z�{ : �ڴN���w�o�ت��v���H" << endl << endl ;
					cout << "��o  \"�H�F\"  " << endl ;
					aka_Ok=false;
					task_npc_aka_mussel();
				}
				else
				{
					cout << "���a : ���� ���N�|���A�C " << endl << endl ;
					cout << "�x�_�z�{ : �ڵ��L�A\"�H�F\"�F �ϰ�]��{�� ! " << endl << endl ;
				}
				validInput_npc_aka = false ;
				break ;
			
			default:
				break ;
		} 
	} 
} // �ɮ{npc�禡



int npc_businessman(  ) // �ӤHnpc �禡
{
	
}
 


int npc_farmer(  ) // �A��npc �禡
{

} 



int npc_well(  ) // �������� �禡
{

} 


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// ���Ȩ禡 

int task_npc_aka_mussel() // ���� aka_�H�F�n�� 
{
	bool Esc=0;
	for(int Height=0; Height<bag_Height ; Height++ ) //ø�s�]�] 
	{
		for(int Width=0; Width<bag_Width ; Width++ )
		{
			if(bag[Width][Height]=="")
			{
				bag[Width][Height]="�F";//�]�]���e���� �i�H�� 
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







