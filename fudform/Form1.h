#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

unsigned int count = 0;
struct client* clients = NULL;
struct list* sp = NULL;

void make_file(const char* path)
{
	FILE* file = fopen(path, "w");
	if (fprintf(
		file,
		"15\n"
		"��_������_�10 ������        2024-11-12 5000 2000\n"
		"��_�������_�3 �����         2024-11-11 500 2500\n"
		"��_�������_�3 �������_����� 2024-11-12 250 500\n"
		"��_�������_�2 ����������    2024-11-12 100 400\n"
		"�_����������� �����         2024-11-11 950 6500\n"
		"��_����_�6    ����          2024-11-10 500 2500\n"
		"��_������_�3  �������       2024-11-11 350 2000\n"

		"������        �������       2024-12-11 1000 10000\n"
		
		"��_������_�12 �������       2024-11-12 2250 250\n"
		"��_�������_�7 �����         2024-11-11 500 2500\n"
		"��_�������_�4 ���_�����     2024-11-12 250 500\n"
		"��_�������_�7 ����������    2024-11-12 100 400\n"
		"��_�������_�9 �������_����� 2024-11-11 100 400\n"
		"��_����_�8    �������       2024-11-13 250 1250\n"
		"��_������_�5  ����          2024-11-11 700 5000\n"
	) < 0) exit(1);
	fclose(file);
}

