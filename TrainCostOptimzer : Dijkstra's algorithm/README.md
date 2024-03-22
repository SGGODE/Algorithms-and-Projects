# Minimum Cost Travel Project

This project calculates the minimum cost to travel between different cities in India by train. The program allows you to choose the source and destination cities, as well as the type of train set (AC, Sleeper, or General) you want to travel in.

## Prerequisites

To run this program, you need to have a C++ compiler installed on your system.

## Getting Started

1. Clone the repository to your local machine or download the source code file.

2. Navigate to the project directory.
 [cd TrainCostOptimzer : Dijkstra's algorithm]

3. Compile the source code.
 [g++ -o main.cpp]

4. Run the executable.


## Usage

1. When you run the program, you will see a list of cities along with their corresponding numbers. The numbers are used for selecting the source and destination cities.

2. Enter the number of the source city and press Enter.

3. Enter the number of the destination city and press Enter.

4. You will be prompted to choose the type of train set:

   - Enter `1` for AC set.
   - Enter `2` for Sleeper set.
   - Enter `3` for General set.

5. After entering the set type, the program will calculate and display the minimum cost required to travel from the source city to the destination city using the chosen train set.

6. You can run the program multiple times to calculate costs for different city pairs and train set types.

## Example
```
Keep in Mind The Number in According to Your Source And Destination City :
Delhi 1
Mumbai 2
Pune 3
Bangalore 4
Hyderabad 5
Kolkata 6
Chennai 7
Ahmedabad 8
Enter Source City Number :
1

Enter Destination City Number :
7

Enter From Which Kind of Set You Want to Go :
AC - 1
Sleeper - 2
General - 3

Enter Valid Set Type :
2

This Is The Possible Minimum Cost Required to Go Chennai From Delhi in Sleeper set : 730
```

## Data Structure and Algorithm

The program uses an adjacency list representation of a graph to store the train connections between cities. It uses the Breadth-First Search (BFS) algorithm to find the minimum cost from the source city to the destination city.

The `find_min_cost` function takes the start and end city numbers along with the adjacency list as parameters and returns the minimum cost.

```
{source_city, destination_city, adjacency list}
```

## Data

The `train_info` vector contains information about the trains connecting different cities. Each entry in the vector represents a train connection and has the following format:

- `source_city` and `destination_city` are the numbers representing the source and destination cities respectively.
- `cost_set1` and `cost_set2` are the costs of traveling in different train sets (AC, Sleeper, General).

## Customization

If you want to modify the cities or add more train connections, you can update the `citys` vector and the `train_info` vector in the `main` function.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Acknowledgements

This project was implemented by [Sanket_Gode] as a part of []. Feel free to use and modify the code as needed. If you found it helpful, a reference or acknowledgement would be appreciated.


