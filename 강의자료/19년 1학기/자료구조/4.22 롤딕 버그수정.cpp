#include <iostream>
#include <string>
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
		cout << "�̸� : " << name << "\nü�� : " << hp
			<< "\n���� : " << mp << "\n�̵��ӵ� : " << speed
			<< "\n��Ÿ� : " << range << "\n������ : " << position
			<< endl << endl;
	}
};

struct node {
	lol_dic LOL;
	node* next;
	node* before;
};
node* p, * head = NULL, * old=NULL;

void Array2LinkedList(lol_dic champ[]) {
	for (int i = 0;; i++) {
		if (champ[i].name[0] == ' ') {
			return;
		}
		p = new node[sizeof(node)];
		p->LOL = champ[i];
		if (i == 0) {
			head = p;
			old = p;
			p->next = NULL;
			p->before = NULL;
		}
		else {
			old->next = p;
			p->before = old;
			p->next = head;
			head->before = p;
			old = p;
		}
	}
}

bool samecheck(char name1[], char name2[]) { // �̸���
	for (int i = 0; i < 20; i++) {
		if (name1[i] == NULL) break;
		if (!(name1[i] == name2[i])) {
			return false;
		}
	}
	return true;
}

void nodedel(node* p) { // ������ ��带 ��
	if (head == old) { head = NULL, old = NULL, p = NULL; return; }
	if (p == old)old = old->before;
	if (p == head)head = head->next;
	p->before->next = p->next;
	p->next->before = p->before;
}

void addhead(node * p) {
	p->next = head;
	p->before = old;
	old->next = p;
	head->before = p;
	head = p;
}

void addold(node * p) {
	old->next = p;
	p->before = old;
	p->next = head;
	head->before = old;
	old = p;
}

void serch(char name[]) {//1��
	for (p = head;; p = p->next) {
		if (samecheck(p->LOL.name, name)) {
			p->LOL.show();
			return;
		}
		if (p == old) {
			return;
		}
	}
}

void bubble() { //7�� ��������
	lol_dic tmp;
	for (int i = 0; i < 100; i++) {
		for (p = head;; p = p->next) {
			if (p->LOL.hp < p->next->LOL.hp) {
				tmp = p->LOL;
				p->LOL = p->next->LOL;
				p->next->LOL = tmp;
			}
			if (p->next == old) {
				break;
			}
		}
	}
}

void in() { //2��
	p = new node[sizeof(node)];
	cout << "�Է��Ͻ� ������ �ѹ���� ��� �˴ϴ�." << endl;
	cout << "�̸� : "; cin >> p->LOL.name;
	cout << "ü�� : "; cin >> p->LOL.hp;
	cout << "���� : "; cin >> p->LOL.mp;
	cout << "�̵��ӵ� : "; cin >> p->LOL.speed;
	cout << "��Ÿ� : "; cin >> p->LOL.range;
	cout << "������ : "; cin >> p->LOL.position;
	if (head == NULL && old == NULL) {
		head = p;
		old = p;
		p->next = NULL;
		p->before = NULL;
		return;
	}
	addold(p);
	bubble();
}

void del() {//3��
	if (head == NULL && old == NULL) { cout << "������ �����ϴ�." << endl; return; }
	char name[20];
	cout << "������ è�Ǿ� �̸��� �Է� �ϼ��� : ";
	cin >> name;
	for (p = head;; p = p->next) {
		if (samecheck(p->LOL.name, name)) {
			nodedel(p);
		}
		if (p == old)return;
	}
	bubble();
}

void delall() {//4��
	if (head == NULL && old == NULL) { cout << "������ �����ϴ�." << endl; return; }
	char position[20];
	cout << "������ �������� �Է� �ϼ��� : ";
	cin >> position;
	for (p = head;; p = p->next) {
		if (samecheck(p->LOL.position, position)) {
			nodedel(p);
			if (head == NULL && old == NULL)return;
		}
		if (p == old)return;
	}
	bubble();
}

