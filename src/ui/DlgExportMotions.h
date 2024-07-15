#pragma once

class MetroModel;

namespace MetroEX {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ DlgExportMotions
	/// </summary>
	public ref class DlgExportMotions : public System::Windows::Forms::Form
	{
	public:
		DlgExportMotions(void)
		{
			InitializeComponent();
		}

        ref struct MotionInfo {
            String^ name;
            String^ path;
            float   duration;
        };

        Generic::List<MotionInfo^> m_miMotionsAll;
        Generic::List< MotionInfo^> m_miMotionsToExport;

    private:
        MetroModel* m_model{};

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~DlgExportMotions()
		{
			if (components)
			{
				delete components;
			}
		}

    private:
        System::Windows::Forms::Button^ btnAddAllMotions;
        System::Windows::Forms::Button^ btnDelAllMotions;


        System::Windows::Forms::ListBox^ listAnimsAll;
        System::Windows::Forms::ListBox^ listAnimsToExport;
        System::Windows::Forms::GroupBox^ groupBoxMotions;
        System::Windows::Forms::Button^ btnDelMotion;
        System::Windows::Forms::Button^ btnAddMotion;
        System::Windows::Forms::Button^ btnCancel;
        System::Windows::Forms::Button^ btnExport;

        System::Windows::Forms::GroupBox^ groupBotPanel;
        System::Windows::Forms::Label^ labelModelName;

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
            this->listAnimsAll = (gcnew System::Windows::Forms::ListBox());
            this->listAnimsToExport = (gcnew System::Windows::Forms::ListBox());
            this->groupBoxMotions = (gcnew System::Windows::Forms::GroupBox());
            this->btnAddAllMotions = (gcnew System::Windows::Forms::Button());
            this->btnDelAllMotions = (gcnew System::Windows::Forms::Button());
            this->btnDelMotion = (gcnew System::Windows::Forms::Button());
            this->btnAddMotion = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            this->btnExport = (gcnew System::Windows::Forms::Button());
            this->groupBotPanel = (gcnew System::Windows::Forms::GroupBox());
            this->labelModelName = (gcnew System::Windows::Forms::Label());
            this->groupBoxMotions->SuspendLayout();
            this->groupBotPanel->SuspendLayout();
            this->SuspendLayout();
            // 
            // listAnimsAll
            // 
            this->listAnimsAll->FormattingEnabled = true;
            this->listAnimsAll->ItemHeight = 16;
            this->listAnimsAll->Location = System::Drawing::Point(6, 21);
            this->listAnimsAll->Name = L"listAnimsAll";
            this->listAnimsAll->Size = System::Drawing::Size(479, 340);
            this->listAnimsAll->TabIndex = 0;
            this->listAnimsAll->SelectedIndexChanged += gcnew System::EventHandler(this, &DlgExportMotions::listBox1_SelectedIndexChanged);
            // 
            // listAnimsToExport
            // 
            this->listAnimsToExport->FormattingEnabled = true;
            this->listAnimsToExport->ItemHeight = 16;
            this->listAnimsToExport->Location = System::Drawing::Point(630, 21);
            this->listAnimsToExport->Name = L"listAnimsToExport";
            this->listAnimsToExport->Size = System::Drawing::Size(485, 340);
            this->listAnimsToExport->TabIndex = 1;
            this->listAnimsToExport->SelectedIndexChanged += gcnew System::EventHandler(this, &DlgExportMotions::listBox1_SelectedIndexChanged_1);
            // 
            // groupBoxMotions
            // 
            this->groupBoxMotions->Controls->Add(this->btnAddAllMotions);
            this->groupBoxMotions->Controls->Add(this->btnDelAllMotions);
            this->groupBoxMotions->Controls->Add(this->btnDelMotion);
            this->groupBoxMotions->Controls->Add(this->btnAddMotion);
            this->groupBoxMotions->Controls->Add(this->listAnimsAll);
            this->groupBoxMotions->Controls->Add(this->listAnimsToExport);
            this->groupBoxMotions->Location = System::Drawing::Point(12, 72);
            this->groupBoxMotions->Name = L"groupBoxMotions";
            this->groupBoxMotions->Size = System::Drawing::Size(1121, 409);
            this->groupBoxMotions->TabIndex = 2;
            this->groupBoxMotions->TabStop = false;
            this->groupBoxMotions->Text = L"Select Motions:";
            this->groupBoxMotions->Enter += gcnew System::EventHandler(this, &DlgExportMotions::groupBox1_Enter);
            // 
            // btnAddAllMotions
            // 
            this->btnAddAllMotions->Location = System::Drawing::Point(352, 367);
            this->btnAddAllMotions->Name = L"btnAddAllMotions";
            this->btnAddAllMotions->Size = System::Drawing::Size(133, 31);
            this->btnAddAllMotions->TabIndex = 5;
            this->btnAddAllMotions->Text = L"Add All >>";
            this->btnAddAllMotions->UseVisualStyleBackColor = true;
            this->btnAddAllMotions->Click += gcnew System::EventHandler(this, &DlgExportMotions::btnAddAllMotions_Click);
            // 
            // btnDelAllMotions
            // 
            this->btnDelAllMotions->Location = System::Drawing::Point(630, 367);
            this->btnDelAllMotions->Name = L"btnDelAllMotions";
            this->btnDelAllMotions->Size = System::Drawing::Size(133, 31);
            this->btnDelAllMotions->TabIndex = 4;
            this->btnDelAllMotions->Text = L"Delete All <<";
            this->btnDelAllMotions->UseVisualStyleBackColor = true;
            this->btnDelAllMotions->Click += gcnew System::EventHandler(this, &DlgExportMotions::btnDelAllMotions_Click);
            // 
            // btnDelMotion
            // 
            this->btnDelMotion->Location = System::Drawing::Point(491, 201);
            this->btnDelMotion->Name = L"btnDelMotion";
            this->btnDelMotion->Size = System::Drawing::Size(133, 54);
            this->btnDelMotion->TabIndex = 3;
            this->btnDelMotion->Text = L"Delete Motion <<";
            this->btnDelMotion->UseVisualStyleBackColor = true;
            this->btnDelMotion->Click += gcnew System::EventHandler(this, &DlgExportMotions::btnDelMotion_Click);
            // 
            // btnAddMotion
            // 
            this->btnAddMotion->Location = System::Drawing::Point(491, 132);
            this->btnAddMotion->Name = L"btnAddMotion";
            this->btnAddMotion->Size = System::Drawing::Size(133, 54);
            this->btnAddMotion->TabIndex = 2;
            this->btnAddMotion->Text = L"Add Motion >>";
            this->btnAddMotion->UseVisualStyleBackColor = true;
            this->btnAddMotion->Click += gcnew System::EventHandler(this, &DlgExportMotions::btnAddMotion_Click);
            // 
            // btnCancel
            // 
            this->btnCancel->Location = System::Drawing::Point(970, 21);
            this->btnCancel->Name = L"btnCancel";
            this->btnCancel->Size = System::Drawing::Size(145, 38);
            this->btnCancel->TabIndex = 3;
            this->btnCancel->Text = L"Cancel";
            this->btnCancel->UseVisualStyleBackColor = true;
            this->btnCancel->Click += gcnew System::EventHandler(this, &DlgExportMotions::btnCancel_Click);
            // 
            // btnExport
            // 
            this->btnExport->Location = System::Drawing::Point(810, 21);
            this->btnExport->Name = L"btnExport";
            this->btnExport->Size = System::Drawing::Size(145, 38);
            this->btnExport->TabIndex = 4;
            this->btnExport->Text = L"Export";
            this->btnExport->UseVisualStyleBackColor = true;
            this->btnExport->Click += gcnew System::EventHandler(this, &DlgExportMotions::btnExport_Click);
            // 
            // groupBotPanel
            // 
            this->groupBotPanel->Controls->Add(this->btnExport);
            this->groupBotPanel->Controls->Add(this->btnCancel);
            this->groupBotPanel->Location = System::Drawing::Point(12, 487);
            this->groupBotPanel->Name = L"groupBotPanel";
            this->groupBotPanel->Size = System::Drawing::Size(1121, 67);
            this->groupBotPanel->TabIndex = 5;
            this->groupBotPanel->TabStop = false;
            this->groupBotPanel->Enter += gcnew System::EventHandler(this, &DlgExportMotions::groupBox1_Enter_1);
            // 
            // labelModelName
            // 
            this->labelModelName->AutoSize = true;
            this->labelModelName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->labelModelName->Location = System::Drawing::Point(12, 9);
            this->labelModelName->Name = L"labelModelName";
            this->labelModelName->Size = System::Drawing::Size(570, 36);
            this->labelModelName->TabIndex = 6;
            this->labelModelName->Text = L"Exporting model with selected animations:";
            // 
            // DlgExportMotions
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1145, 562);
            this->Controls->Add(this->labelModelName);
            this->Controls->Add(this->groupBotPanel);
            this->Controls->Add(this->groupBoxMotions);
            this->Name = L"DlgExportMotions";
            this->Text = L"DlgExportMotions";
            this->groupBoxMotions->ResumeLayout(false);
            this->groupBotPanel->ResumeLayout(false);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    public:
        System::Void SetupModel(MetroModel* model);
        System::Void SetupDefault();

    private:
        System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	    }
        System::Void listBox1_SelectedIndexChanged_1(System::Object^ sender, System::EventArgs^ e) {
        }
        System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
        }

        System::Void groupBox1_Enter_1(System::Object^ sender, System::EventArgs^ e) {
        }

        //-- Export/Cancel btn clicked
        System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnExport_Click(System::Object^ sender, System::EventArgs^ e);

        //-- Add/Delete Motion btns click effects
        System::Void btnAddMotion_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnDelMotion_Click(System::Object^ sender, System::EventArgs^ e);

        //-- Add/Delete All Motion
        System::Void btnAddAllMotions_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnDelAllMotions_Click(System::Object^ sender, System::EventArgs^ e);

};
}
