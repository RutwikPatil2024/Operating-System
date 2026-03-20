#include <iostream>
#include <fcntl.h>   // for open()
#include <unistd.h>  // for read(), close()
using namespace std;
int main() {
    // 1. Open file
    int fd = open("file.txt", O_RDONLY);

    if (fd == -1) {
        cout << "Error opening file\n";
        return 1;
    }

    // 2. Read file
    char buffer[100];

    int bytesRead = read(fd, buffer, 99);

    if (bytesRead == -1) {
        cout << "Error reading file\n";
        return 1;
    }

    buffer[bytesRead] = '\0'; // convert to string

    // 3. Print data
    cout << "File content: " << buffer << endl;

    // 4. Close file
    close(fd);

    return 0;
}