# Desenvolvimento de um sensor de radiação solar de baixo custo para aplicações em placas fotovoltaicas

Este projeto tem como objetivo o desenvolvimento de um sensor de radiação solar de baixo custo para aplicações em placas fotovoltaicas. Desenvolvido na disciplina de Projeto Integrador 3 do curso de graduação em Engenharia Eletrônica do Instituto Federal de Educação, Ciência e Tecnologia de Santa Catarina (IFSC). 

# Especificações do Projeto  (TA ENCAMINHADO)

* Monitorar a quantidade de radiação absorvida pelo sensor para comparação com a potência gerada pela placa fotovoltaica.
* Desenvolver um circuito de baixo custo, que não precise de muita manutenção.

# Etapas de desenvolvimento do projeto (FAZENDO)

Este projeto dividiu-de em (QUANTOS?) etapas, sendo elas:
1. Análise bibliográfica sobre energia fotovoltaica e radiação solar, averiguando informações sobre modelos de sensores que pudessem ter baixo custo.
1. Escolha da case e do sensor a serem usados no projeto.
1. Planejamento de comunicação entre o microcontrolador e o sensor vinculado à placa fotovoltaica.
1. Desenvolvimento da placa com o sensor necessária para aquisição da radiação.
1. Desenvolvimento do software para aquisição de dados advindos do sensor.
1. Integração da placa e o microcontrolador com a placa fotovoltaica para aquisição de dados.
1. Finalização, testes e deferimento do projeto.

## Table of Contents 
1. [Sensor de radiação](#register-convention)
	* [Integer Register Convention](#integer-register-convention)
	* [Floating-point Register Convention](#floating-point-register-convention)
2. [Procedure Calling Convention](#procedure-calling-convention)
	* [Integer Calling Convention](#integer-calling-convention)
	* [Hardware Floating-point Calling Convention](#hardware-floating-point-calling-convention)
  
## Copyright and license information

This RISC-V ELF psABI specification document is
 &copy; 2016 Palmer Dabbelt <palmer@dabbelt.com>
 &copy; 2016 Stefan O'Rear <sorear2@gmail.com>
 
 ## <a name=default-abis-and-c-type-sizes></a> Sensor de Radiação Solar 
Para que seja possível conferir se a placa fotovoltaica está suja, é necessário ter um sensor de radiação que se possa fazer a comparação entre a radiação absorvida pelas placas e a radiação captada pelo sensor, onde, muita radiação e pouca energia gerada pelas placas informa que a placa pode estar suja e precisa de manutenção.
 	Com o elevado custo de um sensor de radiação fez-se necessário construir um módulo com um custo muito mais baixo, sendo assim, com base no artigo (LINK DO ARTIGO), 
 

#FABRICAÇÃO DO SENSOR 
Utilizou-se um fototransistor, onde uma excitação de luminosidade na base do transistor gera uma corrente entre o coletor e emissor, que é proporcional a incidência de radiação. Utilizou-se fototransistor PT204C pois 

