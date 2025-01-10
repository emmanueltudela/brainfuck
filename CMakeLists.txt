cmake_minimum_required(VERSION 3.30)

enable_testing()

project(brainfuck)

set(SOURCES src/brainfuck.c src/queue.c src/stack.c src/stripe.c)

add_executable(main src/main.c ${SOURCES})
add_executable(brainfuck_test tests/brainfuck_test.c ${SOURCES})
add_executable(queue_test tests/queue_test.c ${SOURCES})
add_executable(stack_test tests/stack_test.c ${SOURCES})
add_executable(stripe_test tests/stripe_test.c ${SOURCES})

add_compile_options(-std=c99 -Wall -g)
