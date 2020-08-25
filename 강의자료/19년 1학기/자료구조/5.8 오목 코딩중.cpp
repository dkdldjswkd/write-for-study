#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//┌ ┐ ┘ └ ├ ┬ ┤ ┴ ┼
// 보드는 19 X 19
void printbord(string bord[19][19]) {// 바둑판 출력
	system("cls");
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cout << bord[i][j];
			if (!(bord[i][j] == "○" || bord[i][j] == "●" || bord[i][j] == "☆")) cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void bordclear(string bord[19][19]) {

	if (bord[0][0] != "○" && bord[0][0] != "●")
	bord[0][0] = "┌";
	if (bord[0][18] != "○" && bord[0][18] != "●")
	bord[0][18] = "┐";
	if (bord[18][0] != "○" && bord[18][0] != "●")
	bord[18][0] = "└";
	if (bord[18][18] != "○" && bord[18][18] != "●")
	bord[18][18] = "┘";

	for (int i = 1; i < 18; i++) {
		if (bord[0][i] != "○" && bord[0][i] != "●")
			bord[0][i] = "┬";
	}
	for (int i = 1; i < 18; i++) {
		if (bord[i][18] != "○" && bord[i][18] != "●")
			bord[i][18] = "┤";
	}
	for (int i = 1; i < 18; i++) {
		if (bord[18][i] != "○" && bord[18][i] != "●")
			bord[18][i] = "┴";
	}
	for (int i = 1; i < 18; i++) {
		if (bord[i][0] != "○" && bord[i][0] != "●")
			bord[i][0] = "├";
	}

	for (int i = 1; i < 18; i++) { // 바둑판 중앙부 십자무늬 대입
		for (int j = 1; j < 18; j++) {
			if (bord[i][j] != "○" && bord[i][j] != "●")
				bord[i][j] = "┼";
		}
	}
}

void diag(string bord[19][19]) { // 우상좌하 대각선
	int count = 0;
	int max = 0;
	int concount = 0;
	int Bcount = 0;
	for (int i = 0; i < 19; i = count) {
		for (int j = 0; i >= 0; i--, j++) {
			if (bord[i][j] == "○") {
				concount = 0;
				Bcount++;
			}
			else if (bord[i][j] != "●") {
				concount++;
			}
			else if (bord[i][j] == "●") {
				concount = 2;
			}
			if (concount >= 2) {
				Bcount = 0;
			}
			if (max <= Bcount) {
				max = Bcount;
			}
		}
		if (max > 1)cout << "우상좌하 대각선 " << count + 1 << "번째줄의 가장긴 흑돌 수는 " << max << "개" << endl;
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
			if (bord[i][j] == "○") {
				concount = 0;
				Bcount++;
			}
			else if (bord[i][j] != "●") {
				concount++;
			}
			else if (bord[i][j] == "●") {
				concount = 2;
			}
			if (concount >= 2) {
				Bcount = 0;
			}
			if (max <= Bcount) {
				max = Bcount;
			}
		}
		if (max > 1)cout << "우상좌하 대각선 " << count + 19 << "번째줄의 가장긴 흑돌 수는 " << max << "개" << endl;
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
			if (bord[i][j] == "●") {
				concount = 0;
				Bcount++;
			}
			else if (bord[i][j] != "○") {
				concount++;
			}
			else if (bord[i][j] == "○") {
				concount = 2;
			}
			if (concount >= 2) {
				Bcount = 0;
			}
			if (max <= Bcount) {
				max = Bcount;
			}
		}
		if (max > 1)cout << "우상좌하 대각선 " << count + 1 << "번째줄의 가장긴 흰돌 수는 " << max << "개" << endl;
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
			if (bord[i][j] == "●") {
				concount = 0;
				Bcount++;
			}
			else if (bord[i][j] != "○") {
				concount++;
			}
			else if (bord[i][j] == "○") {
				concount = 2;
			}
			if (concount >= 2) {
				Bcount = 0;
			}
			if (max <= Bcount) {
				max = Bcount;
			}
		}
		if (max > 1)cout << "우상좌하 대각선 " << count + 19 << "번째줄의 가장긴 흰돌 수는 " << max << "개" << endl;
		count++;
		max = 0;
		Bcount = 0;
	}
}

