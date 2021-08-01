#include <iostream>
#include <iomanip>
#include "ExcuteBMI.h"
using namespace std;

int main() {

	bool result = 0;

	InputBMI *inputBMI = new InputBMI();
	result = inputBMI->inputData();

	// 結果がfalseなら処理終了
	if (!result) {
		delete inputBMI;
		return 0;
	}
	
	for (int i = 0; i <= inputBMI->getTotalCount(); i++) {

		// BMIの計算
		GetBMI *getBMI = new GetBMI();

		inputBMI->setCount(i);
		getBMI->setName(inputBMI->getName());
		getBMI->setHeight(inputBMI->getHeight());
		getBMI->setWeight(inputBMI->getWeight());

		getBMI->calcBMI();

		// 結果表示
		DisplayBMI *displayBMI = new DisplayBMI(getBMI->getName(), getBMI->getBMI(), getBMI->getStdWeight());

		if (inputBMI->getDiffereceFlag() == "y") {
			displayBMI->displayResult(getBMI->getDeightDifferece());
		} else {
			displayBMI->displayResult();
		}

		delete getBMI;
		delete displayBMI;

	}

	delete inputBMI;

	return 0;
}