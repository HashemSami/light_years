add_executable(
  ${LIGHT_YEARS_GAME_TARGET_NAME}

  ${CMAKE_CURRENT_SOURCE_DIR}/src/entry_point.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/game_application.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/game_application.cpp
)


# add include folder to ba able to access header files using include command
target_include_directories(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC ${LIGHT_YEARS_ENGINE_TARGET_NAME})

# creating a function that will copy the required dll files form SFML source files to work on windows machines
function(CopyLibDirToTarget LIB_NAME TARGET_NAME)
  add_custom_command(
    TARGET ${TARGET_NAME}
    POST_BUILD
    COMMAND
    ${CMAKE_COMMAND} -E copy_directory
    $<TARGET_FILE_DIR:${LIB_NAME}>
    $<TARGET_FILE_DIR:${TARGET_NAME}>
  )
endfunction()

CopyLibDirToTarget( ${LIGHT_YEARS_ENGINE_TARGET_NAME} ${LIGHT_YEARS_GAME_TARGET_NAME})
