cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
cmake_policy(SET CMP0054 OLD)
cmake_policy(SET CMP0045 OLD)

project(ps C)
add_subdirectory(vendor/libft)

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}
  -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS_DEBUG}
  -fno-omit-frame-pointer -fsanitize=address")

file(GLOB_RECURSE ps_HDRS ${ps_HDRS} include/ps/*.h)

add_executable(checker ${ps_HDRS} include/ps.h
  src/checker.c
  src/op.c
  src/opti.c
  src/ps.c
  src/quicksort.c
  src/selectsort.c
  src/sort.c
  src/stack.c)
set_property(TARGET checker PROPERTY C_STANDARD 90)
target_include_directories(checker PUBLIC include)
target_link_libraries(checker PUBLIC debug ft)

target_compile_definitions(checker
  PRIVATE $<$<CONFIG:Debug>:DEBUG>$<$<CONFIG:Release>:NDEBUG>)
if (MSVC)
  target_compile_options(checker
    PRIVATE /MT$<$<CONFIG:Debug>:d> /Oy /W3
    PRIVATE /D_CRT_SECURE_NO_WARNINGS /Dinline=__inline
    PRIVATE /O$<$<CONFIG:Debug>:d>$<$<CONFIG:Release>:x>)
else ()
  target_compile_options(checker
    PRIVATE -Wall -Werror -Wextra
    PRIVATE -O$<$<CONFIG:Debug>:0 -g3>$<$<CONFIG:Release>:3>)
endif ()

add_executable(push_swap ${ps_HDRS} include/ps.h
  src/push_swap.c
  src/op.c
  src/opti.c
  src/ps.c
  src/quicksort.c
  src/selectsort.c
  src/sort.c
  src/stack.c)
set_property(TARGET push_swap PROPERTY C_STANDARD 90)
target_include_directories(push_swap PUBLIC include)
target_link_libraries(push_swap PUBLIC debug ft)

target_compile_definitions(push_swap
  PRIVATE $<$<CONFIG:Debug>:DEBUG>$<$<CONFIG:Release>:NDEBUG>)
if (MSVC)
  target_compile_options(push_swap
    PRIVATE /MT$<$<CONFIG:Debug>:d> /Oy /W3
    PRIVATE /D_CRT_SECURE_NO_WARNINGS /Dinline=__inline
    PRIVATE /O$<$<CONFIG:Debug>:d>$<$<CONFIG:Release>:x>)
else ()
  target_compile_options(push_swap
    PRIVATE -Wall -Werror -Wextra
    PRIVATE -O$<$<CONFIG:Debug>:0 -g3>$<$<CONFIG:Release>:3>)
endif ()

add_executable(visu ${ps_HDRS} include/ps.h
  src/visu.c
  src/draw.c
  src/op.c
  src/opti.c
  src/ps.c
  src/quicksort.c
  src/selectsort.c
  src/sort.c
  src/stack.c)
set_property(TARGET visu PROPERTY C_STANDARD 90)
target_include_directories(visu PUBLIC include)
target_link_libraries(visu PUBLIC debug ft ncurses)

target_compile_definitions(visu
  PRIVATE $<$<CONFIG:Debug>:DEBUG>$<$<CONFIG:Release>:NDEBUG>)
if (MSVC)
  target_compile_options(visu
    PRIVATE /MT$<$<CONFIG:Debug>:d> /Oy /W3
    PRIVATE /D_CRT_SECURE_NO_WARNINGS /Dinline=__inline
    PRIVATE /O$<$<CONFIG:Debug>:d>$<$<CONFIG:Release>:x>)
else ()
  target_compile_options(visu
    PRIVATE -Wall -Werror -Wextra
    PRIVATE -O$<$<CONFIG:Debug>:0 -g3>$<$<CONFIG:Release>:3>)
endif ()
