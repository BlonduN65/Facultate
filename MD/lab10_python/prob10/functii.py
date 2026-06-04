import numpy as np
import networkx as nx
import matplotlib.pyplot as plt

def desenareGraf(G):
    fig, ax = plt.subplots()

    pos = nx.circular_layout(G)

#node options
    node_options = {
            "node_color": "white",
            "node_size": 500,
            "edgecolors":"black"
            }

#edge options
    edge_options = {
            "width": 1,
            "edge_color": "black",
            "connectionstyle": 'arc3, rad = 0.10',
            "arrowsize": 12,
            "arrowstyle":"-|>",
            "arrows":True
            }

    node_label_options = {
        "font_size": 10,
        "font_color": "black",
        "verticalalignment": "center",
        "horizontalalignment": "center"
        }

    nx.draw_networkx_nodes(G, pos, ax = ax, **node_options)

    nx.draw_networkx_edges(G, pos, **edge_options)

    nx.draw_networkx_labels(G, pos, **node_label_options)

    ax.set_aspect('equal')

#    plt.draw()
    plt.savefig("____.png")
    plt.show()


def citire():
    E=[]
    print("Introduceti elementele pana la citirea lui 0: ")

    while True:
        intrare=input("> ").strip()
        if intrare=='0':
            break
        numere=intrare.split()
        if len(numere)==2:
            a=int(numere[0])
            b=int(numere[1])
            E.append((a,b))
        else:
            print("eroare")
    return E

def generare_matrice(relatie):
    n=max(max(a,b) for a,b in relatie)
    M=np.zeros((n,n),dtype=int)
    for a ,b in relatie:
        M[a-1][b-1]=1

    return M

def generare_graf(M):
    n=len(M)
    G=nx.DiGraph()
    G.add_nodes_from(range(1,n))
    for i in range(n):
        for j in range(n):
            if M[i][j]==1:
                G.add_edge(i+1,j+1)

    return G


def simetrie(M):
    return np.array_equal(M,M.T)

def reflexiva(M):
    n=len(M)
    for i in range(n):
        if M[i][i]==0:
            return False

    return True 

def tranzitivitate(M):
    n=len(M)
    M2=(np.dot(M,M)>0).astype(int)
    for i in range(n):
        for j in range(n):
            if   M[i][j]==1 and M2[i][j]==1:
                return False

    return True

def antisimetrica(M):
    n=len(M)
    for i in range(n):
        for j in range(n):
            if i!=j and M[i][j]==1 and M[j][i]==1:
                return False

    return True

def asimetrica(M):
    return reflexiva(M) and antisimetrica(M)


