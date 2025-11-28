cmake_minimum_required(VERSION 3.21)

project(Viewer3D
  VERSION 2.0.0
  LANGUAGES CXX
  DESCRIPTION "3D Viewer Application"
)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  add_compile_options(
    -Wall 
    -Wextra 
    -Wpedantic 
    -Werror 
    -g 
    -D_POSIX_C_SOURCE=201706L)
endif()


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets OpenGLWidgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets OpenGLWidgets)
find_package(OpenGL REQUIRED)

set(INCLUDE_DIRS
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/controller
  ${CMAKE_CURRENT_SOURCE_DIR}/core
  ${CMAKE_CURRENT_SOURCE_DIR}/core/math
  ${CMAKE_CURRENT_SOURCE_DIR}/core/service
  ${CMAKE_CURRENT_SOURCE_DIR}/core/parameters
  ${CMAKE_CURRENT_SOURCE_DIR}/model
  ${CMAKE_CURRENT_SOURCE_DIR}/model/model3d
  ${CMAKE_CURRENT_SOURCE_DIR}/model/model3d/elements
  ${CMAKE_CURRENT_SOURCE_DIR}/model/parser
  ${CMAKE_CURRENT_SOURCE_DIR}/model/parser/parser_src
  ${CMAKE_CURRENT_SOURCE_DIR}/model/parser/service_functions
  ${CMAKE_CURRENT_SOURCE_DIR}/view/render
  ${CMAKE_CURRENT_SOURCE_DIR}/view/render/render_src
  ${CMAKE_CURRENT_SOURCE_DIR}/view/render/uniforms
  ${CMAKE_CURRENT_SOURCE_DIR}/view
  ${CMAKE_CURRENT_SOURCE_DIR}/view/gui
  ${CMAKE_CURRENT_SOURCE_DIR}/view/gui/controls
  ${CMAKE_CURRENT_SOURCE_DIR}/view/gui/controls/elements
  ${CMAKE_CURRENT_SOURCE_DIR}/view/gui/model_viewer
  ${CMAKE_CURRENT_SOURCE_DIR}/view/gui/model_viewer/model_viewer_src
  ${CMAKE_CURRENT_SOURCE_DIR}/view/gui/mainwindow
  ${CMAKE_CURRENT_SOURCE_DIR}/view/gui/capture
)
set(SOURCES
  controller/model_parser_worker.cpp
  core/math/matrix4x4.cpp
  core/math/vec3.cpp
  core/math/vec4.cpp
  core/service/service.cpp
  core/parameters/view_parameters.cpp
  model/model3d/model3d.cpp
  model/model3d/elements/vertices.cpp
  model/model3d/elements/edges.cpp
  model/model3d/elements/axisbounds.cpp
  model/parser/parser_src/parser.cpp
  model/parser/parser_src/model_alterers.cpp
  model/parser/parser_src/prefix_handlers.cpp
  model/parser/parser_src/model_parser.cpp
  model/parser/service_functions/service_functions.cpp
  view/render/render_src/gpu_model.cpp
  view/render/render_src/shader_program.cpp
  view/render/uniforms/uniforms.cpp
  view/gui/model_viewer/model_viewer_src/model_viewer.cpp
  view/gui/model_viewer/model_viewer_src/mouse_actions.cpp
  view/gui/controls/elements/slider.cpp
  view/gui/controls/model_settings.cpp
  view/gui/mainwindow/mainwindow.cpp
  view/gui/mainwindow/mainwindow.ui
  main.cpp
  view/gui/capture/capture_src/capturer.tpp
  view/gui/capture/capture_src/screenshot_maker.cpp
  view/gui/capture/capture_src/gif_maker.cpp
)
set(HEADERS
  controller/model_parser_worker.h
  controller/render_controller.h
  core/math/basis.h
  core/math/matrix4x4.h
  core/math/vec2.h
  core/math/vec3.h
  core/math/vec4.h
  core/service/service.h
  core/parameters/view_parameters.h
  model/model3d/model3d.h
  model/model3d/elements/mesh.h
  model/model3d/elements/axisbounds.h
  model/parser/parser.h
  model/parser/model_parser.h
  model/parser/service_functions/service_functions.h
  view/render/gpu_model.h
  view/render/shader_program.h
  view/render/uniforms/uniforms.h
  view/gui/model_viewer/model_viewer.h
  view/gui/model_viewer/mouse_actions.h
  view/gui/controls/model_controls.h
  view/gui/controls/model_settings.h
  view/gui/controls/elements/slider.h
  view/gui/mainwindow/mainwindow.h
  third_party/gif.h
  view/gui/capture/capturer.h
  view/gui/capture/screenshot_maker.h
  view/gui/capture/gif_maker.h
)

