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
	/// Сводка для OuterForm
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
		/// Освободить все используемые ресурсы.
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

	public:

	public:
	protected:

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
			this->OutLabel = (gcnew System::Windows::Forms::Label());
			this->OutDataGridView = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OutDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// OutLabel
			// 
			this->OutLabel->AutoSize = true;
			this->OutLabel->Location = System::Drawing::Point(23, 30);
			this->OutLabel->Name = L"OutLabel";
			this->OutLabel->Size = System::Drawing::Size(293, 13);
			this->OutLabel->TabIndex = 2;
			this->OutLabel->Text = L"Подбор результатов с максимальной ценой и составом";
			// 
			// OutDataGridView
			// 
			this->OutDataGridView->BackgroundColor = System::Drawing::SystemColors::Menu;
			this->OutDataGridView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->OutDataGridView->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			this->OutDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->OutDataGridView->Location = System::Drawing::Point(26, 66);
			this->OutDataGridView->Name = L"OutDataGridView";
			this->OutDataGridView->Size = System::Drawing::Size(549, 300);
			this->OutDataGridView->TabIndex = 3;
			// 
			// OuterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(608, 405);
			this->Controls->Add(this->OutDataGridView);
			this->Controls->Add(this->OutLabel);
			this->Name = L"OuterForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Результаты подбора";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OutDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
