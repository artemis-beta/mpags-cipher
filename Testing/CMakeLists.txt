# - Build sub-script for the MPAGSCipher library unit tests

# Most basic test
add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)

# Create Interface Library for Catch
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# First Catch based test
add_executable(testCatch testCatch.cpp)
add_test(NAME test-catch COMMAND testCatch)
target_link_libraries(testCatch Catch)

# Test TransformChar
add_executable(testTransformChar testTransformChar.cpp)
add_test(NAME test-transformchar COMMAND testTransformChar)
target_link_libraries(testTransformChar MPAGSCipher Catch)
