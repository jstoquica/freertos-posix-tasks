# tasks-FreeRTOS-Linux

## Resumo
O FreeRTOS é um simulador de kernel open source, usado para aplicações em tempo real. Esse projeto simula a criação de 4 tasks, que são equivalentes a threads. A função que executa a task 3 é utilizada para suspender a execução dela mesma. A função vTaskSuspend() é utilizada para fazer essa interrupção, para que as tasks voltem a rodar em loop se deve utilizar a função vTaskResume(), isso é o que ocorre dentro do loop for da task 2, nessa função há um contador i, o contador é iniciado em 0, e incrementa a cada vez que o a task 2 é executada pelo kernel. Quando o contador i chega em 2 a task 3 volta a ser eecutada por mais uma vez. Quando o contador i receber 6 como valor de variável será executada a task 4, que encerra o kernel.

## Compilando e executanto

***Pré requisitos***

- Ter o FreeRTOS instalado como uma variável de ambiente: <a href="https://www.freertos.org/a00104.html"> Download FreeRTOS</a>
    - para isso baixe o FreeRTOS com o link acima
    - coloque a pasta do FreeRTOS na home 
    - execute: 
    ```bash
       vim .profile
    ```
    - na última linha coloque o código a seguir: 
    ```bash
       export FREERTOS_PATH=~/FreeRTOSv202212.01
    ```
    - reinicie sua máquina
 
- ter o GCC instalado

**para compilar utilize o comando abaixo**

```bash
make
```

Ao fazer isso será gerada uma nova pasta chamada *build*. Dentro dessa pasta será gerado um arquivo chamado *modelo-posix-gcc*

**Para executar utilize**

```bash
./modelo-posix-gcc
```

### Autor
Jônatas Fernandes

#### Referência
```bash
https://youtu.be/wZmXPj1YvBg?si=-CDg9VBKjG4tUGgU
```
