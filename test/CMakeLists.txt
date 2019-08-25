project(SymMath_Test)

find_package(Catch2 REQUIRED)

include(CTest)

macro(ADD_TEST_FILE TEST_NAME)
  add_executable(${TEST_NAME} ${TEST_NAME}.cc)
  target_link_libraries(${TEST_NAME} Catch2::Catch2)
  add_test(${TEST_NAME} ${PROJECT_BINARY_DIR}/${TEST_NAME})
endmacro()

ADD_TEST_FILE(test_main)
