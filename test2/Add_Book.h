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
	private: System::Windows::Forms::TextBox^ txtCoverImagePath;

	private: System::Windows::Forms::Button^ btnBrowseCover_Click;
	private: System::Windows::Forms::PictureBox^ pictureBoxCover;
	private: System::Windows::Forms::TextBox^ txtTitle;





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
			this->txtCoverImagePath = (gcnew System::Windows::Forms::TextBox());
			this->btnBrowseCover_Click = (gcnew System::Windows::Forms::Button());
			this->pictureBoxCover = (gcnew System::Windows::Forms::PictureBox());
			this->txtTitle = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCover))->BeginInit();
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
			this->btnBrowse->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnBrowse->Location = System::Drawing::Point(29, 54);
			this->btnBrowse->Name = L"btnBrowse";
			this->btnBrowse->Size = System::Drawing::Size(111, 56);
			this->btnBrowse->TabIndex = 1;
			this->btnBrowse->Text = L"выбрать книгу";
			this->btnBrowse->UseVisualStyleBackColor = true;
			this->btnBrowse->Click += gcnew System::EventHandler(this, &add_Book::btnBrowse_Click);
			// 
			// btnUpload
			// 
			this->btnUpload->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnUpload->Location = System::Drawing::Point(566, 303);
			this->btnUpload->Name = L"btnUpload";
			this->btnUpload->Size = System::Drawing::Size(112, 57);
			this->btnUpload->TabIndex = 2;
			this->btnUpload->Text = L"Загрузить";
			this->btnUpload->UseVisualStyleBackColor = true;
			this->btnUpload->Click += gcnew System::EventHandler(this, &add_Book::btnUpload_Click);
			// 
			// txtFilePath
			// 
			this->txtFilePath->Location = System::Drawing::Point(197, 60);
			this->txtFilePath->Multiline = true;
			this->txtFilePath->Name = L"txtFilePath";
			this->txtFilePath->ReadOnly = true;
			this->txtFilePath->Size = System::Drawing::Size(211, 45);
			this->txtFilePath->TabIndex = 3;
			// 
			// lblStatus
			// 
			this->lblStatus->AutoSize = true;
			this->lblStatus->Location = System::Drawing::Point(285, 113);
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(35, 13);
			this->lblStatus->TabIndex = 4;
			this->lblStatus->Text = L"label1";
			// 
			// txtCoverImagePath
			// 
			this->txtCoverImagePath->Location = System::Drawing::Point(197, 152);
			this->txtCoverImagePath->Multiline = true;
			this->txtCoverImagePath->Name = L"txtCoverImagePath";
			this->txtCoverImagePath->ReadOnly = true;
			this->txtCoverImagePath->Size = System::Drawing::Size(211, 45);
			this->txtCoverImagePath->TabIndex = 5;
			// 
			// btnBrowseCover_Click
			// 
			this->btnBrowseCover_Click->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnBrowseCover_Click->Location = System::Drawing::Point(29, 146);
			this->btnBrowseCover_Click->Name = L"btnBrowseCover_Click";
			this->btnBrowseCover_Click->Size = System::Drawing::Size(111, 59);
			this->btnBrowseCover_Click->TabIndex = 6;
			this->btnBrowseCover_Click->Text = L"выбрать обложку";
			this->btnBrowseCover_Click->UseVisualStyleBackColor = true;
			this->btnBrowseCover_Click->Click += gcnew System::EventHandler(this, &add_Book::btnBrowseCover_Click_Click);
			// 
			// pictureBoxCover
			// 
			this->pictureBoxCover->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBoxCover->Cursor = System::Windows::Forms::Cursors::AppStarting;
			this->pictureBoxCover->Location = System::Drawing::Point(496, 16);
			this->pictureBoxCover->Name = L"pictureBoxCover";
			this->pictureBoxCover->Size = System::Drawing::Size(237, 268);
			this->pictureBoxCover->TabIndex = 7;
			this->pictureBoxCover->TabStop = false;
			// 
			// txtTitle
			// 
			this->txtTitle->Location = System::Drawing::Point(197, 235);
			this->txtTitle->Multiline = true;
			this->txtTitle->Name = L"txtTitle";
			this->txtTitle->Size = System::Drawing::Size(211, 45);
			this->txtTitle->TabIndex = 8;
			// 
			// add_Book
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SlateGray;
			this->ClientSize = System::Drawing::Size(777, 378);
			this->Controls->Add(this->txtTitle);
			this->Controls->Add(this->pictureBoxCover);
			this->Controls->Add(this->btnBrowseCover_Click);
			this->Controls->Add(this->txtCoverImagePath);
			this->Controls->Add(this->lblStatus);
			this->Controls->Add(this->txtFilePath);
			this->Controls->Add(this->btnUpload);
			this->Controls->Add(this->btnBrowse);
			this->Controls->Add(this->buttonReturnToMain_Click);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"add_Book";
			this->Text = L"add_Book";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCover))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//кнопка возврата на 1 страницу
	private: System::Void buttonReturnToMain_Click_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}


	//кнопка добавить книгу
	private: System::Void btnBrowse_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();

		openFileDialog1->Filter = "PDF Files (*.pdf)|*.pdf";
		openFileDialog1->Title = "Select a PDF File";

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			txtFilePath->Text = openFileDialog1->FileName;
		}
	}


	//кнопка загрузки обложки
	private: System::Void btnBrowseCover_Click_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openFileDialogCover = gcnew OpenFileDialog();

		openFileDialogCover->Filter = "Image Files (*.jpg, *.jpeg, *.png, *.bmp)|*.jpg;*.jpeg;*.png;*.bmp";
		openFileDialogCover->Title = "Select a Cover Image";

		if (openFileDialogCover->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				String^ imagePath = openFileDialogCover->FileName;
				txtCoverImagePath->Text = imagePath; // Set the path to the TextBox

				//Load the image into the PictureBox
				pictureBoxCover->Image = System::Drawing::Image::FromFile(imagePath);  // Use System::Drawing::Image
			}
			catch (Exception^ ex) {
				MessageBox::Show("Ошибка при загрузке изображения: " + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				// Handle the exception (e.g., log it, clear the PictureBox)
				pictureBoxCover->Image = nullptr; // Clear the PictureBox if loading fails
			}
		}
		else {
			// If the user cancels the dialog, clear the TextBox and PictureBox (optional)
			txtCoverImagePath->Text = "";
			pictureBoxCover->Image = nullptr;
		}
	}


	//кнопка загрузить книгу в базу даный sqlite (LibraryDatabase.db)
