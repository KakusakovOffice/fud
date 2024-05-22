// <адрес заказа> <тип заказа> <цена заказа> <вес> <дата>

#include "stdafx.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <clocale>

#include <conio.h>

using namespace std;
using namespace System;
using namespace System::IO;

struct client
{
	char address[20];
	char kind[20];
	char date[11];
	long weight;
	long price;
};

struct list
{
	char kind[20];
	long count;
	long price;
	struct list* next;
	struct list* prev;
};

unsigned int count;
struct client* clients;
struct list* sp;

#define ENTER 13
#define ESC   27
#define UP    72
#define DOWN  80
#define HOME  71
#define END   79

void print_clients()
{
	Console::ForegroundColor = ConsoleColor::White;
	Console::BackgroundColor = ConsoleColor::Black;
	Console::Clear();
	for (unsigned int i = 0; i < count; i++)
	{
		printf(
			"\n%-20s %-20s %11s %7ld %7ld",
			clients[i].address,
			clients[i].kind,
			clients[i].date,
			clients[i].weight,
			clients[i].price
		);
	}
	_getch();
}

void print_most_expensive()
{
	struct client* best = &clients[0];
	for (unsigned int i = 0; i < count; i++)
	{
		if (best->price < clients[i].price)
		{
			best = &clients[i];
		}
	}
	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::BackgroundColor = ConsoleColor::Black;

	Console::CursorLeft = 10;
	printf("Самый дорогой заказ: %ld руб.\n", best->price);
	Console::CursorLeft = 10;
	printf("Его адрес: %s\n", best->address);
	_getch();
}

void to_pretty_date(char* to, const char* from)
{
	char tmp[3];
	const char* months[] = {
		"января","февраля","марта","апреля","мая","июня",
		"июля","августа","сентября","октября","ноября","декабря"
	};
	strcpy(to, from + 8);
	strcat(to, " ");
	strncpy(tmp, from + 5, 2);
	tmp[2] = '\0';
	strcat(to, months[atoi(tmp) - 1]);
	strcat(to, " ");
	strncat(to, from, 4);
}

void last()
{
	struct client* best = &clients[0];
	for (unsigned int i = 0; i < count; i++)
	{
		if (strcmp(clients[i].date, best->date) < 0)
		{
			best = &clients[i];
		}
	}

	char pretty_date[17];
	to_pretty_date(pretty_date, best->date);
	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::BackgroundColor = ConsoleColor::Black;
	Console::CursorLeft = 10;
	printf("Последний заказ:\n");
	Console::CursorLeft = 12;
	printf("открыт: %s\n", pretty_date);
	Console::CursorLeft = 12;
	printf("адрес: % s\n", best->address);
	Console::CursorLeft = 12;
	printf("тип: %s\n", best->kind);
	Console::CursorLeft = 12;
	printf("сумма: %ld\n", best->price);
	_getch();
}

void print_pizza_count()
{
	unsigned int total = 0;
	for (unsigned int i = 0; i < count; i++)
	{
		if (strcmp(clients[i].kind, "пицца") == 0) total++;
	}

	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::BackgroundColor = ConsoleColor::Black;

	Console::CursorLeft = 10;
	printf("\nКоличество заказов пиццы: %u", total);
	_getch();
}

void make_list()
{
	if (sp != NULL) return;
	sp = (struct list*)malloc(sizeof(struct list));
	if (sp == NULL) abort();
	strcpy(sp->kind, clients[0].kind);
	sp->price = clients[0].price;
	sp->count = 1;
	sp->next = NULL;

	for (unsigned int i = 1; i < count; i++)
	{
		struct list* nt;
		struct list* prev = NULL;
		for (nt = sp;
			nt != NULL && strcmp(clients[i].kind, nt->kind) > 0;
			prev = nt, nt = nt->next
			);
		if (strcmp(nt->kind, clients[i].kind) == 0)
		{
			nt->price += clients[i].price;
			nt->count++;
			continue;
		}

		struct list* tmp = (struct list*)malloc(sizeof(struct list));
		if (tmp == NULL) abort();
		strcpy(tmp->kind, clients[i].kind);
		tmp->price = clients[i].price;
		tmp->count = 1;
		tmp->next = nt;
		if (prev != NULL) prev->next = tmp;
		else  sp = tmp;
	}
	sp->prev = NULL;
	struct list* tail = sp;
	while (tail->next != NULL)
	{
		tail->next->prev = tail;
		tail = tail->next;
	}
}

void list_alpha()
{
	Console::ForegroundColor = ConsoleColor::Black;
	Console::BackgroundColor = ConsoleColor::Gray;
	Console::Clear();
	printf("\n");
	Console::CursorLeft = 12;
	printf("Алфавитный список по типу заказа.");
	printf("\n\r----------------------------------------------------------------");
	make_list();
	for (struct list* nt = sp; nt != NULL; nt = nt->next)
	{
		printf(
			"%\n\r%-20s %7ld шт. %7ld р.",
			nt->kind,
			nt->count,
			nt->price
		);
	}
	_getch();
}