void to_pretty_date(char* to, const char* from)
{
	char tmp[3];
	const char* months[] = {
		"������","�������","�����","������","���","����",
		"����","�������","��������","�������","������","�������"
	};
	strcpy(to, from + 8);
	strcat(to, " ");
	strncpy(tmp, from + 5, 2);
	tmp[2] = '\0';
	strcat(to, months[atoi(tmp) - 1]);
	strcat(to, " ");
	strncat(to, from, 4);
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
		if (nt != NULL && strcmp(nt->kind, clients[i].kind) == 0)  // I added null check, is everything ok?
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

namespace fudform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// ������ ��� Form1
	///
	/// ��������! ��� ��������� ����� ����� ������ ���������� ����� ��������
	///          �������� ����� ����� �������� ("Resource File Name") ��� �������� ���������� ������������ �������,
	///          ���������� �� ����� ������� � ����������� .resx, �� ������� ������� ������ �����. � ��������� ������,
	///          ������������ �� ������ ��������� �������� � ���������������
	///          ���������, ��������������� ������ �����.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::MenuStrip^  menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������������������������������ToolStripMenuItem;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::ToolStripMenuItem^  ������������������1000�ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����������������������ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������������������������������ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������������ToolStripMenuItem;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::TabPage^  tabPage6;





	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridView^ dataGridView3;
	private: System::Windows::Forms::DataGridView^ dataGridView4;
	private: System::Windows::Forms::DataGridView^ dataGridView5;

	protected: 


	protected: 

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������������1000�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������������ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������������������������ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView5 = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip2->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->tabPage5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Location = System::Drawing::Point(0, 24);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(472, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuStrip2
			// 
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->����ToolStripMenuItem,
					this->�������ToolStripMenuItem, this->�����ToolStripMenuItem
			});
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(472, 24);
			this->menuStrip2->TabIndex = 1;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->�������ToolStripMenuItem,
					this->���������ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�������ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::���������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
				this->�������������������������ToolStripMenuItem,
					this->��������������ToolStripMenuItem, this->����������������������ToolStripMenuItem, this->�������������������������������ToolStripMenuItem,
					this->������������������1000�ToolStripMenuItem, this->����������������������ToolStripMenuItem1, this->���������ToolStripMenuItem,
					this->�������������������������ToolStripMenuItem, this->�������������������������������ToolStripMenuItem1, this->��������������ToolStripMenuItem
			});
			this->�������ToolStripMenuItem->Enabled = false;
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(69, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			// 
			// �������������������������ToolStripMenuItem
			// 
			this->�������������������������ToolStripMenuItem->Name = L"�������������������������ToolStripMenuItem";
			this->�������������������������ToolStripMenuItem->Size = System::Drawing::Size(309, 22);
			this->�������������������������ToolStripMenuItem->Text = L"����� ������ �������� ������";
			this->�������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�������������������������ToolStripMenuItem_Click);
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(309, 22);
			this->��������������ToolStripMenuItem->Text = L"��������� �����";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::��������������ToolStripMenuItem_Click);
			// 
			// ����������������������ToolStripMenuItem
			// 
			this->����������������������ToolStripMenuItem->Name = L"����������������������ToolStripMenuItem";
			this->����������������������ToolStripMenuItem->Size = System::Drawing::Size(309, 22);
			this->����������������������ToolStripMenuItem->Text = L"���������� ������ �� ����";
			this->����������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::����������������������ToolStripMenuItem_Click);
			// 
			// �������������������������������ToolStripMenuItem
			// 
			this->�������������������������������ToolStripMenuItem->Name = L"�������������������������������ToolStripMenuItem";
			this->�������������������������������ToolStripMenuItem->Size = System::Drawing::Size(309, 22);
			this->�������������������������������ToolStripMenuItem->Text = L"���������� ������ �� ���� (��������)";
			this->�������������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�������������������������������ToolStripMenuItem_Click);
			// 
			// ������������������1000�ToolStripMenuItem
			// 
			this->������������������1000�ToolStripMenuItem->Name = L"������������������1000�ToolStripMenuItem";
			this->������������������1000�ToolStripMenuItem->Size = System::Drawing::Size(309, 22);
			this->������������������1000�ToolStripMenuItem->Text = L"������ �� ����� ����� 1.000 �.";
			this->������������������1000�ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::������������������1000�ToolStripMenuItem_Click);
			// 
			// ����������������������ToolStripMenuItem1
			// 
			this->����������������������ToolStripMenuItem1->Name = L"����������������������ToolStripMenuItem1";
			this->����������������������ToolStripMenuItem1->Size = System::Drawing::Size(309, 22);
			this->����������������������ToolStripMenuItem1->Text = L"���������� ������� �����";
			this->����������������������ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::����������������������ToolStripMenuItem1_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(309, 22);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::���������ToolStripMenuItem_Click);
			// 
			// �������������������������ToolStripMenuItem
			// 
			this->�������������������������ToolStripMenuItem->Name = L"�������������������������ToolStripMenuItem";
			this->�������������������������ToolStripMenuItem->Size = System::Drawing::Size(309, 22);
			this->�������������������������ToolStripMenuItem->Text = L"�������� � ����������� �����";
			this->�������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�������������������������ToolStripMenuItem_Click);
			// 
			// �������������������������������ToolStripMenuItem1
			// 
			this->�������������������������������ToolStripMenuItem1->Name = L"�������������������������������ToolStripMenuItem1";
			this->�������������������������������ToolStripMenuItem1->Size = System::Drawing::Size(309, 22);
			this->�������������������������������ToolStripMenuItem1->Text = L"�������� � ����������� ����� (������)";
			this->�������������������������������ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::�������������������������������ToolStripMenuItem1_Click);
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(309, 22);
			this->��������������ToolStripMenuItem->Text = L"�������� ������";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::��������������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�����ToolStripMenuItem_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage6);
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Location = System::Drawing::Point(0, 24);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(472, 329);
			this->tabControl1->TabIndex = 2;
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->dataGridView1);
			this->tabPage6->Location = System::Drawing::Point(4, 22);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Size = System::Drawing::Size(464, 303);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"�������� ������";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(464, 303);
			this->dataGridView1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(464, 303);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"���������";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::tabPage1_Paint);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridView2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(464, 303);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"������";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->dataGridView3);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(464, 303);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"������ (��������)";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->dataGridView4);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(464, 303);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"������ �� ����� ����� 1.000 �.";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->dataGridView5);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(464, 303);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"�������� � ����������� �����";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(8, 7);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(455, 295);
			this->dataGridView2->TabIndex = 0;
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Location = System::Drawing::Point(3, 6);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->Size = System::Drawing::Size(460, 296);
			this->dataGridView3->TabIndex = 0;
			// 
			// dataGridView4
			// 
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Location = System::Drawing::Point(2, 3);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->Size = System::Drawing::Size(461, 299);
			this->dataGridView4->TabIndex = 0;
			// 
			// dataGridView5
			// 
			this->dataGridView5->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView5->Location = System::Drawing::Point(1, 4);
			this->dataGridView5->Name = L"dataGridView5";
			this->dataGridView5->Size = System::Drawing::Size(466, 298);
			this->dataGridView5->TabIndex = 0;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(472, 353);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->menuStrip2);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"��������";
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->tabPage4->ResumeLayout(false);
			this->tabPage5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void �����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void ���������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void �������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			free(clients);
			//listBox1->Items->Clear();
			�������ToolStripMenuItem->Enabled = false;

			make_file("Vklad.dat");
			FILE* file;
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				char* path = (char*)(void*)Marshal::StringToHGlobalAnsi(openFileDialog1->FileName);
				file = fopen(path, "r");
				if (file == NULL)
				{
					MessageBox::Show(
						"�� ������� ������� ����",
						"������",
						MessageBoxButtons::OK,
						MessageBoxIcon::Error
					);
					return;
				}
				Marshal::FreeHGlobal(IntPtr((void*)path));
			}
			else return;

			if (fscanf(file, "%u", &count) != 1) 
			{
				MessageBox::Show(
					"���� ������ ���������� ����������� ������� (������������� �����)",
					"������",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
				return;
			}

			if (count == 0)
			{
				MessageBox::Show(
					"���������� ������� � ����� �� ����� ���� �������",
					"������",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
				return;
			}

			DataTable^ Table1;
			Table1 = gcnew DataTable();
			this->dataGridView1->DataSource = Table1;
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ReadOnly = true;

			Table1->Columns->Add("�����");
			Table1->Columns->Add("��� ������");
			Table1->Columns->Add("����");
			Table1->Columns->Add("����� �.");
			Table1->Columns->Add("���� ���.");

			this->dataGridView1->Columns["����� �."]->HeaderCell->Style->Alignment =
				DataGridViewContentAlignment::MiddleRight;
			this->dataGridView1->Columns["����� �."]->DefaultCellStyle->Alignment =
				DataGridViewContentAlignment::MiddleRight;
			this->dataGridView1->Columns["���� ���."]->HeaderCell->Style->Alignment =
				DataGridViewContentAlignment::MiddleRight;
			this->dataGridView1->Columns["���� ���."]->DefaultCellStyle->Alignment =
				DataGridViewContentAlignment::MiddleRight;

			clients = (struct client*)malloc(sizeof(struct client) * count);
			if (clients == NULL) abort();
			for (unsigned int i = 0; i < count; i++)
			{
				if (feof(file))
				{
					MessageBox::Show(
						"���� �������� ������ �������, ��� ��������� � ��� ���������",
						"������",
						MessageBoxButtons::OK,
						MessageBoxIcon::Error
					);
					return;
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
					MessageBox::Show(
						"���� ��� ����� ������� ����� ���������� ��� �������� � ������������ �������",
						"������",
						MessageBoxButtons::OK,
						MessageBoxIcon::Error
					);
					return;
				}
				char tmp[80] = {0};
				sprintf(
					tmp,
					"%-20s %-20s %-11s %7ld %7ld",
					clients[i].address,
					clients[i].kind,
					clients[i].date,
					clients[i].weight,
					clients[i].price
				);
				DataRow^ row = Table1->Rows->Add();
				row[0] = gcnew String(clients[i].address);
				row[1] = gcnew String(clients[i].kind);
				row[2] = gcnew String(clients[i].date);
				row[3] = clients[i].weight;
				row[4] = clients[i].price;
			}
			�������ToolStripMenuItem->Enabled = true;
			fclose(file);
		 }
private: System::Void �������������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			struct client* best = &clients[0];
			char s[100];
			for (unsigned int i = 0; i < count; i++)
			{
				if (best->price < clients[i].price)
				{
					best = &clients[i];
				}
			}
			Console::ForegroundColor = ConsoleColor::Yellow;
			Console::BackgroundColor = ConsoleColor::Black;

			sprintf(
				s, 
				"�����: %ld ���.\n"
				"�����: %s\n", 
				best->price,
				best->address
			);
			MessageBox::Show(gcnew String(s), "����� ������ �������� ������");
		}
	private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			struct client* best = &clients[0];
			char s[100];
			for (unsigned int i = 0; i < count; i++)
			{
				if (strcmp(clients[i].date, best->date) < 0)
				{
					best = &clients[i];
				}
			}

			char pretty_date[17];
			to_pretty_date(pretty_date, best->date);
			sprintf(
				s, 
				"������: %s\n"
				"�����: % s\n"
				"���: %s\n"
				"�����: %ld\n",
				pretty_date,
				best->address,
				best->kind,
				best->price
			);
			MessageBox::Show(gcnew String(s), "��������� �����");
		}
	private: System::Void ����������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			char s[100];
			tabControl1->SelectTab(2);
			DataTable^ Table1;
			Table1 = gcnew DataTable();
			this->dataGridView2->DataSource = Table1;
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->ReadOnly = true;

			Table1->Columns->Add("��� ������");
			Table1->Columns->Add("���-��");
			Table1->Columns->Add("���� ���.");

			this->dataGridView2->Columns["���-��"]->HeaderCell->Style->Alignment =
				DataGridViewContentAlignment::MiddleRight;
			this->dataGridView2->Columns["���-��"]->DefaultCellStyle->Alignment =
				DataGridViewContentAlignment::MiddleRight;
			this->dataGridView2->Columns["���� ���."]->HeaderCell->Style->Alignment =
				DataGridViewContentAlignment::MiddleRight;
			this->dataGridView2->Columns["���� ���."]->DefaultCellStyle->Alignment =
				DataGridViewContentAlignment::MiddleRight;

			make_list();
			for (struct list* nt = sp; nt != NULL; nt = nt->next)
			{
				DataRow^ row = Table1->Rows->Add();
				row[0] = gcnew String(nt->kind);
				row[1] = nt->count;
				row[2] = nt->price;
			}
		}
