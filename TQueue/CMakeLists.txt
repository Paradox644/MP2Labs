file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${TQueue} ${srcs} ${hdrs})
target_link_libraries(${TQueue} ${TQueuelib})