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
    print("Introduceti elemente pana la citirea lui zero: ")

    while True:
        intrare=input("> ").strip()
        if intrare=='0':
            break
        numere=intrare.split()
        if len(numere)==2:
            a=int(numere[0])
            b=int(numere[1])
            E.append((a,b))
    return E

def generare_matrice(E):
    n=max(max(a,b) for a,b in E)
    M=np.zeros((n,n),dtype=int)
    for a,b in E:
        M[a-1][b-1]=1

    return M

def generare_graf(M):
    G=nx.DiGraph()
    n=len(M)
    G.add_nodes_from(range(1,n))
    for i in range(n):
        for j in range(n):
            if M[i][j]==1:
                G.add_edge(i+1, j+1)

    return G



def inchidere_reflexiva(M):
    n=M.shape[0]
    M_refl=M.copy()
    for i in range(n):
        M_refl[i][i]=1
    return M_refl


def inchidere_simetrica(M):

    M_sim=M | M.T
    return M_sim

def inchidere_tranzitiva(M):
    n=M.shape[0]
    W=M.copy()
    for k in range(n):
        for i in range(n):
            for j in range(n):
                W[i][j]=W[i][j] or (W[i][k] and W[k][j])
    return W




