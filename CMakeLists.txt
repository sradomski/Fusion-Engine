cmake_minimum_required(VERSION 2.8)
project(MMF)

file(GLOB_RECURSE MMF_FILES ${PROJECT_SOURCE_DIR}/MultimodalFusion/*.cpp ${PROJECT_SOURCE_DIR}/MultimodalFusion/*.h)

add_library(mmf ${MMF_FILES})