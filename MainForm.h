#pragma once

namespace BookBastionGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ OptionList;
	private: System::Windows::Forms::TextBox^ StringSearch;
	private: System::Windows::Forms::Button^ SearchButton;
	private: System::Windows::Forms::Button^ ClearButton;

	private: System::Windows::Forms::TextBox^ MinYear;




	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ MaxYear;

	private: System::Windows::Forms::TextBox^ MinRate;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ MaxRate;




	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ListBox^ BOOK_RESULTS;

	private: System::Windows::Forms::ListBox^ RESULTS;
	private: System::Windows::Forms::TextBox^ resultText;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::ListBox^ o;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button1;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->OptionList = (gcnew System::Windows::Forms::ComboBox());
			this->StringSearch = (gcnew System::Windows::Forms::TextBox());
			this->SearchButton = (gcnew System::Windows::Forms::Button());
			this->ClearButton = (gcnew System::Windows::Forms::Button());
			this->MinYear = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->MaxYear = (gcnew System::Windows::Forms::TextBox());
			this->MinRate = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->MaxRate = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->BOOK_RESULTS = (gcnew System::Windows::Forms::ListBox());
			this->RESULTS = (gcnew System::Windows::Forms::ListBox());
			this->resultText = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->o = (gcnew System::Windows::Forms::ListBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(365, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(417, 81);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Book Bastion";
			this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// OptionList
			// 
			this->OptionList->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->OptionList->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->OptionList->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->OptionList->FormattingEnabled = true;
			this->OptionList->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Search by: Title", L"Search by: Author", L"Search by: Filters" });
			this->OptionList->Location = System::Drawing::Point(626, 148);
			this->OptionList->Name = L"OptionList";
			this->OptionList->Size = System::Drawing::Size(189, 35);
			this->OptionList->TabIndex = 1;
			this->OptionList->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::OptionList_SelectedIndexChanged);
			// 
			// StringSearch
			// 
			this->StringSearch->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 24, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StringSearch->Location = System::Drawing::Point(135, 145);
			this->StringSearch->Name = L"StringSearch";
			this->StringSearch->Size = System::Drawing::Size(351, 45);
			this->StringSearch->TabIndex = 2;
			this->StringSearch->Text = L"Search...";
			this->StringSearch->TextChanged += gcnew System::EventHandler(this, &MainForm::StringSearch_TextChanged);
			// 
			// SearchButton
			// 
			this->SearchButton->Location = System::Drawing::Point(528, 145);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(82, 45);
			this->SearchButton->TabIndex = 3;
			this->SearchButton->Text = L"Search";
			this->SearchButton->UseVisualStyleBackColor = true;
			this->SearchButton->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// ClearButton
			// 
			this->ClearButton->Location = System::Drawing::Point(483, 145);
			this->ClearButton->Name = L"ClearButton";
			this->ClearButton->Size = System::Drawing::Size(48, 45);
			this->ClearButton->TabIndex = 4;
			this->ClearButton->Text = L"X";
			this->ClearButton->UseVisualStyleBackColor = true;
			this->ClearButton->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// MinYear
			// 
			this->MinYear->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MinYear->Location = System::Drawing::Point(731, 299);
			this->MinYear->Name = L"MinYear";
			this->MinYear->Size = System::Drawing::Size(84, 23);
			this->MinYear->TabIndex = 6;
			this->MinYear->Text = L"Min";
			this->MinYear->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::Control;
			this->label2->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(827, 302);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 18);
			this->label2->TabIndex = 7;
			this->label2->Text = L"-";
			// 
			// MaxYear
			// 
			this->MaxYear->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MaxYear->Location = System::Drawing::Point(846, 299);
			this->MaxYear->Name = L"MaxYear";
			this->MaxYear->Size = System::Drawing::Size(84, 23);
			this->MaxYear->TabIndex = 8;
			this->MaxYear->Text = L"Max";
			this->MaxYear->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox2_TextChanged);
			// 
			// MinRate
			// 
			this->MinRate->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MinRate->Location = System::Drawing::Point(731, 260);
			this->MinRate->Name = L"MinRate";
			this->MinRate->Size = System::Drawing::Size(84, 23);
			this->MinRate->TabIndex = 9;
			this->MinRate->Text = L"Min";
			this->MinRate->TextChanged += gcnew System::EventHandler(this, &MainForm::MinRate_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::Control;
			this->label3->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(827, 261);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(13, 18);
			this->label3->TabIndex = 10;
			this->label3->Text = L"-";
			this->label3->Click += gcnew System::EventHandler(this, &MainForm::label3_Click);
			// 
			// MaxRate
			// 
			this->MaxRate->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MaxRate->Location = System::Drawing::Point(846, 258);
			this->MaxRate->Name = L"MaxRate";
			this->MaxRate->Size = System::Drawing::Size(84, 23);
			this->MaxRate->TabIndex = 11;
			this->MaxRate->Text = L"Max";
			this->MaxRate->TextChanged += gcnew System::EventHandler(this, &MainForm::MaxRate_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::Control;
			this->label4->Location = System::Drawing::Point(619, 341);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(313, 37);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Book Information For:";
			// 
			// BOOK_RESULTS
			// 
			this->BOOK_RESULTS->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BOOK_RESULTS->FormattingEnabled = true;
			this->BOOK_RESULTS->ItemHeight = 16;
			this->BOOK_RESULTS->Location = System::Drawing::Point(626, 381);
			this->BOOK_RESULTS->Name = L"BOOK_RESULTS";
			this->BOOK_RESULTS->ScrollAlwaysVisible = true;
			this->BOOK_RESULTS->Size = System::Drawing::Size(403, 340);
			this->BOOK_RESULTS->TabIndex = 15;
			this->BOOK_RESULTS->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::BOOK_RESULTS_SelectedIndexChanged);
			// 
			// RESULTS
			// 
			this->RESULTS->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->RESULTS->FormattingEnabled = true;
			this->RESULTS->ItemHeight = 16;
			this->RESULTS->Location = System::Drawing::Point(135, 207);
			this->RESULTS->Name = L"RESULTS";
			this->RESULTS->Size = System::Drawing::Size(475, 516);
			this->RESULTS->TabIndex = 18;
			this->RESULTS->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::RESULTS_SelectedIndexChanged);
			// 
			// resultText
			// 
			this->resultText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->resultText->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resultText->Location = System::Drawing::Point(147, 230);
			this->resultText->Multiline = true;
			this->resultText->Name = L"resultText";
			this->resultText->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->resultText->Size = System::Drawing::Size(453, 481);
			this->resultText->TabIndex = 19;
			this->resultText->Text = L"...";
			this->resultText->TextChanged += gcnew System::EventHandler(this, &MainForm::resultText_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(731, 215);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(197, 37);
			this->textBox1->TabIndex = 20;
			this->textBox1->Text = resources->GetString(L"textBox1.Text");
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged_1);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(934, 215);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(84, 23);
			this->textBox2->TabIndex = 21;
			this->textBox2->Text = L"Number";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox2_TextChanged_1);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->BackColor = System::Drawing::SystemColors::Control;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox1->Location = System::Drawing::Point(635, 260);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(90, 28);
			this->checkBox1->TabIndex = 22;
			this->checkBox1->Text = L"Rating:";
			this->checkBox1->UseVisualStyleBackColor = false;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->BackColor = System::Drawing::SystemColors::Control;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox2->Location = System::Drawing::Point(635, 299);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(72, 28);
			this->checkBox2->TabIndex = 23;
			this->checkBox2->Text = L"Year:";
			this->checkBox2->UseVisualStyleBackColor = false;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->BackColor = System::Drawing::SystemColors::Control;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox3->Location = System::Drawing::Point(635, 210);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(86, 28);
			this->checkBox3->TabIndex = 24;
			this->checkBox3->Text = L"Genre:";
			this->checkBox3->UseVisualStyleBackColor = false;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox3_CheckedChanged);
			// 
			// o
			// 
			this->o->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->o->FormattingEnabled = true;
			this->o->ItemHeight = 16;
			this->o->Location = System::Drawing::Point(626, 207);
			this->o->Name = L"o";
			this->o->Size = System::Drawing::Size(403, 132);
			this->o->TabIndex = 25;
			this->o->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::listBox1_SelectedIndexChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Data: Ordered Map", L"Data: Unordered Map" });
			this->comboBox1->Location = System::Drawing::Point(829, 148);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(200, 35);
			this->comboBox1->TabIndex = 26;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBox1_SelectedIndexChanged);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(925, 345);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(51, 30);
			this->textBox3->TabIndex = 27;
			this->textBox3->Text = L"------";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox3_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(635, 403);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox4->Size = System::Drawing::Size(383, 308);
			this->textBox4->TabIndex = 28;
			this->textBox4->Text = L"...";
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox4_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(982, 345);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(47, 33);
			this->button1->TabIndex = 29;
			this->button1->Text = L"Select";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click_1);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSlateGray;
			this->ClientSize = System::Drawing::Size(1134, 742);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->resultText);
			this->Controls->Add(this->BOOK_RESULTS);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->MaxRate);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->MinRate);
			this->Controls->Add(this->MaxYear);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->MinYear);
			this->Controls->Add(this->ClearButton);
			this->Controls->Add(this->SearchButton);
			this->Controls->Add(this->StringSearch);
			this->Controls->Add(this->OptionList);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->RESULTS);
			this->Controls->Add(this->o);
			this->Name = L"MainForm";
			this->Text = L"Book Bastion";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//activate search
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		//clear all inputs
	}
	private: System::Void StringSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		//set this as the value to search
	}
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		//min year
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		//max year
	}

	private: System::Void listBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	//num genre selected
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	//result number
}
private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	//genre checked
}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	//ratings checked
}
private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	//year checked
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	//book info display
}
private: System::Void resultText_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	//list of results display
}
private: System::Void MinRate_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	//min rating
}
private: System::Void MaxRate_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	//max rating
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	//result number button 
}
private: System::Void OptionList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	//select type of search, 3 types
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	//select type of map, 2 types
}
private: System::Void BOOK_RESULTS_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	//display time to search final
}
private: System::Void RESULTS_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	//display time to search general
}
};
}
