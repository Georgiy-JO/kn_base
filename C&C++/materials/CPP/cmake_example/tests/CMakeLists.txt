cmake_minimum_required(VERSION 3.21)
project(ViewerGTests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# if(CMAKE_BUILD_TYPE STREQUAL "Release")
#     add_compile_options(-O2 -DNDEBUG)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  add_compile_options(
    -Wall 
    -Wextra 
    -Wpedantic
    -Werror
    -g
    -D_POSIX_C_SOURCE=201706L
    -O0 
    )
endif()

option(BUILD_TESTS "Build tests" ON)
option(BUILD_COVERAGE "Enable code coverage" ON)

if(BUILD_TESTS OR BUILD_COVERAGE)
    find_program(VALGRIND_EXECUTABLE valgrind)
    find_program(LCOV_EXECUTABLE lcov)
    find_program(GENHTML_EXECUTABLE genhtml)
    find_package(glm REQUIRED)

    set(INBOUND_MODEL_INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/..
        ${CMAKE_CURRENT_SOURCE_DIR}/../core/math
        ${CMAKE_CURRENT_SOURCE_DIR}/../model
        ${CMAKE_CURRENT_SOURCE_DIR}/../model/model3d
        ${CMAKE_CURRENT_SOURCE_DIR}/../model/model3d/elements
        ${CMAKE_CURRENT_SOURCE_DIR}/../model/parser
        ${CMAKE_CURRENT_SOURCE_DIR}/../model/parser/service_functions
    )
    set(INBOUND_MODEL_SRC
        ../model/model3d/model3d.cpp
        ../model/model3d/elements/axisbounds.cpp
        ../model/model3d/elements/edges.cpp
        ../model/model3d/elements/vertices.cpp
        ../core/math/vec3.cpp

        ../model/parser/parser_src/parser.cpp
        ../model/parser/parser_src/model_parser.cpp
        ../model/parser/parser_src/model_alterers.cpp
        ../model/parser/parser_src/prefix_handlers.cpp
        ../model/parser/service_functions/service_functions.cpp
    )
    set(INBOUND_MODEL_TEST_SRC
        model/model3d_tests.cpp
        model/parser_tests.cpp
    )

    set(THIRD_PARTY_INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/..
        ${CMAKE_CURRENT_SOURCE_DIR}/../third_party
        ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/matrix
    )
    set(THIRS_PARTY_SRC
        ../third_party/matrix/matrix.cpp
    )
    set(THIRS_PARTY_TEST_SRC
        third_party/matrix_tests.cpp
    )

    set(CORE_INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/../core/math
        ${CMAKE_CURRENT_SOURCE_DIR}/../core/parameters
        ${CMAKE_CURRENT_SOURCE_DIR}/../core/service
        ${THIRD_PARTY_INCLUDE_DIRS}
    )
    set(CORE_SRC
        ../core/math/vec3.cpp
        ../core/math/vec4.cpp
        ../core/math/matrix4x4.cpp
        ../core/service/service.cpp
        ../core/parameters/view_parameters.cpp
        ${THIRS_PARTY_SRC}
    )
    set(CORE_TEST_SRC
        core/core_tests.cpp
        core/view_parameters_tests.cpp
    )

    find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Gui OpenGLWidgets)  
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui OpenGLWidgets)    
    if(${QT_VERSION_MAJOR})
        set(RENDER_INCLUDE_DIRS
            ${CMAKE_CURRENT_SOURCE_DIR}/../view/render
            ${CMAKE_CURRENT_SOURCE_DIR}/../view/render/uniforms
            ${CMAKE_CURRENT_SOURCE_DIR}/../view/render/shaders
            ${CMAKE_CURRENT_SOURCE_DIR}/../view/render/render_src
            ${CORE_INCLUDE_DIRS}
            ${INBOUND_MODEL_INCLUDE_DIRS}
        )
        set(RENDER_SRC
            ../view/render/uniforms/uniforms.cpp
            ../view/render/render_src/gpu_model.cpp        
            ../view/render/render_src/shader_program.cpp
            ${CORE_SRC}
            ${INBOUND_MODEL_SRC}
        )
        set(RENDER_TEST_SRC
            render/main.cpp
            render/uniforms_tests.cpp
            render/gpu_model_tests.cpp
            render/shader_program_tests.cpp
        )
        set(RENDER_VALG_SRC
            ../view/render/uniforms/uniforms.cpp
            ${CORE_SRC}
        )
        set(RENDER_VALG_TEST_SRC
            render/uniforms_tests.cpp
        )
        file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../view/render/shaders
            DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
    else()
        message(WARNING "No render tests will be possible, QT source files was not found.")
    endif()

    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    FetchContent_MakeAvailable(googletest)

    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../../materials/models
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

endif()