private: System::Void �������������������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			char s[100];
			tabControl1->SelectTab(3);
			DataTable^ Table1;
			Table1 = gcnew DataTable();
			this->dataGridView3->DataSource = Table1;
			this->dataGridView3->AllowUserToAddRows = false;
			this->dataGridView3->AllowUserToDeleteRows = false;
			this->dataGridView3->ReadOnly = true;

			Table1->Columns->Add("��� ������");
			Table1->Columns->Add("���-��");
			Table1->Columns->Add("���� ���.");

			this->dataGridView3->Columns["���-��"]->HeaderCell->Style->Alignment =
				DataGridViewContentAlignment::MiddleRight;
			this->dataGridView3->Columns["���-��"]->DefaultCellStyle->Alignment =
				DataGridViewContentAlignment::MiddleRight;
			this->dataGridView3->Columns["���� ���."]->HeaderCell->Style->Alignment =
				DataGridViewContentAlignment::MiddleRight;
			this->dataGridView3->Columns["���� ���."]->DefaultCellStyle->Alignment =
				DataGridViewContentAlignment::MiddleRight;
			make_list();
			struct list* tail = sp;
			while (tail->next != NULL) tail = tail->next;
			for (struct list* nt = tail; nt != NULL; nt = nt->prev)
			{
				DataRow^ row = Table1->Rows->Add();
				row[0] = gcnew String(nt->kind);
				row[1] = nt->count;
				row[2] = nt->price;
			}
		}
