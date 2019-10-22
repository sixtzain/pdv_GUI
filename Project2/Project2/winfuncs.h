#pragma once
#ifdef WINFUNCS_EXPORTS
#define WINFUNCS_API __declspec(dllexport)
#else
#define WINFUNCS_API __declspec(dllexport)
#endif

extern "C" WINFUNCS_API bool checkInstallation();

extern "C" WINFUNCS_API bool checkSpecReg();

extern "C" WINFUNCS_API bool changeRegValue();