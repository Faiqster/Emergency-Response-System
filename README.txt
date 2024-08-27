# Emergency Response System

Welcome to our demonstration of an Emergency Response System built using C++! This project addresses the critical challenge of finding the nearest hospital and calculating the shortest path to it from a given location. Here’s an overview of the system:

## Features

- **Real-Time Location Input**: Users can input their current location, which the system uses to find the nearest available hospital.
- **Graph-Based Pathfinding**: Utilizes Dijkstra’s algorithm, a powerful graph traversal method, to compute the shortest path from the user’s location to the hospital, ensuring timely and efficient emergency responses.
- **Graph Representation**: Models locations and distances using a graph, where nodes represent locations (such as hospitals and user locations) and edges represent the distances between them.
- **Priority Queue for Efficiency**: Employs a priority queue to efficiently select the closest node at each step, optimizing the pathfinding process.

## Overview

This project showcases the application of classic algorithms in real-world scenarios, improving emergency response times and potentially saving lives. Dive into the implementation to see how we bring this system to life!

## Installation

**Clone the repository**:
   git clone https://github.com/yourusername/emergency-response-system.git
Navigate to the project directory:

cd emergency-response-system
Compile the project:

g++ -o emergency_response_system main.cpp -std=c++11
Usage
Run the application with:

./emergency_response_system
Follow the on-screen prompts to input your location and see the nearest hospital and the shortest path to it.

Contributing
Contributions are welcome! Please open issues or submit pull requests for improvements. For more details, refer to our CONTRIBUTING.md file.
