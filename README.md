# Desenvolvimento de um sensor de radiação solar de baixo custo para aplicações em placas fotovoltaicas

Este projeto tem como objetivo o desenvolvimento de um sensor de radiação solar de baixo custo para aplicações em placas fotovoltaicas. Desenvolvido na disciplina de Projeto Integrador 3 do curso de graduação em Engenharia Eletrônica do Instituto Federal de Educação, Ciência e Tecnologia de Santa Catarina (IFSC). 

# Especificações do Projeto

* Monitorar a quantidade de radiação solar medida pelo sensor para comparação com a potência gerada pela placa fotovoltaica, e assim verificar se a placa fotovoltaica está suja.
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
Placas fotovoltaicas estão sempre em desenvolvimento e avanços, uma delas é a inserção de sensores que possam captar a radiação para verificar se a painel está fornecendo a energia máxima. Fatores externos podem alterar a eficiência de um painel, e um fator bastante importante que tem sido deixado de lado é o "fator sujeira". Elementos como o ácaro, folhas, lama, restos de seres vivos e entre outros, podem formar uma camada de sujeira com o passar do tempo necessitando assim manutenção periódica do painel.
	
![painelsujo](https://user-images.githubusercontent.com/38983849/56757448-a1304400-676a-11e9-8ecd-1c92633be9c4.jpg)

Figura 1. Painel fotovoltaico sujo.

![painel limpo](https://user-images.githubusercontent.com/38983849/56757777-6ed31680-676b-11e9-8d29-56324a788673.jpg)

Figura 2. Painel fotovoltaico limpo.
	
Para que seja possível conferir se o painel está com essa camada de sujeira, é necessário ter um sensor de radiação que se possa fazer a comparação entre a potência gerada pelo painel fotovoltaico e a radiação captada pelo sensor, onde, muita radiação e pouca energia gerada pelos painéis informa que a placa pode estar suja e precisa de manutenção. O sensor utilizado é o Piranometro da SP Lite2 que será utilizado como um modelo de comparação de resultados com o sensor projetado.

![01_Pyranometers_01_SP_Lite2_01_SP_Lite2](https://user-images.githubusercontent.com/38983849/57800798-a0b31980-7728-11e9-8bb7-bd36bb760ba3.jpg)

Figura 3. Pyranometro SP Lite2.

É importante salientar que a energia solar não depende da intensidade luminosa do Sol. Pois o dispositivo usado para determinar
a quantidade de energia solar, concentrada em um ponto e mede a radiação (radiometria) ao invés do fluxo luminoso (fotometria). A figura abaixo mostra a energia contida no espectro solar (área sob a curva). Pode ser visto que a porção principal da energia está contida entre 300nm e 1300 nm de comprimento de onda.

![image](https://user-images.githubusercontent.com/38983849/57805452-4c616700-7733-11e9-825e-3d7943a6d149.png)

Figura 4. Diagrama do espectro da radiação solar.

 Com o elevado custo de um sensor de radiação fez-se necessário construir um módulo com um custo muito mais baixo, e com base no artigo (LINK DO ARTIGO), foi possível fazer implementação e testes.

##FABRICAÇÃO DO SENSOR 
Utilizou-se um fototransistor, onde uma excitação de luminosidade na base do transistor gera uma corrente entre o coletor e emissor, que é proporcional a incidência de radiação. Utilizou-se fototransistor PT204C pois 


![image](https://user-images.githubusercontent.com/38983849/57803240-50d75100-772e-11e9-8ea3-85fb9d9c09a3.png)

Figura 4. PT204C

![image](https://user-images.githubusercontent.com/38983849/57804735-bed14780-7731-11e9-8178-5948820d149e.png)

Figura 5. Esquemático do circuito.

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

