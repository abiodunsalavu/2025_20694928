cmake_minimum_required(VERSION 3.19)
project(Worksheet_6 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(Worksheet_6
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

target_link_libraries(Worksheet_6
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS Worksheet_6
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Worksheet_6
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
