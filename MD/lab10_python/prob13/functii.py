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
    print("Dati valori pana la citirea lui zero: ")
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

def generare_m(E):
    n=max(max(a,b) for a, b in E)
    m=np.zeros((n,n),dtype=int)
    for a,b in E:
        m[a-1][b-1]=1

    return m

def generare_g(m):
    n=len(m)
    G=nx.DiGraph()
    for i in range(n):
        for j in range(n):
            if m[i][j]==1:
                G.add_edge(i+1,j+1)
    return G


def inchidere_reflexivitate(M):
    n=len(M)
    M_R=M.copy()
    for i in range(n):
        M_R[i][i]=1

    return M

def inchidere_simetrica(M):
    M_S=M | M.T
    return M_S

def inchider_tranzitiva(M):
    n=len(M)
    W=M.copy()
    for k in range(n):
        for i in range(n):
            for j in range(n):
                M[i][j]=M[i][j] or (M[i][k] and M[j][k])

    return W






