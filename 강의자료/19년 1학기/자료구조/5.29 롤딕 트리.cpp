#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

struct champ {
	string position;
	string name;
	int hp;
	int offense;
	int defense;
	void show() {
		cout << "포지션 : " << position << endl;
		cout << "이름 : " << name << endl;
		cout << "체력 : " << hp << endl;
		cout << "공격력 : " << offense << endl;
		cout << "방어력 : " << defense << endl;
	}
};

struct node {
	champ data;
	node* left;
	node* right;
};

node* p, * head, * tail;

void SortByName_SL(int n) {//1번
	clock_t begin, end;
	begin = clock();

	champ tmp;
	p = head;
	for (int i = 0; i < n; i++) {
		for (p=head;; p=p->right) {
			if (p->data.name > p->right->data.name) {
				tmp = p->data;
				p->data = p->right->data;
				p->right->data = tmp;
			}
			if (p->right == tail)break;
		}
	}

	end = clock();
	cout << "SortByName_SL 수행시간 : " << ((end - begin) / CLOCKS_PER_SEC) << endl;
}

void printall() { // 헤드부터 오른쪽으로 탐색함
	for (p = head;; p = p->right) {
		p->data.show(); cout << endl;
		if (p == tail)return;
	}
}

void SortByName_BT() { // 2번 7번??
	clock_t begin, end;
	begin = clock();

	node* tmp = head;
	for (p = head->right;;p=p->right) {
		p->left->right = NULL;
		p->left->left = NULL;
		while (true) {	
			if (tmp->data.name < p->data.name) {
				if (tmp->right == NULL) {
					tmp->right = p;
					break;
				}					
				else {
					tmp = tmp->right;
				}
			}
			else if(p->data.name < tmp->data.name) {
				if (tmp->left == NULL) {
					tmp->left = p;
					break;
				}
				else {
					tmp = tmp->left;
				}
			}
		}
		if (p == tail) {
			p->left = NULL;
			p->right = NULL;
			break;
		}
	}

	end = clock();
	cout << "SortByName_BT() 수행시간 : " << ((end - begin) / CLOCKS_PER_SEC) << endl;
}

void Insert_BT(node newnode) {//4번
	clock_t begin, end;
	begin = clock();

	node* tmp = head;
		while (true) {
			if (tmp->data.name < newnode.data.name) {
				if (tmp->right == NULL) {
					tmp->right = &newnode;
					break;
				}
				else {
					tmp = tmp->right;
				}
			}
			else if (newnode.data.name < tmp->data.name) {
				if (tmp->left == NULL) {
					tmp->left = &newnode;
					break;
				}
				else {
					tmp = tmp->left;
				}
			}
		}

		end = clock();
		cout << "Insert_BT() 수행시간 : " << ((end - begin) / CLOCKS_PER_SEC) << endl;
}

int main() {
	string rs;
	int ri;
	bool first = true;
	int n=0;
	ifstream in("LOLDic.txt");

	while (!in.eof()) {
		p = new node;
		n++;

		if (first) {
			head = p;
			tail = p;
			first = false;
		}
		else {
			tail->right = p;
			p->left = tail;
			tail = p;
		}

		in >> rs;
		p->data.position = rs;
		in >> rs;
		p->data.name = rs;
		in >> ri;
		p->data.hp = ri;
		in >> ri;
		p->data.offense = ri;
		in >> ri;
		p->data.defense = ri;

		//if (in.eof()) {
		//	p->right = head;
		//	head->left = p;
		//}
	}//메모장 데이터 연결리스트로 구현

	SortByName_BT();

}