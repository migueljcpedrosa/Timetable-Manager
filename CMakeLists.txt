cmake_minimum_required(VERSION 3.23)
project(ttm_vf_aed)

set(CMAKE_CXX_STANDARD 14)

add_executable(ttm_vf_aed main.cpp
        Estudante.cpp
        Slot.cpp
        TTM.cpp
        UcTurma.cpp
        BaseMenu.cpp
        ListingMenu.cpp
        ChangeMenu.cpp
        Pedido.cpp
        Estudante.h
        Slot.h
        TTM.h
        UcTurma.h
        BaseMenu.h
        ListingMenu.h
        ChangeMenu.h
        Pedido.h
        )
