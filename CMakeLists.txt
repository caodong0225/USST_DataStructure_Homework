cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(DataStructure)

# 指定编译选项
set(CMAKE_C_STANDARD 11)

# 添加源文件
set(SOURCES
    ex1/LinkedList.c
    ex2/SingleLinkedList.c
    ex3/stack.c
    ex4/queue.c
    ex7/search.c
    ex8/sort.c
)

# 添加头文件目录
# include_directories(include)

# 添加可执行文件
add_executable(DataStructure ${SOURCES})

# 添加测试
enable_testing()
add_test(NAME MyTest COMMAND DataStructure)