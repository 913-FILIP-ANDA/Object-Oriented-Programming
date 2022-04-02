cmake_minimum_required(VERSION 3.17)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab4 main.cpp Domain/TrenchCoat.cpp Domain/TrenchCoat.h Repository/Repo.cpp Repository/Repo.h service/Service.cpp service/Service.h Ui/Ui.cpp Ui/Ui.h Vector/DynamicArray.cpp Vector/DynamicArray.h AppException.h Vector/DynamicArrayIterator.h Test/Test.cpp Test/Test.h)