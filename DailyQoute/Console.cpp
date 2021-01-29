#include "Console.hpp"
using namespace DailyQoute;

std::wstring Name = L"Daily Qoute";

void console::Init() {
	if (!AttachConsole(GetCurrentProcessId()))
		AllocConsole();
	SetConsoleTitle(Name.c_str());
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 700, 450, TRUE);

	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);

	SendDebug("Console allocated");
}

// Output

void console::Send(string text) {
	std::cout << text << "\n";
}

void console::Send(string text, int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << text << "\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // back to white
}


// Input 

std::string console::In() {
	std::string input;
	std::getline(std::cin,input);
	return input;
}

std::string console::In(string text) {
	std::string input;
	std::cout << text;
	std::getline(std::cin,input);
	return input;
}

std::string console::In(string text, int color) {
	std::string input;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << text;
	std::getline(std::cin,input);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // white
	return input;
}

// Debug

void console::SendDebug(string text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // green
	std::cout << "[DEBUG] ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // white
	std::cout << text << "\n";
}

void console::SendDebug(string text, int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // green
	std::cout << "[DEBUG] ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << text << "\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // white
}