void list_alpha_reverse()
{
	Console::ForegroundColor = ConsoleColor::Black;
	Console::BackgroundColor = ConsoleColor::Gray;
	Console::Clear();
	printf("\n");
	Console::CursorLeft = 12;
	printf("Обратный алфавитный список по типу заказа.");
	printf("\n\r----------------------------------------------------------------------------");
	make_list();
	struct list* tail = sp;
	while (tail->next != NULL) tail = tail->next;
	for (struct list* nt = tail; nt != NULL; nt = nt->prev)
	{
		printf(
			"%\n\r%-20s %7ld шт. %7ld р.",
			nt->kind,
			nt->count,
			nt->price
		);
	}
	_getch();
}

void print_expensive_list()
{
	Console::ForegroundColor = ConsoleColor::Black;
	Console::BackgroundColor = ConsoleColor::Gray;
	Console::Clear();
	printf("\n");
	Console::CursorLeft = 12;
	printf("Список заказов на сумму более 1.000 руб");
	printf("\n\r----------------------------------------------------------------");
	make_list();
	for (int i = 0; i < count; i++)
	{
		if (clients[i].price > 1000)
		{
			printf(
				"%\n\r%-20s %-20s %7ld г %7ld р.",
				clients[i].address,
				clients[i].kind,
				clients[i].weight,
				clients[i].price
			);
		}
	}
	_getch();
}

void diagram()
{
	Console::BackgroundColor = ConsoleColor::Yellow;
	Console::Clear();
	long total = 0;
	for (unsigned int i = 0; i < count; i++)
	{
		total += clients[i].price;
	}

	make_list();
	ConsoleColor color = ConsoleColor::Black;
	int ncolor = 0;
	for (struct list* nt = sp; nt != NULL; nt = nt->next, ncolor++, color++)
	{
		char str[20];
		sprintf(str, "%3.1f%%", (nt->price * 100.0 / total));
		Console::ForegroundColor = ConsoleColor::Black;
		Console::BackgroundColor = ConsoleColor::Yellow;
		Console::CursorLeft = 5;
		printf("%20s %7ld шт. %20s", nt->kind, nt->count, str);
		Console::BackgroundColor = color;
		Console::CursorLeft = 60;
		printf("%*.s\n", nt->price * 30 / total, "");
		if (ncolor == 13)
		{
			color = ConsoleColor::Black;
			ncolor = 0;
		}
	}
	_getch();
	return;
}

void match_one()
{
	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::BackgroundColor = ConsoleColor::Black;

	struct client a, b;
	bool found_match = false;
	for (unsigned int i = 0; i < count; i++)
	{
		for (unsigned int j = i + 1; j < count; j++)
		{
			a = clients[i];
			b = clients[j];
			if (strcmp(a.kind, b.kind) == 0) continue;
			if (a.price != b.price) continue;
			found_match = true;
			goto finish;
		}
	}
finish:
	Console::CursorLeft = 10;
	printf("Первый продукт с совпадающей ценой:\n");
	Console::CursorLeft = 10;
	if (found_match)
	{
		printf("цена: %7ld\n", a.price);
		Console::CursorLeft = 10;
		printf("тип 1: %-20s\n", a.kind);
		Console::CursorLeft = 10;
		printf("тип 2: %-20s\n", b.kind);
	}
	else printf("Совпадений не найдено.\n");
	_getch();
}

void match()
{
	Console::ForegroundColor = ConsoleColor::Black;
	Console::BackgroundColor = ConsoleColor::Gray;
	Console::Clear();
	printf("Список продуктов с совпадающей ценой и разным типом:");
	for (unsigned int i = 0; i < count; i++)
	{
		for (unsigned int j = i + 1; j < count; j++)
		{
			struct client a = clients[i];
			struct client b = clients[j];
			if (strcmp(a.kind, b.kind) == 0) continue;
			if (a.price != b.price) continue;
			printf("\r\n%-20s %-20s %7ld", a.kind, b.kind, a.price);
		}
	}
	_getch();
}

