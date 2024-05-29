#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdlib.h>
#include <math.h>

float lerp(float a, float b, float t)
{
	return a * (1.0 - t) + (b * t);
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
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown3;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::Button^ button2;



































	protected: 


	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(916, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(659, 432);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(245, 69);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(641, 489);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(659, 380);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(244, 20);
			this->numericUpDown1->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(659, 364);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(80, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Длительность";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(659, 325);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Размер";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(659, 341);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(244, 20);
			this->numericUpDown2->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(659, 286);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Число повторов";
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(659, 302);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(244, 20);
			this->numericUpDown3->TabIndex = 7;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(659, 234);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(245, 49);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Изменить цвет";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(916, 513);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Задание 8";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Color c = Color::Black;

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	const float dur = (float)this->numericUpDown1->Value;
	const float smult = (float)this->numericUpDown2->Value;
	const float niter = (float)this->numericUpDown3->Value;
	const float smin = 5;
	const int N = 4;

	const int xmin = 100;
	const int ymin = 200;
	const int xmax = 600;
	const int ymax = 200;
	array <PointF>^ points = { 
		PointF(),
		PointF(),
		PointF(),
		PointF()
	};
	Graphics^ g = pictureBox1->CreateGraphics();
	g->Clear(System::Drawing::Color::White);
	Pen^ myPen = gcnew Pen(System::Drawing::Color::Black, 3);
	if (smult <= 0)
	{
		MessageBox::Show("Размер должен быть больше нуля!", "Внимание!");
		return;
	}
	if (dur <= 0)
	{
		MessageBox::Show("Длительность должна быть больше нуля!", "Внимание!");
		return;
	}
	if (niter <= 0)
	{
		MessageBox::Show("Число повторов должно быть больше нуля!", "Внимание!");
		return;
	}

	DateTime start = DateTime::Now;
	while (true)
	{
		const double elapsed = (DateTime::Now - start).TotalSeconds;
		if (elapsed > dur) break;

		myPen->Color::set(Color::White);
		g->DrawPolygon(myPen, points);

		const float fr = (float)elapsed / dur;
		float tmp;
		tmp = ((float)elapsed / (dur / niter));
		tmp = tmp - Math::Floor(tmp);
		tmp = (Math::Sin(tmp * Math::PI * 2.0f) + 1.0f) / 2.0f;
		const float sz = lerp(smin, smin * smult, tmp);
		const float x = lerp(xmin, xmax, fr);
		const float y = lerp(ymin, ymax, fr);
		points[0] = PointF(x + sz, y + sz);
		points[1] = PointF(x - sz, y + sz);
		points[2] = PointF(x - sz, y - sz);
		points[3] = PointF(x + sz, y - sz);


		myPen->Color::set(c);
		g->DrawPolygon(myPen, points);
		_sleep(50);  // 30 FPS
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	colorDialog1->ShowDialog();
	c = colorDialog1->Color;
}
};
}

