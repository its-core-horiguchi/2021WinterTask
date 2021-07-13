#include <iostream>
#include <iomanip>
#include "HumanData.h"
using namespace std;

class InputBMI : public HumanData {

public:
	InputBMI();
	bool inputData();
	string InputBMI::getNameList(int i);
	double InputBMI::getHeightList(int i);
	int InputBMI::getWeightList(int i);
	int InputBMI::getCount();

private:
	string nameList[3];
	double heightList[3];
	int weightList[3];
	int count;
	string yn;
	bool end;
};

class GetBMI : public HumanData {

public:
    void calcBMI();
    double getBMI();

private:
    double bmi;
};