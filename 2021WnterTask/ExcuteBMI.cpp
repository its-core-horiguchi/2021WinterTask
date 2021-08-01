#include <iostream>
#include <iomanip>
#include "ExcuteBMI.h"
#include "CheckBMI.cpp"
using namespace std;

InputBMI::InputBMI() {
	this->totalCount = 0;
}

bool InputBMI::inputData() {

	do {
		// ���O�̃L�[����
		cout << "�����O����͂��Ă��������F";
		cin >> this->name;
		this->nameList[this->totalCount] = this->name;

		// �g���icm�j�̃L�[����
		cout << "�g������͂��Ă��������F";
		cin >> this->height;
		heightList[this->totalCount] = this->height;

		// �̏d�ikg�j�̃L�[����
		cout << "�̏d����͂��Ă��������F";
		cin >> this->weight;
		weightList[this->totalCount] = this->weight;

		if (this->totalCount < 2) {
			// �ǉ��œ��͂��邩�B
			cout << "�ǉ��œ��͂��܂����H(y/n)�F";
			cin >> this->yn;

			if (this->yn == "y") {
				// �uy�v�̏ꍇ�͓��͑��s�B
				this->totalCount = this->totalCount + 1;
				this->end = true;
			}
			else if (yn == "n") {
				// �un�v�̏ꍇ�͓��͂��I�����ABMI�̔���Ɉڂ�B
				this->end = false;
			}
			else {
				// ����ȊO�͏����I���B
				this->end = false;
				cout << "�s���ȓ��͂ł��B�������I�����܂��B" << endl;
				return false;
			}
		}
		else {
			// 3�l�܂œ��͂����狭���I��BMI�̔���Ɉڂ�B
			this->end = false;
		}

	} while (this->end);

	cout << "�W���̏d�Ƃ̍���ǉ��ŕ\�����܂����H(y/n)�F";
	cin >> this->differeceFlag;

	if (this->differeceFlag != "y" && this->differeceFlag != "n") {
		// ����ȊO�͏����I���B
		this->end = false;
		cout << "�s���ȓ��͂ł��B�������I�����܂��B" << endl;
		return false;
	}

	return true;
}

string InputBMI::getName() {
	return this->nameList[this->count];
}

double InputBMI::getHeight() {
	return this->heightList[this->count];
}

int InputBMI::getWeight() {
	return this->weightList[this->count];
}

int InputBMI::getTotalCount() {
	return this->totalCount;
}

void InputBMI::setCount(int count) {
	this->count = count;
}

string InputBMI::getDiffereceFlag() {
	return this->differeceFlag;
}

void GetBMI::calcBMI() {

	// �W��BMI�l
	const int STD_BMI = 22;

	// BMI�v�Z
	this->bmi = this->weight / (this->mHeight * this->mHeight);

	// �W���̏d�v�Z
	this->stdWeight = STD_BMI * (this->mHeight * this->mHeight);

	// �W���̏d�Ƃ̍����v�Z
	this->weightDifferece = this->weight - this->stdWeight;
}

double GetBMI::getDeightDifferece() {
	return this->weightDifferece;
}

DisplayBMI::DisplayBMI(string name, double bmi, double stdWeight) {
	this->name = name;
	this->bmi = bmi;
	this->stdWeight = stdWeight;
}

void DisplayBMI::displayResult() {
	// BMI�̕\��
	cout << this->getName() << "�����BMI�́A" << fixed << setprecision(1) << this->getBMI() << "�ł��B" << endl;

	// �W���̏d�̕\��
	cout << this->getName() << "����̕W���̏d�́A" << this->getStdWeight() << "kg�ł��B" << endl;

	// �ǂ̂��炢�̔얞�x�����肷��B
	cout << checkBMI(this->getBMI()) << endl;
}

void DisplayBMI::displayResult(double weightDifferece) {

	// ��{�̏���\��
	this->displayResult();

	// �W���̏d�Ƃ̍���\��
	cout << "�W���̏d�Ƃ̍��́A" << weightDifferece << "kg�ł��B" << endl;
}