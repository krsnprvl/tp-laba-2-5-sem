#include "TRAIN.h"

using namespace std;

	bool TIME::isCorrect()
	{
		if (hour < 0 || hour > 24)
			return false;
		if (min < 0 || min > 59)
			return false;
		return true;
	}

	void TIME::setDefault()
	{
		hour = 0; min = 0;
		printf("установленно время по умолчанию\n");
	}


	int TIME::getHour()
	{
		return hour;
	}

	int TIME::getMin()
	{
		return min;
	}

	void TIME::set(int h, int m)
	{
		hour = h;
		min = m;
		if (!isCorrect())
		{
			printf("неверное время\n");
			setDefault();
		}
	}

	std::ostream& operator<<(std::ostream& out, const TIME& ptr)
	{
		(ptr.hour < 10) ? (out << "0" << ptr.hour) : (out << ptr.hour);
		out << ":";
		(ptr.min < 10) ? (out << "0" << ptr.min) : (out << ptr.min);

		return out << endl;
	}


	std::istream& operator>>(std::istream& in, TIME& time)
	{
		int h = -1;
		int m = -1;
		while (h < 0 || h > 23)
		{
			std::cout << "Часы: ";
			scan("%d", &h);
		}
		time.hour = h;
		while (m < 0 || m > 59)
		{
			std::cout << "Минуты: ";
			scan("%d", &m);
		}
		time.min = m;
		return in;
	}


	bool TIME::operator>(TIME& p2)
	{
		if (this->hour * 100 + this->min > p2.getHour() * 100 + p2.getMin())
		{
			return true;
		}
		return false;
	}

	bool TIME::operator==(TIME& p2)
	{
		if (this->hour == p2.getHour() && this->min == p2.getMin())
		{
			return true;
		}
		return false;
	}



	TRAIN::TRAIN()
	{
		cout << "Вызван конструктор TRAIN" << endl;
		destination = "Неизвестно:(";
		number = "Неизвестно:(";
		departure.set(12, 0);
	}

	TRAIN::~TRAIN()
	{
		cout << "Вызван деструктор TRAIN" << endl;
	}

	std::istream& operator>>(std::istream& in, TRAIN& train)
	{
		std::cout << "Пункт назначения: ";
		getline(in, train.destination);

		std::cout << "Номер поезда: ";
		in.clear();
		getline(in, train.number);

		std::cout << "Время отправления: ";
		in.clear();
		in >> train.departure;
		in.sync();
		return in;
	}



	std::ostream& operator<<(std::ostream& out, const TRAIN& train)
	{
		out << "Поезд с номером " << train.number << " следующий в " << train.destination << " отправляется в " << train.departure << endl;
		return out;
	}

	TIME TRAIN::getDeparture()
	{
		return departure;
	}

	string TRAIN::getDestination()
	{
		return destination;
	}

	string* TRAIN::getNumber()
	{
		return &number;
	}
