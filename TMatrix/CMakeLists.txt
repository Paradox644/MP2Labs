file(GLOB srcs "*.cpp")

add_executable(${TMatrix} ${srcs} ${hdrs})
target_link_libraries(${TMatrix} ${TMatrixlib})