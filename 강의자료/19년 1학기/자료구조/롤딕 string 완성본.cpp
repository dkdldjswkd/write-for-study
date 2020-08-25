#include <iostream>
#include <string>
using namespace std;

struct lol_dic {
	string name = " ";
	int hp = 1;
	int mp = 1;
	int speed = 1;
	int range = 1;
	string position = " ";

	void show() {
		cout << "\n챔피언 명 : " << name << "\n체력 : " << hp << "\n마나 : " << mp
			<< "\n이동속도 : " << speed << "\n사거리 : " << range << "\n주 포지션 : " << position
			<< endl;
	}

	void in(string name, int hp, int mp, int speed, int range, string position) {
		this->name = name;
		this->hp = hp;
		this->mp = mp;
		this->speed = speed;
		this->range = range;
		this->position = position;
	}

	void del() {
		this->name = " ";
		this->hp = 1;
		this->mp = 1;
		this->speed = 1;
		this->range = 1;
		this->position = " ";
	}
};

int main() {
	cout << "롤 백과" << endl;
	lol_dic champ[100] =
	{
		{"그레이브즈", 2115, 1002, 345, 425, "정글"}, {"리신", 2015, 200, 345, 125, "정글"},
		{"아리", 2090, 843, 330, 550, "미드"}, {"카이사", 2033, 990, 335, 525, "원딜"},
		{"니달리", 1990, 1060, 335, 525, "정글"}, {"니코", 2070, 960, 340, 550, "미드"},
		{"티모", 2058, 947, 330, 500, "탑"}, {"가렌", 2048, 0, 340, 175, "탑"},
		{"누누", 2100, 997, 345, 125, "정글"}, {"갈리오", 2466, 1080, 335, 125, "서포터"},
		{"일라오이", 2200, 980, 340, 125, "탑"}, {"우디르", 2276, 780, 345, 125, "정글"},
		{"다리우스", 2282, 780, 340, 125, "탑"}, {"요릭", 2280, 980, 340, 175, "탑"},
		{"모데카이저", 1856, 120, 325, 175, "탑"}, {"초가스", 1934, 952, 345, 125, "탑"},
		{"진", 2103, 1150, 330, 550, "원딜"}, {"제드", 2029, 200, 345, 125, "미드"},
		{"알리스타", 2375, 924, 330, 125, "서포터"}, {"소나", 1791, 1105, 325, 550, "서포터"}
	};

	while (true) {
		int num;
		for (int i = 0; i < 100; i++) {
			if (champ[i].name == " ") {
				num = i;
				break;
			}
		}// 비어잇는 방 찾아서 num 에 대입
		cout << "\n현제 등록되어 있는 챔피언 수 " << num << endl;
		cout << "1. 챔피언 정보 보기" << endl; //이름으로 찾기
		cout << "2. 챔피언 정보 입력하기" << endl;
		cout << "3. 챔피언 이름으로 정보 삭제" << endl;
		cout << "4. 입력하는 포지션의 챔피언 정보 모두삭제" << endl;
		cout << "5. 챔피언 정보 모두보기" << endl;
		cout << "6. 체력이 가장 높은 챔피언 순서대로 보기" << endl;
		cout << "7. 체력이 높은 챔피언 순서대로 정렬하기" << endl;
		cout << "8. 프로그램 종료" << endl;
		cout << "입력 : ";

		int an;
		cin >> an;
		string name, position;
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
				if (champ[i].name == name) {
					champ[i].show();
					break;
				}
			}
			break;

		case 2:
			cout << "\n입력하신 데이터는 롤백과에 수집됩니다" << endl;
			cout << "이름 : "; cin >> name;
			cout << "hp : "; cin >> hp;
			cout << "mp : "; cin >> mp;
			cout << "speed : "; cin >> speed;
			cout << "range : "; cin >> range;
			cout << "position : "; cin >> position;
			champ[num].in(name, hp, mp, speed, range, position);
			cout << num + 1 << "번째 챔피언으로 등록 되었습니다." << endl;
			break;

		case 3:
			cout << "\n삭제할 챔피언을 입력하세요 : ";
			cin >> name;
			for (int i = 0; i < 100; i++) {
				if (champ[i].name == name) {
					champ[i].del();
					for (i; i < 99; i++) { // 한칸씩 당기기
						champ[i].name = champ[i + 1].name;
						champ[i].hp = champ[i + 1].hp;
						champ[i].mp = champ[i + 1].mp;
						champ[i].speed = champ[i + 1].speed;
						champ[i].range = champ[i + 1].range;
						champ[i].position = champ[i + 1].position;
					}
				}
			}
			break;
		case 4:
			cout << "삭제할 포지션을 입력하세요 : ";
			cin >> position;
			for (int i = 0; i < 100; i++) {
				if (champ[i].position == position) {
					champ[i].del();
					for (int j = i; j < 99; j++) { // 한칸씩 당기기
						champ[j].name = champ[j + 1].name;
						champ[j].hp = champ[j + 1].hp;
						champ[j].mp = champ[j + 1].mp;
						champ[j].speed = champ[j + 1].speed;
						champ[j].range = champ[j + 1].range;
						champ[j].position = champ[j + 1].position;
					}
					i--;
				}
			}
			break;
		case 5:
			cout << endl;
			for (int i = 0; i < 100; i++) {
				if (champ[i].name != " ") {
					champ[i].show();
				}
			}
			break;

		case 6:
			for (int i = 0; i < 100;i++) {
				tmptable[i].name = champ[i].name;
				tmptable[i].hp = champ[i].hp;
				tmptable[i].mp = champ[i].mp;
				tmptable[i].speed = champ[i].speed;
				tmptable[i].range = champ[i].range;
				tmptable[i].position = champ[i].position;
			}// 임시변수 배열에 대입

			for (int i = 0; i < 99; i++) { // 체력이 높은 챔피언 순서대로 교환 알고리즘
				for (int j = i + 1; j < 100; j++) {
					if (champ[i].hp < champ[j].hp) {
						tmp.name = champ[i].name;
						tmp.hp = champ[i].hp;
						tmp.mp = champ[i].mp;
						tmp.speed = champ[i].speed;
						tmp.range = champ[i].range;
						tmp.position = champ[i].position; // 임시변수 tmp에 정보를 옮김

						champ[i].name = champ[j].name;
						champ[i].hp = champ[j].hp;
						champ[i].mp = champ[j].mp;
						champ[i].speed = champ[j].speed;
						champ[i].range = champ[j].range;
						champ[i].position = champ[j].position;

						champ[j].name = tmp.name;
						champ[j].hp = tmp.hp;
						champ[j].mp = tmp.mp;
						champ[j].speed = tmp.speed;
						champ[j].range = tmp.range;
						champ[j].position = tmp.position;
					}
				}
			}

			cout << endl;
			for (int i = 0; i < 100; i++) {
				if (champ[i].name != " ") {
					champ[i].show();
				}
			}// 전부출력 알고리즘

			for (int i = 0; i < 100; i++) {
				champ[i].name = tmptable[i].name;
				champ[i].hp = tmptable[i].hp;
				champ[i].mp = tmptable[i].mp;
				champ[i].speed = tmptable[i].speed;
				champ[i].range = tmptable[i].range;
				champ[i].position = tmptable[i].position;
			}// 원래 변수배열에 담아뒀던 임시변수 태이블 다시 복사
			break;

		case 7:
			cout << endl << "챔피언 순서를 체력이 높은 순서대로 정렬합니다." << endl;
			
			for (int i = 0; i < 99; i++) { // 체력이 높은 챔피언 순서대로 교환 알고리즘
				for (int j = i + 1; j < 100; j++) {
					if (champ[i].hp < champ[j].hp) {
						tmp.name = champ[i].name;
						tmp.hp = champ[i].hp;
						tmp.mp = champ[i].mp;
						tmp.speed = champ[i].speed;
						tmp.range = champ[i].range;
						tmp.position = champ[i].position; // 임시변수 tmp에 정보를 옮김

						champ[i].name = champ[j].name;
						champ[i].hp = champ[j].hp;
						champ[i].mp = champ[j].mp;
						champ[i].speed = champ[j].speed;
						champ[i].range = champ[j].range;
						champ[i].position = champ[j].position;

						champ[j].name = tmp.name;
						champ[j].hp = tmp.hp;
						champ[j].mp = tmp.mp;
						champ[j].speed = tmp.speed;
						champ[j].range = tmp.range;
						champ[j].position = tmp.position;
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