#include <your_api_name_here/implementation/bar.h>

#include <iostream>
#include <iomanip>

namespace your_api_name_here::implementation
{
   bar_t::bar_t()  = default;
   bar_t::~bar_t() = default;

   bar_t::bar_t(const std::string& name) : my_name(name), my_foo(name) {}

   const std::string& bar_t::get_name() const { return my_name; }
   void bar_t::set_name(const std::string& name) { my_name = name; my_foo.set_name(name); }

   foo_t& bar_t::get_foo() { return my_foo; }

   double bar_t::do_bar(double x, const char* name)
   {
      std::cout << "bar v1 " << std::quoted(my_name) << " do_bar(" << x << ", " << std::quoted(name ? name : "") << ") then calling my_foo: ";
      return x * x * my_foo.do_virtual(x);
   }
}
