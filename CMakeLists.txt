cmake_minimum_required(VERSION 3.28)
project(TradingExchange)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

include_directories(include)


add_library(pricing
        src/pricing/MarketPrice.cpp
)

#add_library(simulation
#        src/simulation/MarketSimulator.h
#)

#add_library(orderbook
#        src/orderbook/OrderBookSimulator.h
#)

add_library(events
        src/events/event_bus.cpp
)

add_library(transport
        src/transport/server.cpp
)


add_executable(market_data_service
        apps/market_data_service/main.cpp
)

target_link_libraries(market_data_service
        PRIVATE
        pricing
#        simulation
#        orderbook
        events
        transport
)


add_subdirectory(test)