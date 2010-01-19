#include "FbHtmlWindow.h"
#include "FbConst.h"
#include "FbParams.h"
#include <wx/uri.h>

class FbURI: public wxURI
{
	public:
		FbURI(const wxString& uri): wxURI(uri) {};
		friend class FbHtmlWindow;
};

FbHtmlWindow::FbHtmlWindow(wxWindow *parent, wxWindowID id)
	: wxHtmlWindow(parent, id, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER)
{
}

wxHtmlOpeningStatus FbHtmlWindow::OnOpeningURL(wxHtmlURLType type, const wxString& url, wxString * redirect) const
{
	if (type != wxHTML_URL_IMAGE) return wxHTML_OPEN;

	wxString addr = url;
	FbURI uri = addr;

	if (uri.GetScheme() == wxT("http")) {
		if ( !FbParams::GetValue(FB_HTTP_IMAGES) ) {
			*redirect = wxT("memory:blank");
			return wxHTML_REDIRECT;
		}
	}

	return wxHTML_OPEN;
}

