cmake_minimum_required(VERSION 3.30)

enable_testing()

project(brainfuck)

include(CTest)

set(SOURCES src/brainfuck.c src/queue.c src/stack.c src/stripe.c src/linked_list.c src/linked_list_aux.c)

add_executable(main src/main.c ${SOURCES})
add_executable(brainfuck_test tests/brainfuck_test.c ${SOURCES})
add_executable(queue_test tests/queue_test.c ${SOURCES})
add_executable(stack_test tests/stack_test.c ${SOURCES})
add_executable(stripe_test tests/stripe_test.c ${SOURCES})
add_executable(linked_list_test tests/linked_list_test.c ${SOURCES})
add_executable(linked_list_aux_test tests/linked_list_aux_test.c ${SOURCES})

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
add_test(NAME llist_append_i COMMAND linked_list_test llist_append_i)
add_test(NAME llist_prepend_i COMMAND linked_list_test llist_prepend_i)
add_test(NAME llist_append_c COMMAND linked_list_test llist_append_c)
add_test(NAME llist_prepend_c COMMAND linked_list_test llist_prepend_c)
add_test(NAME llist_value_i COMMAND linked_list_test llist_value_i)
add_test(NAME llist_value_c COMMAND linked_list_test llist_value_c)
add_test(NAME llist_set COMMAND linked_list_test llist_set)
add_test(NAME llist_set_i COMMAND linked_list_test llist_set_i)
add_test(NAME llist_set_c COMMAND linked_list_test llist_set_c)

# queue_test
add_test(NAME queue_create COMMAND queue_test queue_create)
add_test(NAME queue_free COMMAND queue_test queue_free)
add_test(NAME queue_empty COMMAND queue_test queue_empty)
add_test(NAME queue_enqueue COMMAND queue_test queue_enqueue)
add_test(NAME queue_dequeue COMMAND queue_test queue_dequeue)
add_test(NAME queue_push COMMAND queue_test queue_push)
add_test(NAME queue_eject COMMAND queue_test queue_eject)

# linked_list_aux_test
add_test(NAME llist_aux_append COMMAND linked_list_aux_test llist_aux_append)
add_test(NAME llist_aux_prepend COMMAND linked_list_aux_test llist_aux_prepend)
add_test(NAME llist_aux_remove_all COMMAND linked_list_aux_test llist_aux_remove_all)
add_test(NAME llist_aux_first COMMAND linked_list_aux_test llist_aux_first)
add_test(NAME llist_aux_last COMMAND linked_list_aux_test llist_aux_last)

add_test(NAME llist_aux_append_i COMMAND linked_list_aux_test llist_aux_append_i)
add_test(NAME llist_aux_prepend_i COMMAND linked_list_aux_test llist_aux_prepend_i)
add_test(NAME llist_aux_append_c COMMAND linked_list_aux_test llist_aux_append_c)
add_test(NAME llist_aux_prepend_c COMMAND linked_list_aux_test llist_aux_prepend_c)

# stripe_test
add_test(NAME stripe_create COMMAND stripe_test stripe_create)
add_test(NAME stripe_free COMMAND stripe_test stripe_free)
add_test(NAME stripe_cursor COMMAND stripe_test stripe_cursor)
add_test(NAME stripe_cursor_previous COMMAND stripe_test stripe_cursor_previous)
add_test(NAME stripe_cursor_next COMMAND stripe_test stripe_cursor_next)
add_test(NAME stripe_current COMMAND stripe_test stripe_current)
add_test(NAME stripe_current_set COMMAND stripe_test stripe_current_set)
add_test(NAME stripe_current_pred COMMAND stripe_test stripe_current_pred)
add_test(NAME stripe_current_succ COMMAND stripe_test stripe_current_succ)
add_test(NAME stripe_get_index COMMAND stripe_test stripe_get_index)

# brainfuck_test

add_test(NAME brainfuck_create COMMAND brainfuck_test brainfuck_create)
add_test(NAME brainfuck_free COMMAND brainfuck_test brainfuck_free)

add_test(NAME brainfuck_load_char COMMAND brainfuck_test brainfuck_load_char)
add_test(NAME brainfuck_load_string COMMAND brainfuck_test brainfuck_load_string)
add_test(NAME brainfuck_finished COMMAND brainfuck_test brainfuck_finished)
add_test(NAME brainfuck_iter COMMAND brainfuck_test brainfuck_iter)
add_test(NAME brainfuck_compute COMMAND brainfuck_test brainfuck_compute)
add_test(NAME brainfuck_get_index COMMAND brainfuck_test brainfuck_get_index)
add_test(NAME brainfuck_print COMMAND brainfuck_test brainfuck_print)
