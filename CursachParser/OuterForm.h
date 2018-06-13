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
	/// ������ ��� OuterForm
	/// </summary>
	public ref class OuterForm : public System::Windows::Forms::Form
	{
	public:
		OuterForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~OuterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  OutLabel;
	protected:

	protected:

	public: System::Windows::Forms::DataGridView^  OutDataGridView;
	private: System::Windows::Forms::Button^  ExitButton;
	public:

	public:

	public:
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(OuterForm::typeid));
			this->OutLabel = (gcnew System::Windows::Forms::Label());
			this->OutDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OutDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// OutLabel
			// 
			this->OutLabel->AutoSize = true;
			this->OutLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->OutLabel->Location = System::Drawing::Point(22, 23);
			this->OutLabel->Name = L"OutLabel";
			this->OutLabel->Size = System::Drawing::Size(403, 18);
			this->OutLabel->TabIndex = 2;
			this->OutLabel->Text = L"������ ����������� � ������������ ����� � ��������";
			// 
			// OutDataGridView
			// 
			this->OutDataGridView->BackgroundColor = System::Drawing::SystemColors::Menu;
			this->OutDataGridView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->OutDataGridView->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			this->OutDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->OutDataGridView->Location = System::Drawing::Point(26, 66);
			this->OutDataGridView->Name = L"OutDataGridView";
			this->OutDataGridView->Size = System::Drawing::Size(845, 274);
			this->OutDataGridView->TabIndex = 3;
			// 
			// ExitButton
			// 
			this->ExitButton->Location = System::Drawing::Point(26, 364);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(145, 38);
			this->ExitButton->TabIndex = 4;
			this->ExitButton->Text = L"�����";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &OuterForm::ExitButton_Click);
			// 
			// OuterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(902, 433);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->OutDataGridView);
			this->Controls->Add(this->OutLabel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"OuterForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"���������� �������";
			this->Load += gcnew System::EventHandler(this, &OuterForm::OuterForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OutDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void OuterForm_Load(System::Object^  sender, System::EventArgs^  e) {
			OutDataGridView->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells);
		}

		private: System::Void ExitButton_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Hide();
		}
};
}
