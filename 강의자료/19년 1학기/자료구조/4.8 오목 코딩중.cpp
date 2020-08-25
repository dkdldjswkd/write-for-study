#include <iostream>
#include <string>
using namespace std;

//┌ ┐ ┘ └ ├ ┬ ┤ ┴ ┼

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
	bool jb = false;

	while (1) { // 여기서부턴 게임진행

		while (1) { // 흑돌이 두는 알고리즘
			jb = false;
			cout << "흑돌의 갯수 : " << black << endl;
			cout << "흰돌의 갯수 : " << white << endl;
			cout << "흑돌은 놓을 자리를 입력하세요 : ";
			rewind(stdin); // 입력버퍼 비우기
			cin >> x >> y; // 좌표를 입력받음
			if (x > 19 || y > 19 || x < 1 || y < 1) {
				cout << "숫자를 확인하고 다시 입력해주세요" << endl;
				continue;
			}
			for (int i = 0; i < 19; i++) {
				for (int j = 0; j < 19; j++) {
					if (bord[i][j] == "○" || bord[i][j] == "●") {
						jb = true;
						cout << "이미 놓은 칸입니다 다시 입력해주세요" << endl;
						break;
					}
				}
				if (jb)break;
			}
			if (jb)continue;

			bord[x - 1][y - 1] = "○"; // 그 좌표에 흑돌 대입
			black++;

			for (int i = 0; i < 19; i++) { // 바둑판 출력
				for (int j = 0; j < 19; j++) {
					cout << bord[i][j];
					if (!(bord[i][j] == "○" || bord[i][j] == "●")) cout << " ";
				}
				cout << endl;
			}
			break;
		}

		while (1) { // 흰돌이 두는 알고리즘
			jb = 0;
			cout << "흑돌의 갯수 : " << black << endl;
			cout << "흰돌의 갯수 : " << white << endl;
			cout << "흰돌은 놓을 자리를 입력하세요 : ";
			rewind(stdin); // 입력버퍼 비우기
			cin >> x >> y; // 좌표를 입력받음
			if (x > 19 || y > 19 || x < 1 || y < 1) {
				cout << "숫자를 확인하고 다시 입력해주세요" << endl;
				continue;
			}
			for (int i = 0; i < 19; i++) {
				for (int j = 0; j < 19; j++) {
					if (bord[i][j] == "○" || bord[i][j] == "●") {
						jb = true;
						cout << "이미 놓은 칸입니다 다시 입력해주세요" << endl;
						break;
					}
				}
				if (jb)break;
			}
			if (jb)continue;
			bord[x - 1][y - 1] = "●"; // 그 좌표에 흰돌 대입
			white++;

			for (int i = 0; i < 19; i++) { // 바둑판 출력
				for (int j = 0; j < 19; j++) {
					cout << bord[i][j];
					if (!(bord[i][j] == "○" || bord[i][j] == "●")) cout << " ";
				}
				cout << endl;
			}
			break;
		}

	}
}