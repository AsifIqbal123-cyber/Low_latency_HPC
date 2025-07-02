#pragma once
#include <cstdint>
#include <cstring>
using namespace std;

#pragma pack(push,1)

struct TradeMessage {
    uint64_t timestamp; // The number is large because we are calculating in nanoseconds.
    char symbol[8];
    double price;
    uint32_t size;
    char side;

    // I made sure that the trademesage doesnt contain any complex members such string or vector.
    // It will cause damages. 
    TradeMessage(){
        memset(this,0, sizeof(TradeMessage));
    }
};
#pragma pack(pop)

