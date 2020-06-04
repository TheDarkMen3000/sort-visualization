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
    window.hpp
    window.cpp
)

target_link_libraries(sort PRIVATE libglew_static glfw)