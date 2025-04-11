#include "MyForm.h"
#include "Add_Book.h"
#include "Edit_Book.h"
#include <sqlite3.h>
#include <iostream>

//зум картинок не работает
//текст не видемый






#pragma comment(lib, "sqlite3.lib")

using namespace std;
using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main(cli::array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	test2::MyForm form;
	Application::Run(% form);
	sqlite3* db;           
	char* zErrMsg = 0;      // Указатель на сообщение об ошибке
	int rc;               


	rc = sqlite3_open("LibraryDatabase.db", &db);
	if (rc) {
		cerr << "no open BD: " << sqlite3_errmsg(db) << endl;
		return 1;
	}
	else {
		cout << "open BD" << endl;
	}

	//const char* sqlCreateTable =
	//	"CREATE TABLE IF NOT EXISTS Products ("
	//	"id INTEGER PRIMARY KEY AUTOINCREMENT,"
	//	"name TEXT NOT NULL,"
	//	"description TEXT,"
	//	"price REAL"
	//	");";
	
	//if (rc != SQLITE_OK) {
	//	MessageBox::Show(String::Format("Ошибка при создании таблицы {0}"));
	//}
	//Console::WriteLine("Таблица создана (или уже существовала).");
}