cmake_minimum_required(VERSION 3.23)
project(gptTraiding)

set(CMAKE_CXX_STANDARD 20)

add_executable(gptTraiding main.cpp StrategyTester.h StrategyTester.cpp MovingAverageStrategy.cpp MovingAverageStrategy.h Visualizer.cpp Visualizer.h BinanceAPI.cpp BinanceAPI.h TradingStrategy.cpp TradingStrategy.h Trade.h)
