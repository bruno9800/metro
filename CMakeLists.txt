cmake_minimum_required(VERSION 3.12)
project(metro)

# Definir a versão do C++
set(CMAKE_CXX_STANDARD 14)

# Adicionar os arquivos de origem do projeto
file(GLOB SOURCES "src/*.cpp")
add_executable(app ${SOURCES})

# Incluir os diretórios de cabeçalho
target_include_directories(app PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
