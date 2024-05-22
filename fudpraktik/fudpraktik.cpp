// <адрес заказа> <тип заказа> <цена заказа> <вес> <дата>

// #include "stdafx.h"
#include "pch.h"

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

struct clients
{
	int count;
	struct client* items;
};

struct list
{
	char kind[20];
	long count;
	long price;
	struct list* next;
	struct list* prev;
};

void print_clients(struct clients clients)
{
	Console::ForegroundColor = ConsoleColor::White;
	Console::BackgroundColor = ConsoleColor::Black;
	Console::Clear();
	for (int i = 0; i < clients.count; i++)
	{
		printf(
			"\n%-20s %-20s %11s %7ld %7ld",
			clients.items[i].address,
			clients.items[i].kind,
			clients.items[i].date,
			clients.items[i].weight,
			clients.items[i].price
		);
	}
	(void)_getch();
}

void print_most_expensive(struct clients clients)
{
	struct client* best = &clients.items[0];
	for (int i = 0; i < clients.count; i++)
	{
		if (best->price < clients.items[i].price)
		{
			best = &clients.items[i];
		}
	}
	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::BackgroundColor = ConsoleColor::Black;

	Console::CursorLeft = 10;
	printf("Самый дорогой заказ: %ld руб.\n", best->price);
	Console::CursorLeft = 10;
	printf("Его адрес: %s\n", best->address);
	(void)_getch();
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

void last(struct clients clients)
{
	struct client* best = &clients.items[0];
	for (int i = 0; i < clients.count; i++)
	{
		if (strcmp(clients.items[i].date, best->date) < 0)
		{
			best = &clients.items[i];
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
	(void)_getch();
}

void print_pizza_count(struct clients clients)
{
	int total = 0;
	for (int i = 0; i < clients.count; i++)
	{
		if (strcmp(clients.items[i].kind, "пицца") == 0) total++;
	}

	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::BackgroundColor = ConsoleColor::Black;

	Console::CursorLeft = 10;
	printf("\nКоличество заказов пиццы: %u", total);
	(void)_getch();
}

void make_list(struct clients clients, struct list** spp)
{
	if (*spp != NULL) return;
	struct list* sp = (struct list*)malloc(sizeof(struct list));
	if (sp == NULL) abort();
	strcpy(sp->kind, clients.items[0].kind);
	sp->price = clients.items[0].price;
	sp->count = 1;
	sp->next = NULL;

	for (int i = 1; i < clients.count; i++)
	{
		struct list* nt;
		struct list* prev = NULL;
		for (nt = sp;
			nt != NULL && strcmp(clients.items[i].kind, nt->kind) > 0;
			prev = nt, nt = nt->next
			);
		if (nt != NULL && strcmp(nt->kind, clients.items[i].kind) == 0)
		{
			nt->price += clients.items[i].price;
			nt->count++;
			continue;
		}

		struct list* tmp = (struct list*)malloc(sizeof(struct list));
		if (tmp == NULL) abort();
		strcpy(tmp->kind, clients.items[i].kind);
		tmp->price = clients.items[i].price;
		tmp->count = 1;
		tmp->next = nt;
		if (prev != NULL) prev->next = tmp;
		else sp = tmp;
	}
	sp->prev = NULL;
	struct list* tail = sp;
	while (tail->next != NULL)
	{
		tail->next->prev = tail;
		tail = tail->next;
	}
	*spp = sp;
}

void list_alpha(struct clients clients, struct list** spp)
{
	Console::ForegroundColor = ConsoleColor::Black;
	Console::BackgroundColor = ConsoleColor::Gray;
	Console::Clear();
	printf("\n");
	Console::CursorLeft = 12;
	printf("Алфавитный список по типу заказа.");
	printf("\n\r----------------------------------------------------------------");
	make_list(clients, spp);
	for (struct list* nt = *spp; nt != NULL; nt = nt->next)
	{
		printf(
			"\n\r%-20s %7ld шт. %7ld р.",
			nt->kind,
			nt->count,
			nt->price
		);
	}
	(void)_getch();
}

void list_alpha_reverse(struct clients clients, struct list** spp)
{
	Console::ForegroundColor = ConsoleColor::Black;
	Console::BackgroundColor = ConsoleColor::Gray;
	Console::Clear();
	printf("\n");
	Console::CursorLeft = 12;
	printf("Обратный алфавитный список по типу заказа.");
	printf("\n\r----------------------------------------------------------------------------");
	make_list(clients, spp);
	struct list* tail = *spp;
	while (tail->next != NULL) tail = tail->next;
	for (struct list* nt = tail; nt != NULL; nt = nt->prev)
	{
		printf(
			"\n\r%-20s %7ld шт. %7ld р.",
			nt->kind,
			nt->count,
			nt->price
		);
	}
	(void)_getch();
}

void print_expensive_list(struct clients clients)
{
	Console::ForegroundColor = ConsoleColor::Black;
	Console::BackgroundColor = ConsoleColor::Gray;
	Console::Clear();
	printf("\n");
	Console::CursorLeft = 12;
	printf("Список заказов на сумму более 1.000 руб");
	printf("\n\r----------------------------------------------------------------");
	for (int i = 0; i < clients.count; i++)
	{
		if (clients.items[i].price > 1000)
		{
			printf(
				"\n\r%-20s %-20s %7ld г %7ld р.",
				clients.items[i].address,
				clients.items[i].kind,
				clients.items[i].weight,
				clients.items[i].price
			);
		}
	}
	(void)_getch();
}

void diagram(struct clients clients, struct list** spp)
{
	Console::BackgroundColor = ConsoleColor::Yellow;
	Console::Clear();
	long total = 0;
	for (int i = 0; i < clients.count; i++)
	{
		total += clients.items[i].price;
	}

	make_list(clients, spp);
	ConsoleColor color = ConsoleColor::Black;
	int ncolor = 0;
	for (struct list* nt = *spp; nt != NULL; nt = nt->next, ncolor++, color++)
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
	(void)_getch();
	return;
}

void match_one(struct clients clients)
{
	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::BackgroundColor = ConsoleColor::Black;

	struct client a, b;
	bool found_match = false;
	for (int i = 0; i < clients.count; i++)
	{
		for (int j = i + 1; j < clients.count; j++)
		{
			a = clients.items[i];
			b = clients.items[j];
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
	(void)_getch();
}

void match(struct clients clients)
{
	Console::ForegroundColor = ConsoleColor::Black;
	Console::BackgroundColor = ConsoleColor::Gray;
	Console::Clear();
	printf("Список продуктов с совпадающей ценой и разным типом:");
	for (int i = 0; i < clients.count; i++)
	{
		for (int j = i + 1; j < clients.count; j++)
		{
			struct client a = clients.items[i];
			struct client b = clients.items[j];
			if (strcmp(a.kind, b.kind) == 0) continue;
			if (a.price != b.price) continue;
			printf("\r\n%-20s %-20s %7ld", a.kind, b.kind, a.price);
		}
	}
	(void)_getch();
}

int menu()
{
	Console::BackgroundColor = ConsoleColor::Yellow;
	Console::Clear();

	Console::ForegroundColor = ConsoleColor::Black;
	Console::BackgroundColor = ConsoleColor::Gray;

	const char* const options[] = {
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
	const int options_count = sizeof(options) / sizeof(options[0]);

	for (int i = 0; i < options_count; i++)
	{
		Console::CursorLeft = 10;
		Console::CursorTop = 4 + i;
		printf(" %s ", options[i]);
	}

	int y = 1;
	int last_y = y;
	const int first_option = 1;
	const int last_option = options_count - 2;
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

		const int key_enter = 13;
		const int key_esc = 27;
		const int key_up = 72;
		const int key_down = 80;
		const int key_home = 71;
		const int key_end = 79;
		switch (_getch())
		{
		case key_down:  y++; break;
		case key_up:    y--; break;
		case key_home:  y = first_option; break;
		case key_end:   y = last_option; break;
		case key_enter: return y - 1;
		case key_esc:   exit(0);
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
		(void)_getch();
		exit(1);
	}

	struct clients clients = { 0 };
	if (fscanf(file, "%u", &clients.count) != 1)
	{
		printf(
			"\nошибка: файл должен начинаться "
			"количеством записей (положительное число)"
		);
		(void)_getch();
		exit(1);
	}

	if (clients.count == 0)
	{
		printf("\nошибка: количество записей не может быть нулевым");
		(void)_getch();
		exit(1);
	}

	clients.items = (struct client*)malloc(sizeof(struct client) * clients.count);
	if (clients.items == NULL) abort();
	for (int i = 0; i < clients.count; i++)
	{
		if (feof(file))
		{
			printf(
				"\nошибка: файл содержит меньше записей, "
				"чем объявлено в его заголовке "
				"(%u из %u)", i, clients.count
			);
			(void)_getch();
			exit(1);
		}
		if (fscanf(
			file,
			"%s%s%s%ld%ld",
			clients.items[i].address,
			clients.items[i].kind,
			clients.items[i].date,
			&clients.items[i].weight,
			&clients.items[i].price) != 5)
		{
			printf(
				"\nошибка: запись номер %u повреждена или "
				"записана в некорректном формате", i + 1
			);
			(void)_getch();
			exit(1);
		}
	}

	struct list* sp = NULL;
	while (true)
	{
		switch (menu())
		{
		case 0: print_most_expensive(clients);    break;
		case 1: last(clients);                    break;
		case 2: list_alpha(clients, &sp);         break;
		case 3: list_alpha_reverse(clients, &sp); break;
		case 4: print_expensive_list(clients);    break;
		case 5: print_pizza_count(clients);       break;
		case 6: diagram(clients, &sp);            break;
		case 7: match(clients);                   break;
		case 8: match_one(clients);               break;
		case 9: print_clients(clients);           break;
		case 10: exit(0);
		}
	}
}