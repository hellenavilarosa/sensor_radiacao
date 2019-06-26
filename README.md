# Desenvolvimento de um sensor de radiação solar de baixo custo para aplicações em placas fotovoltaicas

Este projeto tem como objetivo o desenvolvimento de um sensor de radiação solar de baixo custo para aplicações em placas fotovoltaicas. Desenvolvido na disciplina de Projeto Integrador 3 do curso de graduação em Engenharia Eletrônica do Instituto Federal de Educação, Ciência e Tecnologia de Santa Catarina (IFSC). 

# Especificações do Projeto

* Monitorar a radiação solar medida pelo sensor para comparação com a potência gerada pela placa fotovoltaica, e assim verificar se a placa fotovoltaica está suja.
* Desenvolver um circuito de baixo custo, que não precise de muita manutenção.

# Etapas de desenvolvimento do projeto 

Este projeto dividiu-de em (QUANTOS?) etapas, sendo elas:
1. Análise bibliográfica sobre energia fotovoltaica e radiação solar, averiguando informações sobre modelos de sensores que pudessem ter baixo custo.
2. Escolha da case e dos componentes a serem usados no projeto.
3. Planejamento de comunicação entre o microcontrolador e o sensor vinculado à placa fotovoltaica.
4. Desenvolvimento do sensor.
5. Desenvolvimento do software para aquisição de dados advindos do sensor.
6. Integração da sensor e o microcontrolador com a placa fotovoltaica para aquisição de dados.
7. Finalização, testes e deferimento do projeto.

