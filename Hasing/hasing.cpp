/*
    ================== HASHING ==================

    - Hashing ek technique hai jo data ko uniquely identify karne ke liye use hoti hai.
    - Data ko key : value pair ke form me store kiya jata hai.
    - Ek hash function use hota hai jo key ko index me convert karta hai.

    Example:
        h(x) = x % 10

    - Hash table ek data structure hai jisme data store hota hai.

    - Time Complexity (average case):
        Searching  -> O(1)
        Inserting  -> O(1)
        Deletion   -> O(1)


    ================== COLLISION ==================

    - Jab do ya usse zyada keys same index par map ho jaye,
      usse collision kehte hain.

    Example:
        h(x) = x % 10
        25 -> 5
        35 -> 5
        → Dono same index → Collision

    - Collision hona unavoidable hai (kyuki keys infinite ho sakti hain
      aur table size limited hota hai)


    ================== COLLISION HANDLING ==================

    1. Chaining
        - Har index par ek linked list/vector hoti hai
        - Same index wale elements list me store hote hain

        Example:
            index 5 -> [25 -> 35]

        Pros:
            - Simple
        Cons:
            - Extra memory use hota hai

    ================ Load Factor =====================
    - performance of chaning 
       M = no. of slots in Hash Table
       N = no. of keys to be inserted
        
    - Load factor (α) = N/M
    - We want to be load factor to be small.
    ===================================================

    2. Open Addressing
        - Saare elements table ke andar hi store hote hain
        - Collision par naya empty slot find karte hain

        a) Linear Probing
            (h(key) + i) % size

            - Next index check karte rehte hain
            - Problem: Primary Clustering

        b) Quadratic Probing
            (h(key) + i*i) % size

            - Square jump karta hai
            - Less clustering than linear

        c) Double Hashing
            (h1(key) + i*h2(key)) % size

            - Second hash function use hota hai
            - Best distribution, minimum clustering


    ================== CLUSTERING ==================

    - Jab consecutive filled slots ka group ban jata hai,
      usse clustering kehte hain.

    Types:

    1. Primary Clustering (Linear Probing)
        Example:
            23 -> 3
            33 -> 4
            43 -> 5

            → Continuous block: [23,33,43]

        Problem:
            - Naye elements bhi isi cluster me add hote hain
            - Search slow ho jata hai

    2. Secondary Clustering (Quadratic Probing)
        - Same hash wale elements same pattern follow karte hain
        - Linear se better but still issue hai


    ================== HOW TO REDUCE ==================

    - Better hash function use karo
    - Load factor kam rakho (resize table)
    - Linear probing avoid karo
    - Double hashing best approach hai


    ================== APPLICATIONS ==================

    - unordered_map (C++)
    - Database indexing
    - Caching
    - Password hashing

*/ 