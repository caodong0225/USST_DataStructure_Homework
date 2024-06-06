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

# 添加测试
enable_testing()
add_test(NAME StackTest COMMAND Stack)
add_test(NAME QueueTest COMMAND Queue)
add_test(NAME SearchTest COMMAND Search)
add_test(NAME SortTest COMMAND Sort)
