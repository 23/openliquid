# Macro for performing a test
macro (PerformTest name source)
  include_directories(
        ${PROJECT_SOURCE_DIR}/lib
        )
  add_executable(Test${name}
      ${source}
    )
  target_link_libraries(Test${name}
      openliquid
      ${PCRECPP_LIBRARIES}
    )
  add_test (Test${name} Test${name})
endmacro (PerformTest)

PerformTest("LiquidExpressions" "tests/liquid/Expressions.cpp")
PerformTest("LiquidFragmentComparison" "tests/liquid/FragmentComparison.cpp")
PerformTest("LiquidRendering" "tests/liquid/Rendering.cpp")
