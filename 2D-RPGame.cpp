// ���Y�� 

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>  
#include <conio.h>
#include <stdio.h>

// ²�Ƶ{���X 

using namespace std;

typedef struct R2
{
	int A = 0;
	int B = 0;
};


void map_main( int run_x , int run_y );// �a�Ϩ禡 
int bag_main( int B1 , int B2 , int B3 , int B4 , int B5 , int B6 , int B7 , int B8 , int B9 );// �I�]�禡
void help_main(  );// �ާ@���ܲM��禡
void situation_main( string name , int blood );// �ۧڪ��p�M��禡

R2 W_run( int run_x , int run_y , int task_yes);// �V�W���禡
R2 S_run( int run_x , int run_y , int task_yes);// �V�U���禡
R2 A_run( int run_x , int run_y , int task_yes);// �V�����禡
R2 D_run( int run_x , int run_y , int task_yes);// �V�k���禡

/////////////////////////////////////////////////////////// npc�禡
int npc_aka( int run_x , int run_y , int task_yes );
int npc_businessman(  );
int npc_farmer(  );
int npc_well(  );

/////////////////////////////////////////////////////////// ���Ȩ禡
int task_npc_aka_mussel( int B1 , int B2 , int B3 , int B4 , int B5 , int B6 , int B7 , int B8 , int B9 );

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////�D�C���禡 

int main()// �}�l ����{��  
{
	
	// �]�w��l�� �P �ŧi�ܼƦW�� 
	
	R2 x;
	
	string name ;

	
	int blood = 100 ;
	
	int run_x=6 , run_y=6 ;
	
	int start_input , end=0 ; // ���� �}�l 
	
	int position , button ; // 
	
	int B1=0 , B2=0 , B3=0 , B4=0 , B5=0 , B6=0 , B7=0 , B8=0 , B9=0 ;
	
	int task_yes = 0 ;
	
	bool validInput ; // bool ���� �O �P �_ 
	
	srand( time(0) ); // �^���{�b �ɶ� ��Ѽ� 
	
	//�H�U�}�l�i�J�C���{�� 
	
	cout << "�w��C�� \"mini RPGame\" �p�C��" << endl << endl ; // �w�� �P �򥻾ާ@���� 
	cout << "      �򥻾ާ@:" << endl ;
	cout << "      W A S D �����V  |  E �}�I�] " << endl << "      Esc �����C��  |  ? �ާ@����" << endl << endl;
	
	cout << "�п�J�A������W�r" << endl << endl ;
	cin >> name ;
	
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
		task_yes = 0 ;
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
				
				x = W_run(run_x , run_y , task_yes ) ;// �^�� �V�W���禡��run_y  ���ȭ� task_yes
				task_yes = x.A ;
				run_y = x.B ;
				
				switch(task_yes) // �P�_���L ���� 
				{ 
					case 1 : 
						B1 = task_npc_aka_mussel( B1 , B2 , B3 , B4 , B5 , B6 , B7 , B8 , B9 ) ;
					break ;
				}
				map_main( run_x , run_y );//�B�� �a�Ϩ禡
				break ;
			} 
						 
			case 115 : //�� S 
			{ 
				run_y++ ;// �V�U��
				
				x = S_run(run_x , run_y , task_yes ) ;// �^�� �V�U ���禡��run_y  ���ȭ� task_yes
				task_yes = x.A ;
				run_y = x.B ;
				
				switch(task_yes) // �P�_���L ���� 
				{ 
					case 1 : 
						B1 = task_npc_aka_mussel( B1 , B2 , B3 , B4 , B5 , B6 , B7 , B8 , B9 ) ;
					break ;
				}
				map_main( run_x , run_y );//�B�� �a�Ϩ禡
				break ;
			} 
						 
			case 97:   //�� A 
			{ 
				run_x-- ;// �V����
				x = A_run(run_x , run_y , task_yes ) ;// �^�� �V�� ���禡��run_x  ���ȭ� task_yes 
				task_yes = x.A ;
				run_x = x.B ;
				switch(task_yes) // �P�_���L ���� 
				{ 
					case 1 : 
						B1 = task_npc_aka_mussel( B1 , B2 , B3 , B4 , B5 , B6 , B7 , B8 , B9 ) ;
					break ;
				}
				map_main( run_x , run_y );//�B�� �a�Ϩ禡
				break ;
			} 
				
			case 100 : //�� D 
			{
				run_x++ ;// �V�k��
				x = D_run(run_x , run_y , task_yes ) ;// �^�� �V�k ���禡��run_x ���ȭ� task_yes 
				task_yes = x.A ;
				run_x = x.B ;
				switch(task_yes) // �P�_���L ���� 
				{ 
					case 1 : 
						B1 = task_npc_aka_mussel( B1 , B2 , B3 , B4 , B5 , B6 , B7 , B8 , B9 ) ;
					break ;
				}
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
				bag_main( B1 , B2 , B3 , B4 , B5 , B6 , B7 , B8 , B9 );	//�B�� �]�]�禡 
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



int bag_main( int B1 , int B2 , int B3 , int B4 , int B5 , int B6 , int B7 , int B8 , int B9 )// �I�]�禡
{
	int take;
	bool validInput_bag ;
	
	cout << "                      �] �]" << endl << endl ;
	
	for(int z=1; z<=9 ; z++ ) //ø�s�]�] 
	{
		switch(z) // �P�_���a�����J�����G 
		{ 
			case 1 : // �� 1 �� 
			{ 
				if(B1 != 0)
				{
					cout << " x" ;
				}
				else
				{
					cout << " ��" ; 
				}
				break ;
			}  
			
			case 2 : // �� 2 �� 
			{ 
				if(B2 != 0)
				{
					cout << " x" ;
				}
				else
				{
					cout << " ��" ; 
				}
				break ;
			}  
			
			case 3 : // �� 3 �� 
			{ 
				if(B3 != 0)
				{
					cout << " x" ;
				}
				else
				{
					cout << " ��" ; 
				}
				break ;
			}  
			
			case 4 : // �� 4 �� 
			{ 
				if(B4 != 0)
				{
					cout << " x" ;
				}
				else
				{
					cout << " ��" ; 
				}
				break ;
			}  
			
			case 5 : // �� 5 �� 
			{ 
				if(B5 != 0)
				{
					cout << " x" ;
				}
				else
				{
					cout << " ��" ; 
				}
				break ;
			}  
			
			case 6 : // �� 6 �� 
			{ 
				if(B6 != 0)
				{
					cout << " x" ;
				}
				else
				{
					cout << " ��" ; 
				}
				break ;
			}  
			
			case 7 : // �� 7 �� 
			{ 
				if(B7 != 0)
				{
					cout << " x" ;
				}
				else
				{
					cout << " ��" ; 
				}
				break ;
			}  
			
			case 8 : // �� 8 �� 
			{ 
				if(B8 != 0)
				{
					cout << " x" ;
				}
				else
				{
					cout << " ��" ; 
				}
				break ;
			} 
			
			case 9 : // �� 9 �� 
			{ 
				if( B9 != 0 )
				{
					
				}
				else
				{
					cout << " ��" ; 
				}
				break ;
			} 
		}
			
	} 

	cout << endl << " 1  2  3  4  5  6  7  8  9" << endl ; // ��� �]�]��s�� 
	
	cout << "                                        ��J�s���������~ E �����]�]" << endl ;
	
	validInput_bag = true ;
	
	while(validInput_bag)  // �P�_ �]�]�ާ@ �O�_�n����
	{
		
		take = 0 ;
		while (1)// Ū�����a���� // ���� �]�] �ާ@
		{
            take = getch();// Ū�����a���� 
            if (take != 0)
			{
				break; 
			}
    	}// Ū�����a����  
    	
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
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �V�W���禡



R2 W_run(int run_x , int run_y , int task_yes)
{ 
	R2 output ;
	
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
		output.A = npc_aka( run_x , run_y , task_yes );
	}
	cout << endl << endl ;
	output.B = run_y  ;
	return output ;
}
		


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �V�U���禡


			 
R2 S_run(int run_x , int run_y , int task_yes)
{ 
	R2 output ;

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
		output.A = npc_aka( run_x , run_y , task_yes );
	}
	cout << endl << endl ;
	output.B = run_y  ;
	return output ;
}
		


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �V�����禡


				 
R2 A_run(int run_x , int run_y , int task_yes)
{ 
	R2 output ;

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
		output.A = npc_aka( run_x , run_y , task_yes );
	}
	cout << endl << endl ;
	output.B = run_x  ;
	return output ;
}
			


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �V�k���禡


	
R2 D_run(int run_x , int run_y , int task_yes )
{ 
	R2 output ;
	
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
		output.A = npc_aka( run_x , run_y , task_yes );
	}                             
	cout << endl << endl ;
	output.B = run_x  ;
	return output ;
}
			


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// �]�]�� 



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// npc�禡 


