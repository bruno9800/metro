# Nome do Projeto

Descrição do projeto.

## Configurando o Ambiente de Desenvolvimento

Siga as instruções abaixo para configurar o ambiente de desenvolvimento em sua máquina.

### Pré-requisitos

- Compilador C++ (como o g++)
- CMake
- Git

### Clonando o Repositório

1. Abra um terminal e navegue até o diretório onde você deseja clonar o projeto.
2. Execute o seguinte comando para clonar o repositório:

```sh
   git clone https://github.com/bruno9800/metro.git
   ```

### Compilando o Projeto

1. Navegue até o diretório raiz do projeto.
2. Crie um diretório de compilação executando o seguinte comando:
 ```sh
  mkdir build
  cd build
  ```
3. Configure o projeto com o CMake executando o seguinte comando:
```sh
  cmake ..
  ```
4. Compile o projeto executando o seguinte comando:
```sh
  cmake --build .
  ```
### Executando o Projeto

Após a compilação, você pode executar o projeto executando o seguinte comando:
```sh
  ./build/NomeDoExecutavel
  ```


### Agora é mão na massa

para atualizar o build basta executar o comando do item 4 da sessão ___compilando o projeto___


__Certifique-se de substituir "NomeDoExecutavel" pelo nome do executável gerado durante a compilação__