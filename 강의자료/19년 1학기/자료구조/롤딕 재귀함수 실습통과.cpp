#include <iostream>
using namespace std;
int num;
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

bool samecheck(char name1[], char name2[]) { // �̸���
	for (int i = 0; i < 20; i++) {
		if (name1[i] == NULL) break;
		if (!(name1[i] == name2[i])) {
			return false;
		}
	}
	return true;
}

void champserch(lol_dic champ[], char name2[], int i) { // 1�� è�Ǿ� ���� ����
	if (samecheck(champ[i].name, name2)) {
		champ[i].show();
		return;
	}
	champserch(champ, name2, ++i);
}


void insert(lol_dic champ[], int i) { // 2�� è�Ǿ� ���� �Է�
	if (i == num) {
		cout << "\n�Է��Ͻ� �����ʹ� �ѹ���� �����˴ϴ�" << endl;
		cout << "�̸� : "; cin >> champ[num].name;
		cout << "hp : "; cin >> champ[num].hp;
		cout << "mp : "; cin >> champ[num].mp;
		cout << "speed : "; cin >> champ[num].speed;
		cout << "range : "; cin >> champ[num].range;
		cout << "position : "; cin >> champ[num].position;
		cout << num + 1 << "��° è�Ǿ����� ��� �Ǿ����ϴ�." << endl;
		return;
	}
	insert(champ, ++i);
}

void champdel(lol_dic champ[], char name[], int i) {// 3�� è�Ǿ� ���� ����
	if (i == 100) return;
	if (samecheck(champ[i].name, name)) {
		champ[i].del();
		for (i; i < 99; i++) { // ��ĭ�� ����
			for (int j = 0; j < 20; j++) {
				champ[i].name[j] = champ[i + 1].name[j];
				champ[i].position[j] = champ[i + 1].position[j];
			}
			champ[i].hp = champ[i + 1].hp;
			champ[i].mp = champ[i + 1].mp;
			champ[i].speed = champ[i + 1].speed;
			champ[i].range = champ[i + 1].range;
		}
		return;
	}

	champdel(champ, name, ++i);
}

void delposi(lol_dic champ[], char pos[], int i) { // 4�� �Է� ������ è�Ǿ� ���� ����
	if (i == 100)return;
	if (samecheck(champ[i].position, pos)) {
		champ[i].del();
		for (int j = i; j < 99; j++) { // ��ĭ�� ����
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
	delposi(champ, pos, ++i);
}

void printall(lol_dic champ[], int i) { // 5�� è�Ǿ� ���� ���
	if (i == 100) return;
	if (champ[i].name[0] != ' ') {
		champ[i].show();
	}
	printall(champ, ++i);
}

int best = 0;
void printbest(lol_dic champ[], int index, int i) { // 6�� ���� ü���� ���� è�Ǿ� ���
	if (i == 100) {
		champ[index].show();
		return;
	}
	if (best < champ[i].hp) {
		best = champ[i].hp;
		index = i;
	}
	printbest(champ, index, ++i);
}

void sort(lol_dic champ[], int i) { // 7�� è�Ǿ� ü�� ���������� ������
	if (i == 100)return;
	lol_dic tmp;
	for (int j = i + 1; j < 100; j++) {// ü���� ���� è�Ǿ� ������� ��ȯ �˰���
		if (champ[i].hp < champ[j].hp) {
			for (int k = 0; k < 20; k++) {
				tmp.name[k] = champ[i].name[k];
				tmp.position[k] = champ[i].position[k];
			}
			tmp.hp = champ[i].hp;
			tmp.mp = champ[i].mp;
			tmp.speed = champ[i].speed;
			tmp.range = champ[i].range;// �ӽú��� tmp�� ������ �ű�

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
	sort(champ, ++i);
}

int main() {
	cout << "�� ���" << endl;
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
		cout << "6. ü���� ���� ���� è�Ǿ� ����" << endl;
		cout << "7. ü���� ���� è�Ǿ� ������� �����ϱ�" << endl;
		cout << "8. ���α׷� ����" << endl;
		cout << "�Է� : ";

		int an;
		cin >> an;
		char name[20], position[20];
		int hp, mp, speed, range;
		//lol_dic tmptable[100];


		if (!(0 < an&&an < 9)) {
			cout << "\nȮ�� �� �ٽ� �Է����ּ���.\n" << endl;
			continue;
		}

		switch (an)
		{
		case 1:
			cout << "\n������ �� è�Ǿ��� �̸��� �Է��ϼ��� : ";
			cin >> name;
			champserch(champ, name, 0);
			break;

		case 2:
			insert(champ, 0);
			break;
		case 3:
			cout << "\n������ è�Ǿ��� �Է��ϼ��� : ";
			cin >> name;
			champdel(champ, name, 0);
			break;
		case 4:
			cout << "������ �������� �Է��ϼ��� : ";
			cin >> position;
			delposi(champ, position, 0);
			break;
		case 5:
			cout << endl;
			printall(champ, 0);
			break;
		case 6:
			printbest(champ, 0, 0);
			break;

		case 7:
			cout << endl << "è�Ǿ� ������ ü���� ���� ������� �����մϴ�." << endl;
			sort(champ, 0);
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