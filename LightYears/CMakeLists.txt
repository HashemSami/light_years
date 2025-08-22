add_executable(
  ${LIGHT_YEARS_GAME_TARGET_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC SFML::Graphics)

# copy the required dll files form SFML source files to work on windows machines
add_custom_command(
  TARGET ${LIGHT_YEARS_GAME_TARGET_NAME}
  POST_BUILD
  COMMAND
  ${CMAKE_COMMAND} -E copy_if_different
  $<TARGET_FILE:sfml-window>
  $<TARGET_FILE_DIR:${LIGHT_YEARS_GAME_TARGET_NAME}>
)