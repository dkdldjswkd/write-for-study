#include <iostream>
#include <string>
using namespace std;
int num;

bool samecheck(char name1[], char name2[]); // 캐릭터 배열이 같은지
void serch(char name[]);//1번
void in(); //2번
void del(); //3번
void delall(); //4번
void printall(); //5번
void besthp();//6번
void sort(int a=1);//7번


struct lol_dic {
	char name[20] = " ";
	int hp = 1;
	int mp = 1;
	int speed = 1;
	int range = 1;
	char position[20] = " ";
	void show() {
		cout << "이름 : " << name << "\n체력 : " << hp
			<< "\n마나 : " << mp << "\n이동속도 : " << speed
			<< "\n사거리 : " << range << "\n포지션 : " << position
			<< endl << endl;
	}
};

struct node {
	lol_dic LOL;
	node* next;
	node* before;
};
node* p, *head = NULL, *old;

void Array2LinkedList(lol_dic champ[]) { // 구조체 배열을 연결리스트화 시킴
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

void nodedel() { // 삭제할 노드를 뺌
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
	cout << "롤 백과" << endl;
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
		}// 비어잇는 방 찾아서 num 에 대입

		//cout << "\n현재 등록되어 있는 챔피언 수 " << num << endl;
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
		//lol_dic tmptable[100];


		if (!(0 < an && an < 9)) {
			cout << "\n확인 후 다시 입력해주세요.\n" << endl;
			continue;
		}

		switch (an)
		{
		case 1:
			cout << "\n정보를 볼 챔피언의 이름을 입력하세요 : ";
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
			cout << endl << "챔피언 순서를 체력이 높은 순서대로 정렬합니다." << endl;
			sort();
			break;
		case 8:
			return 0;
		default:
			break;
		}
	}
}

// 메인문 끝 ------------------------------------------------------------------------------------------------

bool samecheck(char name1[], char name2[]) { // 이름비교
	for (int i = 0; i < 20; i++) {
		if (name1[i] == NULL) break;
		if (!(name1[i] == name2[i])) {
			return false;
		}
	}
	return true;
}

void serch(char name[]) { // 1번 이름으로 정보보기
	while (true) {
		if (samecheck(p->LOL.name, name)) {
			cout << endl;
			p->LOL.show();
			p = head;
			return;
		}
		else if (p->next == head) {
			cout << "찾는 챔피언이 없습니다." << endl;
			return;
		}
		else p = p->next;
	}
}

void in() { // 2번 정보입력
	cout << "\n챔피언 정보를 입력하세요."
		<< endl << "입력하신 정보는 롤 백과에 등록됩니다." << endl;
	node* add = new node[sizeof(node)];
	cout << "이름 : ";
	cin >> add->LOL.name;
	cout << "체력 : ";
	cin >> add->LOL.hp;
	cout << "마나 : ";
	cin >> add->LOL.mp;
	cout << "이동속도 : ";
	cin >> add->LOL.speed;
	cout << "사거리 : ";
	cin >> add->LOL.range;
	cout << "포지션 : ";
	cin >> add->LOL.position;

	add->before = old;
	old->next = add;
	old = add;
	add->next = head;
	sort();
}


void del() { // 3번 정보삭제
	cout << "롤백과에서 삭제할 챔피언을 입력하세요 : ";
	char name[20];
	cin >> name;
	for (p = head;; p = p->next) {
		if (samecheck(p->LOL.name, name)) {
			nodedel();
			//p가 가르키는 노드 메모리를 제거해 줘야함 (미구현
			p = head;
			return;
		}
		else if (p->next == head) {
			cout << "찾는 챔피언이 없습니다." << endl << endl;
			return;
		}

	}
}

void delall() { //4번
	cout << "롤백과에서 삭제할 포지션을 입력하세요 (전부삭제 됩니다.) : ";
	char position[20];
	cin >> position;
	for (p = head;; p = p->next) {
		if (samecheck(p->LOL.position, position)) {
			p->before->next = p->next;
			p->next->before = p->before;
			//p가 가르키는 노드 메모리를 제거해 줘야함 (미구현
			if (p == old)old = old->before;
			if (p == head)head = head->next;
			p = head;
		}
		else if (p->next == head) {
			cout << "삭제 되었습니다." << endl << endl;
			return;
		}
	}
}

void printall() { // 5번 전부출력
	p = head;
	while (true) {
		p->LOL.show();
		p = p->next;
		if (p == head)return;
	}
}

void besthp() { // 6번 가장 체력이 높은 챔피언 보기
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

void sort(int a) { // 7번 체력순으로 정렬
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


//배열에 저장된 데이터를 단일 환형 연결리스트 구조로 바꾸어 저장하는 함수 Array2LinkedList()를 구현하라.


//Search[챔피언이름] : 주어진 챔피언의 정보를 출력한다.
//Insert : 새로운 챔피언의 정보를 입력받아 삽입한다.
//   Delete[챔피언이름] : 주어진 챔피언에 대한 정보를 삭제한다.
//   DeleteAll[position] : 주어진 위치의 모든 챔피언 정보를 삭제한다.
//   PrintAll : 모든 챔피언의 정보를 배열에 저장된 순서대로 출력한다.
//   FindMaxHp : 가장 체력이 큰 챔피언의 정보를 출력한다.
//   SortByHp : 체력이 큰 챔피언부터 순서대로 저장한다.
//