#include <iostream>
#include <iomanip>
#include "ExcuteBMI.h"
#include "CheckBMI.cpp"
using namespace std;

int main() {

	bool result = 0;
	double stdWeight;
	const int STD_BMI = 22;

	InputBMI *inputBMI = new InputBMI();
	result = inputBMI->inputData();

	// ���ʂ�false�Ȃ珈���I��
	if (!result) {
		return 0;
	}
	
	for (int i = 0; i <= inputBMI->getCount(); i++) {

		// BMI�̌v�Z
		GetBMI *getBMI = new GetBMI();

		getBMI->setName(inputBMI->getNameList(i));
		getBMI->setHeight(inputBMI->getHeightList(i));
		getBMI->setWeight(inputBMI->getWeightList(i));

		getBMI->calcBMI();

		// �W���̏d
		stdWeight = STD_BMI * (getBMI->getMHeight() * getBMI->getMHeight());

		// BMI�̕\��
		cout << getBMI->getName() << "�����BMI�́A" << fixed << setprecision(1) << getBMI->getBMI() << "�ł��B" << endl;

		// �W���̏d�̕\��
		cout << getBMI->getName() << "����̕W���̏d�́A" << stdWeight << "kg�ł��B" << endl;

		// �ǂ̂��炢�̔얞�x�����肷��B
		cout << checkBMI(getBMI->getBMI()) << endl;

		delete getBMI;
	}

	delete inputBMI;

	return 0;
}