void diag2(string bord[19][19]) { // 좌상우하 대각선
	int count = 0;
	int max = 0;
	int concount = 0;
	int Bcount = 0;
	for (int i = 0; i < 19; i = count) {
		for (int j = 18; i >= 0; i--, j--) {
			if (bord[i][j] == "○") {
				concount = 0;
				Bcount++;
			}
			else if (bord[i][j] != "●") {
				concount++;
			}
			else if (bord[i][j] == "●") {
				concount = 2;
			}
			if (concount >= 2) {
				Bcount = 0;
			}
			if (max <= Bcount) {
				max = Bcount;
			}
		}
		if (max > 1)cout << "좌상우하 대각선 " << count + 1 << "번째줄의 가장긴 흑돌 수는 " << max << "개" << endl;
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
			if (bord[i][j] == "○") {
				concount = 0;
				Bcount++;
			}
			else if (bord[i][j] != "●") {
				concount++;
			}
			else if (bord[i][j] == "●") {
				concount = 2;
			}
			if (concount >= 2) {
				Bcount = 0;
			}
			if (max <= Bcount) {
				max = Bcount;
			}
		}
		if (max > 1)cout << "좌상우하 대각선 " << 37 - count << "번째줄의 가장긴 흑돌 수는 " << max << "개" << endl;
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
			if (bord[i][j] == "●") {
				concount = 0;
				Bcount++;
			}
			else if (bord[i][j] != "○") {
				concount++;
			}
			else if (bord[i][j] == "○") {
				concount = 2;
			}
			if (concount >= 2) {
				Bcount = 0;
			}
			if (max <= Bcount) {
				max = Bcount;
			}
		}
		if (max > 1)cout << "좌상우하 대각선 " << count + 1 << "번째줄의 가장긴 흰돌 수는 " << max << "개" << endl;
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
			if (bord[i][j] == "●") {
				concount = 0;
				Bcount++;
			}
			else if (bord[i][j] != "○") {
				concount++;
			}
			else if (bord[i][j] == "○") {
				concount = 2;
			}
			if (concount >= 2) {
				Bcount = 0;
			}
			if (max <= Bcount) {
				max = Bcount;
			}
		}
		if (max > 1)cout << "좌상우하 대각선 " << 37 - count << "번째줄의 가장긴 흰돌 수는 " << max << "개" << endl;
		count--;
		max = 0;
		Bcount = 0;
	}
}

