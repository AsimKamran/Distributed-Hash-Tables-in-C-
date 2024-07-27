# Distributed-Hash-Tables-in-C-

A distributed hash table (DHT) provides a lookup (or search) service similar to a hash table: (key,
value) pairs are stored in a DHT and any participating machine can efficiently retrieve the value
associated with a given key. Responsibility for maintaining the mapping from keys to values is
distributed among the machines. In particular,\
\
Hash function such as SHA-1 is used to map key to identifier space. For example, a key
is mapped to an id e1 in the identifier space. Another key is mapped to the id e2 and so on.\
\
 Machines are also mapped into identifier space using the hash function on their addresses such as
IP address.\
\
Each machine is responsible for a range of ids in the identifier space. For example,
machine 1 is responsible for storing the data (i.e., key, value pairs) whose keys are mapped to
e1 and e2. Likewise, machine 3 is responsible for the ids e4 and e5.\
\
When a machine leaves, its id range is merged with a neighbor’s range. For example, 
machine 4 will be responsible for the ids in the range e4 to e6, in case machine 3 leaves
the network.\
\
Likewise, when a new machine joins, the id range of neighbor is subdivided.\
\
## Properties of Ring DHT

- **Identifier Space:** 
  - Ring DHT uses a 160-bit circular identifier space using SHA-1.
  - The example uses a 4-bit identifier space for simplicity.
  
- **Node Identifiers:**
  - Identifiers (IDs) are randomly chosen and assigned to machines (also called nodes).
  - Node ID is derived from the hash of the node address: `H(Node Address) -> Node ID`.
  - Example: Machines with IDs 1, 4, 7, 12, and 15.
  
- **Data Identifiers:**
  - Identifiers are also assigned to data, i.e., (key, value) pairs: `H(key) -> Data ID`.
  - Data with identifier `e` is stored on the node with the smallest identifier `p` such that `p ≥ e`.
  - This node is called the successor of `e`, denoted as `succ(e)`.

- **Data Storage:**
  - Machine with ID 12 stores data with IDs 8, 9, 10, 11, and 12 (if available).
  - Machine with ID 4 stores data with IDs 2, 3, and 4 (if available).
  
- **Data Structure:**
  - Each machine stores data in the form of an AVL tree.
  - This is simplistic in examples; real machines may store millions of key-value pairs.
  - AVL tree searching is used to retrieve the actual data once the machine is identified.

### Search Algorithm
The request to search a data, i.e., given a key search for the value, can arrive on any machine. The
machine will first determine whether the data is locally stored, i.e., id e of the data is less than or equal
to the id p of the machine (p ≥ e). If data is not locally found, the search request is forwarded to the
next node in the circular linked list and so on. This very simple search algorithm is not very efficient
with a complexity of O(N) where N is the number of machines in the distributed system. Why?\
\
To efficiently resolve data identifier e to machine succ(e), each machine p contains routing table FTp
of at most O(log N) entries, where N is the number of machines in the distributed system. Each
routing table entry i contains the shortcut/pointer to the distant node, i.e., FTp[i]=succ(p + 2i-1),
where i=1,...,l≤log(N). The FT of machine 1 includes
the links (also called shortcuts or pointers) to the machines who are responsible, i.e., succ, for the ids
(1+1), (1+2), (1+4), (1+8), (1+16).\
\

## Implementation Notes

- **Routing Table:**
  - Implemented as a doubly linked list.
  - Routing table entries maintain the address/pointer of the linked list node corresponding to the machine.

- **Search Query Routing:**
  - A machine `p` receives a key, i.e., `H(key) = e`, and initiates the search for the corresponding value.
  - Machine `p` receiving `search(e)` considers the following cases:
    - **Case 1:** `p = e`
      - The value is stored on the same machine.
      - Use AVL search to find the data and return the results.
    - **Case 2:** `p < e` and `e ≤ FTp[1]`
      - Forward the search request to the machine `FTp[1]` (the first entry of the routing table).
    - **Case 3:** `FTp[j] < e ≤ FTp[j+1]`
      - Forward the search request to the machine `FTp[j]`.


## New Machine Joining

- When a new machine joins, the following steps are performed:
  - **Calculate Machine ID:** `H(Machine Address) = p` is calculated, and the machine is placed in the ring accordingly.
  - **Initialize Routing Table:** The routing table of `p` is initialized, and the routing tables of other machines are updated.
  - **Subdivide ID Range:** The ID range is subdivided between `p` and `succ(p+1)`. Each data `e` with `e ≤ p` is moved from `succ(p+1)` to `p`. The AVL trees are adjusted accordingly.

## Machine Leaving

- Machines leave gracefully, ensuring that all stored data is distributed to other machine(s) before departure from the network.
- This may result in the redistribution of ID ranges and adjustments to the AVL trees.

## Data Storage Query

- The data storage request can arrive on any machine.
- Upon receiving the key-value pair, a machine will:
  - **Find Data ID:** Calculate `H(key) = e`.
  - **Determine Responsible Machine:** Use an algorithm similar to the search to identify the machine that is `succ(e)` and responsible for storing the data.

