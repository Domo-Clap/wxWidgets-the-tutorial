#include <wx/wx.h>
#include <sstream>
#include <map>
#include <vector>


// We make our class off of the wxApp class, so we inherit from it
class MorseTranslatorApp : public wxApp
{

// List of public functions and vars
public:

	// window init function
	virtual bool OnInit();

	// Vars we want to be public to use in convert_text and other spaces easily
	wxButton* convertBtn;
	wxStaticText* headerLbl;
	wxTextCtrl* enterEnglishBox;

	// The map to contain morse to english conversions
	std::map<std::string, std::string> morseMap;

// List of private functions and vars
private:
	void convert_text(wxCommandEvent& event);

};