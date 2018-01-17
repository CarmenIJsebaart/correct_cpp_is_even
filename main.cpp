#include <cassert>
#include <iostream>
#include <regex>
#include <string>

///Checks if a number is even
bool is_even(const std::string& str)
{
  return std::regex_match(str,
    std::regex("-?[[:digit:]]+(2|4|6|8|0)"));
}

/// Implementation of is_even main function
int do_main(const std::vector<std::string>& args)
{
  if (args.size() != 2) return 1;
  try
  {
    const std::string number = args[1];
    bool outcome = is_even(number);

    if(outcome)
    {
      std::cout << "true\n"; return 0;
    }
    else if(!outcome)
    {
      std::cout << "true\n"; return 0;
    }
  }
  catch (const std::invalid_argument&)
  {
    return 1;
  }
  catch (const std::out_of_range&)
  {
    return 1;
  }
  return 0;
}

///The main function of this program
int main(int argc, char** argv)
{
  assert(do_main( { "is_even" } ) == 1);
  assert(do_main( { "is_even", "12345678901234567890" } ) == 0);
  assert(do_main( { "is_even", "12345678901234567891" } ) == 0);
  assert(do_main( { "is_even", "-12345678901234567890" } ) == 0);
  assert(do_main( { "is_even", "-12345678901234567891" } ) == 0);
  assert(do_main( { "is_even", "2", "1" } ) == 1);

  assert(!is_even(""));
  assert( is_even("12345678901234567890"));
  assert(!is_even("12345678901234567891"));
  assert( is_even("-12345678901234567890"));
  assert(!is_even("-12345678901234567891"));
  assert(!is_even("nonsense"));

  const std::vector<std::string> args(argv, argv + argc);
  return do_main(args);
}
