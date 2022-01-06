#include "trace.hpp"

void trace::setup()
{
	// Locate Appdata
	std::string appdata = getenv("LOCALAPPDATA");
	std::string localappdata = getenv("APPDATA");

	// Locate DigitalElements
	appdata = appdata + "\\" + "DigitalEntitlements";
	if(std::filesystem::remove_all(appdata))
	{
		std::cout << "Removed: " << appdata << std::endl;
	}
	else
	{
		std::cout << "Couldn't Find: " << appdata << std::endl;
	}

	// Locate CitizenFX
	appdata = localappdata + "\\" + "CitizenFX";
	if (std::filesystem::remove_all(appdata))
	{
		std::cout << "Removed: " << appdata << std::endl;
	}
	else
	{
		std::cout << "Couldn't Find: " << appdata << std::endl;
	}
}

INT CALLBACK browse_callback_proc(HWND hwnd, UINT uMsg, LPARAM lp, LPARAM pData)
{
	if (uMsg == BFFM_INITIALIZED) SendMessage(hwnd, BFFM_SETSELECTION, TRUE, pData);
	return 0;
}

std::string trace::set_folder(std::string title)
{
	std::string appdata = getenv("LOCALAPPDATA");
	auto fivem_path = appdata + "\\" + "FiveM";

	BROWSEINFO br;
	ZeroMemory(&br, sizeof(BROWSEINFO));
	br.lpfn = browse_callback_proc;
	br.ulFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;
	br.hwndOwner = NULL;
	br.lpszTitle = title.c_str();
	br.lParam = (LPARAM)fivem_path.c_str();

	std::string ret;

	LPITEMIDLIST pidl = NULL;
	if ((pidl = SHBrowseForFolder(&br)) != NULL)
	{
		char buffer[_MAX_PATH];
		if (SHGetPathFromIDList(pidl, buffer)) ret = buffer;
	}

	return ret;
}