## Table of Contents 
1. [Sensor de radiação](#register-convention)
	* [Integer Register Convention](#integer-register-convention)
	* [Floating-point Register Convention](#floating-point-register-convention)
2. [Procedure Calling Convention](#procedure-calling-convention)
	* [Integer Calling Convention](#integer-calling-convention)
	* [Hardware Floating-point Calling Convention](#hardware-floating-point-calling-convention)
  

 
 ## <a name=default-abis-and-c-type-sizes></a> Sensor de Radiação Solar 
Placas fotovoltaicas estão sempre em desenvolvimento e avanços, uma delas é a inserção de sensores que possam captar a radiação para verificar se o painel está fornecendo a energia máxima. Fatores externos podem alterar a eficiência de um painel, e um fator bastante importante que tem sido deixado de lado é o "fator sujeira". Elementos como o ácaro, folhas, lama, restos de seres vivos e entre outros, podem formar uma camada de sujeira com o passar do tempo necessitando assim manutenção periódica do painel.
	
![painelsujo](https://user-images.githubusercontent.com/38983849/56757448-a1304400-676a-11e9-8ecd-1c92633be9c4.jpg)

Figura 1. Painel fotovoltaico sujo.

![painel limpo](https://user-images.githubusercontent.com/38983849/56757777-6ed31680-676b-11e9-8d29-56324a788673.jpg)

Figura 2. Painel fotovoltaico limpo.
	
Para que seja possível conferir se o painel está com essa camada de sujeira, é necessário um sensor de radiação que se possa fazer a comparação entre a potência gerada pelo painel fotovoltaico e a radiação captada pelo sensor, onde, muita radiação e pouca energia gerada pelos painéis informa que as placas podem estar sujas e precisam de manutenção. O sensor utilizado é o Piranometro da SP Lite2 que será utilizado como um modelo de comparação de resultados com o sensor projetado.

![01_Pyranometers_01_SP_Lite2_01_SP_Lite2](https://user-images.githubusercontent.com/38983849/57800798-a0b31980-7728-11e9-8bb7-bd36bb760ba3.jpg)

Figura 3. Pyranometro SP Lite2.

É importante salientar que a energia solar não depende da intensidade luminosa do Sol. Pois o dispositivo usado para determinar
a quantidade de energia solar, concentra em um ponto e mede a radiação (radiometria) ao invés do fluxo luminoso (fotometria). A figura abaixo mostra a energia contida no espectro solar (área sob a curva). Pode ser visto que a porção principal da energia está contida entre 300nm e 1300 nm de comprimento de onda.

![image](https://user-images.githubusercontent.com/38983849/57805452-4c616700-7733-11e9-825e-3d7943a6d149.png)

Figura 4. Diagrama do espectro da radiação solar.

O objetivo deste trabalho é projetar e construir um sensor de radiação solar capaz de coletar dados de irradiância usando componentes de baixo custo, e com base no artigo "DESIGN OF A LOW-COST SENSOR FOR SOLAR IRRADIANCE" disponível em: (http://twixar.me/8Zdn), foi possível fazer implementação e testes.

## FABRICAÇÃO DO SENSOR 
Utilizou-se um fototransistor, onde uma excitação de luminosidade na base do fototransistor gera uma corrente entre o coletor e emissor, que é proporcional a incidência de radiação. 
Para isso utilizou-se o fototransistor PT204C na configuração de emissor comum como o circuito da  Figura 1. Nesta configuração, uma variação na corrente do coletor  é proporcional a variação de tensão entre emissor e GND. 


![image](https://user-images.githubusercontent.com/38983849/57804735-bed14780-7731-11e9-8178-5948820d149e.png)

Figura 5. Esquemático do circuito.

Utilizando o PT204C e está configuração, a  máxima radiação que ele consegue medir é de 50w/m2 com uma tensão de 5v. Porém esse valor é muito menor do que a radiação que precisa medir em Florianópolis-SC, e para isso precisou utilizar um atenuador para que o sensor não saturasse.
A estrutura física do sensor foi composta por uma placa com o circuito da Figura 1, um cano de PVC e camadas de teflon. O fototransistor foi colocado no centro de um cano de PVC de 24mm a 10mm do topo do cano como mostra a Figura 2.

![posicao_pt](https://user-images.githubusercontent.com/39311424/59780637-b4eeb700-9290-11e9-90df-bb775ca7bf03.png)
Figura 6. Posição do PT204C no cano de PVC.

Para que o sensor não saturasse foi utilizado um atenuador feito com teflon. Utilizou-se 24 camadas de teflon, dispostas uma em cima da outra como mostra a Figura 7, e após isso foi colocado um peso em cima deixando lá por 24h, para que saísse todo o ar entre as camadas. 

![camadas_teflon](https://user-images.githubusercontent.com/39311424/59785806-31d35e00-929c-11e9-9cad-18f3738e99cc.png)

Figura 7. Camadas de teflon.

Após colocar as camadas de teflon no cano de PVC, obtivemos como resultado a Figura 8. Com as camadas de teflon obtivemos uma atenuação de 92%, ou seja o máximo de radiação que ele conseguirá medir sem saturar é de 1242 W/m², o suficiente para a cidade de Florianópolis-SC.
Como suporte para o sensor de radiação utilizou-se uma tampa de cano de PVC com um furo central onde foi colocado o sensor.

![IMG_1798](https://user-images.githubusercontent.com/38983849/57803105-f50cc800-772d-11e9-8c53-bc7c3d565710.JPG)

Figura 8. Sensor com atenuador de teflon.


Como o sensor ficará ao ar livre optamos por colocar uma (CUPULA DE LAMPADA DE LED????NAO SEI O NOME DISSO) vedada com silicone para proteger o sensor da chuva e da sujeira que poderia ficar acumulada no teflon. 
 A Figura 9 mostra o resultado final da produção do sensor, onde uma case vedada com silicone foi utilizada para armazenar o microcontrolador e a bateria utilizada, para que estes também ficassem protegidos da chuva. 


![sensro_cortado](https://user-images.githubusercontent.com/39311424/60203386-e7655a80-9822-11e9-9db4-7921280c8a4a.jpg)Figura 9. Protótipo Sensor de Radiação.





## SOFTWARE
Para aquisição de dados foi desenvolvido um código em C utilizando o microcontrolador ATMEGA328P. Utilizando o conversor analógico - digital do microcontrolador, foi possível adquirir os resultados do sensor de radiação e da potência da placa fotovoltaica. 
Para que fosse possível obter resultados satisfatórios, utilizou-se um RTC(Real Time Clock) para que ficasse salvo em qual horário foi adquirido o valor do sensor de radiação, e um módulo com cartão de memória para salvar estes dados. 
Ou seja, a cada 30 segundos é realizado uma média móvel de 8 valores adquiridos pelo ADC do microcontrolador (que representam os valores do sensor de radiação) e após isso é gravado em uma planilha no cartão de memória o valor dos ADCs e o horário. Com isso obtém-se uma planilha com os dados de radiação e potência da placa fotovoltaica. 

FOTO DA PLAQUINHA
Figura 9- Foto da placa

Para que fosse possível obter os dados da potência da placa fotovoltaica, utilizou como carga um circuito composto por 3 resistores em série: 2 resistores no valor de 20 ohms e um no valor de 3,19 ohms. Sendo assim, foi medido a tensão em cima do resistor de 3,19 ohms utilizando o ADC do microcontrolador e com isso obtivemos o valor da corrente deste circuito, sendo possível fazer o cálculo da potência consumida pela placa fotovoltaica. Foi medido a tensão no resistor de menor valor pois o máximo de tensão que pode ser lido pelo ADC é de 5V. 


## RESULTADOS E COMPARAÇÕES COM A PLACA FOTOVOLTAICA
Para que fosse possível detectar se a placa fotovoltaica está suja ou não, utilizou o sensor de radiação fabricado em comparação com a potência fornecida da placa fotovoltaica. Onde muita radiação e baixa potência fornecida, conclui-se que a placa fotovoltaica está suja ou está com algum objeto em cima, atrapalhando o fornecimento de energia.

Para caracterização desta aplicação, foi colocado o sensor de radiação juntamente com a placa fotovoltaica limpa para testes em um dia de sol, como resultados obteve-se o gráfico da Figura 10.

![radiacao_21_06](https://user-images.githubusercontent.com/39311424/60204266-d3225d00-9824-11e9-9630-c593283e9f5b.png)
Figura 10- Grafico potencia da placa e radiação solar







--------------------------------------------
![IMG_20190430_121725_767](https://user-images.githubusercontent.com/38983849/57803650-49fd0e00-772f-11e9-8ed6-2437c388a44c.jpg)

Figura 11. Teste do sensor de radiação.

