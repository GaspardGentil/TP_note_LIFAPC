# TP Noté de LIFAPC

## Contenu du TP

1. **Graph (image)**
2. **Parcours de l'image (largeur et profondeur)**
3. **Calcul du flot (binarisation de l'image)**

## Structures Utilisées

### Graph

Le graphe est représenté à l'aide d'une structure de tableau censé representer une grille

### Pixel

Chaque Pixel du graphe est caractérisé par son intensité et son état.

## Algorithme de Parcours

L'algorithme de parcours en profondeur est défini comme suit (en pseudocode) :

parcours(s)
    si etat[s] == visité
        fini
    etat[s] = visité   
    pour chaque voisin v de s 
        parcours(v)

## Relation entre Indice Global et Coordonnées

La relation entre l'indice global `i` et les coordonnées `(l, c)` est donnée par les équations suivantes :

i = l * C + c
l = i / C
c = i % C

## TODO

- Debug the graph constructor by file (segfault)
- Breadth First Traversal function
- Display the image (in ASCII)
- Save the image in a file
- Arc managing

/***************************************/

Binarisation

## How to use the code

- **Go into the parent directory (should be TP_note)**
- **Enter a Terminal and type "make"**
- **the compilation of the source files should be done**
- **execute the main executable "./bin/main"**
- **if you need to recompile some file (after updates) just type make again**
- **to clean the compiled file and the executable, simply type "make clean"**