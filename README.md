# LIFAPC TP

## TP Content

1. **Graph (image)**
2. **Traversal of image (DFT and BFT)**
3. **Calculating flow  (image binarisation)**

## Used structures

### Graph

The graph is represented by an array structure meant to be a matrix of pixels

### Pixel

Every pixel is represented by its own intensity, state, capacity, flow and the neighbors flow and capacity. The source and the sink flow and capacity is also stored in the pixel.

## Traversal algorithms

- The Depth First Traversal is defined like this (in pseudocode) :

Traversal(s)
    if state[s] == visited
        finish
    state[s] = visited
    for each neighbors v of s
        Traversal(v)


- The Breadth First Traversal is defined like this (in pseudocode) :

Traversal(s)
    queue Q
    Q.push(s)
    while Q != null
        current = Q.pop()
        if state[courant] == visited
            state[courant] = visited
        for neighbor v = current.neighbors()
            if state[v] != visited
                Q.push(v)

## Relationship between Global Index and Coordinates

The relationship between the global index `i` and the coordinates `(l, c)` is given by the following equations:

i = l * C + c
l = i / C
c = i % C

## TODO

- Debug the graph constructor by file (segfault)
- Display the image (in ASCII)
- Save the image in a file
- Arc managing

- Binarisation

## How to use the code

- **Go into the parent directory**
- **Enter a Terminal and type "make"**
- **the compilation of the source files should be done**
- **execute the main executable "./bin/main"**
- **if you need to recompile some file (after file modification) just type make again**
- **to clean the compiled file and the executable, simply type "make clean"**