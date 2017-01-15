#pragma once
#ifdef CMDLINE_EXPORTS
#define CMDLINE_API __declspec(dllexport)
#else
#define CMDLINE_API __declspec(dllimport)
#endif