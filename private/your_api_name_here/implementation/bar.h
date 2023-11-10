#pragma once

#include <your_api_name_here/implementation/implementation.h>
#include <your_api_name_here/implementation/foo.h>

#include <string>

namespace your_api_name_here::implementation
{
   struct bar_t : implementation_t
   {
      bar_t();
      ~bar_t();

      bar_t(const std::string& name);

      const std::string& get_name() const;
      void set_name(const std::string& name);

      foo_t& get_foo();

      // Return x squared mutiplied by the foo do_virtual.
      double do_bar(double x, const char* name);

   private:
      std::string my_name;

      // When using another versioned type, use the type from
      // the same namespace. Never change it afterward. The
      // versioning system will take care of doing the right thing.
      foo_t my_foo;
   };
}