set(SHADER_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/view/render/shaders/shader.frag
  ${CMAKE_CURRENT_SOURCE_DIR}/view/render/shaders/shader.vert
)

set(MATRIX_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/third_party/matrix/matrix.cpp
)
set(MATRIX_HEADERS
  ${CMAKE_CURRENT_SOURCE_DIR}/third_party/matrix/matrix_exceptions.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/third_party/matrix/matrix_service.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/third_party/matrix/matrix.hpp
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third_party)

# Main executable block    ------------------------------------------------------------------------
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)

    add_executable(Viewer3D
        ${SOURCES}
        ${HEADERS}
    )
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/view/render/shaders
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../materials/models
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
endif()

add_custom_target(run_Viewer3D
    COMMAND Viewer3D
    DEPENDS Viewer3D
    COMMENT "Running Viewer3D executable"
)

target_include_directories(Viewer3D PUBLIC
    ${INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/matrix
)

target_link_libraries(Viewer3D PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::OpenGLWidgets
    OpenGL::GLU
    OpenGL::GL
    matrix
)
# Extra block    ----------------------------------------------------------------------------------
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES
  ${HEADERS}
  ${SOURCES}
)

# Tests block (tests and coverage coals are defined in tests/CMakeList.txt)   ---------------------
enable_testing()
add_subdirectory(tests)


# Clang-format block    ---------------------------------------------------------------------------
find_program(CLANG_FORMAT_EXE
    NAMES clang-format clang-format-20 clang-format-14 clang-format-13
    DOC "Path to clang-format executable"
)

if(CLANG_FORMAT_EXE)
    find_file(CLANG_FILE 
        ${CMAKE_CURRENT_SOURCE_DIR}/../.clang-format
        ${CMAKE_CURRENT_SOURCE_DIR}/.clang-format
        )

    set(PROJECT_CHECKABLE_FILES
        ${HEADERS}
        ${SOURCES}
        # ${SHADER_FILES}
        ${MATRIX_SOURCES}
        ${MATRIX_HEADERS}
    )
    set(ALL_SOURCE_FILES
        ${PROJECT_CHECKABLE_FILES}
        ${CMAKE_CURRENT_SOURCE_DIR}/../*/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../*/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../*/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../*/*/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../*/*/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../*/*/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../*/*/*/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../*/*/*/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../*/*/*/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../*/*/*/*/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../*/*/*/*/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../*/*/*/*/*.hpp
    )

    file(GLOB_RECURSE ALL_CHECKABLE_FILES
        LIST_DIRECTORIES false
        ${ALL_SOURCE_FILES}
    )

    list(FILTER ALL_CHECKABLE_FILES EXCLUDE REGEX ".*/build/.*")

    add_custom_target(show_all_source_files
        COMMAND ${CMAKE_COMMAND} -E echo "${ALL_CHECKABLE_FILES}"
    )

    if(ALL_CHECKABLE_FILES)
        if(CLANG_FILE)
            add_custom_target(style_check_all
                COMMAND ${CLANG_FORMAT_EXE}
                    --style=file:${CLANG_FILE}
                    -n
                    ${ALL_CHECKABLE_FILES}
                COMMENT "Checking Google code style..."
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                VERBATIM
            )
            add_custom_target(style_make_all
                COMMAND ${CLANG_FORMAT_EXE}
                    --style=file:${CLANG_FILE}
                    -i
                    ${ALL_CHECKABLE_FILES}
                COMMENT "Fixing files' style according to Google style..."
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                VERBATIM
            )
        else()
            add_custom_target(style_check_all
                COMMAND ${CLANG_FORMAT_EXE}
                    --style=Google
                    -n
                    ${ALL_CHECKABLE_FILES}
                COMMENT "Checking Google code style..."
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                VERBATIM
            )
            add_custom_target(style_make_all
                COMMAND ${CLANG_FORMAT_EXE}
                    --style=Google
                    -i
                    ${ALL_CHECKABLE_FILES}
                COMMENT "Fixing files' style according to Google style..."
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                VERBATIM
            )
        endif()
    else()
        message(WARNING "No source files found for code style checking!")
    endif()
    if(PROJECT_CHECKABLE_FILES)
        if(CLANG_FILE)
            add_custom_target(style_check_project
                COMMAND ${CLANG_FORMAT_EXE}
                    --style=file:${CLANG_FILE}
                    -n
                    ${PROJECT_CHECKABLE_FILES}
                COMMENT "Checking Google code style..."
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                VERBATIM
            )
            add_custom_target(style_make_project
                COMMAND ${CLANG_FORMAT_EXE}
                    --style=file:${CLANG_FILE}
                    -i
                    ${PROJECT_CHECKABLE_FILES}
                COMMENT "Fixing files' style according to Google style..."
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                VERBATIM
            )
        else()
            add_custom_target(style_check_project
                COMMAND ${CLANG_FORMAT_EXE}
                    --style=Google
                    -n
                    ${PROJECT_CHECKABLE_FILES}
                COMMENT "Checking Google code style..."
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                VERBATIM
            )
            add_custom_target(style_make_project
                COMMAND ${CLANG_FORMAT_EXE}
                    --style=Google
                    -i
                    ${PROJECT_CHECKABLE_FILES}
                COMMENT "Fixing files' style according to Google style..."
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                VERBATIM
            )
        endif()
    endif()
else()
    message(WARNING "clang-format not found! Code style targets unavailable.")
endif()

# Install block    --------------------------------------------------------------------------------
# This is system-style install, it's fine, but too complex for this project
    # install(TARGETS Viewer3D
    #     EXPORT Viewer3DTargets
    #     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    #     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    #     ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    # )
    # install(DIRECTORY core/
    #     DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/core
    #     FILES_MATCHING PATTERN "*.h"
    # )

    # install(EXPORT Viewer3DTargets
    #     FILE Viewer3DTargets.cmake
    #     DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Viewer3D
    # )

# Self-made installation
# Default installation prefix is the build dir
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}" CACHE PATH "Install path prefix" FORCE)
endif()

