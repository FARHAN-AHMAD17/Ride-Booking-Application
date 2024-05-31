# Ride Booking Application
I Developed FAQ RIDING App using the Data Structure concepts of C++ programming language🚕😎🎶

## **Project Overview**

This project is a comprehensive implementation of a ride booking application, designed as a Data Structures and Algorithms (DSA) project. The application simulates the functionalities of a ride-hailing service, allowing passengers to book rides, drivers to manage their rides, and admins to oversee the entire operation.

##**Features**

### **Admin Module**
- **Admin Login**: Secure login for admin users.
- **Admin Operations**: Manage cars, drivers, and passengers within the system.
- **Car Portal**: Manage car-related information.
- **Driver Portal**: Manage driver-related information.
- **Passenger Portal**: Manage passenger-related information.

### **Driver Module**
- **Driver Login**: Secure login for drivers.
- **Driver Operations**: Manage personal ride history and current ride requests.

### **Passenger Module**
- **Passenger Login**: Secure login for passengers.
- **Ride Booking**: Book different classes of rides (e.g., Mini, Go, Luxury).
- **Ride Management**: View and manage current and past ride requests.

**Data Structures Used**

**Linked List**
- **Description**: Used extensively for managing lists of cars, drivers, and passengers.
- **Operations Implemented**:
  - Insertion, Deletion (including specific deletions), Display, and Validity Checks.

**Queue**
- **Description**: Utilized for managing ride requests in a First-In-First-Out (FIFO) manner.
- **Operations Implemented**:
  - Insertion at the rear, Removal from the front, Checking the front, Display, and Deletion of all elements.

**Stack**
- **Description**: Used to manage the ride history of passengers.
- **Operations Implemented**:
  - Standard stack operations like push, pop, and display.

**Key Classes and Functions**

**Admin Class**
- **Attributes**: ID and Password.
- **Functions**: Set values, Get ID, Get Password.

**DriverRequest Class**
- **Attributes**: Driver details including ID, name, contact number, vehicle, vehicle class, arrival time, and fare.
- **Functions**: Set request details, Get functions for each attribute, and Overloaded `<<` operator for display.

**Passenger Class**
- **Attributes**: ID, password, name, contact number, wallet, pickup and drop-off locations, complaint, accepted driver ID, ride history, and ride requests.
- **Functions**: Manage passenger-specific operations and interactions.

**Menu Class**
- **Functions**:
  - Display introduction screen.
  - Admin, Driver, and Passenger operations.
  - Ride booking and selection process.

**How to Run**

1. **Setup**: Ensure you have a C++ compiler installed.
2. **Compile**: Compile the source files.
3. **Execute**: Run the compiled program.
4. **Interaction**: Follow the on-screen prompts to interact with the application as an Admin, Driver, or Passenger.

**Conclusion**

This project encapsulates various data structures and algorithms to create a functional ride-booking system, providing a practical implementation of theoretical concepts. It serves as a solid foundation for understanding the application of DSA in real-world scenarios.
