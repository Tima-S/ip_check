function(custom_add_executable_from_dir TARGET TARGET_SRC_DIR)
    file(GLOB TARGET_SRC "${TARGET_SRC_DIR}/*.cpp")
    add_executable(${TARGET} ${TARGET_SRC})
endfunction()
