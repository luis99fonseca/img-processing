# img-processing

**Descrição**: Repositório para o desenvolvimento de estruturas, métodos e pequenos programas de manipulação de imagens, utilizando a linguagem de programação C.

Link do repositório privado no GitHub: [https://github.com/tiagocmendes/img-processing](https://github.com/tiagocmendes/img-processing)


## Estrutura

Todas as estruturas e métodos desenvolvidos para a manipulação de imagens estão presentes nos ficheiros **structs.h** e **structs.c**, na pasta **src**. Nesta pasta, também estão presentes os programas de teste, de nomenclatura *p-numero-do-programa.c*, bem como o respetivo ficheiro **Makefile** de compilação.

Na pasta **out**, irão estar presentes as imagens **.ppm** geradas a partir dos nossos programas de teste, após a sua execução.

Na pasta **img**, encontram-se as imagens que irão ser manipuladas.

Por fim, na pasta **doc**, encontra-se a documentação gerada automaticamente com o Doxygen.

## Compilar e executar

Para compilar e executar os diversos programas de teste, apenas terá de utilizar o ficheiro **Makefile**, presente na pasta **src**, como se ilustra nos seguintes exemplos:

**Compilar e executar o programa de testes no. 1:**

```console
$ make p1
./p1
```

**Compilar e executar o programa de testes no. 8:**

```console
$ make p8
./p8
```

## Autores - Grupo 1

* 89066 - Luís Carlos Duarte Fonseca
* 88886 - Tiago Carvalho Mendes