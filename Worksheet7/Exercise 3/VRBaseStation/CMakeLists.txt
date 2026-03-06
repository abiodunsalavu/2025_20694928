cmake_minimum_required(VERSION 3.19)
project(VRBaseStation LANGUAGES CXX)
find_package(VTK REQUIRED)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
set(CMAKE_AUTOMOC_ON)
set(CMAKE_AUTORCC ON)

qt_standard_project_setup()

qt_add_executable(VRBaseStation
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    ModelPart.h
    ModelPart.cpp
    ModelPartList.h
    ModelPartList.cpp
    icons.qrc
    optiondialog.h 
    optiondialog.cpp 
    optiondialog.ui
)

target_link_libraries(VRBaseStation
    PRIVATE
        Qt::Core
        Qt::Widgets
        ${VTK_LIBRARIES}
)

include(GNUInstallDirs)

install(TARGETS VRBaseStation
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET VRBaseStation
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
add_custom_target(vrbindings)
add_custom_command (TARGET vrbindings PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/vrbindings ${CMAKE_BINARY_DIR}/ )
