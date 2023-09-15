#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<bits/stdc++.h>
struct ShoppingItem {
	char name[50]; // ��Ʒ����
	int quantity; // ��Ʒ����
	struct ShoppingItem* next; // ָ����һ���ڵ��ָ��
};

struct ShoppingItem* shoppingList = NULL;
struct ShoppingItem* shoppingList2 = NULL;

//�����Ʒ�������嵥��
void addItem(char itemName[], int itemQuantity) {
	struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	
	newItem->quantity = itemQuantity;
	newItem->next = NULL;
	strcpy(newItem->name, itemName);
	
	if (shoppingList == NULL) {
		shoppingList = newItem;
	} else {
		struct ShoppingItem* current = shoppingList;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newItem;
	}
}

void addItem2(char itemName[], int itemQuantity) {
	struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	
	newItem->quantity = itemQuantity;
	newItem->next = NULL;
	strcpy(newItem->name, itemName);
	
	if (shoppingList2 == NULL) {
		shoppingList2 = newItem;
	} else {
		struct ShoppingItem* current = shoppingList2;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newItem;
	}
}

//�ӹ����嵥���Ƴ���Ʒ��
void removeItem(char itemName[]) {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* previous = NULL;
	
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			if (previous != NULL) {
				previous->next = current->next;
			} else {
				shoppingList = current->next;
			}
			free(current);
			break;
		}
		
		previous = current;
		current = current->next;
	}
}

//�鿴�����嵥
void displayList() {
	struct ShoppingItem* current = shoppingList;
	printf("�����嵥:\n");
	while (current != NULL) {
		printf("%s - ������%d\n", current->name, current->quantity);
		
		current=current->next;
		
	}
}

//�޸Ĺ����嵥
void updateQuantity(char itemName[], int newItemQuantity) {
	struct ShoppingItem* current = shoppingList;
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			
			current->quantity = newItemQuantity;
			
			break;
		}
		current = current->next;
	}
}

//��չ����嵥��
void clearList() {
	while (shoppingList != NULL) {
		
		struct ShoppingItem* temp = shoppingList;
		shoppingList = shoppingList->next;
		
		free(temp);
	}
	printf("��չ����嵥\n");
}

//���㹺���嵥����Ʒ����������
int totalQuantity() {
	struct ShoppingItem* current = shoppingList;
	int total = 0;
	while (current != NULL) {
		
		total += current->quantity;
		current = current->next;
		
	}
	return total;
}

//���ҹ����嵥�е���Ʒ��
void findItem(char itemName[]) {
	struct ShoppingItem* current = shoppingList;
	
	printf("������Ʒ %s ��\n", itemName);
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			printf("%s - ������%d\n", current->name, current->quantity);
			return;
		}
		
		current = current->next;
		
	}
	printf("δ�ҵ���Ʒ %s��\n", itemName);
} 

//�������嵥��
void sortList() {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* nextItem = NULL;
	char tempName[50];
	int tempQuantity;
	
	while (current != NULL) {
		nextItem = current->next;
		
		while (nextItem != NULL) {
			if (strcmp(current->name, nextItem->name) > 0) {
				
				// ������Ʒ��Ϣ
				strcpy(tempName, current->name);
				strcpy(current->name, nextItem->name);
				strcpy(nextItem->name, tempName);
				
				tempQuantity = current->quantity;
				current->quantity = nextItem->quantity;
				nextItem->quantity = tempQuantity;
			}
			nextItem = nextItem->next;
		}
		current = current->next;
	}
}

//�ϲ������嵥��
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
	struct ShoppingItem* current = *list1;
	
	while (current->next != NULL) {
		current = current->next;
	}
	
	current->next = *list2;
	*list2 = NULL;
}

//ɾ�������嵥�е���Ʒ��
void deleteItem(char itemName[], int deleteAll) {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* prev = NULL;
	
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			if (prev == NULL) {
				struct ShoppingItem* temp = shoppingList;
				
				shoppingList = shoppingList->next;
				
				free(temp);
				if (!deleteAll) break;
			} else {
				
				prev->next = current->next;
				
				free(current);
				current = prev->next;
				if (!deleteAll) break;
			}
		} else {
			prev = current;
			current = current->next;
		}
	}
}

int main() {
	
	addItem("Ǧ��", 20);
	addItem("ˮ��", 30);        
	addItem("�ֱ�", 15);
	addItem("ë��", 10);
	
	printf("��ӹ����嵥��\n");
	displayList(); // ��ʾ�����嵥
	
	printf("\n");
	
	updateQuantity("Ǧ��", 25); // �޸�����Ϊ25
	printf("�޸ġ�Ǧ�ʡ�����Ϊ25��\n");
	displayList(); // �ٴ���ʾ�����嵥
	
	printf("\n");
	printf("���ҡ��ֱʡ���\n");
	findItem("�ֱ�");
	printf("δ���ҵ���Ʒ��\n");
	findItem("��ë��");
	printf("\n");
	
	printf("��ѯ��Ʒ��������\n");
	printf("%d\n",totalQuantity());
	
	removeItem("ˮ��"); // �Ƴ�ˮ��
	printf("�Ƴ�ˮ�ʣ�\n");
	displayList(); // �ٴ���ʾ�����嵥
	
	addItem2("��ë��", 200);
	addItem2("Ӳ��", 300);
	addItem2("���", 150);
	
	printf("�ϲ���������\n");
	mergeLists(&shoppingList,&shoppingList2);
	
	displayList();
	
	clearList(); // ��չ����嵥
	
	addItem("Ǧ��", 20);
	addItem("ˮ��", 30);        
	addItem("�ֱ�", 15);
	addItem("ë��", 10);
	
	printf("�������嵥��\n");
	sortList();
	
	displayList();
	
	addItem("Ǧ��", 20);
	
	deleteItem("Ǧ��",1);
	printf("ɾ��ȫ���Ĺ����嵥�ϵġ�Ǧ�ʣ�\n");
	displayList();
	
	return 0;
}


