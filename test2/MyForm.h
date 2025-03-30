#pragma once

#include "Add_Book.h"
#include "Edit_Book.h"

namespace test2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonGoToAddBook;
	private: System::Windows::Forms::Button^ buttonEditBook_Click;
	protected:


	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;



	private: System::ComponentModel::IContainer^ components;


	protected:

	protected:




	protected:

	protected:


	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->buttonGoToAddBook = (gcnew System::Windows::Forms::Button());
			this->buttonEditBook_Click = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonGoToAddBook
			// 
			this->buttonGoToAddBook->BackColor = System::Drawing::Color::SlateGray;
			this->buttonGoToAddBook->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonGoToAddBook.BackgroundImage")));
			this->buttonGoToAddBook->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->buttonGoToAddBook->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonGoToAddBook->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonGoToAddBook->ForeColor = System::Drawing::Color::SlateGray;
			this->buttonGoToAddBook->Location = System::Drawing::Point(106, 248);
			this->buttonGoToAddBook->Name = L"buttonGoToAddBook";
			this->buttonGoToAddBook->Size = System::Drawing::Size(90, 69);
			this->buttonGoToAddBook->TabIndex = 0;
			this->buttonGoToAddBook->TabStop = false;
			this->buttonGoToAddBook->UseVisualStyleBackColor = false;
			this->buttonGoToAddBook->Click += gcnew System::EventHandler(this, &MyForm::buttonGoToAddBook_Click);
			// 
			// buttonEditBook_Click
			// 
			this->buttonEditBook_Click->BackColor = System::Drawing::Color::SlateGray;
			this->buttonEditBook_Click->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonEditBook_Click.BackgroundImage")));
			this->buttonEditBook_Click->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->buttonEditBook_Click->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonEditBook_Click->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonEditBook_Click->ForeColor = System::Drawing::Color::SlateGray;
			this->buttonEditBook_Click->Location = System::Drawing::Point(588, 248);
			this->buttonEditBook_Click->Name = L"buttonEditBook_Click";
			this->buttonEditBook_Click->Size = System::Drawing::Size(90, 69);
			this->buttonEditBook_Click->TabIndex = 1;
			this->buttonEditBook_Click->TabStop = false;
			this->buttonEditBook_Click->UseVisualStyleBackColor = false;
			this->buttonEditBook_Click->Click += gcnew System::EventHandler(this, &MyForm::buttonEditBook_Click_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Azure;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox1->Location = System::Drawing::Point(106, 43);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(89, 95);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Azure;
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox2->Location = System::Drawing::Point(258, 43);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(89, 95);
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Azure;
			this->pictureBox3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox3->Location = System::Drawing::Point(421, 43);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(89, 95);
			this->pictureBox3->TabIndex = 4;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Azure;
			this->pictureBox4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox4->Location = System::Drawing::Point(564, 43);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(89, 95);
			this->pictureBox4->TabIndex = 5;
			this->pictureBox4->TabStop = false;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(45, 70);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(46, 40);
			this->button1->TabIndex = 6;
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(680, 70);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(46, 40);
			this->button2->TabIndex = 7;
			this->button2->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SlateGray;
			this->ClientSize = System::Drawing::Size(777, 378);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->buttonEditBook_Click);
			this->Controls->Add(this->buttonGoToAddBook);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::SlateGray;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"MyBook";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	
	

private: System::Void buttonGoToAddBook_Click(System::Object^ sender, System::EventArgs^ e) {
	add_Book^ newForm = gcnew add_Book();
	this->Hide();
	newForm->ShowDialog();
	this->Show();
}
private: System::Void buttonEditBook_Click_Click(System::Object^ sender, System::EventArgs^ e) {
	Edit_Book^ newForm1 = gcnew Edit_Book();
	this->Hide();
	newForm1->ShowDialog();
	this->Show();
}
};
}