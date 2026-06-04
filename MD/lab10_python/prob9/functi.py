import networkx as nx
import matplotlib.pyplot as plt
import numpy as np


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
    plt.show()

def generare_graf(A):
    litera=['a','b','c','d']
    G=nx.DiGraph()
    n=len(A)
    G.add_nodes_from(litera)
    for i in range(n):
        for j in range(n):
            if A[i][j]==1:
                G.add_edge(litera[i],litera[j])
    return G


def citire():
    n=int(input("Dimensiunea matricei: "))
    M=np.zeros((n,n),dtype=int)
    for i in range(n):
        for j in range(n):
            M[i][j]=int(input(f"M[{i}][{j}]"))

    return M


def afisare(M):
    elemente=['a','b','c','d']
    n=len(M)
    l=[]
    for i in range(n):
        for j in range(n):
            if M[i][j]==1:
                l.append((elemente[i],elemente[j]))
    print(l)

def simetrie(M):
    return np.array_equal(M,M.T)

def reflexiva(M):
    n=len(M)
    for i in range(n):
        if M[i][i]==0:
            return False
    return True
def tranzitiva(M):
    M2=(np.dot(M,M)>0).astype(int)
    n=len(M)
    for i in range(n):
        for j in range(n):
            if M2[i][j]==1 and M[i][j]==0:
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

