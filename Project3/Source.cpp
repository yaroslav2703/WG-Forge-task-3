#include <iostream>

using namespace std;

void dob();//���������� ������� � ���
void vivod();//����� ���� �� �����
void prov();//�������� � ����������� ����������

struct adresat {
	char name[10];
	adresat *prev = nullptr;
	adresat *next = nullptr;
};

adresat *p = new adresat;//��������� �� ����� ������� ������
adresat *p2;//������ ����� ������� ������
adresat *k;//��������� ��� ������
adresat *n;//��������� ���������
adresat *d;//��������� ���������
adresat *g;//��������� ���������
adresat *sor;//��������� ��� ��������


int main() {
	
	int n;//���������� ���������
	cin >> n;
	p = nullptr;
	for (int i=0; i < n;i++) {
		dob();
	}
	
	prov();
	vivod();
	system("pause");
}



void dob() {
	adresat *t = new adresat;
		
	if (p == nullptr) {//���� ������ �������� ������
		cin >> t->name;
		p = t;
	}
	else {//���� ������� ��� ����
		cin >> t->name;
		t->prev = p;
		p->next = t;
		p = t;
	}

}

void vivod() {
	
	while (p != nullptr) {
		k = p->prev;
		cout << p->name << endl;
		p = k;
		
	}
}

void prov() {
	p2 = p;


	while (p2 != nullptr) {//���� �������� ������, ����� �������� ����� ������
		n = p2;
		d = n->prev;
		g = n;
		int flag = 0;//���� ���� 0, �� ������� �������
		while (d != nullptr) {//����, ������� ��� ������� ���������� � ����� ����� ���������

			flag = 0;


			for (int i = 0; i < 10; i++) {//�������� �� ���������� ������� � ������� ����
				if (p2->name[i] != d->name[i]) {
					flag = 1;
					break;
				}
				else {
					continue;
				}
			}
			if (flag == 0) {//������� ��������� ��������� �� ����
				g = d->prev;
				if (g != nullptr) {//���� ����� ������� ����� "������" ���������
					g->next = n;
				}
				n->prev = g;
				sor = d;
				d = g;
				if (p2->prev == d) {
					p2->prev == g;
				}
				delete sor;
				continue;
			}
			n = d;
			d = n->prev;

		}
		n = p2->prev;
		p2 = n;
	}

}