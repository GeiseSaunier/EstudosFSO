**Geise Dioneia de Albuquerque Saunier - 190124318**

## T1: tradição de família

    O filho morre logo após o pai em decorrência da função raise, visto que o processo pai entra na condição (if) e morre quando a raise é invocada. Por definição, o filho passa a executar a partir de onde é criado, como foi criado a partir da condição (if), ele não entra na mesma e assim os comandos posteriores é que são executados, como a pause(). Logo, o filho finaliza em seguida.
    Como solução, poderia criar uma condição pause dentro de um while(1), como mostrado em exemplos de aulas anteriores, e mandar um sinal, permitindo agora que o filho receba o sinal do pai antes de morrer. Em contrapartida, se tiver outros filhos, eles também esperarão o sinal. 



## T2: A respeito de fork() e signal()

    Cenário 1: se o fork retonar -1, visto que quando isso acontece não há possibilidade de criar um filho, logo não há como acordar o pai. 

    Cenário 2: neste cenário pode ser que o pai morra antes de receber o sinal do filho, então o filho ficará orfão. 
