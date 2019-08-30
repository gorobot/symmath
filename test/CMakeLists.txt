project(SymMath_Test)

find_package(Catch2 REQUIRED)

include(CTest)
include(Catch)

set(TEST_MAIN test_main)

macro(create_test)
  # set(options OPTIONAL)
  set(ONE_VALUE_ARGS NAME)
  set(MULTI_VALUE_ARGS FILES)
  cmake_parse_arguments(
    CREATE_TEST
    ""
    "${ONE_VALUE_ARGS}"
    "${MULTI_VALUE_ARGS}"
    ${ARGN}
  )

  list(APPEND CREATE_TEST_FILES ${TEST_MAIN})

  message("${CREATE_TEST_NAME}")
  add_executable(${CREATE_TEST_NAME} ${CREATE_TEST_FILES})
  target_link_libraries(${CREATE_TEST_NAME} Catch2::Catch2)
  target_include_directories(${CREATE_TEST_NAME} INTERFACE
    $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/symmath>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  )

  catch_discover_tests(${CREATE_TEST_NAME})
endmacro()

create_test(
  NAME Numerics
  FILES
  test_complex
  test_integer
  test_natural
  test_real
)

# set(NUMERIC_TESTS
#   ${TEST_MAIN}
#   test_complex
#   test_integer
#   test_natural
#   test_real
# )
#
# add_executable(NumericMain ${NUMERIC_TESTS})
# target_link_libraries(NumericMain Catch2::Catch2)
# target_include_directories(NumericMain INTERFACE
#   $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/symmath>
#   $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
# )
#
# catch_discover_tests(NumericMain)

#
# foreach(name ${NUMERIC_TESTS})
#   add_executable(${name} ${name}.cc $<TARGET_OBJECTS:NumericMain>)
#   target_link_libraries(${name} Catch2::Catch2)
# endforeach()

# add_executable(test_main test_main.cc)
# target_link_libraries(test_main Catch2::Catch2)
# target_include_directories(test_main PUBLIC ${PROJECT_SOURCE_DIR}/test)

# catch_discover_tests(test_numeric)

# macro(ADD_TEST_FILE TEST_NAME)
#   add_executable(${TEST_NAME} ${TEST_NAME}.cc)
#   target_link_libraries(${TEST_NAME} Catch2::Catch2)
#   add_test(${TEST_NAME} ${PROJECT_BINARY_DIR}/${TEST_NAME})
# endmacro()

# macro(add_test_file)
#   # set(options OPTIONAL)
#   set(oneValueArgs FILE)
#   set(multiValueArgs TESTS)
#   cmake_parse_arguments(
#     ADD_TEST_FILE
#     ""
#     "${oneValueArgs}"
#     "${multiValueArgs}"
#     ${ARGN}
#   )
#
#   # foreach(something ${ADD_TEST_FILE_FILE})
#   #   message("${something}")
#   # endforeach()
#
#   # add_executable(${ADD_TEST_FILE_FILE} ${ADD_TEST_FILE_FILE}.cc)
#   target_link_libraries(${ADD_TEST_FILE_FILE} Catch2::Catch2)
#
#   foreach(linked_test ${ADD_TEST_FILE_TESTS})
#     target_link_libraries(${ADD_TEST_FILE_FILE} linked_test)
#   endforeach()
#
#   add_test(${ADD_TEST_FILE_FILE} ${PROJECT_BINARY_DIR}/${ADD_TEST_FILE_FILE}.cc)
# endmacro()

# ADD_TEST_FILE(test_main)

# ADD_TEST_FILE(FILE test_numeric
#   TESTS
#   test_complex
#   test_integer
#   test_natural
#   test_real
# )

# ADD_TEST_FILE(test_complex)
# ADD_TEST_FILE(test_integer)
# ADD_TEST_FILE(test_natural)
# ADD_TEST_FILE(test_real)

# ADD_TEST_FILE(test_variable)

# ADD_TEST_FILE(test_operation)
