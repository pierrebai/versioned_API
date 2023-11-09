#include <your_api_name_here/implementation/foo.h>

#include <iostream>
#include <iomanip>

namespace your_api_name_here::implementation
{
   foo_t::foo_t()  = default;
   foo_t::~foo_t() = default;

   foo_t::foo_t(const std::string& name) : my_name(name) {}
   
   const std::string& foo_t::get_name() const { return my_name; }
   void foo_t::set_name(const std::string& name) { my_name = name; }

   int foo_t::get_value() const { return my_value; }

   int foo_t::do_foo(int count, const char* name)
   {
      my_value += count;
      std::cout << "foo v2 " << std::quoted(my_name) << " do_foo(" << count << ", " << std::quoted(name ? name : "") << ") with my value = " << my_value << std::endl;
      return my_value;
   }

   double foo_t::do_virtual(double x, double y)
   {
      my_y = y;
      std::cout << "foo v2 " << std::quoted(my_name) << " do_virtual(" << x << ", " << y << ")" << std::endl;
      return x * 2. + y;
   }
}
