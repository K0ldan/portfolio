#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>
#include <stdint.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996) 
void l1()
{
	printf("������ ���\n");
}
void l2()
{
	int moloko = 75 * 22;
	float kolbassa = 194.442 * 5, sosiski = 214.544 * 4, sardel = 309.32;
	long double xleb = 25.5 * 7, sum;
	sum = moloko + kolbassa + sosiski + sardel + xleb;
	printf("%.2Lf\n", sum);
}

void l3() {
	int k;
	printf("������� ��� -> ");
	scanf_s("%d", &k);
	if (k % 4 == 0) printf("��� ����������\n");
	else printf("��� �� ����������\n");
}

void l4() {
	int a, b;
	printf("������� ����� A -> ");
	scanf_s("%d", &a);
	printf("������� ����� B -> ");
	scanf_s("%d", &b);
	printf("\n%d * %d = ", a, b);
	int mul = 0;
	for (int i = 0; i < b; i++) {
		mul += a;
	}
	printf("%d\n", mul);
}
void lab2()
{
	int k;
	FILE* z = fopen("input.txt", "r");
	FILE* p = fopen("output.txt", "w");
	while (fscanf(z, "%d", &k) != EOF)
	{
		if (k % 2 == 0)
		{
			printf(" %d\n", k);
			fprintf(p, " %d\n", k);
		}
		else
		{
			printf("%d\n", k);
			fprintf(p, "%d\n", k);
		}
	}
	fclose(z);
	fclose(p);
}
void lab3()

{
	int G;
	int g;
	int a[100];
	int i;
	scanf_s("%d", &g);
	for (G = 0; G < 100; G++) {
		a[G] = rand();
	}
	for (i = 0; i < 100; i++) {
		if (g > a[i])
		{
			printf("%d\n", a[i]);
		}
	}
}
void lab4()
{
	int* matrix;
	int i, j;
	int a, b;
	int min, max;
	int k = 0;
	int v = 0;
	int p = 0;

	printf("%s\n", "������� ������� ��������� �����");
	scanf_s("%d", &min);
	printf("%s\n", "������� �������� ��������� �����");
	scanf_s("%d", &max);
	if (max >= min)
	{
		max = max - min + 1;
		printf("%s\n", "������� ���-�� �����");
		scanf_s("%d", &a);
		printf("%s\n", "������� ���-�� ��������");
		scanf_s("%d", &b);

		matrix = (int*)malloc(a * b * sizeof(int));

		for (i = 0; i < a; i++)
		{
			for (j = 0; j < b; j++)
			{

				*(matrix + i * b + j) = min + rand() % max;
			}

		}
		for (i = 0; i < a; i++)
		{
			for (j = 0; j < b; j++)
			{
				printf("%5d", *(matrix + i * b + j));
			}
			printf("\n");
		}

		for (i = 0; i < a; i++)
		{
			for (j = 0; j < b; j++)
			{
				if (*(matrix + i * b + j) != 0)
				{
					v += 1;
				}
				if (*(matrix + i * b + j) == 0)
				{
					p += 1;
				}

			}
			if (v == b)
			{
				k += 1;
				printf("%s", "������ �����");
				printf("%d\n", i + 1);
			}
			v = 0;
		}
		printf("%s\n", "���-�� �� ������� �����");
		printf("%d\n", k);
		printf("%d\n", p);
	}



}
void laba5() {
	FILE* f; fopen_s(&f, "alfa.txt", "r+");
	char string[1000];
	char alphabet[] = { '�', '�', '�', '�', '�', '�', '�', '�'
	, '�', '�', '�', '�', '�', '�', '�', '�'
	, '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�'
	, '�', '�', '�', '�', '�', '�' };
	int charnomer = 0, position = 0, check = 0;
	rewind(f);
	fscanf_s(f, ".", &string);
	fgets(string, 1000, f);
	for (int i = 0; i < sizeof(string); i++) {
		if (string[i] == 46) check = 1;
		if (string[i] != alphabet[i]) {
			position = i + 1;
			charnomer = string[i]; break;
		}
	}
	if (check) printf(" ���� �� ����������� �������");
	else printf("������� ������� ������� �������� �������: %d ��� ����� %c\n", position, charnomer);
	fclose(f);
}