if(BUILD_TESTS)
    # Core tests
    add_executable(core_tests
        ${CORE_TEST_SRC}       # <- test code files
        ${CORE_SRC}
    )

    target_include_directories(core_tests PRIVATE ${CORE_INCLUDE_DIRS})
    target_link_libraries(core_tests PRIVATE gtest_main pthread)
    set_property(TARGET core_tests PROPERTY CXX_STANDARD 20)
    add_test(NAME CoreTests COMMAND core_tests)

    add_custom_target(run_core_tests
        COMMAND core_tests
        DEPENDS core_tests
        COMMENT "Running core_tests executable"
    )

    if(VALGRIND_EXECUTABLE)
        add_custom_target(valgrind_core_tests
            COMMAND valgrind 
                --tool=memcheck  
                --leak-check=full 
                --show-leak-kinds=all 
                --track-origins=yes 
                --verbose 
                --log-file=valgrind_core_tests.txt
                $<TARGET_FILE:core_tests>
            DEPENDS core_tests
            COMMENT "Running core_tests under Valgrind (see valgrind_core_tests.txt)."
        )
    else()
        message(WARNING "Valgrind not found. valgrind_core_tests target will not be available.")
    endif()

    # Inbound model tests
    add_executable(inbound_model_tests
        ${INBOUND_MODEL_TEST_SRC}       # <- test code files
        ${INBOUND_MODEL_SRC}
    )

    target_include_directories(inbound_model_tests PRIVATE ${INBOUND_MODEL_INCLUDE_DIRS})
    target_link_libraries(inbound_model_tests PRIVATE gtest_main pthread)
    set_property(TARGET inbound_model_tests PROPERTY CXX_STANDARD 20)
    add_test(NAME ModelTests COMMAND inbound_model_tests)

    add_custom_target(run_inbound_model_tests
        COMMAND inbound_model_tests
        DEPENDS inbound_model_tests
        COMMENT "Running inbound_model_tests executable"
    )

    if(VALGRIND_EXECUTABLE)
        add_custom_target(valgrind_inbound_model_tests
            COMMAND valgrind 
                --tool=memcheck  
                --leak-check=full 
                --show-leak-kinds=all 
                --track-origins=yes 
                --verbose 
                --log-file=valgrind_inbound_model_tests.txt
                $<TARGET_FILE:inbound_model_tests>
            DEPENDS inbound_model_tests
            COMMENT "Running inbound_model_tests under Valgrind (see valgrind_inbound_model_tests.txt)."
        )
    else()
        message(WARNING "Valgrind not found. valgrind_inbound_model_tests target will not be available.")
    endif()

    # Third party tests
    add_executable(third_party_tests
        ${THIRS_PARTY_TEST_SRC}       # <- test code files
        ${THIRS_PARTY_SRC}
    )

    target_include_directories(third_party_tests PRIVATE ${THIRD_PARTY_INCLUDE_DIRS})
    target_link_libraries(third_party_tests PRIVATE gtest_main pthread)
    set_property(TARGET third_party_tests PROPERTY CXX_STANDARD 20)
    add_test(NAME ThirdPartyTests COMMAND third_party_tests)

    add_custom_target(run_third_party_tests
        COMMAND third_party_tests
        DEPENDS third_party_tests
        COMMENT "Running third_party_tests executable"
    )

    if(VALGRIND_EXECUTABLE)
        add_custom_target(valgrind_third_party_tests
            COMMAND valgrind 
                --tool=memcheck  
                --leak-check=full 
                --show-leak-kinds=all 
                --track-origins=yes 
                --verbose 
                --log-file=valgrind_third_party_tests.txt
                $<TARGET_FILE:third_party_tests>
            DEPENDS third_party_tests
            COMMENT "Running third_party_tests under Valgrind (see valgrind_third_party_tests.txt)."
        )
    else()
        message(WARNING "Valgrind not found. valgrind_third_party_tests target will not be available.")
    endif()

    # Render tests
    if(${QT_VERSION_MAJOR})
        add_executable(render_tests
            ${RENDER_TEST_SRC}       # <- test code files
            ${RENDER_SRC}
        )

        target_include_directories(render_tests PRIVATE ${RENDER_INCLUDE_DIRS})
        target_link_libraries(render_tests PRIVATE gtest pthread Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::OpenGLWidgets) 
        set_property(TARGET render_tests PROPERTY CXX_STANDARD 20)
        add_test(NAME RenderTests COMMAND render_tests)

        add_custom_target(run_render_tests
            COMMAND render_tests
            DEPENDS render_tests
            COMMENT "Running render_tests executable"
        )

        if(VALGRIND_EXECUTABLE)
            add_executable(render_valg_tests
                ${RENDER_VALG_TEST_SRC}       # <- test code files
                ${RENDER_VALG_SRC}
            )

            target_include_directories(render_valg_tests PRIVATE ${RENDER_INCLUDE_DIRS})
            target_link_libraries(render_valg_tests PRIVATE gtest_main pthread Qt${QT_VERSION_MAJOR}::Gui) 
            set_property(TARGET render_valg_tests PROPERTY CXX_STANDARD 20)


            add_custom_target(valgrind_render_tests
                COMMAND valgrind 
                    --tool=memcheck  
                    --leak-check=full 
                    --show-leak-kinds=all 
                    --track-origins=yes 
                    --verbose 
                    --log-file=valgrind_render_tests.txt
                    $<TARGET_FILE:render_valg_tests>
                DEPENDS render_valg_tests
                COMMENT "Running render_valg_tests under Valgrind (see valgrind_render_tests.txt)."
            )

            add_custom_target(valgrind_global
                DEPENDS
                    valgrind_third_party_tests 
                    valgrind_core_tests 
                    valgrind_inbound_model_tests 
                    valgrind_render_tests
                COMMENT "Running all tests via valgrind at once (see valgrind_third_party_tests.txt, valgrind_core_tests.txt, valgrind_inbound_model_tests.txt, valgrind_render_tests.txt)."
            )
        else()
            message(WARNING "Valgrind not found. valgrind_render_tests and valgrind_global targets will not be available.")
        endif()
    endif()

    # All tests
    if(${QT_VERSION_MAJOR})
        add_custom_target(tests
            DEPENDS
                run_third_party_tests
                run_core_tests
                run_inbound_model_tests
                run_render_tests
            COMMENT "Running all tests at once."
        )
    else()
        add_custom_target(tests
            DEPENDS
                run_third_party_tests
                run_core_tests
                run_inbound_model_tests
            COMMENT "Running all tests at once."
        )
    endif()

