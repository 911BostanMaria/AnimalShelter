cmake_minimum_required(VERSION 3.20)
project(animalshelter)

set(CMAKE_CXX_STANDARD 14)


add_executable(animalshelter main.cpp Shelter.cpp Shelter.h DynamicVector.h Repository.cpp Repository.h
        User.cpp User.h Service.cpp Service.h Validator.cpp Validator.h UserInterface.cpp
        UserInterface.h tests.h tests.cpp RepositoryHTML.cpp RepositoryHTML.h RepositoryCSV.cpp RepositoryCSV.h)
