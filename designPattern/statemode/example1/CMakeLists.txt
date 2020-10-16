cmake_minimum_required(VERSION 2.4)

project(StatePattern)
include_directories(${PROJECT_SOURCE_DIR})
add_executable(stateMachine
        StateMode/CClosingState.cpp
        StateMode/CContext.cpp  
        StateMode/CLifeState.cpp
        StateMode/COpenningState.cpp
        StateMode/CRunningState.cpp
        StateMode/CStoppingState.cpp
        StateMode/main.cpp)
