import matplotlib.pyplot as plt
import networkx as nx
import numpy as np
import random

G = nx.DiGraph()
G.add_node("a", demand=-5)
G.add_node("d", demand=5)


G.add_edge("a", "b", weight=3, capacity=4)
G.add_edge("a", "c", weight=6, capacity=10)
G.add_edge("b", "d", weight=1, capacity=9)
G.add_edge("c", "d", weight=2, capacity=5)


flowDict = nx.min_cost_flow(G)
flowCost = nx.min_cost_flow_cost(G)
print(flowCost)
print(flowDict)


# Draw the graph
pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True)

# Annotate edges with flow/capacity information
edge_labels = {(i, j): "(" + str(flowDict[i][j]) + "/" + str(G[i][j]['capacity']) + ")"
               for i, j in G.edges()}
# Annotate edges with weight information
weight_labels = {(i, j): "time: " +
                 str(G[i][j]['weight']) for i, j in G.edges()}
nx.draw_networkx_edge_labels(G, pos, edge_labels=weight_labels)

# Annotate edges with flow/capacity information
flow_capacity_labels = {(i, j): "flow/capacity: (" + str(flowDict[i][j]) + "/" + str(G[i][j]['capacity']) + ")"
                        for i, j in G.edges()}
nx.draw_networkx_edge_labels(
    G, pos, edge_labels=flow_capacity_labels, label_pos=0.7)


for i, j in G.edges():
    flow = flowDict[i][j]
    capacity = G[i][j]['capacity']
    cost = flow * G[i][j]['weight']
    print(f"{i} -> {j}   {flow}  /  {capacity} {cost}")

plt.show()
