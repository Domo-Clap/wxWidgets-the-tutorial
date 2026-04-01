#include <wx/wx.h>

// This is the specific include statement for the textCtrl widget
#include <wx/textctrl.h>


// The textCtrl widget is pretty much the actual text entry box widget we have in wxWidgets.
// Depending on what flags we pass to our textCtrl widget, we can make it either a single line input or multi-line input
// The textCtrl widget itself allows text to be displayed in the box and edited.
// A lot of the methods and controls in this widget are based off the wxTextEntry widget

// A cool thing with textCtrl widgets is that they support a lot of styling options. You can set colors and font for multiple or indiv characters in the entry box.

// In the official wxWidgets class reference pages, you can find it here: https://docs.wxwidgets.org/latest/classwx_text_ctrl.html

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Hello wxWidgets");
        frame->Show(true);

        // Lets make sure we define some points to determine where our label and entry widgets are going to be!
        // Also, good thing to note. In your actual apps, it isn't a good idea to use absolute positions for widgets. Instad, wxWidget sizers are the best option in your apps.
        // I am only using these hardcoded points to make it easier 
        wxPoint labelPos(100, 100);
        wxPoint entryPos(100, 120);

        wxPoint multiLabelPos(100, 160);
        wxPoint multiEntryPos(100, 180);

        wxPoint styledEntryPos(100, 210);

        // Lets also define some general sizes for the text entry boxe to make them easy to see!
        wxSize entrySize(150, 50);

        // Lets start off by making a label to go over the top of our text entry widget so we know what we are entering!
        wxStaticText* entryLabel = new wxStaticText(frame, wxID_ANY, "Please enter name here:", labelPos, wxDefaultSize);

        // Now lets create our first text entry widget
        // We'll make this one a single line entry box
        wxTextCtrl* nameEntryBox = new wxTextCtrl(frame, wxID_ANY, "", entryPos, wxDefaultSize);


        // Gotta have a label for the multi line entry box
        wxStaticText* multiEntryLabel = new wxStaticText(frame, wxID_ANY, "Please enter some text here:", multiLabelPos, wxDefaultSize);
        
        // Now lets create another text entry box, but this time, it will be a multi line entry box
        wxTextCtrl* multiEntryBox = new wxTextCtrl(frame, wxID_ANY, "", multiEntryPos, wxDefaultSize, wxTE_MULTILINE);



        // Cool!, now, lets try adding some styles into the textEntry box!
        wxTextCtrl* styledEntryBox = new wxTextCtrl(frame, wxID_ANY, "", styledEntryPos, wxDefaultSize, wxTE_MULTILINE);

        // The best way to add these styles is after the fact, so lets do that! (At least when starting out. It all depends on personal preferance really)
        // You can make it so the the styles are added in upon widget creation as well!

        // This style just sets the default style to have red text!
        // Warning! (This style only works on multiline text boxes)
        styledEntryBox->SetDefaultStyle(wxTextAttr(*wxRED));


        // And a fun thing we can do with the textCtrl widgets is append text. All you need to do is call the AppendText function on the textCtrl widget you want!
        styledEntryBox->AppendText("Cool Red Text!");

        // Now maybe lets try making the next set of text blue!
        // Warning! (This style only works on multiline text boxes)
        styledEntryBox->SetDefaultStyle(wxTextAttr(*wxBLUE));
        styledEntryBox->AppendText(" Fun Blue Text!!!");

        // With text entry boxes, there are a ton of other cool options you can mess around with, but be careful! Only some style options work for multiline text boxes!
        // There are also a great number of functions you can call on the textCtrl widgets that allow you to get the number of lines, the specific line text, the line length, the modified status, etc...

        return true;
    }
};

wxIMPLEMENT_APP(MyApp);