#pragma once
#include <Windows.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <mutex>
#include <string>
#include <vector>

namespace DailyQoute {
using std::string;
class console {
public:
  void Init();

  // Send message
  void Send(string text);
  void Send(string text, int color);
  void SendDebug(string text);
  void SendDebug(string text, int color);

  // Input
  std::string In();
  std::string In(string text);
  std::string In(string text, int color);
};

inline std::unique_ptr<console> Console;
} // namespace DailyQoute