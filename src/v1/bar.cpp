#include <your_api_name_here/v1/bar.h>
#include <your_api_name_here/implementation/bar.h>

#include "../implementation/versioned.cpp"

namespace your_api_name_here::v1
{
   // The default constructor, destructor, copy constructors, and assigments
   // are all defaulted, but they must not be inlined for the magic of the
   // versioned_t class to work when new versions are created.

   bar_t::bar_t()  = default;
   bar_t::~bar_t() = default;

   bar_t::bar_t(const bar_t& other) = default;
   bar_t::bar_t(bar_t&& other)      = default;

   bar_t::bar_t(void* implementation, bool is_ref_counted) : versioned_t(implementation, is_ref_counted) {}

   bar_t& bar_t::operator=(const bar_t& other) = default;
   bar_t& bar_t::operator=(bar_t&& other)      = default;

   // All member functions get forwarded to the implementation.

   bar_t::bar_t(const std::string& name) { self<current_implementation_t>()->set_name(name); }

   const std::string& bar_t::get_name() const { return self<current_implementation_t>()->get_name(); }
   void bar_t::set_name(const std::string& name) { self<current_implementation_t>()->set_name(name); }

   foo_t bar_t::get_foo() { return foo_t::wrap(self<current_implementation_t>()->get_foo(), false); }

   double bar_t::do_bar(double x, const char* name) { return self<current_implementation_t>()->do_bar(x, name); }
}
