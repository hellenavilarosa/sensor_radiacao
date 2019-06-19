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

IBAGEM

![IMG_1798](https://user-images.githubusercontent.com/38983849/57803105-f50cc800-772d-11e9-8c53-bc7c3d565710.JPG)

Figura 6. Cano com 25 camadas de teflon.

![arduino_uno_r3_-_cabo_usb_-_design_italy](https://user-images.githubusercontent.com/38983849/57801620-795d4c00-772a-11e9-94aa-d10dd6a0a4a1.jpg)

Figura 7. Arduino UNO.

![rtc](https://user-images.githubusercontent.com/38983849/57801611-75c9c500-772a-11e9-8361-6e29b61a50e9.jpg)

Figura 8. RTC.

![716up2f1W4L _SX425_](https://user-images.githubusercontent.com/38983849/57802628-cb06d600-772c-11e9-9872-bbace843cc2c.jpg)

Figura 9. SD CARD.

![photo_2019-05-15_16-02-15](https://user-images.githubusercontent.com/38983849/57803374-a27fdb80-772e-11e9-9c78-62f6486b7f57.jpg)

Figura 10. Sensor de radiação.

![IMG_20190430_121725_767](https://user-images.githubusercontent.com/38983849/57803650-49fd0e00-772f-11e9-8ed6-2437c388a44c.jpg)

Figura 11. Teste do sensor de radiação.

