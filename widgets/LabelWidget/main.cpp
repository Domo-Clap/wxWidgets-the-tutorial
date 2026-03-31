#include <wx/wx.h>

// This is the specific include statement for the static text widget
#include <wx/stattext.h>


// The Label widget, otherwise known as the StaticText widget is pretty simple in what it does
// It is just a widget that allows us to place static text within a specified space!
// The text within this widget is Read-only. Users can't write to it!

// In the official wxWidgets class reference pages, you can find it here: https://docs.wxwidgets.org/latest/classwx_static_text.html


class MyApp : public wxApp
{
public:

    // So, on inititialization, we are creating our wxFrame as per usualy, but lets add in a label somewhere in our window!
    virtual bool OnInit()
    {
        wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Hello wxWidgets");
        frame->Show(true);


        // So, here is where we actually build our first label
        // We start off by creating a wxStaticText pointer object and we assign it to a new wxStaticText object
        // In the constructor, there are a couple of params you can and will need to pass.

        // We first have the parent, which in this case is our frame!
        // Then, we have the windowID, which in this case you can just make either -1 or wxID_ANY since we aren't specifying a control id here
        // Next, we have the most important one, the label or text you want to appear! All you really need to do is provide a string here.
        // And then there is the position and size params. Basically where we want it to appear in the parent container, and the size we want it to appear as
        wxStaticText* headerLabel = new wxStaticText(frame, wxID_ANY, "This is the Header label!!!", wxDefaultPosition, wxDefaultSize);


        // Here we are setting a specific position via wxPoint
        // And we are setting a sepcific size via wxSize
        wxPoint specificPos(50, 50);
        wxSize specificSize(300, 300);

        // Lets look at another example of it here
        // For this example, we will provide a specific position and size instead of the default
        wxStaticText* secondHeaderLabel = new wxStaticText(frame, wxID_ANY, "Now we have a second label!", specificPos, specificSize);


        // Now we have an important function you can use for StaticText Widgets: SetLabel
        // As simple as it sounds, it lets you change the string in the widget!
        headerLabel->SetLabel("New Header Label");

        return true;
    }
};

wxIMPLEMENT_APP(MyApp);