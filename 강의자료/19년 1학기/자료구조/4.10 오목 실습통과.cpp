#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//┌ ┐ ┘ └ ├ ┬ ┤ ┴ ┼
// 보드는 19 X 19

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

	int black = 0;
	int white = 0;
	int x, y;
	bool who = true;

	int WB = 0, WW = 0, HB = 0, HW = 0;
	int manyWB = 1, manyWW = 1, manyHB = 1, manyHW = 1;
	int diaB = 1, diaW = 1, diaB2 = 1, diaW2 = 1;
	bool conCheck = false;

	while (1) { // 게임 와일문
		cout << endl;
		cout << "흑돌의 갯수 : " << black << endl;
		cout << "흰돌의 갯수 : " << white << endl;

		if (who) {
			cout << "흑돌은 놓을 자리를 입력하세요 : ";
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
			if (who) {
				bord[x - 1][y - 1] = "○"; // 그 좌표에 흑돌 대입
				black++;
				who = false;
			}
			else {
				bord[x - 1][y - 1] = "●"; // 그 좌표에 흑돌 대입
				white++;
				who = true;
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

		for (int i = 0; i < 19; i++) {//돌 행 숫자세기
			for (int j = 0; j < 19; j++) {
				if (bord[i][j] == "○") {
					HB++;
				}
				else if (bord[i][j] == "●") {
					HW++;
				}
			}
			if (HW > 0 || HB > 0) {
				cout << i + 1 << "행의 검은돌의 갯수는 " << HB << "개"
					<< " 흰돌의 갯수는 " << HW << "개" << endl;
			}
			HB = 0, HW = 0;
		}

		for (int i = 0; i < 19; i++) {//돌 열 숫자세기
			for (int j = 0; j < 19; j++) {
				if (bord[j][i] == "○") {
					WB++;
				}
				else if (bord[j][i] == "●") {
					WW++;
				}
			}
			if (WB > 0 || WW > 0) {//행에 흰돌과 검은돌이 0개가 아니라면 몇번째 열에 돌이 몇개 있는지 알려줌
				cout << i + 1 << "열의 검은돌의 갯수는 " << WB << "개"
					<< " 흰돌의 갯수는 " << WW << "개" << endl;
			}
			WB = 0, WW = 0;
		}

		int max = 0;
		int x = 0, y = 0, tmp = 0;
		for (int i = 0; i < 19; i++) { // 행에 검은돌이 연속인가
			for (int j = 0; j < 19; j++) {
				if (j > 0) {
					if ((bord[i][j] == "○") && (bord[i][j - 1] == "○")) {
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
				cout << i + 1 << "행의 이어진 흑돌의 갯수는 " << max << endl;
			}
			max = 0;
		}
		//	if (tmp > 1) {
			//	cout << "행중 가장 길게 이어진 검은돌의 좌표는 (" << x << ", " << y - (tmp - 1) << ")" << " 부터" << "(" << x << ", " << y << ")" << endl;
		//	}

		max = 0;
		for (int i = 0; i < 19; i++) { // 열에 검은돌이 연속인가
			for (int j = 0; j < 19; j++) {
				if (j > 0) {
					if ((bord[j][i] == "○") && (bord[j - 1][i] == "○")) {
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
				cout << i + 1 << "열의 이어진 흑돌의 갯수는 " << max << endl;
			}
			max = 0;
		}

		max = 0;
		int x2 = 0, y2 = 0, tmp2 = 0;
		for (int i = 0; i < 19; i++) { // 행에 흰돌이 연속인가
			for (int j = 0; j < 19; j++) {
				if (j > 0) {
					if ((bord[i][j] == "●") && (bord[i][j - 1] == "●")) {
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
				cout << i + 1 << "행의 이어진 흰돌의 갯수는 " << max << endl;
			}
			max = 0;
		}

		if (tmp >= tmp2 && tmp > 1) {
			cout << "행중 가장 길게 이어진 돌은 검은돌로 좌표는 (" << x << ", " << y - (tmp - 1) << ")" << " 부터" << "(" << x << ", " << y << ")" << endl;
		}
		else if (tmp <= tmp2 && tmp2 > 1) {
			cout << "행중 가장 길게 이어진 돌은 흰돌로 좌표는 (" << x2 << ", " << y2 - (tmp2 - 1) << ")" << " 부터" << "(" << x2 << ", " << y2 << ")" << endl;
		}

		max = 0;
		for (int i = 0; i < 19; i++) { // 열에 흰돌이 연속인가
			for (int j = 0; j < 19; j++) {
				if (j > 0) {
					if ((bord[j][i] == "●") && (bord[j - 1][i] == "●")) {
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
				cout << i + 1 << "열의 이어진 흰돌의 갯수는 " << max << endl;
			}
			max = 0;
		}

		int a = 0, b = 0;
		for (int i = 0; i < 19; i++) { // 왼쪽 위 대각선 흑돌
			a = i; b = 0;
			for (; a > 0; a--, b++) {
				if (a > 0) {
					if (bord[a][b] == "○" && bord[a - 1][b + 1] == "○") {
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
				cout << "왼쪽 위부터 " << i + 1 << "번째 대각선의 이어진 흑돌의 갯수는 " << max << endl;
			}
			max = 0;
		}

		for (int i = 18; i >= 1; i--) { // 오른쪽 아래 대각선 흑돌
			a = 18; b = i;
			for (; b < 18; a--, b++) {
				if (a > 0) {
					if (bord[a][b] == "○" && bord[a - 1][b + 1] == "○") {
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
				cout << "왼쪽 위부터 " << i + 19 << "번째 대각선의 이어진 흑돌의 갯수는 " << max << endl;
			}
			max = 0;
		}

		for (int i = 0; i < 19; i++) { // 왼쪽위 대각선 흰돌
			a = i; b = 0;
			for (; a > 0; a--, b++) {
				if (a > 0) {
					if (bord[a][b] == "●" && bord[a - 1][b + 1] == "●") {
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
				cout << "왼쪽 위부터 " << i + 1 << "번째 대각선의 이어진 흰돌의 갯수는 " << max << endl;
			}
			max = 0;
		}

		max = 0, a = 18, b = 18;
		for (int i = 18; i >= 1; i--) { // 오른쪽 아래 대각선 흰돌
			a = 18; b = i;
			for (; b < 18; a--, b++) {
				if (a > 0) {
					if (bord[a][b] == "●" && bord[a - 1][b + 1] == "●") {
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
				cout << "왼쪽 위부터 " << i + 19 << "번째 대각선의 이어진 백돌의 갯수는 " << max << endl;
			}
			max = 0;
		}

		max = 0;
		for (int i = 18; i >= 0; i--) { //오른쪽 위 대각선 흑돌
			a = 0; b = i;
			for (; b < 18; a++, b++) {
				if (b < 18) {
					if (bord[a][b] == "○" && bord[a + 1][b + 1] == "○") {
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
				cout << "오른쪽 위부터 " << -(i - 19) << "번째 대각선의 이어진 흑돌의 갯수는 " << max << endl;
			}
			max = 0;
		}

		for (int i = 18; i >= 1; i--) { // 왼쪽 아래 대각선 흑돌
			a = i, b = 0;
			for (; a < 18; a++, b++) {
				if (a < 18) {
					if (bord[a][b] == "○" && bord[a + 1][b + 1] == "○") {
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
				cout << "오른쪽 위부터 " << i + 19 << "번째 대각선의 이어진 흑돌의 갯수는 " << max << endl;
			}
			max = 0;
		}

		for (int i = 18; i >= 0; i--) { // 오른쪽 위 대각선 흰돌
			a = 0; b = i;
			for (; b < 18; a++, b++) {
				if (b < 18) {
					if (bord[a][b] == "●" && bord[a + 1][b + 1] == "●") {
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
				cout << "오른쪽 위부터 " << -(i - 19) << "번째 대각선의 이어진 백돌의 갯수는 " << max << endl;
			}
			max = 0;
		}

		for (int i = 18; i >= 1; i--) { // 왼쪽 아래 대각선 흰돌
			a = i, b = 0;
			for (; a < 18; a++, b++) {
				if (a < 19) {
					if (bord[a][b] == "●" && bord[a + 1][b + 1] == "●") {
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
				cout << "오른쪽 위부터 " << i + 19 << "번째 대각선의 이어진 흰돌의 갯수는 " << max << endl;
			}
			max = 0;
		}


	}//와일문 끝
}//메인문 끝

//○흑돌 ●백돌