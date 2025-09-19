cmake_minimum_required(VERSION 3.30)
project(TradingExchange)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

include_directories(include)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS include/*.h)

add_subdirectory(test)

add_executable(TradingExchange main.cpp ${SOURCES}
        include/PriceGenerator.h
        include/Configuration.h
        include/MarkPrice.h
        src/MarketPrice.cpp
        include/MarketSimulator.h
        include/OrderBookSimulator.h
        include/Instrument.h)
