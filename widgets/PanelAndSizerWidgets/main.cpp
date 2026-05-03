#include <wx/wx.h>

// This is the specific include statement for the panel widget
#include <wx/panel.h>

// This is the specific include statement for the box sizer widget
#include <wx/sizer.h>


// The panel widget is honestly one of the most important widgets in wxWidgets. It is like our star player in many apps.
// The best way to think of the panel widget is basically a window which sits on top of our frame, where we can place objects/other widgets
// We can have a ton of panels within one window, and it is kind of how we would want to build our apps. Each panel is a layer like in an art app. Each panel can have some sub levels too (Stuff inside the panel)!
// Panels are the spot where we want all our controls to go really.

// You can even have panels inside panels!

class MyApp : public wxApp
{
public:

    virtual bool OnInit()
    {
        wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Hello wxWidgets");
        frame->Show(true);


        // Lets get started!
        // Here is a basic panel object:
        wxPanel* headerPanel = new wxPanel(frame, wxID_ANY, wxDefaultPosition, wxDefaultSize);

        // Similar to the other widgets, we define the parent window/frame, the window/frame id, and the default position and size of the panel

        // Now, what can we do with a panel?
        // We can pretty much do anything in regards to placing other widgets inside of it!
        
        // However, what is the best way to place things inside of the a panel and make it so it scales correctly when we change the size of the window?
        // Sizers of course!

        // A sizer is basically an object that sits on top of a panel, frame, or window, and it makes it easier to create a layout within the panel/frame/window.
        // Sizers don't really draw anything to our screen. Rather, they are just our little invisible layout managers. (They are the dude who yells at the other components to get into place after a resize lol)
        // We specifically are going to use a box sizer here now:
        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        
        // To add an item to a sizer, we want to do the following:
        wxStaticText* headerLabel = new wxStaticText(frame, wxID_ANY, "This is the Header label!!!", wxDefaultPosition, wxDefaultSize);

        mainSizer->Add(headerLabel, 0, wxALL, 10);


        return true;
    }
};

wxIMPLEMENT_APP(MyApp);