#define _CRT_SECURE_NO_WARNINGS
#include "io.h"
#include "stdio.h"


int scan(const char* _f, void* _x)
{
	while (1)
	{
		printf("����: ");
		if (scanf(_f, _x) != 1)
			printf("���������� �����\n");
		else
		{
			if (getchar());
			return 1;
		}
		if (getchar());
	}
}