#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

//�� �� �� �� �� �� �� �� ��
// ����� 19 X 19

struct re {
	int x = 0, y = 0;
	re* before;
	bool who = true;
	void color(int turn) { if (turn % 2 == 1)who = true; else if (turn % 2 == 0)who = false; }
};

struct rere {
	int x = 0, y = 0;
	rere* before;
	bool who = true;
	void color(int turn) { if (turn % 2 == 1)who = true; else if (turn % 2 == 0)who = false; }
};

re* p = NULL, * tail = NULL, * head = NULL;
rere* rerep = NULL, * reretail = NULL, * rerehead = NULL;


void re_push(int x, int y, int turn) {
	p->x = x, p->y = y;
	p->before = tail;
	tail = p;
	p->color(turn);
}

void rere_push() {
	rerep->x = p->x;
	rerep->y = p->y;
	rerep->who = p->who;
	if (reretail == NULL) {
		rerep->before = NULL;
		reretail = rerep;
	}
	else {
		rerep->before = reretail;
		reretail = rerep;
	}
}

void rere_alldel() {
	rerep = NULL;
	reretail = NULL;
}

void rere_del() {
	if (rerep->before == NULL) {
		rerep = NULL; reretail = NULL;
	}
	else {
		rerep = rerep->before;
		reretail = rerep;
	}
}

void re_del() {
	if (p->before == NULL) {
		p = NULL; tail = NULL;
	}
	else {
		p = p->before;
		tail = p;
	}
}

void save(ofstream & fout, string bord[19][19], int turn, int black, int white, int mmn) {
	fout << "bord" << endl;
	for (int i = 0; i <= 18; i++) {
		for (int j = 0; j <= 18; j++) {
			fout << bord[i][j] << endl;
		}
	}

	fout << "turn" << endl;
	fout << turn << endl;

	fout << "black" << endl;
	fout << black << endl;
	fout << "white" << endl;
	fout << white << endl;
	fout << "mmn" << endl;
	fout << mmn << endl;

	if (p != NULL) {
		fout << "re" << endl;
		for (p = tail;; p = p->before) {
			fout << p->x << " " << p->y << " " << p->who << endl;
			if (p->before == NULL) { p = tail; break; }
		}
	}

	if (rerep != NULL) {
		fout << "rere" << endl;
		for (rerep = reretail;; rerep = rerep->before) {
			fout << rerep->x << " " << rerep->y << " " << rerep->who << endl;
			if (rerep->before == NULL) { p = tail; break; }
		}
	}


}

