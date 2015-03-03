Bienvenido al repositorio de contenidos de las cátedras *Sistemas
Operativos* e *Introduccion a los Sistemas Operativos* de la Facultad de
Informática, Universidad Nacional de La Plata. Acá vas a encontrar el
código fuente LaTeX que se utiliza para armar los trabajos prácticos y
explicaciones de las materias.

# Requisitos
Debido a la diversidad de sistemas operativos que utilizan los integrantes
de la cátedra, este repositorio debe ser multi-plataforma. Para tal fin se
utiliza una serie de archivos `Makefile`.

A continuación se especifican las dependencias que se deben instalar para
compilar el proyecto:
* texlive (con soporte español)
* make

## GNU/Linux
En Debian y distribuciones derivadas la instalación de las dependencias
puede efectuarse mediante el siguiente comando:

    # apt-get install make texlive texlive-lang-spanish texlive-latex-recommended texlive-latex-extra

## Windows
En Windows NT y sus versiones derivadas se deberá descargar los siguientes instaladores:

	#MikTex desde "http://mirrors.ctan.org/systems/win32/miktex/setup/basic-miktex-2.9.5105.exe"
	#GnuWin desde "http://gnuwin32.sourceforge.net/downlinks/make.php"

Una vez descargados los archivos deberá ejecutarlos siguiente las
indicaciones. Para finalizar reinicie la máquina.  Nota: en caso de que la
ejecucion de los comandos `make` o `pdflatex` no sean reconocidos por el
interprete de comandos, agregar los siguientes directorios a la variable de
entorno PATH del sistema: %DIRECTORIO_INSTALACION_MIKTEX%\miktex\bin y
%DIRECTORIO_INSTALACION_GNUWIN%\bin.

# Modo de uso
La forma más sencilla de compilar el contenido de este repositorio es
utilizando el comando `make install` en el directorio principal. Esto
provocará que se compile todo el material disponible y se lo guarde en el
directorio `pdf/`.

Cuando estés trabajando en un único documento puede resultar innecesario
tener que compilar todo el contenido. En este caso, es recomendable que
navegues hasta el directorio que contiene el material que quieras editar y
ejecutes `make` directamente desde esa ubicación. Todo el contenido se
encuentra jerárquicamente organizado en los directorios `practicas/` y
`explicaciones/`.

Cuando decidas que una práctica o explicación ya está lista para ser publicada,
ejecutá `make install` para que el sistema de compilación la guarde en el
directorio `pdf/`. ¡No hagas `commit`s de PDFs sin terminar!

# ¿Cómo colaborar?
La mejor forma de escribir material para la cátedra utilizando este
repositorio es mirando y estudiando lo que ya está hecho, con el objetivo de
aprender la sintaxis, y traducir a LaTeX el material de años anteriores.
