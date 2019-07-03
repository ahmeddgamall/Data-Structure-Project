import networkx as nx
import matplotlib.pyplot as plt

G = nx.Graph()

file = open('C:\\Users\\Dell\\Desktop\\input\\output.txt','r')

str = file.read()
lines = str.split('\n')

size = []
for i in lines:
    numbers = i.split(' ')
    if(len(numbers) == 2):
        start = numbers[0]
        end = numbers[1]
        G.add_node(start)
        G.add_node(end)
        G.add_edges_from([(start, end),])
    elif(len(numbers) == 1):
        size.append(float(numbers[0]))
    else:
        break

file.close()

max_cen = max(size)
min_cen = min(size)
for i in range(0, len(size)):
    size[i] = size[i] * (max_cen/(min_cen + 1)) * 10000
    
pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels = True, font_weight = 'bold', font_color = 'RED', node_size = size, node_color = 'black', nodelist = sorted(G.nodes()))
plt.show()
