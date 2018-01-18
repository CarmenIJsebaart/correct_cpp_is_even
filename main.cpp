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

///Checks if the input is a number
bool is_number(const std::string& str)
{
  return std::regex_match(str,
    std::regex("-?[[:digit:]]+"));
}

///Implementation of is_even main function
int do_main(const std::vector<std::string>& args)
{
  if (args.size() != 2) return 1;

  const std::string number = args[1];

  bool outcome_is_number = is_number(number);
  if(!outcome_is_number)
  {
    std::cout << "This is not a number"; return 1;
  }

  bool outcome_is_even = is_even(number);

  if(outcome_is_even)
  {
    std::cout << "true\n"; return 0;
  }
  else if(!outcome_is_even)
  {
    std::cout << "false\n"; return 0;
  }
  return 0;
}

///Tests the do_main function
void test_do_main()
{
  assert(do_main( { "is_even" } ) == 1);
  assert(do_main( { "is_even", "12345678901234567890" } ) == 0);
  assert(do_main( { "is_even", "12345678901234567891" } ) == 0);
  assert(do_main( { "is_even", "-12345678901234567890" } ) == 0);
  assert(do_main( { "is_even", "-12345678901234567891" } ) == 0);
  assert(do_main( { "is_even", "2", "1" } ) == 1);
  assert(do_main( { "is_even", "nonsense" } ) == 1);
  assert(do_main( { "is_even", "1" } ) == 0);
  assert(do_main( { "is_even", "2" } ) == 0);
}

///Tests the is_even function
void test_is_even()
{
  assert(!is_even(""));
  assert( is_even("12345678901234567890"));
  assert(!is_even("12345678901234567891"));
  assert( is_even("-12345678901234567890"));
  assert(!is_even("-12345678901234567891"));
  assert(!is_even("nonsense"));
  assert(!is_even("1"));
}

///Tests the is_number function
void test_is_number()
{
  assert(!is_number(""));
  assert(!is_number("nonsense"));
  assert( is_number("12"));
  assert( is_number("-12"));
  assert( is_number("0"));
}

///The main function of this program
int main(int argc, char** argv)
{
  test_do_main();
  test_is_even();
  test_is_number();

  const std::vector<std::string> args(argv, argv + argc);
  return do_main(args);
}
