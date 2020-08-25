#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//�� �� �� �� �� �� �� �� ��
// ����� 19 X 19
void printbord(string bord[19][19]) {// �ٵ��� ���
//   system("cls");
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cout << bord[i][j];
			if (!(bord[i][j] == "��" || bord[i][j] == "��" || bord[i][j] == "��")) cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void bordclear(string bord[19][19]) {

	if (bord[0][0] != "��" && bord[0][0] != "��")
		bord[0][0] = "��";
	if (bord[0][18] != "��" && bord[0][18] != "��")
		bord[0][18] = "��";
	if (bord[18][0] != "��" && bord[18][0] != "��")
		bord[18][0] = "��";
	if (bord[18][18] != "��" && bord[18][18] != "��")
		bord[18][18] = "��";

	for (int i = 1; i < 18; i++) {
		if (bord[0][i] != "��" && bord[0][i] != "��")
			bord[0][i] = "��";
	}
	for (int i = 1; i < 18; i++) {
		if (bord[i][18] != "��" && bord[i][18] != "��")
			bord[i][18] = "��";
	}
	for (int i = 1; i < 18; i++) {
		if (bord[18][i] != "��" && bord[18][i] != "��")
			bord[18][i] = "��";
	}
	for (int i = 1; i < 18; i++) {
		if (bord[i][0] != "��" && bord[i][0] != "��")
			bord[i][0] = "��";
	}

	for (int i = 1; i < 18; i++) { // �ٵ��� �߾Ӻ� ���ڹ��� ����
		for (int j = 1; j < 18; j++) {
			if (bord[i][j] != "��" && bord[i][j] != "��")
				bord[i][j] = "��";
		}
	}
}

void diag(string bord[19][19]) { // ������� �밢��
	int x=0, y=0;
	int gap_n = 0;
	int count = 0;
	int max = 0;
	int concount = 0;
	int Bcount = 0;
	for (int i = 0; i < 19; i = count) {//������ ������ �浹üũ
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
			if (max <= Bcount && concount == 0) {
				max = Bcount;
				x = i + 1;
				y = j + 1;
				gap_n = 0;
				for (int a = 0, b = 0;;) {
					if (bord[i + a][j - a] != "��")gap_n++;
					else if (bord[i + a][j - a] == "��")b++;
					if (b == Bcount)break;
					a++;
				}
			}
		}
		if (max > 1)cout << "������� �밢�� " << count + 1 << "��°���� ����� �浹 ���� " << max << "��"
			<< "��ǥ�� " << "(" << x + (max - 1) + gap_n << ", " << y - (max - 1) - gap_n << ") ���� " << "(" << x << ", " << y << ")" << endl;
		count++;

		x--; y--;//x,y �� ������ ��ǥ���� �ٽ� ����

		if (max == 3 && gap_n == 0) { // ���������� �̾��� ������ ��
			if (y - (max - 1) - gap_n >=1 && x>=1) { // �����ڸ��� �ƴ� ������
				if (bord[x + (max - 1) + gap_n+1][y - (max - 1) - gap_n-1] != "��" && bord[x-1][y+1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
					bord[x - 1][y + 1] = "��";
					bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "��";
				}
			}
		}
		if (max == 3 && gap_n == 1) { // ������ �� ���� ��ĭ�� �ϳ� �ִٸ�
			if (y - (max - 1) - gap_n >= 1 && x >= 1) { // �����ڸ��� �ƴ϶��
				if (bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "��" && bord[x - 1][y + 1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
					for (int a = x, b = y;; a++, b--) {
						if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
							bord[a][b] = "��";
							break;
						}
					}
				}
			}
		}
		if (max == 4 && gap_n == 1) { // �װ��� �� ���� ��ĭ�� �ϳ� �ִٸ�
			for (int a = x, b = y;; a++, b--) {
				if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
					bord[a][b] = "��";
					break;
				}
			}
		}
		if (max == 4 && gap_n == 0) { // �װ��� ���� ���������� �����ٸ�
			if (y - (max - 1) - gap_n ==0) {//���� ������ʾƷ��� �����ִٸ� ���ӵ� ���� ���������� ������
				bord[x-1][y+1] = "��";
			}
			else if (x==0) {//���� �����ʰ������� �����ִٸ� ���� ���� �Ʒ��� �� ����
				bord[x + (max - 1) + gap_n+1][y - (max - 1) - gap_n-1] = "��";
			}
		}

		if (max >= 5) { // �ټ��� �� �̻��� �����̵� ��ĭ�� �ֵ�
			if (y - (max - 1) - gap_n >0 && bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n-1] != "��") {//�̾������� ���ʾƷ�ĭ�� ���� �ƴϰ� �鵹�� ������ �ʾѴٸ�
				bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "��";//�̾��� ���� ���ʾƷ�ĭ�� ��ǥ����
			}
			if (x > 0 && bord[x-1][y + 1] != "��") {//�̾��� ���� ��������ĭ�� ���̾ƴϰ� �鵹�� ������ �ʾҴٸ�
				bord[x-1][y + 1] = "��";//�̾��� ���� ������ ĭ�� ��ǥ����
			}
			for (int a = x, b = y;; a++, b--) {
				if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
					bord[a][b] = "��";
				}
				if (a == x + (max - 1) + gap_n && b == y - (max - 1) - gap_n)break;
			}
		}

		max = 0;
		Bcount = 0;
	}

	count = 1;
	max = 0;
	concount = 0;
	Bcount = 0;
	for (int i = 18; count <= 18; i = 18) { // ������ �Ʒ� ������ �浹üũ
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
			if (max <= Bcount && concount == 0) {
				max = Bcount;
				x = i + 1;
				y = j + 1;
				gap_n = 0;
				for (int a = 0, b = 0;;) {
					if (bord[i + a][j - a] != "��")gap_n++;
					else if (bord[i + a][j - a] == "��")b++;
					if (b == Bcount)break;
					a++;
				}
			}
		}
		if (max > 1)cout << "������� �밢�� " << count + 19 << "��°���� ����� �浹 ���� " << max << "��"
			<< "��ǥ�� " << "(" << x + (max - 1) + gap_n << ", " << y - (max - 1) - gap_n << ") ���� " << "(" << x << ", " << y << ")" << endl;
		count++;

		x--; y--;//x,y �� ������ ��ǥ���� �ٽ� ����

		if (max == 3 && gap_n == 0) { // ���������� �̾��� ������ ��
			if (x + (max - 1) + gap_n <18 && y < 18) { // �����ڸ��� �ƴ� ������
				if (bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "��" && bord[x - 1][y + 1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
					bord[x - 1][y + 1] = "��";
					bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "��";
				}
			}
		}
		if (max == 3 && gap_n == 1) { // ������ �� ���� ��ĭ�� �ϳ� �ִٸ�
			if (x + (max - 1) + gap_n < 18 && y < 18) { // �����ڸ��� �ƴ϶��
				if (bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "��" && bord[x - 1][y + 1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
					for (int a = x, b = y;; a++, b--) {
						if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
							bord[a][b] = "��";
							break;
						}
					}
				}
			}
		}
		if (max == 4 && gap_n == 1) { // �װ��� �� ���� ��ĭ�� �ϳ� �ִٸ�
			for (int a = x, b = y;; a++, b--) {
				if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
					bord[a][b] = "��";
					break;
				}
			}
		}
		if (max == 4 && gap_n == 0) { // �װ��� ���� ���������� �����ٸ�
			if (x + (max - 1) + gap_n == 18) {//���� ������ʾƷ��� �����ִٸ� ���ӵ� ���� ���������� ������
				bord[x - 1][y + 1] = "��";
			}
			else if (y == 18) {//���� �����ʰ������� �����ִٸ� ���� ���� �Ʒ��� �� ����
				bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "��";
			}
		}

		if (max >= 5) { // �ټ��� �� �̻��� �����̵� ��ĭ�� �ֵ�
			if (x + (max - 1) + gap_n < 18 && bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "��") {//�̾������� ���ʾƷ�ĭ�� ���� �ƴϰ� �鵹�� ������ �ʾѴٸ�
				bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "��";//�̾��� ���� ���ʾƷ�ĭ�� ��ǥ����
			}
			if (y <18 && bord[x - 1][y + 1] != "��") {//�̾��� ���� ������ĭ�� ���̾ƴϰ� �鵹�� ������ �ʾҴٸ�
				bord[x - 1][y + 1] = "��";//�̾��� ���� ������ ĭ�� ��ǥ����
			}
			for (int a = x, b = y;; a++, b--) {
				if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
					bord[a][b] = "��";
				}
				if (a == x + (max - 1) + gap_n && b == y - (max - 1) - gap_n)break;
			}
		}
		max = 0;
		Bcount = 0;
	}

	count = 0;
	max = 0;
	concount = 0;
	Bcount = 0;
	for (int i = 0; i < 19; i = count) {//������ ���� ��
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
			if (max <= Bcount && concount == 0) {
				max = Bcount;
				x = i + 1;
				y = j + 1;
				gap_n = 0;
				for (int a = 0, b = 0;;) {
					if (bord[i + a][j - a] != "��")gap_n++;
					else if (bord[i + a][j - a] == "��")b++;
					if (b == Bcount)break;
					a++;
				}
			}
		}
		if (max > 1)cout << "������� �밢�� " << count + 1 << "��°���� ����� �� ���� " << max << "��"
			<< "��ǥ�� " << "(" << x + (max - 1) + gap_n << ", " << y - (max - 1) - gap_n << ") ���� " << "(" << x << ", " << y << ")" << endl;
		count++;
		x--; y--;//x,y �� ������ ��ǥ���� �ٽ� ����

		if (max == 3 && gap_n == 0) { // ���������� �̾��� ������ ��
			if (y - (max - 1) - gap_n >= 1 && x >= 1) { // �����ڸ��� �ƴ� ������
				if (bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "��" && bord[x - 1][y + 1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
					bord[x - 1][y + 1] = "��";
					bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "��";
				}
			}
		}
		if (max == 3 && gap_n == 1) { // ������ �� ���� ��ĭ�� �ϳ� �ִٸ�
			if (y - (max - 1) - gap_n >= 1 && x >= 1) { // �����ڸ��� �ƴ϶��
				if (bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "��" && bord[x - 1][y + 1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
					for (int a = x, b = y;; a++, b--) {
						if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
							bord[a][b] = "��";
							break;
						}
					}
				}
			}
		}
		if (max == 4 && gap_n == 1) { // �װ��� �� ���� ��ĭ�� �ϳ� �ִٸ�
			for (int a = x, b = y;; a++, b--) {
				if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
					bord[a][b] = "��";
					break;
				}
			}
		}
		if (max == 4 && gap_n == 0) { // �װ��� ���� ���������� �����ٸ�
			if (y - (max - 1) - gap_n == 0) {//���� ������ʾƷ��� �����ִٸ� ���ӵ� ���� ���������� ������
				bord[x - 1][y + 1] = "��";
			}
			else if (x == 0) {//���� �����ʰ������� �����ִٸ� ���� ���� �Ʒ��� �� ����
				bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "��";
			}
		}

		if (max >= 5) { // �ټ��� �� �̻��� �����̵� ��ĭ�� �ֵ�
			if (y - (max - 1) - gap_n > 0 && bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "��") {//�̾������� ���ʾƷ�ĭ�� ���� �ƴϰ� �浹�� ������ �ʾѴٸ�
				bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "��";//�̾��� ���� ���ʾƷ�ĭ�� ��ǥ����
			}
			if (x > 0 && bord[x - 1][y + 1] != "��") {//�̾��� ���� ��������ĭ�� ���̾ƴϰ� �浹�� ������ �ʾҴٸ�
				bord[x - 1][y + 1] = "��";//�̾��� ���� ������ ĭ�� ��ǥ����
			}
			for (int a = x, b = y;; a++, b--) {
				if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
					bord[a][b] = "��";
				}
				if (a == x + (max - 1) + gap_n && b == y - (max - 1) - gap_n)break;
			}
		}

		max = 0;
		Bcount = 0;
	}

	count = 1;
	max = 0;
	concount = 0;
	Bcount = 0;
	for (int i = 18; count <= 18; i = 18) {//�����ʾƷ� ���� �鵹
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
			if (max <= Bcount && concount == 0) {
				max = Bcount;
				x = i + 1;
				y = j + 1;
				gap_n = 0;
				for (int a = 0, b = 0;;) {
					if (bord[i + a][j - a] != "��")gap_n++;
					else if (bord[i + a][j - a] == "��")b++;
					if (b == Bcount)break;
					a++;
				}
			}
		}
		if (max > 1)cout << "������� �밢�� " << count + 19 << "��°���� ����� �� ���� " << max << "��"
			<< "��ǥ�� " << "(" << x + (max - 1) + gap_n << ", " << y - (max - 1) - gap_n << ") ���� " << "(" << x << ", " << y << ")" << endl;
		count++;
		x--; y--;//x,y �� ������ ��ǥ���� �ٽ� ����

		if (max == 3 && gap_n == 0) { // ���������� �̾��� ������ ��
			if (x + (max - 1) + gap_n < 18 && y < 18) { // �����ڸ��� �ƴ� ������
				if (bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "��" && bord[x - 1][y + 1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
					bord[x - 1][y + 1] = "��";
					bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "��";
				}
			}
		}
		if (max == 3 && gap_n == 1) { // ������ �� ���� ��ĭ�� �ϳ� �ִٸ�
			if (x + (max - 1) + gap_n < 18 && y < 18) { // �����ڸ��� �ƴ϶��
				if (bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "��" && bord[x - 1][y + 1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
					for (int a = x, b = y;; a++, b--) {
						if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
							bord[a][b] = "��";
							break;
						}
					}
				}
			}
		}
		if (max == 4 && gap_n == 1) { // �װ��� �� ���� ��ĭ�� �ϳ� �ִٸ�
			for (int a = x, b = y;; a++, b--) {
				if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
					bord[a][b] = "��";
					break;
				}
			}
		}
		if (max == 4 && gap_n == 0) { // �װ��� ���� ���������� �����ٸ�
			if (x + (max - 1) + gap_n == 18) {//���� ������ʾƷ��� �����ִٸ� ���ӵ� ���� ���������� ������
				bord[x - 1][y + 1] = "��";
			}
			else if (y == 18) {//���� �����ʰ������� �����ִٸ� ���� ���� �Ʒ��� �� ����
				bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "��";
			}
		}

		if (max >= 5) { // �ټ��� �� �̻��� �����̵� ��ĭ�� �ֵ�
			if (x + (max - 1) + gap_n < 18 && bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "��") {//�̾������� ���ʾƷ�ĭ�� ���� �ƴϰ� �浹�� ������ �ʾѴٸ�
				bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "��";//�̾��� ���� ���ʾƷ�ĭ�� ��ǥ����
			}
			if (y < 18 && bord[x - 1][y + 1] != "��") {//�̾��� ���� ������ĭ�� ���̾ƴϰ� �浹�� ������ �ʾҴٸ�
				bord[x - 1][y + 1] = "��";//�̾��� ���� ������ ĭ�� ��ǥ����
			}
			for (int a = x, b = y;; a++, b--) {
				if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
					bord[a][b] = "��";
				}
				if (a == x + (max - 1) + gap_n && b == y - (max - 1) - gap_n)break;
			}
		}
		max = 0;
		Bcount = 0;
	}
}

