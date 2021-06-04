#include "Console.hpp"
#include <TlHelp32.h>
#include <cpr/cpr.h>
#include <rapidjson/document.h>
#define FMT_HEADER_ONLY
#include <fmt/format.h>
using namespace DailyQoute;

DWORD procid = 0;

const char* wchartochar(WCHAR* w) {
	return (const char*)w;
}

void MainProgram() {
	cpr::Response r = cpr::Get(cpr::Url{ "http://api.quotable.io/random" });
	rapidjson::Document json;
	if (json.Parse(r.text.c_str()).HasParseError()) {
		Console->Send("Error parsing qoute", 4);
		MainProgram();
	}
	else {
		if (json.HasMember("content")) {
			std::string qoute = json["content"].GetString();
			std::string author = json["author"].GetString();
			Console->Send("Random qoute:");
			Console->Send(fmt::format("{0} \nBAuthor: {1}", qoute, author));
			Console->Send("\nInput something random and press enter to get a new qoute", 10);
			Console->In();
			MainProgram();
			return;
		}
		else {
			Console->Send("Error failed to get qoute", 4);
			MainProgram();
		}
	}

}

int main() {
	MainProgram();
}
