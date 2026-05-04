#include "main.h"


// Our main function!
// This is where all of our components are getting rendered
bool MorseTranslatorApp::OnInit() {

	// Create our frame object and specify a title for the window, plus the starting window size
	wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Tutorial - Morse Translator App", wxDefaultPosition, wxSize(400, 400));
	frame->Show(true);

	// After making our frame, lets make our sizer:
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	mainSizer->AddSpacer(5);

	// Header label just to show at the top for a little bit more detail
	headerLbl = new wxStaticText(frame, wxID_ANY, "Morse Translator App", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
	// Add it to the sizer so it will show up and size properly
	mainSizer->Add(headerLbl, 0, wxALIGN_CENTER);

	// Text entry box for user to enter the text they want to convert
	enterEnglishBox = new wxTextCtrl(frame, wxID_ANY, "", wxDefaultPosition, wxSize(-1, 100), wxTE_RIGHT);
	// Add it to the sizer so it will show up and size properly
	mainSizer->Add(enterEnglishBox, 0, wxEXPAND | wxALL, 10);

	// Button for user to click to convert the enlgish to morse and open a dialog box showing the result.
	convertBtn = new wxButton(frame, wxID_ANY, "Convert to morse");
	// Binds the convert_text function to this button
	convertBtn->Bind(wxEVT_BUTTON, &MorseTranslatorApp::convert_text, this);
	// Add it to the sizer so it will show up and size properly
	mainSizer->Add(convertBtn, 0, wxALIGN_CENTER | wxALL, 5);

	// Set the min size of the window
	frame->SetMinSize(wxSize(300, 300));
	frame->SetSizer(mainSizer);
	frame->Layout();

	return true;
	
}


void MorseTranslatorApp::convert_text(wxCommandEvent& event) {
	// When we convert a piece of morse code, all we are really doing is taking the text, and finding in a map where the code (separated by spaces) based on key. Then grabbing the value for that key and adding it to a list

	// Adding alphabet values to morseMap 
	morseMap["A"] = ".-";
	morseMap["B"] = "-...";
	morseMap["C"] = "-.-.";
	morseMap["D"] = "-..";
	morseMap["E"] = ".";
	morseMap["F"] = "..-.";
	morseMap["G"] = "--.";
	morseMap["H"] = "....";
	morseMap["I"] = "..";
	morseMap["J"] = ".---";
	morseMap["K"] = "-.-";
	morseMap["L"] = ".-..";
	morseMap["M"] = "--";
	morseMap["N"] = "-.";
	morseMap["O"] = "---";
	morseMap["P"] = ".--.";
	morseMap["Q"] = "--.-";
	morseMap["R"] = ".-.";
	morseMap["S"] = "...";
	morseMap["T"] = "-";
	morseMap["U"] = "..-";
	morseMap["V"] = "...-";
	morseMap["W"] = ".--";
	morseMap["X"] = "-..-";
	morseMap["Y"] = "-.--";
	morseMap["Z"] = "--..";

	// Adding number values to morseMap
	morseMap["1"] = ".----";
	morseMap["2"] = "..---";
	morseMap["3"] = "...--";
	morseMap["4"] = "....-";
	morseMap["5"] = ".....";
	morseMap["6"] = "-....";
	morseMap["7"] = "--...";
	morseMap["8"] = "---..";
	morseMap["9"] = "----.";
	morseMap["0"] = "-----";

	// Adding punctuation to morseMap
	morseMap["."] = ".-.-.-";
	morseMap[","] = "--..--";
	morseMap["\?"] = "..--..";
	morseMap["\'"] = ".----.";
	morseMap["\:"] = "---...";
	morseMap["/"] = "-..-.";
	morseMap["\;"] = "-.-.-.";
	morseMap["+"] = ".-.-.";
	morseMap["-"] = "-....-";
	morseMap["="] = "-...-";
	morseMap[" "] = " ";

	// We want to take the text in 
	wxString enteredText = enterEnglishBox->GetValue();

	// Trim trailing and leading whitespaces
	enteredText = enteredText.Trim();
	enteredText = enteredText.Trim(false);

	// In order to generate the morse output, we need to loop over each character in the text, find the matching key in the map. Then take the value at that key, and append it to the vector
	std::string resultStr = "";
	std::string dialogText = "";

	if (enteredText.Length() == 0) {
		dialogText = "It seems there was no text entered in the entry box";
	}
	else {

		enteredText.MakeUpper();
		dialogText = "";

		std::string enteredTextStr = enteredText.ToStdString();

		// Loop over each character in the text box
		for (size_t i = 0; i < enteredText.length(); i++) {
			// turn it into a character
			wxChar c = enteredText[i];

			// and then make it a string of 1 char
			std::string enteredKey(1, static_cast<char>(c));

			// Then we find the value based on the key, and add the resulting value into the result string
			if (morseMap.find(enteredKey) != morseMap.end()) {
				resultStr += morseMap[enteredKey] + " ";
			}
		}

		dialogText += resultStr;
	}

	// Displays a simple dialog box with the morse code translation in it
	wxMessageBox(dialogText, "Translated Morse Code", wxOK | wxICON_INFORMATION);

}

wxIMPLEMENT_APP(MorseTranslatorApp);