private: System::Void ������������������1000�ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			char s[100];
			tabControl1->SelectTab(4);
			DataTable^ Table1;
			Table1 = gcnew DataTable();
			this->dataGridView4->DataSource = Table1;
			this->dataGridView4->AllowUserToAddRows = false;
			this->dataGridView4->AllowUserToDeleteRows = false;
			this->dataGridView4->ReadOnly = true;

			Table1->Columns->Add("�����");
			Table1->Columns->Add("��� ������");
			Table1->Columns->Add("����� �.");
			Table1->Columns->Add("���� ���.");

			this->dataGridView4->Columns["����� �."]->HeaderCell->Style->Alignment =
				DataGridViewContentAlignment::MiddleRight;
			this->dataGridView4->Columns["����� �."]->DefaultCellStyle->Alignment =
				DataGridViewContentAlignment::MiddleRight;
			this->dataGridView4->Columns["���� ���."]->HeaderCell->Style->Alignment =
				DataGridViewContentAlignment::MiddleRight;
			this->dataGridView4->Columns["���� ���."]->DefaultCellStyle->Alignment =
				DataGridViewContentAlignment::MiddleRight;
			for (int i = 0; i < count; i++)
			{
				if (clients[i].price > 1000)
				{
					DataRow^ row = Table1->Rows->Add();
					row[0] = gcnew String(clients[i].address);
					row[1] = gcnew String(clients[i].kind);
					row[2] = clients[i].weight;
					row[3] = clients[i].price;
				}
			}
		}
private: System::Void ����������������������ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
			char s[80];
			unsigned int total = 0;
			for (unsigned int i = 0; i < count; i++)
			{
				if (strcmp(clients[i].kind, "�����") == 0) total++;
			}

			sprintf(s, "%u ����\n", total);
			MessageBox::Show(gcnew String(s), "���������� ������� �����");
		}
