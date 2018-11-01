cmake_minimum_required(VERSION 2.8)

project( FastMetrics  )

include_directories(src/)
file(GLOB SOURCES "src/*.cpp" 
            "src/app/application/*.cpp" 
            "src/app/estimation/impl/*.cpp" 
            "src/app/io/impl/*.cpp" 
            "src/app/toolkit/impl/*.cpp"
            )

add_executable( FastMetrics ${SOURCES} )
