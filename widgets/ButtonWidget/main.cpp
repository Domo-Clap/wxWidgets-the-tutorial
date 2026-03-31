#include <wx/wx.h>

// This is the specific include for the button widget
#include <wx/button.h>

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Hello wxWidgets");
        frame->Show(true);


        // So, lets discuss the button widget that exists within wxWidgets!
        // The button allows us to control things within our app. We can attach functions to these buttons to perform tasks, pull data, change datas, etc...
        // The button widget can pretty much be placed inside dialog boxes, panels, and any other window

        // By default, the label for the button is centered horizontally and vertically
        // Buttons in wxWidgets newer versions do have the capability to show both a label and an image in the button
        // Buttons can also have different images for different states! (whether the button is enabled, disabled, pressed, etc...)


        // Lets instantiate a button object now!
        // So, the button is pretty simple right now. Currently, it is just a button being displayed. There isn't any functionality attached to it, which we want with our buttons!
        //wxButton* firstButton = new wxButton(frame, wxID_ANY, "Click Me!", wxDefaultPosition, wxDefaultSize);

        // Just some basic points to move the button and label a bit away from each other
        wxPoint specificLabelPos(50, 50);
        wxPoint specificBtnPos(50, 100);

        headerLabel = new wxStaticText(frame, wxID_ANY, "Boring text...", specificLabelPos, wxDefaultSize);

        wxButton* changeTextButton = new wxButton(frame, wxID_ANY, "Change label text!", specificBtnPos, wxDefaultSize);

        // In order to attach the function to the button, we need to use the Bind functionality! This is pretty much wxWidgets way of having the callback attached to certain widgets
        // So, lets use Bind, to attach the onChangeTextButtonClick function to our changeTextButton!
        changeTextButton->Bind(wxEVT_BUTTON, &MyApp::onChangeTextButtonClick, this);

        // So in this Bind call, we essentially said to the computer, look at the changeTextButton, and bind the onChangeTextButtonClick function to it in relation toi a button event


        // There is a ton more on what buttons can do
        

        return true;
    }

private:
    wxStaticText* headerLabel;

    // So this callback is super easy to think about.
    // All we are doing is setting the headerLabel widget to a different string!
    void onChangeTextButtonClick(wxCommandEvent& event) {
        headerLabel->SetLabel("This is a cool label!!!");
    }
};

wxIMPLEMENT_APP(MyApp);