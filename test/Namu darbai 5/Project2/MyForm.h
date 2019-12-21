#pragma once
#include "Funkcijos.h"

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	int A[256][256];
	int a, b, c, d, f = 0;
	double ee = 0;
	std::string text = "";

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(344, 118);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(76, 136);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(213, 49);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Skaičiuoti";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ClientSize = System::Drawing::Size(368, 196);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"Dvimatis masyvas";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		skait(A, d, f);
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		ofstream fs("rez.txt");
		skait(A, d, f);
		fs << "Pries pakeitima:" << endl;
		spausd(A, fs);
		textBox1->Text += "Pries pakeitima\r\n";
		while (a < f)
		{
			rodyti(text, A, d, a);
			textBox1->Text += gcnew String(text.c_str()) + "\r\n";
			a++;
		}
		a = 0;
		calc(A, 2, ee);
		calc2(A, b);
		keit(A, 0, ee);
		fs << "Po pakeitimo:" << endl;
		spausd(A, fs);
		textBox1->Text += "Po pakeitimo\r\n";
		while (a < f)
		{
			rodyti(text, A, d, a);
			textBox1->Text += gcnew String(text.c_str()) + "\r\n";
			a++;
		}
	}
	};
}
