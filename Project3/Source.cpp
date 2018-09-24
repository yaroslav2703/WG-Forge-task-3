#include <iostream>

using namespace std;

void dob();//добавление диалога в чат
void vivod();//вывод чата на экран
void prov();//проверка и исправление совпадений

struct adresat {
	char name[10];
	adresat *prev = nullptr;
	adresat *next = nullptr;
};

adresat *p = new adresat;//указатель на самый верхний диалог
adresat *p2;//мнимый самый верхний диалог
adresat *k;//указатель для вывода
adresat *n;//временный указатель
adresat *d;//временный указатель
adresat *g;//временный указатель
adresat *sor;//указатель для удаления


int main() {
	
	int n;//количество сообщений
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
		
	if (p == nullptr) {//если список диалогов пустой
		cin >> t->name;
		p = t;
	}
	else {//если диалоги уже есть
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


	while (p2 != nullptr) {//цикл меняющий диалог, копии которого будем искать
		n = p2;
		d = n->prev;
		g = n;
		int flag = 0;//если флаг 0, то диалоги совпали
		while (d != nullptr) {//цикл, который все диалоги сравнивает с нашим ранее выбранным

			flag = 0;


			for (int i = 0; i < 10; i++) {//проверка на одинаковые диалоги в истории чата
				if (p2->name[i] != d->name[i]) {
					flag = 1;
					break;
				}
				else {
					continue;
				}
			}
			if (flag == 0) {//удаляем повторное сообщение из чата
				g = d->prev;
				if (g != nullptr) {//если нужно удалить самое "старое" сообщение
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