install(TARGETS Viewer3D
    RUNTIME DESTINATION Viewer_3D
    COMPONENT Viewer3D
)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../materials/models
    DESTINATION Viewer_3D
    COMPONENT Viewer3D
)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/view/render/shaders
    DESTINATION Viewer_3D
    COMPONENT Viewer3D
)

# Custom install target that does not depend on "all"
# Choose location with th following way: PREFIX=/someting/folder make install_Viewer3D 
add_custom_target(install_Viewer3D
    COMMAND ${CMAKE_COMMAND} -DCMAKE_INSTALL_COMPONENT=Viewer3D
                             "-DCMAKE_INSTALL_PREFIX=$ENV{PREFIX}"
                             -P ${CMAKE_BINARY_DIR}/cmake_install.cmake
    DEPENDS Viewer3D
    COMMENT "Installing only Viewer3D and its resources"
)

# Uninstall block    ------------------------------------------------------------------------------
# Use PREFIX if provided, otherwise default to CMAKE_INSTALL_PREFIX
add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_BINARY_DIR}/Viewer_3D"
    COMMENT "Removing Viewer3D from build folder"
)


# Documentation block    --------------------------------------------------------------------------
find_package(Doxygen QUIET)
set(DOXYGEN_PROJECT_NUMBER "2.0.0")
set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/../materials/Doxyfile)
set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/project_docs)

if(DOXYGEN_FOUND AND EXISTS ${DOXYGEN_IN})
    add_custom_target(dvi
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_IN}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../materials
        COMMENT "Generating API documentation with Doxygen (output -> ${DOXYGEN_OUT})"
        VERBATIM
    )
else()
    add_custom_target(dvi
    COMMAND ${CMAKE_COMMAND} -E echo "Doxygen not found or ${DOXYGEN_IN} missing. Install Doxygen or place a Doxyfile in ../materials to enable 'dvi' target."
)
endif()

# Distribution block    ---------------------------------------------------------------------------
find_program(TAR_EXECUTABLE tar)

if(TAR_EXECUTABLE)
    add_custom_target(dist
        COMMAND ${TAR_EXECUTABLE} -czf ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-${PROJECT_VERSION}.tar.gz -C ${CMAKE_CURRENT_SOURCE_DIR}/.. src materials README.md 
        COMMENT "Creating source archive using system tar"
    )
else()
    add_custom_target(dist
        COMMAND ${CMAKE_COMMAND} -E echo "Neither git nor tar found; cannot create source archive from ${CMAKE_CURRENT_SOURCE_DIR}/.."
    )   
endif()