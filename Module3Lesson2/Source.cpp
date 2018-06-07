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
	printf("введите номер задания: ");
	scanf("%d", &n);

	switch (n)
	{
	case 1:
	{
		//1.	Ввести с клавиатуры два числа. Определить, что больше, разность квадратов или модуль квадрата разности этих чисел. Ответ вывести в виде сообщения
		int a = 0, b = 0;
		printf("введите число а: ");
		scanf("%d", &a);

		printf("введите число b: ");
		scanf("%d", &b);

		int square = 0, absNumbers = 0;
		square = pow(a, 2) - pow(b, 2);
		absNumbers = fabs(pow(a - b, 2));

		if (square > absNumbers)
		{
			printf("разность квадратов больше, чем модуль квадрата разности чисел\n");
		}
		else
		{
			printf("модуль квадрата разности больше, чем разность квадратов чисел\n");
		}
	}
	break;

	case 2:
	{
		//2.	Ввести с клавиатуры географическую долготу и широту места и определить, в каком полушарии оно находится (в восточном или западном).
		int shirota = 0, dolgota = 0;
		printf("введите широту: ");
		scanf("%d", &shirota);

		printf("введите долготу: ");
		scanf("%d", &dolgota);

		if (shirota >= -90 && shirota < 0)
		{
			if (dolgota >= -180 && dolgota < 0)
			{
				SetConsoleTextAttribute(hConsole, 13);
				printf("вы находитесь в северной широте и западном полушарии\n");
			}
			else if (dolgota >= 0 && dolgota <= 180)
			{
				SetConsoleTextAttribute(hConsole, 11);
				printf("вы находитесь в северной широте и восточном полушарии\n");
			}
		}
		else if (shirota >= 0 && shirota <= 90)
		{
			if (dolgota >= -180 && dolgota < 0)
			{
				SetConsoleTextAttribute(hConsole, 12);
				printf("вы находитесь в южной широте и западном полушарии\n");
			}
			else if (dolgota >= 0 && dolgota <= 180)
			{
				SetConsoleTextAttribute(hConsole, 10);
				printf("вы находитесь в южной широте и восточном полушарии\n");
			}
		}
		SetConsoleTextAttribute(hConsole, 15);
	}
	break;

	case 3:
	{
		//1.	Написать программу вычисления стоимости переговоров, если по субботам и воскресеньям предоставляется 20% скидка. Ввести продолжительность разговора и день недели (цифра от 1 до 7).

		float conversation = 0;
		int day = 0;
		printf("введите длительность разговора: ");
		scanf("%f", &conversation);

		printf("введите день недели: ");
		scanf("%d", &day);

		switch (day)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		{
			printf("стоимость разговора: %f\n", conversation * (float)2);
		}
		break;

		case 6:
		case 7:
		{
			float weekendPrice = 0;
			weekendPrice = (conversation*(float)2) - ((conversation*(float)2)*(float)0.2);
			printf("стоимость разговора: %f\n", weekendPrice);
		}
		break;
		}
	}
	break;

	case 4:
	{
		//2.	Вычислить стоимость покупки с учетом скидки. Скидка 5% предоставляется, если сумма покупки превышает 500 тенге и 10%, если больше 1000 тенге.
		float sum = 0;
		printf("введите сумму покупки: ");
		scanf("%f", &sum);

		if (sum > 500)
		{
			float sumTotal = 0;
			sumTotal = sum - (sum*(float)0.05);

			printf("сумма к оплате: %f\n", sumTotal);
		}
		else if (sum > 1000)
		{
			float sumTotal = 0;
			sumTotal = sum - (sum*(float)0.1);

			printf("сумма к оплате: %f\n", sumTotal);
		}
		else if (sum <= 500)
		{
			printf("сумма к оплате: %f\n", sum);
		}
	}
	break;

	case 5:
	{
		//3.	Ввести с экрана число от 1 до 12. По номеру месяца выдать сообщение о времени года. Если пользователь введет недопустимое число, программа должна выдать сообщение об ошибке
		int month = 0;
		printf("введите номер месяца: ");
		scanf("%d", &month);

		if (month >= 3 && month <= 5)
		{
			SetConsoleTextAttribute(hConsole, 10);
			printf("сейчас весна\n");
		}
		else if (month >= 6 && month <= 8)
		{
			SetConsoleTextAttribute(hConsole, 11);
			printf("сейчас лето\n");
		}
		else if (month >= 9 && month <= 11)
		{
			SetConsoleTextAttribute(hConsole, 12);
			printf("сейчас осень\n");
		}
		else if (month == 12 || month == 1 || month == 2)
		{
			SetConsoleTextAttribute(hConsole, 13);
			printf("сейчас зима\n");
		}
		else
		{
			printf("такого месяца нет!\n");
		}

		SetConsoleTextAttribute(hConsole, 15);
	}
	break;

	case 6:
	{
		//4.	Даны три числа a, b, c. Определить, имеется ли среди них хотя бы одна пара равных
		int a = 0, b = 0, c = 0;
		a = 1 + rand() % 100;
		b = 1 + rand() % 100;
		c = 1 + rand() % 100;

		if (a == b || a == c || b == c)
			printf("среди трех чисел есть пара равных\n");
		else
			printf("среди трех чисел нет ни одной пары равных\n");
	}
	break;

	case 7:
	{
		//5.	Написать программу для определения времени суток по данному текущему времени и вывести сообщение (утро – с 6 до 12, день – с 12 до 18, вечер – с 18 до 24, ночь – с 0 до 6).
		int dayTime = 0;
		printf("введите время суток: ");
		scanf("%d", &dayTime);

		if (dayTime >= 0 && dayTime < 6)
		{
			SetConsoleTextAttribute(hConsole, 13);
			printf("сейчас ночь\n");
		}
		else if (dayTime >= 6 && dayTime < 12)
		{
			SetConsoleTextAttribute(hConsole, 10);
			printf("сейчас утро\n");
		}
		else if (dayTime >= 12 && dayTime < 18)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("сейчас день\n");
		}
		else if (dayTime >= 18 && dayTime <= 24)
		{
			SetConsoleTextAttribute(hConsole, 11);
			printf("сейчас вечер\n");
		}
		else
		{
			printf("введите корректное время!\n");
		}

		SetConsoleTextAttribute(hConsole, 15);
	}
	break;

	case 8:
	{
		//1.	Дано двухзначное число. Определить:   
		//a.входит ли в него цифра 5;
		//b.входит ли в него цифра а.

		int x = 0, a = 0;

		x = 10 + rand() % 99;

		printf("введите число а: ");
		scanf("%d", &a);

		if (x / 10 == 5 || a % 10 == 5)
			printf("Цифра 5 входит в рандомно выбранное двухзначное число. Число Х = %d\n", x);
		else
			printf("Цифра 5 не входит в рандомно выбранное двухзначное число. Число Х = %d\n", x);

		if (x / 10 == a || x % 10 == a)
			printf("Цифра a входит в рандомно выбранное двухзначное число\n");
		else
			printf("Цифра а не входит в рандомно выбранное двухзначное число\n");
	}
	break;

	case 9:
	{
		//2.	Написать программу, которая при вводе числа в диапазоне от 1 до 99 добавляет к нему слово "копейка" в правильной форме. Например, 1 копейка, 5 копеек, 42 копейки
		int kop = 0;
		kop = 1 + rand() % 99;

		if (kop % 10 == 1 && kop != 11)
			printf("%d копейка\n", kop);
		else if ((kop % 10 == 2 && kop != 12) || (kop % 10 == 3 && kop != 13) || (kop % 10 == 4 && kop != 14))
			printf("%d копейки\n", kop);
		else
			printf("%d копеек\n", kop);
	}
	break;

	case 10:
	{
		//3.	Дано натуральное четырехзначное число. Выяснить, является ли оно палиндромом (читается одинаково слева направо и справа налево).
		int number = 0;
		number = 1000 + rand() % 9999;

		int x1 = 0, x2 = 0, x3 = 0, x4 = 0;//7231
		x1 = number % 10;					//1
		x2 = number / 10;					//723
		x3 = x2 % 10;						//3
		x4 = x2 / 10;						//72

		if ((x4 / 10) == x1 && (x4 % 10) == x3)
			printf("Это число палиндром = %d\n", number);
		else
			printf("Это число не палиндром = %d\n", number);
	}
	break;

	case 11:
	{
		//1.	Даны два числа a и b. Разработать и описать алгоритм, в результате которого числа меняют свой знак на противоположный, 
		//если они имеют разный знак и будут заменены на нули, если это не так.
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
		//2.	Закажите билет на авиарейс.  Алматы – в одном направлении 500тн, в двух направлениях -750тн. 
		//Астана - в одном направлении 400тн, в двух направлениях -600тн. 
		//Шымкент - в одном направлении 350тн, в двух направлениях -550тн. 
		//Караганда - в одном направлении 600гр, в двух направлениях – 900тн. 
		//Если билет заказывается за 45 суток – скидка 20%, за 20 суток – скидка 10%. Определить стоимость заказа. Предусмотреть обработку ошибок ввода.

		unsigned char city, trip;
int days = 0;
start:
//system("pause");
//system("cls");
		printf("Введите город (A - Алматы, T - Астана, S - Шымкент, K - Караганда)"
			   " \n(O - в одну сторону, R - в обе стороны)"
			"\nЗа сколько суток до вылета заказываете билет\n\n"
		"------------------------------------\n");

		cin.get();
		scanf("%c %c %d", &city,&trip, &days);

		/*printf("Введите направление : ");
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
					printf("Стоимость билета в одну сторону до Алматы: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за 45 суток до вылета: 20%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", totalSum);
				}
				else if (days >= 20 && days < 45)
				{
					float sum = 500, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("Стоимость билета в одну сторону до Алматы: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за 20 суток до вылета: 10%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", totalSum);
				}
				else
				{
					float sum = 500, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("Стоимость билета в одну сторону до Алматы: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за %d суток до вылета: нет\n", days);

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", sum);
				}
				SetConsoleTextAttribute(hConsole, 15);
			}
			else if (trip == 'R')
			{
				if (days >= 45)
				{
					float sum = 750, totalSum = 0;
					totalSum = sum - (sum*(float)0.2);
					printf("Стоимость билета в обе стороны до/из Алматы: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за 45 суток до вылета: 20%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", totalSum);
				}
				else if (days >= 20 && days < 45)
				{
					float sum = 750, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("Стоимость билета в обе стороны до/из Алматы: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за 20 суток до вылета: 10%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", totalSum);
				}
				else
				{
					float sum = 750, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("Стоимость билета в обе стороны до/из Алматы: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за %d суток до вылета: нет\n", days);

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", sum);
				}
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
			{
				printf("Неправильно введено направление! Еще раз введите корректно все данные!\n");
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
					printf("Стоимость билета в одну сторону до Астаны: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за 45 суток до вылета: 20%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", totalSum);
				}
				else if (days >= 20 && days < 45)
				{
					float sum = 400, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("Стоимость билета в одну сторону до Астаны: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за 20 суток до вылета: 10%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", totalSum);
				}
				else
				{
					float sum = 400, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("Стоимость билета в одну сторону до Астаны: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за %d суток до вылета: нет\n", days);

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", sum);
				}
				SetConsoleTextAttribute(hConsole, 15);
			}
			else if (trip == 'R')
			{
				if (days >= 45)
				{
					float sum = 600, totalSum = 0;
					totalSum = sum - (sum*(float)0.2);
					printf("Стоимость билета в обе стороны до/из Астаны: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за 45 суток до вылета: 20%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", totalSum);
				}
				else if (days >= 20 && days < 45)
				{
					float sum = 600, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("Стоимость билета в обе стороны до/из Астаны: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за 20 суток до вылета: 10%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", totalSum);
				}
				else
				{
					float sum = 600, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("Стоимость билета в обе стороны до/из Астаны: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за %d суток до вылета: нет\n", days);

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", sum);
				}
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
			{
				printf("Неправильно введено направление! Еще раз введите корректно все данные!\n");
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
					printf("Стоимость билета в одну сторону до Шымкента: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за 45 суток до вылета: 20%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", totalSum);
				}
				else if (days >= 20 && days < 45)
				{
					float sum = 350, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("Стоимость билета в одну сторону до Шымкента: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за 20 суток до вылета: 10%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", totalSum);
				}
				else
				{
					float sum = 350, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("Стоимость билета в одну сторону до Шымкента: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за %d суток до вылета: нет\n", days);

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", sum);
				}
				SetConsoleTextAttribute(hConsole, 15);
			}
			else if (trip == 'R')
			{
				if (days >= 45)
				{
					float sum = 550, totalSum = 0;
					totalSum = sum - (sum*(float)0.2);
					printf("Стоимость билета в обе стороны до/из Шымкента: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за 45 суток до вылета: 20%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", totalSum);
				}
				else if (days >= 20 && days < 45)
				{
					float sum = 550, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("Стоимость билета в обе стороны до/из Шымкента: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за 20 суток до вылета: 10%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", totalSum);
				}
				else
				{
					float sum = 550, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("Стоимость билета в обе стороны до/из Шымкента: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за %d суток до вылета: нет\n", days);

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", sum);
				}
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
			{
				printf("Неправильно введено направление! Еще раз введите корректно все данные!\n");
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
					printf("Стоимость билета в одну сторону до Караганды: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за 45 суток до вылета: 20%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", totalSum);
				}
				else if (days >= 20 && days < 45)
				{
					float sum = 600, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("Стоимость билета в одну сторону до Караганды: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за 20 суток до вылета: 10%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", totalSum);
				}
				else
				{
					float sum = 600, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("Стоимость билета в одну сторону до Караганды: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за %d суток до вылета: нет\n", days);

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", sum);
				}
				SetConsoleTextAttribute(hConsole, 15);
			}
			else if (trip == 'R')
			{
				if (days >= 45)
				{
					float sum = 900, totalSum = 0;
					totalSum = sum - (sum*(float)0.2);
					printf("Стоимость билета в обе стороны до/из Караганды: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за 45 суток до вылета: 20%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", totalSum);
				}
				else if (days >= 20 && days < 45)
				{
					float sum = 900, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("Стоимость билета в обе стороны до/из Караганды: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за 20 суток до вылета: 10%\n");

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", totalSum);
				}
				else
				{
					float sum = 900, totalSum = 0;
					totalSum = sum - (sum*(float)0.1);
					printf("Стоимость билета в обе стороны до/из Караганды: %f\n", sum);

					SetConsoleTextAttribute(hConsole, 10);
					printf("Скидка за заказ за %d суток до вылета: нет\n", days);

					SetConsoleTextAttribute(hConsole, 11);
					printf("ИТОГО к оплате: %f\n", sum);
				}
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
			{
				printf("Неправильно введено направление! Еще раз введите корректно все данные!\n");
				goto start;
			}
		}
		break;

		default:
		{
			printf("Неправильно введен город! Еще раз введите корректно все данные!\n");
			goto start;
		}
		break;
		}

//
	}
	break;

	}



}