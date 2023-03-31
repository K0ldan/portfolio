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
	printf("Привет Мир\n");
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
	printf("Введите год -> ");
	scanf_s("%d", &k);
	if (k % 4 == 0) printf("Год високосный\n");
	else printf("Год не високосный\n");
}

void l4() {
	int a, b;
	printf("Введите число A -> ");
	scanf_s("%d", &a);
	printf("Введите число B -> ");
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

	printf("%s\n", "Введите минимум случайных чисел");
	scanf_s("%d", &min);
	printf("%s\n", "Введите максимум случайных чисел");
	scanf_s("%d", &max);
	if (max >= min)
	{
		max = max - min + 1;
		printf("%s\n", "Введите кол-во строк");
		scanf_s("%d", &a);
		printf("%s\n", "Введите кол-во столбцов");
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
				printf("%s", "номера строк");
				printf("%d\n", i + 1);
			}
			v = 0;
		}
		printf("%s\n", "кол-во не нулевых строк");
		printf("%d\n", k);
		printf("%d\n", p);
	}



}
void laba5() {
	FILE* f; fopen_s(&f, "alfa.txt", "r+");
	char string[1000];
	char alphabet[] = { 'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж'
	, 'З', 'И', 'Й', 'К', 'Л', 'М', 'Н', 'О'
	, 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ'
	, 'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я' };
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
	if (check) printf(" Весь по алфавитному порядку");
	else printf("Позиция символа который нарушает порядок: %d это буква %c\n", position, charnomer);
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
	printf("Какое колво рейсов вы хотите ввести");
	scanf("%d", &M);
	char sname[50];
	struct AEROFLOT* airport;
	airport = calloc(100, sizeof(struct AEROFLOT*));
	for (i = 0; i < M; i++) {
		printf("Введите Старт рейса:");
		scanf("%s", airport[i].DESTINATION);
	}
	for (i = 0; i < M; i++) {
		printf("Введите номер рейса:");
		scanf("%d", &airport[i].FLIGHTNUMBER);
	}
	for (i = 0; i < M; i++) {
		printf("Введите Имя пилота:");
		scanf("%s", &airport[i].PILOTNAME);
	}
	for (i = 0; i < M; i++) {
		printf("Введите колво пассажиров:");
		scanf("%d", &airport[i].NUMBEROFPASSENGERS);
	}
	system("cls");
	while (1) {
		printf("\nВыберите формат поиска\n");
		printf("(1)Поиск по Имени пилота\n");
		printf("(2)Добавить Рейс\n");
		printf("(3)Сортировка\n");
		printf("(4)Список\n");
		scanf("%d", &k);

		if (k == 1) {
			printf("Какой пилот вам нужен\n");
			printf("Введите Имя\n");
			scanf("%s", sname);
			for (i = 0; i < M; i++) {
				if (strcmp(airport[i].PILOTNAME, sname) == 0) {
					printf("%s является пилотом маршрута номер %d\n", airport[i].PILOTNAME,
						airport[i].FLIGHTNUMBER);
					break;
				}
				else {
					if (i == M - 1)
						printf("Такого Пилота нет\n");
				}
			}
		}
		if (k == 2) {
			int L = 1;
			airport = realloc(airport, sizeof(struct AEROFLOT*) * L);
			for (int i = M; i < L + M; i++) {
				printf("Введите Старт Рейса:");
				scanf("%s", airport[M].DESTINATION);
				printf("Введите номер Рейса:");
				scanf("%d", &airport[M].FLIGHTNUMBER);
				printf("Введите Имя пилота:");
				scanf("%s", &airport[M].PILOTNAME);
				printf("Введите колво пасскажиров:");
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
			printf("Отсортированный список:\n");
			for (int i = 0; i < M; ++i) {
				printf(" %s Колво пассажиров:%d\n", airport[i].PILOTNAME, airport[i].NUMBEROFPASSENGERS);
			}
		}
		if (k == 4) {
			printf("Cписок:\n");
			for (int i = 0; i < M; ++i) {
				printf("Начальная точка: %s\nколво пассажиров: %d\nНомер: %d\nИмя пилота: %s\n",
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
	printf("Сколько узлов вы хотите добавить\n");
	scanf_s("%d", &k);
	system("cls");
	Node* list = NULL;
	int min = 1000000000;
	for (int i = 1; i <= k; i++) {
		scanf_s("%d", &num[i]);
		dobavit(&list, num[i]);
		if (num[i] < min) min = (num[i]);
	}
	printf("Минимальное значение в списке: %d\n", min);
	printf("Вывод Списка\n");
	spisok(list);
	return 0;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	while (1) {
		printf("[a] 0. Привет Мир! \n");
		printf("[b] 1.1 Типы данных. \n");
		printf("[c] 1.2 Операторы ветвления.\n");
		printf("[d] 1.3 Циклы. \n");
		printf("[f] 1.4 Файл. \n");
		printf("[l] 1.5 Массивы \n");
		printf("[g] 1.6 Массивы динамические \n");
		printf("[k] 1.7 Замена в тексте \n");
		printf("[t] 1.8 Аэропорт\n");
		printf("[z] 1.8 Списки\n");
		printf("[0] Выход \n");
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
		default:printf("Вы ввели не правльную цифру.\n");
		}
	}
}
