#include <iostream>
using namespace std;

struct lol_dic {
	char name[20] = " ";
	int hp = 1;
	int mp = 1;
	int speed = 1;
	int range = 1;
	char position[20] = " ";

	void show() {
		cout << "\n챔피언 명 : " << name << "\n체력 : " << hp << "\n마나 : " << mp
			<< "\n이동속도 : " << speed << "\n사거리 : " << range << "\n주 포지션 : " << position
			<< endl;
	}

	void del() {
		name[0] = ' ';
		position[0] = ' ';
		for (int i = 1; i < 20; i++) {
			name[i] = NULL;
			position[i] = NULL;
		}
		hp = 1;
		mp = 1;
		speed = 1;
		range = 1;
	}

};

int main() {
	cout << "롤 백과" << endl;
	lol_dic champ[100] =
	{
		{"Graves", 2115, 1002, 345, 425, "Jungle"}, {"LeeSin", 2015, 200, 345, 125, "Jungle"},
		{"Ahri", 2090, 843, 330, 550, "Mid"}, {"Kaisa", 2033, 990, 335, 525, "Ad"},
		{"Nidalee", 1990, 1060, 335, 525, "Jungle"}, {"Nico", 2070, 960, 340, 550, "Mid"},
		{"Teemo", 2058, 947, 330, 500, "Top"}, {"Garen", 2048, 0, 340, 175, "Top"},
		{"Nunu", 2100, 997, 345, 125, "Jungle"}, {"Galio", 2466, 1080, 335, 125, "supporter"},
		{"Illaoi", 2200, 980, 340, 125, "Top"}, {"Udyr", 2276, 780, 345, 125, "Jungle"},
		{"Darius", 2282, 780, 340, 125, "Top"}, {"Yorick", 2280, 980, 340, 175, "Top"},
		{"Mordekaiser", 1856, 120, 325, 175, "Top"}, {"Chogath", 1934, 952, 345, 125, "Top"},
		{"Jin", 2103, 1150, 330, 550, "Ad"}, {"Zed", 2029, 200, 345, 125, "Mid"},
		{"Alistar", 2375, 924, 330, 125, "supporter"}, {"Sona", 1791, 1105, 325, 550, "supporter"}
	};

	while (true) {
		int num;
		for (int i = 0; i < 100; i++) {
			if (champ[i].name[0] == ' ') {
				num = i;
				break;
			}
		}// 비어잇는 방 찾아서 num 에 대입
		cout << "\n현재 등록되어 있는 챔피언 수 " << num << endl;
		cout << "1. 챔피언 정보 보기" << endl; //이름으로 찾기
		cout << "2. 챔피언 정보 입력하기" << endl;
		cout << "3. 챔피언 이름으로 정보 삭제" << endl;
		cout << "4. 입력하는 포지션의 챔피언 정보 모두삭제" << endl;
		cout << "5. 챔피언 정보 모두보기" << endl;
		cout << "6. 체력이 가장 높은 챔피언 보기" << endl;
		cout << "7. 체력이 높은 챔피언 순서대로 정렬하기" << endl;
		cout << "8. 프로그램 종료" << endl;
		cout << "입력 : ";

		int an;
		cin >> an;
		char name[20], position[20];
		int hp, mp, speed, range;
		lol_dic tmp;
		lol_dic tmptable[100];


		if (!(0 < an&&an < 9)) {
			cout << "\n확인 후 다시 입력해주세요.\n" << endl;
			continue;
		}

		switch (an)
		{
		case 1:
			cout << "\n정보를 볼 챔피언의 이름을 입력하세요 : ";
			cin >> name;

			for (int i = 0; i < 100; i++) {
					if (champ[i].name[0] == name[0] && champ[i].name[1] == name[1] && champ[i].name[2] == name[2]) {
						champ[i].show();
						break;
					}

			}
			break;

		case 2:
			cout << "\n입력하신 데이터는 롤백과에 수집됩니다" << endl;
			cout << "이름 : "; cin >> champ[num].name;
			cout << "hp : "; cin >> champ[num].hp;
			cout << "mp : "; cin >> champ[num].mp;
			cout << "speed : "; cin >> champ[num].speed;
			cout << "range : "; cin >> champ[num].range;
			cout << "position : "; cin >> champ[num].position;
			cout << num + 1 << "번째 챔피언으로 등록 되었습니다." << endl;
			break;

		case 3:
			cout << "\n삭제할 챔피언을 입력하세요 : ";
			cin >> name;
			for (int i = 0; i < 100; i++) {
				if (champ[i].name[0] == name[0] && champ[i].name[1] == name[1] && champ[i].name[2] == name[2]) {
					champ[i].del();
					for (i; i < 99; i++) { // 한칸씩 당기기
						for (int j = 0; j < 20; j++) {
							champ[i].name[j] = champ[i + 1].name[j];
							champ[i].position[j] = champ[i + 1].position[j];
						}
						champ[i].hp = champ[i + 1].hp;
						champ[i].mp = champ[i + 1].mp;
						champ[i].speed = champ[i + 1].speed;
						champ[i].range = champ[i + 1].range;
					}
				}
			}
			break;
		case 4:
			cout << "삭제할 포지션을 입력하세요 : ";
			cin >> position;
			for (int i = 0; i < 100; i++) {
				if (champ[i].position[0] == position[0] && champ[i].position[1] == position[1]) {
					champ[i].del();
					for (int j = i; j < 99; j++) { // 한칸씩 당기기
						for (int k = 0; k < 20; k++) {
							champ[j].name[k] = champ[j + 1].name[k];
							champ[j].position[k] = champ[j + 1].position[k];
						}
						champ[j].hp = champ[j + 1].hp;
						champ[j].mp = champ[j + 1].mp;
						champ[j].speed = champ[j + 1].speed;
						champ[j].range = champ[j + 1].range;
					}
					i--;
				}
			}
			break;
		case 5:
			cout << endl;
			for (int i = 0; i < 100; i++) {
				if (champ[i].name[0] != ' ') {
					champ[i].show();
				}
			}
			break;

		case 6:
		{
			int best = 0;
			int index;
			for (int i = 0; i < 100; i++) {
				if (best < champ[i].hp) {
					best = champ[i].hp;
					index = i;
				}
			}
			champ[index].show();
		}
			break;

		case 7:
			cout << endl << "챔피언 순서를 체력이 높은 순서대로 정렬합니다." << endl;

			for (int i = 0; i < 99; i++) { // 체력이 높은 챔피언 순서대로 교환 알고리즘
				for (int j = i + 1; j < 100; j++) {
					if (champ[i].hp < champ[j].hp) {
						for (int k = 0; k < 20; k++) {
							tmp.name[k] = champ[j + 1].name[k];
							tmp.position[k] = champ[j + 1].position[k];
						}
						tmp.hp = champ[i].hp;
						tmp.mp = champ[i].mp;
						tmp.speed = champ[i].speed;
						tmp.range = champ[i].range;// 임시변수 tmp에 정보를 옮김

						for (int k = 0; k < 20; k++) {
							champ[i].name[k] = champ[j].name[k];
							champ[i].name[k] = champ[j].position[k];
						}
						champ[i].hp = champ[j].hp;
						champ[i].mp = champ[j].mp;
						champ[i].speed = champ[j].speed;
						champ[i].range = champ[j].range;

						for (int k = 0; k < 20; k++) {
							champ[j].name[k] = tmp.name[k];
							champ[j].position[k] = tmp.position[k];
						}
						champ[j].hp = tmp.hp;
						champ[j].mp = tmp.mp;
						champ[j].speed = tmp.speed;
						champ[j].range = tmp.range;
					}
				}
			}
			break;
		case 8:
			return 0;
		default:
			break;
		}

	}
}


//Search[챔피언이름] : 주어진 챔피언의 정보를 출력한다.
//Insert : 새로운 챔피언의 정보를 입력받아 삽입한다.
//	Delete[챔피언이름] : 주어진 챔피언에 대한 정보를 삭제한다.
//	DeleteAll[position] : 주어진 위치의 모든 챔피언 정보를 삭제한다.
//	PrintAll : 모든 챔피언의 정보를 배열에 저장된 순서대로 출력한다.
//	FindMaxHp : 가장 체력이 큰 챔피언의 정보를 출력한다.
//	SortByHp : 체력이 큰 챔피언부터 순서대로 저장한다.
//