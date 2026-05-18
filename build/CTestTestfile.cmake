# CMake generated Testfile for 
# Source directory: C:/Users/Yourm/Documents/TSU/C++/cpp_timer_project
# Build directory: C:/Users/Yourm/Documents/TSU/C++/cpp_timer_project/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(TimerTests "C:/Users/Yourm/Documents/TSU/C++/cpp_timer_project/build/Debug/timer_tests.exe")
  set_tests_properties(TimerTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Yourm/Documents/TSU/C++/cpp_timer_project/CMakeLists.txt;14;add_test;C:/Users/Yourm/Documents/TSU/C++/cpp_timer_project/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(TimerTests "C:/Users/Yourm/Documents/TSU/C++/cpp_timer_project/build/Release/timer_tests.exe")
  set_tests_properties(TimerTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Yourm/Documents/TSU/C++/cpp_timer_project/CMakeLists.txt;14;add_test;C:/Users/Yourm/Documents/TSU/C++/cpp_timer_project/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(TimerTests "C:/Users/Yourm/Documents/TSU/C++/cpp_timer_project/build/MinSizeRel/timer_tests.exe")
  set_tests_properties(TimerTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Yourm/Documents/TSU/C++/cpp_timer_project/CMakeLists.txt;14;add_test;C:/Users/Yourm/Documents/TSU/C++/cpp_timer_project/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(TimerTests "C:/Users/Yourm/Documents/TSU/C++/cpp_timer_project/build/RelWithDebInfo/timer_tests.exe")
  set_tests_properties(TimerTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Yourm/Documents/TSU/C++/cpp_timer_project/CMakeLists.txt;14;add_test;C:/Users/Yourm/Documents/TSU/C++/cpp_timer_project/CMakeLists.txt;0;")
else()
  add_test(TimerTests NOT_AVAILABLE)
endif()
