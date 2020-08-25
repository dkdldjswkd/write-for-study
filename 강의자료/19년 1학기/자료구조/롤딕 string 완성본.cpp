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
		cout << "\nè�Ǿ� �� : " << name << "\nü�� : " << hp << "\n���� : " << mp
			<< "\n�̵��ӵ� : " << speed << "\n��Ÿ� : " << range << "\n�� ������ : " << position
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
			if (champ[i].name == " ") {
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
		string name, position;
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
				if (champ[i].name == name) {
					champ[i].show();
					break;
				}
			}
			break;

		case 2:
			cout << "\n�Է��Ͻ� �����ʹ� �ѹ���� �����˴ϴ�" << endl;
			cout << "�̸� : "; cin >> name;
			cout << "hp : "; cin >> hp;
			cout << "mp : "; cin >> mp;
			cout << "speed : "; cin >> speed;
			cout << "range : "; cin >> range;
			cout << "position : "; cin >> position;
			champ[num].in(name, hp, mp, speed, range, position);
			cout << num + 1 << "��° è�Ǿ����� ��� �Ǿ����ϴ�." << endl;
			break;

		case 3:
			cout << "\n������ è�Ǿ��� �Է��ϼ��� : ";
			cin >> name;
			for (int i = 0; i < 100; i++) {
				if (champ[i].name == name) {
					champ[i].del();
					for (i; i < 99; i++) { // ��ĭ�� ����
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
			cout << "������ �������� �Է��ϼ��� : ";
			cin >> position;
			for (int i = 0; i < 100; i++) {
				if (champ[i].position == position) {
					champ[i].del();
					for (int j = i; j < 99; j++) { // ��ĭ�� ����
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
			}// �ӽú��� �迭�� ����

			for (int i = 0; i < 99; i++) { // ü���� ���� è�Ǿ� ������� ��ȯ �˰���
				for (int j = i + 1; j < 100; j++) {
					if (champ[i].hp < champ[j].hp) {
						tmp.name = champ[i].name;
						tmp.hp = champ[i].hp;
						tmp.mp = champ[i].mp;
						tmp.speed = champ[i].speed;
						tmp.range = champ[i].range;
						tmp.position = champ[i].position; // �ӽú��� tmp�� ������ �ű�

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
			}// ������� �˰���

			for (int i = 0; i < 100; i++) {
				champ[i].name = tmptable[i].name;
				champ[i].hp = tmptable[i].hp;
				champ[i].mp = tmptable[i].mp;
				champ[i].speed = tmptable[i].speed;
				champ[i].range = tmptable[i].range;
				champ[i].position = tmptable[i].position;
			}// ���� �����迭�� ��Ƶ״� �ӽú��� ���̺� �ٽ� ����
			break;

		case 7:
			cout << endl << "è�Ǿ� ������ ü���� ���� ������� �����մϴ�." << endl;
			
			for (int i = 0; i < 99; i++) { // ü���� ���� è�Ǿ� ������� ��ȯ �˰���
				for (int j = i + 1; j < 100; j++) {
					if (champ[i].hp < champ[j].hp) {
						tmp.name = champ[i].name;
						tmp.hp = champ[i].hp;
						tmp.mp = champ[i].mp;
						tmp.speed = champ[i].speed;
						tmp.range = champ[i].range;
						tmp.position = champ[i].position; // �ӽú��� tmp�� ������ �ű�

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


//Search[è�Ǿ��̸�] : �־��� è�Ǿ��� ������ ����Ѵ�.
//Insert : ���ο� è�Ǿ��� ������ �Է¹޾� �����Ѵ�.
//	Delete[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ������ �����Ѵ�.
//	DeleteAll[position] : �־��� ��ġ�� ��� è�Ǿ� ������ �����Ѵ�.
//	PrintAll : ��� è�Ǿ��� ������ �迭�� ����� ������� ����Ѵ�.
//	FindMaxHp : ���� ü���� ū è�Ǿ��� ������ ����Ѵ�.
//	SortByHp : ü���� ū è�Ǿ���� ������� �����Ѵ�.
//