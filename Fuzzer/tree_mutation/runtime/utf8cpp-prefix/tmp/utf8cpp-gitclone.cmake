
if(NOT "/mnt/d/zyp/fuzzer/memdbFuzz/tree_mutation/runtime/utf8cpp-prefix/src/utf8cpp-stamp/utf8cpp-gitinfo.txt" IS_NEWER_THAN "/mnt/d/zyp/fuzzer/memdbFuzz/tree_mutation/runtime/utf8cpp-prefix/src/utf8cpp-stamp/utf8cpp-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/mnt/d/zyp/fuzzer/memdbFuzz/tree_mutation/runtime/utf8cpp-prefix/src/utf8cpp-stamp/utf8cpp-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/mnt/d/zyp/fuzzer/memdbFuzz/tree_mutation/runtime/thirdparty/utfcpp"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/mnt/d/zyp/fuzzer/memdbFuzz/tree_mutation/runtime/thirdparty/utfcpp'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout "https://github.com/nemtrif/utfcpp" "utfcpp"
    WORKING_DIRECTORY "/mnt/d/zyp/fuzzer/memdbFuzz/tree_mutation/runtime/thirdparty"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/nemtrif/utfcpp'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout v3.1.1 --
  WORKING_DIRECTORY "/mnt/d/zyp/fuzzer/memdbFuzz/tree_mutation/runtime/thirdparty/utfcpp"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'v3.1.1'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/mnt/d/zyp/fuzzer/memdbFuzz/tree_mutation/runtime/thirdparty/utfcpp"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/mnt/d/zyp/fuzzer/memdbFuzz/tree_mutation/runtime/thirdparty/utfcpp'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/mnt/d/zyp/fuzzer/memdbFuzz/tree_mutation/runtime/utf8cpp-prefix/src/utf8cpp-stamp/utf8cpp-gitinfo.txt"
    "/mnt/d/zyp/fuzzer/memdbFuzz/tree_mutation/runtime/utf8cpp-prefix/src/utf8cpp-stamp/utf8cpp-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/mnt/d/zyp/fuzzer/memdbFuzz/tree_mutation/runtime/utf8cpp-prefix/src/utf8cpp-stamp/utf8cpp-gitclone-lastrun.txt'")
endif()

