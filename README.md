# AntColonyOptimization
- Abstract : Ant Colony Optimization is population-based meta heuristic that can be used to find approximate solutions to difficult optimization problems. Here, we are using Ant Colony Optimization technique to solve one of the most intensively studied problems in computational mathematics, Traveling Salesman Problem.

- Introduction : Traveling Salesman Problem is deceptively simple combinatorial problem. In this problem, Salesman completes one tour by visiting all the given cities just once and finish up where he started. This paper reports effective way to implement Traveling Salesman Problem using Ant Colony Optimization technique. We have implemented a Greedy algorithm, and three variations of the local search algorithm called Tabu Search.

- Description : Ant Colony Optimization is method that take inspiration by bio-semiotic communication between ants. Each ant constructs solution with the help of stochastic greedy method and special chemical called as pheromone trail. This class of algorithm is known as Swarm Optimization. Stochastic greedy algorithms achieve optimal running time while maintaining an optimal approximation guarantee. Pheromone trail can be used to track most frequently visited paths in between two cities. Each ant will choose the next to visit according to the pheromone trail remained on the paths.
There are two main differences between artificial ants and real ants:
    1) the artificial ants have “memory”; they can remember the cities they have visited and 	therefore they would not select those cities again.
    2) The artificial ants are not completely “blind”; they know the distances between two cities and prefer to choose the nearby cities from their positions.

- Algorithm\

ANT COLONY OPTIMIZATION\

INPUT : \
    i. N – Number of cities\
    ii. distance[N][N] – Distance between any two selected cities\
    iii. Lk[l] – Path distance covered by randomly chosen ‘l’ ants\
    iv. p – Edge selection probability on each city\
    v. τij – Pheromone level corresponding to each edge\\

FORMULA :\
    • Pheromone level calculation :\
      

  The trail levels are updated as on a tour each ant leaves pheromone quantity given by Q/Lk, where Q is a constant and Lk the length of its tour, respectively. On the other hand, the pheromone will evaporate as the time goes by. \
      where t is the iteration counter, ρ ϵ [0, 1] the parameter to regulate the reduction of τij, Δτij the total increase of trail level on edge (i, j) and Δτijk the increase of trail level on edge (i, j) caused by ant k, respectively.\

   • Probability of choosing path :\
       
       



where τij is the intensity of pheromone trail between cities i and j, α the parameter to regulate the influence of τij, ηij the visibility of city j from city i, which is always set as 1/dij (dij is the distance between city i and j), β the parameter to regulate the influence of ηij and allowedk the set of cities that have not been visited yet, respectively.\

	
ALGORITHM :\
    i. Intialize Pheromone Trail(τij) for each edge as 0.01.\
    ii. For t = 1 to iteration number do:\
        i. Select ‘l’ ants and randomly place them on given cities.\
        ii. For k = 1 to l do:\
            i. Repeat steps till each city is visited\
                i. Calculate Probability(p) of choosing path based on given formula.\
                ii. Randomly choose path to next possible city.\
                iii. Update Visited city and distance travelled.\
            ii. End\
        iii. End\
        iv. Update Pheromone Trail(τij) based on given formula.\
    iii. End\


- Pros :
    • Can search among a population in parallel.
    • Can give rapid discovery of good solutions.
    • Can adapt changes such as new distances.
    • Have guaranteed convergence.

- Cons :
    • Probability distrubution can change for each iteration.
    • Have a difficult theoretical analysis.
    • Have dependent sequences of random decisions.
    • Have more experimental than theoretical research.
    • Have certain time to convergence.

 

- Improvement done after feedback :
    • Iterating procedure multiple time to improve performance and identify frequently visited paths based on pheromone level.
    • Selected number of ants in every iterations based on rand() function in a range of 0.2*N to 0.7*N where N is number of given cities.
    • By evaluating several values for parameter used to regulate the reduction of Pheromone trail after each iterations, finally assigned 0.5.
