#include <iostream>
using namespace std;

struct item {
	char name[15];
	item* next;		
};

item* Del(item* head, char name[15]) {
	item* temp = new item;
	item* tempprev = new item;
	temp = head;
	if (!strcmp(temp->name, name)) {
		head = temp->next;
		return temp;
	}
	else {
		while (temp->next != 0) {
			tempprev = temp;
			temp = temp->next;
			if (!strcmp(temp->name, name)) {
				tempprev->next = temp->next;
				return temp;
			}
			else return 0;
		}
	}
}

item* Add(item* head, char newname[15]) {
	item* temp = new item;
	if (head == 0) {
		strcpy_s(temp->name, newname);
		temp->next = 0;
		return temp;
	}
	else {
		strcpy_s(temp->name, newname);
		temp->next = head;
		head = temp;
		return head;
	}
}

void Print(item* head) {
	item* x;
	x = head;
	while (x != 0) {
		cout << x->name << endl;
		x = x->next;
	}
}

void main() {
	item* head = 0;
	char bebr[] = "Ibragimova";
	head = Add(head, bebr);
	char name[] = "Medvedev";
	head = Add(head, name);
	Print(head);
	item* x = Del(head, bebr);
	delete x;
	cout << endl << "List after Del" << endl;
	Print(head);
}
