#include <iostream>
#include <iomanip>
#include "HumanData.h"
using namespace std;

class InputBMI : public HumanData {

public:
	InputBMI();
	bool inputData();
	string getName();
	double getHeight();
	int getWeight();
	int getTotalCount();
	void setCount(int count);
	string getDiffereceFlag();

private:
	string nameList[3];
	double heightList[3];
	int weightList[3];
	int totalCount;
	int count;
	string yn;
	bool end;
	string differeceFlag;
};

class GetBMI : public HumanData {

private:
	double weightDifferece;

public:
    void calcBMI();
	double getDeightDifferece();
};


class DisplayBMI : public HumanData {

public:
	DisplayBMI(string name, double bmi, double stdWeight);
	void displayResult();
	void displayResult(double weightDifferece);
};