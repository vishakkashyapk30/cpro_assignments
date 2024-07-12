# Introduction
This README provides an overview of the program's purpose, data structures used, functions, important variables used to achieve its functionality and assumptions made while writing the code. It serves as a reference for understanding how the codes operate.

# Q1: Bank Account Management System

## Purpose of the Code
This code is a simple bank account management system implemented in C. It allows users to create, delete, and perform transactions on bank accounts. It also provides options to display account information and list low-balance accounts. The code is designed to simulate basic banking operations.

## Data Structures Used
- **Linked List:** 
  - **Description:** A linked list is the primary data structure used in the code. It is a dynamic data structure where elements are stored in nodes, and each node points to the next node. In this context, it is used to manage and store information about various bank accounts.
- **Enumeration (`enum`):** 
  - **Name:** AccountType
  - **Description:** Represents the types of accounts using an enumeration. It includes `savings` and `current` account types.
- **Structure (`struct`):** 
  - **Name:** AccountInfo
  - **Description:** Stores information about an account, including the account number, account type, name, and balance.
- **Structure (`struct`):** 
  - **Name:** AccountNode
  - **Description:** Represents a node in the linked list. Each node contains an `AccountInfo` structure and a pointer to the next node in the list.
- **Alias (`typedef`):** 
  - **Name:** LinkedList
  - **Description:** An alias for the `AccountNode` structure, creating a more readable name for the linked list of accounts.

## Function Descriptions
### `insert`
This function is used to insert a new account into the linked list at a specified position.
### `accountTypeToStr`
Converts an account type enumeration to a string for better readability.
### `createAccount`
Creates a new bank account and adds it to the linked list. It checks for duplicate accounts and account number availability.
### `deleteAccount`
Deletes a bank account based on account type and account holder's name.
### `transaction`
Performs a deposit or withdrawal transaction on a bank account, updating the account's balance.
### `lowBalanceAccounts`
Displays accounts with a balance lower than 100.
### `display`
Displays information for all accounts in the linked list.

## Important Variable Descriptions
- `AccountType`: An enumeration that defines the type of the bank account (savings or current).
- `AccountInfo`: A structure that holds account information, including account number, type, name, and balance.
- `AccountNode`: A structure that represents a node in the linked list, containing account data and a reference to the next node.
- `LinkedList`: An alias for `AccountNode*`, representing the linked list of bank accounts.
- Various other local variables are used for temporary storage and control within the functions.

## Assumptions
- Account numbers start from 100 and increment by one for each new account.
- Account types are either "savings" or "current," and case-insensitive.
- Account names are unique for each account type.
- Transaction codes: 1 for deposit, 0 for withdrawal.
- Transaction amounts must be positive.
- The code runs in a terminal environment where user inputs are provided through standard input (stdin).
- Users are familiar with the options displayed and use them correctly.


# Q2: Complex Number Operations in C

## Purpose
This C program is designed to perform various operations on complex numbers represented as linked lists. It allows you to create complex numbers, add, subtract, find the dot product, and calculate cosine similarity between two complex numbers.

## Data Structures Used
- **Linked List:**
  - **Description:** A linked list is the primary data structure used in the code. It is employed to create and manipulate complex numbers, specifically as a linked list of floating-point values.
- **Structure (`struct`):**
  - **Name:** Node
  - **Description:** Represents a node in the linked list containing a floating-point `value` and a pointer to the `next` node.
- **Alias (`typedef`):**
  - **Name:** ComplexNumber
  - **Description:** An alias for the `Node*` data type, used to represent a linked list of floating-point numbers, forming complex numbers.


## Functions
### `ComplexNumber createComplexNumber(int dimension)`
- Purpose: Create a complex number represented as a linked list.
- Parameters:
  `dimension`: An integer indicating the number of components in the complex number.
- Returns: A pointer to the head of the linked list representing the complex number.
### `void printComplexNumber(ComplexNumber num)`
- Purpose: Print the components of a complex number.
- Parameters:
  - `num`: A pointer to the head of the linked list representing the complex number.
### `ComplexNumber add(ComplexNumber c1, ComplexNumber c2)`
- Purpose: Add two complex numbers.
- Parameters:
  `c1`: A pointer to the head of the first complex number.
  `c2`: A pointer to the head of the second complex number.
- Returns: A pointer to the head of the linked list representing the result of the addition.
### `ComplexNumber sub(ComplexNumber c1, ComplexNumber c2)`
- Purpose: Subtract one complex number from another.
- Parameters:
  `c1`: A pointer to the head of the first complex number.
  `c2`: A pointer to the head of the second complex number.
- Returns: A pointer to the head of the linked list representing the result of the subtraction.
### `float dot(ComplexNumber c1, ComplexNumber c2)`
- Purpose: Calculate the dot product of two complex numbers.
- Parameters:
  `c1`: A pointer to the head of the first complex number.
  `c2`: A pointer to the head of the second complex number.
