file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${TStack} ${srcs} ${hdrs})
target_link_libraries(${TStack} ${TStacklib})