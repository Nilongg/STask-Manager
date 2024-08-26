#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/aui/aui.h>
#include <TaskRetriever.cpp>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    // Retrieve all the tasks before the GUI loads
    TaskRetriever tr = TaskRetriever();

    // Create wxAuiNotebook
    wxAuiNotebook* auiNotebook = new wxAuiNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
        wxAUI_NB_LEFT | wxAUI_NB_TAB_SPLIT | wxAUI_NB_TAB_MOVE);

    // Create a scrolled window for the Processes panel
    wxScrolledWindow* scrolledProcessesPanel = new wxScrolledWindow(auiNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
    scrolledProcessesPanel->SetScrollRate(10, 10);  // Set the scroll rate in pixels

    // Add all the tasks/processes from the tasks vector to the Processes panel 
    // (ID, name, Priority) // Maybe network and CPU usage
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    for (unsigned int i = 0; i < tr.tasks.size(); i++)
    {
        // Setting only the process name for now.
        wxStaticText* text = new wxStaticText(scrolledProcessesPanel, wxID_ANY, tr.tasks[i].GetName());
        sizer->Add(text, 0, wxALL, 5);
    }
    scrolledProcessesPanel->SetSizer(sizer);
    scrolledProcessesPanel->FitInside();  // Adjust the virtual size based on the content
    scrolledProcessesPanel->SetScrollRate(10, 10);  // Ensure scroll rate is set

    // Add the scrolled panel to the notebook
    auiNotebook->AddPage(scrolledProcessesPanel, "Processes");

    // Create other panels and add them to the notebook
    wxPanel* panel2 = new wxPanel(auiNotebook, wxID_ANY);
    panel2->SetBackgroundColour(*wxGREEN);
    auiNotebook->AddPage(panel2, "Network");

    wxPanel* panel3 = new wxPanel(auiNotebook, wxID_ANY);
    panel3->SetBackgroundColour(*wxBLUE);
    auiNotebook->AddPage(panel3, "Performance");

    wxPanel* panel4 = new wxPanel(auiNotebook, wxID_ANY);
    panel4->SetBackgroundColour(*wxBLACK);
    auiNotebook->AddPage(panel4, "App history");

    // Create a wxAuiManager object
    wxAuiManager* auiManager = new wxAuiManager(this);
    auiManager->AddPane(auiNotebook, wxAuiPaneInfo().Center().CaptionVisible(false));
    auiManager->Update();
}