endif()

if(BUILD_COVERAGE AND LCOV_EXECUTABLE AND GENHTML_EXECUTABLE)

    if(${QT_VERSION_MAJOR})
        add_executable(test_cov
            ${THIRS_PARTY_TEST_SRC}         # <- test code files
            ${INBOUND_MODEL_TEST_SRC}       # <- test code files
            ${CORE_TEST_SRC}                # <- test code files
            ${RENDER_TEST_SRC}              # <- test code files
            ${RENDER_SRC}                   # include ${THIRS_PARTY_SRC} ${CORE_SRC} ${INBOUND_MODEL_SRC}
        )
        target_include_directories(test_cov PRIVATE 
            ${RENDER_INCLUDE_DIRS}            # include ${THIRD_PARTY_INCLUDE_DIRS} ${INBOUND_MODEL_INCLUDE_DIRS} ${CORE_INCLUDE_DIRS}
            )
        target_link_libraries(test_cov PRIVATE 
            gtest 
            pthread 
            Qt${QT_VERSION_MAJOR}::Gui 
            Qt${QT_VERSION_MAJOR}::OpenGLWidgets 
        )
    else()
        add_executable(test_cov
            ${THIRS_PARTY_TEST_SRC}         # <- test code files
            ${INBOUND_MODEL_TEST_SRC}       # <- test code files
            ${CORE_TEST_SRC}                # <- test code files
            ${INBOUND_MODEL_SRC}
            ${CORE_SRC}                     # include ${THIRS_PARTY_SRC}
        )
        target_include_directories(test_cov PRIVATE 
            ${INBOUND_MODEL_INCLUDE_DIRS}
            ${CORE_INCLUDE_DIRS}            # include ${THIRD_PARTY_INCLUDE_DIRS} 
            )
        target_link_libraries(test_cov PRIVATE gtest_main pthread)
    endif()

    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY CMAKE_COVERAGE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
    
    target_compile_options(test_cov  PRIVATE
        -fprofile-arcs 
        -ftest-coverage
    )
    target_link_options(test_cov PRIVATE --coverage)

    add_custom_target(coverage
        COMMAND ${CMAKE_COMMAND} -E remove_directory coverage
        COMMAND ${CMAKE_COMMAND} -E make_directory coverage

        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_cov

        COMMAND ${LCOV_EXECUTABLE} --capture --directory ${CMAKE_CURRENT_BINARY_DIR}  --output-file coverage/coverage_1.info --rc geninfo_unexecuted_blocks=1 --ignore-errors mismatch,mismatch --path ${CMAKE_CURRENT_BINARY_DIR}/..
        COMMAND ${LCOV_EXECUTABLE} --remove coverage/coverage_1.info '/usr/*' 'gtest/*' 'tests/*' --output-file coverage/coverage.info
        COMMAND ${CMAKE_COMMAND} -E remove -f coverage/coverage_1.info
        COMMAND ${GENHTML_EXECUTABLE} --output-directory=coverage coverage/coverage.info

        # COMMAND find ${CMAKE_CURRENT_BINARY_DIR} -name "*.gcda" -o -name "*.gcno" -delete         # isues may cause these
        # COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_CURRENT_BINARY_DIR}/test_cov

        DEPENDS test_cov
        COMMENT "Running tests + Generating HTML coverage report in ./coverage"
    )

else()
    message(WARNING "Coverage tools not found or BUILD_COVERAGE is OFF. coverage target will not be available.")
endif()
