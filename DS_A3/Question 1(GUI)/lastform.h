#pragma once

namespace L226198A3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for lastform
	/// </summary>
	public ref class lastform : public System::Windows::Forms::Form
	{
	public:
		lastform(void)
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
		~lastform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ finalwin;

	private: System::Windows::Forms::Button^ End;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ winner;

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
			this->finalwin = (gcnew System::Windows::Forms::Label());
			this->End = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->winner = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// finalwin
			// 
			this->finalwin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->finalwin->BackColor = System::Drawing::Color::Tan;
			this->finalwin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->finalwin->Location = System::Drawing::Point(231, 215);
			this->finalwin->Name = L"finalwin";
			this->finalwin->Size = System::Drawing::Size(199, 43);
			this->finalwin->TabIndex = 0;
			this->finalwin->Text = L"Winner:";
			this->finalwin->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// End
			// 
			this->End->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->End->BackColor = System::Drawing::Color::DarkCyan;
			this->End->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->End->Location = System::Drawing::Point(334, 415);
			this->End->Name = L"End";
			this->End->Size = System::Drawing::Size(189, 45);
			this->End->TabIndex = 2;
			this->End->Text = L"End";
			this->End->UseVisualStyleBackColor = false;
			this->End->Click += gcnew System::EventHandler(this, &lastform::End_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Tan;
			this->label1->Location = System::Drawing::Point(456, 224);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 20);
			this->label1->TabIndex = 3;
			// 
			// winner
			// 
			this->winner->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->winner->BackColor = System::Drawing::Color::Tan;
			this->winner->Location = System::Drawing::Point(447, 215);
			this->winner->Name = L"winner";
			this->winner->Size = System::Drawing::Size(145, 43);
			this->winner->TabIndex = 4;
			this->winner->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->winner->Click += gcnew System::EventHandler(this, &lastform::winner_Click);
			// 
			// lastform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(816, 566);
			this->Controls->Add(this->winner);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->End);
			this->Controls->Add(this->finalwin);
			this->MinimumSize = System::Drawing::Size(838, 622);
			this->Name = L"lastform";
			this->Text = L"lastform";
			this->Load += gcnew System::EventHandler(this, &lastform::lastform_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void End_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void winner_Click(System::Object^ sender, System::EventArgs^ e)
{

}
private: System::Void lastform_Load(System::Object^ sender, System::EventArgs^ e);
};
}
