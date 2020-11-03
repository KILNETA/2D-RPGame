// ���Y�� 

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>  
#include <conio.h>

// ²�Ƶ{���X 

using namespace std;

void map_main( int run_x , int run_y , bool validInput );// �a�Ϩ禡 
void bag_main( int run_x , int run_y , bool validInput );// �I�]�禡

int W_run( int run_x , int run_y );// �V�W���禡
int S_run( int run_x , int run_y );// �V�U���禡
int A_run( int run_x , int run_y );// �V�����禡
int D_run( int run_x , int run_y );// �V�k���禡

int one_bag   ();
int two_bag   ();
int three_bag ();
int four_bag  ();
int five_bag  ();
int six_bag   ();
int seven_bag ();
int eight_bag ();
int nine_bag  ();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////�D�C���禡 

int main()// �}�l ����{�� 
{
	
	// �]�w��l�� �P �ŧi�ܼƦW�� 
	
	int run_x=6 , run_y=6 ;
	
	int start_input , end=0 ; // ���� �}�l 
	
	int position , button ; // 
	
	bool validInput ; // bool ���� �O �P �_ 
	
	srand( time(0) ); // �^���{�b �ɶ� ��Ѽ� 
	
	//�H�U�}�l�i�J�C���{�� 
	
	cout << "�w��C�� \"mini RPGame\" �p�C��" << endl << endl ; // �w�� �P �򥻾ާ@���� 
	cout << "      �򥻾ާ@:" << endl ;
	cout << "      ��J W A S D �����V  |  ��J E �ݭI�]  |  ��J Q �����C��" << endl;
	cout << "      (�i�@����J�������B��) (�����j�p�g)" << endl << endl ; 
	
	cout << " Enter �}�l�C��" << endl ;
	
	while (1)//�P�_ �C���}�l
		{
            start_input = getch();//�ϥ�_getch()��??�����U��?��
            if (start_input == 13)
			{
				break; 
			}
    	}//�P�_ �C���}�l
	
	system("cls"); // �M��
		
	validInput = true ; //��J���T �w�]���� 
	
	cout << endl << endl ;
	map_main( run_x , run_y , validInput ); //�Ĥ@����ܦa�� 
	
	while (validInput)
	{
		button = 0 ;
		while (1)
		{
            button = getch();// Ū�����a���� 
            if (button != 0)
			{
				break; 
			}
    	}
		
		switch(button) // �P�_���a�����J�����G 
		{ 
			case 119 : 
				run_y-- ;// �V�W��
				run_y = W_run(run_x , run_y );// �^�� �V�W���禡��run_y
				map_main( run_x , run_y , validInput );//�B�� �a�Ϩ禡
				break ;
						 
			case 115 :
				run_y++ ;// �V�U��
				run_y = S_run(run_x , run_y );// �^�� �V�W���禡 ��run_y
				map_main( run_x , run_y , validInput );//�B�� �a�Ϩ禡
				break ;
						 
			case 97:
				run_x-- ;// �V����
				run_x = A_run(run_x , run_y);// �^�� �V�W���禡 ��run_x 
				map_main( run_x , run_y , validInput );//�B�� �a�Ϩ禡
				break ;
				
			case 100 :
				run_x++ ;// �V�k��
				run_x = D_run(run_x , run_y );// �^�� �V�W���禡 ��run_x 
				map_main( run_x , run_y , validInput );//�B�� �a�Ϩ禡
				break ;
					
			case 27  : //���a�����C�� 
				cout << endl ;	
				cout << "                                        �U���A�Ӫ��� �t�t" << endl << endl ;
				validInput = false ;
				break ;
				
			case 101  : //�}�ҭI�] 
				system("cls");
				cout << endl ;
				cout << "                                        �}�_�I�]" << endl ; 
				bag_main( run_x , run_y , validInput );	//�B�� �]�]�禡 
				break ;
				
			default:
				break ; 
			
		}
	}
	while( end != -1 ) //�������� 
	{
			cout << "�п�J (-1 ��������)" << endl ;
			cin >> end ;
	}
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �a�Ϩ禡



void map_main( int run_x , int run_y , bool validInput ) // �a�Ϩ禡
{
	int x=1 , y=1 ;
	
	if (validInput)
	{
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
	} 
	cout << endl << endl ;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �I�]�禡



void bag_main( int run_x , int run_y , bool validInput )// �I�]�禡
{
	int take;
	bool validInput_bag ;
	
	cout << "                      �] �]" << endl << endl ;
	
	for(int z=1; z<=9 ; z++ )
	{
		cout << " ��" ; 
	} 

	cout << endl << " 1  2  3  4  5  6  7  8  9" << endl ; // ��� �]�]��s�� 
	
	cout << "                                        ��J�s���������~ E �����]�]" << endl ;
	
	validInput_bag = true ;
	
	while(validInput_bag)
	{
		
		take = 0 ;
		while (1)
		{
            take = getch();// Ū�����a���� 
            if (take != 0)
			{
				break; 
			}
    	}
    	
		switch(take) // �P�_���a�����J�����G 
		{ 
			case 49 : 
				cout << "                                        ���� 1" << endl ; 
				validInput_bag = false ;
				break ;
				 
			case 50 : 
				cout << "                                        ���� 2" << endl ; 
				validInput_bag = false ;
				break ;
			
			case 51 : 
				cout << "                                        ���� 3" << endl ; 
				validInput_bag = false ;
				break ;
			
			case 52 : 
				cout << "                                        ���� 4" << endl ;
				validInput_bag = false ;
				break ;
				
			case 53 : 
				cout << "                                        ���� 5" << endl ; 
				validInput_bag = false ;
				break ;
				 
			case 54 : 
				cout << "                                        ���� 6" << endl ; 
				validInput_bag = false ;
				break ;
			
			case 55 : 
				cout << "                                        ���� 7" << endl ; 
				validInput_bag = false ;
				break ;
			
			case 56 : 
				cout << "                                        ���� 8" << endl ; 
				validInput_bag = false ;
				break ;
				
			case 57 : 
				cout << "                                        ���� 9" << endl ; 
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
	_sleep(750); // ���d0.75�� 
	system("cls"); // �M�� 
	cout << endl << endl ;
	map_main( run_x , run_y , validInput ); //�B�� �a�Ϩ禡 
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �V�W���禡



int W_run(int run_x , int run_y )
{ 
	system("cls"); // �M��
	if(run_y < 1 )
	{
		run_y++ ;
		cout << "�����L�h�F " ;
	}
	if( run_x == 3 && run_y == 4 )
	{
		run_y++ ;
		cout << "�A�� : �L����i�H��L�ڪ��ڤ� �쩳�O������ " ;
	}
	if( run_x == 8 && run_y == 6 )
	{
		run_y++ ;
		cout << "�ӤH : �Ӭݬݷs�f " ;
	}
	if( run_x == 3 && run_y == 9 )
	{
		run_y++ ;
		cout << "os : �S�`�S�� ���I���� " ;
	}
	if( run_x == 6 && run_y == 2 )
	{
		run_y++ ;
		cout << "�x�_�z�{ : ���ڴN�ȳQ�|��" ;
	}
	cout << endl << endl ;
	return run_y ;
}
		


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �V�U���禡


			 
int S_run(int run_x , int run_y )
{ 
	system("cls"); // �M��
	if(run_y > 11 )
	{
		run_y-- ;
		cout << "�����L�h�F " ;
	}
	if( run_x == 3 && run_y == 4 )
	{
		run_y-- ;
		cout << "�A�� : �L����i�H��L�ڪ��ڤ� �쩳�O������ " ;
	}
	if( run_x == 8 && run_y == 6 )
	{
		run_y-- ;
		cout << "�ӤH : �Ӭݬݷs�f " ;
	}
	if( run_x == 3 && run_y == 9 )
	{
		run_y-- ;
		cout << "os : �S�`�S�� ���I���� " ;
	}
	if( run_x == 6 && run_y == 2 )
	{
		run_y-- ;
		cout << "�x�_�z�{ : ���ڴN�ȳQ�|��" ;
	}
	cout << endl << endl ;
	return run_y ;
}
		


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �V�����禡


				 
int A_run(int run_x , int run_y )
{ 
	system("cls"); // �M��
	if(run_x < 1 )
	{
		run_x++ ;
		cout << "�����L�h�F " ;
	}
	if( run_x == 3 && run_y == 4 )
	{
		run_x++ ;
		cout << "�A�� : �L����i�H��L�ڪ��ڤ� �쩳�O������ " ;
	}
	if( run_x == 8 && run_y == 6 )
	{
		run_x++ ;
		cout << "�ӤH : �Ӭݬݷs�f " ;
	}
	if( run_x == 3 && run_y == 9 )
	{
		run_x++ ;
		cout << "os : �S�`�S�� ���I���� " ;
	}
	if( run_x == 6 && run_y == 2 )
	{
		run_x++ ;
		cout << "�x�_�z�{ : ���ڴN�ȳQ�|��" ;
	}
	cout << endl << endl ;
	return run_x ;
}
			


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �V�k���禡


	
int D_run(int run_x , int run_y )
{ 
	system("cls"); // �M��
	if(run_x > 11 )
	{
		run_x-- ;
		cout << "�����L�h�F " ;
	}
	if( run_x == 3 && run_y == 4 )
	{
		run_x-- ;
		cout << "�A�� : �L����i�H��L�ڪ��ڤ� �쩳�O������ " ;
	}
	if( run_x == 8 && run_y == 6 )
	{
		run_x-- ;
		cout << "�ӤH : �Ӭݬݷs�f " ;
	}
	if( run_x == 3 && run_y == 9 )
	{
		run_x-- ;
		cout << "os : �S�`�S�� ���I���� " ;
	}
	if( run_x == 6 && run_y == 2 )
	{
		run_x-- ;
		cout << "�x�_�z�{ : ���ڴN�ȳQ�|��" ;
	}
	cout << endl << endl ;
	return run_x ;
}
			


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �]�]�� 



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









