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
	/// —водка дл€ OuterForm
	/// </summary>
	public ref class OuterForm : public System::Windows::Forms::Form
	{
	public:
		OuterForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~OuterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  Outlabel;
	public: System::Windows::Forms::DataGridView^  OutDataGridView;

	public:

	public:
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Outlabel = (gcnew System::Windows::Forms::Label());
			this->OutDataGridView = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OutDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// Outlabel
			// 
			this->Outlabel->AutoSize = true;
			this->Outlabel->Location = System::Drawing::Point(23, 30);
			this->Outlabel->Name = L"Outlabel";
			this->Outlabel->Size = System::Drawing::Size(52, 13);
			this->Outlabel->TabIndex = 2;
			this->Outlabel->Text = L"Outlabel1";
			// 
			// OutDataGridView
			// 
			this->OutDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->OutDataGridView->Location = System::Drawing::Point(243, 88);
			this->OutDataGridView->Name = L"OutDataGridView";
			this->OutDataGridView->Size = System::Drawing::Size(351, 230);
			this->OutDataGridView->TabIndex = 3;
			// 
			// OuterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(620, 426);
			this->Controls->Add(this->OutDataGridView);
			this->Controls->Add(this->Outlabel);
			this->Name = L"OuterForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"–езультаты подбора";
			this->Load += gcnew System::EventHandler(this, &OuterForm::OuterForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OutDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void OuterForm_Load(System::Object^  sender, System::EventArgs^  e) {
		OutDataGridView->DataSource = GlobalClass::DataGridExample();
	}
	};
}
