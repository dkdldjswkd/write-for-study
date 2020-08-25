#include <iostream>
#include <string>
using namespace std;
int num;

bool samecheck(char name1[], char name2[]); // ĳ���� �迭�� ������
void serch(char name[]);//1��
void in(); //2��
void del(); //3��
void delall(); //4��
void printall(); //5��
void besthp();//6��
void sort(int a=1);//7��


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
node* p, *head = NULL, *old;

void Array2LinkedList(lol_dic champ[]) { // ����ü �迭�� ���Ḯ��Ʈȭ ��Ŵ
	for (int i = 0; i < 100; i++) {
		if (champ[i].name[0] == ' ') {
			p->next = head;
			head->before = p;
			p = head;
			return;
		}
		p = new node[sizeof(node)];
		if (i == 0) { head = p, old = p; }
		else { p->before = old, old->next = p, old = p; }
		p->LOL = champ[i];
	}
}

void nodedel() { // ������ ��带 ��
	if (p == old)old = old->before;
	if (p == head)head = head->next;
	p->before->next = p->next;
	p->next->before = p->before;
}

void addhead() {
	p->next = head;
	p->before = old;
	old->next = p;
	head->before = p;
	head = p;
}

void addold() {
	old->next = p;
	p->before = old;
	p->next = head;
	head->before = old;
	old = p;
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
			cout << endl;
			printall();
			break;
		case 6:
			besthp();
			break;
		case 7:
			cout << endl << "è�Ǿ� ������ ü���� ���� ������� �����մϴ�." << endl;
			sort();
			break;
		case 8:
			return 0;
		default:
			break;
		}
	}
}

// ���ι� �� ------------------------------------------------------------------------------------------------

bool samecheck(char name1[], char name2[]) { // �̸���
	for (int i = 0; i < 20; i++) {
		if (name1[i] == NULL) break;
		if (!(name1[i] == name2[i])) {
			return false;
		}
	}
	return true;
}

void serch(char name[]) { // 1�� �̸����� ��������
	while (true) {
		if (samecheck(p->LOL.name, name)) {
			cout << endl;
			p->LOL.show();
			p = head;
			return;
		}
		else if (p->next == head) {
			cout << "ã�� è�Ǿ��� �����ϴ�." << endl;
			return;
		}
		else p = p->next;
	}
}

void in() { // 2�� �����Է�
	cout << "\nè�Ǿ� ������ �Է��ϼ���."
		<< endl << "�Է��Ͻ� ������ �� ����� ��ϵ˴ϴ�." << endl;
	node* add = new node[sizeof(node)];
	cout << "�̸� : ";
	cin >> add->LOL.name;
	cout << "ü�� : ";
	cin >> add->LOL.hp;
	cout << "���� : ";
	cin >> add->LOL.mp;
	cout << "�̵��ӵ� : ";
	cin >> add->LOL.speed;
	cout << "��Ÿ� : ";
	cin >> add->LOL.range;
	cout << "������ : ";
	cin >> add->LOL.position;

	add->before = old;
	old->next = add;
	old = add;
	add->next = head;
	sort();
}


void del() { // 3�� ��������
	cout << "�ѹ������ ������ è�Ǿ��� �Է��ϼ��� : ";
	char name[20];
	cin >> name;
	for (p = head;; p = p->next) {
		if (samecheck(p->LOL.name, name)) {
			nodedel();
			//p�� ����Ű�� ��� �޸𸮸� ������ ����� (�̱���
			p = head;
			return;
		}
		else if (p->next == head) {
			cout << "ã�� è�Ǿ��� �����ϴ�." << endl << endl;
			return;
		}

	}
}

void delall() { //4��
	cout << "�ѹ������ ������ �������� �Է��ϼ��� (���λ��� �˴ϴ�.) : ";
	char position[20];
	cin >> position;
	for (p = head;; p = p->next) {
		if (samecheck(p->LOL.position, position)) {
			p->before->next = p->next;
			p->next->before = p->before;
			//p�� ����Ű�� ��� �޸𸮸� ������ ����� (�̱���
			if (p == old)old = old->before;
			if (p == head)head = head->next;
			p = head;
		}
		else if (p->next == head) {
			cout << "���� �Ǿ����ϴ�." << endl << endl;
			return;
		}
	}
}

void printall() { // 5�� �������
	p = head;
	while (true) {
		p->LOL.show();
		p = p->next;
		if (p == head)return;
	}
}

void besthp() { // 6�� ���� ü���� ���� è�Ǿ� ����
	cout << endl;
	int hp = 0;
	p = head;
	while (true) {
		if (p->LOL.hp > hp) {
			hp = p->LOL.hp;
		}
		p = p->next;
		if (p->next == head) break;
	}
	p = head;
	while (true) {
		if (p->LOL.hp == hp) {
			p->LOL.show();
			break;
		}
		p = p->next;
	}
}

void sort(int a) { // 7�� ü�¼����� ����
	int hp = 0;
	lol_dic tmp;
	node* p2 = head;
	p = head;

	while (1) {
		for (p;; p = p->next) {
			if (p->LOL.hp > hp)hp = p->LOL.hp;
			if (p == old)break;
		}
		for (p = head;; p = p->next) {
			if (hp == p->LOL.hp) {
				tmp = p2->LOL;
				p2->LOL = p->LOL;
				p->LOL = tmp;
				p2 = p2->next;
				hp = 0;
				break;
			}
		}
		p = head;
		for (int i = 0; i < a; i++) {
			p = p->next;
		}
		if (p == old)return;
		a++;
	}
}


//�迭�� ����� �����͸� ���� ȯ�� ���Ḯ��Ʈ ������ �ٲپ� �����ϴ� �Լ� Array2LinkedList()�� �����϶�.


//Search[è�Ǿ��̸�] : �־��� è�Ǿ��� ������ ����Ѵ�.
//Insert : ���ο� è�Ǿ��� ������ �Է¹޾� �����Ѵ�.
//   Delete[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ������ �����Ѵ�.
//   DeleteAll[position] : �־��� ��ġ�� ��� è�Ǿ� ������ �����Ѵ�.
//   PrintAll : ��� è�Ǿ��� ������ �迭�� ����� ������� ����Ѵ�.
//   FindMaxHp : ���� ü���� ū è�Ǿ��� ������ ����Ѵ�.
//   SortByHp : ü���� ū è�Ǿ���� ������� �����Ѵ�.
//