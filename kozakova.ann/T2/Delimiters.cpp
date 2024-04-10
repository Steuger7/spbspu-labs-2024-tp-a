#include "Delimiters.hpp"
#include <algorithm>
#include "StreamGuard.hpp"

std::istream& kozakova::operator>>(std::istream& in, kozakova::DelimiterString&& exp)
{
  std::istream::sentry guard(in);
  if (!guard)
  {
    return in;
  }
  std::string s = "";
  char c = 0;
  for (int i = 0; i < 3; ++i)
  {
    std::cin.get(c);
    s += c;
  }
  std::string expUp = exp.expected;
  std::transform(exp.expected.begin(), exp.expected.end(), exp.expected.begin(), ::tolower);
  if (!(s == exp.expected || s == expUp))
  {
    in.setstate(std::ios::failbit);
  }
  return in;
}

std::istream& kozakova::operator>>(std::istream& in, kozakova::DelimiterChar&& exp)
{
  std::istream::sentry guard(in);
  if (!guard)
  {
    return in;
  }
  kozakova::StreamGuard sguard(in);
  char c = 0;
  in >> c;
  if (!(c == exp.expected || c == std::tolower(exp.expected)))
  {
    in.setstate(std::ios::failbit);
  }
  return in;
}
