
set(CMAKE_PREFIX_PATH "/Users/michaelamaya/Qt/6.5.1/macos")
set(TARGET "test_WASM")

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(PostgreSQL REQUIRED)
qt_standard_project_setup()

file(GLOB includes_h CONFIGURE_DEPENDS "../include/*.h")

qt_add_executable(${TARGET}
    ../core.cpp
    main_window.cpp
    config_reader.cpp
    clothe_classifiers.cpp
    database_postgres.cpp
    ${includes_h}
)

target_link_libraries(${TARGET} PRIVATE Qt6::Widgets)
target_link_libraries(${TARGET} PRIVATE PostgreSQL::PostgreSQL)


set_target_properties(${TARGET} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)