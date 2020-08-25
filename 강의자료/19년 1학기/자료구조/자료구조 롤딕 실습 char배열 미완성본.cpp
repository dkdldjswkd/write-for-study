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
		cout << "\nè�Ǿ� �� : " << name << "\nü�� : " << hp << "\n���� : " << mp
			<< "\n�̵��ӵ� : " << speed << "\n��Ÿ� : " << range << "\n�� ������ : " << position
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
	cout << "�� ���" << endl;
	lol_dic champ[100] =
	{
		{"�׷��̺���", 2115, 1002, 345, 425, "����"}, {"����", 2015, 200, 345, 125, "����"},
		{"�Ƹ�", 2090, 843, 330, 550, "�̵�"}, {"ī�̻�", 2033, 990, 335, 525, "����"},
		{"�ϴ޸�", 1990, 1060, 335, 525, "����"}, {"����", 2070, 960, 340, 550, "�̵�"},
		{"Ƽ��", 2058, 947, 330, 500, "ž"}, {"����", 2048, 0, 340, 175, "ž"},
		{"����", 2100, 997, 345, 125, "����"}, {"������", 2466, 1080, 335, 125, "������"},
		{"�϶����", 2200, 980, 340, 125, "ž"}, {"���", 2276, 780, 345, 125, "����"},
		{"�ٸ��콺", 2282, 780, 340, 125, "ž"}, {"�丯", 2280, 980, 340, 175, "ž"},
		{"��ī����", 1856, 120, 325, 175, "ž"}, {"�ʰ���", 1934, 952, 345, 125, "ž"},
		{"��", 2103, 1150, 330, 550, "����"}, {"����", 2029, 200, 345, 125, "�̵�"},
		{"�˸���Ÿ", 2375, 924, 330, 125, "������"}, {"�ҳ�", 1791, 1105, 325, 550, "������"}
	};

	while (true) {
		int num;
		for (int i = 0; i < 100; i++) {
			if (champ[i].name[0] == ' ') {
				num = i;
				break;
			}
		}// ����մ� �� ã�Ƽ� num �� ����
		cout << "\n���� ��ϵǾ� �ִ� è�Ǿ� �� " << num << endl;
		cout << "1. è�Ǿ� ���� ����" << endl; //�̸����� ã��
		cout << "2. è�Ǿ� ���� �Է��ϱ�" << endl;
		cout << "3. è�Ǿ� �̸����� ���� ����" << endl;
		cout << "4. �Է��ϴ� �������� è�Ǿ� ���� ��λ���" << endl;
		cout << "5. è�Ǿ� ���� ��κ���" << endl;
		cout << "6. ü���� ���� ���� è�Ǿ� ������� ����" << endl;
		cout << "7. ü���� ���� è�Ǿ� ������� �����ϱ�" << endl;
		cout << "8. ���α׷� ����" << endl;
		cout << "�Է� : ";

		int an;
		cin >> an;
		char name[20], position[20];
		int hp, mp, speed, range;
		lol_dic tmp;
		lol_dic tmptable[100];


		if (!(0 < an&&an < 9)) {
			cout << "\nȮ�� �� �ٽ� �Է����ּ���.\n" << endl;
			continue;
		}

		switch (an)
		{
		case 1:
			cout << "\n������ �� è�Ǿ��� �̸��� �Է��ϼ��� : ";
			cin >> name;

			for (int i = 0; i < 100; i++) {
				if (champ[i].name[0] == name[0] && champ[i].name[1] == name[1] && champ[i].name[2] == name[2]) {
					champ[i].show();
					break;
				}
			}
			break;

		case 2:
			cout << "\n�Է��Ͻ� �����ʹ� �ѹ���� �����˴ϴ�" << endl;
			cout << "�̸� : "; cin >> champ[num].name;
			cout << "hp : "; cin >> champ[num].hp;
			cout << "mp : "; cin >> champ[num].mp;
			cout << "speed : "; cin >> champ[num].speed;
			cout << "range : "; cin >> champ[num].range;
			cout << "position : "; cin >> champ[num].position;
			cout << num + 1 << "��° è�Ǿ����� ��� �Ǿ����ϴ�." << endl;
			break;

		case 3:
			//cout << "\n������ è�Ǿ��� �Է��ϼ��� : ";
			//cin >> name;
			//for (int i = 0; i < 100; i++) {
			//	if (champ[i].name == name) {
			//		champ[i].del();
			//		for (i; i < 99; i++) { // ��ĭ�� ����
			//			champ[i].name = champ[i + 1].name;
			//			champ[i].hp = champ[i + 1].hp;
			//			champ[i].mp = champ[i + 1].mp;
			//			champ[i].speed = champ[i + 1].speed;
			//			champ[i].range = champ[i + 1].range;
			//			champ[i].position = champ[i + 1].position;
			//		}
			//	}
			//}
			break;
		case 4:
			//cout << "������ �������� �Է��ϼ��� : ";
			//cin >> position;
			//for (int i = 0; i < 100; i++) {
			//	if (champ[i].position == position) {
			//		champ[i].del();
			//		for (int j = i; j < 99; j++) { // ��ĭ�� ����
			//			champ[j].name = champ[j + 1].name;
			//			champ[j].hp = champ[j + 1].hp;
			//			champ[j].mp = champ[j + 1].mp;
			//			champ[j].speed = champ[j + 1].speed;
			//			champ[j].range = champ[j + 1].range;
			//			champ[j].position = champ[j + 1].position;
			//		}
			//		i--;
			//	}
			//}
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
			//cout << endl << "è�Ǿ� ������ ü���� ���� ������� �����մϴ�." << endl;

			//for (int i = 0; i < 99; i++) { // ü���� ���� è�Ǿ� ������� ��ȯ �˰���
			//	for (int j = i + 1; j < 100; j++) {
			//		if (champ[i].hp < champ[j].hp) {
			//			tmp.name = champ[i].name;
			//			tmp.hp = champ[i].hp;
			//			tmp.mp = champ[i].mp;
			//			tmp.speed = champ[i].speed;
			//			tmp.range = champ[i].range;
			//			tmp.position = champ[i].position; // �ӽú��� tmp�� ������ �ű�

			//			champ[i].name = champ[j].name;
			//			champ[i].hp = champ[j].hp;
			//			champ[i].mp = champ[j].mp;
			//			champ[i].speed = champ[j].speed;
			//			champ[i].range = champ[j].range;
			//			champ[i].position = champ[j].position;

			//			champ[j].name = tmp.name;
			//			champ[j].hp = tmp.hp;
			//			champ[j].mp = tmp.mp;
			//			champ[j].speed = tmp.speed;
			//			champ[j].range = tmp.range;
			//			champ[j].position = tmp.position;
			//		}
			//	}
			//}
			break;
		case 8:
			return 0;
		default:
			break;
		}

	}
}


//Search[è�Ǿ��̸�] : �־��� è�Ǿ��� ������ ����Ѵ�.
//Insert : ���ο� è�Ǿ��� ������ �Է¹޾� �����Ѵ�.
//	Delete[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ������ �����Ѵ�.
//	DeleteAll[position] : �־��� ��ġ�� ��� è�Ǿ� ������ �����Ѵ�.
//	PrintAll : ��� è�Ǿ��� ������ �迭�� ����� ������� ����Ѵ�.
//	FindMaxHp : ���� ü���� ū è�Ǿ��� ������ ����Ѵ�.
//	SortByHp : ü���� ū è�Ǿ���� ������� �����Ѵ�.
//