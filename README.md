# Práctica 03. Productos capicúa.

### Objetivos
Los objetivos de esta práctica son: 

* Ser capaz de desarrollar, compilar y ejecutar programas escritos en C++ en el entorno de trabajo IaaS
* Ser capaz de usar comandos de la shell de GNU/Linux para trabajar en la Máquina Virtual de la asignatura
* Que el alumnado codifique sus programas siguiendo lo estipulado en la Guía de Estilo de código de Google
* Profundizar en los conocimientos de Visual Studio Code (VSC)
* Que el alumnado aprenda a utilizar la utilidad make para el desarrollo de programas simples
* Poner en práctica los conocimientos de programación estructurada


### Rúbrica de evaluacion de esta práctica
Se señalan a continuación los aspectos más relevantes (la lista no es exhaustiva)
que se tendrán en cuenta a la hora de evaluar esta práctica:

* El alumnado ha de acreditar conocimientos para trabajar con la shell de GNU/Linux en su VM
* Ser capaz de desarrollar, editar remotamente usando VSC, compilar y ejecutar programas escritos en C++ en su VM
* El código ha de estar escrito de acuerdo al estándar de la [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
* El alumnado ha de acreditar capacidad para editar ficheros remotos en la VM de la asignautra usando VSC
* El programa desarrollado deberá compilarse utilizando la herramienta `make` y un fichero `Makefile`
* El comportamiento del programa debe ajustarse a lo solicitado en este documento.
* Ha de acreditarse capacidad para introducir cambios en el programa desarrollado.
* Modularidad: el programa ha de escribirse de modo que las diferentes funcionalidades que se precisen sean encapsuladas en funciones y/o métodos cuya extensión textual se mantenga acotada.

Si el alumnado tiene dudas respecto a cualquiera de estos aspectos, debiera acudir al
foro de discusiones de la asignatura para plantearlas allı́. 
Se espera que, a través de ese foro, el alumnado intercambie experiencias y conocimientos, ayudándose mutuamente
a resolver dichas dudas. 
También el profesorado de la asignatura intervendrá en las discusiones que pudieran suscitarse, si fuera necesario.
    
### Introducción
Un [palíndromo](https://es.wikipedia.org/wiki/Pal%C3%ADndromo)
es una palabra, número o frase que se lee igual de izquierda a derecha que de derecha a
izquierda.
Ejemplos de palíndromos son las palabras *arenera*, *Ana*, *arepera* o *reconocer*.
Si se trata de un numeral, usualmente en notación indoarábiga, al palíndromo se le denomina número capicúa.

Teniendo en cuenta esta definición, se puede observar que el mayor número capicúa obtenido como el producto
de dos números de dos dígitos, es el 9009:

`9009 = 91 × 99`

Análogamente, 99000099 es el mayor número capicúa obtenido como producto de dos números de cuatro dígitos:

`99000099 = 9999 × 9901`

### Ejercicio práctico
Diseñar e implementar en C++ un programa `palindrome_prod.cc` que, dado un número entero `n > 0`, 
encuentre los números capicúas resultantes de multiplicar dos números de `n` dígitos cada uno. 
El programa deberá almacenar en un fichero de texto esos números capicúas usando una línea diferente para cada
producto, de forma que un ejemplo de línea de ese fichero serían los dos productos anteriores.
Como entrada el programa recibirá por línea de comandos el número `n` y el nombre
de un fichero de salida para almacenar los números capicúa, de modo que el programa se ejecutará como:

`$> ./palindrome_prod n output.txt`

siendo `n` el número de dígitos de los factores que producen los números capicúa.

### Entorno de Trabajo
En esta práctica debe Ud. compilar su programa accediendo a su VM, e invocando al compilador en su directorio
de trabajo:

`$ g++ -std=c++14 -g -Wall -o palindrome_prod palindrome_prod.cc`

Estudie algún tutorial ([este podría ser un ejemplo](https://cs.colby.edu/maxwell/courses/tutorials/maketutor/)) para aprender a utilizar
la herramienta `make` y ficheros `Makefile`.
Revise igualmente la documentación oficial correspondiente a [GNU Make](https://www.gnu.org/software/make/).

Su proyecto de programación debe contener un fichero `Makefile` de modo que al ejecutar

`$ make`

se produzca la compilación del programa y se genere el fichero ejecutable `palindrome_prod`, mientras que
ejecutando

`$ make clean`

se borren todos los ficheros del directorio de trabajo salvo los que contengan código fuente
(`palindrome_prod.*`) y el propio `Makefile`.

### Referencias
* [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) La guía de estilo de código que
  se usará en la asignatura
* [GNU Make](https://www.gnu.org/software/make/)
* [Ejemplo de un fichero Makefile](https://github.com/fsande/IB-class-code-examples/blob/master/IntroductionToC%2B%2B/Makefile) para compilar el programa hello_world.cc
* [A Simple Makefile Tutorial](https://cs.colby.edu/maxwell/courses/tutorials/maketutor/) De forma incremental
  explica el funcionamiento de la herramienta `make`. Utiliza el compilador de C en lugar de `g++`, pero es
	obvio cómo adaptar los ejemplos al caso de C++.
* [How to parse command line parameters](http://www.cplusplus.com/articles/DEN36Up4/) Explica cómo pasar parámetros a un programa C o C++ desde la línea de comandos.
* [C++ Tutor](http://pythontutor.com/cpp.html#mode=display) Visualización online de la ejecución de código C++
