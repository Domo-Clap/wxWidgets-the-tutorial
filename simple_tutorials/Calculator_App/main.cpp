#include "main.h"

    bool CalculatorApp::OnInit()
    {
        wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Tutorial - Calculator App", wxDefaultPosition, wxSize(500, 700));
        frame->Show(true);

        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer* displaySizer = new wxBoxSizer(wxVERTICAL);

        // We created our buttonGridSizer with 4 rows, 4 columns, and padding of 5px in between
        wxGridSizer* buttonGridSizer = new wxGridSizer(4, 4, 5, 5);
       
        displayArea = new wxTextCtrl(frame, wxID_ANY, "", wxDefaultPosition, wxSize(-1, 100), (wxTE_RIGHT | wxTE_READONLY));

        // We set the padding to 10, proportion or vertical growth to 0, and make it stretch horizontally via wxEXPAND
        displaySizer->Add(displayArea, 0, wxEXPAND | wxALL, 10);

        /*
            Here, we create a ton of buttons to be displayed in our window.
            We will assign each one a callback/bind function using the Bind() function
            For each bind function, we pass the wxEVT_BUTTON param to define it is a button click event.
            We also pass the function we built further down to catch the number and insert it into the textCtrl box
        */
        button_1 = new wxButton(frame, wxID_ANY, "1");
        button_1->Bind(wxEVT_BUTTON, &CalculatorApp::insertNumber, this);

        button_2 = new wxButton(frame, wxID_ANY, "2");
        button_2->Bind(wxEVT_BUTTON, &CalculatorApp::insertNumber, this);

        button_3 = new wxButton(frame, wxID_ANY, "3");
        button_3->Bind(wxEVT_BUTTON, &CalculatorApp::insertNumber, this);

        button_4 = new wxButton(frame, wxID_ANY, "4");
        button_4->Bind(wxEVT_BUTTON, &CalculatorApp::insertNumber, this);

        button_5 = new wxButton(frame, wxID_ANY, "5");
        button_5->Bind(wxEVT_BUTTON, &CalculatorApp::insertNumber, this);

        button_6 = new wxButton(frame, wxID_ANY, "6");
        button_6->Bind(wxEVT_BUTTON, &CalculatorApp::insertNumber, this);

        button_7 = new wxButton(frame, wxID_ANY, "7");
        button_7->Bind(wxEVT_BUTTON, &CalculatorApp::insertNumber, this);

        button_8 = new wxButton(frame, wxID_ANY, "8");
        button_8->Bind(wxEVT_BUTTON, &CalculatorApp::insertNumber, this);

        button_9 = new wxButton(frame, wxID_ANY, "9");
        button_9->Bind(wxEVT_BUTTON, &CalculatorApp::insertNumber, this);

        button_0 = new wxButton(frame, wxID_ANY, "0");
        button_0->Bind(wxEVT_BUTTON, &CalculatorApp::insertNumber, this);

        button_plus = new wxButton(frame, wxID_ANY, "+");
        button_plus->Bind(wxEVT_BUTTON, &CalculatorApp::insertPlusSign, this);

        button_minus = new wxButton(frame, wxID_ANY, "-");
        button_minus->Bind(wxEVT_BUTTON, &CalculatorApp::insertMinusSign, this);

        button_multiply = new wxButton(frame, wxID_ANY, "*");
        button_multiply->Bind(wxEVT_BUTTON, &CalculatorApp::insertMultipySign, this);

        button_divide = new wxButton(frame, wxID_ANY, "/");
        button_divide->Bind(wxEVT_BUTTON, &CalculatorApp::insertDivideSign, this);

        button_enter = new wxButton(frame, wxID_ANY, "=");
        button_enter->Bind(wxEVT_BUTTON, &CalculatorApp::performCalc, this);

        button_clear = new wxButton(frame, wxID_ANY, "c");
        button_clear->Bind(wxEVT_BUTTON, &CalculatorApp::clearPrompt, this);

        /*
            Then here, we added all of our buttons to our buttonGridSizer in the order we want them to appear
        */
        // Will be row 1
        buttonGridSizer->Add(button_1, 1, wxEXPAND);
        buttonGridSizer->Add(button_2, 1, wxEXPAND);
        buttonGridSizer->Add(button_3, 1, wxEXPAND);
        buttonGridSizer->Add(button_plus, 1, wxEXPAND);

        // Will be row 2
        buttonGridSizer->Add(button_4, 1, wxEXPAND);
        buttonGridSizer->Add(button_5, 1, wxEXPAND);
        buttonGridSizer->Add(button_6, 1, wxEXPAND);
        buttonGridSizer->Add(button_minus, 1, wxEXPAND);

        // Will be row 3
        buttonGridSizer->Add(button_7, 1, wxEXPAND);
        buttonGridSizer->Add(button_8, 1, wxEXPAND);
        buttonGridSizer->Add(button_9, 1, wxEXPAND);
        buttonGridSizer->Add(button_multiply, 1, wxEXPAND);

        // Will be row 4
        buttonGridSizer->Add(button_0, 1, wxEXPAND);
        buttonGridSizer->Add(button_divide, 1, wxEXPAND);
        buttonGridSizer->Add(button_enter, 1, wxEXPAND);
        buttonGridSizer->Add(button_clear, 1, wxEXPAND);


        /*
            And lastly, here, we added our 2 sizers for the display box and the grid into our main sizer.
            Which we then set the sizer for the frame as mainSizer
        */
        mainSizer->Add(displaySizer, 0, wxEXPAND);
        mainSizer->Add(buttonGridSizer, 1, wxEXPAND | wxALL, 10);

        frame->SetMinSize(wxSize(320, 320));
        frame->SetSizer(mainSizer);
        frame->Layout();

        return true;
    }

    void CalculatorApp::insertPlusSign(wxCommandEvent& event)
    {
        displayArea->AppendText("+");
    }

    void CalculatorApp::insertMinusSign(wxCommandEvent& event)
    {
        displayArea->AppendText("-");
    }

    void CalculatorApp::insertMultipySign(wxCommandEvent& event)
    {
        displayArea->AppendText("*");
    }

    void CalculatorApp::insertDivideSign(wxCommandEvent& event)
    {
        displayArea->AppendText("/");
    }

    void CalculatorApp::insertNumber(wxCommandEvent& event)
    {
        wxButton* btn = (wxButton*)event.GetEventObject();
        wxString currNum = btn->GetLabel();

        displayArea->AppendText(currNum);
    }

    void CalculatorApp::performCalc(wxCommandEvent& event)
    {
        wxString currValue = displayArea->GetValue();

        if (currValue.IsEmpty())
            return;

        double result = 0;
        char op = 0;
        double current = 0;

        std::string s = currValue.ToStdString();
        std::stringstream ss(s);

        ss >> result;

        while (ss >> op >> current)
        {
            switch (op)
            {
            case '+': result += current; break;
            case '-': result -= current; break;
            case '*': result *= current; break;
            case '/':
                if (current != 0)
                    result /= current;
                else
                {
                    displayArea->SetValue("Error");
                    return;
                }
                break;
            }
        }

        displayArea->SetValue(wxString::Format("%g", result));
    }

    void CalculatorApp::clearPrompt(wxCommandEvent& event)
    {
        displayArea->Clear();
    }

wxIMPLEMENT_APP(CalculatorApp);