private: System::Void btnUpload_Click(System::Object^ sender, System::EventArgs^ e) {
	// Проверка заполнения всех обязательных полей
	if (String::IsNullOrEmpty(txtFilePath->Text)) {
		MessageBox::Show("Пожалуйста, выберите PDF файл книги", "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (String::IsNullOrEmpty(txtCoverImagePath->Text)) {
		MessageBox::Show("Пожалуйста, выберите обложку книги", "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (String::IsNullOrEmpty(txtTitle->Text)) {
		MessageBox::Show("Пожалуйста, введите название книги", "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	try {
		// Чтение данных файлов в байтовые массивы
		array<Byte>^ pdfData = File::ReadAllBytes(txtFilePath->Text);
		array<Byte>^ coverData = File::ReadAllBytes(txtCoverImagePath->Text);
		String^ fileName = Path::GetFileName(txtFilePath->Text);
		String^ title = txtTitle->Text;

		// Подключение к SQLite базе данных
		sqlite3* db;
		String^ dbPath = "LibraryDatabase.db";
		int rc = sqlite3_open(msclr::interop::marshal_as<std::string>(dbPath).c_str(), &db);

		if (rc != SQLITE_OK) {
			throw gcnew Exception("Не удалось открыть базу данных: " + gcnew String(sqlite3_errmsg(db)));
		}

		// Создание таблицы, если она не существует
		const char* createTableSQL = "CREATE TABLE IF NOT EXISTS Books ("
			"Id INTEGER PRIMARY KEY AUTOINCREMENT, "
			"Title TEXT NOT NULL, "
			"PdfData BLOB NOT NULL, "
			"CoverImage BLOB NOT NULL, "
			"FileName TEXT NOT NULL, "
			"UploadDate TEXT DEFAULT CURRENT_TIMESTAMP);";

		char* errMsg = nullptr;
		rc = sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errMsg);
		if (rc != SQLITE_OK) {
			String^ error = gcnew String(errMsg);
			sqlite3_free(errMsg);
			sqlite3_close(db);
			throw gcnew Exception("Ошибка при создании таблицы: " + error);
		}

		// Подготовка SQL запроса для вставки данных
		sqlite3_stmt* stmt;
		const char* insertSQL = "INSERT INTO Books (Title, PdfData, CoverImage, FileName) VALUES (?, ?, ?, ?)";

		rc = sqlite3_prepare_v2(db, insertSQL, -1, &stmt, nullptr);
		if (rc != SQLITE_OK) {
			sqlite3_close(db);
			throw gcnew Exception("Ошибка подготовки SQL запроса: " + gcnew String(sqlite3_errmsg(db)));
		}

		// Привязка параметров
		// Название книги
		std::string titleStr = msclr::interop::marshal_as<std::string>(title);
		sqlite3_bind_text(stmt, 1, titleStr.c_str(), -1, SQLITE_TRANSIENT);

		// PDF данные
		pin_ptr<unsigned char> pdfPtr = &pdfData[0];
		sqlite3_bind_blob(stmt, 2, pdfPtr, pdfData->Length, SQLITE_TRANSIENT);

		// Обложка
		pin_ptr<unsigned char> coverPtr = &coverData[0];
		sqlite3_bind_blob(stmt, 3, coverPtr, coverData->Length, SQLITE_TRANSIENT);

		// Имя файла
		std::string fileNameStr = msclr::interop::marshal_as<std::string>(fileName);
		sqlite3_bind_text(stmt, 4, fileNameStr.c_str(), -1, SQLITE_TRANSIENT);

		// Выполнение запроса
		rc = sqlite3_step(stmt);
		if (rc != SQLITE_DONE) {
			String^ error = gcnew String(sqlite3_errmsg(db));
			sqlite3_finalize(stmt);
			sqlite3_close(db);
			throw gcnew Exception("Ошибка при выполнении запроса: " + error);
		}

		// Очистка
		sqlite3_finalize(stmt);
		sqlite3_close(db);

		// Сообщение об успехе
		MessageBox::Show("Книга успешно загружена в базу данных!", "Успех",
			MessageBoxButtons::OK, MessageBoxIcon::Information);

		// Очистка формы
		txtFilePath->Text = "";
		txtCoverImagePath->Text = "";
		txtTitle->Text = "";
		pictureBoxCover->Image = nullptr;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Ошибка при загрузке книги: " + ex->Message, "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	}
};
}
