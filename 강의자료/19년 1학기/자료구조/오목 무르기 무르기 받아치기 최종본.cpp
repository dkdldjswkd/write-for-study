#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

//┌ ┐ ┘ └ ├ ┬ ┤ ┴ ┼
// 보드는 19 X 19

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

	bord[0][0] = "┌";
	bord[0][18] = "┐";
	bord[18][0] = "└";
	bord[18][18] = "┘"; // 바둑판 모서리 무늬 대입

	for (int i = 1; i < 18; i++) {
		bord[0][i] = "┬";
	}
	for (int i = 1; i < 18; i++) {
		bord[i][18] = "┤";
	}
	for (int i = 1; i < 18; i++) {
		bord[18][i] = "┴";
	}
	for (int i = 1; i < 18; i++) {
		bord[i][0] = "├";
	} // 바둑판 가장자리 무늬 대입

	for (int i = 1; i < 18; i++) { // 바둑판 중앙부 십자무늬 대입
		for (int j = 1; j < 18; j++) {
			bord[i][j] = "┼";
		}
	}

	for (int i = 0; i < 19; i++) { // 바둑판 출력
		for (int j = 0; j < 19; j++) {
			cout << bord[i][j] << " ";
		}
		cout << endl;
	}

	ifstream fin("test.txt");
	int black = 0, white = 0; // 흑돌과 백돌의 총 갯수
	bool who = true; // 참일땐 흑돌 거짓일땐 백돌
	bool first = true;
	int Bcount = 0, Wcount = 0; // 흑돌과 백돌의 일부 갯수
	int manyWB = 1, manyWW = 1, manyHB = 1, manyHW = 1;
	int diaB = 1, diaW = 1, diaB2 = 1, diaW2 = 1;
	bool conCheck = false;
	int x, y; // x, y의 좌표
	int turn = 1; //홀수라면 흑돌차례 짝수라면 백돌차례
	int mmn = 0;

	while (1) { // 게임 와일문
	//	int nResult = remove("test.txt");
		cout << endl;
		cout << turn << "번째 턴 입니다." << endl;
		cout << "흑돌의 갯수 : " << black << endl;
		cout << "흰돌의 갯수 : " << white << endl;
		cout << "U : 무르기 R : 무르기 취소 S : 저장 후 종료 L : 불러오기 (다른키 누를시 계속진행) : ";
		char replay; cin >> replay;

		if (turn == 1 && replay == 'U') {
			cout << "1턴에는 무르기가 불가능 합니다." << endl;
		}
		else if (replay == 'U') {
			mmn++; //무르기 받아치기의 스택갯수를 증가시킴
			p = tail;
			rerep = new rere[sizeof(rere)];
			rere_push();
			if (p->x == 0 && p->y == 0) {
				bord[p->x][p->y] = "┌";
			}
			else if (p->x == 0 && p->y == 18) {
				bord[p->x][p->y] = "┐";
			}
			else if (p->x == 18 && p->y == 0) {
				bord[p->x][p->y] = "└";
			}
			else if (p->x == 18 && p->y == 18) {
				bord[p->x][p->y] = "┘";
			}
			else if (p->x == 0) {
				bord[p->x][p->y] = "┬";
			}
			else if (p->x == 18) {
				bord[p->x][p->y] = "┴";
			}
			else if (p->y == 0) {
				bord[p->x][p->y] = "├";
			}
			else if (p->y == 18) {
				bord[p->x][p->y] = "┤";
			}
			else {
				bord[p->x][p->y] = "┼";
			}

			re_del();
			turn--;

			system("cls");

			for (int i = 0; i < 19; i++) { // 바둑판 출력
				for (int j = 0; j < 19; j++) {
					cout << bord[i][j];
					if (!(bord[i][j] == "○" || bord[i][j] == "●")) cout << " ";
				}
				cout << endl;
			}
			cout << endl;
			continue;
		}
		else if (replay == 'R' && rerep == NULL) {
			cout << "무르기 취소 할 값이 없습니다." << endl;
		}
		else if (replay == 'R') {

			if (rerep->who == true) {
				bord[rerep->x][rerep->y] = "○";
			}
			else if (rerep->who == false) {
				bord[rerep->x][rerep->y] = "●";
			}

			turn++;
			p = new re[sizeof(re)];
			re_push(rerep->x, rerep->y, turn);

			rere_del();
			system("cls");

			for (int i = 0; i < 19; i++) { // 바둑판 출력
				for (int j = 0; j < 19; j++) {
					cout << bord[i][j];
					if (!(bord[i][j] == "○" || bord[i][j] == "●")) cout << " ";
				}
				cout << endl;
			}
			cout << endl;
			continue;
		}
		else if (replay == 'S') {
			ofstream fout("test.txt");
			save(fout, bord, turn, black, white, mmn);
			cout << "저장되었습니다." << endl;
			return 0;
		}
		else if (replay == 'L') {
			Load(fin, bord, turn, black, white, mmn);
			system("cls");
			cout << "저장된 파일로 게임을 시작합니다." << endl;
			for (int i = 0; i < 19; i++) { // 바둑판 출력
				for (int j = 0; j < 19; j++) {
					cout << bord[i][j];
					if (!(bord[i][j] == "○" || bord[i][j] == "●")) cout << " ";
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
			cout << "흑돌은 놓을 자리를 입력하세요  : ";
			rere_alldel();
		}
		else {
			cout << "백돌은 놓을 자리를 입력하세요 : ";
			rere_alldel();
		}

		rewind(stdin); // 입력버퍼 비우기
		cin >> x >> y; // 좌표를 입력받음

		if (x > 19 || y > 19 || x < 1 || y < 1) {
			cout << "숫자를 확인하고 다시 입력해주세요" << endl;
			continue;
		}
		else if (bord[x - 1][y - 1] == "○" || bord[x - 1][y - 1] == "●") {
			cout << "이미 놓은 칸입니다 다시 입력해주세요" << endl;
			continue;
		}
		else {
			if (turn % 2 == 1) {
				bord[x - 1][y - 1] = "○"; // 그 좌표에 흑돌 대입
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
				bord[x - 1][y - 1] = "●"; // 그 좌표에 흑돌 대입
				white++;
				who = true;
				p = new re[sizeof(re)];
				re_push(x - 1, y - 1, turn);
				turn++;
			}
		}

		system("cls");
		for (int i = 0; i < 19; i++) { // 바둑판 출력
			for (int j = 0; j < 19; j++) {
				cout << bord[i][j];
				if (!(bord[i][j] == "○" || bord[i][j] == "●")) cout << " ";
			}
			cout << endl;
		}
		cout << endl;

	}//와일문 끝
}//메인문 끝

//○흑돌 ●백돌