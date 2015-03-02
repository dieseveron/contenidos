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

    # apt-get install make texlive texlive-lang-spanish

## Windows
TODO

# Modo de uso
La forma más sencilla de compilar el contenido de este repositorio es
utilizando el comando `make install` en el directorio principal. Esto
provocará que se compile todo el material disponible y se lo guarde en el
directorio `pdf/`.

Cuando estés trabajando en un único documento puede resultar innecesario
tener que compilar todo el contenido. En este caso, es recomendable que
navegues hasta el directorio que contiene el material que quieras editar y
ejecutes `make` directamente desde esa ubicación. Todo el contenido se
encuentra jerárquicamente organizado en el directorio `src/`.

Cuando decidas que una práctica o explicación ya está lista para ser publicada,
ejecutá `make install` para que el sistema de compilación la guarde en el
directorio `pdf/`. ¡No hagas `commit`s de PDFs sin terminar!

# ¿Cómo colaborar?
