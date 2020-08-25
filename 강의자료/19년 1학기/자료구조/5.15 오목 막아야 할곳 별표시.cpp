#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//┌ ┐ ┘ └ ├ ┬ ┤ ┴ ┼
// 보드는 19 X 19
void printbord(string bord[19][19]) {// 바둑판 출력
//   system("cls");
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
	int x=0, y=0;
	int gap_n = 0;
	int count = 0;
	int max = 0;
	int concount = 0;
	int Bcount = 0;
	for (int i = 0; i < 19; i = count) {//왼쪽위 보드판 흑돌체크
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
			if (max <= Bcount && concount == 0) {
				max = Bcount;
				x = i + 1;
				y = j + 1;
				gap_n = 0;
				for (int a = 0, b = 0;;) {
					if (bord[i + a][j - a] != "○")gap_n++;
					else if (bord[i + a][j - a] == "○")b++;
					if (b == Bcount)break;
					a++;
				}
			}
		}
		if (max > 1)cout << "우상좌하 대각선 " << count + 1 << "번째줄의 가장긴 흑돌 수는 " << max << "개"
			<< "좌표는 " << "(" << x + (max - 1) + gap_n << ", " << y - (max - 1) - gap_n << ") 부터 " << "(" << x << ", " << y << ")" << endl;
		count++;

		x--; y--;//x,y 에 원래의 좌표값을 다시 넣음

		if (max == 3 && gap_n == 0) { // 연속적으로 이어진 세개의 돌
			if (y - (max - 1) - gap_n >=1 && x>=1) { // 가장자리가 아닌 가운데라면
				if (bord[x + (max - 1) + gap_n+1][y - (max - 1) - gap_n-1] != "●" && bord[x-1][y+1] != "●") {//양옆 모두 다른돌이 막고있지 않다면
					bord[x - 1][y + 1] = "☆";
					bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "☆";
				}
			}
		}
		if (max == 3 && gap_n == 1) { // 세개의 돌 사이 빈칸이 하나 있다면
			if (y - (max - 1) - gap_n >= 1 && x >= 1) { // 가장자리가 아니라면
				if (bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "●" && bord[x - 1][y + 1] != "●") {//양옆 모두 다른돌이 막고있지 않다면
					for (int a = x, b = y;; a++, b--) {
						if (bord[a][b] != "○") {//해당 칸이 빈칸이라면 별표를 대입
							bord[a][b] = "☆";
							break;
						}
					}
				}
			}
		}
		if (max == 4 && gap_n == 1) { // 네개의 돌 사이 빈칸이 하나 있다면
			for (int a = x, b = y;; a++, b--) {
				if (bord[a][b] != "○") {//해당 칸이 빈칸이라면 별표를 대입
					bord[a][b] = "☆";
					break;
				}
			}
		}
		if (max == 4 && gap_n == 0) { // 네개의 돌이 연속적으로 놓였다면
			if (y - (max - 1) - gap_n ==0) {//돌이 가장왼쪽아래에 놓여있다면 연속된 돌의 오른쪽위에 별대입
				bord[x-1][y+1] = "☆";
			}
			else if (x==0) {//돌이 오른쪽가장위에 놓여있다면 돌의 왼쪽 아래에 별 대입
				bord[x + (max - 1) + gap_n+1][y - (max - 1) - gap_n-1] = "☆";
			}
		}

		if (max >= 5) { // 다섯개 돌 이상이 연속이든 빈칸이 있든
			if (y - (max - 1) - gap_n >0 && bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n-1] != "●") {//이어진돌의 왼쪽아래칸이 벽이 아니고 백돌로 막히지 않앗다면
				bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "☆";//이어진 돌의 왼쪽아래칸에 별표대입
			}
			if (x > 0 && bord[x-1][y + 1] != "●") {//이어진 돌의 오른쪽위칸이 벽이아니고 백돌로 막히지 않았다면
				bord[x-1][y + 1] = "☆";//이어진 돌의 오른쪽 칸에 별표대입
			}
			for (int a = x, b = y;; a++, b--) {
				if (bord[a][b] != "○") {//해당 칸이 빈칸이라면 별표를 대입
					bord[a][b] = "☆";
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
	for (int i = 18; count <= 18; i = 18) { // 오른쪽 아래 보드판 흑돌체크
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
			if (max <= Bcount && concount == 0) {
				max = Bcount;
				x = i + 1;
				y = j + 1;
				gap_n = 0;
				for (int a = 0, b = 0;;) {
					if (bord[i + a][j - a] != "○")gap_n++;
					else if (bord[i + a][j - a] == "○")b++;
					if (b == Bcount)break;
					a++;
				}
			}
		}
		if (max > 1)cout << "우상좌하 대각선 " << count + 19 << "번째줄의 가장긴 흑돌 수는 " << max << "개"
			<< "좌표는 " << "(" << x + (max - 1) + gap_n << ", " << y - (max - 1) - gap_n << ") 부터 " << "(" << x << ", " << y << ")" << endl;
		count++;

		x--; y--;//x,y 에 원래의 좌표값을 다시 넣음

		if (max == 3 && gap_n == 0) { // 연속적으로 이어진 세개의 돌
			if (x + (max - 1) + gap_n <18 && y < 18) { // 가장자리가 아닌 가운데라면
				if (bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "●" && bord[x - 1][y + 1] != "●") {//양옆 모두 다른돌이 막고있지 않다면
					bord[x - 1][y + 1] = "☆";
					bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "☆";
				}
			}
		}
		if (max == 3 && gap_n == 1) { // 세개의 돌 사이 빈칸이 하나 있다면
			if (x + (max - 1) + gap_n < 18 && y < 18) { // 가장자리가 아니라면
				if (bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "●" && bord[x - 1][y + 1] != "●") {//양옆 모두 다른돌이 막고있지 않다면
					for (int a = x, b = y;; a++, b--) {
						if (bord[a][b] != "○") {//해당 칸이 빈칸이라면 별표를 대입
							bord[a][b] = "☆";
							break;
						}
					}
				}
			}
		}
		if (max == 4 && gap_n == 1) { // 네개의 돌 사이 빈칸이 하나 있다면
			for (int a = x, b = y;; a++, b--) {
				if (bord[a][b] != "○") {//해당 칸이 빈칸이라면 별표를 대입
					bord[a][b] = "☆";
					break;
				}
			}
		}
		if (max == 4 && gap_n == 0) { // 네개의 돌이 연속적으로 놓였다면
			if (x + (max - 1) + gap_n == 18) {//돌이 가장왼쪽아래에 놓여있다면 연속된 돌의 오른쪽위에 별대입
				bord[x - 1][y + 1] = "☆";
			}
			else if (y == 18) {//돌이 오른쪽가장위에 놓여있다면 돌의 왼쪽 아래에 별 대입
				bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "☆";
			}
		}

		if (max >= 5) { // 다섯개 돌 이상이 연속이든 빈칸이 있든
			if (x + (max - 1) + gap_n < 18 && bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "●") {//이어진돌의 왼쪽아래칸이 벽이 아니고 백돌로 막히지 않앗다면
				bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "☆";//이어진 돌의 왼쪽아래칸에 별표대입
			}
			if (y <18 && bord[x - 1][y + 1] != "●") {//이어진 돌의 오른쪽칸이 벽이아니고 백돌로 막히지 않았다면
				bord[x - 1][y + 1] = "☆";//이어진 돌의 오른쪽 칸에 별표대입
			}
			for (int a = x, b = y;; a++, b--) {
				if (bord[a][b] != "○") {//해당 칸이 빈칸이라면 별표를 대입
					bord[a][b] = "☆";
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
	for (int i = 0; i < 19; i = count) {//왼쪽위 보드 흰돌
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
			if (max <= Bcount && concount == 0) {
				max = Bcount;
				x = i + 1;
				y = j + 1;
				gap_n = 0;
				for (int a = 0, b = 0;;) {
					if (bord[i + a][j - a] != "●")gap_n++;
					else if (bord[i + a][j - a] == "●")b++;
					if (b == Bcount)break;
					a++;
				}
			}
		}
		if (max > 1)cout << "우상좌하 대각선 " << count + 1 << "번째줄의 가장긴 흰돌 수는 " << max << "개"
			<< "좌표는 " << "(" << x + (max - 1) + gap_n << ", " << y - (max - 1) - gap_n << ") 부터 " << "(" << x << ", " << y << ")" << endl;
		count++;
		x--; y--;//x,y 에 원래의 좌표값을 다시 넣음

		if (max == 3 && gap_n == 0) { // 연속적으로 이어진 세개의 돌
			if (y - (max - 1) - gap_n >= 1 && x >= 1) { // 가장자리가 아닌 가운데라면
				if (bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "○" && bord[x - 1][y + 1] != "○") {//양옆 모두 다른돌이 막고있지 않다면
					bord[x - 1][y + 1] = "☆";
					bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "☆";
				}
			}
		}
		if (max == 3 && gap_n == 1) { // 세개의 돌 사이 빈칸이 하나 있다면
			if (y - (max - 1) - gap_n >= 1 && x >= 1) { // 가장자리가 아니라면
				if (bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "○" && bord[x - 1][y + 1] != "○") {//양옆 모두 다른돌이 막고있지 않다면
					for (int a = x, b = y;; a++, b--) {
						if (bord[a][b] != "●") {//해당 칸이 빈칸이라면 별표를 대입
							bord[a][b] = "☆";
							break;
						}
					}
				}
			}
		}
		if (max == 4 && gap_n == 1) { // 네개의 돌 사이 빈칸이 하나 있다면
			for (int a = x, b = y;; a++, b--) {
				if (bord[a][b] != "●") {//해당 칸이 빈칸이라면 별표를 대입
					bord[a][b] = "☆";
					break;
				}
			}
		}
		if (max == 4 && gap_n == 0) { // 네개의 돌이 연속적으로 놓였다면
			if (y - (max - 1) - gap_n == 0) {//돌이 가장왼쪽아래에 놓여있다면 연속된 돌의 오른쪽위에 별대입
				bord[x - 1][y + 1] = "☆";
			}
			else if (x == 0) {//돌이 오른쪽가장위에 놓여있다면 돌의 왼쪽 아래에 별 대입
				bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "☆";
			}
		}

		if (max >= 5) { // 다섯개 돌 이상이 연속이든 빈칸이 있든
			if (y - (max - 1) - gap_n > 0 && bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "○") {//이어진돌의 왼쪽아래칸이 벽이 아니고 흑돌로 막히지 않앗다면
				bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "☆";//이어진 돌의 왼쪽아래칸에 별표대입
			}
			if (x > 0 && bord[x - 1][y + 1] != "○") {//이어진 돌의 오른쪽위칸이 벽이아니고 흑돌로 막히지 않았다면
				bord[x - 1][y + 1] = "☆";//이어진 돌의 오른쪽 칸에 별표대입
			}
			for (int a = x, b = y;; a++, b--) {
				if (bord[a][b] != "●") {//해당 칸이 빈칸이라면 별표를 대입
					bord[a][b] = "☆";
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
	for (int i = 18; count <= 18; i = 18) {//오른쪽아래 보드 백돌
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
			if (max <= Bcount && concount == 0) {
				max = Bcount;
				x = i + 1;
				y = j + 1;
				gap_n = 0;
				for (int a = 0, b = 0;;) {
					if (bord[i + a][j - a] != "●")gap_n++;
					else if (bord[i + a][j - a] == "●")b++;
					if (b == Bcount)break;
					a++;
				}
			}
		}
		if (max > 1)cout << "우상좌하 대각선 " << count + 19 << "번째줄의 가장긴 흰돌 수는 " << max << "개"
			<< "좌표는 " << "(" << x + (max - 1) + gap_n << ", " << y - (max - 1) - gap_n << ") 부터 " << "(" << x << ", " << y << ")" << endl;
		count++;
		x--; y--;//x,y 에 원래의 좌표값을 다시 넣음

		if (max == 3 && gap_n == 0) { // 연속적으로 이어진 세개의 돌
			if (x + (max - 1) + gap_n < 18 && y < 18) { // 가장자리가 아닌 가운데라면
				if (bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "○" && bord[x - 1][y + 1] != "○") {//양옆 모두 다른돌이 막고있지 않다면
					bord[x - 1][y + 1] = "☆";
					bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "☆";
				}
			}
		}
		if (max == 3 && gap_n == 1) { // 세개의 돌 사이 빈칸이 하나 있다면
			if (x + (max - 1) + gap_n < 18 && y < 18) { // 가장자리가 아니라면
				if (bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "○" && bord[x - 1][y + 1] != "○") {//양옆 모두 다른돌이 막고있지 않다면
					for (int a = x, b = y;; a++, b--) {
						if (bord[a][b] != "●") {//해당 칸이 빈칸이라면 별표를 대입
							bord[a][b] = "☆";
							break;
						}
					}
				}
			}
		}
		if (max == 4 && gap_n == 1) { // 네개의 돌 사이 빈칸이 하나 있다면
			for (int a = x, b = y;; a++, b--) {
				if (bord[a][b] != "●") {//해당 칸이 빈칸이라면 별표를 대입
					bord[a][b] = "☆";
					break;
				}
			}
		}
		if (max == 4 && gap_n == 0) { // 네개의 돌이 연속적으로 놓였다면
			if (x + (max - 1) + gap_n == 18) {//돌이 가장왼쪽아래에 놓여있다면 연속된 돌의 오른쪽위에 별대입
				bord[x - 1][y + 1] = "☆";
			}
			else if (y == 18) {//돌이 오른쪽가장위에 놓여있다면 돌의 왼쪽 아래에 별 대입
				bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "☆";
			}
		}

		if (max >= 5) { // 다섯개 돌 이상이 연속이든 빈칸이 있든
			if (x + (max - 1) + gap_n < 18 && bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] != "○") {//이어진돌의 왼쪽아래칸이 벽이 아니고 흑돌로 막히지 않앗다면
				bord[x + (max - 1) + gap_n + 1][y - (max - 1) - gap_n - 1] = "☆";//이어진 돌의 왼쪽아래칸에 별표대입
			}
			if (y < 18 && bord[x - 1][y + 1] != "○") {//이어진 돌의 오른쪽칸이 벽이아니고 흑돌로 막히지 않았다면
				bord[x - 1][y + 1] = "☆";//이어진 돌의 오른쪽 칸에 별표대입
			}
			for (int a = x, b = y;; a++, b--) {
				if (bord[a][b] != "●") {//해당 칸이 빈칸이라면 별표를 대입
					bord[a][b] = "☆";
				}
				if (a == x + (max - 1) + gap_n && b == y - (max - 1) - gap_n)break;
			}
		}
		max = 0;
		Bcount = 0;
	}
}

void diag2(string bord[19][19]) { // 좌상우하 대각선
	int x=0, y=0, gap_n = 0;
	int count = 0;
	int max = 0;
	int concount = 0;
	int Bcount = 0;
	for (int i = 0; i < 19; i = count) {//오른쪽 위 보드 흑돌
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
			if (max <= Bcount && concount == 0) {
				max = Bcount;
				x = i + 1;
				y = j + 1;
				gap_n = 0;
				for (int a = 0, b = 0;;) {
					if (bord[i + a][j + a] != "○")gap_n++;
					else if (bord[i + a][j + a] == "○")b++;
					if (b == Bcount)break;
					a++;
				}
			}
		}
		if (max > 1)cout << "좌상우하 대각선 " << count + 1 << "번째줄의 가장긴 흑돌 수는 " << max << "개"
			<< "좌표는 " << "(" << x + (max - 1) + gap_n << ", " << y + (max - 1) + gap_n << ") 부터 " << "(" << x << ", " << y << ")" << endl;
		count++;
		x--; y--;//x,y 에 원래의 좌표값을 다시 넣음

		if (max == 3 && gap_n == 0) { // 연속적으로 이어진 세개의 돌
			if (y + (max - 1) + gap_n < 18 && x > 0) { // 가장자리가 아닌 가운데라면
				if (bord[x + (max - 1) + gap_n+1][y + (max - 1) + gap_n+1] != "●" && bord[x - 1][y -1] != "●") {//양옆 모두 다른돌이 막고있지 않다면
					bord[x - 1][y - 1] = "☆";
					bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "☆";
				}
			}
		}
		if (max == 3 && gap_n == 1) { // 세개의 돌 사이 빈칸이 하나 있다면
			if (y + (max - 1) + gap_n < 18 && x > 0) { // 가장자리가 아니라면
				if (bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] != "●" && bord[x - 1][y - 1] != "●") {//양옆 모두 다른돌이 막고있지 않다면
					for (int a = x, b = y;; a++, b++) {
						if (bord[a][b] != "○") {//해당 칸이 빈칸이라면 별표를 대입
							bord[a][b] = "☆";
							break;
						}
					}
				}
			}
		}
		if (max == 4 && gap_n == 1) { // 네개의 돌 사이 빈칸이 하나 있다면
			for (int a = x, b = y;; a++, b++) {
				if (bord[a][b] != "○") {//해당 칸이 빈칸이라면 별표를 대입
					bord[a][b] = "☆";
					break;
				}
			}
		}
		if (max == 4 && gap_n == 0) { // 네개의 돌이 연속적으로 놓였다면
			if (y + (max - 1) + gap_n == 18) {//돌이 가장오른쪽아래에 놓여있다면 연속된 돌의 왼쪽위에 별대입
				bord[x-1][y - 1] = "☆";
			}
			else if (x == 0) {//돌이 오른쪽가장위에 놓여있다면 돌의 왼쪽 아래에 별 대입
				bord[x + (max - 1) + gap_n+1][y + (max - 1) + gap_n+1] = "☆";
			}
		}

		if (max >= 5) { // 다섯개 돌 이상이 연속이든 빈칸이 있든
			if (y + (max - 1) + gap_n < 18 && bord[x + (max - 1) + gap_n+1][y + (max - 1) + gap_n+1] != "●") {//이어진돌의 오른쪽아래칸이 벽이 아니고 백돌로 막히지 않앗다면
				bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "☆";//이어진 돌의 오른쪽아래칸에 별표대입
			}
			if (x > 0 && bord[x-1][y - 1] != "●") {//이어진 돌의 오른쪽위칸이 벽이아니고 백돌로 막히지 않았다면
				bord[x - 1][y - 1] = "☆";//이어진 돌의 오른쪽 칸에 별표대입
			}
			for (int a = x, b = y;; a++, b++) {
				if (bord[a][b] != "○") {//해당 칸이 빈칸이라면 별표를 대입
					bord[a][b] = "☆";
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
	for (int i = 18; count >= 0; i = 18) {//왼쪽아래 보드 흑돌
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
			if (max <= Bcount && concount == 0) {
				max = Bcount;
				x = i + 1;
				y = j + 1;
				gap_n = 0;
				for (int a = 0, b = 0;;) {
					if (bord[i + a][j + a] != "○")gap_n++;
					else if (bord[i + a][j + a] == "○")b++;
					if (b == Bcount)break;
					a++;
				}
			}
		}
		if (max > 1)cout << "좌상우하 대각선 " << 37 - count << "번째줄의 가장긴 흑돌 수는 " << max << "개"
			<< "좌표는 " << "(" << x + (max - 1) + gap_n << ", " << y + (max - 1) + gap_n << ") 부터 " << "(" << x << ", " << y << ")" << endl;
		count--;
		x--; y--;//x,y 에 원래의 좌표값을 다시 넣음

		if (max == 3 && gap_n == 0) { // 연속적으로 이어진 세개의 돌
			if (y>0&& x + (max - 1) + gap_n<18) { // 가장자리가 아닌 가운데라면
				if (bord[x + (max - 1) + gap_n+1][y + (max - 1) + gap_n+1] != "●" && bord[x - 1][y - 1] != "●") {//양옆 모두 다른돌이 막고있지 않다면
					bord[x - 1][y - 1] = "☆";
					bord[x + (max - 1) + gap_n+1][y + (max - 1) + gap_n+1] = "☆";
				}
			}
		}
		if (max == 3 && gap_n == 1) { // 세개의 돌 사이 빈칸이 하나 있다면
			if (y > 0 && x + (max - 1) + gap_n < 18) { // 가장자리가 아닌 가운데라면
				if (bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] != "●" && bord[x - 1][y - 1] != "●") {//양옆 모두 다른돌이 막고있지 않다면
					for (int a = x, b = y;; a++, b++) {
						if (bord[a][b] != "○") {//해당 칸이 빈칸이라면 별표를 대입
							bord[a][b] = "☆";
							break;
						}
					}
				}
			}
		}
		if (max == 4 && gap_n == 1) { // 네개의 돌 사이 빈칸이 하나 있다면
			for (int a = x, b = y;; a++, b++) {
				if (bord[a][b] != "○") {//해당 칸이 빈칸이라면 별표를 대입
					bord[a][b] = "☆";
					break;
				}
			}
		}
		if (max == 4 && gap_n == 0) { // 네개의 돌이 연속적으로 놓였다면
			if (x + (max - 1) + gap_n == 18) {//돌이 가장오른쪽아래에 놓여있다면 연속된 돌의 왼쪽위에 별대입
				bord[x - 1][y - 1] = "☆";
			}
			else if (y == 0) {//돌이 오른쪽가장위에 놓여있다면 돌의 왼쪽 아래에 별 대입
				bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "☆";
			}
		}

		if (max >= 5) { // 다섯개 돌 이상이 연속이든 빈칸이 있든
			if (x + (max - 1) + gap_n < 18 && bord[x + (max - 1) + gap_n+1][y + (max - 1) + gap_n+1] != "●") {//이어진돌의 오른쪽아래칸이 벽이 아니고 백돌로 막히지 않앗다면
				bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "☆";//이어진 돌의 오른쪽아래칸에 별표대입
			}
			if (y > 0 && bord[x - 1][y - 1] != "●") {//이어진 돌의 왼쪽위칸이 벽이아니고 백돌로 막히지 않았다면
				bord[x - 1][y - 1] = "☆";//이어진 돌의 오른쪽 칸에 별표대입
			}
			for (int a = x, b = y;; a++, b++) {
				if (bord[a][b] != "○") {//해당 칸이 빈칸이라면 별표를 대입
					bord[a][b] = "☆";
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
	for (int i = 0; i < 19; i = count) {//오른쪽 위 보드 백돌
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
			if (max <= Bcount && concount == 0) {
				max = Bcount;
				x = i + 1;
				y = j + 1;
				gap_n = 0;
				for (int a = 0, b = 0;;) {
					if (bord[i + a][j + a] != "●")gap_n++;
					else if (bord[i + a][j + a] == "●")b++;
					if (b == Bcount)break;
					a++;
				}
			}
		}
		if (max > 1)cout << "좌상우하 대각선 " << count + 1 << "번째줄의 가장긴 흰돌 수는 " << max << "개"
			<< "좌표는 " << "(" << x + (max - 1) + gap_n << ", " << y + (max - 1) + gap_n << ") 부터 " << "(" << x << ", " << y << ")" << endl;
		count++;
		x--; y--;//x,y 에 원래의 좌표값을 다시 넣음

		if (max == 3 && gap_n == 0) { // 연속적으로 이어진 세개의 돌
			if (y + (max - 1) + gap_n < 18 && x > 0) { // 가장자리가 아닌 가운데라면
				if (bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] != "○" && bord[x - 1][y - 1] != "○") {//양옆 모두 다른돌이 막고있지 않다면
					bord[x - 1][y - 1] = "☆";
					bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "☆";
				}
			}
		}
		if (max == 3 && gap_n == 1) { // 세개의 돌 사이 빈칸이 하나 있다면
			if (y + (max - 1) + gap_n < 18 && x > 0) { // 가장자리가 아니라면
				if (bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] != "○" && bord[x - 1][y - 1] != "○") {//양옆 모두 다른돌이 막고있지 않다면
					for (int a = x, b = y;; a++, b++) {
						if (bord[a][b] != "●") {//해당 칸이 빈칸이라면 별표를 대입
							bord[a][b] = "☆";
							break;
						}
					}
				}
			}
		}
		if (max == 4 && gap_n == 1) { // 네개의 돌 사이 빈칸이 하나 있다면
			for (int a = x, b = y;; a++, b++) {
				if (bord[a][b] != "●") {//해당 칸이 빈칸이라면 별표를 대입
					bord[a][b] = "☆";
					break;
				}
			}
		}
		if (max == 4 && gap_n == 0) { // 네개의 돌이 연속적으로 놓였다면
			if (y + (max - 1) + gap_n == 18) {//돌이 가장오른쪽아래에 놓여있다면 연속된 돌의 왼쪽위에 별대입
				bord[x - 1][y - 1] = "☆";
			}
			else if (x == 0) {//돌이 오른쪽가장위에 놓여있다면 돌의 왼쪽 아래에 별 대입
				bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "☆";
			}
		}

		if (max >= 5) { // 다섯개 돌 이상이 연속이든 빈칸이 있든
			if (y + (max - 1) + gap_n < 18 && bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] != "○") {//이어진돌의 오른쪽아래칸이 벽이 아니고 흑돌로 막히지 않앗다면
				bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "☆";//이어진 돌의 오른쪽아래칸에 별표대입
			}
			if (x > 0 && bord[x - 1][y - 1] != "○") {//이어진 돌의 오른쪽위칸이 벽이아니고 흑돌로 막히지 않았다면
				bord[x - 1][y - 1] = "☆";//이어진 돌의 오른쪽 칸에 별표대입
			}
			for (int a = x, b = y;; a++, b++) {
				if (bord[a][b] != "●") {//해당 칸이 빈칸이라면 별표를 대입
					bord[a][b] = "☆";
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
	for (int i = 18; count >= 0; i = 18) {//왼쪽 아래 보드 백돌
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
			if (max <= Bcount && concount == 0) {
				max = Bcount;
				x = i + 1;
				y = j + 1;
				gap_n = 0;
				for (int a = 0, b = 0;;) {
					if (bord[i + a][j + a] != "●")gap_n++;
					else if (bord[i + a][j + a] == "●")b++;
					if (b == Bcount)break;
					a++;
				}
			}
		}
		if (max > 1)cout << "좌상우하 대각선 " << 37 - count << "번째줄의 가장긴 흰돌 수는 " << max << "개"
			<< "좌표는 " << "(" << x + (max - 1) + gap_n << ", " << y + (max - 1) + gap_n << ") 부터 " << "(" << x << ", " << y << ")" << endl;
		count--;
		x--; y--;//x,y 에 원래의 좌표값을 다시 넣음

		if (max == 3 && gap_n == 0) { // 연속적으로 이어진 세개의 돌
			if (y > 0 && x + (max - 1) + gap_n < 18) { // 가장자리가 아닌 가운데라면
				if (bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] != "○" && bord[x - 1][y - 1] != "○") {//양옆 모두 다른돌이 막고있지 않다면
					bord[x - 1][y - 1] = "☆";
					bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "☆";
				}
			}
		}
		if (max == 3 && gap_n == 1) { // 세개의 돌 사이 빈칸이 하나 있다면
			if (y > 0 && x + (max - 1) + gap_n < 18) { // 가장자리가 아닌 가운데라면
				if (bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] != "○" && bord[x - 1][y - 1] != "○") {//양옆 모두 다른돌이 막고있지 않다면
					for (int a = x, b = y;; a++, b++) {
						if (bord[a][b] != "●") {//해당 칸이 빈칸이라면 별표를 대입
							bord[a][b] = "☆";
							break;
						}
					}
				}
			}
		}
		if (max == 4 && gap_n == 1) { // 네개의 돌 사이 빈칸이 하나 있다면
			for (int a = x, b = y;; a++, b++) {
				if (bord[a][b] != "●") {//해당 칸이 빈칸이라면 별표를 대입
					bord[a][b] = "☆";
					break;
				}
			}
		}
		if (max == 4 && gap_n == 0) { // 네개의 돌이 연속적으로 놓였다면
			if (x + (max - 1) + gap_n == 18) {//돌이 가장오른쪽아래에 놓여있다면 연속된 돌의 왼쪽위에 별대입
				bord[x - 1][y - 1] = "☆";
			}
			else if (y == 0) {//돌이 오른쪽가장위에 놓여있다면 돌의 왼쪽 아래에 별 대입
				bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "☆";
			}
		}

		if (max >= 5) { // 다섯개 돌 이상이 연속이든 빈칸이 있든
			if (x + (max - 1) + gap_n < 18 && bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] != "○") {//이어진돌의 오른쪽아래칸이 벽이 아니고 흑돌로 막히지 않앗다면
				bord[x + (max - 1) + gap_n + 1][y + (max - 1) + gap_n + 1] = "☆";//이어진 돌의 오른쪽아래칸에 별표대입
			}
			if (y > 0 && bord[x - 1][y - 1] != "○") {//이어진 돌의 왼쪽위칸이 벽이아니고 흑돌로 막히지 않았다면
				bord[x - 1][y - 1] = "☆";//이어진 돌의 오른쪽 칸에 별표대입
			}
			for (int a = x, b = y;; a++, b++) {
				if (bord[a][b] != "●") {//해당 칸이 빈칸이라면 별표를 대입
					bord[a][b] = "☆";
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

		system("cls");

		int max = 0;
		x = 0, y = 0;
		int tmp = 0;
		int concount = 0; // 인접한곳에 돌이있으면 0 한칸 떨어져있으면 1 두칸떨어지면 2
		int gap_n = 0;
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
				if (max <= Bcount && concount == 0) {
					max = Bcount;
					x = i + 1;
					y = j + 1;
					gap_n = 0;
					for (int a = 0, b = 0;;) {
						if (bord[i][j - a] != "○")gap_n++;
						else if (bord[i][j - a] == "○")b++;
						if (b == Bcount)break;
						a++;
					}
				}
			}
			if (max > 1)cout << i + 1 << "행의 이어진 가장긴 흑돌 수는 " << max << "개 "
				<< "좌표는 " << "(" << x << ", " << y - (max - 1) - gap_n << ") 부터 " << "(" << x << ", " << y << ")" << endl;
			x--; y--;//x,y 에 원래의 좌표값을 다시 넣음
			if (max == 3 && gap_n == 0) { // 연속적으로 이어진 세개의 돌
				if (y < 18 && (y - (max - 1) - gap_n)>0) { // 가장자리가 아닌 가운데라면
					if (bord[x][y + 1] != "●" && bord[x][y - (max - 1) - gap_n - 1] != "●") {//양옆 모두 다른돌이 막고있지 않다면
						bord[x][y + 1] = "☆";
						bord[x][y - (max - 1) - gap_n - 1] = "☆";
					}
				}
			}
			if (max == 3 && gap_n == 1) { // 세개의 돌 사이 빈칸이 하나 있다면
				if (y < 18 && (y - (max - 1) - gap_n)>0) { // 가장자리가 아니라면
					if (bord[x][y + 1] != "●" && bord[x][y - (max - 1) - gap_n - 1] != "●") {//양옆 모두 다른돌이 막고있지 않다면
						for (int a = y;; a--) {
							if (bord[x][a] != "○") {//해당 칸이 빈칸이라면 별표를 대입
								bord[x][a] = "☆";
								break;
							}
						}
					}
				}
			}
			if (max == 4 && gap_n == 1) { // 네개의 돌 사이 빈칸이 하나 있다면
				for (int a = y;; a--) {
					if (bord[x][a] != "○") {//해당 칸이 빈칸이라면 별표를 대입
						bord[x][a] = "☆";
						break;
					}
				}
			}
			if (max == 4 && gap_n == 0) { // 네개의 돌이 연속적으로 놓였다면
				if (y == 18) {//돌이 오른쪽 가장자리에 놓여있다면 연속된 돌의 왼쪽칸에 별 대입
					bord[x][y - (max - 1) - gap_n - 1] = "☆";
				}
				else if ((y - (max - 1) - gap_n) == 0) {//돌이 왼쪽 가장자리에 놓여있다면 연속된 돌의 오른쪽칸에 별 대입
					bord[x][y + 1] = "☆";
				}
			}

			if (max >= 5) { // 다섯개 돌 이상이 연속이든 빈칸이 있든
				if (y - (max - 1) - gap_n - 1 >= 0 && bord[x][y - (max - 1) - gap_n - 1]!= "●") {//이어진돌의 왼쪽칸이 벽이 아니고 백돌로 막히지 않앗다면
					bord[x][y - (max - 1) - gap_n - 1] = "☆";//이어진 돌의 왼쪽칸에 별표대입
				}
				if (y + 1 <= 18 && bord[x][y + 1] != "●") {//이어진 돌의 오른쪽칸이 벽이아니고 백돌로 막히지 않았다면
					bord[x][y + 1] = "☆";//이어진 돌의 오른쪽 칸에 별표대입
				}
				for (int a = y;a>= y - (max - 1) - gap_n; a--) {//이어진 돌의 좌표들중
					if(bord[x][a]!= "○" && bord[x][a]!= "●")//빈칸이 있다면
						bord[x][a]= "☆";//빈칸에 별표 대입
				}
			}
			
			max = 0;
			Bcount = 0;
		}
		//↑행에 검은돌이 연속인가

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
				if (max <= Bcount && concount == 0) {
					max = Bcount;
					x = i + 1;
					y = j + 1;
					gap_n = 0;
					for (int a = 0, b = 0;;) {
						if (bord[i - a][j] != "○")gap_n++;
						else if (bord[i - a][j] == "○")b++;
						if (b == Bcount)break;
						a++;
					}
				}
			}
			if (max > 1)cout << j + 1 << "열의 이어진 가장긴 흑돌 수는 " << max << "개 "
				<< "좌표는 " << "(" << x - (max - 1)-gap_n << ", " << y << ") 부터 " << "(" << x << ", " << y << ")" << endl;
			x--; y--;//x,y 에 원래의 좌표값을 다시 넣음
			if (max == 3 && gap_n == 0) { // 연속적으로 이어진 세개의 돌
				if (x < 18 && (x - (max - 1) - gap_n)>0) { // 가장자리가 아닌 가운데라면
					if (bord[x+1][y] != "●" && bord[x - (max - 1) - gap_n-1][y] != "●") {//양옆 모두 다른돌이 막고있지 않다면
						bord[x+1][y] = "☆";
						bord[x - (max - 1) - gap_n-1][y] = "☆";
					}
				}
			}
			if (max == 3 && gap_n == 1) { // 세개의 돌 사이 빈칸이 하나 있다면
				if (x < 18 && (x - (max - 1) - gap_n)>0) { // 가장자리가 아니라면
					if (bord[x+1][y] != "●" && bord[x - (max - 1) - gap_n-1][y] != "●") {//양옆 모두 다른돌이 막고있지 않다면
						for (int a = x;; a--) {
							if (bord[a][y] != "○") {//해당 칸이 빈칸이라면 별표를 대입
								bord[a][y] = "☆";
								break;
							}
						}
					}
				}
			}
			if (max == 4 && gap_n == 1) { // 네개의 돌 사이 빈칸이 하나 있다면
				for (int a = x;; a--) {
					if (bord[a][y] != "○") {//해당 칸이 빈칸이라면 별표를 대입
						bord[a][y] = "☆";
						break;
					}
				}
			}
			if (max == 4 && gap_n == 0) { // 네개의 돌이 연속적으로 놓였다면
				if (x == 18) {//돌이 오른쪽 가장자리에 놓여있다면 연속된 돌의 왼쪽칸에 별 대입
					bord[x - (max - 1) - gap_n - 1][y] = "☆";
				}
				else if ((x- (max - 1) - gap_n) == 0) {//돌이 왼쪽 가장자리에 놓여있다면 연속된 돌의 오른쪽칸에 별 대입
					bord[x+1][y] = "☆";
				}
			}

			if (max >= 5) { // 다섯개 돌 이상이 연속이든 빈칸이 있든
				if (x - (max - 1) - gap_n - 1 >= 0 && bord[x - (max - 1) - gap_n - 1][y] != "●") {//이어진돌의 윗칸이 벽이 아니고 백돌로 막히지 않앗다면
					bord[x - (max - 1) - gap_n - 1][y] = "☆";//이어진 돌의 윗쪽칸에 별표대입
				}
				if (x + 1 <= 18 && bord[x+1][y] != "●") {//이어진 돌의 오른쪽칸이 벽이아니고 백돌로 막히지 않았다면
					bord[x+1][y] = "☆";//이어진 돌의 오른쪽 칸에 별표대입
				}
				for (int a = x; a >= x - (max - 1) - gap_n; a--) {//이어진 돌의 좌표들중
					if (bord[a][y] != "○" && bord[a][y] != "●")//빈칸이 있다면
						bord[a][y] = "☆";//빈칸에 별표 대입
				}
			}

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
				if (max <= Wcount && concount == 0) {
					max = Wcount;
					x = i + 1;
					y = j + 1;
					gap_n = 0;
					for (int a = 0, b = 0;;) {
						if (bord[i][j - a] != "●")gap_n++;
						else if (bord[i][j - a] == "●")b++;
						if (b == Wcount)break;
						a++;
					}
				}


			}
			if (max > 1)cout << i + 1 << "행의 이어진 가장긴 흰돌 수는 " << max << "개 "
				<< "좌표는 " << "(" << x << ", " << y - (max - 1) - gap_n << ") 부터 " << "(" << x << ", " << y << ")" << endl;
			x--; y--;//x,y 에 원래의 좌표값을 다시 넣음
			if (max == 3 && gap_n == 0) { // 연속적으로 이어진 세개의 돌
				if (y < 18 && (y - (max - 1) - gap_n)>0) { // 가장자리가 아닌 가운데라면
					if (bord[x][y + 1] != "○" && bord[x][y - (max - 1) - gap_n - 1] != "○") {//양옆 모두 다른돌이 막고있지 않다면
						bord[x][y + 1] = "☆";
						bord[x][y - (max - 1) - gap_n - 1] = "☆";
					}
				}
			}
			if (max == 3 && gap_n == 1) { // 세개의 돌 사이 빈칸이 하나 있다면
				if (y < 18 && (y - (max - 1) - gap_n)>0) { // 가장자리가 아니라면
					if (bord[x][y + 1] != "○" && bord[x][y - (max - 1) - gap_n - 1] != "○") {//양옆 모두 다른돌이 막고있지 않다면
						for (int a = y;; a--) {
							if (bord[x][a] != "●") {//해당 칸이 빈칸이라면 별표를 대입
								bord[x][a] = "☆";
								break;
							}
						}
					}
				}
			}
			if (max == 4 && gap_n == 1) { // 네개의 돌 사이 빈칸이 하나 있다면
				for (int a = y;; a--) {
					if (bord[x][a] != "●") {//해당 칸이 빈칸이라면 별표를 대입
						bord[x][a] = "☆";
						break;
					}
				}
			}
			if (max == 4 && gap_n == 0) { // 네개의 돌이 연속적으로 놓였다면
				if (y == 18) {//돌이 오른쪽 가장자리에 놓여있다면 연속된 돌의 왼쪽칸에 별 대입
					bord[x][y - (max - 1) - gap_n - 1] = "☆";
				}
				else if ((y - (max - 1) - gap_n) == 0) {//돌이 왼쪽 가장자리에 놓여있다면 연속된 돌의 오른쪽칸에 별 대입
					bord[x][y + 1] = "☆";
				}
			}

			if (max >= 5) { // 다섯개 돌 이상이 연속이든 빈칸이 있든
				if (y - (max - 1) - gap_n - 1 >= 0 && bord[x][y - (max - 1) - gap_n - 1] != "○") {//이어진돌의 왼쪽칸이 벽이 아니고 백돌로 막히지 않앗다면
					bord[x][y - (max - 1) - gap_n - 1] = "☆";//이어진 돌의 왼쪽칸에 별표대입
				}
				if (y + 1 <= 18 && bord[x][y + 1] != "○") {//이어진 돌의 오른쪽칸이 벽이아니고 흑돌로 막히지 않았다면
					bord[x][y + 1] = "☆";//이어진 돌의 오른쪽 칸에 별표대입
				}
				for (int a = y; a >= y - (max - 1) - gap_n; a--) {//이어진 돌의 좌표들중
					if (bord[x][a] != "●" && bord[x][a] != "○")//빈칸이 있다면
						bord[x][a] = "☆";//빈칸에 별표 대입
				}
			}

			max = 0;
			Bcount = 0;
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
				if (max <= Wcount && concount == 0) {
					max = Wcount;
					x = i + 1;
					y = j + 1;
					gap_n = 0;
					for (int a = 0, b = 0;;) {
						if (bord[i - a][j] != "●")gap_n++;
						else if (bord[i - a][j] == "●")b++;
						if (b == Wcount)break;
						a++;
					}
				}
			}
			if (max > 1)cout << j + 1 << "열의 이어진 가장긴 흰돌 수는 " << max << "개 "
				<< "좌표는 " << "(" << x - (max - 1) - gap_n << ", " << y << ") 부터 " << "(" << x << ", " << y << ")" << endl;
			x--; y--;//x,y 에 원래의 좌표값을 다시 넣음
			if (max == 3 && gap_n == 0) { // 연속적으로 이어진 세개의 돌
				if (x < 18 && (x - (max - 1) - gap_n)>0) { // 가장자리가 아닌 가운데라면
					if (bord[x + 1][y] != "○" && bord[x - (max - 1) - gap_n - 1][y] != "○") {//양옆 모두 다른돌이 막고있지 않다면
						bord[x + 1][y] = "☆";
						bord[x - (max - 1) - gap_n - 1][y] = "☆";
					}
				}
			}
			if (max == 3 && gap_n == 1) { // 세개의 돌 사이 빈칸이 하나 있다면
				if (x < 18 && (x - (max - 1) - gap_n)>0) { // 가장자리가 아니라면
					if (bord[x + 1][y] != "○" && bord[x - (max - 1) - gap_n - 1][y] != "○") {//양옆 모두 다른돌이 막고있지 않다면
						for (int a = x;; a--) {
							if (bord[a][y] != "●") {//해당 칸이 빈칸이라면 별표를 대입
								bord[a][y] = "☆";
								break;
							}
						}
					}
				}
			}
			if (max == 4 && gap_n == 1) { // 네개의 돌 사이 빈칸이 하나 있다면
				for (int a = x;; a--) {
					if (bord[a][y] != "●") {//해당 칸이 빈칸이라면 별표를 대입
						bord[a][y] = "☆";
						break;
					}
				}
			}
			if (max == 4 && gap_n == 0) { // 네개의 돌이 연속적으로 놓였다면
				if (x == 18) {//돌이 오른쪽 가장자리에 놓여있다면 연속된 돌의 왼쪽칸에 별 대입
					bord[x - (max - 1) - gap_n - 1][y] = "☆";
				}
				else if ((x - (max - 1) - gap_n) == 0) {//돌이 왼쪽 가장자리에 놓여있다면 연속된 돌의 오른쪽칸에 별 대입
					bord[x + 1][y] = "☆";
				}
			}

			if (max >= 5) { // 다섯개 돌 이상이 연속이든 빈칸이 있든
				if (x - (max - 1) - gap_n - 1 >= 0 && bord[x - (max - 1) - gap_n - 1][y] != "○") {//이어진돌의 윗칸이 벽이 아니고 흑돌로 막히지 않앗다면
					bord[x - (max - 1) - gap_n - 1][y] = "☆";//이어진 돌의 윗쪽칸에 별표대입
				}
				if (x + 1 <= 18 && bord[x + 1][y] != "○") {//이어진 돌의 오른쪽칸이 벽이아니고 흑돌로 막히지 않았다면
					bord[x + 1][y] = "☆";//이어진 돌의 오른쪽 칸에 별표대입
				}
				for (int a = x; a >= x - (max - 1) - gap_n; a--) {//이어진 돌의 좌표들중
					if (bord[a][y] != "●" && bord[a][y] != "○")//빈칸이 있다면
						bord[a][y] = "☆";//빈칸에 별표 대입
				}
			}

			max = 0;
			Bcount = 0;
		}

		diag(bord);
		diag2(bord);

		printbord(bord);
		bordclear(bord);


	}//와일문 끝
}//메인문 끝

//○흑돌 ●백돌