void printall() { // 5��
	if (old == NULL && head == NULL) {
		cout << "�Էµ� ���� �����ϴ�." << endl;
		return;
	}
	for (p = head;; p = p->next) {
		cout << endl;
		p->LOL.show();
		if (p == old) {
			break;
		}
	}
}

void showhp() { // 6��
	int hp = 0;
	for (p = head;; p = p->next) {
		if (p->LOL.hp > hp)hp = p->LOL.hp;
		if (p == old)break;
	}
	for (p = head;; p = p->next) {
		if (hp == p->LOL.hp) {
			p->LOL.show();
			return;
		}
		if (p == old)return;
	}
}


int main() {
	cout << "�� ���" << endl;
	lol_dic champ[100] =
	{
	   {"Ahri", 2090, 843, 330, 550, "Mid"} , {"LeeSin", 2015, 200, 345, 125, "Jungle"},
	   {"Graves", 2115, 1002, 345, 425, "Jungle"}, {"Kaisa", 2033, 990, 335, 525, "Ad"},
	   {"Nidalee", 1990, 1060, 335, 525, "Jungle"}, {"Sona", 1791, 1105, 325, 550, "supporter"},
	   {"Teemo", 2058, 947, 330, 500, "Top"}, {"Garen", 2048, 0, 340, 175, "Top"},
	   {"Nunu", 2100, 997, 345, 125, "Jungle"}, {"Galio", 2466, 1080, 335, 125, "supporter"},
	   {"Illaoi", 2200, 980, 340, 125, "Top"}, {"Udyr", 2276, 780, 345, 125, "Jungle"},
	   {"Darius", 2282, 780, 340, 125, "Top"}, {"Yorick", 2280, 980, 340, 175, "Top"},
	   {"Mordekaiser", 1856, 120, 325, 175, "Top"}, {"Chogath", 1934, 952, 345, 125, "Top"},
	   {"Jin", 2103, 1150, 330, 550, "Ad"}, {"Zed", 2029, 200, 345, 125, "Mid"},
	   {"Alistar", 2375, 924, 330, 125, "supporter"}, {"Nico", 2070, 960, 340, 550, "Mid"}
	};


	Array2LinkedList(champ);


	while (true) {
		for (int i = 0; i < 100; i++) {
			if (champ[i].name[0] == ' ') {
				num = i;
				break;
			}
		}// ����մ� �� ã�Ƽ� num �� ����

		//cout << "\n���� ��ϵǾ� �ִ� è�Ǿ� �� " << num << endl;
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


		if (!(0 < an && an < 9)) {
			cout << "\nȮ�� �� �ٽ� �Է����ּ���.\n" << endl;
			continue;
		}

		switch (an)
		{
		case 1:
			cout << "\n������ �� è�Ǿ��� �̸��� �Է��ϼ��� : ";
			cin >> name;
			serch(name);
			break;

		case 2:
			in();
			break;
		case 3:
			del();
			break;
		case 4:
			delall();
			break;
		case 5:
			printall();
			break;
		case 6:
			showhp();
			break;
		case 7:
			cout << endl << "è�Ǿ� ������ ü���� ���� ������� �����մϴ�." << endl;
			bubble();
			//sort();
			break;
		case 8:
			return 0;
		default:
			break;
		}
	}
}

// ���ι� �� ------------------------------------------------------------------------------------------------
//�迭�� ����� �����͸� ���� ȯ�� ���Ḯ��Ʈ ������ �ٲپ� �����ϴ� �Լ� Array2LinkedList()�� �����϶�.


//Search[è�Ǿ��̸�] : �־��� è�Ǿ��� ������ ����Ѵ�.
//Insert : ���ο� è�Ǿ��� ������ �Է¹޾� �����Ѵ�.
//   Delete[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ������ �����Ѵ�.
//   DeleteAll[position] : �־��� ��ġ�� ��� è�Ǿ� ������ �����Ѵ�.
//   PrintAll : ��� è�Ǿ��� ������ �迭�� ����� ������� ����Ѵ�.
//   FindMaxHp : ���� ü���� ū è�Ǿ��� ������ ����Ѵ�.
//   SortByHp : ü���� ū è�Ǿ���� ������� �����Ѵ�.
//