- Returns: The dot product of the two complex numbers.
### `float mod(ComplexNumber c)`
- Purpose: Calculate the modulus (magnitude) of a complex number.
- Parameters:
  `c`: A pointer to the head of the complex number.
- Returns: The modulus of the complex number.
### `float cosineSimilarity(ComplexNumber c1, ComplexNumber c2)`
- Purpose: Calculate the cosine similarity between two complex numbers.
- Parameters:
  `c1`: A pointer to the head of the first complex number.
  `c2`: A pointer to the head of the second complex number.
- Returns: The cosine similarity between the two complex numbers.

## Important Variables
- `ComplexNumber`: A pointer type representing a complex number as a linked list of floats.
- `dimension`: An integer specifying the number of components in a complex number.
- `c1` and `c2`: Pointers to the heads of complex numbers used in various operations.

## Assumptions
- **Input Validity:** The code assumes that the user will provide valid input. It does not include extensive error handling for invalid inputs, such as non-numeric values when entering complex number components.
- **Complex Number Representation:** Complex numbers are represented as linked lists of floats. Each float in the linked list corresponds to a component of the complex number. For example, for a complex number "a + bi," the linked list will contain [a, b].
- **Common Dimension:** When performing operations like addition, subtraction, dot product, and cosine similarity, the code assumes that both complex numbers have the same dimension (i.e., the same number of components).
- **Cosine Similarity Limitations:** The code calculates cosine similarity as the dot product of two complex numbers divided by the product of their magnitudes. It assumes that the input complex numbers are not zero-vectors to avoid division by zero.
- **Complex Number Validity:** The code doesn't verify if the linked list representing complex numbers is valid (e.g., contains numeric data). It's the user's responsibility to ensure valid complex number representations.
- **Operation Selection:** The code offers several operations like ADD, SUB, DOT, and COSINE. Users must enter the corresponding operation as input. Any other input is considered invalid.
- **Exit Input:** To exit the program, users need to enter -1 as input for the operation.


# Q3: Linked List Color Remover

## Purpose
The purpose of this C program is to demonstrate the implementation of a singly linked list to manage a list of colors. It provides the following functionality:
- Creation of a Linked List: The program allows users to input a list of colors and constructs a linked list based on the provided colors.
- Removal of Duplicate Colors: It efficiently removes any duplicate colors from the linked list while retaining each unique color exactly once.
- Displaying Modified Linked List: The modified linked list with unique colors is printed to the console.

## Data Structures Used
- **Linked List:**
  - **Description:** A linked list is the primary data structure used in the code. It is employed to manage and manipulate a list of colors (integers) and remove duplicates from it.

- **Structure (`struct`):**
  - **Name:** Node
  - **Description:** Represents a node in the linked list containing an integer `data` field and a pointer to the `next` node.

## Data Structures Used
**Singly Linked List:** The code primarily uses a singly linked list data structure to store and manipulate the color data. Each element of the list is represented by the `Node` structure, which contains data and a reference to the next node.

## Functions
### `void removeDuplicateColors(Node* head)`
- Purpose: This function removes duplicate colors from the linked list.
- Parameters: It takes the `head` of the linked list as an argument, allowing it to operate on the linked list and eliminate duplicate colors.
- Working: It iterates through the linked list, comparing each node's color with the color of the next node. If a match is found, the function removes the duplicate node by updating pointers and deallocating memory.
### `void printColors(Node* head)`
- Purpose: This function prints the colors in the linked list.
- Parameters: It accepts the `head` of the linked list as an argument, allowing it to traverse and print the colors.
- Working: The function iterates through the linked list, printing each color. It adds an arrow ("->") after the color for all nodes except the last one.

## Important Variables
- `Node* head`: This pointer references the first node in the linked list, serving as the entry point to the list.
- `Node* traverse`: It is used for traversing the linked list, pointing to the current node being processed.
- `int data`: An integer field in the `Node` structure that stores the color value.
- `struct Node* next`: A pointer in the `Node` structure that points to the next node in the linked list, creating the linkage between nodes.

## Assumptions
- **Color Representation:** Colors are assumed to be represented as integers, but the specific encoding is left unspecified.
- **Input Validation:** The program lacks input validation and assumes valid color data is provided by the user.
- **Duplicate Color Removal:** Duplicate colors are determined by equality of their integer representations, and one of them will be removed.
- **Sorting of Linked List:** The program doesn't perform any sorting on the linked list; it solely removes duplicate colors.
- **Empty List Handling:** The code doesn't handle cases where the linked list is empty; it's assumed there's at least one color in the list.
- **Non-Integer Inputs:** Input validation for non-integer inputs is not included.
- **Number of Colors:** Users are assumed to provide the specified number of colors.
- **Handling of Non-Adjacent Duplicates:** Consecutive duplicate colors are removed, but non-adjacent duplicates are not.