#pragma once

namespace L226198A3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for mainorm
	/// </summary>
	public ref class mainorm : public System::Windows::Forms::Form
	{
	public:
		mainorm(void)
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
		~mainorm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ process;
	private: System::Windows::Forms::Button^ buttonwin;
	private: System::Windows::Forms::TextBox^ playersprocess;

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(mainorm::typeid));
			this->process = (gcnew System::Windows::Forms::Label());
			this->buttonwin = (gcnew System::Windows::Forms::Button());
			this->playersprocess = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// process
			// 
			this->process->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->process->BackColor = System::Drawing::Color::Tan;
			this->process->Location = System::Drawing::Point(117, 55);
			this->process->Name = L"process";
			this->process->Size = System::Drawing::Size(582, 40);
			this->process->TabIndex = 0;
			this->process->Text = L"Processing";
			this->process->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// buttonwin
			// 
			this->buttonwin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonwin->BackColor = System::Drawing::Color::DarkCyan;
			this->buttonwin->Location = System::Drawing::Point(105, 476);
			this->buttonwin->Name = L"buttonwin";
			this->buttonwin->Size = System::Drawing::Size(594, 44);
			this->buttonwin->TabIndex = 1;
			this->buttonwin->Text = L"Get winner";
			this->buttonwin->UseVisualStyleBackColor = false;
			this->buttonwin->Click += gcnew System::EventHandler(this, &mainorm::buttonwin_Click);
			// 
			// playersprocess
			// 
			this->playersprocess->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->playersprocess->BackColor = System::Drawing::Color::Tan;
			this->playersprocess->Location = System::Drawing::Point(122, 151);
			this->playersprocess->Multiline = true;
			this->playersprocess->Name = L"playersprocess";
			this->playersprocess->Size = System::Drawing::Size(577, 274);
			this->playersprocess->TabIndex = 2;
			this->playersprocess->TextChanged += gcnew System::EventHandler(this, &mainorm::playersprocess_TextChanged);
			// 
			// mainorm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(15, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(816, 566);
			this->Controls->Add(this->playersprocess);
			this->Controls->Add(this->buttonwin);
			this->Controls->Add(this->process);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimumSize = System::Drawing::Size(838, 622);
			this->Name = L"mainorm";
			this->Text = L"mainorm";
			this->Load += gcnew System::EventHandler(this, &mainorm::mainorm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void process_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void mainorm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonwin_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void playersprocess_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
