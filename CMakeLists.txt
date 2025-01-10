cmake_minimum_required(VERSION 3.30)

enable_testing()

project(brainfuck)

set(SOURCES src/brainfuck.c src/queue.c src/stack.c src/stripe.c)

add_executable(main src/main.c ${SOURCES})
add_executable(brainfuck_test tests/brainfuck_test.c ${SOURCES})
add_executable(queue_test tests/queue_test.c ${SOURCES})
add_executable(stack_test tests/stack_test.c ${SOURCES})
add_executable(stripe_test tests/stripe_test.c ${SOURCES})
add_executable(linked_list_test tests/linked_list_test.c ${SOURCES})

add_compile_options(-std=c99 -Wall -g)
include_directories(include)

# stack_test
add_test(NAME stack_create COMMAND stack_test stack_create)
add_test(NAME stack_free COMMAND stack_test stack_free)
add_test(NAME stack_empty COMMAND stack_test stack_empty)
add_test(NAME stack_push COMMAND stack_test stack_push)
add_test(NAME stack_pop COMMAND stack_test stack_pop)

# linked_list_test
add_test(NAME llist_create COMMAND linked_list_test llist_create)
add_test(NAME llist_free COMMAND linked_list_test llist_free)
add_test(NAME llist_empty COMMAND linked_list_test llist_empty)
add_test(NAME llist_previous COMMAND linked_list_test llist_previous)
add_test(NAME llist_next COMMAND linked_list_test llist_next)
add_test(NAME llist_append COMMAND linked_list_test llist_append)
add_test(NAME llist_prepend COMMAND linked_list_test llist_prepend)
add_test(NAME llist_value COMMAND linked_list_test llist_value)
add_test(NAME llist_remove COMMAND linked_list_test llist_remove)
