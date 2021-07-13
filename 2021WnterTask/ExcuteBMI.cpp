#include <iostream>
#include <iomanip>
#include "ExcuteBMI.h"
using namespace std;

InputBMI::InputBMI() {
	this->count = 0;
}

bool InputBMI::inputData() {

	do {
		// ���O�̃L�[����
		cout << "�����O����͂��Ă��������F";
		cin >> this->name;
		this->nameList[this->count] = this->name;

		// �g���icm�j�̃L�[����
		cout << "�g������͂��Ă��������F";
		cin >> this->height;
		heightList[this->count] = this->height;

		// �̏d�ikg�j�̃L�[����
		cout << "�̏d����͂��Ă��������F";
		cin >> this->weight;
		weightList[this->count] = this->weight;

		if (this->count < 2) {
			// �ǉ��œ��͂��邩�B
			cout << "�ǉ��œ��͂��܂����H(y/n)�F";
			cin >> this->yn;

			if (this->yn == "y") {
				// �uy�v�̏ꍇ�͓��͑��s�B
				this->count = this->count + 1;
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

	return true;
}

string InputBMI::getNameList(int i) {
	return this->nameList[i];
}

double InputBMI::getHeightList(int i) {
	return this->heightList[i];
}

int InputBMI::getWeightList(int i) {
	return this->weightList[i];
}

int InputBMI::getCount() {
	return this->count;
}

void GetBMI::calcBMI() {
	this->bmi = this->weight / (this->mHeight * this->mHeight);
}

double GetBMI::getBMI() {
	return this->bmi;
}