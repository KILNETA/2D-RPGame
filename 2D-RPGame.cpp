// ���Y�� 

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>  

// ²�Ƶ{���X 

using namespace std;



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
	
//	cout << "�w��C�� \"���y��\" �p�C��" << endl << endl ; // �w�� �P �W�h���� 
//	cout << "�W�h:" << endl ;
//	cout << "���a�P�q�� �i��1~5���A" << endl ;
//	cout << "��ܦn��A�ƫ� �C���Y�}�l" << endl ;
//	cout << "�q�� �Ѫ̲�@�� �Ӫ̤���" << endl << endl ;
	
	cout << "�п�J -1 �}�l�C��" << endl ;
	
	while(start_output) //�P�_ �C���}�l 
	{
	cin >> start_input ;
	
	if(start_input == -1) //�� bool ���C���}�l
		{
			start_output = false ;
		}
	}//�P�_ �C���}�l
	
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
							cout << " �f" ;
						}
						else if(x == 3 && y == 4)
						{
							cout << " ��" ;
						}
					}
					else if(x == run_x && y == run_y)
					{
						cout << " ��" ;
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
		
		cout << "�п�J W A S D �����V ��J E �����C�� " << endl ;
		cout << "(�i�@����J�������B��) (�����j�p�g)" << endl ; 
		cin >> run ;
		
		switch(run) // �P�_���a�X�������G 
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
				break ;
					
			case 'e'  : //���a��󦹧� 
				cout << endl ;
				cout << "�U���A�Ӫ��� �t�t" << endl << endl ;		
				break ;
				
			case 'E'  : //���a��󦹧� 
				cout << endl ;	
				cout << "�U���A�Ӫ��� �t�t" << endl << endl ;	
				break ;
				
			default: 
				cout << "-----error-----�Ф��n�åX-----error-----" << endl << endl ;
				validInput = false ; // �X�� ���X�W
		}
		
	}
	
	while( end != -1 )
		{
			cout << "�п�J (-1 ���}�C��)" << endl ;
			cin >> end ;
		}
	
}
