#include <wx/wx.h>
#include <sstream>

class CalculatorApp : public wxApp
{
public:
    virtual bool OnInit();


    // Buttons
    wxButton* button_1;
    wxButton* button_2;
    wxButton* button_3;
    wxButton* button_4;
    wxButton* button_5;
    wxButton* button_6;
    wxButton* button_7;
    wxButton* button_8;
    wxButton* button_9;
    wxButton* button_0;

    wxButton* button_plus;
    wxButton* button_minus;
    wxButton* button_multiply;
    wxButton* button_divide;
    wxButton* button_enter;
    wxButton* button_clear;

    // Text Entry
    wxTextCtrl* displayArea;

private:
    void insertPlusSign(wxCommandEvent& event);
    void insertMinusSign(wxCommandEvent& event);
    void insertMultipySign(wxCommandEvent& event);
    void insertDivideSign(wxCommandEvent& event);
    void insertNumber(wxCommandEvent& event);
    void performCalc(wxCommandEvent& event);
    void clearPrompt(wxCommandEvent& event);

};