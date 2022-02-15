# Ejemplos Taller Nintendo DS

En este repositorio, puedes encontrar los distintos ejemplos, relacionados con el taller de desarrollo retro para Nintendo DS. Podemos ver los siguientes ejemplos:

* Hello: Hola mundo donde ver como mostrar texto y usar la pantalla táctil.
* texto: Muestra texto tanto en la pantalla superior como en la inferior.
* backgrounds: Ejemplo usando 1 fondo en la pantalla superior y texto en la inferior.
* background2: Ejemplo mostrando 2 fondos.
* Sprites: Ejemplo usando 1 fondo y sprite.

Puedes utilizar docker para generar las roms; con las siguientes instrucciones:

1.- Clonar el siguiente repositorio: [https://github.com/zerasul/dockerretro](https://github.com/zerasul/dockerretro).

2.- En la carpeta nds, generar la imagen:

```bash
docker build -t nds .
```
3.- Para compilar, ejecutar la siguiente instrucción con docker:

```bash
docker run --rm -v $PWD:/src/nds nds # Para Windows cambiar $PWD por %CD%.
```
