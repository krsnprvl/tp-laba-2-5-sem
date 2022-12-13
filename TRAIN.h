#include "stdio.h"
#include "iostream"
#include <string>
#include "io.h"

using namespace std;

class TIME
{
	int hour;
	int min;
	bool isCorrect();
	void setDefault();
	
public:

	int getHour();
	int getMin();
	void set(int h, int m);

	friend std::ostream& operator<<(std::ostream& out, const TIME& ptr);
	friend std::istream& operator>>(std::istream& in, TIME& time);


	bool operator>(TIME& p2);
	bool operator==(TIME& p2);
};

class TRAIN
{
	string destination;
	string number;
	TIME departure;

public:

	TRAIN();
	~TRAIN();

	friend std::istream& operator>>(std::istream& in, TRAIN& train);
	friend std::ostream& operator<<(std::ostream& out, const TRAIN& train);

	TIME getDeparture();
	string getDestination();
	string* getNumber();

};