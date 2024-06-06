cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(DataStructure C)

# 指定编译选项
set(CMAKE_C_STANDARD 11)

# 添加源文件
add_executable(LinkedList ex1/LinkedList.c)
add_executable(SingleLinkedList ex2/SingleLinkedList.c)
add_executable(Stack ex3/stack.c)
add_executable(Queue ex4/queue.c)
add_executable(Search ex7/search.c)
add_executable(Sort ex8/sort.c)

add_executable(run_tests test/run_tests.c)
# 创建自定义目标来构建所有可执行文件
add_custom_target(build_all
    DEPENDS LinkedList SingleLinkedList Stack Queue Search Sort
)
# 添加测试
enable_testing()
add_test(NAME LinkedListTest COMMAND run_tests LinkedList)
add_test(NAME SingleLinkedListTest COMMAND run_tests SingleLinkedList)
add_test(NAME StackTest COMMAND run_tests Stack)
add_test(NAME QueueTest COMMAND run_tests Queue)
add_test(NAME SearchTest COMMAND run_tests Search)
add_test(NAME SortTest COMMAND run_tests Sort)
