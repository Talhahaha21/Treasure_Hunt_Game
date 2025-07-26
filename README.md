Treasure Diggers

Treasure Diggers is a thrilling C++ console-based strategy game combining risk, reward, and logic. Navigate a 5x5 desert grid, dig for treasure, avoid hidden bombs, and try to earn a spot on the top 10 leaderboard. This is my first major project uploaded to GitHub and demonstrates the application of core Data Structures and Algorithms (DSA) in game development.

🎮 Introduction

Treasure Diggers places players in a mysterious desert filled with hidden treasures and bombs. With only 4 spades and 3 lives, each dig could lead to treasure or disaster. Perform well to rank among the top ten diggers, but one wrong move might end your journey.

Key Mechanics:
-> 5x5 desert grid
-> Randomized bomb and treasure placement
-> 4 spades per round
-> 3 lives per player
-> Top 10 leaderboard

ASCII art used in the game was sourced from:
-> https://www.asciiart.eu/
-> https://ascii.co.uk/art

💡 Inspiration

-> Minesweeper – uncovering safe tiles while avoiding hazards.
-> Treasure Hunt Games – excitement of rewards mixed with risk.
-> Bomberman – strategy in a grid-based setting.

🎯 Objective

-> Demonstrate real-world application of DSA by:
-> Building an interactive treasure hunt game.
-> Using structures like arrays, queues, and linked lists.
-> Applying algorithms for randomization, traversal, and sorting.

📌 Problem Statement

-> Random, non-overlapping bomb and treasure placement.
-> Strategic grid traversal with limited actions.
-> Efficient score and leaderboard management.
-> Optimized data handling and memory usage.

🧱 Data Structures Used

1. 2D/Multi-level Doubly Linked List
-> Core structure for the game map.
-> Allows four-way traversal.
-> Efficient updates when digging tiles.

2. Queue
-> Ensures unique placement of bombs and treasure.
-> Maintains list of used coordinates.

4. Arrays
-> Level Array: Tracks game levels.
-> Score Array: Maintains top 10 scores with sorting.

📊 Algorithms Used
-> Insertion: Used for storing random bomb/treasure locations and player scores.
-> Selection: Ensures unique coordinate generation.
-> Traversal: Supports player movement and data iteration.
-> Searching: Validates uniqueness in the queue.
-> Updating: Grid and scoreboard updates.
-> Sorting: Maintains top scores in descending order.

🛠 Implementation Highlights
Player Class
-> Tracks health, score, spades.
-> Handles grid traversal.
Key Functions
-> Menu and UI display.
-> Scoreboard and ranking system.
Code Snippets
-> Doubly linked list for grid.
-> Queue for random placements.
-> Score sorting via arrays.

✅ Conclusion

Treasure Diggers is a hands-on demonstration of DSA in action. Doubly linked lists allow efficient map navigation, queues ensure unique placements, and arrays manage scores. Future improvements could include:
-> Larger maps
-> AI opponents
-> Optimized sorting techniques

🖥️ Technologies Used
Language: C++
Libraries:
- <iostream>
- <conio.h>
- <fstream>
- <string>
- <windows.h>
- <chrono>
- <thread>

📁 License / Credits
ASCII Art from: https://www.asciiart.eu/ and https://ascii.co.uk/art
Feel free to fork, use, or build upon this project.
Thank you for checking out Treasure Diggers! 🎉
