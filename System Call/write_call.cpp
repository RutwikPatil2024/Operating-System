#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

using namespace std;

int main() {
    int fd = open("test.txt", O_WRONLY | O_CREAT, 0644);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    const char* text = "Hello Rutwik Patil";

    write(fd, text, strlen(text));

    close(fd);

    cout << "Data written successfully\n";

    return 0;
}