void diag2(string bord[19][19]) { // �»���� �밢��
	int x=0, y=0, gap_n = 0;
	int count = 0;
	int max = 0;
	int concount = 0;
	int Bcount = 0;
	for (int i = 0; i < 19; i = count) {//������ �� ���� �浹
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
			if (max <= Bcount && concount == 0) {
				max = Bcount;
				x = i + 1;
				y = j + 1;
				gap_n = 0;
				for (int a = 0, b = 0;;) {
					if (bord[i + a][j + a] != "��")gap_n++;
					else if (bord[i + a][j + a] == "��")b++;
					if (b == Bcount)break;
					a++;
				}
			}
		}
		if (max > 1)cout << "�»���� �밢�� " << count + 1 << "��°���� ����� �浹 ���� " << max << "��"
			<< "��ǥ�� " << "(" << x + (max - 1) + gap_n << ", " << y + (max - 1) + gap_n << ") ���� " << "(" << x << ", " << y << ")" << endl;
		count++;
		x--; y--;//x,y �� ������ ��ǥ���� �ٽ� ����

		if (max == 3 && gap_n == 0) { // ���������� �̾��� ������ ��
			if (y + (max - 1) + gap_n < 18 && x > 0) { // �����ڸ��� �ƴ� ������
				if (bord[x + (max - 1) + gap_n+1][y + (max - 1) + gap_n+1] != "��" && bord[x - 1][y -1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
					bord[x - 1][y - 1] = "��";
					bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "��";
				}
			}
		}
		if (max == 3 && gap_n == 1) { // ������ �� ���� ��ĭ�� �ϳ� �ִٸ�
			if (y + (max - 1) + gap_n < 18 && x > 0) { // �����ڸ��� �ƴ϶��
				if (bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] != "��" && bord[x - 1][y - 1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
					for (int a = x, b = y;; a++, b++) {
						if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
							bord[a][b] = "��";
							break;
						}
					}
				}
			}
		}
		if (max == 4 && gap_n == 1) { // �װ��� �� ���� ��ĭ�� �ϳ� �ִٸ�
			for (int a = x, b = y;; a++, b++) {
				if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
					bord[a][b] = "��";
					break;
				}
			}
		}
		if (max == 4 && gap_n == 0) { // �װ��� ���� ���������� �����ٸ�
			if (y + (max - 1) + gap_n == 18) {//���� ��������ʾƷ��� �����ִٸ� ���ӵ� ���� �������� ������
				bord[x-1][y - 1] = "��";
			}
			else if (x == 0) {//���� �����ʰ������� �����ִٸ� ���� ���� �Ʒ��� �� ����
				bord[x + (max - 1) + gap_n+1][y + (max - 1) + gap_n+1] = "��";
			}
		}

		if (max >= 5) { // �ټ��� �� �̻��� �����̵� ��ĭ�� �ֵ�
			if (y + (max - 1) + gap_n < 18 && bord[x + (max - 1) + gap_n+1][y + (max - 1) + gap_n+1] != "��") {//�̾������� �����ʾƷ�ĭ�� ���� �ƴϰ� �鵹�� ������ �ʾѴٸ�
				bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "��";//�̾��� ���� �����ʾƷ�ĭ�� ��ǥ����
			}
			if (x > 0 && bord[x-1][y - 1] != "��") {//�̾��� ���� ��������ĭ�� ���̾ƴϰ� �鵹�� ������ �ʾҴٸ�
				bord[x - 1][y - 1] = "��";//�̾��� ���� ������ ĭ�� ��ǥ����
			}
			for (int a = x, b = y;; a++, b++) {
				if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
					bord[a][b] = "��";
				}
				if (a == x + (max - 1) + gap_n && b == y + (max - 1) + gap_n)break;
			}
		}

		max = 0;
		Bcount = 0;
	}

	count = 17;
	max = 0;
	concount = 0;
	Bcount = 0;
	for (int i = 18; count >= 0; i = 18) {//���ʾƷ� ���� �浹
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
			if (max <= Bcount && concount == 0) {
				max = Bcount;
				x = i + 1;
				y = j + 1;
				gap_n = 0;
				for (int a = 0, b = 0;;) {
					if (bord[i + a][j + a] != "��")gap_n++;
					else if (bord[i + a][j + a] == "��")b++;
					if (b == Bcount)break;
					a++;
				}
			}
		}
		if (max > 1)cout << "�»���� �밢�� " << 37 - count << "��°���� ����� �浹 ���� " << max << "��"
			<< "��ǥ�� " << "(" << x + (max - 1) + gap_n << ", " << y + (max - 1) + gap_n << ") ���� " << "(" << x << ", " << y << ")" << endl;
		count--;
		x--; y--;//x,y �� ������ ��ǥ���� �ٽ� ����

		if (max == 3 && gap_n == 0) { // ���������� �̾��� ������ ��
			if (y>0&& x + (max - 1) + gap_n<18) { // �����ڸ��� �ƴ� ������
				if (bord[x + (max - 1) + gap_n+1][y + (max - 1) + gap_n+1] != "��" && bord[x - 1][y - 1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
					bord[x - 1][y - 1] = "��";
					bord[x + (max - 1) + gap_n+1][y + (max - 1) + gap_n+1] = "��";
				}
			}
		}
		if (max == 3 && gap_n == 1) { // ������ �� ���� ��ĭ�� �ϳ� �ִٸ�
			if (y > 0 && x + (max - 1) + gap_n < 18) { // �����ڸ��� �ƴ� ������
				if (bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] != "��" && bord[x - 1][y - 1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
					for (int a = x, b = y;; a++, b++) {
						if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
							bord[a][b] = "��";
							break;
						}
					}
				}
			}
		}
		if (max == 4 && gap_n == 1) { // �װ��� �� ���� ��ĭ�� �ϳ� �ִٸ�
			for (int a = x, b = y;; a++, b++) {
				if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
					bord[a][b] = "��";
					break;
				}
			}
		}
		if (max == 4 && gap_n == 0) { // �װ��� ���� ���������� �����ٸ�
			if (x + (max - 1) + gap_n == 18) {//���� ��������ʾƷ��� �����ִٸ� ���ӵ� ���� �������� ������
				bord[x - 1][y - 1] = "��";
			}
			else if (y == 0) {//���� �����ʰ������� �����ִٸ� ���� ���� �Ʒ��� �� ����
				bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "��";
			}
		}

		if (max >= 5) { // �ټ��� �� �̻��� �����̵� ��ĭ�� �ֵ�
			if (x + (max - 1) + gap_n < 18 && bord[x + (max - 1) + gap_n+1][y + (max - 1) + gap_n+1] != "��") {//�̾������� �����ʾƷ�ĭ�� ���� �ƴϰ� �鵹�� ������ �ʾѴٸ�
				bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "��";//�̾��� ���� �����ʾƷ�ĭ�� ��ǥ����
			}
			if (y > 0 && bord[x - 1][y - 1] != "��") {//�̾��� ���� ������ĭ�� ���̾ƴϰ� �鵹�� ������ �ʾҴٸ�
				bord[x - 1][y - 1] = "��";//�̾��� ���� ������ ĭ�� ��ǥ����
			}
			for (int a = x, b = y;; a++, b++) {
				if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
					bord[a][b] = "��";
				}
				if (a == x + (max - 1) + gap_n && b == y + (max - 1) + gap_n)break;
			}
		}

		max = 0;
		Bcount = 0;
	}

	count = 0;
	max = 0;
	concount = 0;
	Bcount = 0;
	for (int i = 0; i < 19; i = count) {//������ �� ���� �鵹
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
			if (max <= Bcount && concount == 0) {
				max = Bcount;
				x = i + 1;
				y = j + 1;
				gap_n = 0;
				for (int a = 0, b = 0;;) {
					if (bord[i + a][j + a] != "��")gap_n++;
					else if (bord[i + a][j + a] == "��")b++;
					if (b == Bcount)break;
					a++;
				}
			}
		}
		if (max > 1)cout << "�»���� �밢�� " << count + 1 << "��°���� ����� �� ���� " << max << "��"
			<< "��ǥ�� " << "(" << x + (max - 1) + gap_n << ", " << y + (max - 1) + gap_n << ") ���� " << "(" << x << ", " << y << ")" << endl;
		count++;
		x--; y--;//x,y �� ������ ��ǥ���� �ٽ� ����

		if (max == 3 && gap_n == 0) { // ���������� �̾��� ������ ��
			if (y + (max - 1) + gap_n < 18 && x > 0) { // �����ڸ��� �ƴ� ������
				if (bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] != "��" && bord[x - 1][y - 1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
					bord[x - 1][y - 1] = "��";
					bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "��";
				}
			}
		}
		if (max == 3 && gap_n == 1) { // ������ �� ���� ��ĭ�� �ϳ� �ִٸ�
			if (y + (max - 1) + gap_n < 18 && x > 0) { // �����ڸ��� �ƴ϶��
				if (bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] != "��" && bord[x - 1][y - 1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
					for (int a = x, b = y;; a++, b++) {
						if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
							bord[a][b] = "��";
							break;
						}
					}
				}
			}
		}
		if (max == 4 && gap_n == 1) { // �װ��� �� ���� ��ĭ�� �ϳ� �ִٸ�
			for (int a = x, b = y;; a++, b++) {
				if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
					bord[a][b] = "��";
					break;
				}
			}
		}
		if (max == 4 && gap_n == 0) { // �װ��� ���� ���������� �����ٸ�
			if (y + (max - 1) + gap_n == 18) {//���� ��������ʾƷ��� �����ִٸ� ���ӵ� ���� �������� ������
				bord[x - 1][y - 1] = "��";
			}
			else if (x == 0) {//���� �����ʰ������� �����ִٸ� ���� ���� �Ʒ��� �� ����
				bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "��";
			}
		}

		if (max >= 5) { // �ټ��� �� �̻��� �����̵� ��ĭ�� �ֵ�
			if (y + (max - 1) + gap_n < 18 && bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] != "��") {//�̾������� �����ʾƷ�ĭ�� ���� �ƴϰ� �浹�� ������ �ʾѴٸ�
				bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "��";//�̾��� ���� �����ʾƷ�ĭ�� ��ǥ����
			}
			if (x > 0 && bord[x - 1][y - 1] != "��") {//�̾��� ���� ��������ĭ�� ���̾ƴϰ� �浹�� ������ �ʾҴٸ�
				bord[x - 1][y - 1] = "��";//�̾��� ���� ������ ĭ�� ��ǥ����
			}
			for (int a = x, b = y;; a++, b++) {
				if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
					bord[a][b] = "��";
				}
				if (a == x + (max - 1) + gap_n && b == y + (max - 1) + gap_n)break;
			}
		}

		max = 0;
		Bcount = 0;
	}

	count = 17;
	max = 0;
	concount = 0;
	Bcount = 0;
	for (int i = 18; count >= 0; i = 18) {//���� �Ʒ� ���� �鵹
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
			if (max <= Bcount && concount == 0) {
				max = Bcount;
				x = i + 1;
				y = j + 1;
				gap_n = 0;
				for (int a = 0, b = 0;;) {
					if (bord[i + a][j + a] != "��")gap_n++;
					else if (bord[i + a][j + a] == "��")b++;
					if (b == Bcount)break;
					a++;
				}
			}
		}
		if (max > 1)cout << "�»���� �밢�� " << 37 - count << "��°���� ����� �� ���� " << max << "��"
			<< "��ǥ�� " << "(" << x + (max - 1) + gap_n << ", " << y + (max - 1) + gap_n << ") ���� " << "(" << x << ", " << y << ")" << endl;
		count--;
		x--; y--;//x,y �� ������ ��ǥ���� �ٽ� ����

		if (max == 3 && gap_n == 0) { // ���������� �̾��� ������ ��
			if (y > 0 && x + (max - 1) + gap_n < 18) { // �����ڸ��� �ƴ� ������
				if (bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] != "��" && bord[x - 1][y - 1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
					bord[x - 1][y - 1] = "��";
					bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "��";
				}
			}
		}
		if (max == 3 && gap_n == 1) { // ������ �� ���� ��ĭ�� �ϳ� �ִٸ�
			if (y > 0 && x + (max - 1) + gap_n < 18) { // �����ڸ��� �ƴ� ������
				if (bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] != "��" && bord[x - 1][y - 1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
					for (int a = x, b = y;; a++, b++) {
						if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
							bord[a][b] = "��";
							break;
						}
					}
				}
			}
		}
		if (max == 4 && gap_n == 1) { // �װ��� �� ���� ��ĭ�� �ϳ� �ִٸ�
			for (int a = x, b = y;; a++, b++) {
				if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
					bord[a][b] = "��";
					break;
				}
			}
		}
		if (max == 4 && gap_n == 0) { // �װ��� ���� ���������� �����ٸ�
			if (x + (max - 1) + gap_n == 18) {//���� ��������ʾƷ��� �����ִٸ� ���ӵ� ���� �������� ������
				bord[x - 1][y - 1] = "��";
			}
			else if (y == 0) {//���� �����ʰ������� �����ִٸ� ���� ���� �Ʒ��� �� ����
				bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "��";
			}
		}

		if (max >= 5) { // �ټ��� �� �̻��� �����̵� ��ĭ�� �ֵ�
			if (x + (max - 1) + gap_n < 18 && bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] != "��") {//�̾������� �����ʾƷ�ĭ�� ���� �ƴϰ� �浹�� ������ �ʾѴٸ�
				bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "��";//�̾��� ���� �����ʾƷ�ĭ�� ��ǥ����
			}
			if (y > 0 && bord[x - 1][y - 1] != "��") {//�̾��� ���� ������ĭ�� ���̾ƴϰ� �浹�� ������ �ʾҴٸ�
				bord[x - 1][y - 1] = "��";//�̾��� ���� ������ ĭ�� ��ǥ����
			}
			for (int a = x, b = y;; a++, b++) {
				if (bord[a][b] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
					bord[a][b] = "��";
				}
				if (a == x + (max - 1) + gap_n && b == y + (max - 1) + gap_n)break;
			}
		}

		max = 0;
		Bcount = 0;
	}
}

