// ���Y�� 

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>  

// ²�Ƶ{���X 

using namespace std;

void run_main( int x ,int y, int run_x , int run_y , bool validInput ,char run );// �a�Ϩ禡 
void bag_main();// �I�]�禡

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////�D�C���禡 

int main()// �}�l ����{�� 
{
	
	// �]�w��l�� �P �ŧi�ܼƦW�� 
	
	char run ; // �q�� & ���a�X��  
	
	int run_x=6 , run_y=6 , x=1 , y=1 ;
	
	int start_input , end=0 ; // ���� �}�l 
	
	int position ; // 
	
	bool start_output = true , validInput ; // bool ���� �O �P �_ 
	
	srand( time(0) ); // �^���{�b �ɶ� ��Ѽ� 
	
	//�H�U�}�l�i�J�C���{�� 
	
	cout << "�w��C�� \"mini RPGame\" �p�C��" << endl << endl ; // �w�� �P �򥻾ާ@���� 
	cout << "      �򥻾ާ@:" << endl ;
	cout << "      ��J W A S D �����V  |  ��J E �ݭI�]  |  ��J Q �����C��" << endl;
	cout << "      (�i�@����J�������B��) (�����j�p�g)" << endl << endl ; 
	
	cout << "�п�J -1 �}�l�C��" << endl ;
	
	while(start_output) //�P�_ �C���}�l 
	{
	cin >> start_input ;
	
	if(start_input == -1) //�� bool ���C���}�l
		{
			start_output = false ;
		}
	}//�P�_ �C���}�l
	
	cout << endl << endl << endl ;
		
	validInput = true ; //��J���T �w�]���� 
	
	run_main( x , y , run_x , run_y , validInput , run ); //�Ĥ@����ܦa�� 
	
	while (validInput)
	{
		
		cin >> run ;//���a��J�ާ@ 
		
		switch(run) // �P�_���a��J�����G 
		{ 
			case 'w' : 
				run_y-- ;
				if(run_y < 1 )
				{
					run_y++ ;
					cout << "                                        �����L�h�F " << endl ;
				}
				if( run_x == 3 && run_y == 4 )
				{
					run_y++ ;
					cout << "                                        �� : �L����i�H��L�ڪ��ڤ� �쩳�O������ " << endl ;
				}
				run_main( x , y , run_x , run_y , validInput , run );
				break ;
						 
			case 's' :
				run_y++ ;
				if(run_y > 11 )
				{
					run_y-- ;
					cout << "                                        �����L�h�F " << endl ;
				}
				if( run_x == 3 && run_y == 4 )
				{
					run_y-- ;
					cout << "                                        �� : �L����i�H��L�ڪ��ڤ� �쩳�O������ " << endl ;
				}
				run_main( x , y , run_x , run_y , validInput , run );
				break ;
						 
			case 'a' :
				run_x-- ;
				if(run_x < 1 )
				{
					run_x++ ;
					cout << "                                        �����L�h�F " << endl ;
				}
				if( run_x == 3 && run_y == 4 )
				{
					run_x++ ;
					cout << "                                        �� : �L����i�H��L�ڪ��ڤ� �쩳�O������ " << endl ;
				}
				run_main( x , y , run_x , run_y , validInput , run );
				break ;
				
			case 'd' :
				run_x++ ;
				if(run_x > 11 )
				{
					run_x-- ;
					cout << "                                        �����L�h�F " << endl ;
				}
				if( run_x == 3 && run_y == 4 )
				{
					run_x-- ;
					cout << "                                        �� : �L����i�H��L�ڪ��ڤ� �쩳�O������ " << endl ;
				}
				run_main( x , y , run_x , run_y , validInput , run );
				break ;
				
			case 'W' : 
				run_y-- ;
				if(run_y < 1 )
				{
					run_y++ ;
					cout << "                                        �����L�h�F " << endl ;
				}
				if( run_x == 3 && run_y == 4 )
				{
					run_y++ ;
					cout << "                                        �� : �L����i�H��L�ڪ��ڤ� �쩳�O������ " << endl ;
				}
				run_main( x , y , run_x , run_y , validInput , run );
				break ;
						 
			case 'S' :
				run_y++ ;
				if(run_y > 11 )
				{
					run_y-- ;
					cout << "                                        �����L�h�F " << endl ;
				}
				if( run_x == 3 && run_y == 4 )
				{
					run_y-- ;
					cout << "                                        �� : �L����i�H��L�ڪ��ڤ� �쩳�O������ " << endl ;
				}
				run_main( x , y , run_x , run_y , validInput , run );
				break ;
						 
			case 'A' :
				run_x-- ;
				if(run_x < 1 )
				{
					run_x++ ;
					cout << "                                        �����L�h�F " << endl ;
				}
				if( run_x == 3 && run_y == 4 )
				{
					run_x++ ;
					cout << "                                        �� : �L����i�H��L�ڪ��ڤ� �쩳�O������ " << endl ;
				}
				run_main( x , y , run_x , run_y , validInput , run );
				break ;
				
			case 'D' :
				run_x++ ;
				if(run_x > 11 )
				{
					run_x-- ;
					cout << "                                        �����L�h�F " << endl ;
				}
				if( run_x == 3 && run_y == 4 )
				{
					run_x-- ;
					cout << "                                        �� : �L����i�H��L�ڪ��ڤ� �쩳�O������ " << endl ;
				}
				run_main( x , y , run_x , run_y , validInput , run );
				break ;
					
			case 'q'  : //���a��󦹧� 
				cout << endl ;
				cout << "                                        �U���A�Ӫ��� �t�t" << endl << endl ;	
				validInput = false ;	
				break ;
				
			case 'Q'  : //���a��󦹧� 
				cout << endl ;	
				cout << "                                        �U���A�Ӫ��� �t�t" << endl << endl ;
				validInput = false ;
				break ;
				
			case 'e'  : //�}�ҭI�] 
				cout << endl ;
				bag_main();
				cout << endl << endl ;		
				break ;
				
			case 'E'  : //�}�ҭI�]
				cout << endl ;	
				bag_main();
				cout << endl << endl ;
				break ;
				
			default: 
				cout << "                                        -----error-----�Ф��n�åX-----error-----" << endl << endl ;
				validInput = false ; // ��J ���X�W
		}
	}
	while( end != -1 ) //�������� 
	{
			cout << "�п�J (-1 ��������)" << endl ;
			cin >> end ;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////�a�Ϩ禡

void run_main( int x ,int y, int run_x , int run_y , bool validInput ,char run ) // �a�Ϩ禡
{
	if (validInput)
	{
		cout << "                         �����a��" << endl << endl ;
		for(; y<=11 ; y++ )
		{
			for(; x<=11 ; x++ )
			{
				if(x != run_x || y != run_y)//��� �� 
				{
					if(x != 3 || y != 4)
					{
						cout << " �f" ;
					}
					else if(x == 3 && y == 4) //��� ���� 
					{
						cout << " ��" ;
					}
				}
				else if(x == run_x && y == run_y) //��� ���a 
				{
					cout << " ��" ;
				}
			}
			x=1;
			cout << endl ;
		}
	} 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////�I�]�禡

void bag_main()// �I�]�禡
{
	int take;
	
	cout << "                      �] �]" << endl << endl ;
	
	for(int z=1; z<=9 ; z++ )
	{
		cout << " ��" ; 
	} 
	cout << endl ;

	cout << " 1  2  3  4  5  6  7  8  9" ; 
		
	cout << endl ;
	
	cout << "                                        ��J�s���������~ -1�����]�]" << endl ;
	
	cin >> take ;
	
	switch(take) // �P�_���a��J�����G 
		{ 
			case 1 : 
				cout << "                                        ���� 1" << endl ; 
				break ;
				 
			case 2 : 
				cout << "                                        ���� 2" << endl ; 
				break ;
			
			case 3 : 
				cout << "                                        ���� 3" << endl ; 
				break ;
			
			case 4 : 
				cout << "                                        ���� 4" << endl ; 
				break ;
				
			case 5 : 
				cout << "                                        ���� 5" << endl ; 
				break ;
				 
			case 6 : 
				cout << "                                        ���� 6" << endl ; 
				break ;
			
			case 7 : 
				cout << "                                        ���� 7" << endl ; 
				break ;
			
			case 8 : 
				cout << "                                        ���� 8" << endl ; 
				break ;
				
			case 9 : 
				cout << "                                        ���� 9" << endl ; 
				break ;
				
			case 0 : 
				cout << "                                        �����I�]" << endl ; 
				break ;
			
			default: 
				cout << "                                        -----error-----�Ф��n�åX-----error-----" << endl << endl ;
		}
}




