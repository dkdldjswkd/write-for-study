#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//�� �� �� �� �� �� �� �� ��
// ����� 19 X 19

int main() {
	string bord[19][19];

	bord[0][0] = "��";
	bord[0][18] = "��";
	bord[18][0] = "��";
	bord[18][18] = "��"; // �ٵ��� �𼭸� ���� ����

	for (int i = 1; i < 18; i++) {
		bord[0][i] = "��";
	}
	for (int i = 1; i < 18; i++) {
		bord[i][18] = "��";
	}
	for (int i = 1; i < 18; i++) {
		bord[18][i] = "��";
	}
	for (int i = 1; i < 18; i++) {
		bord[i][0] = "��";
	} // �ٵ��� �����ڸ� ���� ����

	for (int i = 1; i < 18; i++) { // �ٵ��� �߾Ӻ� ���ڹ��� ����
		for (int j = 1; j < 18; j++) {
			bord[i][j] = "��";
		}
	}

	for (int i = 0; i < 19; i++) { // �ٵ��� ���
		for (int j = 0; j < 19; j++) {
			cout << bord[i][j] << " ";
		}
		cout << endl;
	}

	int black = 0;
	int white = 0;
	int x, y;
	bool who = true;

	int WB = 0, WW = 0, HB = 0, HW = 0;
	int manyWB = 1, manyWW = 1, manyHB = 1, manyHW = 1;
	int diaB = 1, diaW = 1, diaB2 = 1, diaW2 = 1;
	bool conCheck = false;

	while (1) { // ���� ���Ϲ�
		cout << endl;
		cout << "�浹�� ���� : " << black << endl;
		cout << "���� ���� : " << white << endl;

		if (who) {
			cout << "�浹�� ���� �ڸ��� �Է��ϼ��� : ";
		}
		else {
			cout << "�鵹�� ���� �ڸ��� �Է��ϼ��� : ";
		}

		rewind(stdin); // �Է¹��� ����
		cin >> x >> y; // ��ǥ�� �Է¹���

		if (x > 19 || y > 19 || x < 1 || y < 1) {
			cout << "���ڸ� Ȯ���ϰ� �ٽ� �Է����ּ���" << endl;
			continue;
		}
		else if (bord[x - 1][y - 1] == "��" || bord[x - 1][y - 1] == "��") {
			cout << "�̹� ���� ĭ�Դϴ� �ٽ� �Է����ּ���" << endl;
			continue;
		}
		else {
			if (who) {
				bord[x - 1][y - 1] = "��"; // �� ��ǥ�� �浹 ����
				black++;
				who = false;
			}
			else {
				bord[x - 1][y - 1] = "��"; // �� ��ǥ�� �浹 ����
				white++;
				who = true;
			}
		}

		system("cls");
		for (int i = 0; i < 19; i++) { // �ٵ��� ���
			for (int j = 0; j < 19; j++) {
				cout << bord[i][j];
				if (!(bord[i][j] == "��" || bord[i][j] == "��")) cout << " ";
			}
			cout << endl;
		}
		cout << endl;

		for (int i = 0; i < 19; i++) {//�� �� ���ڼ���
			for (int j = 0; j < 19; j++) {
				if (bord[i][j] == "��") {
					HB++;
				}
				else if (bord[i][j] == "��") {
					HW++;
				}
			}
			if (HW > 0 || HB > 0) {
				cout << i + 1 << "���� �������� ������ " << HB << "��"
					<< " ���� ������ " << HW << "��" << endl;
			}
			HB = 0, HW = 0;
		}

		for (int i = 0; i < 19; i++) {//�� �� ���ڼ���
			for (int j = 0; j < 19; j++) {
				if (bord[j][i] == "��") {
					WB++;
				}
				else if (bord[j][i] == "��") {
					WW++;
				}
			}
			if (WB > 0 || WW > 0) {//�࿡ �򵹰� �������� 0���� �ƴ϶�� ���° ���� ���� � �ִ��� �˷���
				cout << i + 1 << "���� �������� ������ " << WB << "��"
					<< " ���� ������ " << WW << "��" << endl;
			}
			WB = 0, WW = 0;
		}

		int max = 0;
		int x = 0, y = 0, tmp = 0;
		for (int i = 0; i < 19; i++) { // �࿡ �������� �����ΰ�
			for (int j = 0; j < 19; j++) {
				if (j > 0) {
					if ((bord[i][j] == "��") && (bord[i][j - 1] == "��")) {
						conCheck = true;
					}
					else {
						conCheck = false;
						manyWB = 1;
					}
				}
				if (conCheck) {
					manyWB++;
					if (manyWB >= max) {
						max = manyWB;
						if (tmp <= max) {
							x = i + 1, y = j + 1, tmp = max;
						}
					}
				}
			}
			if (max > 1) {
				cout << i + 1 << "���� �̾��� �浹�� ������ " << max << endl;
			}
			max = 0;
		}
		//	if (tmp > 1) {
			//	cout << "���� ���� ��� �̾��� �������� ��ǥ�� (" << x << ", " << y - (tmp - 1) << ")" << " ����" << "(" << x << ", " << y << ")" << endl;
		//	}

		max = 0;
		for (int i = 0; i < 19; i++) { // ���� �������� �����ΰ�
			for (int j = 0; j < 19; j++) {
				if (j > 0) {
					if ((bord[j][i] == "��") && (bord[j - 1][i] == "��")) {
						conCheck = true;
					}
					else {
						conCheck = false;
						manyHB = 1;
					}
				}
				if (conCheck) {
					manyHB++;
					if (manyHB >= max) {
						max = manyHB;
					}
				}
			}
			if (max > 1) {
				cout << i + 1 << "���� �̾��� �浹�� ������ " << max << endl;
			}
			max = 0;
		}

		max = 0;
		int x2 = 0, y2 = 0, tmp2 = 0;
		for (int i = 0; i < 19; i++) { // �࿡ ���� �����ΰ�
			for (int j = 0; j < 19; j++) {
				if (j > 0) {
					if ((bord[i][j] == "��") && (bord[i][j - 1] == "��")) {
						conCheck = true;
					}
					else {
						conCheck = false;
						manyWW = 1;
					}
				}
				if (conCheck) {
					manyWW++;
					if (manyWW >= max) {
						max = manyWW;
						if (tmp <= max) {
							x2 = i + 1, y2 = j + 1, tmp2 = max;
						}
					}
				}
			}
			if (max > 1) {
				cout << i + 1 << "���� �̾��� ���� ������ " << max << endl;
			}
			max = 0;
		}

		if (tmp >= tmp2 && tmp > 1) {
			cout << "���� ���� ��� �̾��� ���� �������� ��ǥ�� (" << x << ", " << y - (tmp - 1) << ")" << " ����" << "(" << x << ", " << y << ")" << endl;
		}
		else if (tmp <= tmp2 && tmp2 > 1) {
			cout << "���� ���� ��� �̾��� ���� �򵹷� ��ǥ�� (" << x2 << ", " << y2 - (tmp2 - 1) << ")" << " ����" << "(" << x2 << ", " << y2 << ")" << endl;
		}

		max = 0;
		for (int i = 0; i < 19; i++) { // ���� ���� �����ΰ�
			for (int j = 0; j < 19; j++) {
				if (j > 0) {
					if ((bord[j][i] == "��") && (bord[j - 1][i] == "��")) {
						conCheck = true;
					}
					else {
						conCheck = false;
						manyHW = 1;
					}
				}
				if (conCheck) {
					manyHW++;
					if (manyHW >= max) {
						max = manyHW;
					}
				}
			}
			if (max > 1) {
				cout << i + 1 << "���� �̾��� ���� ������ " << max << endl;
			}
			max = 0;
		}

		int a = 0, b = 0;
		for (int i = 0; i < 19; i++) { // ���� �� �밢�� �浹
			a = i; b = 0;
			for (; a > 0; a--, b++) {
				if (a > 0) {
					if (bord[a][b] == "��" && bord[a - 1][b + 1] == "��") {
						conCheck = true;
					}
					else {
						conCheck = false;
						diaB = 1;
					}
				}
				if (conCheck) {
					diaB++;
					if (diaB >= max) {
						max = diaB;
					}
				}
			}
			if (max > 1) {
				cout << "���� ������ " << i + 1 << "��° �밢���� �̾��� �浹�� ������ " << max << endl;
			}
			max = 0;
		}

		for (int i = 18; i >= 1; i--) { // ������ �Ʒ� �밢�� �浹
			a = 18; b = i;
			for (; b < 18; a--, b++) {
				if (a > 0) {
					if (bord[a][b] == "��" && bord[a - 1][b + 1] == "��") {
						conCheck = true;
					}
					else {
						conCheck = false;
						diaB = 1;
					}
				}
				if (conCheck) {
					diaB++;
					if (diaB >= max) {
						max = diaB;
					}
				}
			}
			if (max > 1) {
				cout << "���� ������ " << i + 19 << "��° �밢���� �̾��� �浹�� ������ " << max << endl;
			}
			max = 0;
		}

		for (int i = 0; i < 19; i++) { // ������ �밢�� ��
			a = i; b = 0;
			for (; a > 0; a--, b++) {
				if (a > 0) {
					if (bord[a][b] == "��" && bord[a - 1][b + 1] == "��") {
						conCheck = true;
					}
					else {
						conCheck = false;
						diaW = 1;
					}
				}
				if (conCheck) {
					diaW++;
					if (diaW >= max) {
						max = diaW;
					}
				}
			}
			if (max > 1) {
				cout << "���� ������ " << i + 1 << "��° �밢���� �̾��� ���� ������ " << max << endl;
			}
			max = 0;
		}

		max = 0, a = 18, b = 18;
		for (int i = 18; i >= 1; i--) { // ������ �Ʒ� �밢�� ��
			a = 18; b = i;
			for (; b < 18; a--, b++) {
				if (a > 0) {
					if (bord[a][b] == "��" && bord[a - 1][b + 1] == "��") {
						conCheck = true;
					}
					else {
						conCheck = false;
						diaW = 1;
					}
				}
				if (conCheck) {
					diaW++;
					if (diaW >= max) {
						max = diaW;
					}
				}
			}
			if (max > 1) {
				cout << "���� ������ " << i + 19 << "��° �밢���� �̾��� �鵹�� ������ " << max << endl;
			}
			max = 0;
		}

		max = 0;
		for (int i = 18; i >= 0; i--) { //������ �� �밢�� �浹
			a = 0; b = i;
			for (; b < 18; a++, b++) {
				if (b < 18) {
					if (bord[a][b] == "��" && bord[a + 1][b + 1] == "��") {
						conCheck = true;
					}
					else {
						conCheck = false;
						diaB2 = 1;
					}
				}
				if (conCheck) {
					diaB2++;
					if (diaB2 >= max) {
						max = diaB2;
					}
				}
			}
			if (max > 1) {
				cout << "������ ������ " << -(i - 19) << "��° �밢���� �̾��� �浹�� ������ " << max << endl;
			}
			max = 0;
		}

		for (int i = 18; i >= 1; i--) { // ���� �Ʒ� �밢�� �浹
			a = i, b = 0;
			for (; a < 18; a++, b++) {
				if (a < 18) {
					if (bord[a][b] == "��" && bord[a + 1][b + 1] == "��") {
						conCheck = true;
					}
					else {
						conCheck = false;
						diaB2 = 1;
					}
				}
				if (conCheck) {
					diaB2++;
					if (diaB2 >= max) {
						max = diaB2;
					}
				}
			}
			if (max > 1) {
				cout << "������ ������ " << i + 19 << "��° �밢���� �̾��� �浹�� ������ " << max << endl;
			}
			max = 0;
		}

		for (int i = 18; i >= 0; i--) { // ������ �� �밢�� ��
			a = 0; b = i;
			for (; b < 18; a++, b++) {
				if (b < 18) {
					if (bord[a][b] == "��" && bord[a + 1][b + 1] == "��") {
						conCheck = true;
					}
					else {
						conCheck = false;
						diaW2 = 1;
					}
				}
				if (conCheck) {
					diaW2++;
					if (diaW2 >= max) {
						max = diaW2;
					}
				}
			}
			if (max > 1) {
				cout << "������ ������ " << -(i - 19) << "��° �밢���� �̾��� �鵹�� ������ " << max << endl;
			}
			max = 0;
		}

		for (int i = 18; i >= 1; i--) { // ���� �Ʒ� �밢�� ��
			a = i, b = 0;
			for (; a < 18; a++, b++) {
				if (a < 19) {
					if (bord[a][b] == "��" && bord[a + 1][b + 1] == "��") {
						conCheck = true;
					}
					else {
						conCheck = false;
						diaW2 = 1;
					}
				}
				if (conCheck) {
					diaW2++;
					if (diaW2 >= max) {
						max = diaW2;
					}
				}
			}
			if (max > 1) {
				cout << "������ ������ " << i + 19 << "��° �밢���� �̾��� ���� ������ " << max << endl;
			}
			max = 0;
		}


	}//���Ϲ� ��
}//���ι� ��

//���浹 �ܹ鵹