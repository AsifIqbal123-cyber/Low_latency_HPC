#include "../include/FeedReceiver.h"
#include <iostream>
#include <boost/system/error_code.hpp>
#include "../include/Types.h"
#include "Utils.cpp"
namespace asio = boost::asio;
using udp = asio::ip::udp;

using namespace std;

FeedReceiver::FeedReceiver(asio::io_context& io, short port)
    : socket_(io, udp::endpoint(udp::v4(), port)) {}

void FeedReceiver::start(){
    receive();
}

void FeedReceiver::receive(){
    cout<<"Waiting for UDP packet..."<<endl;
    socket_.async_receive_from(
        asio::buffer(buffer_), sender_endpoint_,
        [this](const boost::system::error_code& ec, size_t bytes_recv){
            if(!ec && bytes_recv>0){
                handle_packet(buffer_.data(), bytes_recv);
            }
         receive();
        }
    );

}


void FeedReceiver::handle_packet(const char* data, size_t length ){
    if (length<sizeof(TradeMessage)){
        cerr<<"Incomplete trade"<<endl;
        return;
    }

    Timer timer;
    TradeMessage msg;

    memcpy(&msg,data,sizeof(TradeMessage));

    cout<<"Trade received: "<< string(msg.symbol)
        << " $"<<msg.price<<" x "<< msg.size
        << " side: "<<msg.side<<endl;


    double elapsed = timer.eleapsed_microseconds();

    cout<<"LATENCY: Packet processed in "<<elapsed<<" us\n"<<endl;
    cout<< "-----------------------------------\n"; 

    // cout<<"Received " <<length<< " bytes: ";
    // for(int i=0; i<length;i++){
    //     printf("%02X", static_cast<unsigned>(data[i]));
    // }

    // cout<<"\n"<<endl;
}