void menu()
{
	const char* options[] = {
		"                                      ",
		"Адрес самого дорогого заказа          ",
		"Последний заказ                       ",
		"Алфавитный список по типу             ",
		"Алфавитный список по типу (обратный)  ",
		"Заказы на сумму свыше 1.000 р.        ",
		"Количество заказов пиццы              ",
		"Диаграмма                             ",
		"Продукты с совпадающей ценой          ",
		"Продукты с совпадающей ценой (первый) ",
		"Исходные данные                       ",
		"Выход                                 ",
		"                                      "
	};
	int options_count = sizeof(options) / sizeof(options[0]);
	int first_option = 1;
	int last_option = options_count - 2;

	Console::BackgroundColor = ConsoleColor::Yellow;
	Console::Clear();

	Console::ForegroundColor = ConsoleColor::Black;
	Console::BackgroundColor = ConsoleColor::Gray;
	for (int i = 0; i < options_count; i++)
	{
		Console::CursorLeft = 10;
		Console::CursorTop = 4 + i;
		printf(" %s ", options[i]);
	}

	int y = 1;
	int last_y = y;

	while (1)
	{
		Console::ForegroundColor = ConsoleColor::Black;
		Console::BackgroundColor = ConsoleColor::Gray;
		Console::CursorLeft = 10 + 1;
		Console::CursorTop = 4 + last_y;
		printf("%s", options[last_y]);
		Console::ForegroundColor = ConsoleColor::Black;
		Console::BackgroundColor = ConsoleColor::Yellow;
		Console::CursorLeft = 10 + 1;
		Console::CursorTop = 4 + y;
		printf("%s", options[y]);

		Console::CursorTop = 4 + options_count;
		last_y = y;
		switch (_getch())
		{
		case DOWN:  y++; break;
		case UP:    y--; break;
		case HOME:  y = first_option; break;
		case END:   y = last_option; break;
		case ENTER:
			switch (y)
			{
			case 1: print_most_expensive(); return;
			case 2: last();                 return;
			case 3: list_alpha();           return;
			case 4: list_alpha_reverse();   return;
			case 5: print_expensive_list(); return;
			case 6: print_pizza_count();    return;
			case 7: diagram();              return;
			case 8: match();                return;
			case 9: match_one();            return;
			case 10: print_clients();        return;
			case 11: exit(0);
			}
		case ESC:   exit(0);
		}

		if (y > last_option) y = first_option;
		if (y < first_option) y = last_option;
	}
}

void make_file(const char* path)
{
	FILE* file = fopen(path, "w");
	if (fprintf(
		file,
		"15\n"
		"ул_Ленина_д10 яблоки        2024-11-12 5000 2000\n"
		"ул_Сталина_д3 пицца         2024-11-11 500 2500\n"
		"ул_Пушкина_д3 суповой_набор 2024-11-12 250 500\n"
		"ул_Пушкина_д2 мороженное    2024-11-12 100 400\n"
		"д_Колотушкина пицца         2024-11-11 950 6500\n"
		"ул_Ввод_д6    суши          2024-11-10 500 2500\n"
		"ул_Кукина_д3  шоколад       2024-11-11 350 2000\n"

		"Кремль        шоколад       2024-12-11 1000 10000\n"

		"ул_Ленина_д12 капуста       2024-11-12 2250 250\n"
		"ул_Сталина_д7 пицца         2024-11-11 500 2500\n"
		"ул_Пушкина_д4 сыр_Гауда     2024-11-12 250 500\n"
		"ул_Пушкина_д7 мороженное    2024-11-12 100 400\n"
		"ул_Пушкина_д9 суповой_набор 2024-11-11 100 400\n"
		"ул_Ввод_д8    шоколад       2024-11-13 250 1250\n"
		"ул_Кукина_д5  суши          2024-11-11 700 5000\n"
	) < 0) exit(1);
	fclose(file);
}

int main(array<System::String^>^ args)
{
	setlocale(LC_CTYPE, "Russian");
	Console::CursorVisible::set(false);
	Console::BufferHeight = Console::WindowHeight;
	Console::BufferWidth = Console::WindowWidth;
	const char* path = "Vklad.dat";
	make_file(path);
	FILE* file = fopen(path, "r");
	if (file == NULL)
	{
		printf(
			"\nошибка: Не удается открыть файл %s "
			"для чтения: %s", path, strerror(errno)
		);
		_getch();
		exit(1);
	}

	if (fscanf(file, "%u", &count) != 1)
	{
		printf(
			"\nошибка: файл должен начинаться "
			"количеством записей (положительное число)"
		);
		_getch();
		exit(1);
	}

	if (count == 0)
	{
		printf("\nошибка: количество записей не может быть нулевым");
		_getch();
		exit(1);
	}

	clients = (struct client*)malloc(sizeof(struct client) * count);
	if (clients == NULL) abort();
	for (unsigned int i = 0; i < count; i++)
	{
		if (feof(file))
		{
			printf(
				"\nошибка: файл содержит меньше записей, "
				"чем объявлено в его заголовке "
				"(%u из %u)", i, count
			);
			_getch();
			exit(1);
		}
		if (fscanf(
			file,
			"%s%s%s%ld%ld",
			clients[i].address,
			clients[i].kind,
			clients[i].date,
			&clients[i].weight,
			&clients[i].price) != 5)
		{
			printf(
				"\nошибка: запись номер %u повреждена или "
				"записана в некорректном формате", i + 1
			);
			_getch();
			exit(1);
		}
	}

	while (1) menu();
}