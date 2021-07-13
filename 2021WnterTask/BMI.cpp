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

	// 結果がfalseなら処理終了
	if (!result) {
		return 0;
	}
	
	for (int i = 0; i <= inputBMI->getCount(); i++) {

		// BMIの計算
		GetBMI *getBMI = new GetBMI();

		getBMI->setName(inputBMI->getNameList(i));
		getBMI->setHeight(inputBMI->getHeightList(i));
		getBMI->setWeight(inputBMI->getWeightList(i));

		getBMI->calcBMI();

		// 標準体重
		stdWeight = STD_BMI * (getBMI->getMHeight() * getBMI->getMHeight());

		// BMIの表示
		cout << getBMI->getName() << "さんのBMIは、" << fixed << setprecision(1) << getBMI->getBMI() << "です。" << endl;

		// 標準体重の表示
		cout << getBMI->getName() << "さんの標準体重は、" << stdWeight << "kgです。" << endl;

		// どのくらいの肥満度か判定する。
		cout << checkBMI(getBMI->getBMI()) << endl;

		delete getBMI;
	}

	delete inputBMI;

	return 0;
}