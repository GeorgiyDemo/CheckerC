#include "OuterForm.h"
#include "GlobalClass.h"
#pragma once

namespace CursachParser {

	using namespace System;
	using namespace Globals;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  PriceLabel;
	protected:
	private: System::Windows::Forms::Label^  ContentLabel;
	private: System::Windows::Forms::TextBox^  PriceTextBox;

	private:

	private: System::Windows::Forms::TextBox^  ContentTextBox;
	private: System::Windows::Forms::GroupBox^  MainGroupBox;
	private: System::Windows::Forms::Button^  BeginButton;

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
			this->PriceLabel = (gcnew System::Windows::Forms::Label());
			this->ContentLabel = (gcnew System::Windows::Forms::Label());
			this->PriceTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ContentTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MainGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->BeginButton = (gcnew System::Windows::Forms::Button());
			this->MainGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// PriceLabel
			// 
			this->PriceLabel->AutoSize = true;
			this->PriceLabel->Location = System::Drawing::Point(11, 35);
			this->PriceLabel->Name = L"PriceLabel";
			this->PriceLabel->Size = System::Drawing::Size(175, 13);
			this->PriceLabel->TabIndex = 0;
			this->PriceLabel->Text = L"Введите предпочтительную цену:";
			// 
			// ContentLabel
			// 
			this->ContentLabel->AutoSize = true;
			this->ContentLabel->Location = System::Drawing::Point(11, 67);
			this->ContentLabel->Name = L"ContentLabel";
			this->ContentLabel->Size = System::Drawing::Size(121, 13);
			this->ContentLabel->TabIndex = 1;
			this->ContentLabel->Text = L"Введите ингридиенты:";
			// 
			// PriceTextBox
			// 
			this->PriceTextBox->Location = System::Drawing::Point(192, 32);
			this->PriceTextBox->Name = L"PriceTextBox";
			this->PriceTextBox->Size = System::Drawing::Size(169, 20);
			this->PriceTextBox->TabIndex = 2;
			// 
			// ContentTextBox
			// 
			this->ContentTextBox->Location = System::Drawing::Point(192, 64);
			this->ContentTextBox->Name = L"ContentTextBox";
			this->ContentTextBox->Size = System::Drawing::Size(169, 20);
			this->ContentTextBox->TabIndex = 3;
			// 
			// MainGroupBox
			// 
			this->MainGroupBox->Controls->Add(this->PriceTextBox);
			this->MainGroupBox->Controls->Add(this->ContentTextBox);
			this->MainGroupBox->Controls->Add(this->PriceLabel);
			this->MainGroupBox->Controls->Add(this->ContentLabel);
			this->MainGroupBox->Location = System::Drawing::Point(12, 12);
			this->MainGroupBox->Name = L"MainGroupBox";
			this->MainGroupBox->Size = System::Drawing::Size(387, 108);
			this->MainGroupBox->TabIndex = 4;
			this->MainGroupBox->TabStop = false;
			this->MainGroupBox->Text = L"Основные параметры";
			// 
			// BeginButton
			// 
			this->BeginButton->Location = System::Drawing::Point(244, 126);
			this->BeginButton->Name = L"BeginButton";
			this->BeginButton->Size = System::Drawing::Size(129, 29);
			this->BeginButton->TabIndex = 5;
			this->BeginButton->Text = L"Подобрать заведения";
			this->BeginButton->UseVisualStyleBackColor = true;
			this->BeginButton->Click += gcnew System::EventHandler(this, &MainForm::BeginButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(416, 169);
			this->Controls->Add(this->BeginButton);
			this->Controls->Add(this->MainGroupBox);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Подбор заведения";
			this->MainGroupBox->ResumeLayout(false);
			this->MainGroupBox->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	
private: void StringSpliter(String^ str) {
		GlobalClass::SplitStringArray = str->Split(',');
	}

	private: System::Void BeginButton_Click(System::Object^  sender, System::EventArgs^  e) {
		
		StringSpliter(ContentTextBox->Text);
		OuterForm^OuterForm_obj = gcnew OuterForm();
		OuterForm_obj->OutDataGridView->DataSource = GlobalClass::GetXML(System::Convert::ToInt32(PriceTextBox->Text));
		OuterForm_obj->OutLabel->Text = "Подбор результатов с максимальной ценой " + PriceTextBox->Text + " и ингредиентами " + ContentTextBox->Text;
		this->Hide();
		OuterForm_obj->ShowDialog();
		this->Show();
	}

};
}