void Load(ifstream & fin, string bord[19][19], int& turn, int& black, int& white, int& mmn) {
	string check;
	int intcheck;
	while (!fin.eof()) {
		fin >> check;
		//fin >> check;
		if (check == "bord") {
			for (int i = 0; i <= 18; i++) {
				for (int j = 0; j <= 18; j++) {
					fin >> check;
					//cout << check << endl;
					bord[i][j] = check;
				}
			}
			continue;
		}

		if (check == "turn") {
			fin >> intcheck;
			turn = intcheck;
			continue;
		}

		if (check == "black") {
			fin >> intcheck;
			black = intcheck;
			continue;
		}

		if (check == "white") {
			fin >> intcheck;
			white = intcheck;
			continue;
		}

		if (check == "mmn") {
			fin >> intcheck;
			mmn = intcheck;
			continue;
		}

		if (check == "re") {
			bool first = true;
			for (int i = 0; i < turn - 1; i++) {
				if (first) {
					p = new re[sizeof(re)];
					fin >> intcheck;
					p->x = intcheck;
					fin >> intcheck;
					p->y = intcheck;
					fin >> intcheck;
					p->who = intcheck;
					p->before = NULL;
					tail = p;
					head = p;
					first = false;
				}
				else {
					p = new re[sizeof(re)];
					fin >> intcheck;
					p->x = intcheck;
					fin >> intcheck;
					p->y = intcheck;
					fin >> intcheck;
					p->who = intcheck;
					head->before = p;
					head = p;
					p->before = NULL;
					p = tail;
				}
			}
			continue;
		}

		if (check == "rere") {
			bool first = true;
			for (int i = 0; i < mmn; i++) {
				if (first) {
					rerep = new rere[sizeof(rere)];
					fin >> intcheck;
					rerep->x = intcheck;
					fin >> intcheck;
					rerep->y = intcheck;
					fin >> intcheck;
					rerep->who = intcheck;
					rerep->before = NULL;
					reretail = rerep;
					rerehead = rerep;
					first = false;
				}
				else {
					p = new re[sizeof(re)];
					fin >> intcheck;
					rerep->x = intcheck;
					fin >> intcheck;
					rerep->y = intcheck;
					fin >> intcheck;
					rerep->who = intcheck;
					rerehead->before = rerep;
					rerehead = rerep;
					rerep->before = NULL;
					rerep = reretail;
				}
			}
			return;
		}



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

	ifstream fin("test.txt");
	int black = 0, white = 0; // �浹�� �鵹�� �� ����
	bool who = true; // ���϶� �浹 �����϶� �鵹
	bool first = true;
	int Bcount = 0, Wcount = 0; // �浹�� �鵹�� �Ϻ� ����
	int manyWB = 1, manyWW = 1, manyHB = 1, manyHW = 1;
	int diaB = 1, diaW = 1, diaB2 = 1, diaW2 = 1;
	bool conCheck = false;
	int x, y; // x, y�� ��ǥ
	int turn = 1; //Ȧ����� �浹���� ¦����� �鵹����
	int mmn = 0;

	while (1) { // ���� ���Ϲ�
	//	int nResult = remove("test.txt");
		cout << endl;
		cout << turn << "��° �� �Դϴ�." << endl;
		cout << "�浹�� ���� : " << black << endl;
		cout << "���� ���� : " << white << endl;
		cout << "U : ������ R : ������ ��� S : ���� �� ���� L : �ҷ����� (�ٸ�Ű ������ �������) : ";
		char replay; cin >> replay;

		if (turn == 1 && replay == 'U') {
			cout << "1�Ͽ��� �����Ⱑ �Ұ��� �մϴ�." << endl;
		}
		else if (replay == 'U') {
			mmn++; //������ �޾�ġ���� ���ð����� ������Ŵ
			p = tail;
			rerep = new rere[sizeof(rere)];
			rere_push();
			if (p->x == 0 && p->y == 0) {
				bord[p->x][p->y] = "��";
			}
			else if (p->x == 0 && p->y == 18) {
				bord[p->x][p->y] = "��";
			}
			else if (p->x == 18 && p->y == 0) {
				bord[p->x][p->y] = "��";
			}
			else if (p->x == 18 && p->y == 18) {
				bord[p->x][p->y] = "��";
			}
			else if (p->x == 0) {
				bord[p->x][p->y] = "��";
			}
			else if (p->x == 18) {
				bord[p->x][p->y] = "��";
			}
			else if (p->y == 0) {
				bord[p->x][p->y] = "��";
			}
			else if (p->y == 18) {
				bord[p->x][p->y] = "��";
			}
			else {
				bord[p->x][p->y] = "��";
			}

			re_del();
			turn--;

			system("cls");

			for (int i = 0; i < 19; i++) { // �ٵ��� ���
				for (int j = 0; j < 19; j++) {
					cout << bord[i][j];
					if (!(bord[i][j] == "��" || bord[i][j] == "��")) cout << " ";
				}
				cout << endl;
			}
			cout << endl;
			continue;
		}
		else if (replay == 'R' && rerep == NULL) {
			cout << "������ ��� �� ���� �����ϴ�." << endl;
		}
		else if (replay == 'R') {

			if (rerep->who == true) {
				bord[rerep->x][rerep->y] = "��";
			}
			else if (rerep->who == false) {
				bord[rerep->x][rerep->y] = "��";
			}

			turn++;
			p = new re[sizeof(re)];
			re_push(rerep->x, rerep->y, turn);

			rere_del();
			system("cls");

			for (int i = 0; i < 19; i++) { // �ٵ��� ���
				for (int j = 0; j < 19; j++) {
					cout << bord[i][j];
					if (!(bord[i][j] == "��" || bord[i][j] == "��")) cout << " ";
				}
				cout << endl;
			}
			cout << endl;
			continue;
		}
		else if (replay == 'S') {
			ofstream fout("test.txt");
			save(fout, bord, turn, black, white, mmn);
			cout << "����Ǿ����ϴ�." << endl;
			return 0;
		}
		else if (replay == 'L') {
			Load(fin, bord, turn, black, white, mmn);
			system("cls");
			cout << "����� ���Ϸ� ������ �����մϴ�." << endl;
			for (int i = 0; i < 19; i++) { // �ٵ��� ���
				for (int j = 0; j < 19; j++) {
					cout << bord[i][j];
					if (!(bord[i][j] == "��" || bord[i][j] == "��")) cout << " ";
				}
				cout << endl;
			}
			cout << endl;
			for (p = tail;; p = p->before) {
				cout << p->x << " " << p->y << " " << " " << p->who << endl;
				if (p->before == NULL)break;
			}
			continue;
		}

		if (turn % 2 == 1) {
			cout << "�浹�� ���� �ڸ��� �Է��ϼ���  : ";
			rere_alldel();
		}
		else {
			cout << "�鵹�� ���� �ڸ��� �Է��ϼ��� : ";
			rere_alldel();
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
				p = new re[sizeof(re)];
				if (turn == 1) {
					p->x = x - 1, p->y = y - 1;
					p->before = NULL;
					tail = p;
					p->color(turn);
				}
				else {
					re_push(x - 1, y - 1, turn);
				}
				turn++;
			}
			else {
				bord[x - 1][y - 1] = "��"; // �� ��ǥ�� �浹 ����
				white++;
				who = true;
				p = new re[sizeof(re)];
				re_push(x - 1, y - 1, turn);
				turn++;
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

	}//���Ϲ� ��
}//���ι� ��

//���浹 �ܹ鵹