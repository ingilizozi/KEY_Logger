#pragma once
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <time.h>
#include <string>

#ifdef LOGGERDLL_EXPORTS
#define LOGGERDLL_EXPORTS __declspec(dllexport)
#else
#define LOGGERDLL_EXPORTS __declspec(dllimport)
#endif // 
std::ofstream output_file;
int Save(int key_stroke);
extern "C" LOGGERDLL_EXPORTS void start();