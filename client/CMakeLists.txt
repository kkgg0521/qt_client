cmake_minimum_required(VERSION 3.14)

project(Client LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)



add_library(Client
            include/Client.h
            include/Connection.h
            src/Client.cpp
        src/Connection.cpp include/COMType.h
        include/tpsending.h
        src/tpsending.cpp
        include/SafeQueue.h
        src/sendQueue.cpp
        include/sendQueue.h
        src/recvQueue.cpp
        include/recvQueue.h
        src/tprecving.cpp
        include/tprecving.h
        src/recvThread.cpp
        include/recvThread.h
)

target_include_directories(Client PUBLIC include)
target_link_libraries(Client Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network)

install(TARGETS Client
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
