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
		GetBMI getBMI;

		inputBMI->setCount(i);
		getBMI.setName(inputBMI->getName());
		getBMI.setHeight(inputBMI->getHeight());
		getBMI.setWeight(inputBMI->getWeight());

		getBMI.calcBMI();

		// コピーコンストラクタの実験
		GetBMI copyGetBMI = getBMI;

		// 代入演算子の実験
		GetBMI operatorGetBMI;
		operatorGetBMI = copyGetBMI;

		// 結果表示
		DisplayBMI *displayBMI = new DisplayBMI(operatorGetBMI.getName(), operatorGetBMI.getBMI(), operatorGetBMI.getStdWeight());

		if (inputBMI->getDiffereceFlag() == "y") {
			displayBMI->displayResult(operatorGetBMI.getDeightDifferece());
		} else {
			displayBMI->displayResult();
		}

		delete displayBMI;

	}

	delete inputBMI;

	return 0;
}