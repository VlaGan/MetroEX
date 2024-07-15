#include "DlgExportMotions.h"
#include "../metro/MetroModel.h"
#include "ui/UIHelpers.h"


namespace MetroEX {

    System::Void DlgExportMotions::SetupModel(MetroModel* model){
        SetupDefault();

        if (model) {
            m_model = model;

            for (size_t i = 0; i < model->GetNumMotions(); ++i) {
                MotionInfo^ mi = gcnew MotionInfo();
                mi->name = ToNetString(model->GetMotionName(i));
                mi->path = ToNetString(model->GetMotionPath(i));
                mi->duration = model->GetMotionDuration(i);

                m_miMotionsAll.Add(mi);
            }

            for each (MotionInfo^ motion in m_miMotionsAll)
                listAnimsAll->Items->Add(motion->name);

        }
    }

    System::Void DlgExportMotions::SetupDefault() {
        m_miMotionsAll.Clear();
        m_miMotionsToExport.Clear();
        m_model = nullptr;
        listAnimsAll->Items->Clear();
        listAnimsToExport->Items->Clear();
    }

    System::Void DlgExportMotions::btnAddMotion_Click(System::Object^ sender, System::EventArgs^ e) {
        if (listAnimsAll->SelectedIndex < 0)
            return;

        System::String^ motion_name = listAnimsAll->Items[listAnimsAll->SelectedIndex]->ToString();

        //-- if motion already added - skip
        for each (MotionInfo^ motion in m_miMotionsToExport)
            if (motion->name == motion_name)
                return;

        //-- search animation in all and add to Motions To Export
        for each (MotionInfo^ motion in m_miMotionsAll)
            if (motion->name == motion_name) {
                m_miMotionsToExport.Add(motion);
                listAnimsToExport->Items->Add(motion->name);

                if(listAnimsAll->Items->Count && listAnimsAll->SelectedIndex != listAnimsAll->Items->Count - 1)
                    listAnimsAll->SelectedIndex++;
                Clamp(listAnimsAll->SelectedIndex, 0, listAnimsAll->Items->Count-1);

                break;
            }
    }

    System::Void DlgExportMotions::btnDelMotion_Click(System::Object^ sender, System::EventArgs^ e) {
        int selected_idx = listAnimsToExport->SelectedIndex;
        if (selected_idx < 0)
            return;

        listAnimsToExport->Items->RemoveAt(selected_idx);
        m_miMotionsToExport.RemoveAt(selected_idx);

        if (listAnimsToExport->Items->Count) {
            listAnimsToExport->SelectedIndex = selected_idx-1;
            Clamp(listAnimsToExport->SelectedIndex, 0, listAnimsToExport->Items->Count - 1);
        }
        else
            listAnimsToExport->SelectedIndex = -1;

    }

    System::Void DlgExportMotions::btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
        this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
        this->SetupDefault();
        this->Close();
    }

    System::Void DlgExportMotions::btnExport_Click(System::Object^ sender, System::EventArgs^ e) {
        if (!listAnimsToExport->Items->Count) {
            MetroEX::ShowErrorMessageBox(this, L"There are no selected motions to export!\nSelect something!");
            return;
        }
        
        this->DialogResult = System::Windows::Forms::DialogResult::OK;
        //this->SetupDefault();
        this->Close();
    }

    System::Void DlgExportMotions::btnAddAllMotions_Click(System::Object^ sender, System::EventArgs^ e) {
        m_miMotionsToExport.Clear();
        listAnimsToExport->Items->Clear();

        for each (MotionInfo^ mi in m_miMotionsAll) {
            m_miMotionsToExport.Add(mi);
            listAnimsToExport->Items->Add(mi->name);
        }

        if(listAnimsToExport->Items->Count > 0)
            listAnimsToExport->SelectedIndex = 0;

    }

    System::Void DlgExportMotions::btnDelAllMotions_Click(System::Object^ sender, System::EventArgs^ e) {
        m_miMotionsToExport.Clear();
        listAnimsToExport->Items->Clear();
    }

}
