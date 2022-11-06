cmake_minimum_required(VERSION 3.23)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled2 main.cpp
        Estudante.cpp
        Slot.cpp
        TTM.cpp
        UcTurma.cpp
        BaseMenu.cpp
        ListingMenu.cpp
        ChangeMenu.cpp
        PedidoAdd.cpp
        PedidoChange.cpp
        PedidoRemove.cpp
        Estudante.h
        Slot.h
        TTM.h
        UcTurma.h
        BaseMenu.h
        ListingMenu.h
        ChangeMenu.h
        PedidoAdd.h
        PedidoChange.h
        PedidoRemove.h)
