file(GLOB srcs "*.cpp")

add_executable(${Postfix} ${srcs} ${hdrs})
target_link_libraries(${Postfix} ${Postfixlib})