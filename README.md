# Project4
Project4 cs302

| N             | Elapsed Time  | Memory Usage   |
|---------------|---------------|----------------|
| 10            | 0.004s        | 81,920 bytes   |
| 20            | 0.002s        | 82,760 bytes   |
| 50            | 0.011s        | 121,543 bytes  |
| 100           | 0.023s        | 198,678 bytes  |
| 200           | 0.32s         | 267,430 bytes  |
| 500           | 1.07s         | 734,234 bytes  |
| 1000          | 2.67 s        | 2,357,754 bytes|
|---------------|---------------|----------------|

1. I took the map from std input and put it in an defined on size. I changed the values from chars to ints based on the weights of each tile. I knew that the only possible moves were +1 in the x or y direction so I assumed those as the only possible edges in my dijkstras function.
2. The time complexity of my algorithm is O(ElogT)where E is the number of edges and T is the number of tiles. This is because we iterate through each edge O(n) and seach for each tile O(log(n)).
3. Explain what effect did N (ie. the size of the map) have on the performance of your dijkstras path finding component in terms of execution time and memory usage? As N increased the execution time and memory usage started to grow greatly. I assume that if N keep increasing the execution time and memory usage would increase exponentially.

(No Partners)
