#include <your_api_name_here/versioned.h>

#include <stdint.h>

namespace your_api_name_here
{
   template <typename type_t>
   bool inline versioned_t<type_t>::is_reference_counted() const
   {
      return (uintptr_t(my_implementation) & uintptr_t(1)) == 0;
   }

   template <typename type_t>
   template <typename current_implementation_t>
   inline type_t versioned_t<type_t>::wrap(current_implementation_t& instance, bool is_ref_counted)
   {
      return type_t(reinterpret_cast<void *>(&instance), is_ref_counted);
   }

   template <typename type_t>
   template <typename current_implementation_t>
   inline const type_t versioned_t<type_t>::wrap(const current_implementation_t& instance, bool is_ref_counted)
   {
      return type_t(reinterpret_cast<void *>(&instance), is_ref_counted);
   }

   template <typename type_t>
   inline versioned_t<type_t>::versioned_t()
   : my_implementation(new type_t::current_implementation_t())
   {
      self<type_t::current_implementation_t>()->reference_implementation();
   }

   template <typename type_t>
   inline versioned_t<type_t>::~versioned_t()
   {
      if (is_reference_counted())
         self<type_t::current_implementation_t>()->forget_implementation();
   }

   template <typename type_t>
   inline versioned_t<type_t>::versioned_t(const versioned_t<type_t>& other)
   : my_implementation(other.my_implementation)
   {
      if (is_reference_counted())
         self<type_t::current_implementation_t>()->reference_implementation();
   }

   template <typename type_t>
   inline versioned_t<type_t>::versioned_t(versioned_t<type_t>&& other) noexcept
   : my_implementation(other.my_implementation)
   {
      if (is_reference_counted())
         self<type_t::current_implementation_t>()->reference_implementation();
   }

   template <typename type_t>
   inline versioned_t<type_t>::versioned_t(void * existing_implementation, bool is_ref_counted)
   : my_implementation(existing_implementation)
   {
      if (is_ref_counted)
         self<type_t::current_implementation_t>()->reference_implementation();
      else
         my_implementation = reinterpret_cast<void *>(uintptr_t(my_implementation) | uintptr_t(1));
   }

   template <typename type_t>
   inline versioned_t<type_t>& versioned_t<type_t>::operator=(const versioned_t<type_t>& other)
   {
      const bool was_referenced_counted = is_reference_counted();
      auto to_be_forgotten = self<type_t::current_implementation_t>();

      my_implementation = other.my_implementation;
      if (is_reference_counted())
         self<type_t::current_implementation_t>()->reference_implementation();

      if (was_referenced_counted)
         to_be_forgotten->forget_implementation();

      return *this;
   }

   template <typename type_t>
   inline versioned_t<type_t>& versioned_t<type_t>::operator=(versioned_t<type_t>&& other) noexcept
   {
      const bool was_referenced_counted = is_reference_counted();
      auto to_be_forgotten = self<type_t::current_implementation_t>();

      my_implementation = other.my_implementation;
      if (is_reference_counted())
         self<type_t::current_implementation_t>()->reference_implementation();

      if (was_referenced_counted)
         to_be_forgotten->forget_implementation();

      return *this;
   }

   template <typename type_t>
   template <typename current_implementation_t>
   inline current_implementation_t* versioned_t<type_t>::self()
   {
      return reinterpret_cast<current_implementation_t *>(uintptr_t(my_implementation) & ~uintptr_t(1));
   }

   template <typename type_t>
   template <typename current_implementation_t>
   inline const current_implementation_t* versioned_t<type_t>::self() const
   {
      return reinterpret_cast<const current_implementation_t *>(uintptr_t(my_implementation) & ~uintptr_t(1));
   }
}
