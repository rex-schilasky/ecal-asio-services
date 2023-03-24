#include "ecal_tcpclient.h"
#include "ecal_tcpserver.h"

#include <chrono>
#include <thread>
#include <iostream>

unsigned short g_port(0);

void run_server()
{
  eCAL::CTcpServer server;

  server.Create();
  server.Start();

  auto seconds2run(60);
  while (seconds2run--)
  {
    g_port = server.GetTcpPort();
    std::cout << "Server Port       : " << g_port << std::endl;
    std::cout << "Server IsConnected: " << server.IsConnected() << std::endl << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }

  server.Stop();
  server.Destroy();
}

void run_client()
{
  eCAL::CTcpClient client;

  client.Create("localhost", g_port);

  auto seconds2run(60);
  while (seconds2run--)
  {
    std::cout << "Client IsConnected: " << client.IsConnected() << std::endl << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }

  client.Destroy();
}

int main()
{
  std::thread server(run_server);
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));

  std::thread client(run_client);

  client.join();
  server.join();
  
  return 0;
}
