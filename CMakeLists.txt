# CMake 최소 요구 버전 설정
cmake_minimum_required(VERSION 3.17)

# 프로젝트 이름 설정
project(QtVTKProject)

#======================= Qt 포함 =======================#
# 현재 디렉토리를 포함
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# MOC (Meta-Object Compiler)를 자동으로 실행
set(CMAKE_AUTOMOC ON)
# UI 파일 자동 생성
set(CMAKE_AUTOUIC ON)
# 환경 변수 QTDIR에서 Qt의 프리픽스 경로 찾기
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
# 필요한 Qt 모듈 찾기
find_package(OpenGL)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt5Xml REQUIRED)
find_package(Qt5Widgets REQUIRED)

#======================= VTK 포함 ======================#
# 환경 변수 VTK_DIR에서 VTK의 프리픽스 경로 찾기
set(VTK_DIR $ENV{VTK_DIR})
# 필요한 VTK 모듈 찾기
find_package(VTK REQUIRED)
# VTK 사용 파일 포함
include(${VTK_USE_FILE})

#======================= 코드 포함 ======================#
# 각 디렉토리 경로 설정
set(FORMS_DIR "${CMAKE_SOURCE_DIR}/forms")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

# 디렉토리를 인클루드 디렉토리로 추가
include_directories(${FORMS_DIR})
include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

# 파일 목록 생성
file(GLOB_RECURSE SOURCES
    "${FORMS_DIR}/*.ui"
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)

# AUTOUIC 검색 경로에 forms 디렉토리 추가
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

# 실행 파일 추가
if (WIN32) 
    add_executable(QtVTKProject WIN32 ${SOURCES})
elseif(UNIX)
    add_executable(QtVTKProject ${SOURCES})
endif()

# 타겟에 인클루드 디렉토리 추가
target_include_directories(QtVTKProject PRIVATE ${FORMS_DIR})
target_include_directories(QtVTKProject PRIVATE ${INCLUDE_DIR})
target_include_directories(QtVTKProject PRIVATE ${SOURCE_DIR})

#===================== 라이브러리 링크 =======================#
# Qt 모듈 및 외부 라이브러리 링크
target_link_libraries(QtVTKProject Qt5::OpenGL)
target_link_libraries(QtVTKProject Qt5::Xml)
target_link_libraries(QtVTKProject Qt5::Widgets)
target_link_libraries(QtVTKProject ${QT_LIBRARIES} ${OPENGL_LIBRARIES})
target_link_libraries(QtVTKProject ${VTK_LIBRARIES})
)