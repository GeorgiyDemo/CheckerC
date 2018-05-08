#pragma once

namespace CursachParser {

	using namespace System;
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
			// OuterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->Outlabel);
			this->Name = L"OuterForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"–езультаты подбора";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
