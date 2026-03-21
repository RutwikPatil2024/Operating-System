// We use 3 semaphores:
//  mutex = 1 → For mutual exclusion
//  empty = buffer size → Count of empty slots
//  full = 0 → Count of filled slots


// Producer Algorithm
// DO
//     Produce an item
//     wait(empty)      // Check if space available
//     wait(mutex)      // Lock the buffer
//     Add item to buffer
//     signal(mutex)    // Unlock the buffer
//     signal(full)     // Increase full count
// WHILE (true)



// DO
//     wait(full)       // Check if item available
//     wait(mutex)      // Lock buffer
//     Remove item from buffer
//     signal(mutex)    // Unlock buffer
//     signal(empty)    // Increase empty count
//     Consume item
// WHILE (true)