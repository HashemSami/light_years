add_library(
  ${LIGHT_YEARS_ENGINE_TARGET_NAME} STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/application.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/application.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/include/entry_point.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/entry_point.cpp
)

# add include folder to ba able to access header files using include command
target_include_directories(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC SFML::Graphics)

# creating a function that will copy the required dll files form SFML source files to work on windows machines
function(CopyLibToTarget LIB_NAME TARGET_NAME)
  add_custom_command(
    TARGET ${TARGET_NAME}
    POST_BUILD
    COMMAND
    ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:${LIB_NAME}>
    $<TARGET_FILE_DIR:${TARGET_NAME}>
  )
endfunction()

CopyLibToTarget(sfml-window ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-graphics ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-system ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-audio ${LIGHT_YEARS_ENGINE_TARGET_NAME})