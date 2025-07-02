#include <iostream>
#include <cstring>
#include <boost/asio.hpp>
#include "../include/MessageParser.h"
#include "../include/Types.h"
using namespace std;
namespace asio=boost::asio;

int main(){
    
    
    try{
        
        asio::io_context io;
        asio::ip::udp::socket socket(io);
        socket.open(asio::ip::udp::v4());

        //Destination (port: 9000)
        asio::ip::udp::endpoint receiver_endpoint(
        asio::ip::address::from_string("127.0.0.1"),9000);

        //Temporary trademessage

        TradeMessage msg;
        msg.timestamp = 1234567889000;
        strncpy(msg.symbol,"AAPL",8);
        msg.price = 198.75;
        msg.size = 200;
        msg.side = 'B';

        socket.send_to(boost::asio::buffer(&msg,sizeof(msg)),receiver_endpoint);
        cout<<"TradeMessage sent!"<<endl;


    } catch (exception& e){
        cerr<< "Sender Error: "<<e.what()<<endl;
    }

    return 0;
}