void lab6()
{
	setlocale(LC_ALL, "Rus");
	struct AEROFLOT {
		char DESTINATION[50];
		int FLIGHTNUMBER;
		char PILOTNAME[50];
		int NUMBEROFPASSENGERS;
	};
	int i;
	int k;
	int nunm;
	int M;
	printf("����� ����� ������ �� ������ ������");
	scanf("%d", &M);
	char sname[50];
	struct AEROFLOT* airport;
	airport = calloc(100, sizeof(struct AEROFLOT*));
	for (i = 0; i < M; i++) {
		printf("������� ����� �����:");
		scanf("%s", airport[i].DESTINATION);
	}
	for (i = 0; i < M; i++) {
		printf("������� ����� �����:");
		scanf("%d", &airport[i].FLIGHTNUMBER);
	}
	for (i = 0; i < M; i++) {
		printf("������� ��� ������:");
		scanf("%s", &airport[i].PILOTNAME);
	}
	for (i = 0; i < M; i++) {
		printf("������� ����� ����������:");
		scanf("%d", &airport[i].NUMBEROFPASSENGERS);
	}
	system("cls");
	while (1) {
		printf("\n�������� ������ ������\n");
		printf("(1)����� �� ����� ������\n");
		printf("(2)�������� ����\n");
		printf("(3)����������\n");
		printf("(4)������\n");
		scanf("%d", &k);

		if (k == 1) {
			printf("����� ����� ��� �����\n");
			printf("������� ���\n");
			scanf("%s", sname);
			for (i = 0; i < M; i++) {
				if (strcmp(airport[i].PILOTNAME, sname) == 0) {
					printf("%s �������� ������� �������� ����� %d\n", airport[i].PILOTNAME,
						airport[i].FLIGHTNUMBER);
					break;
				}
				else {
					if (i == M - 1)
						printf("������ ������ ���\n");
				}
			}
		}
		if (k == 2) {
			int L = 1;
			airport = realloc(airport, sizeof(struct AEROFLOT*) * L);
			for (int i = M; i < L + M; i++) {
				printf("������� ����� �����:");
				scanf("%s", airport[M].DESTINATION);
				printf("������� ����� �����:");
				scanf("%d", &airport[M].FLIGHTNUMBER);
				printf("������� ��� ������:");
				scanf("%s", &airport[M].PILOTNAME);
				printf("������� ����� �����������:");
				scanf("%d", &airport[M].NUMBEROFPASSENGERS);
			}
			M += L;
		}
		if (k == 3) {
			struct AEROFLOT* tmp = malloc(sizeof(struct AEROFLOT*) * 2);
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < M - i - 1; j++) {
					if (airport[j].NUMBEROFPASSENGERS > airport[j + 1].NUMBEROFPASSENGERS) {
						*tmp[0].DESTINATION = *airport[j].DESTINATION;
						tmp[0].NUMBEROFPASSENGERS = airport[j].NUMBEROFPASSENGERS;
						tmp[0].FLIGHTNUMBER = airport[j].FLIGHTNUMBER;
						*tmp[0].PILOTNAME = airport[j].PILOTNAME;
						airport[j] = airport[j + 1];
						*airport[j + 1].DESTINATION = *tmp[0].DESTINATION;
						airport[j + 1].NUMBEROFPASSENGERS = tmp[0].NUMBEROFPASSENGERS;
						airport[j + 1].FLIGHTNUMBER = tmp[0].FLIGHTNUMBER;
						*airport[j + 1].PILOTNAME = tmp[0].PILOTNAME;
					}
				}
			}
			printf("��������������� ������:\n");
			for (int i = 0; i < M; ++i) {
				printf(" %s ����� ����������:%d\n", airport[i].PILOTNAME, airport[i].NUMBEROFPASSENGERS);
			}
		}
		if (k == 4) {
			printf("C�����:\n");
			for (int i = 0; i < M; ++i) {
				printf("��������� �����: %s\n����� ����������: %d\n�����: %d\n��� ������: %s\n",
					airport[i].DESTINATION, airport[i].NUMBEROFPASSENGERS, airport[i].FLIGHTNUMBER,
					airport[i].PILOTNAME);
			}
		}
		if (k == 0) {
			free(airport);
			return;
		}
	}
}
typedef int Data;
typedef struct Node Node;
struct Node
{
	Data data;
	Node* next;
};
void spisok(Node* list)
{
	for (Node* p = list; p != NULL; p = p->next) {
		printf("%d\n", p->data);
	}
}
void dobavit(Node** plist, Data d)
{
	Node* p = malloc(sizeof(Node));
	p->data = d;
	p->next = *plist;
	*plist = p;
}
void lab7() {
	int num[10];
	int k;
	printf("������� ����� �� ������ ��������\n");
	scanf_s("%d", &k);
	system("cls");
	Node* list = NULL;
	int min = 1000000000;
	for (int i = 1; i <= k; i++) {
		scanf_s("%d", &num[i]);
		dobavit(&list, num[i]);
		if (num[i] < min) min = (num[i]);
	}
	printf("����������� �������� � ������: %d\n", min);
	printf("����� ������\n");
	spisok(list);
	return 0;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	while (1) {
		printf("[a] 0. ������ ���! \n");
		printf("[b] 1.1 ���� ������. \n");
		printf("[c] 1.2 ��������� ���������.\n");
		printf("[d] 1.3 �����. \n");
		printf("[f] 1.4 ����. \n");
		printf("[l] 1.5 ������� \n");
		printf("[g] 1.6 ������� ������������ \n");
		printf("[k] 1.7 ������ � ������ \n");
		printf("[t] 1.8 ��������\n");
		printf("[z] 1.8 ������\n");
		printf("[0] ����� \n");
		char a;
		scanf_s("%s", &a, 4);
		printf("\n");
		system("cls");
		switch (a) {
		case '0':
			exit(EXIT_SUCCESS);
			break;
		case 'a':
			l1();
			break;
		case 'b':
			l2();
			break;
		case 'c':
			l3();
			break;
		case 'd':
			l4();
			break;
		case 'f':
			lab2();
			break;
		case 'l':
			lab3();
			break;
		case 'g':
			lab4();
			break;
		case 'k':
			laba5();
			break;
		case 't':
			lab6();
			break;
		case 'z':
			lab7();
			break;
		default:printf("�� ����� �� ��������� �����.\n");
		}
	}
}
