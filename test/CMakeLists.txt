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
  numerics/test_complex
  numerics/test_integer
  numerics/test_natural
  numerics/test_real
)

create_test(
  NAME Tensors
  FILES
  tensors/test_matrix
  tensors/test_vector
  tensors/test_scalar
)
