cmake_minimum_required(VERSION 3.21.0)

project(your_api_name_here)

if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

enable_testing()

add_library(your_api_name_here SHARED
   README.md

   include/your_api_name_here/bar.h
   include/your_api_name_here/foo.h
   include/your_api_name_here/version.h
   include/your_api_name_here/versioned.h                src/implementation/versioned.cpp

   include/your_api_name_here/v1/bar.h                   src/v1/bar.cpp
   include/your_api_name_here/v1/foo.h                   src/v1/foo.cpp
   
   private/your_api_name_here/implementation/bar.h       src/implementation/bar.cpp
   private/your_api_name_here/implementation/foo.h       src/implementation/foo.cpp
   private/your_api_name_here/implementation/implementation.h
)

source_group("Header Files/v1" FILES
   include/your_api_name_here/v1/bar.h
   include/your_api_name_here/v1/foo.h
)

source_group("Source Files/v1" FILES
   src/v1/bar.cpp
   src/v1/foo.cpp
)

source_group("Header Files/implementation" FILES
   private/your_api_name_here/implementation/bar.h
   private/your_api_name_here/implementation/foo.h
   private/your_api_name_here/implementation/implementation.h
)

target_compile_features(your_api_name_here PUBLIC
   cxx_std_20
)

target_include_directories(your_api_name_here PUBLIC
   include
)

target_include_directories(your_api_name_here PRIVATE
   private
)

add_subdirectory(tests/v1)

add_subdirectory(examples/using_v1)
