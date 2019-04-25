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
	
Para que seja possível conferir se o painel está com essa camada de sujeira, é necessário ter um sensor de radiação que se possa fazer a comparação entre a potência gerada pelo painel fotovoltaico e a radiação captada pelo sensor, onde, muita radiação e pouca energia gerada pelos painéis informa que a placa pode estar suja e precisa de manutenção.

IMAGEM DO SENSOR CARO

 Com o elevado custo de um sensor de radiação fez-se necessário construir um módulo com um custo muito mais baixo, e com base no artigo (LINK DO ARTIGO), foi possível fazer implementação e testes.

##FABRICAÇÃO DO SENSOR 
Utilizou-se um fototransistor, onde uma excitação de luminosidade na base do transistor gera uma corrente entre o coletor e emissor, que é proporcional a incidência de radiação. Utilizou-se fototransistor PT204C pois 

