#pragma once 
#include <boost/asio.hpp>
#include <array>
using namespace std;
class FeedReceiver {
    public:
    FeedReceiver(boost::asio::io_context& io_context, short port);

    void start();

    private:

    void receive();

    void handle_packet(const char* data, size_t length );

    boost::asio::ip::udp::socket socket_;

    boost::asio::ip::udp::endpoint sender_endpoint_;

    std::array<char, 2048> buffer_;
};