#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<bits/stdc++.h>
struct ShoppingItem {
	char name[50]; // 商品名称
	int quantity; // 商品数量
	struct ShoppingItem* next; // 指向下一个节点的指针
};

struct ShoppingItem* shoppingList = NULL;
struct ShoppingItem* shoppingList2 = NULL;

//添加商品到购物清单：
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

//从购物清单中移除商品：
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

//查看购物清单
void displayList() {
	struct ShoppingItem* current = shoppingList;
	printf("购物清单:\n");
	while (current != NULL) {
		printf("%s - 数量：%d\n", current->name, current->quantity);
		
		current=current->next;
		
	}
}

//修改购物清单
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

//清空购物清单：
void clearList() {
	while (shoppingList != NULL) {
		
		struct ShoppingItem* temp = shoppingList;
		shoppingList = shoppingList->next;
		
		free(temp);
	}
	printf("清空购物清单\n");
}

//计算购物清单中商品的总数量：
int totalQuantity() {
	struct ShoppingItem* current = shoppingList;
	int total = 0;
	while (current != NULL) {
		
		total += current->quantity;
		current = current->next;
		
	}
	return total;
}

//查找购物清单中的商品：
void findItem(char itemName[]) {
	struct ShoppingItem* current = shoppingList;
	
	printf("查找商品 %s ：\n", itemName);
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			printf("%s - 数量：%d\n", current->name, current->quantity);
			return;
		}
		
		current = current->next;
		
	}
	printf("未找到商品 %s。\n", itemName);
} 

//排序购物清单：
void sortList() {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* nextItem = NULL;
	char tempName[50];
	int tempQuantity;
	
	while (current != NULL) {
		nextItem = current->next;
		
		while (nextItem != NULL) {
			if (strcmp(current->name, nextItem->name) > 0) {
				
				// 交换商品信息
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

//合并购物清单：
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
	struct ShoppingItem* current = *list1;
	
	while (current->next != NULL) {
		current = current->next;
	}
	
	current->next = *list2;
	*list2 = NULL;
}

//删除购物清单中的商品：
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
	
	addItem("铅笔", 20);
	addItem("水笔", 30);        
	addItem("钢笔", 15);
	addItem("毛笔", 10);
	
	printf("添加购物清单：\n");
	displayList(); // 显示购物清单
	
	printf("\n");
	
	updateQuantity("铅笔", 25); // 修改数量为25
	printf("修改“铅笔”数量为25：\n");
	displayList(); // 再次显示购物清单
	
	printf("\n");
	printf("查找“钢笔”：\n");
	findItem("钢笔");
	printf("未查找到物品：\n");
	findItem("羽毛笔");
	printf("\n");
	
	printf("查询物品总数量：\n");
	printf("%d\n",totalQuantity());
	
	removeItem("水笔"); // 移除水笔
	printf("移除水笔：\n");
	displayList(); // 再次显示购物清单
	
	addItem2("羽毛笔", 200);
	addItem2("硬笔", 300);
	addItem2("软笔", 150);
	
	printf("合并两个链表：\n");
	mergeLists(&shoppingList,&shoppingList2);
	
	displayList();
	
	clearList(); // 清空购物清单
	
	addItem("铅笔", 20);
	addItem("水笔", 30);        
	addItem("钢笔", 15);
	addItem("毛笔", 10);
	
	printf("排序购物清单：\n");
	sortList();
	
	displayList();
	
	addItem("铅笔", 20);
	
	deleteItem("铅笔",1);
	printf("删除全部的购物清单上的“铅笔：\n");
	displayList();
	
	return 0;
}


