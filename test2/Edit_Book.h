#pragma once
#include <sqlite3.h> 
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <msclr\marshal_cppstd.h>
#include <Windows.h>
#include <msclr/marshal.h>
#include <vcclr.h>


namespace test2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO; 
	using namespace System::Runtime::InteropServices;




	

	/// <summary>
	/// Сводка для Edit_Book
	/// 
	/// Сводка для Edit_Book
	/// </summary>
	public ref class Edit_Book : public System::Windows::Forms::Form
	{
	private:
		int selectedBookId = -1;



		// Загрузка списка книг в DataGridView
		void LoadBooksFromDatabase()
		{
			sqlite3* db;
			String^ dbPath = "LibraryDatabase.db";

			try {
				int rc = sqlite3_open(msclr::interop::marshal_as<std::string>(dbPath).c_str(), &db);
				if (rc != SQLITE_OK) {
					throw gcnew Exception("Ошибка подключения: " + gcnew String(sqlite3_errmsg(db)));
				}

				const char* sql = "SELECT Id, Title, FileName FROM Books;";
				sqlite3_stmt* stmt;

				rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
				if (rc != SQLITE_OK) {
					throw gcnew Exception("Ошибка запроса: " + gcnew String(sqlite3_errmsg(db)));
				}

				DataTable^ table = gcnew DataTable();
				table->Columns->Add("ID", Int32::typeid);
				table->Columns->Add("Название", String::typeid);
				table->Columns->Add("Файл", String::typeid);

				while (sqlite3_step(stmt) == SQLITE_ROW) {
					DataRow^ row = table->NewRow();
					row["ID"] = sqlite3_column_int(stmt, 0);
					row["Название"] = gcnew String((const char*)sqlite3_column_text(stmt, 1));
					row["Файл"] = gcnew String((const char*)sqlite3_column_text(stmt, 2));
					table->Rows->Add(row);
				}

				dataGridViewBooks->DataSource = table;
				dataGridViewBooks->Columns["ID"]->Visible = false;

				sqlite3_finalize(stmt);
				sqlite3_close(db);
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}



		// Загрузка обложки
		void LoadBookCover(int bookId)
		{
			try {
				sqlite3* db;
				String^ dbPath = "LibraryDatabase.db";

				if (sqlite3_open(msclr::interop::marshal_as<std::string>(dbPath).c_str(), &db) != SQLITE_OK) {
					throw gcnew Exception("Ошибка подключения");
				}

				const char* sql = "SELECT CoverImage FROM Books WHERE Id = ?;";
				sqlite3_stmt* stmt;

				sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
				sqlite3_bind_int(stmt, 1, bookId);

				if (sqlite3_step(stmt) == SQLITE_ROW) {
					const void* blob = sqlite3_column_blob(stmt, 0); //  Получаем BLOB-данные
					int blobSize = sqlite3_column_bytes(stmt, 0); //  Получаем BLOB-данные

					array<Byte>^ imageData = gcnew array<Byte>(blobSize);//Преобразование в управляемый массив
					Marshal::Copy(IntPtr((void*)blob), imageData, 0, blobSize);//  Копирование данных через Marshal

					MemoryStream^ ms = gcnew MemoryStream(imageData);//  Создание изображения
					pictureBoxCover->Image = Image::FromStream(ms);//  Создание изображения
				}

				sqlite3_finalize(stmt);
				sqlite3_close(db);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Ошибка загрузки обложки: " + ex->Message);
			}
		}



		// Открытие PDF
		void OpenPdf(int bookId)
		{
			try {
				sqlite3* db;
				String^ dbPath = "LibraryDatabase.db";

				if (sqlite3_open(msclr::interop::marshal_as<std::string>(dbPath).c_str(), &db) != SQLITE_OK) {
					throw gcnew Exception("Ошибка подключения");
				}

				const char* sql = "SELECT PdfData, FileName FROM Books WHERE Id = ?;";
				sqlite3_stmt* stmt;

				sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
				sqlite3_bind_int(stmt, 1, bookId);

				if (sqlite3_step(stmt) == SQLITE_ROW)
				{
					const void* pdfBlob = sqlite3_column_blob(stmt, 0);
					int pdfSize = sqlite3_column_bytes(stmt, 0);
					String^ fileName = gcnew String((const char*)sqlite3_column_text(stmt, 1));
					array<Byte>^ pdfData = gcnew array<Byte>(pdfSize);
					Marshal::Copy(IntPtr((void*)pdfBlob), pdfData, 0, pdfSize);
					// Исправленная строка:
					String^ tempFile = Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::LocalApplicationData) + "\\Temp", fileName);
					// Альтернативный вариант:
					// String^ tempFile = Path::Combine(Path::GetTempPath(), fileName);
					File::WriteAllBytes(tempFile, pdfData);
					if (File::Exists(tempFile)) {
						System::Diagnostics::Process::Start(tempFile);
					}
					else {
						MessageBox::Show("Файл не был создан!", "Ошибка");
					}
				}
				sqlite3_finalize(stmt);
				sqlite3_close(db);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Ошибка PDF: " + ex->Message);
			}
		}


		//экран глава народов(экран для вывода книг)
	private:
		System::Void dataGridViewBooks_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
			if(dataGridViewBooks->SelectedRows->Count > 0) {
				selectedBookId = Convert::ToInt32(dataGridViewBooks->SelectedRows[0]->Cells["ID"]->Value);
				LoadBookCover(selectedBookId);
			}
		}

		System::Void btnDownloadPdf_Click(System::Object^ sender, System::EventArgs^ e) {
			if (selectedBookId != -1) {
				OpenPdf(selectedBookId);
			}
			else {
				MessageBox::Show("Сначала выберите книгу!");
			}
		}

	public:
		Edit_Book(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			dataGridViewBooks->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewBooks->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			pictureBoxCover->SizeMode = PictureBoxSizeMode::Zoom;

			dataGridViewBooks->SelectionChanged += gcnew System::EventHandler(this, &Edit_Book::dataGridViewBooks_SelectionChanged);// Подключение событий
			btnDownloadPdf->Click += gcnew System::EventHandler(this, &Edit_Book::btnDownloadPdf_Click);// Подключение событий
			//TODO: добавьте код конструктора
			//

			// Первоначальная загрузка данных
			LoadBooksFromDatabase();
		}
	

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Edit_Book()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonReturnToMain_Click;
	private: System::Windows::Forms::DataGridView^ dataGridViewBooks;
	private: System::Windows::Forms::PictureBox^ pictureBoxCover;
	private: System::Windows::Forms::Button^ btnDownloadPdf;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Edit_Book::typeid));
			this->buttonReturnToMain_Click = (gcnew System::Windows::Forms::Button());
			this->dataGridViewBooks = (gcnew System::Windows::Forms::DataGridView());
			this->pictureBoxCover = (gcnew System::Windows::Forms::PictureBox());
			this->btnDownloadPdf = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewBooks))->BeginInit();
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
			this->buttonReturnToMain_Click->Click += gcnew System::EventHandler(this, &Edit_Book::buttonReturnToMain_Click_Click1);
			// 
			// dataGridViewBooks
			// 
			this->dataGridViewBooks->BackgroundColor = System::Drawing::Color::IndianRed;
			this->dataGridViewBooks->Cursor = System::Windows::Forms::Cursors::Hand;
			this->dataGridViewBooks->GridColor = System::Drawing::SystemColors::ActiveCaption;
			this->dataGridViewBooks->Location = System::Drawing::Point(391, 30);
			this->dataGridViewBooks->Name = L"dataGridViewBooks";
			this->dataGridViewBooks->Size = System::Drawing::Size(374, 227);
			this->dataGridViewBooks->TabIndex = 1;
			// 
			// pictureBoxCover
			// 
			this->pictureBoxCover->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBoxCover->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBoxCover->Location = System::Drawing::Point(61, 12);
			this->pictureBoxCover->Name = L"pictureBoxCover";
			this->pictureBoxCover->Size = System::Drawing::Size(232, 232);
			this->pictureBoxCover->TabIndex = 2;
			this->pictureBoxCover->TabStop = false;
			// 
			// btnDownloadPdf
			// 
			this->btnDownloadPdf->Location = System::Drawing::Point(242, 295);
			this->btnDownloadPdf->Name = L"btnDownloadPdf";
			this->btnDownloadPdf->Size = System::Drawing::Size(134, 52);
			this->btnDownloadPdf->TabIndex = 3;
			this->btnDownloadPdf->Text = L"открыть";
			this->btnDownloadPdf->UseVisualStyleBackColor = true;
			this->btnDownloadPdf->Click += gcnew System::EventHandler(this, &Edit_Book::btnDownloadPdf_Click);
			// 
			// Edit_Book
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SlateGray;
			this->ClientSize = System::Drawing::Size(777, 378);
			this->Controls->Add(this->btnDownloadPdf);
			this->Controls->Add(this->pictureBoxCover);
			this->Controls->Add(this->dataGridViewBooks);
			this->Controls->Add(this->buttonReturnToMain_Click);
			this->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Location = System::Drawing::Point(454, 51);
			this->Name = L"Edit_Book";
			this->Text = L"Edit_Book";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewBooks))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCover))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void buttonReturnToMain_Click_Click1(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
	};
}
