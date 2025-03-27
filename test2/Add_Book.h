#pragma once
#include <msclr/marshal_cppstd.h>
#include <sqlite3.h> 
#include <iostream>
#include <fstream>
#include <string>
#include <array>


namespace test2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO; // Для работы с файлами (Path::GetFileName)
	using namespace msclr::interop; // Для marshal_as

	/// <summary>
	/// Сводка для add_Book
	/// </summary>
	public ref class add_Book : public System::Windows::Forms::Form
	{
	public:
		add_Book(void)
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
		~add_Book()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonReturnToMain_Click;
	private: System::Windows::Forms::Button^ btnBrowse;
	private: System::Windows::Forms::Button^ btnUpload;


	private: System::Windows::Forms::TextBox^ txtFilePath;
	private: System::Windows::Forms::Label^ lblStatus;

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(add_Book::typeid));
			this->buttonReturnToMain_Click = (gcnew System::Windows::Forms::Button());
			this->btnBrowse = (gcnew System::Windows::Forms::Button());
			this->btnUpload = (gcnew System::Windows::Forms::Button());
			this->txtFilePath = (gcnew System::Windows::Forms::TextBox());
			this->lblStatus = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// buttonReturnToMain_Click
			// 
			this->buttonReturnToMain_Click->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonReturnToMain_Click.BackgroundImage")));
			this->buttonReturnToMain_Click->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->buttonReturnToMain_Click->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonReturnToMain_Click->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonReturnToMain_Click->ForeColor = System::Drawing::Color::SlateGray;
			this->buttonReturnToMain_Click->Location = System::Drawing::Point(29, 306);
			this->buttonReturnToMain_Click->Name = L"buttonReturnToMain_Click";
			this->buttonReturnToMain_Click->Size = System::Drawing::Size(60, 50);
			this->buttonReturnToMain_Click->TabIndex = 0;
			this->buttonReturnToMain_Click->UseVisualStyleBackColor = true;
			this->buttonReturnToMain_Click->Click += gcnew System::EventHandler(this, &add_Book::buttonReturnToMain_Click_Click);
			// 
			// btnBrowse
			// 
			this->btnBrowse->Location = System::Drawing::Point(147, 253);
			this->btnBrowse->Name = L"btnBrowse";
			this->btnBrowse->Size = System::Drawing::Size(100, 56);
			this->btnBrowse->TabIndex = 1;
			this->btnBrowse->Text = L"выбрать книгу";
			this->btnBrowse->UseVisualStyleBackColor = true;
			this->btnBrowse->Click += gcnew System::EventHandler(this, &add_Book::btnBrowse_Click);
			// 
			// btnUpload
			// 
			this->btnUpload->Location = System::Drawing::Point(310, 252);
			this->btnUpload->Name = L"btnUpload";
			this->btnUpload->Size = System::Drawing::Size(112, 57);
			this->btnUpload->TabIndex = 2;
			this->btnUpload->Text = L"Загрузить";
			this->btnUpload->UseVisualStyleBackColor = true;
			this->btnUpload->Click += gcnew System::EventHandler(this, &add_Book::btnUpload_Click);
			// 
			// txtFilePath
			// 
			this->txtFilePath->Location = System::Drawing::Point(120, 132);
			this->txtFilePath->Multiline = true;
			this->txtFilePath->Name = L"txtFilePath";
			this->txtFilePath->ReadOnly = true;
			this->txtFilePath->Size = System::Drawing::Size(211, 45);
			this->txtFilePath->TabIndex = 3;
			// 
			// lblStatus
			// 
			this->lblStatus->AutoSize = true;
			this->lblStatus->Location = System::Drawing::Point(529, 222);
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(35, 13);
			this->lblStatus->TabIndex = 4;
			this->lblStatus->Text = L"label1";
			// 
			// add_Book
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SlateGray;
			this->ClientSize = System::Drawing::Size(777, 378);
			this->Controls->Add(this->lblStatus);
			this->Controls->Add(this->txtFilePath);
			this->Controls->Add(this->btnUpload);
			this->Controls->Add(this->btnBrowse);
			this->Controls->Add(this->buttonReturnToMain_Click);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"add_Book";
			this->Text = L"add_Book";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void buttonReturnToMain_Click_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
	private: System::Void btnBrowse_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();

		openFileDialog1->Filter = "PDF Files (*.pdf)|*.pdf";
		openFileDialog1->Title = "Select a PDF File";

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			txtFilePath->Text = openFileDialog1->FileName;
		}
	}
private: System::Void btnUpload_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrEmpty(txtFilePath->Text)) {
		lblStatus->Text = "Выберите PDF-файл!";
		return;
	} 
	try {
		// 1. Чтение данных из файла PDF
		String^ filePath = txtFilePath->Text;
		std::ifstream fileStream;

		marshal_context context;
		std::string file_path_utf8 = context.marshal_as<std::string>(filePath);

		fileStream.open(file_path_utf8, std::ios::binary);
		if (!fileStream.is_open())
		{
			lblStatus->Text = "Не удалось открыть файл!";
			return;
		}
		fileStream.seekg(0, std::ios::end);
		int length = fileStream.tellg();
		fileStream.seekg(0, std::ios::beg);

		char* buffer = new char[length];
		fileStream.read(buffer, length);
		fileStream.close();
		array<Byte>^ pdfData = gcnew array<Byte>(length);
		for (int i = 0; i < length; i++) {
			pdfData[i] = buffer[i];
		}
		delete[] buffer;


		// 2. Сохранение в базу данных SQLite
		sqlite3* db;
		int rc = sqlite3_open("bd_MyBooks.db", &db);
		if (rc != SQLITE_OK) {
			lblStatus->Text = "Не удалось открыть базу данных: " + marshal_as<String^>(sqlite3_errmsg(db));
			sqlite3_close(db);
			return;
		}
	}
	catch (Exception^ ex) {
		lblStatus->Text = "Ошибка: " + ex->Message;
	}
}
};
}
