find_program(visual_studio_test
   NAMES vstest.console.exe REQUIRED)

add_library(your_api_name_here_v1_tests SHARED
   foo_tests.cpp
   bar_tests.cpp
)

target_link_libraries(your_api_name_here_v1_tests PUBLIC
   your_api_name_here
)

target_compile_features(your_api_name_here_v1_tests PUBLIC
   cxx_std_20
)

target_include_directories(your_api_name_here_v1_tests PUBLIC
   your_api_name_here
)

add_test(
   NAME your_api_name_here_v1_tests
   COMMAND "${visual_studio_test}" "$<TARGET_FILE:your_api_name_here_v1_tests>")