private: System::Void �������������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			char s[100];
			tabControl1->SelectTab(5);
			DataTable^ Table1;
			Table1 = gcnew DataTable();
			this->dataGridView5->DataSource = Table1;
			this->dataGridView5->AllowUserToAddRows = false;
			this->dataGridView5->AllowUserToDeleteRows = false;
			this->dataGridView5->ReadOnly = true;

			Table1->Columns->Add("���1");
			Table1->Columns->Add("���2");
			Table1->Columns->Add("���� ���.");


			this->dataGridView5->Columns["���� ���."]->HeaderCell->Style->Alignment =
				DataGridViewContentAlignment::MiddleRight;
			this->dataGridView5->Columns["���� ���."]->DefaultCellStyle->Alignment =
				DataGridViewContentAlignment::MiddleRight;
			for (unsigned int i = 0; i < count; i++)
			{
				for (unsigned int j = i + 1; j < count; j++)
				{
					struct client a = clients[i];
					struct client b = clients[j];
					if (strcmp(a.kind, b.kind) == 0) continue;
					if (a.price != b.price) continue;
					DataRow^ row = Table1->Rows->Add();
					row[0] = gcnew String(a.kind);
					row[1] = gcnew String(b.kind);
					row[2] = a.price;
				}
			}
		}
	private: System::Void �������������������������������ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
			char s[100];
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
			if (found_match)
			{
				sprintf(
					s,
					"����: %7ld\n"
					"��� 1: %-20s\n"
					"��� 2: %-20s\n", 
					a.price, 
					a.kind, 
					b.kind
				);
			}
			else sprintf(s, "���������� �� �������.\n");
			MessageBox::Show(gcnew String(s), "������ ������� � �����������	�����");
		}
private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			tabControl1->SelectTab(0);
		}
private: System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			tabControl1->SelectTab(1);
		}
private: System::Void tabPage1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			if (clients == NULL) return;
			Pen^ myPen = gcnew Pen(System::Drawing::Color::Black, 3);
			SolidBrush^ myBrush = gcnew SolidBrush(Color::FromArgb(196, 0, 0, 0));
			System::Drawing::Font^ myFont = gcnew System::Drawing::Font("Arial", 8);
			int i, K;
			int iRed, iGreen, iBlue;
			int aStart, aEnd;
			long Sum;
			float xPos, yPos;
			Graphics^ g = tabPage1->CreateGraphics();
			g->Clear(System::Drawing::Color::LightGray);
			make_list();
			K = 0; Sum = 0;
			for (struct list* nt = sp; nt != NULL; nt = nt->next)
			{
				K++;
				Sum += nt->price;
			}
			g->DrawEllipse(myPen, 25, 25, 185, 185);
			aEnd = 0;
			i = 0;
			for (struct list* nt = sp; nt != NULL; nt = nt->next, i++)
			{
				iRed = (((i + 1) & 4) > 0) * 255 / (i / 8 + 1);
				iGreen = (((i + 1) & 2) > 0) * 255 / (i / 8 + 1);
				iBlue = (((i + 1) & 1) > 0) * 255 / (i / 8 + 1);
				aStart = aEnd;
				aEnd += nt->price * 360 / Sum;
				if (i == K - 1)aEnd = 360;
				myBrush->Color::set(Color::FromArgb(196, iRed, iGreen, iBlue));
				g->FillPie(myBrush, 25, 25, 185, 185, aStart, aEnd - aStart);
				g->FillRectangle(myBrush, 300, 50 + (i - 1) * 20, 20, 20);
				myBrush->Color::set(Color::FromArgb(196, 0, 0, 0));
				xPos = 30 + (185 - 25) / 2 + (185 - 25) / 1.5 * Math::Cos(Math::PI * (aStart + aEnd) / 360);
				yPos = 30 + (185 - 25) / 2 + (185 - 25) / 1.5 * Math::Sin(Math::PI * (aStart + aEnd) / 360);
				g->DrawString(gcnew String(nt->kind), myFont, myBrush, 320, 55 + (i - 1) * 20);
				g->DrawString(Convert::ToString(nt->price * 100 / Sum) + "%", myFont, myBrush, xPos, yPos);
			}
		}
};
}

