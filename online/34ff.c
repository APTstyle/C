#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
struct LinkList{
	struct LinkList* left;
	struct LinkList* right;
	int data;
};

int max(int a, int b){
	return a > b ? a : b;
}

void create(struct LinkList** ll){
	(*ll)->left = NULL;
	(*ll)->right = NULL;
	(*ll)->data = 0;
}

void insertLeft(struct LinkList** ll, int data){
	struct LinkList* newNode = calloc(1, sizeof(struct LinkList));
	struct LinkList* temp = *ll;
	if((*ll) == NULL){
		newNode->right = NULL;
		newNode->data = data;
		*ll = newNode;
		return;
	}
	while(temp->left != NULL){
		temp = temp->left; 
	}
	newNode->data = data;
	newNode->right = NULL;
	temp->left = newNode;
	newNode->right = temp;
}

void insertRight(struct LinkList** ll, int data){
	struct LinkList* newNode = calloc(1, sizeof(struct LinkList));
	struct LinkList* temp = *ll;
	if((*ll) == NULL){
		newNode->right = NULL;
		newNode->data = data;
		*ll = newNode;
		return;
	}
	while(temp->right != NULL){
		temp = temp->right;
	}
	create(&newNode);
	newNode->data = data;
	temp->right = newNode;
	newNode->left = temp;
}

int pop_left(struct LinkList** ll){
    struct LinkList* temp = *ll;
    while(temp->left != NULL){
        temp = temp->left;
    }
    int val = 0;
    if(temp == *ll){
        val = (*ll)->data;
        *ll = temp->right;
        (*ll)->left = NULL;
        free(temp);
    }else{
        val = temp->data;
        temp->right->left = NULL;
        free(temp->right->left);
    }
    return val;
}


void print_linkedlist(struct LinkList** ll){
	struct LinkList* temp = *ll;
	while(temp->left != NULL){
		temp = temp->left;
	}
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->right;
	}
	printf("\n");
}

int size(struct LinkList* ll){
	struct LinkList* temp = ll;
	int count = 0;
	while(temp->left != NULL){
		temp = temp->left;
	}
	while(temp != NULL){
		count += 1;
		temp = temp->right;
	}
	return count;
}

int findIndexFromLeft(struct LinkList* ll, int index){
	struct LinkList* temp = ll;
	while(temp->left != NULL){
		temp = temp->left;
	}
	for(int i = 0; i < index; i++){
		temp = temp->right;
	}
	return temp->data;
}

int writeData(char* data, int** target){
	char* pch = strtok(data, " ");
	int size = 0;
	while(pch != NULL){
		(*target)[size] = atoi(pch);
		pch = strtok(NULL, " ");
		size += 1;
	}
	return size;
}

struct LinkList* add(struct LinkList* a, struct LinkList* b){
	int sizeA = size(a);
	int sizeB = size(b);
	for(int i = sizeA; i < max(sizeA, sizeB); i++){
		insertLeft(&a, 0);
	}
	for(int i = sizeB; i < max(sizeA, sizeB); i++){
		insertLeft(&b, 0);
	}
	struct LinkList* sum = NULL;
	for(int i = 0; i < max(sizeA, sizeB); i++){
		insertRight(&sum, findIndexFromLeft(a, i) + findIndexFromLeft(b, i));
	}
	while(findIndexFromLeft(sum, 0) == 0 && size(sum) > 1){
		pop_left(&sum);
	}
	return sum;
}

struct LinkList* subtract(struct LinkList* a, struct LinkList* b){
	int sizeA = size(a);
	int sizeB = size(b);
	for(int i = sizeA; i < max(sizeA, sizeB); i++){
		insertLeft(&a, 0);
	}
	for(int i = sizeB; i < max(sizeA, sizeB); i++){
		insertLeft(&b, 0);
	}
	struct LinkList* sum = NULL;
	for(int i = 0; i < max(sizeA, sizeB); i++){
		insertRight(&sum, findIndexFromLeft(a, i) - findIndexFromLeft(b, i));
	}
	while(findIndexFromLeft(sum, 0) == 0 && size(sum) > 1){
		pop_left(&sum);
	}
	return sum;
}

struct LinkList* multiple(struct LinkList* a, struct LinkList* b){
	int sizeA = size(a);
	int sizeB = size(b);
	struct LinkList* result = calloc(1, sizeof(struct LinkList));
	for(int i = sizeB-1; i >= 0; i--){
		struct LinkList* temp = NULL;
		for(int j = 0; j < sizeA; j++){
			insertRight(&temp, findIndexFromLeft(a, j)*(findIndexFromLeft(b, i)));
		}
		for(int j = 0; j < sizeB-1-i; j++){
			insertRight(&temp, 0);
		}
		result = add(result, temp); 
	}
	while(findIndexFromLeft(result, 0) == 0 && size(result) > 1){
		pop_left(&result);
	}
	return result;
}

int main(){
	char* data = calloc(0100, sizeof(char));
	int* a = calloc(1000, sizeof(int));
	int* b = calloc(1000, sizeof(int));
	struct LinkList* linkedListA = NULL;
	struct LinkList* linkedListB = NULL;
	gets(data);
	int sizeA = writeData(data, &a);
	data = calloc(1000, sizeof(char));
	gets(data);
	int sizeB = writeData(data, &b);
	for(int i = 0; i < sizeA; i++){
		insertRight(&linkedListA, a[i]);
	}
	for(int i = 0; i < sizeB; i++){
		insertRight(&linkedListB, b[i]);
	}
	struct LinkList* add_ll = add(linkedListA, linkedListB);
	struct LinkList* subtract_ll = subtract(linkedListA, linkedListB);
	struct LinkList* multiple_ll = multiple(linkedListA, linkedListB);
	print_linkedlist(&add_ll);
	print_linkedlist(&subtract_ll);
	print_linkedlist(&multiple_ll);
	return 0;
}