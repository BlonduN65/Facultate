import functii as f
import numpy as np
import matplotlib.pyplot as plt
import networkx as nx

def main():

    A={1,2,3,4,5,6}

    R=f.relatie(A)
    print(R)
    
    M=np.zeros((len(A),len(A)),dtype=int)
    for a , b in R:
        M[a-1][b-1]=1

    print("Matricea booleana a relatiei este: ")
    print(M)


    G=nx.DiGraph()
    G.add_nodes_from(A)
    G.add_edges_from(R)

    pos=nx.spring_layout(G)
    nx.draw(G,pos,with_labels=True,node_color='lightblue',edge_color='black',node_size=800,arrowsize=20)
    plt.title("Graful relatiei pentru A:")
    plt.show()

if __name__=="__main__":
    main()




