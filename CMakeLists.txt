cmake_minimum_required(VERSION 4.0)
project(Mini_Database_System C)

set(CMAKE_C_STANDARD 23)

add_executable(Mini_Database_System main.c
        database.c
        utils.c
        include/database.h
        include/utils.h
        include/mahasiswa.h
)
