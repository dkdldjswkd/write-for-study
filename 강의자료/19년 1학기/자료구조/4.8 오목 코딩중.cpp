#include <iostream>
#include <string>
using namespace std;

//�� �� �� �� �� �� �� �� ��

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
	bool jb = false;

	while (1) { // ���⼭���� ��������

		while (1) { // �浹�� �δ� �˰���
			jb = false;
			cout << "�浹�� ���� : " << black << endl;
			cout << "���� ���� : " << white << endl;
			cout << "�浹�� ���� �ڸ��� �Է��ϼ��� : ";
			rewind(stdin); // �Է¹��� ����
			cin >> x >> y; // ��ǥ�� �Է¹���
			if (x > 19 || y > 19 || x < 1 || y < 1) {
				cout << "���ڸ� Ȯ���ϰ� �ٽ� �Է����ּ���" << endl;
				continue;
			}
			for (int i = 0; i < 19; i++) {
				for (int j = 0; j < 19; j++) {
					if (bord[i][j] == "��" || bord[i][j] == "��") {
						jb = true;
						cout << "�̹� ���� ĭ�Դϴ� �ٽ� �Է����ּ���" << endl;
						break;
					}
				}
				if (jb)break;
			}
			if (jb)continue;

			bord[x - 1][y - 1] = "��"; // �� ��ǥ�� �浹 ����
			black++;

			for (int i = 0; i < 19; i++) { // �ٵ��� ���
				for (int j = 0; j < 19; j++) {
					cout << bord[i][j];
					if (!(bord[i][j] == "��" || bord[i][j] == "��")) cout << " ";
				}
				cout << endl;
			}
			break;
		}

		while (1) { // ���� �δ� �˰���
			jb = 0;
			cout << "�浹�� ���� : " << black << endl;
			cout << "���� ���� : " << white << endl;
			cout << "���� ���� �ڸ��� �Է��ϼ��� : ";
			rewind(stdin); // �Է¹��� ����
			cin >> x >> y; // ��ǥ�� �Է¹���
			if (x > 19 || y > 19 || x < 1 || y < 1) {
				cout << "���ڸ� Ȯ���ϰ� �ٽ� �Է����ּ���" << endl;
				continue;
			}
			for (int i = 0; i < 19; i++) {
				for (int j = 0; j < 19; j++) {
					if (bord[i][j] == "��" || bord[i][j] == "��") {
						jb = true;
						cout << "�̹� ���� ĭ�Դϴ� �ٽ� �Է����ּ���" << endl;
						break;
					}
				}
				if (jb)break;
			}
			if (jb)continue;
			bord[x - 1][y - 1] = "��"; // �� ��ǥ�� �� ����
			white++;

			for (int i = 0; i < 19; i++) { // �ٵ��� ���
				for (int j = 0; j < 19; j++) {
					cout << bord[i][j];
					if (!(bord[i][j] == "��" || bord[i][j] == "��")) cout << " ";
				}
				cout << endl;
			}
			break;
		}

	}
}