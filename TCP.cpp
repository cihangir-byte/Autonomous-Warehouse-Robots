#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main() {
  try {
    boost::asio::io_service io_service;

    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 12345));

    for (;;) {
      tcp::socket socket(io_service);
      acceptor.accept(socket);

      std::string message = "Hello, client!";

      boost::system::error_code ignored_error;
      boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
    }
  }
  catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