int npc_aka( int run_x , int run_y , int task_yes ) // �ɮ{npc�禡
{
	int talk ;
	
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
				cout << "���a : ���� ���N�|���A�C " << endl << endl ; 
				cout << "�x�_�z�{ : �ڴN���w�o�ت��v���H" << endl << endl ;
				cout << "��o  \"�H�F\"  " << endl ;
				validInput_npc_aka = false ;
				task_yes = 1 ;
				return task_yes ;
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


int task_npc_aka_mussel( int B1 , int B2 , int B3 , int B4 , int B5 , int B6 , int B7 , int B8 , int B9 ) // ���� �H�F�n�� 
{
	if( B1==0 )
	{
		B1='�F' ;
		return B1;
	}
	else if( B2==0 )
	{
		B2='�F' ;
		return B2 ;
	}
	else if( B3==0 )
	{
		B3='�F' ;
		return B3 ;
	}
	else if( B4==0 )
	{
		B4='�F' ;
		return B4 ;
	}
	else if( B5==0 )
	{
		B5='�F' ;
		return B5 ;
	}
	else if( B6==0 )
	{
		B6='�F' ;
		return B6 ;
	}
	else if( B7==0 )
	{
		B7='�F' ;
		return B7 ;
	}
	else if( B8==0 )
	{
		B8='�F' ;
		return B8 ;
	}
	else if( B9==0 )
	{
		B9='�F' ;
		return B9 ;
	}
}







