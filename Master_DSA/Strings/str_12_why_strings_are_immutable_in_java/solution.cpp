// Time Complexity: -
// Space Complexity: -
// Explanation: 1. **String Pool**: Allows caching of string literals, saving memory. 2. **Security**: Strings are used as arguments for network connections, database URLs, etc. Immutability prevents malicious tampering. 3. **Thread Safety**: Immutable objects are inherently thread-safe and can be shared among multiple threads without synchronization. 4. **Caching Hashcode**: Immutability guarantees the hashcode will never change, making it suitable for keys in HashMaps.

/* Conceptual topic */

