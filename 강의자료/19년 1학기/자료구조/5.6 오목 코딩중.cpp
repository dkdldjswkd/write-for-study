#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//�� �� �� �� �� �� �� �� ��
// ����� 19 X 19
void printbord(string bord[19][19]) {// �ٵ��� ���
	system("cls");
	for (int i = 0; i < 19; i++) { 
		for (int j = 0; j < 19; j++) {
			cout << bord[i][j];
			if (!(bord[i][j] == "��" || bord[i][j] == "��" || bord[i][j]=="��")) cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void diag(string bord[19][19]) { // ������� �밢��
	int count = 0;
	int max = 0;
	int concount = 0;
	int Bcount = 0;
	for (int i = 0; i < 19; i = count) {
		for (int j = 0; i >= 0; i--, j++) {
			if (bord[i][j] == "��") {
				concount = 0;
				Bcount++;
			}
			else if (bord[i][j] != "��") {
				concount++;
			}
			else if (bord[i][j] == "��") {
				concount = 2;
			}
			if (concount >= 2) {
				Bcount = 0;
			}
			if (max <= Bcount) {
				max = Bcount;
			}
		}
		if (max > 1)cout << "������� �밢�� " << count + 1 << "��°���� ����� �浹 ���� " << max << "��" << endl;
		count++;
		max = 0;
		Bcount = 0;
	}

	count = 1;
	max = 0;
	concount = 0;
	Bcount = 0;
	for (int i = 18; count <= 18; i = 18) {
		for (int j = count; j <= 18; i--, j++) {
			if (bord[i][j] == "��") {
				concount = 0;
				Bcount++;
			}
			else if (bord[i][j] != "��") {
				concount++;
			}
			else if (bord[i][j] == "��") {
				concount = 2;
			}
			if (concount >= 2) {
				Bcount = 0;
			}
			if (max <= Bcount) {
				max = Bcount;
			}
		}
		if (max > 1)cout << "������� �밢�� " << count + 19 << "��°���� ����� �浹 ���� " << max << "��" << endl;
		count++;
		max = 0;
		Bcount = 0;
	}

	count = 0;
	max = 0;
	concount = 0;
	Bcount = 0;
	for (int i = 0; i < 19; i = count) {
		for (int j = 0; i >= 0; i--, j++) {
			if (bord[i][j] == "��") {
				concount = 0;
				Bcount++;
			}
			else if (bord[i][j] != "��") {
				concount++;
			}
			else if (bord[i][j] == "��") {
				concount = 2;
			}
			if (concount >= 2) {
				Bcount = 0;
			}
			if (max <= Bcount) {
				max = Bcount;
			}
		}
		if (max > 1)cout << "������� �밢�� " << count + 1 << "��°���� ����� �� ���� " << max << "��" << endl;
		count++;
		max = 0;
		Bcount = 0;
	}

	count = 1;
	max = 0;
	concount = 0;
	Bcount = 0;
	for (int i = 18; count <= 18; i = 18) {
		for (int j = count; j <= 18; i--, j++) {
			if (bord[i][j] == "��") {
				concount = 0;
				Bcount++;
			}
			else if (bord[i][j] != "��") {
				concount++;
			}
			else if (bord[i][j] == "��") {
				concount = 2;
			}
			if (concount >= 2) {
				Bcount = 0;
			}
			if (max <= Bcount) {
				max = Bcount;
			}
		}
		if (max > 1)cout << "������� �밢�� " << count + 19 << "��°���� ����� �� ���� " << max << "��" << endl;
		count++;
		max = 0;
		Bcount = 0;
	}
}

void diag2(string bord[19][19]) { // �»���� �밢��
	int count = 0;
	int max = 0;
	int concount = 0;
	int Bcount = 0;
	for (int i = 0; i < 19; i = count) {
		for (int j = 18; i >= 0; i--, j--) {
			if (bord[i][j] == "��") {
				concount = 0;
				Bcount++;
			}
			else if (bord[i][j] != "��") {
				concount++;
			}
			else if (bord[i][j] == "��") {
				concount = 2;
			}
			if (concount >= 2) {
				Bcount = 0;
			}
			if (max <= Bcount) {
				max = Bcount;
			}
		}
		if (max > 1)cout << "�»���� �밢�� " << count + 1 << "��°���� ����� �浹 ���� " << max << "��" << endl;
		count++;
		max = 0;
		Bcount = 0;
	}

	count = 17;
	max = 0;
	concount = 0;
	Bcount = 0;
	for (int i = 18; count >= 0; i = 18) {
		for (int j = count; j >= 0; i--, j--) {
			if (bord[i][j] == "��") {
				concount = 0;
				Bcount++;
			}
			else if (bord[i][j] != "��") {
				concount++;
			}
			else if (bord[i][j] == "��") {
				concount = 2;
			}
			if (concount >= 2) {
				Bcount = 0;
			}
			if (max <= Bcount) {
				max = Bcount;
			}
		}
		if (max > 1)cout << "�»���� �밢�� " << 37 - count << "��°���� ����� �浹 ���� " << max << "��" << endl;
		count--;
		max = 0;
		Bcount = 0;
	}

	count = 0;
	max = 0;
	concount = 0;
	Bcount = 0;
	for (int i = 0; i < 19; i = count) {
		for (int j = 18; i >= 0; i--, j--) {
			if (bord[i][j] == "��") {
				concount = 0;
				Bcount++;
			}
			else if (bord[i][j] != "��") {
				concount++;
			}
			else if (bord[i][j] == "��") {
				concount = 2;
			}
			if (concount >= 2) {
				Bcount = 0;
			}
			if (max <= Bcount) {
				max = Bcount;
			}
		}
		if (max > 1)cout << "�»���� �밢�� " << count + 1 << "��°���� ����� �� ���� " << max << "��" << endl;
		count++;
		max = 0;
		Bcount = 0;
	}

	count = 17;
	max = 0;
	concount = 0;
	Bcount = 0;
	for (int i = 18; count >= 0; i = 18) {
		for (int j = count; j >= 0; i--, j--) {
			if (bord[i][j] == "��") {
				concount = 0;
				Bcount++;
			}
			else if (bord[i][j] != "��") {
				concount++;
			}
			else if (bord[i][j] == "��") {
				concount = 2;
			}
			if (concount >= 2) {
				Bcount = 0;
			}
			if (max <= Bcount) {
				max = Bcount;
			}
		}
		if (max > 1)cout << "�»���� �밢�� " << 37 - count << "��°���� ����� �� ���� " << max << "��" << endl;
		count--;
		max = 0;
		Bcount = 0;
	}
}

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

	int black = 0, white = 0; // �浹�� �鵹�� �� ����
	bool who = true; // ���϶� �浹 �����϶� �鵹
	bool first = true;
	int Bcount = 0, Wcount = 0; // �浹�� �鵹�� �Ϻ� ����
	int manyWB = 0, manyWW = 1, manyHB = 1, manyHW = 1;
	int diaB = 1, diaW = 1, diaB2 = 1, diaW2 = 1;
	bool conCheck = false;
	int x, y; // x, y�� ��ǥ
	int turn = 1; //Ȧ����� �浹���� ¦����� �鵹����
	int mmn = 0;

	while (1) { // ���� ���Ϲ�
		cout << endl;
		cout << turn << "��° �� �Դϴ�." << endl;
		cout << "�浹�� ���� : " << black << endl;
		cout << "���� ���� : " << white << endl;

		if (turn % 2 == 1) {
			cout << "�浹�� ���� �ڸ��� �Է��ϼ���  : ";
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
			if (turn % 2 == 1) {
				bord[x - 1][y - 1] = "��"; // �� ��ǥ�� �浹 ����
				black++;
				who = false;
				turn++;
			}
			else {
				bord[x - 1][y - 1] = "��"; // �� ��ǥ�� �浹 ����
				white++;
				who = true;
				turn++;
			}
		}

		printbord(bord);


		int max = 0;
		x = 0, y = 0;
		int tmp = 0;
		int concount = 0; // �����Ѱ��� ���������� 0 ��ĭ ������������ 1 ��ĭ�������� 2
		Bcount = 0;
		for (int i = 0; i < 19; i++) { // �࿡ �������� �����ΰ�
			for (int j = 0; j < 19; j++) {
				if (bord[i][j] == "��") {
					concount = 0;
					Bcount++;
				}
				else if (bord[i][j] != "��") {
					concount++;
				}
				else if (bord[i][j] == "��") {
					concount = 2;
				}
				if (concount >= 2) {
					Bcount = 0;
				}
				if (max <= Bcount) {
					max = Bcount;
				}

				if (Bcount >= 3 && concount==0 && j+1<=18) {//���ƾ��ϴ°��� �ٷ� �˷���
					int count = 0;
					for (int a = 0;;) {
						if (bord[i][j + 1 - count] != "��" && bord[i][j + 1 - a] != "��") {
							bord[i][j + 1 - count] = "��";
							if (a >= Bcount)break;
						}
						else if (bord[i][j + 1 - count] == "��") {
							a++;
						}
						count++;
					}
				}

			}
			if (max > 1)cout << i + 1 << "���� �̾��� ����� �浹 ���� " << max << "��" << endl;
			max = 0;
			Bcount = 0;
		}

		max = 0;
		concount = 0;
		Bcount = 0;
		for (int j = 0; j < 19; j++) { // ���� �������� �����ΰ�
			for (int i = 0; i < 19; i++) {
				if (bord[i][j] == "��") {
					concount = 0;
					Bcount++;
				}
				else if (bord[i][j] != "��") {
					concount++;
				}
				else if (bord[i][j] == "��") {
					concount = 2;
				}
				if (concount >= 2) {
					Bcount = 0;
				}
				if (max <= Bcount) {
					max = Bcount;
				}
			}
			if (max > 1)cout << j + 1 << "���� �̾��� ����� �浹 ���� " << max << "��" << endl;
			max = 0;
			Bcount = 0;
		}


		max = 0;
		concount = 0;
		Wcount = 0;
		for (int i = 0; i < 19; i++) { // �࿡ ���� �����ΰ�
			for (int j = 0; j < 19; j++) {
				if (bord[i][j] == "��") {
					concount = 0;
					Wcount++;
				}
				else if (bord[i][j] != "��") {
					concount++;
				}
				else if (bord[i][j] == "��") {
					concount = 2;
				}
				if (concount >= 2) {
					Wcount = 0;
				}
				if (max <= Wcount) {
					max = Wcount;
				}
			}
			if (max > 1)cout << i + 1 << "���� �̾��� ����� �� ���� " << max << "��" << endl;
			max = 0;
			Wcount = 0;
		}

		max = 0;
		concount = 0;
		Wcount = 0;
		for (int j = 0; j < 19; j++) { // ���� ���� �����ΰ�
			for (int i = 0; i < 19; i++) {
				if (bord[i][j] == "��") {
					concount = 0;
					Wcount++;
				}
				else if (bord[i][j] != "��") {
					concount++;
				}
				else if (bord[i][j] == "��") {
					concount = 2;
				}
				if (concount >= 2) {
					Wcount = 0;
				}
				if (max <= Wcount) {
					max = Wcount;
				}
			}
			if (max > 1)cout << j + 1 << "���� �̾��� ����� �� ���� " << max << "��" << endl;
			max = 0;
			Wcount = 0;
		}

		diag(bord);
		diag2(bord);


		printbord(bord);

	}//���Ϲ� ��
}//���ι� ��

//���浹 �ܹ鵹