int main() {
	string bord[19][19];
	bordclear(bord);
	printbord(bord);

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

		system("cls");

		int max = 0;
		x = 0, y = 0;
		int tmp = 0;
		int concount = 0; // �����Ѱ��� ���������� 0 ��ĭ ������������ 1 ��ĭ�������� 2
		int gap_n = 0;
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
				if (max <= Bcount && concount == 0) {
					max = Bcount;
					x = i + 1;
					y = j + 1;
					gap_n = 0;
					for (int a = 0, b = 0;;) {
						if (bord[i][j - a] != "��")gap_n++;
						else if (bord[i][j - a] == "��")b++;
						if (b == Bcount)break;
						a++;
					}
				}
			}
			if (max > 1)cout << i + 1 << "���� �̾��� ����� �浹 ���� " << max << "�� "
				<< "��ǥ�� " << "(" << x << ", " << y - (max - 1) - gap_n << ") ���� " << "(" << x << ", " << y << ")" << endl;
			x--; y--;//x,y �� ������ ��ǥ���� �ٽ� ����
			if (max == 3 && gap_n == 0) { // ���������� �̾��� ������ ��
				if (y < 18 && (y - (max - 1) - gap_n)>0) { // �����ڸ��� �ƴ� ������
					if (bord[x][y + 1] != "��" && bord[x][y - (max - 1) - gap_n - 1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
						bord[x][y + 1] = "��";
						bord[x][y - (max - 1) - gap_n - 1] = "��";
					}
				}
			}
			if (max == 3 && gap_n == 1) { // ������ �� ���� ��ĭ�� �ϳ� �ִٸ�
				if (y < 18 && (y - (max - 1) - gap_n)>0) { // �����ڸ��� �ƴ϶��
					if (bord[x][y + 1] != "��" && bord[x][y - (max - 1) - gap_n - 1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
						for (int a = y;; a--) {
							if (bord[x][a] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
								bord[x][a] = "��";
								break;
							}
						}
					}
				}
			}
			if (max == 4 && gap_n == 1) { // �װ��� �� ���� ��ĭ�� �ϳ� �ִٸ�
				for (int a = y;; a--) {
					if (bord[x][a] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
						bord[x][a] = "��";
						break;
					}
				}
			}
			if (max == 4 && gap_n == 0) { // �װ��� ���� ���������� �����ٸ�
				if (y == 18) {//���� ������ �����ڸ��� �����ִٸ� ���ӵ� ���� ����ĭ�� �� ����
					bord[x][y - (max - 1) - gap_n - 1] = "��";
				}
				else if ((y - (max - 1) - gap_n) == 0) {//���� ���� �����ڸ��� �����ִٸ� ���ӵ� ���� ������ĭ�� �� ����
					bord[x][y + 1] = "��";
				}
			}

			if (max >= 5) { // �ټ��� �� �̻��� �����̵� ��ĭ�� �ֵ�
				if (y - (max - 1) - gap_n - 1 >= 0 && bord[x][y - (max - 1) - gap_n - 1]!= "��") {//�̾������� ����ĭ�� ���� �ƴϰ� �鵹�� ������ �ʾѴٸ�
					bord[x][y - (max - 1) - gap_n - 1] = "��";//�̾��� ���� ����ĭ�� ��ǥ����
				}
				if (y + 1 <= 18 && bord[x][y + 1] != "��") {//�̾��� ���� ������ĭ�� ���̾ƴϰ� �鵹�� ������ �ʾҴٸ�
					bord[x][y + 1] = "��";//�̾��� ���� ������ ĭ�� ��ǥ����
				}
				for (int a = y;a>= y - (max - 1) - gap_n; a--) {//�̾��� ���� ��ǥ����
					if(bord[x][a]!= "��" && bord[x][a]!= "��")//��ĭ�� �ִٸ�
						bord[x][a]= "��";//��ĭ�� ��ǥ ����
				}
			}
			
			max = 0;
			Bcount = 0;
		}
		//���࿡ �������� �����ΰ�

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
				if (max <= Bcount && concount == 0) {
					max = Bcount;
					x = i + 1;
					y = j + 1;
					gap_n = 0;
					for (int a = 0, b = 0;;) {
						if (bord[i - a][j] != "��")gap_n++;
						else if (bord[i - a][j] == "��")b++;
						if (b == Bcount)break;
						a++;
					}
				}
			}
			if (max > 1)cout << j + 1 << "���� �̾��� ����� �浹 ���� " << max << "�� "
				<< "��ǥ�� " << "(" << x - (max - 1)-gap_n << ", " << y << ") ���� " << "(" << x << ", " << y << ")" << endl;
			x--; y--;//x,y �� ������ ��ǥ���� �ٽ� ����
			if (max == 3 && gap_n == 0) { // ���������� �̾��� ������ ��
				if (x < 18 && (x - (max - 1) - gap_n)>0) { // �����ڸ��� �ƴ� ������
					if (bord[x+1][y] != "��" && bord[x - (max - 1) - gap_n-1][y] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
						bord[x+1][y] = "��";
						bord[x - (max - 1) - gap_n-1][y] = "��";
					}
				}
			}
			if (max == 3 && gap_n == 1) { // ������ �� ���� ��ĭ�� �ϳ� �ִٸ�
				if (x < 18 && (x - (max - 1) - gap_n)>0) { // �����ڸ��� �ƴ϶��
					if (bord[x+1][y] != "��" && bord[x - (max - 1) - gap_n-1][y] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
						for (int a = x;; a--) {
							if (bord[a][y] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
								bord[a][y] = "��";
								break;
							}
						}
					}
				}
			}
			if (max == 4 && gap_n == 1) { // �װ��� �� ���� ��ĭ�� �ϳ� �ִٸ�
				for (int a = x;; a--) {
					if (bord[a][y] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
						bord[a][y] = "��";
						break;
					}
				}
			}
			if (max == 4 && gap_n == 0) { // �װ��� ���� ���������� �����ٸ�
				if (x == 18) {//���� ������ �����ڸ��� �����ִٸ� ���ӵ� ���� ����ĭ�� �� ����
					bord[x - (max - 1) - gap_n - 1][y] = "��";
				}
				else if ((x- (max - 1) - gap_n) == 0) {//���� ���� �����ڸ��� �����ִٸ� ���ӵ� ���� ������ĭ�� �� ����
					bord[x+1][y] = "��";
				}
			}

			if (max >= 5) { // �ټ��� �� �̻��� �����̵� ��ĭ�� �ֵ�
				if (x - (max - 1) - gap_n - 1 >= 0 && bord[x - (max - 1) - gap_n - 1][y] != "��") {//�̾������� ��ĭ�� ���� �ƴϰ� �鵹�� ������ �ʾѴٸ�
					bord[x - (max - 1) - gap_n - 1][y] = "��";//�̾��� ���� ����ĭ�� ��ǥ����
				}
				if (x + 1 <= 18 && bord[x+1][y] != "��") {//�̾��� ���� ������ĭ�� ���̾ƴϰ� �鵹�� ������ �ʾҴٸ�
					bord[x+1][y] = "��";//�̾��� ���� ������ ĭ�� ��ǥ����
				}
				for (int a = x; a >= x - (max - 1) - gap_n; a--) {//�̾��� ���� ��ǥ����
					if (bord[a][y] != "��" && bord[a][y] != "��")//��ĭ�� �ִٸ�
						bord[a][y] = "��";//��ĭ�� ��ǥ ����
				}
			}

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
				if (max <= Wcount && concount == 0) {
					max = Wcount;
					x = i + 1;
					y = j + 1;
					gap_n = 0;
					for (int a = 0, b = 0;;) {
						if (bord[i][j - a] != "��")gap_n++;
						else if (bord[i][j - a] == "��")b++;
						if (b == Wcount)break;
						a++;
					}
				}


			}
			if (max > 1)cout << i + 1 << "���� �̾��� ����� �� ���� " << max << "�� "
				<< "��ǥ�� " << "(" << x << ", " << y - (max - 1) - gap_n << ") ���� " << "(" << x << ", " << y << ")" << endl;
			x--; y--;//x,y �� ������ ��ǥ���� �ٽ� ����
			if (max == 3 && gap_n == 0) { // ���������� �̾��� ������ ��
				if (y < 18 && (y - (max - 1) - gap_n)>0) { // �����ڸ��� �ƴ� ������
					if (bord[x][y + 1] != "��" && bord[x][y - (max - 1) - gap_n - 1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
						bord[x][y + 1] = "��";
						bord[x][y - (max - 1) - gap_n - 1] = "��";
					}
				}
			}
			if (max == 3 && gap_n == 1) { // ������ �� ���� ��ĭ�� �ϳ� �ִٸ�
				if (y < 18 && (y - (max - 1) - gap_n)>0) { // �����ڸ��� �ƴ϶��
					if (bord[x][y + 1] != "��" && bord[x][y - (max - 1) - gap_n - 1] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
						for (int a = y;; a--) {
							if (bord[x][a] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
								bord[x][a] = "��";
								break;
							}
						}
					}
				}
			}
			if (max == 4 && gap_n == 1) { // �װ��� �� ���� ��ĭ�� �ϳ� �ִٸ�
				for (int a = y;; a--) {
					if (bord[x][a] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
						bord[x][a] = "��";
						break;
					}
				}
			}
			if (max == 4 && gap_n == 0) { // �װ��� ���� ���������� �����ٸ�
				if (y == 18) {//���� ������ �����ڸ��� �����ִٸ� ���ӵ� ���� ����ĭ�� �� ����
					bord[x][y - (max - 1) - gap_n - 1] = "��";
				}
				else if ((y - (max - 1) - gap_n) == 0) {//���� ���� �����ڸ��� �����ִٸ� ���ӵ� ���� ������ĭ�� �� ����
					bord[x][y + 1] = "��";
				}
			}

			if (max >= 5) { // �ټ��� �� �̻��� �����̵� ��ĭ�� �ֵ�
				if (y - (max - 1) - gap_n - 1 >= 0 && bord[x][y - (max - 1) - gap_n - 1] != "��") {//�̾������� ����ĭ�� ���� �ƴϰ� �鵹�� ������ �ʾѴٸ�
					bord[x][y - (max - 1) - gap_n - 1] = "��";//�̾��� ���� ����ĭ�� ��ǥ����
				}
				if (y + 1 <= 18 && bord[x][y + 1] != "��") {//�̾��� ���� ������ĭ�� ���̾ƴϰ� �浹�� ������ �ʾҴٸ�
					bord[x][y + 1] = "��";//�̾��� ���� ������ ĭ�� ��ǥ����
				}
				for (int a = y; a >= y - (max - 1) - gap_n; a--) {//�̾��� ���� ��ǥ����
					if (bord[x][a] != "��" && bord[x][a] != "��")//��ĭ�� �ִٸ�
						bord[x][a] = "��";//��ĭ�� ��ǥ ����
				}
			}

			max = 0;
			Bcount = 0;
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
				if (max <= Wcount && concount == 0) {
					max = Wcount;
					x = i + 1;
					y = j + 1;
					gap_n = 0;
					for (int a = 0, b = 0;;) {
						if (bord[i - a][j] != "��")gap_n++;
						else if (bord[i - a][j] == "��")b++;
						if (b == Wcount)break;
						a++;
					}
				}
			}
			if (max > 1)cout << j + 1 << "���� �̾��� ����� �� ���� " << max << "�� "
				<< "��ǥ�� " << "(" << x - (max - 1) - gap_n << ", " << y << ") ���� " << "(" << x << ", " << y << ")" << endl;
			x--; y--;//x,y �� ������ ��ǥ���� �ٽ� ����
			if (max == 3 && gap_n == 0) { // ���������� �̾��� ������ ��
				if (x < 18 && (x - (max - 1) - gap_n)>0) { // �����ڸ��� �ƴ� ������
					if (bord[x + 1][y] != "��" && bord[x - (max - 1) - gap_n - 1][y] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
						bord[x + 1][y] = "��";
						bord[x - (max - 1) - gap_n - 1][y] = "��";
					}
				}
			}
			if (max == 3 && gap_n == 1) { // ������ �� ���� ��ĭ�� �ϳ� �ִٸ�
				if (x < 18 && (x - (max - 1) - gap_n)>0) { // �����ڸ��� �ƴ϶��
					if (bord[x + 1][y] != "��" && bord[x - (max - 1) - gap_n - 1][y] != "��") {//�翷 ��� �ٸ����� �������� �ʴٸ�
						for (int a = x;; a--) {
							if (bord[a][y] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
								bord[a][y] = "��";
								break;
							}
						}
					}
				}
			}
			if (max == 4 && gap_n == 1) { // �װ��� �� ���� ��ĭ�� �ϳ� �ִٸ�
				for (int a = x;; a--) {
					if (bord[a][y] != "��") {//�ش� ĭ�� ��ĭ�̶�� ��ǥ�� ����
						bord[a][y] = "��";
						break;
					}
				}
			}
			if (max == 4 && gap_n == 0) { // �װ��� ���� ���������� �����ٸ�
				if (x == 18) {//���� ������ �����ڸ��� �����ִٸ� ���ӵ� ���� ����ĭ�� �� ����
					bord[x - (max - 1) - gap_n - 1][y] = "��";
				}
				else if ((x - (max - 1) - gap_n) == 0) {//���� ���� �����ڸ��� �����ִٸ� ���ӵ� ���� ������ĭ�� �� ����
					bord[x + 1][y] = "��";
				}
			}

			if (max >= 5) { // �ټ��� �� �̻��� �����̵� ��ĭ�� �ֵ�
				if (x - (max - 1) - gap_n - 1 >= 0 && bord[x - (max - 1) - gap_n - 1][y] != "��") {//�̾������� ��ĭ�� ���� �ƴϰ� �浹�� ������ �ʾѴٸ�
					bord[x - (max - 1) - gap_n - 1][y] = "��";//�̾��� ���� ����ĭ�� ��ǥ����
				}
				if (x + 1 <= 18 && bord[x + 1][y] != "��") {//�̾��� ���� ������ĭ�� ���̾ƴϰ� �浹�� ������ �ʾҴٸ�
					bord[x + 1][y] = "��";//�̾��� ���� ������ ĭ�� ��ǥ����
				}
				for (int a = x; a >= x - (max - 1) - gap_n; a--) {//�̾��� ���� ��ǥ����
					if (bord[a][y] != "��" && bord[a][y] != "��")//��ĭ�� �ִٸ�
						bord[a][y] = "��";//��ĭ�� ��ǥ ����
				}
			}

			max = 0;
			Bcount = 0;
		}

		diag(bord);
		diag2(bord);

		printbord(bord);
		bordclear(bord);


	}//���Ϲ� ��
}//���ι� ��

//���浹 �ܹ鵹