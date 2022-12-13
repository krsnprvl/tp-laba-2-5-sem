#include "KEEPER.h"
#include "io.h"


void KEEPER::add()
{
	TRAIN* item = new TRAIN;
	cin >> *item;
	TRAIN** new_arr = new TRAIN * [size + 1];

	if (new_arr == nullptr)
		throw "������ ��������� ������";


	for (int i = 0; i < size; i++)
		new_arr[i] = arr[i];
	

	new_arr[size] = item;
	delete arr; 
	arr = new_arr;

	size++;

	sorting();
}

void KEEPER::seeall()
{
	if (size == 0)
		throw - 1;
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << *arr[i];
		}
	}
}

void KEEPER::edit()
{
	if (size == 0)
		throw - 1;
	else
	while (true)
	{
		cout << "��������� " << size << " ���������" << endl;
		printf("-1 �����\n1 �������� ����� ��� ��������������\n");
		int in = 0;
		scan("%d", &in);

		switch (in)
		{
		case -1:
			return;

		case 1:
		{
			int num = -1;
			
			while (num < 1 || num > size)
			{
				cout << "������� ����� �������� ��� ��������������: ";
				scan("%d", &num);
			}
			
			cout << "������� ����� ���������:" << endl;
			cin >> *arr[num - 1];
			sorting();
		}

		break;

		default:
			printf("����������:(\n");
		}
	}
}

void KEEPER::delet()
{
	if (size == 0)
		throw -1;
	else
	{
		cout << "��������� " << size << " ���������" << endl;
		int num = -1;
		
		while (num < 1 || num > size)
		{
			cout << "������� ����� �������� ��� ��������: " << endl;
			scan("%d", &num);
		}

		size--;
		for (int i = num - 1; i < size; i++)
			arr[i] = arr[i + 1];

		sorting();
	}
	
}

void KEEPER::sorting()
{
	if (size == 1)
			return;
	if (size == 0)
		return;
	else
	{
		int i = 0;
		for (; i < size-1; )
		{
			if (*arr[i]->getNumber() > *arr[i + 1]->getNumber())
			{
				TRAIN* temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				i = 0;
			}
			else
				i++;

		}
	}
}

void KEEPER::seeWithDestination()
{
	if (size == 0)
		throw - 1;
	string dest;
	cout << "������� ����� ����������: ";
	cin >> dest;

	cout << "����� �� " << dest << endl;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->getDestination() == dest)
			count++;
	}
	if (count == 0)
		cout << "������ �� �������" << endl;
	else
	{
		string item_word = (count > 1) ? (" �������") : (" �����");
		cout << "�������: " << count << item_word << endl;
	}

	for (int i = 0; i < size; i++)
	{
		if (arr[i]->getDestination() == dest)
			cout << "����� ������������ � " << arr[i]->getDeparture() << " ��� ������� " << arr[i]->getNumber() << endl;
	}
}

void KEEPER::seeWithNumber()
{
	if (size == 0)
		throw - 1;
	string num;
	cout << "������� ����� ������: ";
	cin >> num;

	cout << "����� �� " << num << endl;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (*arr[i]->getNumber() == num)
			count++;
	}
	if (count == 0)
		cout << "������ �� �������" << endl;
	else
	{
		string item_word = (count > 1) ? (" �������") : (" �����");
		cout << "�������: " << count << item_word << endl;
	}

	for (int i = 0; i < size; i++)
	{
		if (*arr[i]->getNumber() == num)
			cout << "����� ������������ � " << arr[i]->getDeparture() << " � " << arr[i]->getDestination() << endl;
	}
}

void KEEPER::seeWithTime()
{
	if (size == 0)
		throw - 1;
	TIME time;
	cout << "������� ����� �����������: ";
	cin >> time;

	cout << "����� �� " << time << endl;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->getDeparture() == time)
			count++;
	}
	if (count == 0)
		cout << "������ �� �������" << endl;
	else
	{
		string item_word = (count > 1) ? (" �������") : (" �����");
		cout << "�������: " << count << item_word << endl;
	}

	for (int i = 0; i < size; i++)
	{
		if (arr[i]->getDeparture() == time)
			cout << "����� ������������ � " << arr[i]->getDeparture() << "��� �������" << arr[i]->getNumber() << endl;
	}
}