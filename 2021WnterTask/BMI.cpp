#include <iostream>
#include <iomanip>
#include "ExcuteBMI.h"
using namespace std;

int main() {

	bool result = 0;

	InputBMI *inputBMI = new InputBMI();
	result = inputBMI->inputData();

	// ���ʂ�false�Ȃ珈���I��
	if (!result) {
		delete inputBMI;
		return 0;
	}
	
	for (int i = 0; i <= inputBMI->getTotalCount(); i++) {

		// BMI�̌v�Z
		GetBMI getBMI;

		inputBMI->setCount(i);
		getBMI.setName(inputBMI->getName());
		getBMI.setHeight(inputBMI->getHeight());
		getBMI.setWeight(inputBMI->getWeight());

		getBMI.calcBMI();

		// �R�s�[�R���X�g���N�^�̎���
		GetBMI copyGetBMI = getBMI;

		// ������Z�q�̎���
		GetBMI operatorGetBMI;
		operatorGetBMI = copyGetBMI;

		// ���ʕ\��
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