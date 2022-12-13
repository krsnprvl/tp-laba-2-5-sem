#include <iostream>
#include "KEEPER.h"
#include <Windows.h>


#define EXIT -1
#define CLEAR 0
#define SEEALL 1
#define ADD 2
#define DEL 3
#define EDIT 4
#define SEARCH_DEST 5
#define SEARCH_NUM 6
#define SEARCH_TIME 7


void msg()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	printf("Меню\n");
	printf("%d Выход\n", EXIT);
	printf("%d Очистить\n", CLEAR);
	printf("%d Вывести всё\n", SEEALL);
	printf("%d Добавить\n", ADD);
	printf("%d Редактировать\n", EDIT);
	printf("%d Удалить\n", DEL);
	printf("%d Поиск по направлению\n", SEARCH_DEST);
	printf("%d Поиск по поезду\n", SEARCH_NUM);
	printf("%d Поиск по времени\n", SEARCH_TIME);


}

int main()
{
	KEEPER cnt;
	msg();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);



	int t = 0;
	while (true)
	{
		printf("\nМеню\n");
		scan("%d", &t);
		switch (t)
		{

		case EXIT:
			return 0;

		case CLEAR:
			msg();
			break;

		case SEEALL:
			try {
				cnt.seeall();
			}
			catch (int e) {
				if (e == -1)
					cout << "ИСКЛЮЧЕНИЕ: элемент не добавлен" << endl;
			}
			break;


		case ADD:
			try	{
				cnt.add();
			}
			catch (char* m)	{
				printf("%s\n", m);
			};
			
			break;

		case EDIT:
			try {
				cnt.edit();
			}
			catch (int e) {
				if (e == -1)
					cout << "ИСКЛЮЧЕНИЕ: элемент не добавлен" << endl;
			}
			break;

		case DEL:
			try {
				cnt.delet();
			}
			catch (int e) {
				if (e == -1)
					cout << "ИСКЛЮЧЕНИЕ: элемент не добавлен" << endl;
			}
			break;

		case SEARCH_DEST:
			try {
				cnt.seeWithDestination();
			}
			catch (int e) {
				if (e == -1)
					cout << "ИСКЛЮЧЕНИЕ: элемент не добавлен" << endl;
			}
			
			break;

		case SEARCH_NUM:
			try {
				cnt.seeWithNumber();
			}
			catch (int e) {
				if (e == -1)
					cout << "ИСКЛЮЧЕНИЕ: элемент не добавлен" << endl;
			}
			
			break;

		case SEARCH_TIME:
			try {
				cnt.seeWithTime();
			}
			catch (int e) {
				if (e == -1)
					cout << "ИСКЛЮЧЕНИЕ: элемент не добавлен" << endl;
			}
			
			break;

		default:

			printf("Неизвестно:(\n");
			break;

		}
	}

	return 0;
}