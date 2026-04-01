#include <wx/wx.h>


class MyApp : public wxApp
{
public:

    // So, on inititialization, we are creating our wxFrame as per usualy, but lets add in a label somewhere in our window!
    virtual bool OnInit()
    {
        wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Hello wxWidgets");
        frame->Show(true);

        return true;
    }
};

wxIMPLEMENT_APP(MyApp);