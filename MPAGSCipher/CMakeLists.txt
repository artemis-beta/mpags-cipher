# - Build sub-script for the MPAGSCipher library

# - Declare the build of the static MPAGSCipher Library

add_library(MPAGSCipher STATIC
 CaesarCipher.hpp
 Cipher.hpp
 CaesarCipher.cpp
 processCommandLine.hpp
 processCommandLine.cpp
 CipherFactory.hpp
 PlayFairCipher.cpp
 PlayFairCipher.hpp
 CipherFactory.cpp
 TransformChar.cpp
 TransformChar.hpp
 )
target_include_directories(MPAGSCipher PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_compile_features(MPAGSCipher PUBLIC cxx_auto_type cxx_range_for cxx_uniform_initialization cxx_binary_literals)

