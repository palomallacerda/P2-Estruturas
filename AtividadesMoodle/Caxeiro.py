#Código escrito com o Python3, usar o copilador do python#
from sys import maxsize as MAXSIZE
from itertools import permutations
vertex = 5

def calculate_min_route(graph, ini):
    all_vertex = []
    anterior = []
    soma = 0
    for i in range(vertex):
        if i != ini:
            all_vertex.append(i)
 
    min_path = MAXSIZE
    v_permutation = permutations(all_vertex)
    min_route = []
    ant = MAXSIZE
    for i in v_permutation:
        current_path_weight = 0
        src = ini
        for j in i:
            
            current_path_weight += graph[src][j]
            min_route.append(i)
            src = j

        current_path_weight += graph[src][ini]
        soma = current_path_weight
        
        if ant > soma:

            ant = soma
            anterior = min_route.copy()
            min_route = []
        
        else:
            
            min_route = []

        #min_path = min(min_path, current_path_weight)
        
    #return min_path, min_route
    return ant, anterior

if __name__ == "__main__":
    graph = [
        [0, 10, 15, 20, 50], 
        [10, 0, 5, 25, 9],
        [15, 5, 0, 30, 25], 
        [20, 25, 30, 0, 30],
        [50, 9, 25, 30, 0]
    ]
    ini = 0
    result = list(calculate_min_route(graph, ini))
    print('Ordem de visita: {}\nDistância: {}km'.format(result[1][0], result[0]))
