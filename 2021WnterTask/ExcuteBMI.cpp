#include <iostream>
#include <iomanip>
#include "ExcuteBMI.h"
using namespace std;

InputBMI::InputBMI() {
	this->count = 0;
}

bool InputBMI::inputData() {

	do {
		// 名前のキー入力
		cout << "お名前を入力してください：";
		cin >> this->name;
		this->nameList[this->count] = this->name;

		// 身長（cm）のキー入力
		cout << "身長を入力してください：";
		cin >> this->height;
		heightList[this->count] = this->height;

		// 体重（kg）のキー入力
		cout << "体重を入力してください：";
		cin >> this->weight;
		weightList[this->count] = this->weight;

		if (this->count < 2) {
			// 追加で入力するか。
			cout << "追加で入力しますか？(y/n)：";
			cin >> this->yn;

			if (this->yn == "y") {
				// 「y」の場合は入力続行。
				this->count = this->count + 1;
				this->end = true;
			}
			else if (yn == "n") {
				// 「n」の場合は入力を終了し、BMIの判定に移る。
				this->end = false;
			}
			else {
				// それ以外は処理終了。
				this->end = false;
				cout << "不明な入力です。処理を終了します。" << endl;
				return false;
			}
		}
		else {
			// 3人まで入力したら強制的にBMIの判定に移る。
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