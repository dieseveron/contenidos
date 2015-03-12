# Repaso de shell scripting

## Definiciones

* Una shell es un intérprete de comandos
* Interactiva o batch
* En _*nix_: shells configurables e intercambiables
  * **sh**
  * **bash** (nos basaremos en ella para la materia)
  * **dash**
  * **csh**
  * **zsh**
  * ...y otras

## Elementos de una shell

* Comandos internos
  * `man bash` para listarlos, `help COMANDO` para información
  * `cd`, `source`, `for`, `if`, `while`, `continue`, `break`, `echo`, `exit`, `export`, `bg`, `fg`, `help`, `kill`, `let`, `local`, `pwd`, `read`, `return`, `test` (o `[ ]`), `wait`, ...
* Comandos externos
  * `man COMANDO` para información
  * Cualquier binario que instalemos
  * ¡Cualquier script que hagamos nosotros mismos!
  * `grep`, `cat`, `cut`, `ln`, `ls`, `find`, `expr`, `nc`, `rm`, `mv`, `cp`, ...
* Comentarios
  * Comienzan con `#`
  * `# Este es un comentario`
  * `ls # listo los archivos y directorios del path actual`
* Estructuras de control
  * Son comandos internos
  * `for`, `if`, `while`, ...
* Variables
  * Strings
  * Arreglos
  * `hola`, `"este es un string"`, `'y este también'`
  * `(esto es un arreglo con 7 elementos)`
  * `mi_variable="un string"` y luego su valor se accede mediante `$mi_variable`
  * `mi_arreglo=(un arreglo con elementos)` y luego sus valores se acceden mediante `${mi_arreglo[POSICION]}`
    * `${mi_arreglo[0]}` es el primer elemento
    * `${mi_arreglo[*]}` imprime una lista con todos los elementos
    * `${#mi_arreglo[*]}` imprime la cantidad de elementos
    * `mi_arreglo[2]=sin` asigna el tercer elemento
    * `unset mi_arreglo[3]` borra el cuarto elemento
* Funciones
  * Encapsulan lógica, funcionan como comandos una vez definidas
  * `function imprimir() { echo $* }`, luego `imprimir Bienvenidos a SO`
* Redirecciones y *pipes*
  * Son unidireccionales
  * Redirecciones (`<`, `>` y `>>`)
    * Toman la salida de un comando y la pasan a un archivo del filesystem
  * Pipes (`|`)
    * Mecanismo IPC (*Inter Process Communication*)
    * Toman la salida estándar de un comando y la pasan a la entrada estándar de otro
    * Utilizan *buffering*

## Funcionamiento

* Pasaje de parámetros
  * Posicionalmente
  * `$1`..`$n`, `$0`, `$*`, `$#`
* Estados de los comandos (*exit status*)
  * `0`: éxito, `1` a `255`: error
  * `exit` status para comandos
  * `return` para funciones
  * `$?` para consultar el último *exit status*
* Sustitución de comandos
  * Reemplaza un comando por su salida estándar
  * "\`" y `$()`
  * `echo hoy es $(date)`

## En _*nix_ todo es un archivo

* Cada comando tiene al menos 3 archivos abiertos:
  * `fd 0`: `stdin` (entrada estándar)
  * `fd 1`: `stdout` (salida estándar)
  * `fd 2`: `stderr` (salida de error estándar)
* Como son archivos, podemos leer de y escribir en ellos
  * `read variable` lee de `stdin`
  * `read variable < ARCHIVO` escribe el contenido de `ARCHIVO` en `stdin` para `read`
  * `echo Un mensaje` escribe en `stdout`
    * Equivale a `echo Un mensaje >&1`
  * `echo Un error >&2` escribe en `stderr`

## Comandos útiles

* Imprimir texto
  * `echo Shell scripting es sencillo`
* Imprimir el contenido de un archivo
  * `cat archivo`
* Leer de entrada estándar (teclado) en una variable
  * `read variable` y luego `echo $variable`
* Leer el primer campo delimitado por `:`
  * `cut -d: -f1` (de `stdin`)
  * `cut -d: -f1 ARCHIVO` (del archivo `ARCHIVO`)
* Traducir (intercambiar) caracteres
  * `echo hola | tr a-z A-Z` traduce las minúsculas por mayúsculas
* Contar la cantidad de líneas
  * `wc -l` (de `stdin`)
  * `wc -l ARCHIVO` (del archivo `ARCHIVO`)
* Buscar recursivamente archivos por su nombre en el directorio actual (`.`)
  * `find . -name "*.sh"`
* Buscar un patrón
  * `grep shell` (en `stdin`)
  * `grep shell ARCHIVO` (en el archivo `ARCHIVO`)
  * `grep shell *` (en todos los archivos del directorio actual)
* Empaquetado de archivos
  * `tar -cf destino.tar origen1 origen2` empaqueta en `destino.tar`
  * `tar -xf destino.tar` desempaqueta `destino.tar`
* Compresión de archivos
  * `gzip destino.tar` comprime `destino.tar` en `destino.tar.gz`
  * `gzip -d destino.tar.gz` descomprime `destino.tar.gz`
* Empaquetado y compresión con `tar`
  * `tar -cfz destino.tar.gz origen1 origen2` invoca `gzip` automáticamente
  * `tar -xfz destino.tar.gz` descomprime y desempaqueta `destino.tar.gz`
* Listado de procesos
  * `ps -aux` lista los procesos en ejecución de todos los usuarios

## Pipes

* `ps -aux | grep mysql`
* `cat /etc/passwd | cut -d: -f1 | grep o | wc -l`
* `cat /proc/cpuinfo | grep processor | wc -l > procesadores`

## Scripts: *shebang*

* Primer línea de un script
* Indica qué comando se usará para ejecutar un script
  * `#!/bin/bash`
  * `#!/usr/bin/env ruby`

## Alcance de las variables

* Por defecto todas las variables son *globales* al script
* Se pueden especificar variables *locales* mediante `local`
* Existen variables globales a la sesión, llamadas **variables de entorno**
  * `export MI_VARIABLE="su valor"`
  * Ejemplos: `$HOME`, `$PATH`, `$PWD`
  * Consultar las variables de entorno definidas: `export`

## Ejecución de scripts

* Si se tienen permisos de ejecución
  * `./script.sh`
* Especificando el binario a utilizar
  * `bash script.sh`
* Modo de depuración (*debug*)
  * `bash -x script.sh`

## Ejemplos

* **TODO**