int main() {
	string bord[19][19];
	bordclear(bord);
	printbord(bord);

	int black = 0, white = 0; // 흑돌과 백돌의 총 갯수
	bool who = true; // 참일땐 흑돌 거짓일땐 백돌
	bool first = true;
	int Bcount = 0, Wcount = 0; // 흑돌과 백돌의 일부 갯수
	int manyWB = 0, manyWW = 1, manyHB = 1, manyHW = 1;
	int diaB = 1, diaW = 1, diaB2 = 1, diaW2 = 1;
	bool conCheck = false;
	int x, y; // x, y의 좌표
	int turn = 1; //홀수라면 흑돌차례 짝수라면 백돌차례
	int mmn = 0;

	while (1) { // 게임 와일문
		cout << endl;
		cout << turn << "번째 턴 입니다." << endl;
		cout << "흑돌의 갯수 : " << black << endl;
		cout << "흰돌의 갯수 : " << white << endl;

		if (turn % 2 == 1) {
			cout << "흑돌은 놓을 자리를 입력하세요  : ";
		}
		else {
			cout << "백돌은 놓을 자리를 입력하세요 : ";
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
				turn++;
			}
			else {
				bord[x - 1][y - 1] = "●"; // 그 좌표에 흑돌 대입
				white++;
				who = true;
				turn++;
			}
		}

		printbord(bord);


		int max = 0;
		x = 0, y = 0;
		int tmp = 0;
		int concount = 0; // 인접한곳에 돌이있으면 0 한칸 떨어져있으면 1 두칸떨어지면 2
		Bcount = 0;
		for (int i = 0; i < 19; i++) { // 행에 검은돌이 연속인가
			for (int j = 0; j < 19; j++) {
				if (bord[i][j] == "○") {
					concount = 0;
					Bcount++;
				}
				else if (bord[i][j] != "●") {
					concount++;
				}
				else if (bord[i][j] == "●") {
					concount = 2;
				}
				if (concount >= 2) {
					Bcount = 0;
				}
				if (max <= Bcount) {
					max = Bcount;
				}
			//	cout << Bcount << endl; //이따 지우기
				bool gap = false;
				if (Bcount == 3 && concount == 0 && bord[i][j - 3] != "○") { //연속적인 돌임
					gap = false;
				}
				else if (Bcount == 3 && concount == 0 && bord[i][j - 3] == "○") { //한칸 떨어져서 연속인 돌임
					gap = true;
				}
				if (Bcount == 4 && concount == 0 && bord[i][j - 4] != "○") { //연속적인 돌임
					gap = false;
				}
				else if (Bcount == 4 && concount == 0 && bord[i][j - 4] == "○") { //한칸 떨어져서 연속인 돌임
					gap = true;
				}
				
				if (Bcount == 3 && concount == 0 && bord[i][j + 1] != "○") { //세개가 연속된 돌일경우
					if ((gap == false && j - 3 >= 0) && (gap == false && bord[i][j - 3] != "●") || (gap == true && j - 4 >= 0) && (gap == true && bord[i][j - 4] != "●")) { //이어진 돌의 왼쪽 벽이 막혔는지 판단
						if (j + 1 < 18 && bord[i][j + 1] != "●") { // 이어진 돌의 오른쪽 벽이 막혔는지 판단 둘다 막힌곳이 없으면 아래 실행
							int count = 0;
							for (int a = 0;;) {
								if (bord[i][j + 1 - count] != "●" && bord[i][j + 1 - count] != "○") {
									if (bord[i][j + 2 - count] == "○" && bord[i][j - count] == "○") gap = true; // 별이 놔진곳 양옆으로 돌이있으면 gap는 ture
									bord[i][j + 1 - count] = "☆";
									if (a >= Bcount)break;
								}
								else if (bord[i][j + 1 - count] == "○") {
									a++;
								}
								count++;
							}
						}
					}
				}

				if (Bcount == 4 && concount == 0 && bord[i][j + 1] != "○") { //네개가 연속된 돌일경우
					if ((gap == false && j - 3 == 0) || (gap == false && bord[i][j - 4] == "●")) { // 네개의 돌이 붙은돌이고 왼쪽이 막힌경우

					}
					else if ((gap == false && j == 18) || (gap == false && bord[i][j + 1] == "●")) { // 네개의 돌이 붙은돌이고 오른쪽이 막힌경우

					}
					else if ((gap = true && j + 1 <= 18) || (gap == true && j - 4)) {
					}
				}

			}
			if (max > 1)cout << i + 1 << "행의 이어진 가장긴 흑돌 수는 " << max << "개" << endl;
			max = 0;
			Bcount = 0;
		}

		max = 0;
		concount = 0;
		Bcount = 0;
		for (int j = 0; j < 19; j++) { // 열에 검은돌이 연속인가
			for (int i = 0; i < 19; i++) {
				if (bord[i][j] == "○") {
					concount = 0;
					Bcount++;
				}
				else if (bord[i][j] != "●") {
					concount++;
				}
				else if (bord[i][j] == "●") {
					concount = 2;
				}
				if (concount >= 2) {
					Bcount = 0;
				}
				if (max <= Bcount) {
					max = Bcount;
				}
			}
			if (max > 1)cout << j + 1 << "열의 이어진 가장긴 흑돌 수는 " << max << "개" << endl;
			max = 0;
			Bcount = 0;
		}


		max = 0;
		concount = 0;
		Wcount = 0;
		for (int i = 0; i < 19; i++) { // 행에 흰돌이 연속인가
			for (int j = 0; j < 19; j++) {
				if (bord[i][j] == "●") {
					concount = 0;
					Wcount++;
				}
				else if (bord[i][j] != "○") {
					concount++;
				}
				else if (bord[i][j] == "○") {
					concount = 2;
				}
				if (concount >= 2) {
					Wcount = 0;
				}
				if (max <= Wcount) {
					max = Wcount;
				}
			}
			if (max > 1)cout << i + 1 << "행의 이어진 가장긴 흰돌 수는 " << max << "개" << endl;
			max = 0;
			Wcount = 0;
		}

		max = 0;
		concount = 0;
		Wcount = 0;
		for (int j = 0; j < 19; j++) { // 열에 흰돌이 연속인가
			for (int i = 0; i < 19; i++) {
				if (bord[i][j] == "●") {
					concount = 0;
					Wcount++;
				}
				else if (bord[i][j] != "○") {
					concount++;
				}
				else if (bord[i][j] == "○") {
					concount = 2;
				}
				if (concount >= 2) {
					Wcount = 0;
				}
				if (max <= Wcount) {
					max = Wcount;
				}
			}
			if (max > 1)cout << j + 1 << "열의 이어진 가장긴 흰돌 수는 " << max << "개" << endl;
			max = 0;
			Wcount = 0;
		}

		diag(bord);
		diag2(bord);


		printbord(bord);
		bordclear(bord);

	}//와일문 끝
}//메인문 끝

//○흑돌 ●백돌