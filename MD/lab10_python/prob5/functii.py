import numpy as np
import networkx as nx
import matplotlib.pyplot as plt

def citire():
    n=int(input("Dimensiunea matricii:"))
    M=np.zeros((n,n),dtype=int)

    for i in range(n):
        for j in range(n):
            M[i][j]=int(input(f"M[{i}][{j}]"))

    return M

def afisare(M):
    v=[]
    for i in range(3):
        for j in range(3):
            if M[i][j]==1:
                v.append((i,j))


    print(v)

def desenare_graf(M,titlu="Graful Relatiei"):

    G=nx.DiGraph()
    n=len(M)
    noduri=range(1,n+1)
    G.add_nodes_from(noduri)

    for i in range(n):
        for j in range(n):
            if M[i][j]==1:
                G.add_edge(i+1,j+1)



    plt.figure(figsize=(6,4))
    pos=nx.spring_layout(G)

    nx.draw(G,pos,with_labels=True,node_color='lightgreen',node_size=700,arrowsize=20,font_weight='bold')
    plt.title(titlu)
    plt.show()






