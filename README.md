TP noté de LIFAPC

/*
1 - graphe
2 - chemin le plus court
3 - calcul du flot
*/

/*
structures : 
graphe
sommet 
arrete : infos sur arrete 
*/

/
parcours(s)
    si etat[s] == visité
        fini
    etat[s] = visité   
    pour chaque voisin v de s 
        parcours(v)
/

i = l * C + c

l = i/C
c = i%C