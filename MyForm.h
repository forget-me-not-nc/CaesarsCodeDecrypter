#include "Decoder.h"
#include "Encryptor.h"
#include "Eng_decoder.h"
#include "Ukr_decoder.h"
#include "Eng_Encryptor.h"
#include "Ukr_Encryptor.h"
#include "OptionAlert.h"
#include <fstream>//для роботи з файлами

#pragma once

namespace Caesarscode {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Runtime::InteropServices;

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
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ErrorProvider^ TextLengthError;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::ErrorProvider^ KeyInput;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;




	private: System::ComponentModel::IContainer^ components;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->TextLengthError = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->KeyInput = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TextLengthError))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->KeyInput))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(15, 25);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(370, 200);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Input:";
			this->label1->MouseEnter += gcnew System::EventHandler(this, &MyForm::label1_MouseEnter);
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(420, 25);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(355, 200);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(417, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Output:";
			this->label2->MouseEnter += gcnew System::EventHandler(this, &MyForm::label2_MouseEnter);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(673, 295);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 54);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			this->button1->MouseEnter += gcnew System::EventHandler(this, &MyForm::button1_MouseEnter);
			// 
			// checkBox1
			// 
			this->checkBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(6, 16);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(71, 17);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"Ukrainian";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(6, 53);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(60, 17);
			this->checkBox2->TabIndex = 6;
			this->checkBox2->Text = L"English";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged);
			// 
			// textBox3
			// 
			this->textBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->textBox3->Location = System::Drawing::Point(43, 285);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(67, 20);
			this->textBox3->TabIndex = 7;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox3_KeyPress);
			// 
			// label3
			// 
			this->label3->AccessibleDescription = L"";
			this->label3->AccessibleName = L"";
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 288);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(28, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Key:";
			this->label3->MouseEnter += gcnew System::EventHandler(this, &MyForm::label3_MouseEnter);
			// 
			// TextLengthError
			// 
			this->TextLengthError->BlinkRate = 100;
			this->TextLengthError->ContainerControl = this;
			this->TextLengthError->RightToLeftChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(6, 15);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(62, 17);
			this->checkBox3->TabIndex = 10;
			this->checkBox3->Text = L"Encrypt";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox3_CheckedChanged);
			this->checkBox3->MouseEnter += gcnew System::EventHandler(this, &MyForm::checkBox3_MouseEnter);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(6, 53);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(63, 17);
			this->checkBox4->TabIndex = 11;
			this->checkBox4->Text = L"Decrypt";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox4_CheckedChanged);
			this->checkBox4->MouseEnter += gcnew System::EventHandler(this, &MyForm::checkBox4_MouseEnter);
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->groupBox1->Controls->Add(this->checkBox3);
			this->groupBox1->Controls->Add(this->checkBox4);
			this->groupBox1->Location = System::Drawing::Point(210, 273);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(114, 82);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->groupBox2->Controls->Add(this->checkBox1);
			this->groupBox2->Controls->Add(this->checkBox2);
			this->groupBox2->Location = System::Drawing::Point(542, 273);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(125, 82);
			this->groupBox2->TabIndex = 12;
			this->groupBox2->TabStop = false;
			this->groupBox2->Enter += gcnew System::EventHandler(this, &MyForm::groupBox2_Enter);
			// 
			// KeyInput
			// 
			this->KeyInput->BlinkRate = 100;
			this->KeyInput->ContainerControl = this;
			this->KeyInput->RightToLeftChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(126, 289);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(78, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Choose option:";
			this->label4->MouseEnter += gcnew System::EventHandler(this, &MyForm::label4_MouseEnter);
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(443, 289);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(93, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Choose language:";
			this->label5->MouseEnter += gcnew System::EventHandler(this, &MyForm::label5_MouseEnter);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(784, 361);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(1600, 800);
			this->MinimumSize = System::Drawing::Size(800, 400);
			this->Name = L"MyForm";
			this->Text = L"Caesar\'s code";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TextLengthError))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->KeyInput))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		
			button1->Enabled = false;//блокування кнопки Старт

	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		if (textBox1->TextLength == 0)
		{
			button1->Enabled = false;//бокування кнопки Старт
		}
		else
		{
			button1->Enabled = true;//знаття блоку з кнопки Старт
		}

		if(checkBox4->Checked)
		{
			TextLengthError->SetError(textBox1, "In order for the text to be properly deciphered, the text should be large enough to have at least 40 characters\n"//вивід застереження
													"Для того щоб текст був правильно розшифрований текст повинен бути досить великим, хочаби 40 символів");			
		}
	}

	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		textBox2->ReadOnly = true;//блокування поля для виводу 
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		TextLengthError->SetError(textBox1,"");//зняття застереження
		KeyInput->SetError(textBox3, "");//зняття застереження

		if (checkBox4->Checked)
		{

			if (checkBox1->Checked)//UA
			{

				string Code = (const char*)(Marshal::StringToHGlobalAnsi(textBox1->Text)).ToPointer();//перестворення системної строки в звичайну методом марш

				Ukr_decoder C;//створення об`экту класу
				C.Decode(Code);//визов функції початку процессу

				FileIn(Code);//визиваємо метод запису результуючого тексту в файл

				String^ TextToOutput = gcnew System::String(Code.c_str());//перетворення отриманого тексту в системну строку

				textBox2->Clear();//очистка поля виводу
				textBox2->Text = TextToOutput;//вивід

				textBox3->Clear();//очистка поля виводу ключа
				textBox3->Text = C.Res_key.ToString();//вивід ключа

			}
			else if (checkBox2->Checked)//ENG
			{

				string Code = (const char*)(Marshal::StringToHGlobalAnsi(textBox1->Text)).ToPointer();//перестворення системної строки в звичайну методом маршалінга строк

				Eng_decoder C;//створення об`экту класу
				C.Decode(Code);//визов функції початку процессу

				FileIn(Code);//визиваємо метод запису результуючого тексту в файл

				String^ TextToOutput = gcnew System::String(Code.c_str());//перетворення отриманого тексту в системну строку

				textBox2->Clear();//очистка поля виводу
				textBox2->Text = TextToOutput;//вивід

				textBox3->Clear();//очистка поля виводу ключа
				textBox3->Text = C.Res_key.ToString();//вивід ключа

			}
			else
			{
				MessageBox::Show("Need choose language.");//якщо ніяка мова не вибрана, вивід повідомленняпро помилку
			}
		}
		else if (checkBox3->Checked)//вибір функції кодування
		{
			if (textBox3->TextLength == 0)//якщо не вписаний ключ
			{
				MessageBox::Show("Need to choose key.");//то вивід повідомлення про помилку
			}
			else
			{
				if (checkBox1->Checked)//UA
				{

					string Sentence = (const char*)(Marshal::StringToHGlobalAnsi(textBox1->Text)).ToPointer();//перестворення системної строки в звичайну методом маршалінга строк
					string Key = (const char*)(Marshal::StringToHGlobalAnsi(textBox3->Text)).ToPointer();//перестворення системної строки в звичайну методом маршалінга строк
					
					int key = atoi(Key.c_str());//перетвореня строки в число з поля для вводу ключа

					Ukr_Encryptor u1;//створення об`экту класу
					u1.Encryption(Sentence, key);//визов функції початку процессу

					FileIn(Sentence);//визиваємо метод запису результуючого тексту в файл

					String^ TextToOutput = gcnew System::String(Sentence.c_str());//перетворення отриманого тексту в системну строку

					textBox2->Clear();
					textBox2->Text = TextToOutput;
		
				}
				else if (checkBox2->Checked) //ENG
				{

					string Sentence = (const char*)(Marshal::StringToHGlobalAnsi(textBox1->Text)).ToPointer();
					string Key = (const char*)(Marshal::StringToHGlobalAnsi(textBox3->Text)).ToPointer();

					int key = atoi(Key.c_str());//переьворення строки в число
										
					Eng_Encryptor e1;//створення об`экту класу
					e1.Encryption(key, Sentence);//визов функції початку процессу

					FileIn(Sentence);//визиваємо метод запису результуючого тексту в файл

					String^ TextToOutput = gcnew System::String(Sentence.c_str());

					textBox2->Clear();																	
					textBox2->Text = TextToOutput;//вивід 
					
				}
				else
				{
					MessageBox::Show("Need to choose language.");//виодиться повідомлення якщо мова не вибрана
				}
			}
		}
		else
		{
			MessageBox::Show("Need to choose option.");//вивід якщо не вибрана функція обробки тексту
		}
		
	};

	private: System::Void checkBox1_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {

		if (checkBox1->Checked)
		{
			checkBox2->Checked = false;	//зняття галочки якщо вибрана інша функція
		}

	}
	private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

		if (checkBox2->Checked)
		{									
			checkBox1->Checked = false;	//зняття галочки якщо вибрана інша функція
		}
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

		if (checkBox3->Checked)
		{
			checkBox4->Checked = false;				//зняття галочки якщо вибрана інша функція
			textBox3->ReadOnly = false;				//розблокування поля для вводу ключа
			TextLengthError->SetError(textBox1, "");//зняття застереження
		}

	}
	private: System::Void checkBox4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	
		if (checkBox4->Checked)
		{
			checkBox3->Checked = false;		//зняття галочки якщо вибрана інша функція
			textBox3->ReadOnly = true;		//блокування поля для вводу ключа
			KeyInput->SetError(textBox3, "");//зняття застереження
			textBox3->Clear();
		}
	}
	private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {

	}

		  
	private: System::Void textBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		
		if ((e->KeyChar != 8) && (e->KeyChar < 48) || (e->KeyChar > 57))//блокуємо ввід в поле для ключа всього крім цифр
		{
			e->KeyChar = Char(0);														

			if (!checkBox4->Checked)
			{
				KeyInput->SetError(textBox3, "Only numbers can be entered\n"//вивід поіідомлення
											 "Можна ввести тільки цифри");
			}
			
		}
		
	}
	private: System::Void label3_MouseEnter(System::Object^ sender, System::EventArgs^ e) {	//все що нижче - підказки при наведенні на елементи форми
		
		ToolTip^ tt = gcnew ToolTip();														
		tt->SetToolTip(this->label3, "Ключ");	
	}
	private: System::Void label1_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		
		ToolTip^ tt = gcnew ToolTip();
		tt->SetToolTip(this->label1, "Ввід");
	}
	private: System::Void label2_MouseEnter(System::Object^ sender, System::EventArgs^ e) {

		ToolTip^ tt = gcnew ToolTip();
		tt->SetToolTip(this->label2, "Вивід");
	}
	private: System::Void label4_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		
		ToolTip^ tt = gcnew ToolTip();
		tt->SetToolTip(this->label4, "Виберіть опцію");
	}
	private: System::Void checkBox3_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		
		ToolTip^ tt = gcnew ToolTip();
		tt->SetToolTip(this->checkBox3, "Зашифрувати");
	}
	private: System::Void checkBox4_MouseEnter(System::Object^ sender, System::EventArgs^ e) {

		 ToolTip^ tt = gcnew ToolTip();	
		 tt->SetToolTip(this->checkBox4, "Розшифрувати");
	}
	private: System::Void label5_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		
		ToolTip^ tt = gcnew ToolTip();
		tt->SetToolTip(this->label5, "Виберіть мову");
	}
	private: System::Void button1_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
			ToolTip^ tt = gcnew ToolTip();
			tt->SetToolTip(this->button1, "Почати");
	}
	private: void FileIn(string str);
};

}

