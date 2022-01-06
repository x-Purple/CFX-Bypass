#pragma once
#include "common.hpp"

class trace
{
public:
	void setup();
	bool set_path(std::string& folderpath, const char* szCaption = NULL, HWND hOwner = NULL);
	std::string set_folder(std::string title);
public:
	std::string m_fivem_path;
};

inline std::unique_ptr<trace> g_trace;