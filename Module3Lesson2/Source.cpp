#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");

	srand(time(NULL));

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int n = 0;
	printf("������� ����� �������: ");
	scanf("%d", &n);

	switch (n)
	{
	case 1:
	{
		//1.	������ � ���������� ��� �����. ����������, ��� ������, �������� ��������� ��� ������ �������� �������� ���� �����. ����� ������� � ���� ���������
		int a = 0, b = 0;
		printf("������� ����� �: ");
		scanf("%d", &a);

		printf("������� ����� b: ");
		scanf("%d", &b);

		int square = 0, absNumbers = 0;
		square = pow(a, 2) - pow(b, 2);
		absNumbers = fabs(pow(a - b, 2));

		if (square > absNumbers)
		{
			printf("�������� ��������� ������, ��� ������ �������� �������� �����\n");
		}
		else
		{
			printf("������ �������� �������� ������, ��� �������� ��������� �����\n");
		}
	}
	break;

	case 2:
	{
		//2.	������ � ���������� �������������� ������� � ������ ����� � ����������, � ����� ��������� ��� ��������� (� ��������� ��� ��������).
		int shirota = 0, dolgota = 0;
		printf("������� ������: ");
		scanf("%d", &shirota);

		printf("������� �������: ");
		scanf("%d", &dolgota);

		if (shirota >= -90 && shirota < 0)
		{
			if (dolgota >= -180 && dolgota < 0)
			{
				SetConsoleTextAttribute(hConsole, 13);
				printf("�� ���������� � �������� ������ � �������� ���������\n");
			}
			else if (dolgota >= 0 && dolgota <= 180)
			{
				SetConsoleTextAttribute(hConsole, 11);
				printf("�� ���������� � �������� ������ � ��������� ���������\n");
			}
		}
		else if (shirota >= 0 && shirota <= 90)
		{
			if (dolgota >= -180 && dolgota < 0)
			{
				SetConsoleTextAttribute(hConsole, 12);
				printf("�� ���������� � ����� ������ � �������� ���������\n");
			}
			else if (dolgota >= 0 && dolgota <= 180)
			{
				SetConsoleTextAttribute(hConsole, 10);
				printf("�� ���������� � ����� ������ � ��������� ���������\n");
			}
		}
		SetConsoleTextAttribute(hConsole, 15);
	}
	break;

	case 3:
	{
		//1.	�������� ��������� ���������� ��������� �����������, ���� �� �������� � ������������ ��������������� 20% ������. ������ ����������������� ��������� � ���� ������ (����� �� 1 �� 7).

		float conversation = 0;
		int day = 0;
		printf("������� ������������ ���������: ");
		scanf("%f", &conversation);

		printf("������� ���� ������: ");
		scanf("%d", &day);

		switch (day)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		{
			printf("��������� ���������: %f\n", conversation * (float)2);
		}
		break;

		case 6:
		case 7:
		{
			float weekendPrice = 0;
			weekendPrice = (conversation*(float)2) - ((conversation*(float)2)*(float)0.2);
			printf("��������� ���������: %f\n", weekendPrice);
		}
		break;
		}
	}
	break;

	case 4:
	{
		//2.	��������� ��������� ������� � ������ ������. ������ 5% ���������������, ���� ����� ������� ��������� 500 ����� � 10%, ���� ������ 1000 �����.
		float sum = 0;
		printf("������� ����� �������: ");
		scanf("%f", &sum);

		if (sum > 500)
		{
			float sumTotal = 0;
			sumTotal = sum - (sum*(float)0.05);

			printf("����� � ������: %f\n", sumTotal);
		}
		else if (sum > 1000)
		{
			float sumTotal = 0;
			sumTotal = sum - (sum*(float)0.1);

			printf("����� � ������: %f\n", sumTotal);
		}
		else if (sum <= 500)
		{
			printf("����� � ������: %f\n", sum);
		}
	}
	break;

	case 5:
	{
		//3.	������ � ������ ����� �� 1 �� 12. �� ������ ������ ������ ��������� � ������� ����. ���� ������������ ������ ������������ �����, ��������� ������ ������ ��������� �� ������
		int month = 0;
		printf("������� ����� ������: ");
		scanf("%d", &month);

		if (month >= 3 && month <= 5)
		{
			SetConsoleTextAttribute(hConsole, 10);
			printf("������ �����\n");
		}
		else if (month >= 6 && month <= 8)
		{
			SetConsoleTextAttribute(hConsole, 11);
			printf("������ ����\n");
		}
		else if (month >= 9 && month <= 11)
		{
			SetConsoleTextAttribute(hConsole, 12);
			printf("������ �����\n");
		}
		else if (month == 12 || month == 1 || month == 2)
		{
			SetConsoleTextAttribute(hConsole, 13);
			printf("������ ����\n");
		}
		else
		{
			printf("������ ������ ���!\n");
		}

		SetConsoleTextAttribute(hConsole, 15);
	}
	break;

	case 6:
	{
		//4.	���� ��� ����� a, b, c. ����������, ������� �� ����� ��� ���� �� ���� ���� ������
		int a = 0, b = 0, c = 0;
		a = 1 + rand() % 100;
		b = 1 + rand() % 100;
		c = 1 + rand() % 100;

		if (a == b || a == c || b == c)
			printf("����� ���� ����� ���� ���� ������\n");
		else
			printf("����� ���� ����� ��� �� ����� ���� ������\n");
	}
	break;

	case 7:
	{
		//5.	�������� ��������� ��� ����������� ������� ����� �� ������� �������� ������� � ������� ��������� (���� � � 6 �� 12, ���� � � 12 �� 18, ����� � � 18 �� 24, ���� � � 0 �� 6).
		int dayTime = 0;
		printf("������� ����� �����: ");
		scanf("%d", &dayTime);

		if (dayTime >= 0 && dayTime < 6)
		{
			SetConsoleTextAttribute(hConsole, 13);
			printf("������ ����\n");
		}
		else if (dayTime >= 6 && dayTime < 12)
		{
			SetConsoleTextAttribute(hConsole, 10);
			printf("������ ����\n");
		}
		else if (dayTime >= 12 && dayTime < 18)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("������ ����\n");
		}
		else if (dayTime >= 18 && dayTime <= 24)
		{
			SetConsoleTextAttribute(hConsole, 11);
			printf("������ �����\n");
		}
		else
		{
			printf("������� ���������� �����!\n");
		}

		SetConsoleTextAttribute(hConsole, 15);
	}
	break;

	case 8:
	{
		//1.	���� ����������� �����. ����������:   
		//a.������ �� � ���� ����� 5;
		//b.������ �� � ���� ����� �.

		int x = 0, a = 0;

		x = 10 + rand() % 99;

		printf("������� ����� �: ");
		scanf("%d", &a);

		if (x / 10 == 5 || a % 10 == 5)
			printf("����� 5 ������ � �������� ��������� ����������� �����. ����� � = %d\n", x);
		else
			printf("����� 5 �� ������ � �������� ��������� ����������� �����. ����� � = %d\n", x);

		if (x / 10 == a || x % 10 == a)
			printf("����� a ������ � �������� ��������� ����������� �����\n");
		else
			printf("����� � �� ������ � �������� ��������� ����������� �����\n");
	}
	break;

	case 9:
	{
		//2.	�������� ���������, ������� ��� ����� ����� � ��������� �� 1 �� 99 ��������� � ���� ����� "�������" � ���������� �����. ��������, 1 �������, 5 ������, 42 �������
		int kop = 0;
		kop = 1 + rand() % 99;

		if (kop % 10 == 1 && kop != 11)
			printf("%d �������\n", kop);
		else if ((kop % 10 == 2 && kop != 12) || (kop % 10 == 3 && kop != 13) || (kop % 10 == 4 && kop != 14))
			printf("%d �������\n", kop);
		else
			printf("%d ������\n", kop);
	}
	break;

	case 10:
	{
		//3.	���� ����������� �������������� �����. ��������, �������� �� ��� ����������� (�������� ��������� ����� ������� � ������ ������).
		int number = 0;
		number = 1000 + rand() % 9999;

		int x1 = 0, x2 = 0, x3 = 0, x4 = 0;//7231
		x1 = number % 10;					//1
		x2 = number / 10;					//723
		x3 = x2 % 10;						//3
		x4 = x2 / 10;						//72

		if ((x4 / 10) == x1 && (x4 % 10) == x3)
			printf("��� ����� ��������� = %d\n", number);
		else
			printf("��� ����� �� ��������� = %d\n", number);
	}
	break;

	case 11:
	{
		//1.	���� ��� ����� a � b. ����������� � ������� ��������, � ���������� �������� ����� ������ ���� ���� �� ���������������, 
		//���� ��� ����� ������ ���� � ����� �������� �� ����, ���� ��� �� ���.
		//1 a = -3;  b = 3.5; 2 a = 5.8;  b = 2.7; 3 a = -8;  b = -3.5;
		float a = 0, b = 0;
		a = -100 + rand() % 100;
		b = -100 + rand() % 100;

		if ((a > 0 && b < 0) || (a < 0 && b > 0))
			printf("a = %f; b = %f\n", -a, -b);
		else
			printf("a = 0; b = 0\n");
	}
	break;

	case 12:
	{
		//2.	�������� ����� �� ��������.  ������ � � ����� ����������� 500��, � ���� ������������ -750��. 
		//������ - � ����� ����������� 400��, � ���� ������������ -600��. 
		//������� - � ����� ����������� 350��, � ���� ������������ -550��. 
		//��������� - � ����� ����������� 600��, � ���� ������������ � 900��. 
		//���� ����� ������������ �� 45 ����� � ������ 20%, �� 20 ����� � ������ 10%. ���������� ��������� ������. ������������� ��������� ������ �����.

		unsigned char city, trip;
int days = 0;
start:
//system("pause");
//system("cls");
		printf("������� ����� (A - ������, T - ������, S - �������, K - ���������)"
			   " \n(O - � ���� �������, R - � ��� �������)"
			"\n�� ������� ����� �� ������ ����������� �����\n\n"
		"------------------------------------\n");

		cin.get();
		scanf("%c %c %d", &city,&trip, &days);

		/*printf("������� ����������� : ");
		scanf("%c", );*/

		
	
		switch (city)
		{
		case 'A':
		{
			if (trip == 'O')
			{
				if (days >= 45)
				{
					float sum = 500, totalSum = 0;
					totalSum = sum - (sum*(float)0.2);
					printf("��������� ������ � ���� ������� �� ������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� 45 ����� �� ������: 20%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", totalSum);
				}
				else if (days >= 20 && days < 45)
				{
					float sum = 500, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("��������� ������ � ���� ������� �� ������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� 20 ����� �� ������: 10%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", totalSum);
				}
				else
				{
					float sum = 500, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("��������� ������ � ���� ������� �� ������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� %d ����� �� ������: ���\n", days);

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", sum);
				}
				SetConsoleTextAttribute(hConsole, 15);
			}
			else if (trip == 'R')
			{
				if (days >= 45)
				{
					float sum = 750, totalSum = 0;
					totalSum = sum - (sum*(float)0.2);
					printf("��������� ������ � ��� ������� ��/�� ������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� 45 ����� �� ������: 20%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", totalSum);
				}
				else if (days >= 20 && days < 45)
				{
					float sum = 750, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("��������� ������ � ��� ������� ��/�� ������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� 20 ����� �� ������: 10%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", totalSum);
				}
				else
				{
					float sum = 750, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("��������� ������ � ��� ������� ��/�� ������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� %d ����� �� ������: ���\n", days);

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", sum);
				}
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
			{
				printf("����������� ������� �����������! ��� ��� ������� ��������� ��� ������!\n");
				goto start;
			}
		}
		break;

		case 'T':
		{
			if (trip == 'O')
			{
				if (days >= 45)
				{
					float sum = 400, totalSum = 0;
					totalSum = sum - (sum*(float)0.2);
					printf("��������� ������ � ���� ������� �� ������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� 45 ����� �� ������: 20%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", totalSum);
				}
				else if (days >= 20 && days < 45)
				{
					float sum = 400, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("��������� ������ � ���� ������� �� ������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� 20 ����� �� ������: 10%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", totalSum);
				}
				else
				{
					float sum = 400, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("��������� ������ � ���� ������� �� ������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� %d ����� �� ������: ���\n", days);

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", sum);
				}
				SetConsoleTextAttribute(hConsole, 15);
			}
			else if (trip == 'R')
			{
				if (days >= 45)
				{
					float sum = 600, totalSum = 0;
					totalSum = sum - (sum*(float)0.2);
					printf("��������� ������ � ��� ������� ��/�� ������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� 45 ����� �� ������: 20%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", totalSum);
				}
				else if (days >= 20 && days < 45)
				{
					float sum = 600, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("��������� ������ � ��� ������� ��/�� ������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� 20 ����� �� ������: 10%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", totalSum);
				}
				else
				{
					float sum = 600, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("��������� ������ � ��� ������� ��/�� ������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� %d ����� �� ������: ���\n", days);

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", sum);
				}
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
			{
				printf("����������� ������� �����������! ��� ��� ������� ��������� ��� ������!\n");
				goto start;
			}
		}
		break;

		case 'S':
		{
			if (trip == 'O')
			{
				if (days >= 45)
				{
					float sum = 350, totalSum = 0;
					totalSum = sum - (sum*(float)0.2);
					printf("��������� ������ � ���� ������� �� ��������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� 45 ����� �� ������: 20%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", totalSum);
				}
				else if (days >= 20 && days < 45)
				{
					float sum = 350, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("��������� ������ � ���� ������� �� ��������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� 20 ����� �� ������: 10%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", totalSum);
				}
				else
				{
					float sum = 350, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("��������� ������ � ���� ������� �� ��������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� %d ����� �� ������: ���\n", days);

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", sum);
				}
				SetConsoleTextAttribute(hConsole, 15);
			}
			else if (trip == 'R')
			{
				if (days >= 45)
				{
					float sum = 550, totalSum = 0;
					totalSum = sum - (sum*(float)0.2);
					printf("��������� ������ � ��� ������� ��/�� ��������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� 45 ����� �� ������: 20%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", totalSum);
				}
				else if (days >= 20 && days < 45)
				{
					float sum = 550, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("��������� ������ � ��� ������� ��/�� ��������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� 20 ����� �� ������: 10%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", totalSum);
				}
				else
				{
					float sum = 550, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("��������� ������ � ��� ������� ��/�� ��������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� %d ����� �� ������: ���\n", days);

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", sum);
				}
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
			{
				printf("����������� ������� �����������! ��� ��� ������� ��������� ��� ������!\n");
				goto start;
			}
		}
		break;

		case 'K':
		{
			if (trip == 'O')
			{
				if (days >= 45)
				{
					float sum = 600, totalSum = 0;
					totalSum = sum - (sum*(float)0.2);
					printf("��������� ������ � ���� ������� �� ���������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� 45 ����� �� ������: 20%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", totalSum);
				}
				else if (days >= 20 && days < 45)
				{
					float sum = 600, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("��������� ������ � ���� ������� �� ���������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� 20 ����� �� ������: 10%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", totalSum);
				}
				else
				{
					float sum = 600, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("��������� ������ � ���� ������� �� ���������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� %d ����� �� ������: ���\n", days);

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", sum);
				}
				SetConsoleTextAttribute(hConsole, 15);
			}
			else if (trip == 'R')
			{
				if (days >= 45)
				{
					float sum = 900, totalSum = 0;
					totalSum = sum - (sum*(float)0.2);
					printf("��������� ������ � ��� ������� ��/�� ���������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� 45 ����� �� ������: 20%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", totalSum);
				}
				else if (days >= 20 && days < 45)
				{
					float sum = 900, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("��������� ������ � ��� ������� ��/�� ���������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� 20 ����� �� ������: 10%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", totalSum);
				}
				else
				{
					float sum = 900, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("��������� ������ � ��� ������� ��/�� ���������: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("������ �� ����� �� %d ����� �� ������: ���\n", days);

					SetConsoleTextAttribute(hConsole, 11);
					printf("����� � ������: %f\n", sum);
				}
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
			{
				printf("����������� ������� �����������! ��� ��� ������� ��������� ��� ������!\n");
				goto start;
			}
		}
		break;

		default:
		{
			printf("����������� ������ �����! ��� ��� ������� ��������� ��� ������!\n");
			goto start;
		}
		break;
		}

//
	}
	break;

	}



}