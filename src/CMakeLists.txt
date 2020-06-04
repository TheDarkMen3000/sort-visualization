set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sort
    list.hpp
    list.cpp     
    main.cpp
    matrix.hpp
    matrix.cpp
    rect.hpp
    rect.cpp
    renderer.hpp
    renderer.cpp
    shaderprogram.hpp
    shaderprogram.cpp
    sortengine.hpp
    sortengine.cpp
    window.hpp
    window.cpp
)

target_link_libraries(sort PRIVATE libglew_static glfw sol2::sol2 liblua)