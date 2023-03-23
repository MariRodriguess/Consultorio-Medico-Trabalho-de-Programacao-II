# Consultório Médico
#### - Atividade realizada no 2º período para a disciplina de Programação de Computadores II.
#### - Curso de Engenharia da Computação - CEFET-MG, Campus V. 
#### - Programa feito na linguagem C++. 
#### - Instruções para a realização da atividade e resolução do problema se encontram nos dois arquivos pdf's disponibilizados dentro da pasta "Proposta e Resolução". <br><br>


## Compilação e Execução
Esse pequeno exemplo possui um arquivo Makefile que realiza todo o procedimento de compilação e execução.<br>Para tanto, temos as seguintes diretrizes de execução:

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação 