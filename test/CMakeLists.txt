project(ecal_asio_services_test)

add_executable(ecal_asio_services_test)
target_sources(ecal_asio_services_test
  PRIVATE
    main.cpp
    src/asio_server.h
    src/ecal_tcpclient.cpp
    src/ecal_tcpclient.h
    src/ecal_tcpheader.h
    src/ecal_tcpserver.cpp
    src/ecal_tcpserver.h
)

target_include_directories(${PROJECT_NAME}
  PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

target_link_libraries(ecal_asio_services_test PRIVATE asio::asio)
