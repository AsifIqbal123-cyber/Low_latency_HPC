#include <boost/asio.hpp>
#include "../include/FeedReceiver.h"
#include <iostream>
using namespace std;
namespace asio = boost::asio;
int main(){
    boost::asio::io_context io;
    
    FeedReceiver receiver(io, 9000);
    
    cout<< "Server started. Waiting for client ..."<<endl;

    receiver.start();

    io.run();

    
    return 0;
}