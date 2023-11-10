#pragma once

namespace your_api_name_here
{
   // Rules for derived classes:
   //    - Derive from versioned_t<your-class>.
   //    - Declare current_implementation_t to be the implementation of the class.
   //    - All functions must not be inlined.
   //    - All data is kept in the implementation.
   //    - A private constructor to wrap an existing implementation.
   //    - Friend the versioned_t<your-class>.
   template <typename type_t>
   struct versioned_t
   {
      template <typename current_implementation_t>
      static type_t wrap(current_implementation_t& instance, bool is_ref_counted);
      
      template <typename current_implementation_t>
      static const type_t wrap(const current_implementation_t& instance, bool is_ref_counted);
      
   protected:
      bool is_reference_counted() const;

      versioned_t();
      ~versioned_t();

      versioned_t(const versioned_t<type_t>& other);
      versioned_t(versioned_t<type_t>&& other) noexcept;

      versioned_t(void * existing_implementation, bool is_ref_counted);

      versioned_t<type_t>& operator=(const versioned_t<type_t>& other);
      versioned_t<type_t>& operator=(versioned_t<type_t>&& other) noexcept;

      template <typename current_implementation_t>
      current_implementation_t* self();

      template <typename current_implementation_t>
      const current_implementation_t* self() const;

   private:
      void* my_implementation = nullptr;
   };
}
