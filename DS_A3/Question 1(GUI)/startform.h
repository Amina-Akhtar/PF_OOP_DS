#pragma once

namespace L226198A3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for startform
	/// </summary>
	public ref class startform : public System::Windows::Forms::Form
	{
	public:
		startform(void)
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
		~startform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label;

	private: System::Windows::Forms::Label^ k;
	private: System::Windows::Forms::Label^ n;
	private: System::Windows::Forms::TextBox^ tbn;
	private: System::Windows::Forms::TextBox^ tbk;
	private: System::Windows::Forms::Button^ start;


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
			this->label = (gcnew System::Windows::Forms::Label());
			this->k = (gcnew System::Windows::Forms::Label());
			this->n = (gcnew System::Windows::Forms::Label());
			this->tbn = (gcnew System::Windows::Forms::TextBox());
			this->tbk = (gcnew System::Windows::Forms::TextBox());
			this->start = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label
			// 
			this->label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label->BackColor = System::Drawing::Color::DarkCyan;
			this->label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label->Location = System::Drawing::Point(227, 122);
			this->label->MinimumSize = System::Drawing::Size(126, 20);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(400, 32);
			this->label->TabIndex = 0;
			this->label->Text = L"Josephus Game";
			this->label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// k
			// 
			this->k->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->k->BackColor = System::Drawing::Color::Tan;
			this->k->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->k->Location = System::Drawing::Point(69, 324);
			this->k->Name = L"k";
			this->k->Size = System::Drawing::Size(453, 35);
			this->k->TabIndex = 3;
			this->k->Text = L"Enter the number to rotate:\r\n";
			this->k->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// n
			// 
			this->n->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->n->BackColor = System::Drawing::Color::Tan;
			this->n->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->n->Location = System::Drawing::Point(69, 258);
			this->n->Name = L"n";
			this->n->Size = System::Drawing::Size(453, 35);
			this->n->TabIndex = 3;
			this->n->Text = L"Enter the number of players:\r\n";
			this->n->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbn
			// 
			this->tbn->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->tbn->BackColor = System::Drawing::Color::Tan;
			this->tbn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbn->Location = System::Drawing::Point(584, 258);
			this->tbn->Name = L"tbn";
			this->tbn->Size = System::Drawing::Size(100, 35);
			this->tbn->TabIndex = 2;
			this->tbn->TextChanged += gcnew System::EventHandler(this, &startform::tbn_TextChanged);
			// 
			// tbk
			// 
			this->tbk->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->tbk->BackColor = System::Drawing::Color::Tan;
			this->tbk->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbk->Location = System::Drawing::Point(584, 324);
			this->tbk->Name = L"tbk";
			this->tbk->Size = System::Drawing::Size(100, 35);
			this->tbk->TabIndex = 3;
			this->tbk->TextChanged += gcnew System::EventHandler(this, &startform::tbk_TextChanged);
			// 
			// start
			// 
			this->start->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->start->BackColor = System::Drawing::Color::DarkCyan;
			this->start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->start->Location = System::Drawing::Point(346, 458);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(153, 39);
			this->start->TabIndex = 4;
			this->start->Text = L"Start";
			this->start->UseVisualStyleBackColor = false;
			this->start->Click += gcnew System::EventHandler(this, &startform::start_Click);
			// 
			// startform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(819, 576);
			this->Controls->Add(this->start);
			this->Controls->Add(this->tbk);
			this->Controls->Add(this->tbn);
			this->Controls->Add(this->n);
			this->Controls->Add(this->k);
			this->Controls->Add(this->label);
			this->MinimumSize = System::Drawing::Size(838, 622);
			this->Name = L"startform";
			this->Text = L"startform";
			this->Load += gcnew System::EventHandler(this, &startform::startform_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void startform_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void tbk_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbn_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void start_Click(System::Object^ sender, System::EventArgs^ e);
};
}
