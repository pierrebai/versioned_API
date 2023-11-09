#include <your_api_name_here/v2/foo.h>
#include <your_api_name_here/implementation/foo.h>

#include "../implementation/versioned.cpp"

namespace your_api_name_here::v2
{
   // The default constructor, destructor, copy constructors, and assigments
   // are all defaulted, but they must not be inlined for the magic of the
   // versioned_t class to work when new versions are created.

   foo_t::foo_t()  = default;
   foo_t::~foo_t() = default;

   foo_t::foo_t(const foo_t& other) = default;
   foo_t::foo_t(foo_t&& other)      = default;

   foo_t::foo_t(void* implementation, bool is_ref_counted) : versioned_t(implementation, is_ref_counted) {}

   foo_t& foo_t::operator=(const foo_t& other) = default;
   foo_t& foo_t::operator=(foo_t&& other)      = default;

   // All member functions get forwarded to the implementation.

   foo_t::foo_t(const std::string& name) { self<current_implementation_t>()->set_name(name); }

   const std::string& foo_t::get_name() const { return self<current_implementation_t>()->get_name(); }
   void foo_t::set_name(const std::string& name) { self<current_implementation_t>()->set_name(name); }

   int foo_t::get_value() const { return self<current_implementation_t>()->get_value(); }

   int foo_t::do_foo(int count, const char* name) { return self<current_implementation_t>()->do_foo(count, name); }
   double foo_t::do_virtual(double x, double y) { return self<current_implementation_t>()->do_virtual(x, y); }
}
