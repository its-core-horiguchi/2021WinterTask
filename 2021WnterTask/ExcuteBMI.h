#include <iostream>
#include <iomanip>
#include "HumanData.h"
using namespace std;

class InputBMI : public HumanData {

public:
	InputBMI();
	InputBMI(const InputBMI& inputBMI);
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
	GetBMI();
    void calcBMI();
	double getDeightDifferece();
	GetBMI(const GetBMI & getBMI);

	GetBMI &operator=(const GetBMI &getBMI) {

		cout << "‘ã“ü‰‰ŽZŽq‚ÌŽÀŒ±" << endl;

		this->name = getBMI.name;
		this->bmi = getBMI.bmi;
		this->stdWeight = getBMI.stdWeight;
		this->weightDifferece = getBMI.weightDifferece;

		return *this;
	}
};


class DisplayBMI : public HumanData {

public:
	DisplayBMI(string name, double bmi, double stdWeight);
	void displayResult();
	void displayResult(double weightDifferece);
};