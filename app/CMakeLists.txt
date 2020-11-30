cmake_minimum_required(VERSION 3.0)
project(app)

set(Boost_NO_SYSTEM_PATHS TRUE)
set(Boost_USE_STATIC_LIBS TRUE)
set(BOOST_ROOT "C:/Code Projects/Cpp Libraries/boost_1_74_0")

find_package(Boost REQUIRED COMPONENTS system filesystem)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})

    add_executable(${PROJECT_NAME} 
        "src/main.cpp"

        "src/time_slot_playground.cpp"
        "include/time_slot_playground.h"

        "src/smart_pointers_playground.cpp"
        "include/smart_pointers_playground.h"

        "src/multiplication_table_playground.cpp"
        "include/multiplication_table_playground.h"

        "include/printlib.h"
        "include/tuplelib.h")

    target_include_directories( ${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/include
    )
   
    target_link_libraries(${PROJECT_NAME} 
        ${Boost_LIBRARIES}
	    time_slot
        multiplication_table
        lookup_table
    )
endif()