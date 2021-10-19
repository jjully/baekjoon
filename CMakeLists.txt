# cmake -DCMAKE_BUILD_TYPE:STRING=Release -G "Unix Makefiles"
# cmake -LAH

# 요구 CMake 최소 버전
cmake_minimum_required(VERSION 2.8)

# 프로젝트 이름
project("utils")

# 빌드 대상 바이너리 파일명 및 소스 파일 목록
set(C_FILES
    #write down all file names
    5373.cpp
    )

# 출력 디렉토리
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../exefolder)

# 빌드 대상 바이너리 추가
add_executable(Helloo ${C_FILES})